/* Resource limits.
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

#include <hurd.h>
#include <cthreads.h>
#include <hurd/resource.h>
#include <gnu-stabs.h>

/* This must be given an initializer, or the a.out linking rules will
   not include the entire file when this symbol is referenced. */
struct rlimit _hurd_rlimits[RLIM_NLIMITS] = { { 0, }, };

/* This must be initialized data for the same reason as above, but this is
   intentionally initialized to a bogus value to emphasize the point that
   mutex_init is still required below just in case of unexec.  */
struct mutex _hurd_rlimit_lock = { SPIN_LOCK_INITIALIZER, };

static void
init_rlimit (void)
{
  int i;

  __mutex_init (&_hurd_rlimit_lock);

  for (i = 0; i < RLIM_NLIMITS; ++i)
    {
      if (_hurd_rlimits[i].rlim_max == 0)
	_hurd_rlimits[i].rlim_max = RLIM_INFINITY;
      if (_hurd_rlimits[i].rlim_cur == 0)
	_hurd_rlimits[i].rlim_cur = _hurd_rlimits[i].rlim_max;
    }

  (void) &init_rlimit;
}
text_set_element (_hurd_preinit_hook, init_rlimit);
