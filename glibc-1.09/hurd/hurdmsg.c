/* Copyright (C) 1992, 1994 Free Software Foundation, Inc.
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
#include <hurd/msg_server.h>
#include <hurd/fd.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>


#define AUTHCHECK \
  if (auth != mach_task_self () && ! __USEPORT (AUTH, port == auth)) \
    return EPERM


/* Snarfing and frobbing the init ports.  */

kern_return_t
_S_get_init_port (mach_port_t msgport, mach_port_t auth, int which,
		  mach_port_t *result, mach_msg_type_name_t *result_type)
{
  AUTHCHECK;
  *result_type = MACH_MSG_TYPE_MOVE_SEND;
  /* This function adds a new user reference for the *RESULT it gives back.
     Our reply message uses a move-send right that consumes this reference.  */
  return _hurd_ports_get (which, result);
}

kern_return_t
_S_set_init_port (mach_port_t msgport, mach_port_t auth,
		  int which, mach_port_t port)
{
  error_t err;

  AUTHCHECK;

  err = _hurd_ports_set (which, port);
  if (err == 0)
    __mach_port_deallocate (__mach_task_self (), port);

  return 0;
}

kern_return_t
_S_get_init_ports (mach_port_t msgport, mach_port_t auth,
		   mach_port_t **ports,
		   mach_msg_type_name_t *ports_type,
		   unsigned int *nports)
{
  unsigned int i;
  error_t err;

  AUTHCHECK;

  if (err = __vm_allocate (__mach_task_self (), (vm_address_t *) ports,
			   _hurd_nports * sizeof (mach_port_t), 1))
    return err;
  *nports = _hurd_nports;

  for (i = 0; i < _hurd_nports; ++i)
    /* This function adds a new user ref for the *RESULT it gives back.
       Our reply message uses move-send rights that consumes this ref.  */
    if (err = _hurd_ports_get (i, &(*ports)[i]))
      {
	/* Died part way through.  Deallocate the ports already fetched.  */
	while (i-- > 0)
	  __mach_port_deallocate (__mach_task_self (), (*ports)[i]);
	__vm_deallocate (__mach_task_self (),
			 (vm_address_t) *ports,
			 *nports * sizeof (mach_port_t));
	return err;
      }

  *ports_type = MACH_MSG_TYPE_MOVE_SEND;
  return 0;
}

kern_return_t
_S_set_init_ports (mach_port_t msgport, mach_port_t auth,
		   mach_port_t *ports, unsigned int nports)
{
  unsigned int i;
  error_t err;

  AUTHCHECK;

  for (i = 0; i < _hurd_nports; ++i)
    {
      if (err = _hurd_ports_set (i, ports[i]))
	return err;
      else
	__mach_port_deallocate (__mach_task_self (), ports[i]);
    }

  return 0;
}

/* Snarfing and frobbing the init ints.  */

static kern_return_t
get_int (int which, int *value)
{
  switch (which)
    {
    case INIT_UMASK:
      *value = _hurd_umask;
      return 0;
    case INIT_SIGMASK:
      {
	struct hurd_sigstate *ss = _hurd_thread_sigstate (_hurd_sigthread);
	*value = ss->blocked;
	__mutex_unlock (&ss->lock);
	return 0;
      }
    case INIT_SIGPENDING:
      {
	struct hurd_sigstate *ss = _hurd_thread_sigstate (_hurd_sigthread);
	*value = ss->pending;
	__mutex_unlock (&ss->lock);
	return 0;
      }
    case INIT_SIGIGN:
      {
	struct hurd_sigstate *ss = _hurd_thread_sigstate (_hurd_sigthread);
	sigset_t ign;
	int sig;
	__sigemptyset (&ign);
	for (sig = 1; sig < NSIG; ++sig)
	  if (ss->actions[sig].sa_handler == SIG_IGN)
	    __sigaddset (&ign, sig);
	__mutex_unlock (&ss->lock);
	*value = ign;
	return 0;
      }
    default:
      return EINVAL;
    }
}

kern_return_t
_S_get_init_int (mach_port_t msgport, mach_port_t auth,
		 int which, int *value)
{
  AUTHCHECK;

  return get_int (which, value);
}

kern_return_t
_S_get_init_ints (mach_port_t msgport, mach_port_t auth,
		  int **values, unsigned int *nvalues)
{
  error_t err;
  unsigned int i;

  AUTHCHECK;

  if (err = __vm_allocate (__mach_task_self (), (vm_address_t *) values,
			   INIT_INT_MAX * sizeof (int), 1))
    return err;
  *nvalues = INIT_INT_MAX;

  for (i = 0; i < INIT_INT_MAX; ++i)
    switch (err = get_int (i, &(*values)[i]))
      {
      case 0:			/* Success.  */
	break;
      case EINVAL:		/* Unknown index.  */
	(*values)[i] = 0;
	break;
      default:			/* Lossage.  */
	__vm_deallocate (__mach_task_self (),
			 (vm_address_t) *values, INIT_INT_MAX * sizeof (int));
	return err;
      }

  return 0;
}


