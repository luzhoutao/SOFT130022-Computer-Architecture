/* Copyright (C) 1991, 1992, 1993, 1994 Free Software Foundation, Inc.
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

#include <ansidecl.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <hurd.h>
#include <hurd/fd.h>


/* Duplicate FD to FD2, closing the old FD2 and making FD2 be
   open on the same file as FD is.  Return FD2 or -1.  */
int
DEFUN(__dup2, (fd, fd2), int fd AND int fd2)
{
  struct hurd_fd *d;
  struct hurd_fd *d2;
  io_t port, ctty;
  struct hurd_userlink ulink, ctty_ulink;
  int flags;

  HURD_CRITICAL_BEGIN;

  /* Extract the ports and flags from FD.  */
  d = _hurd_fd_get (fd);
  if (d == NULL)
    {
      errno = EBADF;
      goto earlyout;
    }

  if (fd2 == fd)
    {
      /* FD is valid and FD2 is already the same; just return it.  */
      __spin_unlock (&d->port.lock);
      goto out;
    }

  flags = d->flags;
  ctty = _hurd_port_get (&d->ctty, &ctty_ulink);
  port = _hurd_port_locked_get (&d->port, &ulink); /* Unlocks D.d.  */

  __mutex_lock (&_hurd_dtable_lock);
  if (fd2 < 0 || fd2 >= _hurd_dtablesize)
    {
      errno = EBADF;
      fd2 = -1;
    }
  else
    {
      /* Get a hold of the destination descriptor.  */
      d2 = _hurd_dtable[fd2];
      if (d2 == NULL)
	{
	  /* Must allocate a new one.  We don't initialize the port cells
	     with this call so that if it fails (out of memory), we will
	     not have already added user references for the ports, which we
	     would then have to deallocate.  */
	  d2 = _hurd_dtable[fd2] = _hurd_new_fd (MACH_PORT_NULL,
						 MACH_PORT_NULL);
	}
      if (d2 == NULL)
	{
	  fd2 = -1;
	  if (errno == EINVAL)
	    errno = EBADF;	/* POSIX.1-1990 6.2.1.2 ll 54-55.  */
	}
      else
	{
	  /* Give the ports each a user ref for the new descriptor.  */
	  __mach_port_mod_refs (__mach_task_self (), port,
				MACH_PORT_RIGHT_SEND, 1);
	  if (ctty != MACH_PORT_NULL)
	    __mach_port_mod_refs (__mach_task_self (), ctty,
				  MACH_PORT_RIGHT_SEND, 1);

	  /* Install the ports and flags in the new descriptor slot.  */
	  __spin_lock (&d2->port.lock);
	  d2->flags = flags & ~FD_CLOEXEC; /* Duplication clears FD_CLOEXEC. */
	  _hurd_port_set (&d2->ctty, ctty);
	  _hurd_port_locked_set (&d2->port, port); /* Unlocks D2.  */
	}
    }
  __mutex_unlock (&_hurd_dtable_lock);

  _hurd_port_free (&d->port, &ulink, port);
  if (ctty != MACH_PORT_NULL)
    _hurd_port_free (&d->ctty, &ctty_ulink, port);

 out:
  __spin_unlock (&d->port.lock);

 earlyout:
  HURD_CRITICAL_END;

  return fd2;
}
