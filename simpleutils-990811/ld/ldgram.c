/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 22 "ldgram.y" /* yacc.c:339  */

/*

 */

#define DONTDECLARE_MALLOC

#include "bfd.h"
#include "sysdep.h"
#include "bfdlink.h"
#include "ld.h"    
#include "ldexp.h"
#include "ldver.h"
#include "ldlang.h"
#include "ldemul.h"
#include "ldfile.h"
#include "ldmisc.h"
#include "ldmain.h"
#include "mri.h"
#include "ldctor.h"
#include "ldlex.h"

#ifndef YYDEBUG
#define YYDEBUG 1
#endif

static enum section_type sectype;

lang_memory_region_type *region;

struct wildcard_spec current_file;
boolean ldgram_want_filename = true;
boolean had_script = false;
boolean force_make_executable = false;

boolean ldgram_in_script = false;
boolean ldgram_had_equals = false;
boolean ldgram_had_keep = false;
char *ldgram_vers_current_lang = NULL;

#define ERROR_NAME_MAX 20
static char *error_names[ERROR_NAME_MAX];
static int error_index;
#define PUSH_ERROR(x) if (error_index < ERROR_NAME_MAX) error_names[error_index] = x; error_index++;
#define POP_ERROR()   error_index--;

#line 113 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 68 "ldgram.y" /* yacc.c:355  */

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

#line 382 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 399 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1311

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  128
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  104
/* YYNRULES -- Number of rules.  */
#define YYNRULES  287
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  582

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   359

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   126,     2,     2,     2,    34,    21,     2,
      37,   123,    32,    30,   121,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    16,   122,
      24,    10,    25,    15,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   124,     2,   125,    20,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,    19,    50,   127,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    11,    12,    13,    14,    17,
      18,    22,    23,    26,    27,    28,    29,    35,    36,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   151,   151,   152,   153,   154,   158,   162,   162,   171,
     171,   184,   185,   189,   190,   191,   194,   197,   198,   199,
     201,   203,   205,   207,   209,   211,   213,   215,   217,   219,
     221,   222,   223,   225,   227,   229,   231,   233,   234,   236,
     235,   237,   239,   243,   244,   245,   249,   251,   255,   257,
     262,   263,   264,   268,   270,   272,   277,   277,   288,   289,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   307,   309,   311,   314,   316,   318,   320,   322,   321,
     325,   328,   327,   329,   333,   337,   340,   343,   346,   349,
     352,   358,   362,   363,   364,   368,   370,   376,   380,   384,
     391,   397,   403,   409,   419,   426,   436,   442,   441,   448,
     447,   458,   460,   459,   466,   467,   471,   472,   477,   482,
     483,   488,   499,   500,   503,   505,   509,   511,   513,   515,
     517,   522,   529,   535,   537,   539,   541,   543,   545,   547,
     549,   554,   554,   559,   563,   571,   579,   579,   583,   587,
     588,   589,   594,   593,   599,   607,   617,   618,   622,   623,
     627,   629,   634,   639,   640,   645,   647,   653,   655,   657,
     661,   663,   669,   672,   681,   692,   692,   698,   700,   702,
     704,   706,   708,   711,   713,   715,   717,   719,   721,   723,
     725,   727,   729,   731,   733,   735,   737,   739,   741,   743,
     745,   747,   749,   751,   753,   756,   758,   760,   762,   764,
     766,   768,   770,   772,   774,   780,   781,   784,   786,   788,
     794,   796,   784,   802,   804,   806,   811,   813,   801,   822,
     824,   822,   832,   833,   834,   835,   836,   840,   841,   842,
     846,   847,   852,   853,   858,   859,   864,   865,   870,   872,
     877,   880,   893,   897,   902,   904,   895,   912,   915,   917,
     921,   922,   921,   931,   962,   965,   977,   986,   989,   998,
     998,  1012,  1012,  1022,  1023,  1027,  1031,  1038,  1042,  1050,
    1053,  1057,  1061,  1065,  1072,  1076,  1081,  1080
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "NAME", "LNAME", "PLUSEQ",
  "MINUSEQ", "MULTEQ", "DIVEQ", "'='", "LSHIFTEQ", "RSHIFTEQ", "ANDEQ",
  "OREQ", "'?'", "':'", "OROR", "ANDAND", "'|'", "'^'", "'&'", "EQ", "NE",
  "'<'", "'>'", "LE", "GE", "LSHIFT", "RSHIFT", "'+'", "'-'", "'*'", "'/'",
  "'%'", "UNARY", "END", "'('", "ALIGN_K", "BLOCK", "BIND", "QUAD",
  "SQUAD", "LONG", "SHORT", "BYTE", "SECTIONS", "PHDRS", "SORT", "'{'",
  "'}'", "SIZEOF_HEADERS", "OUTPUT_FORMAT", "FORCE_COMMON_ALLOCATION",
  "OUTPUT_ARCH", "INCLUDE", "MEMORY", "DEFSYMEND", "NOLOAD", "DSECT",
  "COPY", "INFO", "OVERLAY", "DEFINED", "TARGET_K", "SEARCH_DIR", "MAP",
  "ENTRY", "NEXT", "SIZEOF", "ADDR", "LOADADDR", "MAX_K", "MIN_K",
  "STARTUP", "HLL", "SYSLIB", "FLOAT", "NOFLOAT", "NOCROSSREFS", "ORIGIN",
  "FILL", "LENGTH", "CREATE_OBJECT_SYMBOLS", "INPUT", "GROUP", "OUTPUT",
  "CONSTRUCTORS", "ALIGNMOD", "AT", "PROVIDE", "CHIP", "LIST", "SECT",
  "ABSOLUTE", "LOAD", "NEWLINE", "ENDWORD", "ORDER", "NAMEWORD",
  "ASSERT_K", "FORMAT", "PUBLIC", "BASE", "ALIAS", "TRUNCATE", "REL",
  "INPUT_SCRIPT", "INPUT_MRI_SCRIPT", "INPUT_DEFSYM", "CASE", "EXTERN",
  "START", "VERS_TAG", "VERS_IDENTIFIER", "GLOBAL", "LOCAL", "VERSIONK",
  "INPUT_VERSION_SCRIPT", "KEEP", "EXCLUDE_FILE", "','", "';'", "')'",
  "'['", "']'", "'!'", "'~'", "$accept", "file", "filename", "defsym_expr",
  "$@1", "mri_script_file", "$@2", "mri_script_lines",
  "mri_script_command", "$@3", "ordernamelist", "mri_load_name_list",
  "mri_abs_name_list", "casesymlist", "extern_name_list", "script_file",
  "$@4", "ifile_list", "ifile_p1", "$@5", "$@6", "input_list", "sections",
  "sec_or_group_p1", "statement_anywhere", "wildcard_name",
  "wildcard_spec", "file_NAME_list", "input_section_spec_no_keep", "$@7",
  "$@8", "input_section_spec", "$@9", "statement", "statement_list",
  "statement_list_opt", "length", "fill_opt", "assign_op", "end",
  "assignment", "opt_comma", "memory", "memory_spec_list", "memory_spec",
  "$@10", "origin_spec", "length_spec", "attributes_opt",
  "attributes_list", "attributes_string", "startup", "high_level_library",
  "high_level_library_NAME_list", "low_level_library",
  "low_level_library_NAME_list", "floating_point_support",
  "nocrossref_list", "mustbe_exp", "$@11", "exp", "opt_at", "section",
  "$@12", "$@13", "$@14", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20",
  "$@21", "$@22", "$@23", "type", "atype", "opt_exp_with_type",
  "opt_exp_without_type", "opt_nocrossrefs", "memspec_opt", "phdr_opt",
  "overlay_section", "$@24", "$@25", "$@26", "phdrs", "phdr_list", "phdr",
  "$@27", "$@28", "phdr_type", "phdr_qualifiers", "phdr_val",
  "version_script_file", "$@29", "version", "$@30", "vers_nodes",
  "vers_node", "verdep", "vers_tag", "vers_defns", "@31", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
      61,   265,   266,   267,   268,    63,    58,   269,   270,   124,
      94,    38,   271,   272,    60,    62,   273,   274,   275,   276,
      43,    45,    42,    47,    37,   277,   278,    40,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   123,
     125,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,    44,    59,    41,    91,    93,    33,   126
};
# endif

#define YYPACT_NINF -534

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-534)))

