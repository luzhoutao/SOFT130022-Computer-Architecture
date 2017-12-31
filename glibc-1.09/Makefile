# Copyright (C) 1991, 1992, 1993, 1994 Free Software Foundation, Inc.
# This file is part of the GNU C Library.

# The GNU C Library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Library General Public License as
# published by the Free Software Foundation; either version 2 of the
# License, or (at your option) any later version.

# The GNU C Library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Library General Public License for more details.

# You should have received a copy of the GNU Library General Public
# License along with the GNU C Library; see the file COPYING.LIB.  If
# not, write to the Free Software Foundation, Inc., 675 Mass Ave,
# Cambridge, MA 02139, USA.

#
#	Master Makefile for the GNU C library
#
ifneq (,)
This makefile requires GNU Make.
endif


# This is the default target; it makes everything except the tests.
.PHONY: all
all: lib others

configure: configure.in
	autoconf $(ACFLAGS)

%/configure: %/configure.in
	autoconf $(ACFLAGS) $< > $@.new
	mv -f $@.new $@

include Makeconfig

include $(objpfx)sysd-dirs
define \n


endef
sysdep-subdirs := $(subst $(\n), ,$(sysdep-subdirs))

# These are the subdirectories containing the library source.
+ansi_dirs	:= assert ctype locale math setjmp \
		   signal stdio stdlib malloc string time
+posix_dirs	:= dirent grp pwd posix io termios
+other_dirs	:= resource socket misc gnulib $(wildcard crypt) manual
subdirs		:= $(strip $(+ansi_dirs) $(+posix_dirs) $(+other_dirs) \
			   $(sysdep-subdirs))
export subdirs := $(subdirs)	# Benign, useless in GNU make before 3.63.

# The mach and hurd subdirectories have many generated header files which
# the much of rest of the library depends on, so it is best to build them
# first (and mach before hurd, at that).  The before-compile additions in
# sysdeps/{mach,hurd}/Makefile should make it reliably work for these files
# not to exist when making in other directories, but it will be slower that
# way with more somewhat expensive `make' invocations.
subdirs	:= $(filter mach,$(subdirs)) $(filter hurd,$(subdirs)) \
	   $(filter-out mach hurd,$(subdirs))

# All initialization source files.
+subdir_inits	:= $(wildcard $(foreach dir,$(subdirs),$(dir)/init-$(dir).c))
# All subdirectories containing initialization source files.
+init_subdirs	:= $(patsubst %/,%,$(dir $(+subdir_inits)))


# These are the targets that are made by making them in each subdirectory.
+subdir_targets	:= subdir_lib objects objs others subdir_mostlyclean	\
		   subdir_clean subdir_distclean subdir_realclean	\
		   tests subdir_lint.out				\
		   subdir_echo-headers subdir_echo-distinfo		\
		   subdir_install $(addprefix install-,			\
					      no-libc.a bin lib		\
					      data headers others)

headers := features.h errno.h sys/errno.h errnos.h limits.h $(stddef.h)

echo-headers: subdir_echo-headers

ifdef +gnu-stabs
# We're using the GNU linker, so we use the set-element init function.
+init := set-init
else
# We're not using the GNU linker, so we use the munch init function.
+init := munch-init

$(objpfx)munch-init.c: munch.awk munch-tmpl.c $(+subdir_inits)
	awk -f $< subdirs='$(+init_subdirs)' $(word 2,$^) > $@-t
	mv -f $@-t $@
generated := $(generated) munch-init.c
endif

aux	:= sysdep $(+init) version start


# What to install.
# SCO 3.2v4 uses crt1.o.  Some other system uses Mcrt1.o.
# They are created below (containing no data or code).
install-lib = crt0.o crt1.o Mcrt1.o	# libc.a is done by Makerules.
install-others = $(includedir)/stubs.h


include Makerules

# Install from subdirectories too.
install: subdir_install

# `crt0' is the traditional name for the startup code,
# so that's what we install start.o as.
$(objpfx)crt0.o: $(objpfx)start.o
	-rm -f $@
	ln $< $@

$(objpfx)Mcrt1.o $(objpfx)crt1.o:
	cp /dev/null $(@:.o=.c)
	$(COMPILE.c) $(@:.o=.c) $(OUTPUT_OPTION)
	rm -f $(@:.o=.c)

lib-noranlib $(libc.a)(__.SYMDEF): subdir_lib


$(objpfx)sysd-dirs: $(+sysdir_pfx)config.make
	(echo define sysdep-subdirs;					      \
	 for dir in $(sysdirs); do					      \
	   if [ -r $(sysdep_dir)/$$dir/Subdirs ]; then			      \
	     sed 's/#.*$$//' $(sysdep_dir)/$$dir/Subdirs;		      \
	   else true;							      \
	   fi;								      \
	 done;								      \
	 echo endef) > $@-tmp
	 mv -f $@-tmp $@

