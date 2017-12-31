/* Copyright (C) 1991, 1994 Free Software Foundation, Inc.

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

#include <errno.h>

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#if defined (__GNU_LIBRARY__) || defined (HAVE_STDLIB_H)
#include <stdlib.h>
#endif
#if defined (__GNU_LIBRARY__) || defined (HAVE_STRING_H)
#include <string.h>
#endif
#if defined (__GNU_LIBRARY__) || defined (HAVE_UNISTD_H)
#include <unistd.h>
#endif

#if !defined (__GNU_LIBRARY__) && !defined (HAVE_STRCHR)
#define strchr index
#endif
#if !defined (__GNU_LIBRARY__) && !defined (HAVE_MEMCPY)
#define memcpy(d,s,n) bcopy ((s), (d), (n))
#endif

#ifndef	HAVE_GNU_LD
#define	__environ	environ
#endif


/* Put STRING, which is of the form "NAME=VALUE", in the environment.  */
int
putenv (string)
     const char *string;
{
  const char *const name_end = strchr (string, '=');
  register size_t size;
  register char **ep;

  if (name_end == NULL)
    {
      /* Remove the variable from the environment.  */
      size = strlen (string);
      for (ep = __environ; *ep != NULL; ++ep)
	if (!strncmp (*ep, string, size) && (*ep)[size] == '=')
	  {
	    while (ep[1] != NULL)
	      {
		ep[0] = ep[1];
		++ep;
	      }
	    *ep = NULL;
	    return 0;
	  }
    }

  size = 0;
  for (ep = __environ; *ep != NULL; ++ep)
    if (!strncmp (*ep, string, name_end - string) &&
	(*ep)[name_end - string] == '=')
      break;
    else
      ++size;

  if (*ep == NULL)
    {
      static char **last_environ = NULL;
      char **new_environ = (char **) malloc ((size + 2) * sizeof (char *));
      if (new_environ == NULL)
	return -1;
      (void) memcpy ((void *) new_environ, (void *) __environ,
		     size * sizeof (char *));
      new_environ[size] = (char *) string;
      new_environ[size + 1] = NULL;
      if (last_environ != NULL)
	free ((void *) last_environ);
      last_environ = new_environ;
      __environ = new_environ;
    }
  else
    *ep = (char *) string;

  return 0;
}
