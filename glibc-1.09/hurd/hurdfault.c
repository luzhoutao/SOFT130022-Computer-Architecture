/* Handle faults in the signal thread.
Copyright (C) 1994 Free Software Foundation, Inc.
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

#include <hurd.h>
#include <hurd/signal.h>
#include "hurdfault.h"
#include <errno.h>
#include <string.h>
#include <setjmp.h>
#include <stdio.h>
#include "thread_state.h"
#include "faultexc.h"		/* mig-generated header for our exc server.  */

jmp_buf _hurdsig_fault_env;

static mach_port_t forward_sigexc;

int _hurdsig_fault_expect_signo;
int _hurdsig_fault_sigcode;
int _hurdsig_fault_sigerror;

kern_return_t
_hurdsig_fault_catch_exception_raise (mach_port_t port,
				      thread_t thread,
				      task_t task,
				      int exception,
				      int code,
				      int subcode)
{
  int signo;

  if (port != forward_sigexc ||
      thread != _hurd_msgport_thread || task != __mach_task_self ())
    return EPERM;		/* Strange bogosity.  */

  /* Call the machine-dependent function to translate the Mach exception
     codes into a signal number and subcode.  */
  _hurd_exception2signal (exception, code, subcode, &signo,
			  &_hurdsig_fault_sigcode, &_hurdsig_fault_sigerror);

  return signo == _hurdsig_fault_expect_signo ? 0 : EGREGIOUS;
}

static void
faulted (void)
{
  struct
    {
      mach_msg_header_t head;
      char buf[64];
    } request;
  struct
    {
      mach_msg_header_t head;
      mach_msg_type_t type;
      int result;
    } reply;
  extern int _hurdsig_fault_exc_server (mach_msg_header_t *,
					mach_msg_header_t *);

 /* Wait for the exception_raise message forwarded by the proc server.  */

 if (__mach_msg (&request.head, MACH_RCV_MSG, 0,
		  sizeof request, forward_sigexc,
		  MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL)
      != MACH_MSG_SUCCESS)
    __libc_fatal ("msg receive failed on signal thread exc\n");

  /* Run the exc demuxer which should call the server function above.
     That function returns 0 if the exception was expected.  */
  switch (_hurdsig_fault_exc_server (&request.head, &reply.head))
    {
    case KERN_SUCCESS:
      if (reply.head.msgh_remote_port != MACH_PORT_NULL)
	__mach_msg (&reply.head, MACH_SEND_MSG, reply.head.msgh_size,
		    0, MACH_PORT_NULL, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
      break;
    default:
      __mach_msg_destroy (&request.head);
    case MIG_NO_REPLY:
    }

  _hurdsig_fault_expect_signo = 0;
  longjmp (_hurdsig_fault_env, 1);
}

static char faultstack[1024];

/* Send exceptions for the signal thread to the proc server.
   It will forward the message on to our message port,
   and then restore the thread's state to code which
   does `longjmp (_hurd_sigthread_fault_env, 1)'.  */

void
_hurdsig_fault_init (void)
{
  error_t err;
  struct machine_thread_state state;
  mach_port_t sigexc;

  if (err = __mach_port_allocate (__mach_task_self (),
				  MACH_PORT_RIGHT_RECEIVE, &sigexc))
    __libc_fatal ("hurd: Can't create receive right for signal thread exc\n");
  if (err = __mach_port_allocate (__mach_task_self (),
				  MACH_PORT_RIGHT_RECEIVE, &forward_sigexc))
    __libc_fatal ("hurd: Can't create receive right for signal thread exc\n");

  memset (&state, 0, sizeof state);
  MACHINE_THREAD_STATE_SET_PC (&state, faulted);
  MACHINE_THREAD_STATE_SET_SP (&state, faultstack, sizeof faultstack);

#if 0				/* Don't confuse gdb.  */
  __thread_set_special_port (_hurd_msgport_thread,
			     THREAD_EXCEPTION_PORT, sigexc);
#endif

  if (err = __USEPORT
      (PROC,
       __proc_handle_exceptions (port,
				 sigexc,
				 forward_sigexc, MACH_MSG_TYPE_MAKE_SEND,
				 MACHINE_THREAD_STATE_FLAVOR,
				 (int *) &state, MACHINE_THREAD_STATE_COUNT)))
    __libc_fatal ("hurd: proc won't handle signal thread exceptions\n");
}

