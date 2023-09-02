
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"


#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "biblioteca.h"
#define YYDEBUG 1

FILE* yyin;
detalleSentencia *ListaSentencias = NULL;
detalleDeclaraciones *ListaDeclaraciones = NULL;
detalleFunciones *ListaFunciones = NULL;

int nroLineaAnterior=1;
char tipo[20];

int yylex();
int yyerror (char *s);

int yywrap(){
  return(1);
}



/* Line 189 of yacc.c  */
#line 100 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CONSTANTE_OCTAL = 258,
     CONSTANTE_DECIMAL = 259,
     CONSTANTE_HEXADECIMAL = 260,
     CONSTANTE_REAL = 261,
     CONSTANTE_CARACTER = 262,
     OR = 263,
     AND = 264,
     IGUALIGUAL = 265,
     DIFERENTE = 266,
     MAYORIGUAL = 267,
     MENORIGUAL = 268,
     MASIGUAL = 269,
     MENOSIGUAL = 270,
     PORIGUAL = 271,
     DIVISIONGUAL = 272,
     MASMAS = 273,
     MENOSMENOS = 274,
     FLECHA = 275,
     AUTO = 276,
     TYPEDEF = 277,
     STATIC = 278,
     REGISTER = 279,
     EXTERN = 280,
     ENUM = 281,
     SIZEOF = 282,
     UNION = 283,
     STRUCT = 284,
     GOTO = 285,
     RETURN = 286,
     CONTINUE = 287,
     BREAK = 288,
     VOLATILE = 289,
     CONST = 290,
     WHILE = 291,
     DO = 292,
     FOR = 293,
     IF = 294,
     ELSE = 295,
     SWITCH = 296,
     CASE = 297,
     DEFAULT = 298,
     VOID = 299,
     CHAR = 300,
     DOUBLE = 301,
     FLOAT = 302,
     INT = 303,
     LONG = 304,
     SHORT = 305,
     SIGNED = 306,
     UNSIGNED = 307,
     IDENTIFICADOR = 308,
     LITERAL_CADENA = 309,
     COMENTARIO_UNA_LINEA = 310,
     COMENTARIO_VARIAS_LINEAS = 311
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 53 "parser.y"

  struct {
    char* cadena;
    int entero;
  } myStruct;



