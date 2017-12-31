/* Support code for dealing with priorities in the Hurd.
Copyright (C) 1994 Free Software Foundation, Inc.
This file is part of the GNU C Library.

The GNU C Library is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public License as
published by the Free Software Foundation; either version 2 of the
License, or (at your option) any later version.

The GNU C Library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Library General Public License for more details.

You should have received a copy of the GNU Library General Public
License along with the GNU C Library; see the file COPYING.LIB.  If
not, write to the Free Software Foundation, Inc., 675 Mass Ave,
Cambridge, MA 02139, USA.  */

#include <hurd/resource.h>
#include <hurd.h>

error_t
_hurd_priority_which_map (enum __priority_which which, int who,
			  error_t (*function) (pid_t, struct procinfo *))
{
  unsigned int npids = 64, i;
  pid_t pidbuf[npids], *pids;
  error_t err;
  struct procinfo *pip;
  int pibuf[sizeof *pip + 5 * sizeof (pip->threadinfos[0])], *pi = pibuf;
  unsigned int pisize = sizeof (pibuf) / sizeof (int);

  switch (which)
    {
    case PRIO_PROCESS:
      npids = 1;
      pids[0] = who;
      err = 0;
      break;

    case PRIO_PGRP:
      err = __USEPORT (PROC, __proc_getpgrppids (port, who, &pids, &npids));
      break;

    case PRIO_USER:
      err = __USEPORT (PROC, __proc_getallpids (port, &pids, &npids));
      break;

    default:
      return EINVAL;
    }

  for (i = 0; !err && i < npids; ++i)
    {
      if (which == PRIO_USER)
	{
	  /* Get procinfo to check the owner.  */
	  int *oldpi = pi;
	  unsigned int oldpisize = pisize;
	  if (err = __USEPORT (PROC, __proc_getprocinfo (port, pids[i],
							 &pi, &pisize)))
	    continue;
	  if (pi != oldpi && oldpi != pibuf)
	    /* Old buffer from last call was not reused; free it.  */
	    __vm_deallocate (__mach_task_self (),
			     (vm_address_t) oldpi, oldpisize * sizeof pi[0]);

	  pip = (struct procinfo *) pi;
	  if (pip->owner != who)
	    continue;
	}
      else
	pip = NULL;

      err = (*function) (pids[i], pip);
    }

  if (pids != pidbuf)
    __vm_deallocate (__mach_task_self (),
		     (vm_address_t) pids, npids * sizeof pids[0]);
  if (pi != pibuf)
    __vm_deallocate (__mach_task_self (),
		     (vm_address_t) pi, pisize * sizeof pi[0]);

  return err;
}