#define YYTABLE_NINF -272

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      97,  -534,  -534,  -534,  -534,    51,  -534,  -534,  -534,  -534,
    -534,    52,  -534,   -50,  -534,   597,   514,    57,    40,   -50,
    -534,   488,    53,   128,    42,  -534,    47,   196,   176,   220,
     221,   222,   223,   226,   227,   228,  -534,  -534,   230,   231,
    -534,   232,   233,   234,  -534,  -534,  -534,  -534,    30,  -534,
    -534,  -534,  -534,  -534,  -534,  -534,   144,  -534,   269,   196,
     270,   504,  -534,   272,   273,   274,  -534,  -534,   275,   276,
     277,   504,   280,   289,   290,   293,   296,   197,   504,    -1,
    -534,  -534,  -534,  -534,  -534,  -534,  -534,  -534,  -534,  -534,
    -534,  -534,  -534,   297,   298,  -534,  -534,   300,   301,   196,
     196,   302,   196,    15,  -534,   303,   203,   271,   196,   305,
     293,  -534,  -534,  -534,   261,     6,  -534,     7,  -534,  -534,
     504,   504,   504,   281,   282,  -534,   299,   306,   307,   308,
     310,   312,   313,   314,   316,   504,   504,  1069,   252,  -534,
     190,  -534,   193,    10,  -534,  -534,   338,  1231,   214,  -534,
    -534,   216,  -534,    18,  -534,  -534,  1231,   334,  -534,   323,
     324,   267,   236,  -534,   504,  -534,    31,    35,     2,   237,
    -534,  -534,  -534,   239,   240,   241,   242,   243,  -534,  -534,
      68,    78,    24,   244,  -534,  -534,    61,   203,   247,   345,
      67,   -50,   504,   504,  -534,   504,   504,  -534,  -534,   671,
     504,   504,   352,   504,   355,   367,   368,   504,   504,   504,
     504,  -534,  -534,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,  1231,   370,   376,  -534,   377,
     504,   504,  1231,   210,   379,  -534,   380,   341,    72,    72,
     -39,   279,  1231,   488,  -534,  -534,  -534,  -534,  -534,  -534,
    -534,  -534,   383,  -534,  -534,   674,   354,     9,  -534,  -534,
    -534,  -534,  -534,  -534,  -534,   196,  -534,   196,   303,  -534,
    -534,  -534,  -534,   224,  -534,    64,  -534,  -534,  -534,   -12,
    1231,  1231,   707,  1231,  1231,  -534,   748,   805,   292,   825,
     294,   304,   311,  1089,  1126,   855,  1146,  1197,   892,   998,
    1104,  1211,  1266,  1277,  1277,   219,   219,   219,   219,   186,
     186,    86,    86,  -534,  -534,  -534,  1231,  1231,  1231,  -534,
    -534,  -534,  1231,  1231,  -534,  -534,  -534,  -534,  -534,   278,
     283,  -534,  -534,   -22,  -534,   410,   454,   410,   504,   291,
    -534,     8,   378,  -534,   300,  -534,  -534,  -534,  -534,  -534,
    -534,  -534,   319,  -534,  -534,  -534,  -534,  -534,  -534,  -534,
    -534,  -534,   504,   504,  -534,   391,   504,    72,    80,   279,
    -534,  -534,   172,   359,  1174,   381,   315,  -534,  1253,   340,
    -534,  1231,    20,   395,  -534,   399,     3,  -534,   342,  -534,
    -534,   875,   912,   321,  1231,   -30,   404,  -534,  -534,  -534,
    -534,  -534,  -534,   322,   504,   -28,   405,  -534,   386,  -534,
    -534,  -534,   315,   375,   389,   392,  -534,   328,  -534,  -534,
    -534,   418,   309,  -534,  -534,  -534,  -534,   279,    72,  -534,
     932,  -534,   504,   382,  -534,  -534,   504,    20,   504,   317,
    -534,  -534,   351,   330,   199,   962,  -534,   387,    32,   982,
    -534,  1019,  -534,  -534,   425,  -534,   279,   400,   427,  -534,
     546,  -534,  -534,  -534,    20,  -534,   504,  -534,   320,  -534,
    -534,  -534,  -534,  -534,  -534,  -534,   409,   416,  -534,  -534,
     417,   419,  -534,  -534,  -534,  -534,  -534,  -534,  -534,   546,
     412,   423,    30,  -534,  -534,  -534,  1039,    92,  -534,  -534,
      25,    58,   426,  -534,  -534,  -534,  -534,    37,   429,  -534,
     332,   430,   346,   348,    22,   353,   431,  -534,   -77,    58,
     449,   363,  -534,  -534,   459,  -534,    25,  -534,  -534,   364,
     365,    25,    73,  -534,    58,   116,   473,  -534,  -534,   440,
     449,  -534,   388,  -534,  -534,  -534,  -534,  -534,    87,   546,
    -534,    25,  -534,   486,  -534,   453,    87,   390,  -534,  -534,
     309,  -534,  -534,  -534,  -534,  -534,   309,    87,  -534,  -534,
     309,  -534
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,    56,     9,     7,   269,     0,     2,    59,     3,    12,
       5,     0,     4,     0,     1,    57,    10,     0,     0,   270,
     273,     0,     0,     0,     0,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   170,   171,     0,     0,
      78,     0,     0,     0,    69,    58,    61,    67,     0,    60,
      63,    64,    65,    66,    62,    68,     0,    15,     0,     0,
       0,     0,    16,     0,     0,     0,    18,    45,     0,     0,
       0,     0,     0,     0,    50,     0,     0,     0,     0,   279,
     274,   133,   134,   135,   136,   175,   137,   138,   139,   140,
     175,    94,   258,     0,     0,     6,    81,     0,     0,     0,
       0,     0,     0,     0,   169,   172,     0,     0,     0,     0,
       0,   142,   141,    96,     0,     0,    39,     0,   203,   211,
       0,     0,     0,     0,     0,   204,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,     0,    48,
      30,    46,    31,    17,    32,    22,     0,    35,     0,    36,
      51,    37,    53,    38,    41,    11,     8,     0,   284,     0,
       0,     0,     0,   143,     0,   144,     0,     0,     0,     0,
      59,   152,   151,     0,     0,     0,     0,     0,   164,   166,
     147,   147,   172,     0,    85,    88,     0,     0,     0,     0,
       0,     0,     0,     0,    12,     0,     0,   181,   177,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   180,   182,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,     0,     0,    44,     0,
       0,     0,    21,     0,     0,    54,     0,     0,     0,     0,
       0,   280,   176,   217,    91,   223,   229,    93,    92,   260,
     257,   259,     0,    73,    75,   271,   156,     0,    70,    71,
      80,    95,   162,   146,   163,     0,   167,     0,   172,   173,
      83,    87,    90,     0,    77,     0,    72,   175,    84,     0,
      26,    27,    42,    28,    29,   178,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   201,   200,
     198,   197,   196,   190,   191,   194,   195,   192,   193,   188,
     189,   186,   187,   183,   184,   185,    14,    25,    23,    49,
      47,    43,    19,    20,    34,    33,    52,    55,   286,     0,
       0,   277,   275,     0,   285,   238,     0,   238,     0,     0,
      82,     0,     0,   148,     0,   149,   165,   168,   174,    86,
      89,    79,     0,   272,    40,   209,   210,   202,   179,   205,
     206,   207,     0,     0,   208,     0,     0,     0,   281,   282,
     278,   276,     0,     0,   238,     0,   216,   245,     0,   246,
     230,   263,   264,     0,   160,     0,     0,   158,     0,   150,
     145,     0,     0,     0,   199,     0,     0,   232,   233,   234,
     235,   236,   239,     0,     0,     0,     0,   241,     0,   218,
     244,   247,   216,     0,   267,     0,   261,     0,   161,   157,
     159,     0,   147,   212,   213,   214,   287,     0,     0,   237,
       0,   240,     0,     0,   224,    94,     0,   264,     0,     0,
      74,   175,     0,     0,   238,     0,   219,     0,     0,     0,
     265,     0,   262,   154,     0,   153,   283,     0,     0,   215,
     124,   225,   231,   268,   264,   175,     0,   242,   106,    99,
      98,   126,   127,   128,   129,   130,     0,     0,   115,   117,
       0,     0,   116,   107,   100,   109,   111,   119,   123,   125,
       0,     0,     0,   252,   266,   155,     0,     0,   175,   112,
       0,     0,     0,   122,   220,   175,   114,     0,   238,    97,
       0,     0,     0,     0,     0,     0,     0,   104,   147,     0,
     249,     0,   253,   226,     0,   118,     0,   102,   121,    97,
       0,     0,     0,   108,     0,   147,     0,   250,   120,     0,
     249,   243,     0,   113,   101,   105,   110,   248,   132,   124,
     250,     0,   175,     0,   221,     0,   132,     0,   131,   251,
     147,   254,   227,   103,   222,   250,   147,   132,   228,   255,
     147,   256
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -534,  -534,   -53,  -534,  -534,  -534,  -534,   318,  -534,  -534,
    -534,  -534,  -534,  -534,   396,  -534,  -534,   339,  -534,  -534,
    -534,   327,  -534,    70,  -162,  -315,  -486,   -13,    -5,  -534,
    -534,  -534,  -534,    21,  -534,   -38,  -534,  -513,  -534,    26,
    -447,  -178,  -534,  -534,  -246,  -534,  -534,  -534,  -534,  -534,
     133,  -534,  -534,  -534,  -534,  -534,  -534,  -167,   -90,  -534,
     -60,   108,  -534,  -534,  -534,  -534,  -534,  -534,  -534,  -534,
    -534,  -534,  -534,  -534,  -534,  -534,  -374,   184,  -534,  -534,
     -18,  -533,  -534,  -534,  -534,  -534,  -534,  -534,  -534,  -534,
    -534,  -534,  -402,  -534,  -534,  -534,  -534,  -534,   347,   -14,
    -534,  -534,  -240,  -534
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,    96,    10,    11,     8,     9,    16,    77,   194,
     143,   142,   140,   151,   153,     6,     7,    15,    45,   107,
     170,   186,    46,   166,    47,   494,   495,   528,   496,   511,
     512,   497,   524,   498,   499,   500,   501,   564,    90,   113,
      48,   544,    49,   267,   172,   266,   432,   465,   352,   396,
     397,    50,    51,   180,    52,   181,    53,   183,   163,   164,
     199,   419,   258,   345,   443,   470,   530,   570,   346,   457,
     503,   550,   576,   347,   423,   413,   385,   386,   389,   422,
     547,   558,   517,   549,   575,   580,    54,   167,   261,   348,
     449,   392,   426,   447,    12,    13,    55,    56,    19,    20,
     343,   161,   162,   377
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     165,   137,   275,   277,   257,    80,   116,   394,   339,   340,
     416,   147,   394,   171,   238,   279,   192,   195,   156,    95,
     436,   355,   245,   502,   424,   527,   539,   566,   182,   519,
     407,   408,   409,   410,   411,   253,   253,   479,   363,   259,
     479,   532,   577,   527,   273,   460,   174,   175,   543,   177,
     179,    14,   502,   572,   480,   188,    17,   480,   555,   353,
     197,   198,   519,    18,   579,   281,   282,    78,   281,   282,
     526,   245,   504,   479,   341,   211,   212,   519,   235,    93,
     468,   254,   472,   342,    94,   260,   242,   533,   479,    79,
     480,   380,   437,   255,   255,   412,   519,   562,    32,    32,
     381,    18,    91,   563,   252,   480,   526,   479,   399,   425,
     157,   358,   502,   158,   159,   160,   256,   256,   229,   230,
     231,    42,    42,   262,   480,   263,   429,   193,   196,   395,
     354,   239,   290,   291,   395,   293,   294,   405,   178,   246,
     296,   297,   491,   299,   534,   278,   493,   303,   304,   305,
     306,   111,   112,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   118,   119,    92,   491,   520,
     332,   333,   283,   157,   284,   283,   158,   361,   246,   273,
     288,   274,   522,   521,   344,   525,   406,   362,   453,   273,
      95,   276,   120,   121,     1,     2,     3,   184,   185,   122,
     123,   124,   521,   334,   335,     4,   227,   228,   229,   230,
     231,   552,   356,   125,   357,    97,   554,   522,   359,   360,
     407,   408,   409,   410,   411,   126,   415,   273,   467,   556,
     127,   128,   129,   130,   131,   132,   567,   225,   226,   227,
     228,   229,   230,   231,   452,   118,   119,    98,    99,   100,
     101,   114,   233,   102,   103,   104,   133,   105,   106,   108,
     109,   110,   134,   115,   117,    80,   138,   139,   141,   144,
     145,   146,   120,   121,   148,   384,   388,   384,   391,   122,
     123,   124,   149,   155,   150,   412,   257,   152,   135,   136,
     154,   168,   169,   125,   171,   173,   176,   182,   187,   189,
     191,   236,   401,   402,   237,   126,   404,   250,   200,   201,
     127,   128,   129,   130,   131,   132,    81,    82,    83,    84,
      85,    86,    87,    88,    89,   243,   202,   244,   247,   248,
     249,   118,   119,   203,   204,   205,   133,   206,   240,   207,
     208,   209,   134,   210,   440,   287,   298,   -97,   251,   300,
     264,   463,   268,   269,   270,   271,   272,   280,   120,   121,
     286,   301,   302,   234,   329,   122,   123,   124,   135,   136,
     330,   331,   455,   336,   337,   505,   459,   349,   461,   125,
     338,   351,   574,   344,   398,   403,   414,   417,   578,   427,
     378,   126,   581,   428,   418,   379,   127,   128,   129,   130,
     131,   132,   393,   118,   119,   367,   506,   369,   523,   421,
     438,   441,   431,   442,   445,   531,   446,   370,   451,   448,
     273,   456,   133,   464,   371,   475,   471,   476,   134,   462,
     120,   121,   400,   477,   435,   439,   507,   382,   123,   124,
     383,   450,   466,   508,   509,   535,   510,   118,   119,   241,
     515,   125,   514,   529,   135,   136,   415,   536,   542,   537,
     387,   538,   568,   126,   546,   551,   541,   557,   127,   128,
     129,   130,   131,   132,   120,   121,   548,  -106,   553,   559,
     569,   122,   123,   124,    81,    82,    83,    84,    85,    86,
      87,    88,    89,   571,   133,   125,   190,   118,   119,   265,
     134,   561,   292,   573,   285,   458,   545,   126,    57,   540,
     513,   565,   127,   128,   129,   130,   131,   132,   516,   430,
     444,   390,   560,     0,   120,   121,   135,   136,   289,     0,
       0,   122,   123,   124,     0,     0,     0,     0,   133,     0,
     478,     0,    58,     0,   134,   125,     0,     0,     0,     0,
       0,   479,     0,     0,     0,     0,     0,   126,     0,    59,
       0,     0,   127,   128,   129,   130,   131,   132,   480,     0,
     135,   136,     0,     0,     0,     0,     0,   481,   482,   483,
     484,   485,     0,     0,   486,     0,     0,     0,   133,     0,
       0,    21,    60,     0,   134,    61,    62,    63,    64,    65,
     -42,    66,    67,    68,     0,    69,    70,    71,    72,    73,
       0,     0,     0,     0,    74,    75,    76,   487,     0,   488,
     135,   136,     0,   489,     0,     0,    42,     0,     0,     0,
       0,     0,     0,    22,    23,     0,     0,     0,     0,    24,
      25,    26,    27,    28,     0,     0,     0,     0,     0,     0,
       0,    29,    30,    31,    32,   490,   491,     0,   492,     0,
     493,    33,    34,    35,    36,    37,    38,     0,    21,     0,
       0,    39,    40,    41,     0,     0,   213,    42,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,     0,     0,    43,     0,
     350,    57,     0,     0,  -271,     0,     0,     0,     0,    44,
      22,    23,     0,     0,     0,     0,    24,    25,    26,    27,
      28,     0,     0,     0,     0,     0,     0,     0,    29,    30,
      31,    32,     0,   364,     0,    58,     0,     0,    33,    34,
      35,    36,    37,    38,     0,     0,     0,     0,    39,    40,
      41,     0,    59,   213,    42,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,     0,     0,    43,     0,     0,     0,     0,
       0,     0,     0,     0,   295,    60,    44,     0,    61,    62,
      63,    64,    65,     0,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,     0,     0,     0,    74,    75,    76,
     213,     0,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     213,     0,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     213,   365,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     213,     0,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   213,   366,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   213,   368,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   213,   374,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   213,   433,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,     0,   213,   434,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   213,   454,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   213,   469,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   213,   473,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,     0,
       0,   213,   474,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   213,   518,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,     0,     0,     0,     0,     0,     0,     0,     0,   213,
     232,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,     0,
     372,   415,   213,   376,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   213,   373,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,     0,   375,   213,   420,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231
};

