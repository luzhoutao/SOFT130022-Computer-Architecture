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

#include <ansidecl.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <hurd.h>
#include <fcntl.h>
#include <hurd/fd.h>


/* Check ERR for wanting to generate a signal.  */

int __stdio_fileno (void *);

static inline int
fd_fail (struct hurd_fd *fd, error_t err)
{
  int signo = _hurd_fd_error_signal (err);
  if (signo)
    _hurd_raise_signal (NULL, signo, __stdio_fileno (fd), err);
  errno = err;
  return -1;
}


/* Read up to N chars into BUF from COOKIE.
   Return how many chars were read, 0 for EOF or -1 for error.  */
ssize_t
DEFUN(__stdio_read, (cookie, buf, n),
      PTR cookie AND register char *buf AND size_t n)
{
  error_t err;
  struct hurd_fd *fd = cookie;

  if (! fd)
    return __hurd_fail (EBADF);

  if (err = _hurd_fd_read (fd, buf, &n))
    return fd_fail (fd, err);

  return n;
}

/* Write up to N chars from BUF to COOKIE.
   Return how many chars were written or -1 for error.  */
ssize_t
DEFUN(__stdio_write, (cookie, buf, n),
      PTR cookie AND register CONST char *buf AND size_t n)
{
  error_t err;
  size_t wrote, nleft;
  struct hurd_fd *fd = cookie;

  if (! fd)
    return __hurd_fail (EBADF);

  nleft = n;
  do
    {
      wrote = nleft;
      if (err = _hurd_fd_write (fd, buf, &wrote))
	return fd_fail (fd, err);
      buf += wrote;
      nleft -= wrote;
    } while (nleft > 0);

  return wrote;
}

/* Move COOKIE's file position *POS bytes, according to WHENCE.
   The current file position is stored in *POS.
   Returns zero if successful, nonzero if not.  */
int
DEFUN(__stdio_seek, (cookie, pos, whence),
      PTR cookie AND fpos_t *pos AND int whence)
{
  error_t err;
  struct hurd_fd *fd = cookie;
  if (! fd)
    return __hurd_fail (EBADF);
  __spin_lock (&fd->port.lock);
  err = HURD_FD_PORT_USE (fd, __io_seek (port, *pos, whence, pos));
  return err ? fd_fail (fd, err) : 0;
}

/* Close the file associated with COOKIE.
   Return 0 for success or -1 for failure.  */
int
DEFUN(__stdio_close, (cookie), PTR cookie)
{
  error_t error;
  if (cookie)
    error = _hurd_fd_close (cookie);
  else
    error = EBADF;
  return error ? __hurd_fail (error) : 0;
}


static inline int
modeflags (__io_mode m)
{
  int flags = 0;
  if (m.__read)
    flags |= O_READ;
  if (m.__write)
    flags |= O_WRITE;
  if (m.__append)
    flags |= O_APPEND;
  if (m.__create)
    flags |= O_CREAT;
  if (m.__truncate)
    flags |= O_TRUNC;
  if (m.__exclusive)
    flags |= O_EXCL;
  return flags;
}

/* Open FILENAME with the mode in M.  */
int
DEFUN(__stdio_open, (filename, m, cookieptr),
      CONST char *filename AND __io_mode m AND PTR *cookieptr)
{
  int flags;
  file_t port;
  struct hurd_fd *d;

  flags = modeflags (m);
  port = __file_name_lookup (filename, flags, 0666 & ~_hurd_umask);
  if (port == MACH_PORT_NULL)
    return -1;

  HURD_CRITICAL_BEGIN;
  d = _hurd_alloc_fd (NULL, 0);
  if (d != NULL)
    {
      _hurd_port2fd (d, port, flags);
      __spin_unlock (&d->port.lock);
    }
  HURD_CRITICAL_END;

  *cookieptr = d;
  return 0;
}


/* Open FILENAME with the mode in M.  Use the same magic cookie
   already in *COOKIEPTR if possible, closing the old cookie with CLOSEFN.  */
int
DEFUN(__stdio_reopen, (filename, m, cookieptr),
      CONST char *filename AND __io_mode m AND
      PTR *cookieptr AND __io_close_fn closefn)
{
  int flags;
  file_t port;
  struct hurd_fd *d;

  if (closefn != __stdio_close)
    {
      /* The old cookie is Not Of The Body.
	 Just close it and do a normal open.  */
      (*closefn) (*cookieptr);
      return __stdio_open (filename, m, cookieptr);
    }

  /* Open a new port on the file.  */
  flags = modeflags (m);
  port = __file_name_lookup (filename, flags, 0666 & ~_hurd_umask);

  /* Install the new port in the same file descriptor slot the old cookie
     points to.  If opening the file failed, PORT will be MACH_PORT_NULL
     and installing it in the descriptor will have the effect of closing
     the old descriptor.  */

  d = *cookieptr;
  HURD_CRITICAL_BEGIN;
  __spin_lock (&d->port.lock);
  _hurd_port2fd (d, port, flags);
  __spin_unlock (&d->port.lock);
  HURD_CRITICAL_END;

  return port == MACH_PORT_NULL ? -1 : 0;
}


/* Write a message to the error output.
   Try hard to make it really get out.  */
void
DEFUN(__stdio_errmsg, (msg, len), CONST char *msg AND size_t len)
{
  io_t server;
  unsigned int wrote;

  server = __getdport (2);
  __io_write (server, msg, len, -1, &wrote);
  __mach_port_deallocate (__mach_task_self (), server);
}


/* Return the POSIX.1 file descriptor associated with COOKIE,
   or -1 for errors.  If COOKIE does not relate to any POSIX.1 file
   descriptor, this should return -1 with errno set to EOPNOTSUPP.  */
int
DEFUN(__stdio_fileno, (cookie), PTR cookie)
{
  int fd;

  if (! cookie)
    return __hurd_fail (EBADF);

  __mutex_lock (&_hurd_dtable_lock);
  for (fd = 0; fd < _hurd_dtablesize; ++fd)
    if (_hurd_dtable[fd] == cookie)
      {
	__mutex_unlock (&_hurd_dtable_lock);
	return fd;
      }
  __mutex_unlock (&_hurd_dtable_lock);

  /* This should never happen, because this function should not be
     installed as a stream's __fileno function unless that stream's cookie
     points to a file descriptor.  */
  errno = EGRATUITOUS;
  return -1;
}
