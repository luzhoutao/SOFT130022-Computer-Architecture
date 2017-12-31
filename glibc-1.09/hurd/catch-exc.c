/* Copyright (C) 1994 Free Software Foundation, Inc.
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

#include <mach/exc_server.h>
#include <hurd/signal.h>

/* Called by the microkernel when a thread gets an exception.  */

kern_return_t
_S_catch_exception_raise (mach_port_t port,
			  thread_t thread,
			  task_t task,
			  int exception,
			  int code,
			  int subcode)
{
  int signo, sigcode, error;
  struct hurd_sigstate *ss;

  if (task != __mach_task_self ())
    /* The sender wasn't the kernel.  */
    return EPERM;

  /* Call the machine-dependent function to translate the Mach exception
     codes into a signal number and subcode.  */
  _hurd_exception2signal (exception, code, subcode,
			  &signo, &sigcode, &error);

  /* Find the sigstate structure for the faulting thread.  */
  __mutex_lock (&_hurd_siglock);
  for (ss = _hurd_sigstates; ss != NULL; ss = ss->next)
    if (ss->thread == thread)
      break;
  __mutex_unlock (&_hurd_siglock);
  if (ss == NULL)
    ss = _hurd_thread_sigstate (thread); /* Allocate a fresh one.  */

  if (__spin_lock_locked (&ss->lock.held))
    /* Oops.  The thread faulted with its sigstate lock held.
       Bad scene.  What to do?  */
    ;				/* XXX */
  else
    __mutex_lock (&ss->lock);

  /* Post the signal.  */
  _hurd_internal_post_signal (ss, signo, sigcode, error,
			      MACH_PORT_NULL, MACH_MSG_TYPE_PORT_SEND);

  return KERN_SUCCESS;
}
