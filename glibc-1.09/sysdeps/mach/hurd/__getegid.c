/* Copyright (C) 1993, 1994 Free Software Foundation, Inc.
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
#include <unistd.h>
#include <hurd.h>
#include <hurd/id.h>

/* Get the effective group ID of the calling process.  */
gid_t
DEFUN_VOID(__getegid)
{
  error_t err;
  gid_t egid;

  HURD_CRITICAL_BEGIN;
  __mutex_lock (&_hurd_id.lock);

  if (err = _hurd_check_ids ())
    {
      errno = err;
      egid = -1;
    }
  else if (_hurd_id.gen.ngids >= 1)
    egid = _hurd_id.gen.gids[0];
  else if (_hurd_id.aux.ngids >= 1)
    /* We have no effective gids.  Return the real gid.  */
    egid = _hurd_id.aux.gids[0];
  else
    {
      /* We do not even have a real gid.  */
      errno = EGRATUITOUS;
      egid = -1;
    }

  __mutex_unlock (&_hurd_id.lock);
  HURD_CRITICAL_END;

  return egid;
}
