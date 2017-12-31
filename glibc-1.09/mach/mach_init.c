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

#include <mach_init.h>
#include <mach/mach_interface.h>

extern void __mig_init (int);

mach_port_t __mach_task_self_;
vm_size_t __vm_page_size;

void
__mach_init (void)
{
  kern_return_t err;
  vm_statistics_data_t stats;

  __mach_task_self_ = (__mach_task_self) ();
  __mig_init (0);

  if (err = __vm_statistics (__mach_task_self (), &stats))
    _exit (err);
  __vm_page_size = stats.pagesize;
}
