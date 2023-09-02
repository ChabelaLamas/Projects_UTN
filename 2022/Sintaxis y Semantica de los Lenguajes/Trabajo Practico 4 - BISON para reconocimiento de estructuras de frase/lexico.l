/* =====================    O P C I O N E S     ===================== */

%option noyywrap
/* yylineno: Utilizado para obtener el numero de linea */
%option yylineno

/* =====================    D E F I N I C I O N E S     ===================== */
%{

#include "parser.tab.h"
#include <string.h>

%}

/* =====================    A L I A S      ===================== */

CONSTANTE_DECIMAL               [1-9][0-9]*
CONSTANTE_OCTAL                 0[0-7]*
CONSTANTE_HEXADECIMAL           0[xX][0-9A-Fa-f]+
CONSTANTE_REAL                  [0-9]*\.[0-9]+([eE][\+\-]?[0-9]+)?|[0-9]+\.([eE][\+\-]?[0-9]+)?|[0-9]([eE][\+\-]?[0-9]+)?
CONSTANTE_CARACTER              '.'
LITERAL_CADENA                  \".*\"
IDENTIFICADOR                   [_a-zA-Z][_a-zA-Z0-9]*
COMENTARIO_UNA_LINEA            \/\/.*
COMENTARIO_VARIAS_LINEAS        \/\*[^\*\/]*\*\/

/* =====================    R E G L A S    ===================== */

%%
"{"                                     {yylval.myStruct.entero = yylineno; return '{';}
"}"                                     {yylval.myStruct.entero = yylineno; return '}';}
"="                                     {return '=';}
"<"                                     {return '<';}
">"                                     {return '>';}
"+"                                     {return '+';}
"-"                                     {return '-';}
"*"                                     {return '*';}
"/"                                     {return '/';}
"%"                                     {return '%';}
";"                                     {yylval.myStruct.entero = yylineno; return ';';}
":"                                     {yylval.myStruct.entero = yylineno; return ':';}
"("                                     {return '(';}
")"                                     {return ')';}
","                                     {return ',';}
"."                                     {return '.';}
"?"                                     {return '?';}
"!"                                     {return '!';}
"["                                     {return '[';}
"]"                                     {return ']';}
"&"                                     {return '&';}

"=="                                    {return IGUALIGUAL;}
"!="                                    {return DIFERENTE;}
"+="                                    {return MASIGUAL;}
"-="                                    {return MENOSIGUAL;}
"*="                                    {return PORIGUAL;}
"/="                                    {return DIVISIONGUAL;}
"<="                                    {return MENORIGUAL;}
">="                                    {return MAYORIGUAL;}
"++"                                    {return MASMAS;}
"--"                                    {return MENOSMENOS;}
"&&"                                    {return AND;}
"||"                                    {return OR;}
"->"                                    {return FLECHA;}

"\n"                                    {yylval.myStruct.entero = yylineno;}
"\t"
" "


int                                     {yylval.myStruct.cadena = strdup(yytext); return INT;}
double                                  {yylval.myStruct.cadena = strdup(yytext); return DOUBLE;}
float                                   {yylval.myStruct.cadena = strdup(yytext); return FLOAT;}
char                                    {yylval.myStruct.cadena = strdup(yytext); return CHAR;}
long                                    {yylval.myStruct.cadena = strdup(yytext); return LONG;}
short                                   {yylval.myStruct.cadena = strdup(yytext); return SHORT;}
unsigned                                {yylval.myStruct.cadena = strdup(yytext); return UNSIGNED;}
signed                                  {yylval.myStruct.cadena = strdup(yytext); return SIGNED;}
const                                   {yylval.myStruct.cadena = strdup(yytext); return CONST;}
static                                  {yylval.myStruct.cadena = strdup(yytext); return STATIC;}
struct                                  {yylval.myStruct.cadena = strdup(yytext); return STRUCT;}
void                                    {yylval.myStruct.cadena = strdup(yytext); return VOID;}
volatile                                {yylval.myStruct.cadena = strdup(yytext);return VOLATILE;}
union                                   {yylval.myStruct.cadena = strdup(yytext); return UNION;}
enum                                    {yylval.myStruct.cadena = strdup(yytext); return ENUM;}


else                                    {yylval.myStruct.entero = yylineno; return ELSE;}
switch                                  {yylval.myStruct.entero = yylineno; return SWITCH;}
break                                   {yylval.myStruct.entero = yylineno; return BREAK;}
for                                     {yylval.myStruct.entero = yylineno; return FOR;}
continue                                {yylval.myStruct.entero = yylineno; return CONTINUE;}
while                                   {yylval.myStruct.entero = yylineno; return WHILE;}
if                                      {yylval.myStruct.entero = yylineno; return IF;}
do                                      {yylval.myStruct.entero = yylineno; return DO;}
case                                    {yylval.myStruct.entero = yylineno; return CASE;}
return                                  {yylval.myStruct.entero = yylineno; return RETURN;}
default                                 {yylval.myStruct.entero = yylineno; return DEFAULT;}
goto                                    {yylval.myStruct.entero = yylineno; return GOTO;}


auto                                    {return AUTO;}
register                                {return REGISTER;}
typedef                                 {return TYPEDEF;}
extern                                  {return EXTERN;}
sizeof                                  {return SIZEOF;}


{CONSTANTE_OCTAL}                       {yylval.myStruct.entero = yylineno; return CONSTANTE_OCTAL;}
{CONSTANTE_DECIMAL}                     {yylval.myStruct.entero = yylineno; return CONSTANTE_DECIMAL;}
{CONSTANTE_HEXADECIMAL}                 {yylval.myStruct.entero = yylineno; return CONSTANTE_HEXADECIMAL;}
{CONSTANTE_REAL}                        {yylval.myStruct.entero = yylineno; return CONSTANTE_REAL;}
{CONSTANTE_CARACTER}                    {yylval.myStruct.entero = yylineno; return CONSTANTE_CARACTER;}
{IDENTIFICADOR}                         {yylval.myStruct.entero = yylineno; yylval.myStruct.cadena = strdup(yytext); return IDENTIFICADOR;}
{LITERAL_CADENA}                        {yylval.myStruct.entero = yylineno; return LITERAL_CADENA;}
{COMENTARIO_UNA_LINEA}                  {return COMENTARIO_UNA_LINEA;}
{COMENTARIO_VARIAS_LINEAS}              {return COMENTARIO_VARIAS_LINEAS;}

.                                       {printf("Error lexico (%s) en linea %i\n", yytext, yylineno);}

%%