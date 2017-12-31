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
#include <errno.h>
#include <stddef.h>
#include <unistd.h>


/* Get file-specific information about descriptor FD.  */
long int
DEFUN(__fpathconf, (fd, name), int fd AND int name)
{
  if (fd < 0)
    {
      errno = EBADF;
      return -1;
    }

  switch (name)
    {
    default:
      errno = EINVAL;
      return -1;

    case _PC_LINK_MAX:
    case _PC_MAX_CANON:
    case _PC_MAX_INPUT:
    case _PC_NAME_MAX:
    case _PC_PATH_MAX:
    case _PC_PIPE_BUF:
    case _PC_CHOWN_RESTRICTED:
    case _PC_NO_TRUNC:
    case _PC_VDISABLE:
      break;
    }

  errno = ENOSYS;
  return -1;
}
