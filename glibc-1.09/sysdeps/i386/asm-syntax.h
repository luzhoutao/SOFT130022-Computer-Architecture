/* asm.h -- Definitions for x86 syntax variations.

Copyright (C) 1992, 1994 Free Software Foundation, Inc.

This file is part of the GNU MP Library.

The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Library General Public License as published by
the Free Software Foundation; either version 2 of the License, or (at your
option) any later version.

The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
License for more details.

You should have received a copy of the GNU Library General Public License
along with the GNU MP Library; see the file COPYING.LIB.  If not, write to
the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

#undef ALIGN

#ifdef GAS_SYNTAX
#define R(r) %r
#define MEM(base)(base)
#define MEM_DISP(base,displacement)displacement(R(base))
#define MEM_INDEX(base,index,size)(R(base),R(index),size)
#ifdef __STDC__
#define INSN1(mnemonic,size_suffix,dst)mnemonic##size_suffix dst
#define INSN2(mnemonic,size_suffix,dst,src)mnemonic##size_suffix src,dst
#else
#define INSN1(mnemonic,size_suffix,dst)mnemonic/**/size_suffix dst
#define INSN2(mnemonic,size_suffix,dst,src)mnemonic/**/size_suffix src,dst
#endif
#define TEXT .text
#define ALIGN .align 4
#define GLOBL .globl
#endif

#ifdef INTEL_SYNTAX
#define R(r) r
#define MEM(base)[base]
#define MEM_DISP(base,displacement)[base+(displacement)]
#define MEM_INDEX(base,index,size)[base+index*size]
#define INSN1(mnemonic,size_suffix,dst)mnemonic dst
#define INSN2(mnemonic,size_suffix,dst,src)mnemonic dst,src
#define TEXT .text
#define ALIGN .align 4
#define GLOBL .globl
#endif
