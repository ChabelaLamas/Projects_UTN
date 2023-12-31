
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
detalleParametros * ListaParametros = NULL;
detalleParametros * ListaArgumentos = NULL;
detalleSentencia * ListaSentencias = NULL;
detalleTablaDeSimbolos * TablaDeSimbolos = NULL;

int contadorParametros = 0;
int contadorArgumentos = 0;
int nroLineaAnterior = 1;
char tipo[20];
char tipoArgumento[20];

int yylex();
int yyerror (char * s);

int yywrap(){
  return(1);
}



/* Line 189 of yacc.c  */
#line 104 "parser.tab.c"

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
#line 59 "parser.y"

  struct {
    char * cadena;
    int entero;
    int esNumerico;
  } myStruct;



/* Line 214 of yacc.c  */
#line 206 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 218 "parser.tab.c"

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
#define YYFINAL  121
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   751

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  177
/* YYNRULES -- Number of states.  */
#define YYNSTATES  307

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
       0,     0,     3,     4,     5,     9,    11,    14,    17,    19,
      21,    24,    26,    28,    34,    39,    45,    50,    52,    53,
      58,    64,    71,    77,    84,    87,    88,    94,    96,    98,
     100,   102,   104,   106,   109,   112,   114,   118,   121,   124,
     126,   129,   136,   142,   143,   146,   152,   160,   166,   172,
     177,   182,   187,   191,   195,   198,   201,   203,   208,   212,
     216,   219,   222,   226,   229,   232,   236,   240,   244,   248,
     251,   253,   256,   259,   261,   264,   265,   270,   271,   278,
     282,   284,   286,   288,   290,   292,   294,   297,   300,   302,
     304,   307,   309,   312,   314,   316,   318,   320,   322,   324,
     326,   328,   330,   336,   341,   347,   352,   356,   361,   363,
     366,   367,   372,   374,   375,   382,   383,   388,   390,   392,
     394,   398,   400,   402,   404,   406,   408,   410,   416,   418,
     422,   424,   428,   430,   434,   438,   440,   444,   448,   452,
     456,   458,   462,   466,   468,   472,   476,   480,   482,   485,
     488,   491,   494,   496,   498,   500,   502,   504,   506,   511,
     516,   520,   524,   528,   531,   534,   536,   537,   542,   544,
     546,   548,   552,   554,   556,   558,   560,   562
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      79,     0,    -1,    -1,    -1,    81,    80,    79,    -1,    89,
      -1,   100,    57,    -1,    83,    57,    -1,    86,    -1,    82,
      -1,     1,    57,    -1,    55,    -1,    56,    -1,    44,    53,
      58,    84,    59,    -1,    44,    53,    58,    59,    -1,   109,
      53,    58,    84,    59,    -1,   109,    53,    58,    59,    -1,
     109,    -1,    -1,   109,    60,    85,    84,    -1,    44,    53,
      58,    59,    91,    -1,    44,    53,    58,    87,    59,    91,
      -1,   109,    53,    58,    59,    91,    -1,   109,    53,    58,
      87,    59,    91,    -1,   109,    53,    -1,    -1,   109,    53,
      60,    88,    87,    -1,    90,    -1,    91,    -1,    93,    -1,
      95,    -1,    98,    -1,    99,    -1,     1,    59,    -1,   120,
      57,    -1,    57,    -1,    61,    92,    62,    -1,    61,    62,
      -1,     1,    62,    -1,    81,    -1,    81,    92,    -1,    39,
      58,   120,    59,    89,    94,    -1,    41,    58,   120,    59,
      89,    -1,    -1,    40,    89,    -1,    36,    58,   120,    59,
      89,    -1,    37,    81,    36,    58,   120,    59,    57,    -1,
      38,    58,    96,    59,    89,    -1,    97,    57,   120,    57,
     120,    -1,    57,   120,    57,   120,    -1,    97,    57,    57,
     120,    -1,    97,    57,   120,    57,    -1,    57,    57,   120,
      -1,    97,    57,    57,    -1,    57,    57,    -1,   109,   102,
      -1,   120,    -1,    42,   136,    63,    89,    -1,    43,    63,
      89,    -1,    53,    63,    89,    -1,    33,    57,    -1,    32,
      57,    -1,    31,   120,    57,    -1,    31,    57,    -1,    30,
      57,    -1,   106,   109,    53,    -1,   106,   101,    53,    -1,
     106,   111,    53,    -1,   106,   116,    53,    -1,   101,   102,
      -1,   107,    -1,   110,   109,    -1,   110,   108,    -1,   103,
      -1,   103,   102,    -1,    -1,    53,    60,   104,   103,    -1,
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
     129,    -1,   130,    71,   129,    -1,   130,    72,   129,    -1,
     132,    -1,    18,   130,    -1,    19,   130,    -1,   131,   130,
      -1,    27,   130,    -1,    73,    -1,    70,    -1,    68,    -1,
      69,    -1,    74,    -1,   135,    -1,   132,    75,   120,    76,
      -1,    53,    58,   133,    59,    -1,    53,    58,    59,    -1,
     132,    77,    53,    -1,   132,    20,    53,    -1,   132,    18,
      -1,   132,    19,    -1,   121,    -1,    -1,   121,    60,   134,
     133,    -1,    53,    -1,   136,    -1,    54,    -1,    58,   120,
      59,    -1,   137,    -1,     7,    -1,     6,    -1,     3,    -1,
       4,    -1,     5,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    70,    70,    71,    71,    74,    75,    76,    77,    78,
      79,    82,    83,    88,    89,    90,    91,    94,    95,    95,
      98,    99,   100,   101,   104,   105,   105,   112,   113,   114,
     115,   116,   117,   118,   121,   122,   125,   126,   127,   130,
     131,   134,   135,   138,   139,   142,   143,   144,   147,   148,
     149,   150,   151,   152,   153,   156,   157,   160,   161,   162,
     165,   166,   167,   168,   169,   175,   176,   177,   178,   179,
     180,   183,   184,   187,   188,   191,   191,   192,   192,   193,
     194,   197,   198,   199,   200,   201,   204,   205,   206,   207,
     210,   211,   212,   213,   216,   217,   218,   219,   220,   221,
     224,   225,   228,   229,   230,   231,   234,   235,   238,   239,
     242,   242,   243,   246,   246,   249,   249,   250,   256,   259,
     260,   263,   264,   265,   266,   267,   270,   271,   274,   275,
     278,   279,   282,   283,   284,   287,   288,   289,   290,   291,
     294,   295,   296,   299,   300,   301,   302,   305,   306,   307,
     308,   309,   312,   313,   314,   315,   316,   319,   320,   321,
     322,   323,   324,   325,   326,   329,   330,   330,   333,   337,
     338,   339,   342,   343,   344,   347,   348,   349
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
  "input", "$@1", "line", "noC", "prototipo", "parametrosPrototipo", "$@2",
  "funciones", "parametrosFuncion", "$@3", "sentencia", "sentExpresion",
  "sentCompuesta", "listaSentencias", "sentSeleccion", "sentElse",
  "sentIteracion", "cuerpoFor", "declaracionFor", "sentEtiquetado",
  "sentSalto", "declaracion", "espDeclaracion", "variasVariables",
  "inicializacion", "$@4", "$@5", "espAlmacenamiento", "declaraciones",
  "espSigno", "tipoDeDato", "calificadorTipo", "espStructUnion",
  "declaracionesStruct", "variasVariablesStruct", "inicializacionStruct",
  "$@6", "espEnum", "$@7", "listaIdentificadores", "$@8", "expresion",
  "expAsignacion", "operAsig", "expCondicional", "expOr", "expAnd",
  "expIgualdad", "expRelacional", "expAditiva", "expMultiplicativa",
  "expUnaria", "operUnario", "expSufijo", "listaArgumentos", "$@9",
  "expPrimaria", "constante", "constanteEntera", 0
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
       0,    78,    79,    80,    79,    81,    81,    81,    81,    81,
      81,    82,    82,    83,    83,    83,    83,    84,    85,    84,
      86,    86,    86,    86,    87,    88,    87,    89,    89,    89,
      89,    89,    89,    89,    90,    90,    91,    91,    91,    92,
      92,    93,    93,    94,    94,    95,    95,    95,    96,    96,
      96,    96,    96,    96,    96,    97,    97,    98,    98,    98,
      99,    99,    99,    99,    99,   100,   100,   100,   100,   100,
     100,   101,   101,   102,   102,   104,   103,   105,   103,   103,
     103,   106,   106,   106,   106,   106,   107,   107,   107,   107,
     108,   108,   108,   108,   109,   109,   109,   109,   109,   109,
     110,   110,   111,   111,   111,   111,   112,   112,   113,   113,
     115,   114,   114,   117,   116,   119,   118,   118,   120,   121,
     121,   122,   122,   122,   122,   122,   123,   123,   124,   124,
     125,   125,   126,   126,   126,   127,   127,   127,   127,   127,
     128,   128,   128,   129,   129,   129,   129,   130,   130,   130,
     130,   130,   131,   131,   131,   131,   131,   132,   132,   132,
     132,   132,   132,   132,   132,   133,   134,   133,   135,   135,
     135,   135,   136,   136,   136,   137,   137,   137
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     3,     1,     2,     2,     1,     1,
       2,     1,     1,     5,     4,     5,     4,     1,     0,     4,
       5,     6,     5,     6,     2,     0,     5,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     3,     2,     2,     1,
       2,     6,     5,     0,     2,     5,     7,     5,     5,     4,
       4,     4,     3,     3,     2,     2,     1,     4,     3,     3,
       2,     2,     3,     2,     2,     3,     3,     3,     3,     2,
       1,     2,     2,     1,     2,     0,     4,     0,     6,     3,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     4,     5,     4,     3,     4,     1,     2,
       0,     4,     1,     0,     6,     0,     4,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     5,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     4,     4,
       3,     3,     3,     2,     2,     1,     0,     4,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,   175,   176,   177,   174,   173,     0,     0,    83,
      81,    82,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,   101,   100,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,    98,    99,    91,    93,
     168,   170,    11,    12,    35,     0,     0,   154,   155,   153,
     152,   156,     0,     3,     9,     0,     8,     5,    27,    28,
      29,    30,    31,    32,     0,     0,     0,    70,     0,     0,
       0,    88,    89,     0,   118,   119,   126,   128,   130,   132,
     135,   140,   143,     0,   147,   157,   169,   172,    10,    33,
      38,   168,   148,   149,   113,   151,     0,     0,     0,     0,
      64,    63,     0,    61,    60,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    92,     0,     0,     0,    37,     0,
       0,     1,     0,     7,     6,    80,    69,    73,     0,     0,
       0,     0,    87,    80,    86,    72,    71,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
     123,   124,   125,   121,     0,     0,     0,     0,   150,   163,
     164,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      62,     0,     0,     0,     0,     0,     0,    56,     0,     0,
       0,     0,    58,     0,   160,   165,     0,    59,   171,    40,
      36,     4,    75,     0,    74,    66,    65,    67,    68,     0,
       0,   129,   143,   131,   133,   134,   138,   139,   136,   137,
     141,   142,   144,   145,   146,   120,   162,     0,   161,     0,
       0,   112,     0,   108,   105,     0,   103,     0,     0,    54,
       0,     0,     0,    55,     0,     0,    57,     0,     0,     0,
      17,   166,   159,     0,    79,     0,     0,     0,     0,   158,
     117,     0,   104,   110,   106,   109,   102,    45,     0,    52,
       0,    47,    53,     0,    43,    42,     0,    20,    13,     0,
      24,    18,     0,    76,    77,    22,    15,     0,   127,   115,
     114,     0,   107,     0,    49,    50,    51,     0,    41,    21,
      25,     0,   167,     0,    23,     0,   111,    46,    48,    44,
       0,    19,    17,    78,   116,    26,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    52,   122,    53,    54,    55,   238,   291,    56,   239,
     300,    57,    58,    59,   120,    60,   288,    61,   174,   175,
      62,    63,    64,    65,   126,   127,   243,   293,    66,    67,
      68,    69,    70,    71,   167,   222,   223,   281,    72,   164,
     251,   295,    73,    74,   157,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,   186,   272,    85,    86,    87
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -229
static const yytype_int16 yypact[] =
{
     252,   -15,  -229,  -229,  -229,  -229,  -229,   677,   677,  -229,
    -229,  -229,  -229,  -229,   -43,   677,   -36,    -4,   -14,   130,
     -11,     2,  -229,  -229,     8,   459,    22,    38,    67,   135,
      39,    29,  -229,  -229,  -229,  -229,  -229,  -229,   177,   177,
     -35,  -229,  -229,  -229,  -229,   677,   311,  -229,  -229,  -229,
    -229,  -229,   132,  -229,  -229,    90,  -229,  -229,  -229,  -229,
    -229,  -229,  -229,  -229,    93,    98,   186,  -229,    98,    99,
     144,  -229,  -229,    96,  -229,  -229,    91,   147,   149,    88,
      28,    52,    21,   677,     1,  -229,  -229,  -229,  -229,  -229,
    -229,   101,  -229,  -229,  -229,  -229,   100,   177,   114,   177,
    -229,  -229,   119,  -229,  -229,   677,   141,   562,   677,   677,
     118,   518,   127,  -229,  -229,   595,   518,   138,  -229,   385,
     124,  -229,   252,  -229,  -229,     7,  -229,    98,   148,   158,
     163,   165,  -229,    19,  -229,  -229,  -229,  -229,   677,   677,
     677,   677,   677,   677,   677,   677,   677,   677,   677,  -229,
    -229,  -229,  -229,  -229,   677,   677,   677,   677,  -229,  -229,
    -229,   166,   677,   175,   168,   177,   184,   140,   177,   176,
    -229,   171,   181,   620,   183,   187,    98,  -229,   188,   189,
     518,    -1,  -229,     5,  -229,   180,   190,  -229,  -229,  -229,
    -229,  -229,  -229,   677,  -229,  -229,  -229,  -229,  -229,    68,
     182,  -229,    34,  -229,  -229,  -229,  -229,  -229,  -229,  -229,
    -229,  -229,  -229,  -229,  -229,  -229,  -229,   170,  -229,   197,
     198,   191,    44,  -229,  -229,   199,  -229,   518,   677,   677,
     205,   518,   652,  -229,   518,   518,  -229,    11,   206,   207,
     -26,  -229,  -229,    98,   204,    12,   209,   210,   677,  -229,
     232,   249,  -229,  -229,   177,  -229,  -229,  -229,   260,  -229,
     677,  -229,   677,   266,   284,  -229,   265,  -229,  -229,    13,
     268,  -229,   677,  -229,  -229,  -229,  -229,    13,  -229,  -229,
    -229,   184,  -229,   274,  -229,  -229,   677,   518,  -229,  -229,
    -229,   177,  -229,    98,  -229,   197,  -229,  -229,  -229,  -229,
     177,  -229,   291,  -229,  -229,  -229,   317
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -229,   253,  -229,   -16,  -229,  -229,  -191,  -229,  -229,  -192,
    -229,  -105,  -229,  -221,   255,  -229,  -229,  -229,  -229,  -229,
    -229,  -229,  -229,   305,   -64,  -228,  -229,  -229,  -229,  -229,
     306,   -37,  -229,   312,   -81,  -229,  -200,  -229,   316,  -229,
      82,  -229,   -19,  -112,  -229,   139,   244,   254,   -18,    62,
      -3,   -45,    24,  -229,  -229,   121,  -229,  -229,   366,  -229
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -40
static const yytype_int16 yytable[] =
{
     102,   113,   114,   185,   132,   134,   182,   247,   246,   106,
      94,   187,   266,   266,   266,   273,   267,    96,   169,   159,
     160,   161,   255,   115,   275,    97,   117,   270,   116,   129,
     119,    92,    93,   136,   271,   149,   150,   151,   152,    95,
     143,   144,    88,   100,    89,   215,   103,    90,   289,    98,
      32,    33,    34,    35,    36,    37,   294,    99,    89,   104,
     166,    90,   166,   194,   237,   303,   105,   192,   -14,   -16,
     176,   193,    46,    46,    46,   236,   162,   199,   163,   192,
     107,   296,   112,   193,   220,   153,   171,   225,   177,   178,
     179,   154,   155,   156,   145,   146,   108,   221,   141,   142,
     301,   254,   111,   119,   154,   155,   156,   158,   305,   212,
     213,   214,   233,    32,    33,    34,    35,    36,    37,   200,
     147,   148,   257,   204,   205,   109,   261,   245,   166,   264,
     265,   166,   121,     2,     3,     4,     5,     6,     2,     3,
       4,     5,     6,   217,   210,   211,   240,   123,     7,     8,
     124,   125,   133,   137,   230,   139,   138,    15,   140,   115,
     185,   165,   240,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   282,   244,   168,   170,   172,   202,   202,
     202,   180,   299,    91,    41,   183,   190,   101,    45,    32,
      33,    34,    35,    36,    37,    38,    39,   188,    47,    48,
      49,   195,   224,    50,    51,   206,   207,   208,   209,   258,
     259,   196,    14,   263,    16,    17,   197,   166,   198,   216,
      22,    23,    32,    33,    34,    35,    36,    37,   218,   219,
     227,    32,    33,    34,    35,    36,    37,   221,   226,   228,
     241,   284,   231,   285,   232,   248,   249,   234,   235,   242,
     250,   253,    -2,     1,   302,     2,     3,     4,     5,     6,
     252,   256,   260,   306,   274,   268,   269,   298,   276,   277,
       7,     8,   202,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,   279,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,   280,     1,    46,     2,     3,     4,     5,     6,   283,
      47,    48,    49,   286,   287,    50,    51,    90,   290,     7,
       8,   297,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,   271,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
     270,   128,    46,   118,   189,   191,   135,   304,   130,    47,
      48,    49,   131,   201,    50,    51,     1,   278,     2,     3,
       4,     5,     6,   292,   203,   110,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,     0,     0,    46,   -39,     0,     0,
       0,     0,     0,    47,    48,    49,     0,     0,    50,    51,
       1,     0,     2,     3,     4,     5,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,     0,   181,
      46,     2,     3,     4,     5,     6,     0,    47,    48,    49,
       0,     0,    50,    51,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,    18,    19,
      20,    21,     0,     0,    24,    25,    26,    27,     0,    28,
      29,    30,     0,     0,     0,     2,     3,     4,     5,     6,
       0,    40,    41,     0,     0,    44,    45,     0,     0,    46,
       7,     8,     0,     0,     0,     0,    47,    48,    49,    15,
       0,    50,    51,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     0,     0,     0,     0,    32,    33,    34,
      35,    36,    37,     7,     8,    91,    41,     0,     0,   173,
      45,     0,    15,     2,     3,     4,     5,     6,     0,     0,
      47,    48,    49,     0,     0,    50,    51,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,    15,    91,    41,
       0,     0,     0,    45,   184,     2,     3,     4,     5,     6,
       0,     0,     0,    47,    48,    49,     0,     0,    50,    51,
       7,     8,     0,    91,    41,     0,     0,   229,    45,    15,
       2,     3,     4,     5,     6,     0,     0,     0,    47,    48,
      49,     0,     0,    50,    51,     7,     8,     0,     0,     0,
       0,     0,     0,     0,    15,    91,    41,     0,     0,   262,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,    48,    49,     0,     0,    50,    51,     0,     0,     0,
      91,    41,     0,     0,     0,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,    48,    49,     0,     0,
      50,    51
};

static const yytype_int16 yycheck[] =
{
      19,    38,    39,   115,    68,    69,   111,   199,   199,    25,
      53,   116,     1,     1,     1,   243,   237,    53,    99,    18,
      19,    20,   222,    58,   245,    61,    45,    53,    63,    66,
      46,     7,     8,    70,    60,    14,    15,    16,    17,    15,
      12,    13,    57,    57,    59,   157,    57,    62,   269,    53,
      45,    46,    47,    48,    49,    50,   277,    61,    59,    57,
      97,    62,    99,   127,    59,   293,    58,    60,    57,    57,
     107,    64,    61,    61,    61,   180,    75,    58,    77,    60,
      58,   281,    53,    64,   165,    64,   105,   168,   107,   108,
     109,    70,    71,    72,    66,    67,    58,    53,    10,    11,
     291,    57,    63,   119,    70,    71,    72,    83,   300,   154,
     155,   156,   176,    45,    46,    47,    48,    49,    50,   138,
      68,    69,   227,   141,   142,    58,   231,    59,   165,   234,
     235,   168,     0,     3,     4,     5,     6,     7,     3,     4,
       5,     6,     7,   162,   147,   148,   183,    57,    18,    19,
      57,    53,    53,    57,   173,     8,    65,    27,     9,    58,
     272,    61,   199,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   254,   193,    61,    57,    36,   154,   155,
     156,    63,   287,    53,    54,    58,    62,    57,    58,    45,
      46,    47,    48,    49,    50,    51,    52,    59,    68,    69,
      70,    53,    62,    73,    74,   143,   144,   145,   146,   228,
     229,    53,    26,   232,    28,    29,    53,   254,    53,    53,
      34,    35,    45,    46,    47,    48,    49,    50,    53,    61,
      59,    45,    46,    47,    48,    49,    50,    53,    62,    58,
      60,   260,    59,   262,    57,    63,    76,    59,    59,    59,
      53,    60,     0,     1,   291,     3,     4,     5,     6,     7,
      62,    62,    57,   300,    60,    59,    59,   286,    59,    59,
      18,    19,   248,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    60,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    62,     1,    61,     3,     4,     5,     6,     7,    59,
      68,    69,    70,    57,    40,    73,    74,    62,    60,    18,
      19,    57,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    60,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      53,    66,    61,    62,   119,   122,    70,   295,    66,    68,
      69,    70,    66,   139,    73,    74,     1,   248,     3,     4,
       5,     6,     7,   272,   140,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    -1,    -1,    73,    74,
       1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,     1,
      61,     3,     4,     5,     6,     7,    -1,    68,    69,    70,
      -1,    -1,    73,    74,    -1,    -1,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    30,    31,
      32,    33,    -1,    -1,    36,    37,    38,    39,    -1,    41,
      42,    43,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    53,    54,    -1,    -1,    57,    58,    -1,    -1,    61,
      18,    19,    -1,    -1,    -1,    -1,    68,    69,    70,    27,
      -1,    73,    74,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    18,    19,    53,    54,    -1,    -1,    57,
      58,    -1,    27,     3,     4,     5,     6,     7,    -1,    -1,
      68,    69,    70,    -1,    -1,    73,    74,    -1,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    53,    54,
      -1,    -1,    -1,    58,    59,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    68,    69,    70,    -1,    -1,    73,    74,
      18,    19,    -1,    53,    54,    -1,    -1,    57,    58,    27,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    68,    69,
      70,    -1,    -1,    73,    74,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    53,    54,    -1,    -1,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    -1,    -1,    73,    74,    -1,    -1,    -1,
      53,    54,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    -1,    -1,
      73,    74
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,    18,    19,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    61,    68,    69,    70,
      73,    74,    79,    81,    82,    83,    86,    89,    90,    91,
      93,    95,    98,    99,   100,   101,   106,   107,   108,   109,
     110,   111,   116,   120,   121,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   135,   136,   137,    57,    59,
      62,    53,   130,   130,    53,   130,    53,    61,    53,    61,
      57,    57,   120,    57,    57,    58,    81,    58,    58,    58,
     136,    63,    53,   109,   109,    58,    63,   120,    62,    81,
      92,     0,    80,    57,    57,    53,   102,   103,   101,   109,
     111,   116,   102,    53,   102,   108,   109,    57,    65,     8,
       9,    10,    11,    12,    13,    66,    67,    68,    69,    14,
      15,    16,    17,    64,    70,    71,    72,   122,   130,    18,
      19,    20,    75,    77,   117,    61,   109,   112,    61,   112,
      57,   120,    36,    57,    96,    97,   109,   120,   120,   120,
      63,     1,    89,    58,    59,   121,   133,    89,    59,    92,
      62,    79,    60,    64,   102,    53,    53,    53,    53,    58,
     120,   124,   130,   125,   126,   126,   127,   127,   127,   127,
     128,   128,   129,   129,   129,   121,    53,   120,    53,    61,
     112,    53,   113,   114,    62,   112,    62,    59,    58,    57,
     120,    59,    57,   102,    59,    59,    89,    59,    84,    87,
     109,    60,    59,   104,   120,    59,    84,    87,    63,    76,
      53,   118,    62,    60,    57,   114,    62,    89,   120,   120,
      57,    89,    57,   120,    89,    89,     1,    91,    59,    59,
      53,    60,   134,   103,    60,    91,    59,    59,   123,    60,
      62,   115,   112,    59,   120,   120,    57,    40,    94,    91,
      60,    85,   133,   105,    91,   119,   114,    57,   120,    89,
      88,    84,   109,   103,   118,    87,   109
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
#line 71 "parser.y"
    {nroLineaAnterior = (yyvsp[(1) - (1)].myStruct.entero);;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 76 "parser.y"
    {ListaParametros = NULL; contadorParametros=0;;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 77 "parser.y"
    {ListaParametros = NULL; contadorParametros=0; ListaSentencias = agregarListaSentencias(ListaSentencias, "Inicio sentencia Compuesta", (yyvsp[(1) - (1)].myStruct.entero));;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 79 "parser.y"
    {printf(" Error sintactico en linea %d\n", (yyvsp[(1) - (2)].myStruct.entero));;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 88 "parser.y"
    {TablaDeSimbolos = agregarAListaDeSimbolos(TablaDeSimbolos, (yyvsp[(2) - (5)].myStruct.cadena), "void", 'F', ListaParametros, contadorParametros, nroLineaAnterior);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 89 "parser.y"
    {TablaDeSimbolos = agregarAListaDeSimbolos(TablaDeSimbolos, (yyvsp[(2) - (4)].myStruct.cadena), "void", 'F', ListaParametros, contadorParametros, nroLineaAnterior);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 90 "parser.y"
    {TablaDeSimbolos = agregarAListaDeSimbolos(TablaDeSimbolos, (yyvsp[(2) - (5)].myStruct.cadena), (yyvsp[(1) - (5)].myStruct.cadena), 'F', ListaParametros, contadorParametros, nroLineaAnterior);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 91 "parser.y"
    {TablaDeSimbolos = agregarAListaDeSimbolos(TablaDeSimbolos, (yyvsp[(2) - (4)].myStruct.cadena), (yyvsp[(1) - (4)].myStruct.cadena), 'F', ListaParametros, contadorParametros, nroLineaAnterior);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 94 "parser.y"
    {ListaParametros = agregarListaParametros (ListaParametros, NULL, tipo); contadorParametros++;;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 95 "parser.y"
    {ListaParametros = agregarListaParametros (ListaParametros, NULL, tipo); contadorParametros++;;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 98 "parser.y"
    {TablaDeSimbolos = agregarAListaDeSimbolos(TablaDeSimbolos, (yyvsp[(2) - (5)].myStruct.cadena), "void", 'F', ListaParametros, contadorParametros, (yyvsp[(2) - (5)].myStruct.entero));;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 99 "parser.y"
    {TablaDeSimbolos = agregarAListaDeSimbolos(TablaDeSimbolos, (yyvsp[(2) - (6)].myStruct.cadena), "void", 'F', ListaParametros, contadorParametros, (yyvsp[(2) - (6)].myStruct.entero));;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 100 "parser.y"
    {TablaDeSimbolos = agregarAListaDeSimbolos(TablaDeSimbolos, (yyvsp[(2) - (5)].myStruct.cadena), (yyvsp[(1) - (5)].myStruct.cadena), 'F', ListaParametros, contadorParametros, (yyvsp[(2) - (5)].myStruct.entero));;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 101 "parser.y"
    {TablaDeSimbolos = agregarAListaDeSimbolos(TablaDeSimbolos, (yyvsp[(2) - (6)].myStruct.cadena), (yyvsp[(1) - (6)].myStruct.cadena), 'F', ListaParametros, contadorParametros, (yyvsp[(2) - (6)].myStruct.entero));;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 104 "parser.y"
    {TablaDeSimbolos = agregarAListaDeSimbolos(TablaDeSimbolos, (yyvsp[(2) - (2)].myStruct.cadena), tipo, 'V', NULL, 0, (yyvsp[(2) - (2)].myStruct.entero)); ListaParametros=agregarListaParametros (ListaParametros, (yyvsp[(2) - (2)].myStruct.cadena), tipo);contadorParametros++;;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 105 "parser.y"
    {TablaDeSimbolos = agregarAListaDeSimbolos(TablaDeSimbolos, (yyvsp[(2) - (3)].myStruct.cadena), tipo, 'V', NULL, 0, (yyvsp[(2) - (3)].myStruct.entero)); ListaParametros=agregarListaParametros (ListaParametros, (yyvsp[(2) - (3)].myStruct.cadena), tipo);contadorParametros++;;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 112 "parser.y"
    {ListaSentencias = agregarListaSentencias(ListaSentencias, "Sentencia de Expresion", (yyvsp[(1) - (1)].myStruct.entero));;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 113 "parser.y"
    {ListaSentencias = agregarListaSentencias(ListaSentencias, "Inicio sentencia Compuesta", (yyvsp[(1) - (1)].myStruct.entero));;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 114 "parser.y"
    {ListaSentencias = agregarListaSentencias(ListaSentencias, "Sentencia Seleccion", (yyvsp[(1) - (1)].myStruct.entero));;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 115 "parser.y"
    {ListaSentencias = agregarListaSentencias(ListaSentencias, "Sentencia Iteracion", (yyvsp[(1) - (1)].myStruct.entero));;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 116 "parser.y"
    {ListaSentencias = agregarListaSentencias(ListaSentencias, "Sentencia Etiquetado", (yyvsp[(1) - (1)].myStruct.entero));;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    {ListaSentencias = agregarListaSentencias(ListaSentencias, "Sentencia Salto", (yyvsp[(1) - (1)].myStruct.entero));;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 118 "parser.y"
    {printf(" Error sintactico en linea %d\n", (yyvsp[(1) - (2)].myStruct.entero));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 122 "parser.y"
    {ListaSentencias = agregarListaSentencias(ListaSentencias, "Sentencia Vacia", (yyvsp[(1) - (1)].myStruct.entero));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 125 "parser.y"
    {ListaSentencias = agregarListaSentencias(ListaSentencias, "Fin sentencia Compuesta", (yyvsp[(3) - (3)].myStruct.entero));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 126 "parser.y"
    {ListaSentencias = agregarListaSentencias(ListaSentencias, "Fin sentencia Compuesta", (yyvsp[(2) - (2)].myStruct.entero));;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 127 "parser.y"
    {printf(" Error sintactico en linea %d\n", (yyvsp[(1) - (2)].myStruct.entero));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 175 "parser.y"
    {TablaDeSimbolos = agregarAListaDeSimbolos(TablaDeSimbolos, (yyvsp[(3) - (3)].myStruct.cadena), tipo, 'V', NULL, 0, (yyvsp[(3) - (3)].myStruct.entero));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 176 "parser.y"
    {TablaDeSimbolos = agregarAListaDeSimbolos(TablaDeSimbolos, (yyvsp[(3) - (3)].myStruct.cadena), tipo, 'V', NULL, 0, (yyvsp[(3) - (3)].myStruct.entero));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 177 "parser.y"
    {TablaDeSimbolos = agregarAListaDeSimbolos(TablaDeSimbolos, (yyvsp[(3) - (3)].myStruct.cadena), tipo, 'V', NULL, 0, (yyvsp[(3) - (3)].myStruct.entero));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 178 "parser.y"
    {TablaDeSimbolos = agregarAListaDeSimbolos(TablaDeSimbolos, (yyvsp[(3) - (3)].myStruct.cadena), tipo, 'V', NULL, 0, (yyvsp[(3) - (3)].myStruct.entero));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 183 "parser.y"
    {strcat((yyvsp[(1) - (2)].myStruct.cadena), " "); strcat((yyvsp[(1) - (2)].myStruct.cadena), tipo); strcpy(tipo, (yyvsp[(1) - (2)].myStruct.cadena));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 184 "parser.y"
    {strcat((yyvsp[(1) - (2)].myStruct.cadena), " "); strcat((yyvsp[(1) - (2)].myStruct.cadena), (yyvsp[(2) - (2)].myStruct.cadena)); strcpy(tipo, (yyvsp[(1) - (2)].myStruct.cadena));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 191 "parser.y"
    {TablaDeSimbolos = agregarAListaDeSimbolos(TablaDeSimbolos, (yyvsp[(1) - (2)].myStruct.cadena), tipo, 'V', NULL, 0, (yyvsp[(1) - (2)].myStruct.entero));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 192 "parser.y"
    {TablaDeSimbolos = agregarAListaDeSimbolos(TablaDeSimbolos, (yyvsp[(1) - (4)].myStruct.cadena), tipo, 'V', NULL, 0, (yyvsp[(1) - (4)].myStruct.entero)); if(!(yyvsp[(3) - (4)].myStruct.esNumerico)) printf(" Error semantico en linea %d: Tipos de datos incorrectos para realizar una asignacion de variable\n", (yyvsp[(2) - (4)].myStruct.entero));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 193 "parser.y"
    {TablaDeSimbolos = agregarAListaDeSimbolos(TablaDeSimbolos, (yyvsp[(1) - (3)].myStruct.cadena), tipo, 'V', NULL, 0, (yyvsp[(1) - (3)].myStruct.entero)); if(!(yyvsp[(3) - (3)].myStruct.esNumerico)) printf(" Error semantico en linea %d: Tipos de datos incorrectos para realizar una asignacion de variable\n", (yyvsp[(2) - (3)].myStruct.entero));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 194 "parser.y"
    {TablaDeSimbolos = agregarAListaDeSimbolos(TablaDeSimbolos, (yyvsp[(1) - (1)].myStruct.cadena), tipo, 'V', NULL, 0, (yyvsp[(1) - (1)].myStruct.entero));;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 210 "parser.y"
    {strcat((yyvsp[(1) - (2)].myStruct.cadena), " "); strcat((yyvsp[(1) - (2)].myStruct.cadena), tipo); strcpy(tipo, (yyvsp[(1) - (2)].myStruct.cadena));;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 211 "parser.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].myStruct.cadena));;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 212 "parser.y"
    {strcat((yyvsp[(1) - (2)].myStruct.cadena), " "); strcat((yyvsp[(1) - (2)].myStruct.cadena), tipo); strcpy(tipo, (yyvsp[(1) - (2)].myStruct.cadena));;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 213 "parser.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].myStruct.cadena));;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 216 "parser.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].myStruct.cadena));;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 217 "parser.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].myStruct.cadena));;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 218 "parser.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].myStruct.cadena));;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].myStruct.cadena));;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 220 "parser.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].myStruct.cadena));;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 221 "parser.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].myStruct.cadena));;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 224 "parser.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].myStruct.cadena));;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 225 "parser.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].myStruct.cadena));;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 228 "parser.y"
    {TablaDeSimbolos = agregarAListaDeSimbolos(TablaDeSimbolos, (yyvsp[(2) - (5)].myStruct.cadena), (yyvsp[(1) - (5)].myStruct.cadena), 'V', NULL, 0, (yyvsp[(2) - (5)].myStruct.entero)); strcpy(tipo, (yyvsp[(1) - (5)].myStruct.cadena));;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 229 "parser.y"
    {strcpy(tipo, (yyvsp[(1) - (4)].myStruct.cadena));;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 230 "parser.y"
    {TablaDeSimbolos = agregarAListaDeSimbolos(TablaDeSimbolos, (yyvsp[(2) - (5)].myStruct.cadena), (yyvsp[(1) - (5)].myStruct.cadena), 'V', NULL, 0, (yyvsp[(2) - (5)].myStruct.entero)); strcpy(tipo, (yyvsp[(1) - (5)].myStruct.cadena));;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 231 "parser.y"
    {strcpy(tipo, (yyvsp[(1) - (4)].myStruct.cadena));;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 242 "parser.y"
    {TablaDeSimbolos = agregarAListaDeSimbolos(TablaDeSimbolos, (yyvsp[(1) - (2)].myStruct.cadena), tipo, 'V', NULL, 0, (yyvsp[(1) - (2)].myStruct.entero));;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 243 "parser.y"
    {TablaDeSimbolos = agregarAListaDeSimbolos(TablaDeSimbolos, (yyvsp[(1) - (1)].myStruct.cadena), tipo, 'V', NULL, 0, (yyvsp[(1) - (1)].myStruct.entero));;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 246 "parser.y"
    {TablaDeSimbolos = agregarAListaDeSimbolos(TablaDeSimbolos, (yyvsp[(2) - (2)].myStruct.cadena), (yyvsp[(1) - (2)].myStruct.cadena), 'V', NULL, 0,(yyvsp[(2) - (2)].myStruct.entero)); strcpy(tipo, (yyvsp[(1) - (2)].myStruct.cadena));;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 249 "parser.y"
    {TablaDeSimbolos = agregarAListaDeSimbolos(TablaDeSimbolos, (yyvsp[(1) - (2)].myStruct.cadena), "int", 'V', NULL, 0,(yyvsp[(1) - (2)].myStruct.entero));;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 250 "parser.y"
    {TablaDeSimbolos = agregarAListaDeSimbolos(TablaDeSimbolos, (yyvsp[(1) - (1)].myStruct.cadena), "int", 'V', NULL, 0,(yyvsp[(1) - (1)].myStruct.entero));;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 260 "parser.y"
    {if (!(yyvsp[(3) - (3)].myStruct.esNumerico)) printf(" Error semantico en linea %d: Tipos de datos incorrectos para realizar una asignacion\n", (yyvsp[(2) - (3)].myStruct.entero)); else (yyvsp[(2) - (3)].myStruct.esNumerico) = 1;;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 283 "parser.y"
    {if ((yyvsp[(1) - (3)].myStruct.esNumerico) != (yyvsp[(3) - (3)].myStruct.esNumerico)) printf(" Error semantico en linea %d: Tipos de datos incorrectos para realizar una comparacion\n", (yyvsp[(2) - (3)].myStruct.entero)); else (yyvsp[(2) - (3)].myStruct.esNumerico) = 1;;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 284 "parser.y"
    {if ((yyvsp[(1) - (3)].myStruct.esNumerico) != (yyvsp[(3) - (3)].myStruct.esNumerico)) printf(" Error semantico en linea %d: Tipos de datos incorrectos para realizar una comparacion\n", (yyvsp[(2) - (3)].myStruct.entero)); else (yyvsp[(2) - (3)].myStruct.esNumerico) = 1;;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 288 "parser.y"
    {if ((yyvsp[(1) - (3)].myStruct.esNumerico) != (yyvsp[(3) - (3)].myStruct.esNumerico)) printf(" Error semantico en linea %d: Tipos de datos incorrectos para realizar una comparacion\n", (yyvsp[(2) - (3)].myStruct.entero)); else (yyvsp[(2) - (3)].myStruct.esNumerico) = 1;;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 289 "parser.y"
    {if ((yyvsp[(1) - (3)].myStruct.esNumerico) != (yyvsp[(3) - (3)].myStruct.esNumerico)) printf(" Error semantico en linea %d: Tipos de datos incorrectos para realizar una comparacion\n", (yyvsp[(2) - (3)].myStruct.entero)); else (yyvsp[(2) - (3)].myStruct.esNumerico) = 1;;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 290 "parser.y"
    {if ((yyvsp[(1) - (3)].myStruct.esNumerico) != (yyvsp[(3) - (3)].myStruct.esNumerico)) printf(" Error semantico en linea %d: Tipos de datos incorrectos para realizar una comparacion\n", (yyvsp[(2) - (3)].myStruct.entero)); else (yyvsp[(2) - (3)].myStruct.esNumerico) = 1;;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 291 "parser.y"
    {if ((yyvsp[(1) - (3)].myStruct.esNumerico) != (yyvsp[(3) - (3)].myStruct.esNumerico)) printf(" Error semantico en linea %d: Tipos de datos incorrectos para realizar una comparacion\n", (yyvsp[(2) - (3)].myStruct.entero)); else (yyvsp[(2) - (3)].myStruct.esNumerico) = 1;;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 295 "parser.y"
    {if (!(yyvsp[(1) - (3)].myStruct.esNumerico) || !(yyvsp[(3) - (3)].myStruct.esNumerico)) printf(" Error semantico en linea %d: Tipos de datos incorrectos para realizar una suma\n", (yyvsp[(2) - (3)].myStruct.entero)); else (yyvsp[(2) - (3)].myStruct.esNumerico) = 1;;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 296 "parser.y"
    {if (!(yyvsp[(1) - (3)].myStruct.esNumerico) || !(yyvsp[(3) - (3)].myStruct.esNumerico)) printf(" Error semantico en linea %d: Tipos de datos incorrectos para realizar una resta\n", (yyvsp[(2) - (3)].myStruct.entero)); else (yyvsp[(2) - (3)].myStruct.esNumerico) = 1;;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 300 "parser.y"
    {if (!(yyvsp[(1) - (3)].myStruct.esNumerico) || !(yyvsp[(3) - (3)].myStruct.esNumerico)) printf(" Error semantico en linea %d: Tipos de datos incorrectos para realizar una multiplicacion\n", (yyvsp[(2) - (3)].myStruct.entero)); else (yyvsp[(2) - (3)].myStruct.esNumerico) = 1;;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 301 "parser.y"
    {if (!(yyvsp[(1) - (3)].myStruct.esNumerico) || !(yyvsp[(3) - (3)].myStruct.esNumerico)) printf(" Error semantico en linea %d: Tipos de datos incorrectos para realizar una division \n", (yyvsp[(2) - (3)].myStruct.entero)); else (yyvsp[(2) - (3)].myStruct.esNumerico) = 1;;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 302 "parser.y"
    {if (!(yyvsp[(1) - (3)].myStruct.esNumerico) || !(yyvsp[(3) - (3)].myStruct.esNumerico)) printf(" Error semantico en linea %d: Tipos de datos incorrectos para realizar un resto\n", (yyvsp[(2) - (3)].myStruct.entero)); else (yyvsp[(2) - (3)].myStruct.esNumerico) = 1;;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 306 "parser.y"
    {if (!(yyvsp[(2) - (2)].myStruct.esNumerico)) printf(" Error semantico en linea %d: Tipos de datos incorrectos para realizar un preincremento\n", (yyvsp[(1) - (2)].myStruct.entero)); else (yyvsp[(1) - (2)].myStruct.esNumerico) = 1;;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 307 "parser.y"
    {if (!(yyvsp[(2) - (2)].myStruct.esNumerico)) printf(" Error semantico en linea %d: Tipos de datos incorrectos para realizar un predecremento\n", (yyvsp[(1) - (2)].myStruct.entero)); else (yyvsp[(1) - (2)].myStruct.esNumerico) = 1;;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 309 "parser.y"
    {(yyval.myStruct.esNumerico) = 1;;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 321 "parser.y"
    {verificarExistencia((yyvsp[(1) - (4)].myStruct.cadena), ListaArgumentos, TablaDeSimbolos, contadorArgumentos, (yyvsp[(1) - (4)].myStruct.entero)); contadorArgumentos = 0; ListaArgumentos = NULL;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 322 "parser.y"
    {verificarExistencia((yyvsp[(1) - (3)].myStruct.cadena), ListaArgumentos, TablaDeSimbolos, contadorArgumentos, (yyvsp[(1) - (3)].myStruct.entero));;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 325 "parser.y"
    {if (!(yyvsp[(1) - (2)].myStruct.esNumerico)) printf(" Error semantico en linea %d: Tipos de datos incorrectos para realizar un posincremento\n", (yyvsp[(2) - (2)].myStruct.entero)); else (yyvsp[(2) - (2)].myStruct.esNumerico) = 1;;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 326 "parser.y"
    {if (!(yyvsp[(1) - (2)].myStruct.esNumerico)) printf(" Error semantico en linea %d: Tipos de datos incorrectos para realizar una posdecremento\n", (yyvsp[(2) - (2)].myStruct.entero)); else (yyvsp[(2) - (2)].myStruct.esNumerico) = 1;;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 329 "parser.y"
    {ListaArgumentos = agregarListaParametros (ListaArgumentos, NULL, tipoArgumento); contadorArgumentos++;;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 330 "parser.y"
    {ListaArgumentos = agregarListaParametros (ListaArgumentos, NULL, tipoArgumento); contadorArgumentos++;;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 333 "parser.y"
    {
                                          (yyval.myStruct.esNumerico) = existeVariable(TablaDeSimbolos, (yyvsp[(1) - (1)].myStruct.cadena)); // Para decir si está en la tabla.
                                          if(!(yyval.myStruct.esNumerico)) printf(" Error semantico en linea %d: No esta declarada la variable %s \n", (yyvsp[(1) - (1)].myStruct.entero), (yyvsp[(1) - (1)].myStruct.cadena));
                                        ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 338 "parser.y"
    {strcpy(tipoArgumento, "char *");;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 342 "parser.y"
    {strcpy(tipoArgumento, "int");;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 343 "parser.y"
    {strcpy(tipoArgumento, "char");;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 344 "parser.y"
    {strcpy(tipoArgumento, "float");;}
    break;



/* Line 1455 of yacc.c  */
#line 2396 "parser.tab.c"
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
#line 352 "parser.y"


/* Llamada por yyparse ante un error */
int yyerror (char *s) {
  //printf ("%s\n", s);
}


/* Main */
int main (){

  #ifdef BISON_DEBUG
    yydebug = 1;
  #endif

  imprimirErrores();

  yyin = fopen("entrada.c","r");
  yyparse();

  fclose(yyin);

  generarReporte(ListaSentencias, TablaDeSimbolos);
  getch();

return 0;
}
