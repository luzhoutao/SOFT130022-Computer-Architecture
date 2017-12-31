/* Copyright (C) 1991, 1992 Free Software Foundation, Inc.
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
 *	POSIX Standard: 5.6 File Characteristics	<sys/stat.h>
 */

#ifndef	_SYS_STAT_H

#define	_SYS_STAT_H	1
#include <features.h>

#include <gnu/types.h>		/* For __mode_t and __dev_t.  */

__BEGIN_DECLS

#include <statbuf.h>

#if defined(__USE_BSD) || defined(__USE_MISC)
#define	S_IFMT		__S_IFMT
#define	S_IFDIR		__S_IFDIR
#define	S_IFCHR		__S_IFCHR
#define	S_IFBLK		__S_IFBLK
#define	S_IFREG		__S_IFREG
#define	S_IFLNK		__S_IFLNK
#define	S_IFSOCK	__S_IFSOCK
#define	S_IFIFO		__S_IFIFO
#endif

/* Test macros for file types.	*/

#define	__S_ISTYPE(mode, mask)	(((mode) & __S_IFMT) == (mask))

#define	S_ISDIR(mode)	__S_ISTYPE((mode), __S_IFDIR)
#define	S_ISCHR(mode)	__S_ISTYPE((mode), __S_IFCHR)
#define	S_ISBLK(mode)	__S_ISTYPE((mode), __S_IFBLK)
#define	S_ISREG(mode)	__S_ISTYPE((mode), __S_IFREG)
#define	S_ISFIFO(mode)	__S_ISTYPE((mode), __S_IFIFO)

#ifdef	__USE_GNU
#define	S_ISLNK(mode)	__S_ISTYPE((mode), __S_IFLNK)
#define	S_ISSOCK(mode)	__S_ISTYPE((mode), __S_IFSOCK)
#endif


/* Protection bits.  */

#define	S_ISUID __S_ISUID	/* Set user ID on execution.  */
#define	S_ISGID	__S_ISGID	/* Set group ID on execution.  */

#if defined(__USE_BSD) || defined(__USE_MISC)
/* Save swapped text after use (sticky bit).  This is pretty well obsolete.  */
#define	S_ISVTX	__S_ISVTX
#endif

#define	S_IRUSR	__S_IREAD	/* Read by owner.  */
#define	S_IWUSR	__S_IWRITE	/* Write by owner.  */
#define	S_IXUSR	__S_IEXEC	/* Execute by owner.  */
/* Read, write, and execute by owner.  */
#define	S_IRWXU	(__S_IREAD|__S_IWRITE|__S_IEXEC)

#if	defined(__USE_MISC) && defined(__USE_BSD)
#define	S_IREAD		S_IRUSR
#define	S_IWRITE	S_IWUSR
#define	S_IEXEC		S_IXUSR
#endif

#define	S_IRGRP	(S_IRUSR >> 3)	/* Read by group.  */
#define	S_IWGRP	(S_IWUSR >> 3)	/* Write by group.  */
#define	S_IXGRP	(S_IXUSR >> 3)	/* Execute by group.  */
/* Read, write, and execute by group.  */
#define	S_IRWXG	(S_IRWXU >> 3)

#define	S_IROTH	(S_IRGRP >> 3)	/* Read by others.  */
#define	S_IWOTH	(S_IWGRP >> 3)	/* Write by others.  */
#define	S_IXOTH	(S_IXGRP >> 3)	/* Execute by others.  */
/* Read, write, and execute by others.  */
#define	S_IRWXO	(S_IRWXG >> 3)


/* Get file attributes for FILE and put them in BUF.  */
extern int __stat __P ((__const char *__file, struct stat *__buf));
extern int stat __P ((__const char *__file, struct stat *__buf));

/* Get file attributes for the file, device, pipe, or socket
   that file descriptor FD is open on and put them in BUF.  */
extern int __fstat __P ((int __fd, struct stat *__buf));
extern int fstat __P ((int __fd, struct stat *__buf));

/* Get file attributes about FILE and put them in BUF.
   If FILE is a symbolic link, do not follow it.  */
extern int __lstat __P ((__const char *__file, struct stat *__buf));
#ifdef	__USE_BSD
extern int lstat __P ((__const char *__file, struct stat *__buf));
#endif

/* Set file access permissions for FILE to MODE.
   This takes an `int' MODE argument because that
   is what `mode_t's get widened to.  */
extern int __chmod __P ((__const char *__file, __mode_t __mode));
extern int chmod __P ((__const char *__file, __mode_t __mode));

/* Set file access permissions of the file FD is open on to MODE.  */
extern int __fchmod __P ((int __fd, __mode_t __mode));
#ifdef	__USE_BSD
extern int fchmod __P ((int __fd, __mode_t __mode));
#endif


/* Set the file creation mask of the current process to MASK,
   and return the old creation mask.  */
extern __mode_t __umask __P ((__mode_t __mask));
extern __mode_t umask __P ((__mode_t __mask));

#ifdef	__USE_GNU
/* Get the current `umask' value without changing it.
   This function is only available under the GNU Hurd.  */
extern __mode_t getumask __P ((void));
#endif

/* Create a new directory named PATH, with permission bits MODE.  */
extern int __mkdir __P ((__const char *__path, __mode_t __mode));
extern int mkdir __P ((__const char *__path, __mode_t __mode));

/* Create a device file named PATH, with permission and special bits MODE
   and device number DEV (which can be constructed from major and minor
   device numbers with the `makedev' macro above).  */
extern int __mknod __P ((__const char *__path,
			 __mode_t __mode, __dev_t __dev));
#if	defined(__USE_MISC) || defined(__USE_BSD)
extern int mknod __P ((__const char *__path,
		       __mode_t __mode, __dev_t __dev));
#endif


/* Create a new FIFO named PATH, with permission bits MODE.  */
extern int mkfifo __P ((__const char *__path, __mode_t __mode));

__END_DECLS

#endif /* sys/stat.h  */