# Makerules creates a file `stub-$(subdir)' for each subdirectory, which
# contains `#define __stub_FUNCTION' for each function which is a stub.
# Here we paste all of these together into <stubs.h>.

subdir-stubs := $(foreach dir,$(subdirs),$(common-objpfx)stub-$(dir))

# Since stubs.h is never needed when building the library, we simplify the
# hairy installation process by producing it in place only as the last part
# of the top-level `make install'.  It depends on subdir_install, which
# iterates over all the subdirs; subdir_install in each subdir depends on
# the subdir's stubs file.  Having more direct dependencies would result in
# extra iterations over the list for subdirs and many recursive makes.
$(includedir)/stubs.h: subdir_install
	@rm -f $(objpfx)stubs.h
	(echo '/* This file is automatically generated.';\
	 echo '   It defines a symbol `__stub_FUNCTION'\'' for each function';\
	 echo '   in the C library which is a stub, meaning it will fail';\
	 echo '   every time called, usually setting errno to ENOSYS.  */';\
	 sort $(subdir-stubs)) > $(objpfx)stubs.h
	$(INSTALL_DATA) $(objpfx)stubs.h $@
	rm -f $(objpfx)stubs.h

# This makes the Info or DVI file of the documentation from the Texinfo source.
.PHONY: info dvi
info dvi:
	$(MAKE) -C manual $@

# This makes all the subdirectory targets.

# For each target, make it depend on DIR/target for each subdirectory DIR.
$(+subdir_targets): %: $(addsuffix /%,$(subdirs))

# Compute a list of all those targets.
all-subdirs-targets := $(foreach dir,$(subdirs),\
				 $(addprefix $(dir)/,$(+subdir_targets)))

# The action for each of those is to cd into the directory and make the
# target there.
$(all-subdirs-targets):
	$(MAKE) -C $(@D) $(@F)

.PHONY: $(+subdir_targets) $(all-subdirs-targets)

# Targets to clean things up to various degrees.

.PHONY: clean realclean distclean distclean-1 parent-clean parent-mostlyclean

# Subroutines of all cleaning targets.
parent-mostlyclean: common-mostlyclean # common-mostlyclean is in Makerules.
	-rm -f $(libc.a) $(addprefix $(objpfx),$(install-lib))
parent-clean: parent-mostlyclean common-clean
	-rm -f $(addprefix $(common-objpfx),$(common-generated))
	-rm -f $(addprefix $(+sysdir_pfx),sysd-Makefile sysd-dirs sysdirs)

clean: parent-clean
# This is done this way rather than having `subdir_clean' be a
# dependency of this target so that libc.a will be removed before the
# subdirectories are dealt with and so they won't try to remove object
# files from it when it's going to be removed anyway.
	@$(MAKE) subdir_clean no_deps=t
mostlyclean: parent-mostlyclean
	@$(MAKE) subdir_mostlyclean no_deps=t

# The realclean target is just like distclean for the parent, but we want
# the subdirs to know the difference in case they care.
realclean distclean: parent-clean
# This is done this way rather than having `subdir_distclean' be a
# dependency of this target so that libc.a will be removed before the
# subdirectories are dealt with and so they won't try to remove object
# files from it when it's going to be removed anyway.
	@$(MAKE) distclean-1 no_deps=t distclean-1=$@

# Subroutine of distclean and realclean.
distclean-1: subdir_$(distclean-1)
	-rm -f $(config-generated)
	-rm -f $(addprefix $(objpfx),config.status config.make)
ifdef objdir
	-rm -f $(objpfx)Makefile
endif

.PHONY: echo_subdirs
echo_subdirs:;@echo '$(subdirs)'

.PHONY: echo-distinfo parent_echo-distinfo
echo-distinfo: parent_echo-distinfo subdir_echo-distinfo
parent_echo-distinfo:
	@echo $(addprefix +header+,$(headers)) \
	      $(addprefix +nodist+,$(generated))

# Make the distribution tarfile.

distribute  := README INSTALL NOTES COPYING.LIB COPYING ChangeLog NEWS	\
	       Makefile Makeconfig Makerules Rules Make-dist MakeTAGS	\
	       ansidecl.h mkinstalldirs move-if-change install.sh	\
	       configure configure.in aclocal.m4 config.sub config.guess\
	       munch-tmpl.c munch.awk gnu-stabs.h sysdep.h set-hooks.h

distribute := $(strip $(distribute))
generated := $(generated) stubs.h

README: README.template version.c ; # Make-dist should update README.

define format-me
@rm -f $@
makeinfo --no-validate --no-warn --no-headers $< -o $@
-chmod a-w $@
endef
INSTALL: manual/maint.texi; $(format-me)
NOTES: manual/creature.texi; $(format-me)
