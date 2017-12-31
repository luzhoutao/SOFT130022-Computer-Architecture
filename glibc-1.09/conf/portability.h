/* This file is used by some of the resolver code in inet/ that
   comes from BIND 4.9.  I have written this file instead of modifying
   those things not to use it so that I can later drop in replacement
   files from future BIND distributions without change.  */

#include <unistd.h>

/* Some BIND code decides it can omit the definitions of some functions
   if BSD is defined to some value.  That might make sense when the BIND
   code is augmenting or replacing an existing system library, but we can
   never omit a function here, since we are defining the system library.  */

#undef BSD
