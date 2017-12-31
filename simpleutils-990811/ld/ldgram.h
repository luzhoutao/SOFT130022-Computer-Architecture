/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    NAME = 259,
    LNAME = 260,
    PLUSEQ = 261,
    MINUSEQ = 262,
    MULTEQ = 263,
    DIVEQ = 264,
    LSHIFTEQ = 265,
    RSHIFTEQ = 266,
    ANDEQ = 267,
    OREQ = 268,
    OROR = 269,
    ANDAND = 270,
    EQ = 271,
    NE = 272,
    LE = 273,
    GE = 274,
    LSHIFT = 275,
    RSHIFT = 276,
    UNARY = 277,
    END = 278,
    ALIGN_K = 279,
    BLOCK = 280,
    BIND = 281,
    QUAD = 282,
    SQUAD = 283,
    LONG = 284,
    SHORT = 285,
    BYTE = 286,
    SECTIONS = 287,
    PHDRS = 288,
    SORT = 289,
    SIZEOF_HEADERS = 290,
    OUTPUT_FORMAT = 291,
    FORCE_COMMON_ALLOCATION = 292,
    OUTPUT_ARCH = 293,
    INCLUDE = 294,
    MEMORY = 295,
    DEFSYMEND = 296,
    NOLOAD = 297,
    DSECT = 298,
    COPY = 299,
    INFO = 300,
    OVERLAY = 301,
    DEFINED = 302,
    TARGET_K = 303,
    SEARCH_DIR = 304,
    MAP = 305,
    ENTRY = 306,
    NEXT = 307,
    SIZEOF = 308,
    ADDR = 309,
    LOADADDR = 310,
    MAX_K = 311,
    MIN_K = 312,
    STARTUP = 313,
    HLL = 314,
    SYSLIB = 315,
    FLOAT = 316,
    NOFLOAT = 317,
    NOCROSSREFS = 318,
    ORIGIN = 319,
    FILL = 320,
    LENGTH = 321,
    CREATE_OBJECT_SYMBOLS = 322,
    INPUT = 323,
    GROUP = 324,
    OUTPUT = 325,
    CONSTRUCTORS = 326,
    ALIGNMOD = 327,
    AT = 328,
    PROVIDE = 329,
    CHIP = 330,
    LIST = 331,
    SECT = 332,
    ABSOLUTE = 333,
    LOAD = 334,
    NEWLINE = 335,
    ENDWORD = 336,
    ORDER = 337,
    NAMEWORD = 338,
    ASSERT_K = 339,
    FORMAT = 340,
    PUBLIC = 341,
    BASE = 342,
    ALIAS = 343,
    TRUNCATE = 344,
    REL = 345,
    INPUT_SCRIPT = 346,
    INPUT_MRI_SCRIPT = 347,
    INPUT_DEFSYM = 348,
    CASE = 349,
    EXTERN = 350,
    START = 351,
    VERS_TAG = 352,
    VERS_IDENTIFIER = 353,
    GLOBAL = 354,
    LOCAL = 355,
    VERSIONK = 356,
    INPUT_VERSION_SCRIPT = 357,
    KEEP = 358,
    EXCLUDE_FILE = 359
  };
#endif
/* Tokens.  */
#define INT 258
#define NAME 259
#define LNAME 260
#define PLUSEQ 261
#define MINUSEQ 262
#define MULTEQ 263
#define DIVEQ 264
#define LSHIFTEQ 265
#define RSHIFTEQ 266
#define ANDEQ 267
#define OREQ 268
#define OROR 269
#define ANDAND 270
#define EQ 271
#define NE 272
#define LE 273
#define GE 274
#define LSHIFT 275
#define RSHIFT 276
#define UNARY 277
#define END 278
#define ALIGN_K 279
#define BLOCK 280
#define BIND 281
#define QUAD 282
#define SQUAD 283
#define LONG 284
#define SHORT 285
#define BYTE 286
#define SECTIONS 287
#define PHDRS 288
#define SORT 289
#define SIZEOF_HEADERS 290
#define OUTPUT_FORMAT 291
#define FORCE_COMMON_ALLOCATION 292
#define OUTPUT_ARCH 293
#define INCLUDE 294
#define MEMORY 295
#define DEFSYMEND 296
#define NOLOAD 297
#define DSECT 298
#define COPY 299
#define INFO 300
#define OVERLAY 301
#define DEFINED 302
#define TARGET_K 303
#define SEARCH_DIR 304
#define MAP 305
#define ENTRY 306
#define NEXT 307
#define SIZEOF 308
#define ADDR 309
#define LOADADDR 310
#define MAX_K 311
#define MIN_K 312
#define STARTUP 313
#define HLL 314
#define SYSLIB 315
#define FLOAT 316
#define NOFLOAT 317
#define NOCROSSREFS 318
#define ORIGIN 319
#define FILL 320
#define LENGTH 321
#define CREATE_OBJECT_SYMBOLS 322
#define INPUT 323
#define GROUP 324
#define OUTPUT 325
#define CONSTRUCTORS 326
#define ALIGNMOD 327
#define AT 328
#define PROVIDE 329
#define CHIP 330
#define LIST 331
#define SECT 332
#define ABSOLUTE 333
#define LOAD 334
#define NEWLINE 335
#define ENDWORD 336
#define ORDER 337
#define NAMEWORD 338
#define ASSERT_K 339
#define FORMAT 340
#define PUBLIC 341
#define BASE 342
#define ALIAS 343
#define TRUNCATE 344
#define REL 345
#define INPUT_SCRIPT 346
#define INPUT_MRI_SCRIPT 347
#define INPUT_DEFSYM 348
#define CASE 349
#define EXTERN 350
#define START 351
#define VERS_TAG 352
#define VERS_IDENTIFIER 353
#define GLOBAL 354
#define LOCAL 355
#define VERSIONK 356
#define INPUT_VERSION_SCRIPT 357
#define KEEP 358
#define EXCLUDE_FILE 359

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 68 "ldgram.y" /* yacc.c:1909  */

  bfd_vma integer;
  char *name;
  const char *cname;
  struct wildcard_spec wildcard;
  int token;
  union etree_union *etree;
  struct phdr_info
    {
      boolean filehdr;
      boolean phdrs;
      union etree_union *at;
      union etree_union *flags;
    } phdr;
  struct lang_nocrossref *nocrossref;
  struct lang_output_section_phdr_list *section_phdr;
  struct bfd_elf_version_deps *deflist;
  struct bfd_elf_version_expr *versyms;
  struct bfd_elf_version_tree *versnode;

#line 283 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
