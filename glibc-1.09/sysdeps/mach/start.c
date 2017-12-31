/* Copyright (C) 1992, 1993 Free Software Foundation, Inc.
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

#include <stddef.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sysdep.h>

#ifndef	__GNUC__
  #error This file uses GNU C extensions; you must compile with GCC.
#endif

/* The first piece of initialized data.  */
int __data_start = 0;

volatile int errno;

#ifndef	HAVE_GNU_LD
#define	__environ	environ
#endif
char **__environ;

extern void __mach_init (void);
extern void __libc_init (int argc, char **argv, char **envp);
extern int main (int argc, char **argv, char **envp);

/* These are uninitialized common definitions so they will be zero
   by default.  If the user links in C threads, that will provide initialized
   definitions that override these.  */
void *(*_cthread_init_routine) (void); /* Returns new SP to use.  */
void (*_cthread_exit_routine) (int status);


/* These are for communication from _start to start1,
   where we cannot use the stack for anything.  */
static int start_argc;
static char **start_argv;

/* _start calls this on the new stack.  */
static volatile void
start1 (void)
{
  __libc_init (start_argc, start_argv, __environ);

  (_cthread_exit_routine != NULL ? *_cthread_exit_routine : exit)
    (main (start_argc, start_argv, __environ));

  /* Should never get here.  */
  LOSE;
}


void
_start (void)
{
  SNARF_ARGS (start_argc, start_argv, __environ);

  __mach_init ();

  if (_cthread_init_routine != NULL)
    CALL_WITH_SP (start1, (*_cthread_init_routine) ());
  else
    start1 ();

  /* Should never get here.  */
  LOSE;
}
