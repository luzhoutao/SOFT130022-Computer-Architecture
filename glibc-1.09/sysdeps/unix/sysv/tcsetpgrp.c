/* Copyright (C) 1992 Free Software Foundation, Inc.
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
#include <sysv_termio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/ioctl.h>

/* Set the foreground process group ID of FD set PGRP_ID.  */
int
DEFUN(tcsetpgrp, (fd, pgrp_id), int fd AND pid_t pgrp_id)
{
  return __ioctl (fd, _TIOCSPGRP, &pgrp_id);
}
