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
#include <sys/types.h>
#include <errno.h>
#include <hurd.h>
#include <hurd/fd.h>

/* Truncate the file FD refers to to LENGTH bytes.  */
int
DEFUN(ftruncate, (fd, length),
      int fd AND off_t length)
{
  error_t err;
  if (err = HURD_DPORT_USE (fd, __file_truncate (port, length)))
    return __hurd_dfail (fd, err);
  return 0;
}
