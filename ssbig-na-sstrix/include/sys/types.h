/* Copyright (C) 1991, 1992, 1994 Free Software Foundation, Inc.
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
not, write to the, 1992 Free Software Foundation, Inc., 675 Mass Ave,
Cambridge, MA 02139, USA.  */

/*
 *	POSIX Standard: 2.6 Primitive System Data Types	<sys/types.h>
 */

#ifndef	_SYS_TYPES_H

#define	_SYS_TYPES_H	1
#include <features.h>

__BEGIN_DECLS

#include <gnu/types.h>

#ifdef	__USE_BSD
#define u_char __u_char
#define u_short __u_short
#define u_int __u_int
#define u_long __u_long
#define quad_t __quad_t
#define u_quad_t __u_quad_t
#define	fsid_t __fsid_t
#endif

#define dev_t __dev_t
#define gid_t __gid_t
#define ino_t __ino_t
#define mode_t __mode_t
#define nlink_t __nlink_t
#define off_t __off_t
#define pid_t __pid_t
#define uid_t __uid_t
#ifndef	ssize_t
#define	ssize_t	__ssize_t
#endif

#ifdef	__USE_BSD
#define daddr_t __daddr_t
#define caddr_t __caddr_t
#endif

#define	__need_time_t
#include <time.h>

#define	__need_size_t
#include <stddef.h>

#ifdef __USE_BSD
/* These size-specific names are used by some of the inet code.  */

typedef	int int32_t;
typedef	short int int16_t;
typedef	char int8_t;
typedef	unsigned int u_int32_t;
typedef	unsigned short int u_int16_t;
typedef	unsigned char u_int8_t;
#endif


#ifdef	__USE_BSD

#define	FD_SETSIZE	__FD_SETSIZE
#define	NFDBITS		__NFDBITS
#define	fd_set		__fd_set
#define	FD_ZERO(set)	__FD_ZERO(set)
#define	FD_SET(d, set)	__FD_SET((d), (set))
#define	FD_CLR(d, set)	__FD_CLR((d), (set))
#define	FD_ISSET(d, set)__FD_ISSET((d), (set))

/* This being here makes the `select' prototype valid whether or not
   we have already included <sys/time.h> to define `struct timeval'.  */
struct timeval;

/* Check the first NFDS descriptors each in READFDS (if not NULL) for read
   readiness, in WRITEFDS (if not NULL) for write readiness, and in EXCEPTFDS
   (if not NULL) for exceptional conditions.  If TIMEOUT is not NULL, time out
   after waiting the interval specified therein.  Returns the number of ready
   descriptors, or -1 for errors.  */
extern int __select __P ((int __nfds, __fd_set *__readfds,
			  __fd_set *__writefds, __fd_set *__exceptfds,
			  struct timeval *__timeout));
extern int select __P ((int __nfds, __fd_set *__readfds,
			__fd_set *__writefds, __fd_set *__exceptfds,
			struct timeval *__timeout));

#endif /* Use BSD.  */


__END_DECLS

#endif /* sys/types.h */
