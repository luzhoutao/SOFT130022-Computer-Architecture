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

/* Get the Mach definitions of ENTRY and kernel_trap.  */
#include <mach/machine/syscall_sw.h>

/* This is invoked by things run when there is random lossage, before they
   try to do anything else.  Just to be safe, deallocate the reply port so
   bogons arriving on it don't foul up future RPCs.  */

#ifndef ASSEMBLER
#include <mach/mig_support.h>
#define FATAL_PREPARE __mig_dealloc_reply_port (MACH_PORT_NULL)
#endif

/* sysdeps/mach/MACHINE/sysdep.h should define the following macros.  */

/* Produce a text assembler label for the C global symbol NAME.  */
#ifndef ENTRY
#define ENTRY(name)
#error ENTRY not defined by sysdeps/mach/MACHINE/sysdep.h
#endif

/* Set variables ARGC, ARGV, and ENVP for the arguments
   left on the stack by the microkernel.  */
#ifndef SNARF_ARGS
#define SNARF_ARGS(argc, argv, envp)
#error SNARF_ARGS not defined by sysdeps/mach/MACHINE/sysdep.h
#endif

/* Call the C function FN with no arguments,
   on a stack starting at SP (as returned by *_cthread_init_routine).
   You don't need to deal with FN returning; it shouldn't.  */
#ifndef	CALL_WITH_SP
#define CALL_WITH_SP(fn, sp)
#error CALL_WITH_SP not defined by sysdeps/mach/MACHINE/sysdep.h
#endif

/* LOSE can be defined as the `halt' instruction or something
   similar which will cause the process to die in a characteristic
   way suggesting a bug.  */
#ifndef LOSE
#define	LOSE	({ volatile int zero = 0; zero / zero; })
#endif

/* One of these should be defined to specify the stack direction.  */
#if !defined (STACK_GROWTH_UP) && !defined (STACK_GROWTH_DOWN)
#error stack direction unspecified
#endif

/* Used by some assembly code.  */
#ifdef NO_UNDERSCORES
#define C_SYMBOL_NAME(name)	name
#else
#define C_SYMBOL_NAME(name)	_##name
#endif
