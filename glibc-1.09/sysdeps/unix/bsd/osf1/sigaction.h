/* Structure and constand definitions for sigaction et al.  OSF/1 version.
   Copyright (C) 1993 Free Software Foundation, Inc.
   Contributed by Brendan Kehoe (brendan@zen.org).

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
not, write to the, 1992 Free Software Foundation, Inc., 675 Mass Ave,
Cambridge, MA 02139, USA.  */

/* Structure describing the action to be taken when a signal arrives.  */
struct sigaction
  {
    /* Signal handler.  */
    __sighandler_t sa_handler;

    /* Additional set of signals to be blocked.  */
    __sigset_t sa_mask;

    /* Special flags.  */
    int sa_flags;
  };

/* Bits in `sa_flags'.  */
#ifdef	__USE_BSD
#define	SA_ONSTACK	0x1	/* Take signal on signal stack.  */
#define	SA_RESTART	0x2	/* Don't restart syscall on signal return.  */
#define	SA_DISABLE	0x4	/* Disable alternate signal stack.  */
#endif
#define	SA_NOCLDSTOP	0x4	/* Don't send SIGCHLD when children stop.  */


/* Values for the HOW argument to `sigprocmask'.  */
#define	SIG_BLOCK	1	/* Block signals.  */
#define	SIG_UNBLOCK	2	/* Unblock signals.  */
#define	SIG_SETMASK	3	/* Set the set of blocked signals.  */