/* Line 214 of yacc.c  */
#line 201 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 213 "parser.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   760

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  173
/* YYNRULES -- Number of states.  */
#define YYNSTATES  308

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    74,     2,     2,     2,    72,    73,     2,
      58,    59,    70,    68,    60,    69,    77,    71,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    63,    57,
      66,    64,    67,    65,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    75,     2,    76,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,    62,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    14,    16,    18,
      21,    23,    25,    31,    36,    42,    47,    49,    53,    59,
      66,    72,    79,    82,    83,    89,    91,    93,    95,    97,
      99,   101,   104,   108,   111,   113,   116,   123,   129,   130,
     133,   139,   147,   153,   159,   164,   169,   174,   178,   182,
     185,   188,   190,   195,   199,   203,   206,   209,   213,   216,
     219,   224,   230,   235,   240,   242,   243,   249,   250,   256,
     259,   261,   264,   265,   270,   271,   278,   282,   284,   286,
     288,   290,   292,   294,   297,   300,   302,   304,   307,   309,
     312,   314,   316,   318,   320,   322,   324,   326,   328,   330,
     336,   341,   347,   352,   356,   361,   363,   366,   367,   372,
     374,   375,   382,   383,   388,   390,   392,   394,   398,   400,
     402,   404,   406,   408,   410,   416,   418,   422,   424,   428,
     430,   434,   438,   440,   444,   448,   452,   456,   458,   462,
     466,   468,   472,   476,   480,   482,   485,   488,   491,   494,
     496,   498,   500,   502,   504,   506,   511,   516,   520,   524,
     528,   531,   534,   536,   540,   542,   544,   546,   550,   552,
     554,   556,   558,   560
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      79,     0,    -1,    -1,    79,    80,    -1,    87,    -1,    98,
      -1,    82,    57,    -1,    84,    -1,    81,    -1,     1,    57,
      -1,    55,    -1,    56,    -1,    44,    53,    58,    83,    59,
      -1,    44,    53,    58,    59,    -1,   109,    53,    58,    83,
      59,    -1,   109,    53,    58,    59,    -1,   109,    -1,   109,
      60,    83,    -1,    44,    53,    58,    59,    87,    -1,    44,
      53,    58,    85,    59,    87,    -1,   109,    53,    58,    59,
      87,    -1,   109,    53,    58,    85,    59,    87,    -1,   109,
      53,    -1,    -1,   109,    53,    60,    86,    85,    -1,    88,
      -1,    89,    -1,    91,    -1,    93,    -1,    96,    -1,    97,
      -1,   120,    57,    -1,    61,    90,    62,    -1,    61,    62,
      -1,    80,    -1,    90,    80,    -1,    39,    58,   120,    59,
      87,    92,    -1,    41,    58,   120,    59,    87,    -1,    -1,
      40,    87,    -1,    36,    58,   120,    59,    87,    -1,    37,
      80,    36,    58,   120,    59,    57,    -1,    38,    58,    94,
      59,    87,    -1,    95,    57,   120,    57,   120,    -1,    57,
     120,    57,   120,    -1,    95,    57,    57,   120,    -1,    95,
      57,   120,    57,    -1,    57,    57,   120,    -1,    95,    57,
      57,    -1,    57,    57,    -1,   109,   102,    -1,   102,    -1,
      42,   135,    63,    87,    -1,    43,    63,    87,    -1,    53,
      63,    87,    -1,    33,    57,    -1,    32,    57,    -1,    31,
     120,    57,    -1,    31,    57,    -1,    30,    57,    -1,   106,
     109,    53,    57,    -1,   106,   110,   109,    53,    57,    -1,
     106,   111,    53,    57,    -1,   106,   116,    53,    57,    -1,
      99,    -1,    -1,   110,   109,   100,   102,    57,    -1,    -1,
     110,   108,   101,   102,    57,    -1,   107,    57,    -1,   103,
      -1,   102,   103,    -1,    -1,    53,    60,   104,   103,    -1,
      -1,    53,    64,   120,    60,   105,   103,    -1,    53,    64,
     120,    -1,    53,    -1,    22,    -1,    23,    -1,    21,    -1,
      24,    -1,    25,    -1,   109,   102,    -1,   108,   102,    -1,
     111,    -1,   116,    -1,    51,   109,    -1,    51,    -1,    52,
     109,    -1,    52,    -1,    45,    -1,    46,    -1,    47,    -1,
      48,    -1,    49,    -1,    50,    -1,    35,    -1,    34,    -1,
      29,    53,    61,   112,    62,    -1,    29,    61,   112,    62,
      -1,    28,    53,    61,   112,    62,    -1,    28,    61,   112,
      62,    -1,   109,   113,    57,    -1,   109,   113,    57,   112,
      -1,   114,    -1,   113,   114,    -1,    -1,    53,    60,   115,
     114,    -1,    53,    -1,    -1,    26,    53,   117,    61,   118,
      62,    -1,    -1,    53,    60,   119,   118,    -1,    53,    -1,
     121,    -1,   123,    -1,   130,   122,   121,    -1,    64,    -1,
      14,    -1,    15,    -1,    16,    -1,    17,    -1,   124,    -1,
     124,    65,   120,    63,   123,    -1,   125,    -1,   125,     8,
     124,    -1,   126,    -1,   126,     9,   125,    -1,   127,    -1,
     127,    10,   126,    -1,   127,    11,   126,    -1,   128,    -1,
     128,    66,   127,    -1,   128,    67,   127,    -1,   128,    12,
     127,    -1,   128,    13,   127,    -1,   129,    -1,   129,    68,
     128,    -1,   129,    69,   128,    -1,   130,    -1,   130,    70,
     130,    -1,   130,    71,   130,    -1,   130,    72,   130,    -1,
     132,    -1,    18,   130,    -1,    19,   130,    -1,   131,   130,
      -1,    27,   130,    -1,    73,    -1,    70,    -1,    68,    -1,
      69,    -1,    74,    -1,   134,    -1,   132,    75,   120,    76,
      -1,   132,    58,   133,    59,    -1,   132,    58,    59,    -1,
     132,    77,    53,    -1,   132,    20,    53,    -1,   132,    18,
      -1,   132,    19,    -1,   121,    -1,   121,    60,   133,    -1,
      53,    -1,   135,    -1,    54,    -1,    58,   120,    59,    -1,
     136,    -1,     7,    -1,     6,    -1,     3,    -1,     4,    -1,
       5,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    64,    67,    68,    69,    70,    71,    72,
      75,    76,    81,    82,    83,    84,    87,    88,    91,    92,
      93,    94,    97,    98,    98,   105,   106,   107,   108,   109,
     110,   113,   116,   117,   120,   121,   124,   125,   128,   129,
     132,   133,   134,   137,   138,   139,   140,   141,   142,   143,
     146,   147,   150,   151,   152,   155,   156,   157,   158,   159,
     165,   166,   167,   168,   169,   172,   172,   173,   173,   174,
     177,   178,   181,   181,   182,   182,   183,   184,   187,   188,
     189,   190,   191,   194,   195,   196,   197,   200,   201,   202,
     203,   206,   207,   208,   209,   210,   211,   214,   215,   218,
     219,   220,   221,   224,   225,   228,   229,   232,   232,   233,
     236,   236,   239,   239,   240,   246,   249,   250,   253,   254,
     255,   256,   257,   260,   261,   264,   265,   268,   269,   272,
     273,   274,   277,   278,   279,   280,   281,   284,   285,   286,
     289,   290,   291,   292,   295,   296,   297,   298,   299,   302,
     303,   304,   305,   306,   309,   310,   311,   312,   313,   314,
     315,   316,   319,   320,   323,   324,   325,   326,   329,   330,
     331,   334,   335,   336
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONSTANTE_OCTAL", "CONSTANTE_DECIMAL",
  "CONSTANTE_HEXADECIMAL", "CONSTANTE_REAL", "CONSTANTE_CARACTER", "OR",
  "AND", "IGUALIGUAL", "DIFERENTE", "MAYORIGUAL", "MENORIGUAL", "MASIGUAL",
  "MENOSIGUAL", "PORIGUAL", "DIVISIONGUAL", "MASMAS", "MENOSMENOS",
  "FLECHA", "AUTO", "TYPEDEF", "STATIC", "REGISTER", "EXTERN", "ENUM",
  "SIZEOF", "UNION", "STRUCT", "GOTO", "RETURN", "CONTINUE", "BREAK",
  "VOLATILE", "CONST", "WHILE", "DO", "FOR", "IF", "ELSE", "SWITCH",
  "CASE", "DEFAULT", "VOID", "CHAR", "DOUBLE", "FLOAT", "INT", "LONG",
  "SHORT", "SIGNED", "UNSIGNED", "IDENTIFICADOR", "LITERAL_CADENA",
  "COMENTARIO_UNA_LINEA", "COMENTARIO_VARIAS_LINEAS", "';'", "'('", "')'",
  "','", "'{'", "'}'", "':'", "'='", "'?'", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'&'", "'!'", "'['", "']'", "'.'", "$accept",
  "input", "line", "noC", "prototipo", "parametrosPrototipo", "funciones",
  "parametrosFuncion", "$@1", "sentencia", "sentExpresion",
  "sentCompuesta", "listaSentencias", "sentSeleccion", "sentElse",
  "sentIteracion", "cuerpoFor", "declaracionFor", "sentEtiquetado",
  "sentSalto", "declaracion", "espDeclaracion", "$@2", "$@3",
  "variasVariables", "inicializacion", "$@4", "$@5", "espAlmacenamiento",
  "declaraciones", "espSigno", "tipoDeDato", "calificadorTipo",
  "espStructUnion", "declaracionesStruct", "variasVariablesStruct",
  "inicializacionStruct", "$@6", "espEnum", "$@7", "listaIdentificadores",
  "$@8", "expresion", "expAsignacion", "operAsig", "expCondicional",
  "expOr", "expAnd", "expIgualdad", "expRelacional", "expAditiva",
  "expMultiplicativa", "expUnaria", "operUnario", "expSufijo",
  "listaArgumentos", "expPrimaria", "constante", "constanteEntera", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,    59,    40,    41,
      44,   123,   125,    58,    61,    63,    60,    62,    43,    45,
      42,    47,    37,    38,    33,    91,    93,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    78,    79,    79,    80,    80,    80,    80,    80,    80,
      81,    81,    82,    82,    82,    82,    83,    83,    84,    84,
      84,    84,    85,    86,    85,    87,    87,    87,    87,    87,
      87,    88,    89,    89,    90,    90,    91,    91,    92,    92,
      93,    93,    93,    94,    94,    94,    94,    94,    94,    94,
      95,    95,    96,    96,    96,    97,    97,    97,    97,    97,
      98,    98,    98,    98,    98,   100,    99,   101,    99,    99,
     102,   102,   104,   103,   105,   103,   103,   103,   106,   106,
     106,   106,   106,   107,   107,   107,   107,   108,   108,   108,
     108,   109,   109,   109,   109,   109,   109,   110,   110,   111,
     111,   111,   111,   112,   112,   113,   113,   115,   114,   114,
     117,   116,   119,   118,   118,   120,   121,   121,   122,   122,
     122,   122,   122,   123,   123,   124,   124,   125,   125,   126,
     126,   126,   127,   127,   127,   127,   127,   128,   128,   128,
     129,   129,   129,   129,   130,   130,   130,   130,   130,   131,
     131,   131,   131,   131,   132,   132,   132,   132,   132,   132,
     132,   132,   133,   133,   134,   134,   134,   134,   135,   135,
     135,   136,   136,   136
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     2,     1,     1,     2,
       1,     1,     5,     4,     5,     4,     1,     3,     5,     6,
       5,     6,     2,     0,     5,     1,     1,     1,     1,     1,
       1,     2,     3,     2,     1,     2,     6,     5,     0,     2,
       5,     7,     5,     5,     4,     4,     4,     3,     3,     2,
       2,     1,     4,     3,     3,     2,     2,     3,     2,     2,
       4,     5,     4,     4,     1,     0,     5,     0,     5,     2,
       1,     2,     0,     4,     0,     6,     3,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       4,     5,     4,     3,     4,     1,     2,     0,     4,     1,
       0,     6,     0,     4,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     5,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     4,     4,     3,     3,     3,
       2,     2,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,   171,   172,   173,   170,   169,     0,
       0,    80,    78,    79,    81,    82,     0,     0,     0,     0,
       0,     0,     0,     0,    98,    97,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,    95,    96,
      88,    90,   164,   166,    10,    11,     0,     0,   151,   152,
     150,   149,   153,     3,     8,     0,     7,     4,    25,    26,
      27,    28,    29,    30,     5,    64,     0,     0,     0,     0,
       0,    85,    86,     0,   115,   116,   123,   125,   127,   129,
     132,   137,   140,     0,   144,   154,   165,   168,     9,   164,
     145,   146,   110,   148,     0,     0,     0,     0,    59,    58,
       0,    56,    55,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    89,     0,     0,    33,    34,     0,     6,     0,
       0,     0,     0,    69,    77,    84,    70,    77,    83,    67,
      65,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   119,   120,   121,   122,   118,     0,     0,
       0,     0,   147,   160,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    57,     0,     0,     0,     0,
       0,    51,     0,     0,     0,     0,    53,     0,    54,   167,
      32,    35,     0,     0,     0,     0,    72,     0,    71,     0,
       0,     0,     0,   126,   140,   128,   130,   131,   135,   136,
     133,   134,   138,   139,   141,   142,   143,   117,   159,   157,
     162,     0,     0,   158,     0,     0,   109,     0,   105,   102,
       0,   100,     0,     0,    49,     0,     0,     0,    50,     0,
       0,    52,    13,     0,     0,    16,    60,     0,    62,    63,
       0,    76,    15,     0,     0,     0,     0,     0,     0,   156,
     155,   114,     0,   101,   107,   103,   106,    99,    40,     0,
      47,     0,    42,    48,     0,    38,    37,    18,    12,     0,
      22,     0,    61,    73,    74,    20,    14,     0,    68,    66,
     124,   163,   112,   111,     0,   104,     0,    44,    45,    46,
       0,    36,    19,    23,    17,    16,     0,    21,     0,   108,
      41,    43,    39,     0,    75,   113,    24,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    53,    54,    55,   233,    56,   234,   303,    57,
      58,    59,   117,    60,   291,    61,   169,   170,    62,    63,
      64,    65,   191,   190,   125,   126,   240,   296,    66,    67,
      68,   161,    70,    71,   162,   217,   218,   284,    72,   159,
     252,   298,    73,    74,   151,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,   211,    85,    86,    87
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -211
static const yytype_int16 yypact[] =
{
    -211,   262,  -211,   -21,  -211,  -211,  -211,  -211,  -211,   686,
     686,  -211,  -211,  -211,  -211,  -211,    -6,   686,   -39,   -37,
       9,   572,    11,    16,  -211,  -211,   -31,   469,    19,    33,
      43,    51,    50,    -4,  -211,  -211,  -211,  -211,  -211,  -211,
     177,   177,    52,  -211,  -211,  -211,   686,   321,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,    60,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,   132,    65,    70,    71,
     168,  -211,  -211,    78,  -211,  -211,    73,   135,   136,    76,
       5,   -57,    28,   686,     1,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,    85,   177,    86,   177,  -211,  -211,
      92,  -211,  -211,   686,   119,   147,   686,   686,    93,   528,
      99,  -211,  -211,   528,   100,  -211,  -211,   395,  -211,   110,
     177,   115,   130,  -211,   -35,    70,  -211,   -26,    70,  -211,
    -211,  -211,   686,   686,   686,   686,   686,   686,   686,   686,
     686,   686,   686,  -211,  -211,  -211,  -211,  -211,   686,   686,
     686,   686,  -211,  -211,  -211,   131,   600,   686,   133,   124,
     177,   134,   127,   177,   128,  -211,   139,   143,   629,   144,
     145,    70,    70,   148,   149,   528,  -211,    34,  -211,  -211,
    -211,  -211,   153,   158,   171,   172,  -211,   686,  -211,    62,
      70,    70,   167,  -211,    -9,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
     173,   175,   155,  -211,   179,   174,   178,   -16,  -211,  -211,
     180,  -211,   528,   686,   686,   183,   528,   657,    70,   528,
     528,  -211,   528,   176,   182,   -30,  -211,   187,  -211,  -211,
      70,   186,   528,   188,   189,    -5,     7,   686,   686,  -211,
    -211,   190,   191,  -211,  -211,   177,  -211,  -211,  -211,   192,
    -211,   686,  -211,   686,   195,   197,  -211,  -211,  -211,   528,
     194,   177,  -211,  -211,  -211,  -211,  -211,   528,  -211,  -211,
    -211,  -211,  -211,  -211,   134,  -211,   198,  -211,  -211,   686,
     528,  -211,  -211,  -211,  -211,   196,    70,  -211,   179,  -211,
    -211,  -211,  -211,   177,  -211,  -211,  -211,   204
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -211,  -211,   -14,  -211,  -211,  -181,  -211,  -183,  -211,   -78,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,   -54,   -75,  -211,  -211,  -211,  -211,
     202,    -1,   193,   207,   -93,  -211,  -210,  -211,   208,  -211,
     -49,  -211,   -18,  -146,  -211,    13,   125,   141,   -41,    35,
     -36,  -211,    -8,  -211,  -211,    29,  -211,   230,  -211
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      69,    90,    91,   100,   164,   207,   244,   256,   243,    93,
     210,   141,   142,   104,    94,   128,    96,   137,   138,   153,
     154,   155,    95,   270,    97,   186,    69,   103,   114,   187,
     271,   176,   189,   116,   186,   178,    88,   216,   187,   111,
     112,   255,   143,   144,   145,   146,    69,    92,   124,   110,
     188,   171,   278,   188,     4,     5,     6,     7,     8,   156,
     124,   148,   149,   150,   279,   119,    98,   215,   101,   130,
     220,   139,   140,   102,   299,   152,   157,   105,   158,    34,
      35,    36,    37,    38,    39,   166,   135,   136,   173,   174,
     294,   106,   147,   232,   196,   197,   188,   231,   148,   149,
     150,   107,   210,   181,   172,   202,   203,    34,    35,    36,
      37,    38,    39,   109,   192,   113,    69,   118,   228,   183,
     306,   242,   123,   124,   127,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   131,   245,   246,   132,   212,
     204,   205,   206,   133,   258,   134,   160,   163,   262,   165,
     225,   265,   266,   188,   267,   167,   175,   177,    16,   179,
      18,    19,   285,   182,   275,   273,    24,    25,   184,   241,
     188,   188,   198,   199,   200,   201,   235,    34,    35,    36,
      37,    38,    39,   185,   208,   214,   213,   216,   235,   219,
     221,   292,    34,    35,    36,    37,    38,    39,   222,   297,
     124,   223,   227,   226,   168,   259,   260,   229,   230,   264,
     236,   237,   302,    34,    35,    36,    37,    38,    39,    40,
      41,   304,    34,    35,    36,    37,    38,    39,   238,   239,
     247,   250,   251,   248,   249,   268,   253,   290,   254,   194,
     261,   269,   257,   287,   272,   288,   274,   276,   277,   305,
     282,   286,   289,   283,   293,   300,   271,   270,   193,   120,
     280,   108,     2,     3,     0,     4,     5,     6,     7,     8,
     295,   301,   129,   121,   122,   195,     0,   281,     0,     0,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,   307,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,     0,
      46,     0,     3,    47,     4,     5,     6,     7,     8,     0,
      48,    49,    50,     0,     0,    51,    52,     0,     0,     9,
      10,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     0,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,     0,    46,
       0,     0,    47,   115,     0,     0,     0,     0,     0,    48,
      49,    50,     0,     0,    51,    52,     3,     0,     4,     5,
       6,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,    10,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     0,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,     0,    46,     0,     0,    47,   180,     0,     0,
       0,     0,     0,    48,    49,    50,     0,     0,    51,    52,
       3,     0,     4,     5,     6,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,    10,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,     0,    46,     0,     0,
      47,     4,     5,     6,     7,     8,     0,    48,    49,    50,
       0,     0,    51,    52,     0,     0,     9,    10,     0,     0,
       0,     0,     0,     0,     0,    17,     0,     0,    20,    21,
      22,    23,     0,     0,    26,    27,    28,    29,     0,    30,
      31,    32,     0,     0,     0,     4,     5,     6,     7,     8,
       0,    42,    43,     0,     0,     0,    46,     0,     0,    47,
       9,    10,     0,     0,     0,     0,    48,    49,    50,    17,
       0,    51,    52,     4,     5,     6,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     9,    10,
       0,     0,     0,     0,     0,    89,    43,    17,     0,    99,
      46,     0,     4,     5,     6,     7,     8,     0,     0,     0,
      48,    49,    50,     0,     0,    51,    52,     9,    10,     0,
       0,     0,     0,    89,    43,     0,    17,     0,    46,   209,
       4,     5,     6,     7,     8,     0,     0,     0,    48,    49,
      50,     0,     0,    51,    52,     9,    10,     0,     0,     0,
       0,     0,    89,    43,    17,     0,   224,    46,     0,     4,
       5,     6,     7,     8,     0,     0,     0,    48,    49,    50,
       0,     0,    51,    52,     9,    10,     0,     0,     0,     0,
      89,    43,     0,    17,   263,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,    49,    50,     0,     0,
      51,    52,     0,     0,     0,     0,     0,     0,     0,    89,
      43,     0,     0,     0,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,    49,    50,     0,     0,    51,
      52
};