static const yytype_int16 yycheck[] =
{
      90,    61,   180,   181,   166,    19,    59,     4,   248,   249,
     384,    71,     4,     4,     4,   182,    10,    10,    78,     4,
      50,   267,     4,   470,     4,   511,     4,   560,     4,     4,
      58,    59,    60,    61,    62,     4,     4,    15,    50,     4,
      15,     4,   575,   529,   121,   447,    99,   100,   125,   102,
     103,     0,   499,   566,    32,   108,     4,    32,   544,    50,
     120,   121,     4,   113,   577,     4,     5,    10,     4,     5,
      48,     4,   474,    15,   113,   135,   136,     4,   138,    37,
     454,    50,    50,   122,    37,    50,   146,    50,    15,    49,
      32,   113,   122,    62,    62,   123,     4,    10,    67,    67,
     122,   113,    49,    16,   164,    32,    48,    15,   354,    89,
     111,   278,   559,   114,   115,   116,    85,    85,    32,    33,
      34,    90,    90,   121,    32,   123,   123,   121,   121,   126,
     121,   121,   192,   193,   126,   195,   196,   377,   123,   121,
     200,   201,   120,   203,   518,   121,   124,   207,   208,   209,
     210,   121,   122,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     3,     4,    49,   120,    87,
     240,   241,   121,   111,   123,   121,   114,   123,   121,   121,
     123,   123,   507,   120,   114,   510,   116,   287,   438,   121,
       4,   123,    30,    31,   107,   108,   109,     4,     5,    37,
      38,    39,   120,     3,     4,   118,    30,    31,    32,    33,
      34,   536,   275,    51,   277,    49,   541,   542,     4,     5,
      58,    59,    60,    61,    62,    63,    37,   121,    39,   123,
      68,    69,    70,    71,    72,    73,   561,    28,    29,    30,
      31,    32,    33,    34,   432,     3,     4,    37,    37,    37,
      37,   117,    10,    37,    37,    37,    94,    37,    37,    37,
      37,    37,   100,     4,     4,   289,     4,     4,     4,     4,
       4,     4,    30,    31,     4,   345,   346,   347,   348,    37,
      38,    39,     3,    96,     4,   123,   458,     4,   126,   127,
       4,     4,     4,    51,     4,     4,     4,     4,    37,     4,
      49,   121,   372,   373,   121,    63,   376,    50,    37,    37,
      68,    69,    70,    71,    72,    73,     6,     7,     8,     9,
      10,    11,    12,    13,    14,   121,    37,   121,     4,    16,
      16,     3,     4,    37,    37,    37,    94,    37,    10,    37,
      37,    37,   100,    37,   414,    10,     4,    37,   122,     4,
     123,   451,   123,   123,   123,   123,   123,   123,    30,    31,
     123,     4,     4,   121,     4,    37,    38,    39,   126,   127,
       4,     4,   442,     4,     4,   475,   446,     4,   448,    51,
      49,    37,   570,   114,    16,     4,    37,    16,   576,     4,
     122,    63,   580,     4,    89,   122,    68,    69,    70,    71,
      72,    73,   121,     3,     4,   123,   476,   123,   508,    79,
      16,    16,    80,    37,    49,   515,    37,   123,    10,    37,
     121,    49,    94,    82,   123,    10,    49,    37,   100,   122,
      30,    31,   123,    16,   123,   123,    37,    37,    38,    39,
      40,   123,   122,    37,    37,   123,    37,     3,     4,   121,
      37,    51,    50,    37,   126,   127,    37,    37,    37,   123,
      16,   123,   562,    63,    25,    16,   123,     4,    68,    69,
      70,    71,    72,    73,    30,    31,   123,   123,   123,    49,
       4,    37,    38,    39,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    50,    94,    51,   110,     3,     4,   170,
     100,   123,   194,   123,   187,   445,   529,    63,     4,   524,
     499,   559,    68,    69,    70,    71,    72,    73,   502,   396,
     422,   347,   550,    -1,    30,    31,   126,   127,   191,    -1,
      -1,    37,    38,    39,    -1,    -1,    -1,    -1,    94,    -1,
       4,    -1,    38,    -1,   100,    51,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    -1,    63,    -1,    55,
      -1,    -1,    68,    69,    70,    71,    72,    73,    32,    -1,
     126,   127,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,
      44,    45,    -1,    -1,    48,    -1,    -1,    -1,    94,    -1,
      -1,     4,    88,    -1,   100,    91,    92,    93,    94,    95,
      96,    97,    98,    99,    -1,   101,   102,   103,   104,   105,
      -1,    -1,    -1,    -1,   110,   111,   112,    81,    -1,    83,
     126,   127,    -1,    87,    -1,    -1,    90,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    66,    67,   119,   120,    -1,   122,    -1,
     124,    74,    75,    76,    77,    78,    79,    -1,     4,    -1,
      -1,    84,    85,    86,    -1,    -1,    15,    90,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,   111,    -1,
      36,     4,    -1,    -1,   117,    -1,    -1,    -1,    -1,   122,
      46,    47,    -1,    -1,    -1,    -1,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      66,    67,    -1,    36,    -1,    38,    -1,    -1,    74,    75,
      76,    77,    78,    79,    -1,    -1,    -1,    -1,    84,    85,
      86,    -1,    55,    15,    90,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,    88,   122,    -1,    91,    92,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,    -1,    -1,    -1,    -1,   110,   111,   112,
      15,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      15,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      15,   123,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      15,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    15,   123,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    15,   123,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,   123,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    15,   123,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    15,   123,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    15,   123,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    15,   123,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    15,   123,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    15,   123,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    15,   123,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
     121,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
     121,    37,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    15,   121,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,   121,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   107,   108,   109,   118,   129,   143,   144,   133,   134,
     131,   132,   222,   223,     0,   145,   135,     4,   113,   226,
     227,     4,    46,    47,    52,    53,    54,    55,    56,    64,
      65,    66,    67,    74,    75,    76,    77,    78,    79,    84,
      85,    86,    90,   111,   122,   146,   150,   152,   168,   170,
     179,   180,   182,   184,   214,   224,   225,     4,    38,    55,
      88,    91,    92,    93,    94,    95,    97,    98,    99,   101,
     102,   103,   104,   105,   110,   111,   112,   136,    10,    49,
     227,     6,     7,     8,     9,    10,    11,    12,    13,    14,
     166,    49,    49,    37,    37,     4,   130,    49,    37,    37,
      37,    37,    37,    37,    37,    37,    37,   147,    37,    37,
      37,   121,   122,   167,   117,     4,   130,     4,     3,     4,
      30,    31,    37,    38,    39,    51,    63,    68,    69,    70,
      71,    72,    73,    94,   100,   126,   127,   188,     4,     4,
     140,     4,   139,   138,     4,     4,     4,   188,     4,     3,
       4,   141,     4,   142,     4,    96,   188,   111,   114,   115,
     116,   229,   230,   186,   187,   186,   151,   215,     4,     4,
     148,     4,   172,     4,   130,   130,     4,   130,   123,   130,
     181,   183,     4,   185,     4,     5,   149,    37,   130,     4,
     142,    49,    10,   121,   137,    10,   121,   188,   188,   188,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,   188,   188,    15,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,   121,    10,   121,   188,   121,   121,     4,   121,
      10,   121,   188,   121,   121,     4,   121,     4,    16,    16,
      50,   122,   188,     4,    50,    62,    85,   152,   190,     4,
      50,   216,   121,   123,   123,   145,   173,   171,   123,   123,
     123,   123,   123,   121,   123,   169,   123,   169,   121,   185,
     123,     4,     5,   121,   123,   149,   123,    10,   123,   226,
     188,   188,   135,   188,   188,   123,   188,   188,     4,   188,
       4,     4,     4,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,     4,
       4,     4,   188,   188,     3,     4,     4,     4,    49,   230,
     230,   113,   122,   228,   114,   191,   196,   201,   217,     4,
      36,    37,   176,    50,   121,   172,   130,   130,   185,     4,
       5,   123,   186,    50,    36,   123,   123,   123,   123,   123,
     123,   123,   121,   121,   123,   121,    16,   231,   122,   122,
     113,   122,    37,    40,   188,   204,   205,    16,   188,   206,
     205,   188,   219,   121,     4,   126,   177,   178,    16,   172,
     123,   188,   188,     4,   188,   230,   116,    58,    59,    60,
      61,    62,   123,   203,    37,    37,   204,    16,    89,   189,
      16,    79,   207,   202,     4,    89,   220,     4,     4,   123,
     178,    80,   174,   123,   123,   123,    50,   122,    16,   123,
     188,    16,    37,   192,   189,    49,    37,   221,    37,   218,
     123,    10,   169,   230,   123,   188,    49,   197,   151,   188,
     220,   188,   122,   186,    82,   175,   122,    39,   204,   123,
     193,    49,    50,   123,   123,    10,    37,    16,     4,    15,
      32,    41,    42,    43,    44,    45,    48,    81,    83,    87,
     119,   120,   122,   124,   153,   154,   156,   159,   161,   162,
     163,   164,   168,   198,   220,   186,   188,    37,    37,    37,
      37,   157,   158,   161,    50,    37,   167,   210,   123,     4,
      87,   120,   153,   186,   160,   153,    48,   154,   155,    37,
     194,   186,     4,    50,   204,   123,    37,   123,   123,     4,
     156,   123,    37,   125,   169,   155,    25,   208,   123,   211,
     199,    16,   153,   123,   153,   154,   123,     4,   209,    49,
     208,   123,    10,    16,   165,   163,   209,   153,   186,     4,
     195,    50,   165,   123,   169,   212,   200,   209,   169,   165,
     213,   169
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   128,   129,   129,   129,   129,   130,   132,   131,   134,
     133,   135,   135,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   137,
     136,   136,   136,   138,   138,   138,   139,   139,   140,   140,
     141,   141,   141,   142,   142,   142,   144,   143,   145,   145,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   147,   146,
     146,   148,   146,   146,   146,   149,   149,   149,   149,   149,
     149,   150,   151,   151,   151,   152,   152,   153,   153,   153,
     154,   154,   154,   154,   155,   155,   156,   157,   156,   158,
     156,   159,   160,   159,   161,   161,   161,   161,   161,   161,
     161,   161,   162,   162,   163,   163,   164,   164,   164,   164,
     164,   165,   165,   166,   166,   166,   166,   166,   166,   166,
     166,   167,   167,   168,   168,   168,   169,   169,   170,   171,
     171,   171,   173,   172,   174,   175,   176,   176,   177,   177,
     178,   178,   179,   180,   180,   181,   181,   182,   183,   183,
     184,   184,   185,   185,   185,   187,   186,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   189,   189,   191,   192,   193,
     194,   195,   190,   196,   197,   198,   199,   200,   190,   201,
     202,   190,   203,   203,   203,   203,   203,   204,   204,   204,
     205,   205,   205,   205,   206,   206,   207,   207,   208,   208,
     209,   209,   210,   211,   212,   213,   210,   214,   215,   215,
     217,   218,   216,   219,   220,   220,   220,   221,   221,   223,
     222,   225,   224,   226,   226,   227,   227,   228,   228,   229,
     229,   229,   229,   229,   230,   230,   231,   230
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     1,     0,     4,     0,
       2,     3,     0,     2,     4,     1,     1,     2,     1,     4,
       4,     3,     2,     4,     3,     4,     4,     4,     4,     4,
       2,     2,     2,     4,     4,     2,     2,     2,     2,     0,
       5,     2,     0,     3,     2,     0,     1,     3,     1,     3,
       0,     1,     3,     1,     2,     3,     0,     2,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     8,     4,     1,     4,     0,     5,
       4,     0,     5,     4,     4,     1,     3,     2,     1,     3,
       2,     4,     2,     2,     0,     4,     2,     1,     1,     1,
       1,     5,     4,     8,     1,     3,     1,     0,     4,     0,
       5,     1,     0,     5,     2,     1,     1,     1,     4,     1,
       4,     4,     2,     1,     0,     1,     1,     1,     1,     1,
       1,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     6,     1,     0,     5,     2,
       3,     0,     0,     7,     3,     3,     0,     3,     1,     2,
       1,     2,     4,     4,     3,     3,     1,     4,     3,     0,
       1,     1,     0,     2,     3,     0,     2,     2,     3,     4,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       3,     3,     4,     1,     1,     4,     4,     4,     4,     4,
       4,     1,     6,     6,     6,     4,     0,     0,     0,     0,
       0,     0,    15,     0,     0,     0,     0,     0,    16,     0,
       0,     7,     1,     1,     1,     1,     1,     3,     0,     2,
       3,     2,     6,    10,     2,     1,     0,     1,     2,     0,
       0,     3,     0,     0,     0,     0,    11,     4,     0,     2,
       0,     0,     6,     1,     0,     3,     5,     0,     3,     0,
       2,     0,     5,     1,     2,     5,     6,     1,     2,     0,
       2,     4,     4,     8,     1,     3,     0,     6
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 7:
#line 162 "ldgram.y" /* yacc.c:1646  */
    { ldlex_defsym(); }
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 164 "ldgram.y" /* yacc.c:1646  */
    {
		  ldlex_popstate();
		  lang_add_assignment(exp_assop((yyvsp[-1].token),(yyvsp[-2].name),(yyvsp[0].etree)));
		}
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 171 "ldgram.y" /* yacc.c:1646  */
    {
		  ldlex_mri_script ();
		  PUSH_ERROR (_("MRI style script"));
		}
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 176 "ldgram.y" /* yacc.c:1646  */
    {
		  ldlex_popstate ();
		  mri_draw_tree ();
		  POP_ERROR ();
		}
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 191 "ldgram.y" /* yacc.c:1646  */
    {
			einfo(_("%P%F: unrecognised keyword in MRI style script '%s'\n"),(yyvsp[0].name));
			}
#line 2100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 194 "ldgram.y" /* yacc.c:1646  */
    {
			config.map_filename = "-";
			}
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 200 "ldgram.y" /* yacc.c:1646  */
    { mri_public((yyvsp[-2].name), (yyvsp[0].etree)); }
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 202 "ldgram.y" /* yacc.c:1646  */
    { mri_public((yyvsp[-2].name), (yyvsp[0].etree)); }
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 204 "ldgram.y" /* yacc.c:1646  */
    { mri_public((yyvsp[-1].name), (yyvsp[0].etree)); }
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 206 "ldgram.y" /* yacc.c:1646  */
    { mri_format((yyvsp[0].name)); }
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 208 "ldgram.y" /* yacc.c:1646  */
    { mri_output_section((yyvsp[-2].name), (yyvsp[0].etree));}
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 210 "ldgram.y" /* yacc.c:1646  */
    { mri_output_section((yyvsp[-1].name), (yyvsp[0].etree));}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 212 "ldgram.y" /* yacc.c:1646  */
    { mri_output_section((yyvsp[-2].name), (yyvsp[0].etree));}
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 214 "ldgram.y" /* yacc.c:1646  */
    { mri_align((yyvsp[-2].name),(yyvsp[0].etree)); }
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 216 "ldgram.y" /* yacc.c:1646  */
    { mri_align((yyvsp[-2].name),(yyvsp[0].etree)); }
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 218 "ldgram.y" /* yacc.c:1646  */
    { mri_alignmod((yyvsp[-2].name),(yyvsp[0].etree)); }
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 220 "ldgram.y" /* yacc.c:1646  */
    { mri_alignmod((yyvsp[-2].name),(yyvsp[0].etree)); }
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 224 "ldgram.y" /* yacc.c:1646  */
    { mri_name((yyvsp[0].name)); }
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 226 "ldgram.y" /* yacc.c:1646  */
    { mri_alias((yyvsp[-2].name),(yyvsp[0].name),0);}
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 228 "ldgram.y" /* yacc.c:1646  */
    { mri_alias((yyvsp[-2].name),0,(int) (yyvsp[0].integer));}
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 230 "ldgram.y" /* yacc.c:1646  */
    { mri_base((yyvsp[0].etree)); }
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 232 "ldgram.y" /* yacc.c:1646  */
    {  mri_truncate((unsigned int) (yyvsp[0].integer)); }
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 236 "ldgram.y" /* yacc.c:1646  */
    { ldfile_open_command_file ((yyvsp[0].name)); }
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 238 "ldgram.y" /* yacc.c:1646  */
    { lang_add_entry ((yyvsp[0].name), false); }
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 243 "ldgram.y" /* yacc.c:1646  */
    { mri_order((yyvsp[0].name)); }
#line 2222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 244 "ldgram.y" /* yacc.c:1646  */
    { mri_order((yyvsp[0].name)); }
#line 2228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 250 "ldgram.y" /* yacc.c:1646  */
    { mri_load((yyvsp[0].name)); }
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 251 "ldgram.y" /* yacc.c:1646  */
    { mri_load((yyvsp[0].name)); }
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 256 "ldgram.y" /* yacc.c:1646  */
    { mri_only_load((yyvsp[0].name)); }
#line 2246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 258 "ldgram.y" /* yacc.c:1646  */
    { mri_only_load((yyvsp[0].name)); }
#line 2252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 262 "ldgram.y" /* yacc.c:1646  */
    { (yyval.name) = NULL; }
#line 2258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 269 "ldgram.y" /* yacc.c:1646  */
    { ldlang_add_undef ((yyvsp[0].name)); }
#line 2264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 271 "ldgram.y" /* yacc.c:1646  */
    { ldlang_add_undef ((yyvsp[0].name)); }
#line 2270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 273 "ldgram.y" /* yacc.c:1646  */
    { ldlang_add_undef ((yyvsp[0].name)); }
#line 2276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 277 "ldgram.y" /* yacc.c:1646  */
    {
	 ldlex_both();
	}
#line 2284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 281 "ldgram.y" /* yacc.c:1646  */
    {
	ldlex_popstate();
	}
#line 2292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 306 "ldgram.y" /* yacc.c:1646  */
    { lang_add_target((yyvsp[-1].name)); }
#line 2298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 308 "ldgram.y" /* yacc.c:1646  */
    { ldfile_add_library_path ((yyvsp[-1].name), false); }
#line 2304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 310 "ldgram.y" /* yacc.c:1646  */
    { lang_add_output((yyvsp[-1].name), 1); }
#line 2310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 312 "ldgram.y" /* yacc.c:1646  */
    { lang_add_output_format ((yyvsp[-1].name), (char *) NULL,
					    (char *) NULL, 1); }
#line 2317 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 315 "ldgram.y" /* yacc.c:1646  */
    { lang_add_output_format ((yyvsp[-5].name), (yyvsp[-3].name), (yyvsp[-1].name), 1); }
#line 2323 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 317 "ldgram.y" /* yacc.c:1646  */
    { ldfile_set_output_arch((yyvsp[-1].name)); }
#line 2329 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 319 "ldgram.y" /* yacc.c:1646  */
    { command_line.force_common_definition = true ; }
#line 2335 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 322 "ldgram.y" /* yacc.c:1646  */
    { lang_enter_group (); }
#line 2341 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 324 "ldgram.y" /* yacc.c:1646  */
    { lang_leave_group (); }
#line 2347 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 326 "ldgram.y" /* yacc.c:1646  */
    { lang_add_map((yyvsp[-1].name)); }
#line 2353 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 328 "ldgram.y" /* yacc.c:1646  */
    { ldfile_open_command_file((yyvsp[0].name)); }
#line 2359 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 330 "ldgram.y" /* yacc.c:1646  */
    {
		  lang_add_nocrossref ((yyvsp[-1].nocrossref));
		}
#line 2367 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 338 "ldgram.y" /* yacc.c:1646  */
    { lang_add_input_file((yyvsp[0].name),lang_input_file_is_search_file_enum,
				 (char *)NULL); }
#line 2374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 341 "ldgram.y" /* yacc.c:1646  */
    { lang_add_input_file((yyvsp[0].name),lang_input_file_is_search_file_enum,
				 (char *)NULL); }
#line 2381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 344 "ldgram.y" /* yacc.c:1646  */
    { lang_add_input_file((yyvsp[0].name),lang_input_file_is_search_file_enum,
				 (char *)NULL); }
#line 2388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 347 "ldgram.y" /* yacc.c:1646  */
    { lang_add_input_file((yyvsp[0].name),lang_input_file_is_l_enum,
				 (char *)NULL); }
#line 2395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 350 "ldgram.y" /* yacc.c:1646  */
    { lang_add_input_file((yyvsp[0].name),lang_input_file_is_l_enum,
				 (char *)NULL); }
#line 2402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 353 "ldgram.y" /* yacc.c:1646  */
    { lang_add_input_file((yyvsp[0].name),lang_input_file_is_l_enum,
				 (char *)NULL); }
#line 2409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 369 "ldgram.y" /* yacc.c:1646  */
    { lang_add_entry ((yyvsp[-1].name), false); }
#line 2415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 377 "ldgram.y" /* yacc.c:1646  */
    {
			  (yyval.cname) = (yyvsp[0].name);
			}
#line 2423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 381 "ldgram.y" /* yacc.c:1646  */
    {
			  (yyval.cname) = "*";
			}
#line 2431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 385 "ldgram.y" /* yacc.c:1646  */
    {
			  (yyval.cname) = "?";
			}
#line 2439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 392 "ldgram.y" /* yacc.c:1646  */
    {
			  (yyval.wildcard).name = (yyvsp[0].cname);
			  (yyval.wildcard).sorted = false;
			  (yyval.wildcard).exclude_name = NULL;
			}
#line 2449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 398 "ldgram.y" /* yacc.c:1646  */
    {
			  (yyval.wildcard).name = (yyvsp[0].cname);
			  (yyval.wildcard).sorted = false;
			  (yyval.wildcard).exclude_name = (yyvsp[-2].cname);
			}
#line 2459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 404 "ldgram.y" /* yacc.c:1646  */
    {
			  (yyval.wildcard).name = (yyvsp[-1].cname);
			  (yyval.wildcard).sorted = true;
			  (yyval.wildcard).exclude_name = NULL;
			}
#line 2469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 410 "ldgram.y" /* yacc.c:1646  */
    {
			  (yyval.wildcard).name = (yyvsp[-1].cname);
			  (yyval.wildcard).sorted = true;
			  (yyval.wildcard).exclude_name = (yyvsp[-3].cname);
			}
#line 2479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 420 "ldgram.y" /* yacc.c:1646  */
    {
			  lang_add_wild ((yyvsp[0].wildcard).name, (yyvsp[0].wildcard).sorted,
					 current_file.name,
					 current_file.sorted,
					 ldgram_had_keep, (yyvsp[0].wildcard).exclude_name);
			}
#line 2490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 427 "ldgram.y" /* yacc.c:1646  */
    {
			  lang_add_wild ((yyvsp[0].wildcard).name, (yyvsp[0].wildcard).sorted,
					 current_file.name,
					 current_file.sorted,
					 ldgram_had_keep, (yyvsp[0].wildcard).exclude_name);
			}
#line 2501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 437 "ldgram.y" /* yacc.c:1646  */
    {
			  lang_add_wild (NULL, false, (yyvsp[0].name), false,
					 ldgram_had_keep, NULL);
			}
#line 2510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 442 "ldgram.y" /* yacc.c:1646  */
    {
			  current_file.name = NULL;
			  current_file.sorted = false;
			}
#line 2519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 448 "ldgram.y" /* yacc.c:1646  */
    {
			  current_file = (yyvsp[0].wildcard);
			  /* '*' matches any file name.  */
			  if (strcmp (current_file.name, "*") == 0)
			    current_file.name = NULL;
			}
#line 2530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 460 "ldgram.y" /* yacc.c:1646  */
    { ldgram_had_keep = true; }
#line 2536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 462 "ldgram.y" /* yacc.c:1646  */
    { ldgram_had_keep = false; }
#line 2542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 468 "ldgram.y" /* yacc.c:1646  */
    {
 		lang_add_attribute(lang_object_symbols_statement_enum); 
	      	}
#line 2550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 473 "ldgram.y" /* yacc.c:1646  */
    {
 		
		  lang_add_attribute(lang_constructors_statement_enum); 
		}
#line 2559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 478 "ldgram.y" /* yacc.c:1646  */
    {
		  constructors_sorted = true;
		  lang_add_attribute (lang_constructors_statement_enum);
		}
#line 2568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 484 "ldgram.y" /* yacc.c:1646  */
    {
			lang_add_data((int) (yyvsp[-3].integer),(yyvsp[-1].etree));
			}
#line 2576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 489 "ldgram.y" /* yacc.c:1646  */
    {
			  lang_add_fill
			    (exp_get_value_int((yyvsp[-1].etree),
					       0,
					       "fill value",
					       lang_first_phase_enum));
			}
#line 2588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 510 "ldgram.y" /* yacc.c:1646  */
    { (yyval.integer) = (yyvsp[0].token); }
#line 2594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 512 "ldgram.y" /* yacc.c:1646  */
    { (yyval.integer) = (yyvsp[0].token); }
#line 2600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 514 "ldgram.y" /* yacc.c:1646  */
    { (yyval.integer) = (yyvsp[0].token); }
#line 2606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 516 "ldgram.y" /* yacc.c:1646  */
    { (yyval.integer) = (yyvsp[0].token); }
#line 2612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 518 "ldgram.y" /* yacc.c:1646  */
    { (yyval.integer) = (yyvsp[0].token); }
#line 2618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 523 "ldgram.y" /* yacc.c:1646  */
    {
		  (yyval.integer) =	 exp_get_value_int((yyvsp[0].etree),
					   0,
					   "fill value",
					   lang_first_phase_enum);
		}
#line 2629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 529 "ldgram.y" /* yacc.c:1646  */
    { (yyval.integer) = 0; }
#line 2635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 536 "ldgram.y" /* yacc.c:1646  */
    { (yyval.token) = '+'; }
#line 2641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 538 "ldgram.y" /* yacc.c:1646  */
    { (yyval.token) = '-'; }
#line 2647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 540 "ldgram.y" /* yacc.c:1646  */
    { (yyval.token) = '*'; }
#line 2653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 542 "ldgram.y" /* yacc.c:1646  */
    { (yyval.token) = '/'; }
#line 2659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 544 "ldgram.y" /* yacc.c:1646  */
    { (yyval.token) = LSHIFT; }
#line 2665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 546 "ldgram.y" /* yacc.c:1646  */
    { (yyval.token) = RSHIFT; }
#line 2671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 548 "ldgram.y" /* yacc.c:1646  */
    { (yyval.token) = '&'; }
#line 2677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 550 "ldgram.y" /* yacc.c:1646  */
    { (yyval.token) = '|'; }
#line 2683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 560 "ldgram.y" /* yacc.c:1646  */
    {
		  lang_add_assignment (exp_assop ((yyvsp[-1].token), (yyvsp[-2].name), (yyvsp[0].etree)));
		}
#line 2691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 564 "ldgram.y" /* yacc.c:1646  */
    {
		  lang_add_assignment (exp_assop ('=', (yyvsp[-2].name),
						  exp_binop ((yyvsp[-1].token),
							     exp_nameop (NAME,
									 (yyvsp[-2].name)),
							     (yyvsp[0].etree))));
		}
#line 2703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 572 "ldgram.y" /* yacc.c:1646  */
    {
		  lang_add_assignment (exp_provide ((yyvsp[-3].name), (yyvsp[-1].etree)));
		}
#line 2711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 594 "ldgram.y" /* yacc.c:1646  */
    { region = lang_memory_region_lookup((yyvsp[0].name)); }
#line 2717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 600 "ldgram.y" /* yacc.c:1646  */
    { region->current =
		 region->origin =
		 exp_get_vma((yyvsp[0].etree), 0L,"origin", lang_first_phase_enum);
}
#line 2726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 608 "ldgram.y" /* yacc.c:1646  */
    { region->length = exp_get_vma((yyvsp[0].etree),
					       ~((bfd_vma)0),
					       "length",
					       lang_first_phase_enum);
		}
#line 2736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 617 "ldgram.y" /* yacc.c:1646  */
    { /* dummy action to avoid bison 1.25 error message */ }
#line 2742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 628 "ldgram.y" /* yacc.c:1646  */
    { lang_set_flags (region, (yyvsp[0].name), 0); }
#line 2748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 630 "ldgram.y" /* yacc.c:1646  */
    { lang_set_flags (region, (yyvsp[0].name), 1); }
#line 2754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 635 "ldgram.y" /* yacc.c:1646  */
    { lang_startup((yyvsp[-1].name)); }
#line 2760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 641 "ldgram.y" /* yacc.c:1646  */
    { ldemul_hll((char *)NULL); }
#line 2766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 646 "ldgram.y" /* yacc.c:1646  */
    { ldemul_hll((yyvsp[0].name)); }
#line 2772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 648 "ldgram.y" /* yacc.c:1646  */
    { ldemul_hll((yyvsp[0].name)); }
#line 2778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 656 "ldgram.y" /* yacc.c:1646  */
    { ldemul_syslib((yyvsp[0].name)); }
#line 2784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 662 "ldgram.y" /* yacc.c:1646  */
    { lang_float(true); }
#line 2790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 664 "ldgram.y" /* yacc.c:1646  */
    { lang_float(false); }
#line 2796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 669 "ldgram.y" /* yacc.c:1646  */
    {
		  (yyval.nocrossref) = NULL;
		}
#line 2804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 673 "ldgram.y" /* yacc.c:1646  */
    {
		  struct lang_nocrossref *n;

		  n = (struct lang_nocrossref *) xmalloc (sizeof *n);
		  n->name = (yyvsp[-1].name);
		  n->next = (yyvsp[0].nocrossref);
		  (yyval.nocrossref) = n;
		}
#line 2817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 682 "ldgram.y" /* yacc.c:1646  */
    {
		  struct lang_nocrossref *n;

		  n = (struct lang_nocrossref *) xmalloc (sizeof *n);
		  n->name = (yyvsp[-2].name);
		  n->next = (yyvsp[0].nocrossref);
		  (yyval.nocrossref) = n;
		}
#line 2830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 692 "ldgram.y" /* yacc.c:1646  */
    { ldlex_expression(); }
#line 2836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 694 "ldgram.y" /* yacc.c:1646  */
    { ldlex_popstate(); (yyval.etree)=(yyvsp[0].etree);}
#line 2842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 699 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_unop('-', (yyvsp[0].etree)); }
#line 2848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 701 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = (yyvsp[-1].etree); }
#line 2854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 703 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_unop((int) (yyvsp[-3].integer),(yyvsp[-1].etree)); }
#line 2860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 705 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_unop('!', (yyvsp[0].etree)); }
#line 2866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 707 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = (yyvsp[0].etree); }
#line 2872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 709 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_unop('~', (yyvsp[0].etree));}
#line 2878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 712 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_binop('*', (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 2884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 714 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_binop('/', (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 2890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 716 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_binop('%', (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 2896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 718 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_binop('+', (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 2902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 720 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_binop('-' , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 2908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 722 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_binop(LSHIFT , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 2914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 724 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_binop(RSHIFT , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 2920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 726 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_binop(EQ , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 2926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 728 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_binop(NE , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 2932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 730 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_binop(LE , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 2938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 732 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_binop(GE , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 2944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 734 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_binop('<' , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 2950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 736 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_binop('>' , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 2956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 738 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_binop('&' , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 2962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 740 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_binop('^' , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 2968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 742 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_binop('|' , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 2974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 744 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_trinop('?' , (yyvsp[-4].etree), (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 2980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 746 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_binop(ANDAND , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 2986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 748 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_binop(OROR , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 2992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 750 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_nameop(DEFINED, (yyvsp[-1].name)); }
#line 2998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 752 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_intop((yyvsp[0].integer)); }
#line 3004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 754 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_nameop(SIZEOF_HEADERS,0); }
#line 3010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 757 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_nameop(SIZEOF,(yyvsp[-1].name)); }
#line 3016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 759 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_nameop(ADDR,(yyvsp[-1].name)); }
#line 3022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 761 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_nameop(LOADADDR,(yyvsp[-1].name)); }
#line 3028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 763 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_unop(ABSOLUTE, (yyvsp[-1].etree)); }
#line 3034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 765 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_unop(ALIGN_K,(yyvsp[-1].etree)); }
#line 3040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 767 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_unop(ALIGN_K,(yyvsp[-1].etree)); }
#line 3046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 769 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_nameop(NAME,(yyvsp[0].name)); }
#line 3052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 771 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_binop (MAX_K, (yyvsp[-3].etree), (yyvsp[-1].etree) ); }
#line 3058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 773 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_binop (MIN_K, (yyvsp[-3].etree), (yyvsp[-1].etree) ); }
#line 3064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 775 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = exp_assert ((yyvsp[-3].etree), (yyvsp[-1].name)); }
#line 3070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 780 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = (yyvsp[-1].etree); }
#line 3076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 781 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = 0; }
#line 3082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 784 "ldgram.y" /* yacc.c:1646  */
    { ldlex_expression(); }
#line 3088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 786 "ldgram.y" /* yacc.c:1646  */
    { ldlex_popstate (); ldlex_script (); }
#line 3094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 788 "ldgram.y" /* yacc.c:1646  */
    {
			  lang_enter_output_section_statement((yyvsp[-5].name), (yyvsp[-3].etree),
							      sectype,
							      0, 0, 0, (yyvsp[-2].etree));
			}
#line 3104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 794 "ldgram.y" /* yacc.c:1646  */
    { ldlex_popstate (); ldlex_expression (); }
#line 3110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 796 "ldgram.y" /* yacc.c:1646  */
    {
		  ldlex_popstate ();
		  lang_leave_output_section_statement ((yyvsp[0].integer), (yyvsp[-2].name), (yyvsp[-1].section_phdr));
		}
#line 3119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 802 "ldgram.y" /* yacc.c:1646  */
    { ldlex_expression (); }
#line 3125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 804 "ldgram.y" /* yacc.c:1646  */
    { ldlex_popstate (); ldlex_script (); }
#line 3131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 806 "ldgram.y" /* yacc.c:1646  */
    {
			  lang_enter_overlay ((yyvsp[-4].etree), (yyvsp[-2].etree), (int) (yyvsp[-3].integer));
			}
#line 3139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 811 "ldgram.y" /* yacc.c:1646  */
    { ldlex_popstate (); ldlex_expression (); }
#line 3145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 813 "ldgram.y" /* yacc.c:1646  */
    {
			  ldlex_popstate ();
			  lang_leave_overlay ((yyvsp[0].integer), (yyvsp[-2].name), (yyvsp[-1].section_phdr));
			}
#line 3154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 822 "ldgram.y" /* yacc.c:1646  */
    { ldlex_expression (); }
#line 3160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 824 "ldgram.y" /* yacc.c:1646  */
    {
		  ldlex_popstate ();
		  lang_add_assignment (exp_assop ('=', ".", (yyvsp[0].etree)));
		}
#line 3169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 832 "ldgram.y" /* yacc.c:1646  */
    { sectype = noload_section; }
#line 3175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 833 "ldgram.y" /* yacc.c:1646  */
    { sectype = dsect_section; }
#line 3181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 834 "ldgram.y" /* yacc.c:1646  */
    { sectype = copy_section; }
#line 3187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 835 "ldgram.y" /* yacc.c:1646  */
    { sectype = info_section; }
#line 3193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 836 "ldgram.y" /* yacc.c:1646  */
    { sectype = overlay_section; }
#line 3199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 841 "ldgram.y" /* yacc.c:1646  */
    { sectype = normal_section; }
#line 3205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 842 "ldgram.y" /* yacc.c:1646  */
    { sectype = normal_section; }
#line 3211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 846 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = (yyvsp[-2].etree); }
#line 3217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 847 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = (etree_type *)NULL;  }
#line 3223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 852 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = (yyvsp[-3].etree); }
#line 3229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 854 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = (yyvsp[-7].etree); }
#line 3235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 858 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = (yyvsp[-1].etree); }
#line 3241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 859 "ldgram.y" /* yacc.c:1646  */
    { (yyval.etree) = (etree_type *) NULL;  }
#line 3247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 864 "ldgram.y" /* yacc.c:1646  */
    { (yyval.integer) = 0; }
#line 3253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 866 "ldgram.y" /* yacc.c:1646  */
    { (yyval.integer) = 1; }
#line 3259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 871 "ldgram.y" /* yacc.c:1646  */
    { (yyval.name) = (yyvsp[0].name); }
#line 3265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 872 "ldgram.y" /* yacc.c:1646  */
    { (yyval.name) = "*default*"; }
#line 3271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 877 "ldgram.y" /* yacc.c:1646  */
    {
		  (yyval.section_phdr) = NULL;
		}
#line 3279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 881 "ldgram.y" /* yacc.c:1646  */
    {
		  struct lang_output_section_phdr_list *n;

		  n = ((struct lang_output_section_phdr_list *)
		       xmalloc (sizeof *n));
		  n->name = (yyvsp[0].name);
		  n->used = false;
		  n->next = (yyvsp[-2].section_phdr);
		  (yyval.section_phdr) = n;
		}
#line 3294 "y.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 897 "ldgram.y" /* yacc.c:1646  */
    {
			  ldlex_script ();
			  lang_enter_overlay_section ((yyvsp[0].name));
			}
#line 3303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 902 "ldgram.y" /* yacc.c:1646  */
    { ldlex_popstate (); ldlex_expression (); }
#line 3309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 904 "ldgram.y" /* yacc.c:1646  */
    {
			  ldlex_popstate ();
			  lang_leave_overlay_section ((yyvsp[0].integer), (yyvsp[-1].section_phdr));
			}
#line 3318 "y.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 921 "ldgram.y" /* yacc.c:1646  */
    { ldlex_expression (); }
#line 3324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 922 "ldgram.y" /* yacc.c:1646  */
    { ldlex_popstate (); }
#line 3330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 924 "ldgram.y" /* yacc.c:1646  */
    {
		  lang_new_phdr ((yyvsp[-5].name), (yyvsp[-3].etree), (yyvsp[-2].phdr).filehdr, (yyvsp[-2].phdr).phdrs, (yyvsp[-2].phdr).at,
				 (yyvsp[-2].phdr).flags);
		}
#line 3339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 932 "ldgram.y" /* yacc.c:1646  */
    {
		  (yyval.etree) = (yyvsp[0].etree);

		  if ((yyvsp[0].etree)->type.node_class == etree_name
		      && (yyvsp[0].etree)->type.node_code == NAME)
		    {
		      const char *s;
		      unsigned int i;
		      static const char * const phdr_types[] =
			{
			  "PT_NULL", "PT_LOAD", "PT_DYNAMIC",
			  "PT_INTERP", "PT_NOTE", "PT_SHLIB",
			  "PT_PHDR"
			};

		      s = (yyvsp[0].etree)->name.name;
		      for (i = 0;
			   i < sizeof phdr_types / sizeof phdr_types[0];
			   i++)
			if (strcmp (s, phdr_types[i]) == 0)
			  {
			    (yyval.etree) = exp_intop (i);
			    break;
			  }
		    }
		}
#line 3370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 962 "ldgram.y" /* yacc.c:1646  */
    {
		  memset (&(yyval.phdr), 0, sizeof (struct phdr_info));
		}
#line 3378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 265:
#line 966 "ldgram.y" /* yacc.c:1646  */
    {
		  (yyval.phdr) = (yyvsp[0].phdr);
		  if (strcmp ((yyvsp[-2].name), "FILEHDR") == 0 && (yyvsp[-1].etree) == NULL)
		    (yyval.phdr).filehdr = true;
		  else if (strcmp ((yyvsp[-2].name), "PHDRS") == 0 && (yyvsp[-1].etree) == NULL)
		    (yyval.phdr).phdrs = true;
		  else if (strcmp ((yyvsp[-2].name), "FLAGS") == 0 && (yyvsp[-1].etree) != NULL)
		    (yyval.phdr).flags = (yyvsp[-1].etree);
		  else
		    einfo (_("%X%P:%S: PHDRS syntax error at `%s'\n"), (yyvsp[-2].name));
		}
#line 3394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 266:
#line 978 "ldgram.y" /* yacc.c:1646  */
    {
		  (yyval.phdr) = (yyvsp[0].phdr);
		  (yyval.phdr).at = (yyvsp[-2].etree);
		}
#line 3403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 267:
#line 986 "ldgram.y" /* yacc.c:1646  */
    {
		  (yyval.etree) = NULL;
		}
#line 3411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 268:
#line 990 "ldgram.y" /* yacc.c:1646  */
    {
		  (yyval.etree) = (yyvsp[-1].etree);
		}
#line 3419 "y.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 998 "ldgram.y" /* yacc.c:1646  */
    {
		  ldlex_version_file ();
		  PUSH_ERROR (_("VERSION script"));
		}
#line 3428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1003 "ldgram.y" /* yacc.c:1646  */
    {
		  ldlex_popstate ();
		  POP_ERROR ();
		}
#line 3437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1012 "ldgram.y" /* yacc.c:1646  */
    {
		  ldlex_version_script ();
		}
#line 3445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1016 "ldgram.y" /* yacc.c:1646  */
    {
		  ldlex_popstate ();
		}
#line 3453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1028 "ldgram.y" /* yacc.c:1646  */
    {
		  lang_register_vers_node ((yyvsp[-4].name), (yyvsp[-2].versnode), NULL);
		}
#line 3461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1032 "ldgram.y" /* yacc.c:1646  */
    {
		  lang_register_vers_node ((yyvsp[-5].name), (yyvsp[-3].versnode), (yyvsp[-1].deflist));
		}
#line 3469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 277:
#line 1039 "ldgram.y" /* yacc.c:1646  */
    {
		  (yyval.deflist) = lang_add_vers_depend (NULL, (yyvsp[0].name));
		}
#line 3477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 278:
#line 1043 "ldgram.y" /* yacc.c:1646  */
    {
		  (yyval.deflist) = lang_add_vers_depend ((yyvsp[-1].deflist), (yyvsp[0].name));
		}
#line 3485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1050 "ldgram.y" /* yacc.c:1646  */
    {
		  (yyval.versnode) = lang_new_vers_node (NULL, NULL);
		}
#line 3493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1054 "ldgram.y" /* yacc.c:1646  */
    {
		  (yyval.versnode) = lang_new_vers_node ((yyvsp[-1].versyms), NULL);
		}
#line 3501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1058 "ldgram.y" /* yacc.c:1646  */
    {
		  (yyval.versnode) = lang_new_vers_node ((yyvsp[-1].versyms), NULL);
		}
#line 3509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1062 "ldgram.y" /* yacc.c:1646  */
    {
		  (yyval.versnode) = lang_new_vers_node (NULL, (yyvsp[-1].versyms));
		}
#line 3517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1066 "ldgram.y" /* yacc.c:1646  */
    {
		  (yyval.versnode) = lang_new_vers_node ((yyvsp[-5].versyms), (yyvsp[-1].versyms));
		}
#line 3525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1073 "ldgram.y" /* yacc.c:1646  */
    {
		  (yyval.versyms) = lang_new_vers_regex (NULL, (yyvsp[0].name), ldgram_vers_current_lang);
		}
#line 3533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1077 "ldgram.y" /* yacc.c:1646  */
    {
		  (yyval.versyms) = lang_new_vers_regex ((yyvsp[-2].versyms), (yyvsp[0].name), ldgram_vers_current_lang);
		}
#line 3541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 286:
#line 1081 "ldgram.y" /* yacc.c:1646  */
    {
			  (yyval.name) = ldgram_vers_current_lang;
			  ldgram_vers_current_lang = (yyvsp[-1].name);
			}
#line 3550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1086 "ldgram.y" /* yacc.c:1646  */
    {
			  ldgram_vers_current_lang = (yyvsp[-2].name);
			}
#line 3558 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3562 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1091 "ldgram.y" /* yacc.c:1906  */

void
yyerror(arg) 
     const char *arg;
{ 
  if (ldfile_assumed_script)
    einfo (_("%P:%s: file format not recognized; treating as linker script\n"),
	   ldfile_input_filename);
  if (error_index > 0 && error_index < ERROR_NAME_MAX)
     einfo ("%P%F:%S: %s in %s\n", arg, error_names[error_index-1]);
  else
     einfo ("%P%F:%S: %s\n", arg);
}
