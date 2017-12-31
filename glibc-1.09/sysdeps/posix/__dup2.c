/* Copyright (C) 1991, 1992, 1993 Free Software Foundation, Inc.
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
#include <limits.h>
#include <unistd.h>


/* Duplicate FD to FD2, closing the old FD2 and making FD2 be
   open the same file as FD is.  Return FD2 or -1.  */
int
DEFUN(__dup2, (fd, fd2), int fd AND int fd2)
{
  int save;

  if (fd2 < 0
#ifdef OPEN_MAX
      || fd2 >= OPEN_MAX
#endif
)
    {
      errno = EBADF;
      return -1;
    }

  /* Check if FD is kosher.  */
  if (fcntl (fd, F_GETFL) < 0)
    return -1;

  if (fd == fd2)
    return fd2;

  /* This is not atomic.  */

  save = errno;
  (void) close (fd2);
  errno = save;

  return fcntl (fd, F_DUPFD, fd2);
}
