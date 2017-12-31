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
#include <stdarg.h>
#include <stdio.h>


/* Write formatted output from FORMAT to a string which is
   allocated with malloc and stored in *STRING_PTR.  */
/* VARARGS2 */
int
DEFUN(asprintf, (string_ptr, format),
      char **string_ptr AND CONST char *format DOTS)
{
  va_list arg;
  int done;

  va_start(arg, format);
  done = vasprintf(string_ptr, format, arg);
  va_end(arg);

  return done;
}
