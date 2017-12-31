/* Copyright (C) 1991 Free Software Foundation, Inc.
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
#include <sysdep.h>
#include <errno.h>
#include <unistd.h>
#include <stddef.h>

/* Write NBYTES of BUF to FD.  Return the number written, or -1.  */
ssize_t
DEFUN(__write, (fd, buf, nbytes),
      int fd AND CONST PTR buf AND size_t nbytes)
{
  if (nbytes == 0)
    return 0;
  if (fd < 0)
    {
      errno = EBADF;
      return -1;
    }
  if (buf == NULL)
    {
      errno = EINVAL;
      return -1;
    }

  errno = ENOSYS;
  return -1;
}


#ifdef	 HAVE_GNU_LD

#include <gnu-stabs.h>

stub_warning(__write);

#endif	/* GNU stabs.  */
