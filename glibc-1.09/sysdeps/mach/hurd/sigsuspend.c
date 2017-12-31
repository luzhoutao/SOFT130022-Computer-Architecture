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
#include <hurd.h>
#include <hurd/signal.h>
#include <hurd/msg.h>

/* Change the set of blocked signals to SET,
   wait until a signal arrives, and restore the set of blocked signals.  */
int
DEFUN(sigsuspend, (set), CONST sigset_t *set)
{
  struct hurd_sigstate *ss;
  sigset_t newmask, oldmask, pending;
  mach_port_t wait;
  mach_msg_header_t msg;

  if (set != NULL)
    /* Crash before locking.  */
    newmask = *set;

  /* Get a fresh port we will wait on.  */
  wait = __mach_reply_port ();

  ss = _hurd_self_sigstate ();

  oldmask = ss->blocked;
  if (set != NULL)
    /* Change to the new blocked signal mask.  */
    ss->blocked = newmask & ~_SIG_CANT_MASK;

  /* Notice if any pending signals just became unblocked.  */
  pending = ss->pending & ~ss->blocked;

  /* Tell the signal thread to message us when a signal arrives.  */
  ss->suspended = wait;
  __mutex_unlock (&ss->lock);

  if (pending)
    /* Tell the signal thread to check for pending signals.  */
    __sig_post (_hurd_msgport, 0, __mach_task_self ());

  /* Wait for the signal thread's message.  */
  __mach_msg (&msg, MACH_RCV_MSG, 0, sizeof (msg), wait,
	      MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
  __mach_port_destroy (__mach_task_self (), wait);

  __mutex_lock (&ss->lock);
  ss->blocked = oldmask;	/* Restore the old mask.  */
  pending = ss->pending & ~ss->blocked;	/* Again check for pending signals.  */
  __mutex_unlock (&ss->lock);

  if (pending)
    /* Tell the signal thread to check for pending signals.  */
    __sig_post (_hurd_msgport, 0, __mach_task_self ());
    
  /* We've been interrupted!  And a good thing, too.
     Otherwise we'd never return.
     That's right; this function always returns an error.  */
  errno = EINTR;
  return -1;
}