static kern_return_t
set_int (int which, int value)
{
  switch (which)
    {
    case INIT_UMASK:
      _hurd_umask = value;
      return 0;

      /* These are pretty odd things to do.  But you asked for it.  */
    case INIT_SIGMASK:
      {
	struct hurd_sigstate *ss = _hurd_thread_sigstate (_hurd_sigthread);
	ss->blocked = value;
	__mutex_unlock (&ss->lock);
	return 0;
      }
    case INIT_SIGPENDING:
      {
	struct hurd_sigstate *ss = _hurd_thread_sigstate (_hurd_sigthread);
	ss->pending = value;
	__mutex_unlock (&ss->lock);
	return 0;
      }
    case INIT_SIGIGN:
      {
	struct hurd_sigstate *ss = _hurd_thread_sigstate (_hurd_sigthread);
	int sig;
	const sigset_t ign = value;
	for (sig = 1; sig < NSIG; ++sig)
	  {
	    if (__sigismember (&ign, sig))
	      ss->actions[sig].sa_handler = SIG_IGN;
	    else if (ss->actions[sig].sa_handler == SIG_IGN)
	      ss->actions[sig].sa_handler = SIG_DFL;
	  }
	__mutex_unlock (&ss->lock);
	return 0;
      }
    default:
      return EINVAL;
    }
}

kern_return_t
_S_set_init_int (mach_port_t msgport, mach_port_t auth,
		 int which, int value)
{
  AUTHCHECK;

  return set_int (which, value);
}

kern_return_t
_S_set_init_ints (mach_port_t msgport, mach_port_t auth,
		  int *values, unsigned int nvalues)
{
  error_t err;
  unsigned int i;

  AUTHCHECK;

  for (i = 0; i < INIT_INT_MAX; ++i)
    switch (err = set_int (i, values[i]))
      {
      case 0:			/* Success.  */
	break;
      case EINVAL:		/* Unknown index.  */
	break;
      default:			/* Lossage.  */
	return err;
      }

  return 0;
}


kern_return_t
_S_get_fd (mach_port_t msgport, mach_port_t auth,
	   int which, mach_port_t *result, mach_msg_type_name_t *result_type)
{
  AUTHCHECK;

  /* This creates a new user reference for the send right.
     Our reply message will move that reference to the caller.  */
  *result = __getdport (which);
  if (*result == MACH_PORT_NULL)
    return errno;
  *result_type = MACH_MSG_TYPE_MOVE_SEND;

  return 0;
}

kern_return_t
_S_set_fd (mach_port_t msgport, mach_port_t auth,
	   int which, mach_port_t port)
{
  AUTHCHECK;

  /* We consume the reference if successful.  */
  return HURD_FD_USE (which, (_hurd_port2fd (descriptor, port, 0), 0));
}

/* Snarfing and frobbing environment variables.  */

kern_return_t
_S_get_env_variable (mach_port_t msgport,
		     char *variable,
		     char **data, unsigned int *datalen)
{
  const char *value = getenv (variable);

  if (value == NULL)
    return ENOENT;

  /* XXX this pointer might become invalid */
  *data = value;
  *datalen = strlen (value);
  return 0;
}


kern_return_t
_S_set_env_variable (mach_port_t msgport, mach_port_t auth,
		     char *variable,
		     char *value,
		     int replace)
{
  AUTHCHECK;

  if (setenv (variable, value, replace)) /* XXX name space */
    return errno;
  return 0;
}

kern_return_t
_S_get_environment (mach_port_t msgport,
		    char **data, unsigned int *datalen)
{
  /* Pack the environment into an array with nulls separating elements.  */
  if (__environ != NULL)
    {
      char *ap, **p;
      size_t envlen = 0;

      for (p = __environ; *p != NULL; ++p)
	envlen += strlen (*p) + 1;

      if (envlen > *datalen)
	{
	  if (__vm_allocate (__mach_task_self (),
			     (vm_address_t *) data, envlen, 1))
	    return ENOMEM;
	}

      ap = *data;
      for (p = __environ; *p != NULL; ++p)
	ap = __memccpy (ap, *p, '\0', ULONG_MAX);

      *datalen = envlen;
    }
  else
    *datalen = 0;

  return 0;
}

kern_return_t
_S_set_environment (mach_port_t msgport, mach_port_t auth,
		    char *data, unsigned int datalen)
{
  int _hurd_split_args (char *, unsigned int, char **);
  int envc;
  char **envp;

  AUTHCHECK;

  envc = _hurd_split_args (data, datalen, NULL);
  envp = malloc ((envc + 1) * sizeof (char *));
  if (envp == NULL)
    return errno;
  _hurd_split_args (data, datalen, envp);
  __environ = envp;		/* XXX cooperate with loadenv et al */
  return 0;
}



/* XXX */

kern_return_t
_S_get_dtable (mach_port_t process,
	       mach_port_t refport,
	       portarray_t *dtable,
	       mach_msg_type_name_t *dtablePoly,
	       mach_msg_type_number_t *dtableCnt)
{ return EOPNOTSUPP; }

kern_return_t
_S_set_dtable (mach_port_t process,
	       mach_port_t refport,
	       portarray_t dtable,
	       mach_msg_type_number_t dtableCnt)
{ return EOPNOTSUPP; }

kern_return_t
_S_io_select_done (mach_port_t notify_port,
		   mach_msg_type_name_t notify_port_type,
		   int select_result,
		   int id_tag)
{ return EOPNOTSUPP; }

kern_return_t
_S_startup_dosync (mach_port_t process)
{ return EOPNOTSUPP; }

kern_return_t
_S_dir_changed (mach_port_t notify_port,
		dir_changed_type_t change,
		string_t name)
{ return EOPNOTSUPP; }

kern_return_t
_S_file_changed (mach_port_t notify_port,
		 file_changed_type_t change,
		 off_t start,
		 off_t end)
{ return EOPNOTSUPP; }
