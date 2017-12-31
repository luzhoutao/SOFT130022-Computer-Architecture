/* _hurd_socket_server - Find the server for a socket domain.

Copyright (C) 1991, 1992, 1993, 1994 Free Software Foundation, Inc.
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
#include <sys/socket.h>
#include <stdlib.h>
#include <hurd/paths.h>
#include <gnu-stabs.h>
#include <stdio.h>
#include "stdio/_itoa.h"
#include <cthreads.h>		/* For `struct mutex'.  */
#include "hurdmalloc.h"		/* XXX */

static struct mutex lock;

static file_t *servers;
static int max_domain;

/* Return a port to the socket server for DOMAIN.
   Socket servers translate nodes in the directory _SERVERS_SOCKET
   (canonically /servers/socket).  These naming point nodes are named
   by the simplest decimal representation of the socket domain number,
   for example "/servers/socket/3".

   Socket servers are assumed not to change very often.
   The library keeps all the server socket ports it has ever looked up,
   and does not look them up in /servers/socket more than once.  */

socket_t
_hurd_socket_server (int domain, int dead)
{
  socket_t server;

  HURD_CRITICAL_BEGIN;
  __mutex_lock (&lock);

  if (domain > max_domain)
    {
      error_t save = errno;
      file_t *new = realloc (servers, (domain + 1) * sizeof (file_t));
      if (new != NULL)
	{
	  while (max_domain <= domain)
	    new[max_domain++] = MACH_PORT_NULL;
	  servers = new;
	}
      else
	/* No space to cache the port; we will just fetch it anew below.  */
	errno = save;
    }

  if (dead && domain <= max_domain)
    {
      /* The user says the port we returned earlier (now in SERVERS[DOMAIN])
	 was dead.  Clear the cache and fetch a new one below.  */
      __mach_port_deallocate (__mach_task_self (), servers[domain]);
      servers[domain] = MACH_PORT_NULL;
    }

  if (domain > max_domain || servers[domain] == MACH_PORT_NULL)
    {
      char name[sizeof (_SERVERS_SOCKET) + 100];
      char *np = &name[sizeof (name)];
      *--np = '\0';
      np = _itoa (domain, np, 10, 0);
      *--np = '/';
      np -= sizeof (_SERVERS_SOCKET) - 1;
      memcpy (np, _SERVERS_SOCKET, sizeof (_SERVERS_SOCKET) - 1);
      server = __file_name_lookup (np, 0, 0);
      if (domain <= max_domain)
	servers[domain] = server;
    }
  else
    server = servers[domain];

  if (server == MACH_PORT_NULL && errno == ENOENT)
    /* If the server node is absent, we don't support that protocol.  */
    errno = EPFNOSUPPORT;

  __mutex_unlock (&lock);
  HURD_CRITICAL_END;

  return server;
}

#include <gnu-stabs.h>

static void
init (void)
{
  size_t i;

  __mutex_init (&lock);

  for (i = 0; i < max_domain; ++i)
    servers[i] = MACH_PORT_NULL;

  (void) &init;			/* Avoid "defined but not used" warning.  */
}
text_set_element (_hurd_preinit_hook, init);