static const yytype_int16 yycheck[] =
{
       1,     9,    10,    21,    97,   151,   189,   217,   189,    17,
     156,    68,    69,    27,    53,    69,    53,    12,    13,    18,
      19,    20,    61,    53,    61,    60,    27,    58,    46,    64,
      60,   109,    58,    47,    60,   113,    57,    53,    64,    40,
      41,    57,    14,    15,    16,    17,    47,    53,    53,    53,
     125,   105,    57,   128,     3,     4,     5,     6,     7,    58,
      53,    70,    71,    72,    57,    66,    57,   160,    57,    70,
     163,    66,    67,    57,   284,    83,    75,    58,    77,    45,
      46,    47,    48,    49,    50,   103,    10,    11,   106,   107,
     271,    58,    64,    59,   135,   136,   171,   175,    70,    71,
      72,    58,   248,   117,   105,   141,   142,    45,    46,    47,
      48,    49,    50,    63,   132,    63,   117,    57,   172,   120,
     303,    59,    57,    53,    53,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,    57,   190,   191,    65,   157,
     148,   149,   150,     8,   222,     9,    61,    61,   226,    57,
     168,   229,   230,   228,   232,    36,    63,    58,    26,    59,
      28,    29,   255,    53,   242,   240,    34,    35,    53,   187,
     245,   246,   137,   138,   139,   140,   177,    45,    46,    47,
      48,    49,    50,    53,    53,    61,    53,    53,   189,    62,
      62,   269,    45,    46,    47,    48,    49,    50,    59,   277,
      53,    58,    57,    59,    57,   223,   224,    59,    59,   227,
      57,    53,   290,    45,    46,    47,    48,    49,    50,    51,
      52,   296,    45,    46,    47,    48,    49,    50,    57,    57,
      63,    76,    53,    60,    59,    59,    62,    40,    60,   247,
      57,    59,    62,   261,    57,   263,    60,    59,    59,   298,
      60,    59,    57,    62,    60,    57,    60,    53,   133,    66,
     247,    31,     0,     1,    -1,     3,     4,     5,     6,     7,
     271,   289,    70,    66,    66,   134,    -1,   248,    -1,    -1,
      18,    19,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,   303,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    -1,     1,    61,     3,     4,     5,     6,     7,    -1,
      68,    69,    70,    -1,    -1,    73,    74,    -1,    -1,    18,
      19,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      -1,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    -1,    -1,    73,    74,     1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    -1,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    -1,    -1,    73,    74,
       1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    -1,    -1,
      61,     3,     4,     5,     6,     7,    -1,    68,    69,    70,
      -1,    -1,    73,    74,    -1,    -1,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    30,    31,
      32,    33,    -1,    -1,    36,    37,    38,    39,    -1,    41,
      42,    43,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    53,    54,    -1,    -1,    -1,    58,    -1,    -1,    61,
      18,    19,    -1,    -1,    -1,    -1,    68,    69,    70,    27,
      -1,    73,    74,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      -1,    -1,    -1,    -1,    -1,    53,    54,    27,    -1,    57,
      58,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      68,    69,    70,    -1,    -1,    73,    74,    18,    19,    -1,
      -1,    -1,    -1,    53,    54,    -1,    27,    -1,    58,    59,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    68,    69,
      70,    -1,    -1,    73,    74,    18,    19,    -1,    -1,    -1,
      -1,    -1,    53,    54,    27,    -1,    57,    58,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    68,    69,    70,
      -1,    -1,    73,    74,    18,    19,    -1,    -1,    -1,    -1,
      53,    54,    -1,    27,    57,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    -1,    -1,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    -1,    -1,    73,
      74
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    79,     0,     1,     3,     4,     5,     6,     7,    18,
      19,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    58,    61,    68,    69,
      70,    73,    74,    80,    81,    82,    84,    87,    88,    89,
      91,    93,    96,    97,    98,    99,   106,   107,   108,   109,
     110,   111,   116,   120,   121,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   134,   135,   136,    57,    53,
     130,   130,    53,   130,    53,    61,    53,    61,    57,    57,
     120,    57,    57,    58,    80,    58,    58,    58,   135,    63,
      53,   109,   109,    63,   120,    62,    80,    90,    57,   109,
     110,   111,   116,    57,    53,   102,   103,    53,   102,   108,
     109,    57,    65,     8,     9,    10,    11,    12,    13,    66,
      67,    68,    69,    14,    15,    16,    17,    64,    70,    71,
      72,   122,   130,    18,    19,    20,    58,    75,    77,   117,
      61,   109,   112,    61,   112,    57,   120,    36,    57,    94,
      95,   102,   109,   120,   120,    63,    87,    58,    87,    59,
      62,    80,    53,   109,    53,    53,    60,    64,   103,    58,
     101,   100,   120,   124,   130,   125,   126,   126,   127,   127,
     127,   127,   128,   128,   130,   130,   130,   121,    53,    59,
     121,   133,   120,    53,    61,   112,    53,   113,   114,    62,
     112,    62,    59,    58,    57,   120,    59,    57,   102,    59,
      59,    87,    59,    83,    85,   109,    57,    53,    57,    57,
     104,   120,    59,    83,    85,   102,   102,    63,    60,    59,
      76,    53,   118,    62,    60,    57,   114,    62,    87,   120,
     120,    57,    87,    57,   120,    87,    87,    87,    59,    59,
      53,    60,    57,   103,    60,    87,    59,    59,    57,    57,
     123,   133,    60,    62,   115,   112,    59,   120,   120,    57,
      40,    92,    87,    60,    83,   109,   105,    87,   119,   114,
      57,   120,    87,    86,   103,   118,    85,   109
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

/* Line 1455 of yacc.c  */
#line 64 "parser.y"
    {nroLineaAnterior = (yyvsp[(2) - (2)].myStruct.entero);}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 72 "parser.y"
    {printf("\tError sintactico en linea %d\n", (yyvsp[(1) - (2)].myStruct.entero));;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 81 "parser.y"
    {ListaFunciones=agregarListaFunciones(ListaFunciones,(yyvsp[(2) - (5)].myStruct.cadena),"void");;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 82 "parser.y"
    {ListaFunciones=agregarListaFunciones(ListaFunciones,(yyvsp[(2) - (4)].myStruct.cadena),"void");;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 83 "parser.y"
    {ListaFunciones=agregarListaFunciones(ListaFunciones,(yyvsp[(2) - (5)].myStruct.cadena),(yyvsp[(1) - (5)].myStruct.cadena));;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 84 "parser.y"
    {ListaFunciones=agregarListaFunciones(ListaFunciones,(yyvsp[(2) - (4)].myStruct.cadena),(yyvsp[(1) - (4)].myStruct.cadena));;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 91 "parser.y"
    {ListaFunciones=agregarListaFunciones(ListaFunciones,(yyvsp[(2) - (5)].myStruct.cadena),"void");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 92 "parser.y"
    {ListaFunciones=agregarListaFunciones(ListaFunciones,(yyvsp[(2) - (6)].myStruct.cadena),"void");;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 93 "parser.y"
    {ListaFunciones=agregarListaFunciones(ListaFunciones,(yyvsp[(2) - (5)].myStruct.cadena),(yyvsp[(1) - (5)].myStruct.cadena));;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 94 "parser.y"
    {ListaFunciones=agregarListaFunciones(ListaFunciones,(yyvsp[(2) - (6)].myStruct.cadena),(yyvsp[(1) - (6)].myStruct.cadena));;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 97 "parser.y"
    {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, (yyvsp[(2) - (2)].myStruct.cadena), tipo);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 98 "parser.y"
    {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, (yyvsp[(2) - (3)].myStruct.cadena), tipo);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 105 "parser.y"
    {ListaSentencias=agregarListaSentencias(ListaSentencias,"Sentencia de Expresion",(yyvsp[(1) - (1)].myStruct.entero));;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 106 "parser.y"
    {ListaSentencias=agregarListaSentencias(ListaSentencias,"Inicio sentencia Compuesta",(yyvsp[(1) - (1)].myStruct.entero));;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    {ListaSentencias=agregarListaSentencias(ListaSentencias,"Sentencia Seleccion",(yyvsp[(1) - (1)].myStruct.entero));;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    {ListaSentencias=agregarListaSentencias(ListaSentencias,"Sentencia Iteracion",(yyvsp[(1) - (1)].myStruct.entero));;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 109 "parser.y"
    {ListaSentencias=agregarListaSentencias(ListaSentencias,"Sentencia Etiquetado",(yyvsp[(1) - (1)].myStruct.entero));;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 110 "parser.y"
    {ListaSentencias=agregarListaSentencias(ListaSentencias,"Sentencia Salto",(yyvsp[(1) - (1)].myStruct.entero));;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 116 "parser.y"
    {ListaSentencias=agregarListaSentencias(ListaSentencias,"Fin sentencia Compuesta",(yyvsp[(3) - (3)].myStruct.entero));;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    {ListaSentencias=agregarListaSentencias(ListaSentencias,"Fin sentencia Compuesta",(yyvsp[(2) - (2)].myStruct.entero));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 172 "parser.y"
    {strcat((yyvsp[(1) - (2)].myStruct.cadena), " "); strcat((yyvsp[(1) - (2)].myStruct.cadena), tipo); strcpy(tipo, (yyvsp[(1) - (2)].myStruct.cadena));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 173 "parser.y"
    {strcat((yyvsp[(1) - (2)].myStruct.cadena), " "); strcat((yyvsp[(1) - (2)].myStruct.cadena), (yyvsp[(2) - (2)].myStruct.cadena)); strcpy(tipo, (yyvsp[(1) - (2)].myStruct.cadena));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, (yyvsp[(1) - (2)].myStruct.cadena), tipo);;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 182 "parser.y"
    {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, (yyvsp[(1) - (4)].myStruct.cadena), tipo);;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 183 "parser.y"
    {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, (yyvsp[(1) - (3)].myStruct.cadena), tipo);;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 184 "parser.y"
    {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, (yyvsp[(1) - (1)].myStruct.cadena), tipo);;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 200 "parser.y"
    {strcat((yyvsp[(1) - (2)].myStruct.cadena), " "); strcat((yyvsp[(1) - (2)].myStruct.cadena), tipo); strcpy(tipo, (yyvsp[(1) - (2)].myStruct.cadena));;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 201 "parser.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].myStruct.cadena));;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 202 "parser.y"
    {strcat((yyvsp[(1) - (2)].myStruct.cadena), " "); strcat((yyvsp[(1) - (2)].myStruct.cadena), tipo); strcpy(tipo, (yyvsp[(1) - (2)].myStruct.cadena));;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 203 "parser.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].myStruct.cadena));;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 206 "parser.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].myStruct.cadena));;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 207 "parser.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].myStruct.cadena));;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 208 "parser.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].myStruct.cadena));;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 209 "parser.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].myStruct.cadena));;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 210 "parser.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].myStruct.cadena));;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 211 "parser.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].myStruct.cadena));;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 214 "parser.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].myStruct.cadena));;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 215 "parser.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].myStruct.cadena));;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 218 "parser.y"
    {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, (yyvsp[(2) - (5)].myStruct.cadena), (yyvsp[(1) - (5)].myStruct.cadena));;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 220 "parser.y"
    {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, (yyvsp[(2) - (5)].myStruct.cadena), (yyvsp[(1) - (5)].myStruct.cadena));;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 232 "parser.y"
    {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, (yyvsp[(1) - (2)].myStruct.cadena), tipo);;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 233 "parser.y"
    {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, (yyvsp[(1) - (1)].myStruct.cadena), tipo);;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 236 "parser.y"
    {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, (yyvsp[(2) - (2)].myStruct.cadena), (yyvsp[(1) - (2)].myStruct.cadena));;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 239 "parser.y"
    {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, (yyvsp[(1) - (2)].myStruct.cadena), "int");;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 240 "parser.y"
    {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, (yyvsp[(1) - (1)].myStruct.cadena), "int");;}
    break;



/* Line 1455 of yacc.c  */
#line 2117 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 339 "parser.y"


/* Llamada por yyparse ante un error */
int yyerror (char *s) {
  //printf ("%s\n", s);
}


/* Main */
int main (){

  #ifdef BISON_DEBUG
    yydebug = 1;
  #endif

  yyin = fopen("entrada.c","r");
  yyparse();

  fclose(yyin);

  recorrerListaSentencias(ListaSentencias);
  recorrerListaDeclaracionesVariables(ListaDeclaraciones);
  recorrerListaFunciones(ListaFunciones);

  getch();

return 0;
}
