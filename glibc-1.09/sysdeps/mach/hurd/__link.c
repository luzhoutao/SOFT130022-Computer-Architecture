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
#include <stddef.h>
#include <unistd.h>
#include <hurd.h>

/* Make a link to FROM called TO.  */
int
DEFUN(__link, (from, to), CONST char *from AND CONST char *to)
{
  error_t err;
  file_t oldfile, linknode, todir;
  char *toname;

  oldfile = __file_name_lookup (from, 0, 0);
  if (oldfile == MACH_PORT_NULL)
    return -1;

  /* The file_getlinknode RPC returns the port that should be passed to
     the receiving filesystem (the one containing TODIR) in dir_link.  */

  err = __file_getlinknode (oldfile, &linknode);
  __mach_port_deallocate (__mach_task_self (), oldfile);
  if (err)
    return __hurd_fail (err);

  todir = __file_name_split (to, &toname);
  if (todir != MACH_PORT_NULL)
    {
      err = __dir_link (linknode, todir, toname);
      __mach_port_deallocate (__mach_task_self (), todir);
    }
  __mach_port_deallocate (__mach_task_self (), linknode);
  if (todir == MACH_PORT_NULL)
    return -1;

  if (err)
    return __hurd_fail (err);
  return 0;
}
