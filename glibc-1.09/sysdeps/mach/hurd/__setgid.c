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
#include <unistd.h>
#include <sys/types.h>
#include <hurd.h>
#include <hurd/id.h>

/* Set the group ID of the calling process to UID.
   If the calling process is the super-user, the real
   and effective group IDs, and the saved set-group-ID to UID;
   if not, the effective group ID is set to GID.  */
int
DEFUN(__setgid, (gid), gid_t gid)
{
  auth_t newauth;
  error_t err;

  HURD_CRITICAL_BEGIN;
  __mutex_lock (&_hurd_id.lock);
  err = _hurd_check_ids ();

  if (!err)
    {
      /* Make a new auth handle which has GID as the real gid,
	 and as the first element in the list of effective gids.  */

      gid_t newgen[_hurd_id.gen.ngids + 1];
      gid_t newaux[_hurd_id.aux.ngids];
      
      newgen[0] = gid;
      memcpy (&newgen[1], _hurd_id.gen.gids,
	      _hurd_id.gen.ngids * sizeof (gid_t));
      newaux[0] = gid;
      memcpy (&newaux[1], _hurd_id.aux.gids,
	      (_hurd_id.aux.ngids - 1) * sizeof (gid_t));

      err = __USEPORT (AUTH, __auth_makeauth
		       (port, NULL, 0, MACH_MSG_TYPE_COPY_SEND,
			_hurd_id.gen.uids, _hurd_id.gen.nuids,
			_hurd_id.aux.uids, _hurd_id.aux.nuids,
			newgen, 1 + _hurd_id.gen.ngids,
			newaux, _hurd_id.aux.ngids,
			&newauth));
    }
  __mutex_unlock (&_hurd_id.lock);
  HURD_CRITICAL_END;

  if (err)
    return __hurd_fail (err);

  /* Install the new handle and reauthenticate everything.  */
  err = __setauth (newauth);
  __mach_port_deallocate (__mach_task_self (), newauth);
  return err;
}
