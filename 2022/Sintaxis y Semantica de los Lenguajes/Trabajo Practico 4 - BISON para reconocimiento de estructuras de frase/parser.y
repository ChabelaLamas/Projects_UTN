%{

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

%}


%token CONSTANTE_OCTAL CONSTANTE_DECIMAL CONSTANTE_HEXADECIMAL
%token CONSTANTE_REAL 
%token CONSTANTE_CARACTER
%token OR AND
%token IGUALIGUAL DIFERENTE
%token MAYORIGUAL
%token MENORIGUAL
%token MASIGUAL MENOSIGUAL PORIGUAL DIVISIONGUAL
%token MASMAS MENOSMENOS
%token FLECHA
%token AUTO TYPEDEF STATIC REGISTER EXTERN ENUM
%token SIZEOF
%token UNION STRUCT
%token GOTO RETURN CONTINUE BREAK
%token VOLATILE CONST
%token WHILE DO FOR
%token IF ELSE SWITCH CASE DEFAULT
%token VOID
%token CHAR DOUBLE FLOAT INT LONG SHORT SIGNED UNSIGNED
%token IDENTIFICADOR
%token LITERAL_CADENA
%token COMENTARIO_UNA_LINEA COMENTARIO_VARIAS_LINEAS

%start input

%union{
  struct {
    char* cadena;
    int entero;
  } myStruct;
}


%%

input:                    /* vacio */
                        | input line                                            {nroLineaAnterior = $<myStruct.entero>2}
;

line:                     sentencia
                        | declaracion
                        | prototipo ';'                                         //{printf("[PROTOTIPO]\n");}
                        | funciones                                             //{printf("[FUNCION]\n");}
                        | noC
                        | error ';'                                             {printf("Error sintactico en linea %d\n", $<myStruct.entero>1);}
;

noC:                      COMENTARIO_UNA_LINEA                                  //{printf("[COMENTARIO]\n");}
                        | COMENTARIO_VARIAS_LINEAS                              //{printf("[COMENTARIO]\n");}
;

/*============================== FUNCIONES ==================================*/

prototipo:                VOID IDENTIFICADOR '(' parametrosPrototipo ')'        {ListaFunciones=agregarListaFunciones(ListaFunciones,$<myStruct.cadena>2,"void");}
                        | VOID IDENTIFICADOR '(' ')'                            {ListaFunciones=agregarListaFunciones(ListaFunciones,$<myStruct.cadena>2,"void");}
                        | tipoDeDato IDENTIFICADOR '(' parametrosPrototipo ')'  {ListaFunciones=agregarListaFunciones(ListaFunciones,$<myStruct.cadena>2,$<myStruct.cadena>1);}
                        | tipoDeDato IDENTIFICADOR '(' ')'                      {ListaFunciones=agregarListaFunciones(ListaFunciones,$<myStruct.cadena>2,$<myStruct.cadena>1);}
;

parametrosPrototipo:      tipoDeDato
                        | tipoDeDato ',' parametrosPrototipo
;

funciones:                VOID IDENTIFICADOR '(' ')' sentencia                          {ListaFunciones=agregarListaFunciones(ListaFunciones,$<myStruct.cadena>2,"void");}
                        | VOID IDENTIFICADOR '(' parametrosFuncion ')' sentencia        {ListaFunciones=agregarListaFunciones(ListaFunciones,$<myStruct.cadena>2,"void");}
                        | tipoDeDato IDENTIFICADOR '(' ')' sentencia                    {ListaFunciones=agregarListaFunciones(ListaFunciones,$<myStruct.cadena>2,$<myStruct.cadena>1);}
                        | tipoDeDato IDENTIFICADOR '(' parametrosFuncion ')' sentencia  {ListaFunciones=agregarListaFunciones(ListaFunciones,$<myStruct.cadena>2,$<myStruct.cadena>1);}    
;

parametrosFuncion:        tipoDeDato IDENTIFICADOR {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, $<myStruct.cadena>2, tipo);}
                        | tipoDeDato IDENTIFICADOR ',' {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, $<myStruct.cadena>2, tipo);} parametrosFuncion
;


/*==============================================SENTENCIAS===========================================*/
/* conflictos: 1 desplazamiento/reducción (En sentElse)*/

sentencia:                sentExpresion                                         {ListaSentencias=agregarListaSentencias(ListaSentencias,"Sentencia de Expresion",$<myStruct.entero>1);}
                        | sentCompuesta                                         {ListaSentencias=agregarListaSentencias(ListaSentencias,"Inicio sentencia Compuesta",$<myStruct.entero>1);}
                        | sentSeleccion                                         {ListaSentencias=agregarListaSentencias(ListaSentencias,"Sentencia Seleccion",$<myStruct.entero>1);}
                        | sentIteracion                                         {ListaSentencias=agregarListaSentencias(ListaSentencias,"Sentencia Iteracion",$<myStruct.entero>1);}
                        | sentEtiquetado                                        {ListaSentencias=agregarListaSentencias(ListaSentencias,"Sentencia Etiquetado",$<myStruct.entero>1);}
                        | sentSalto                                             {ListaSentencias=agregarListaSentencias(ListaSentencias,"Sentencia Salto",$<myStruct.entero>1);}
;

sentExpresion:            expresion ';'
;

sentCompuesta:            '{' listaSentencias '}'                               {ListaSentencias=agregarListaSentencias(ListaSentencias,"Fin sentencia Compuesta",$<myStruct.entero>3);}
                        | '{' '}'                                               {ListaSentencias=agregarListaSentencias(ListaSentencias,"Fin sentencia Compuesta",$<myStruct.entero>2);}
;

listaSentencias:          line
                        | listaSentencias line
;

sentSeleccion:            IF '(' expresion ')' sentencia sentElse                        
                        | SWITCH '(' expresion ')' sentencia                    //{printf("Switch ");}
;

sentElse:                 /* vacio */                                           //{printf("If sin Else ");}                                         
                        | ELSE sentencia                                        //{printf("If con Else ");}
;

sentIteracion:            WHILE '(' expresion ')' sentencia                     //{printf("While ");}
                        | DO line WHILE '(' expresion ')' ';'                   //{printf("DoWhile ");}
                        | FOR '(' cuerpoFor ')' sentencia                       //{printf("For ");}
;

cuerpoFor:                declaracionFor ';' expresion ';' expresion
                        | ';' expresion ';' expresion
                        | declaracionFor ';' ';' expresion
                        | declaracionFor ';' expresion ';'
                        | ';' ';' expresion
                        | declaracionFor ';' ';'
                        | ';' ';'
;

declaracionFor:           tipoDeDato variasVariables
                        | variasVariables
;

sentEtiquetado:           CASE constante ':' sentencia
	                      | DEFAULT ':' sentencia
	                      | IDENTIFICADOR ':' sentencia
;

sentSalto:                BREAK ';'
                        | CONTINUE ';'
                        | RETURN expresion ';'
                        | RETURN ';'
                        | GOTO ';'
;

/*=========================================DECLARACIONES===============================================*/
/* No hay conflictos */

declaracion:              espAlmacenamiento tipoDeDato IDENTIFICADOR ';'
                        | espAlmacenamiento calificadorTipo tipoDeDato IDENTIFICADOR ';'
                        | espAlmacenamiento espStructUnion IDENTIFICADOR ';'
                        | espAlmacenamiento espEnum IDENTIFICADOR ';'
                        | espDeclaracion
;

espDeclaracion:           calificadorTipo tipoDeDato {strcat($<myStruct.cadena>1, " "); strcat($<myStruct.cadena>1, tipo); strcpy(tipo, $<myStruct.cadena>1);} variasVariables ';'
                        | calificadorTipo espSigno {strcat($<myStruct.cadena>1, " "); strcat($<myStruct.cadena>1, $<myStruct.cadena>2); strcpy(tipo, $<myStruct.cadena>1);} variasVariables ';'
                        | declaraciones ';'
;

variasVariables:          inicializacion
                        | variasVariables inicializacion
;

inicializacion:           IDENTIFICADOR ',' {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, $<myStruct.cadena>1, tipo);} inicializacion
		                    | IDENTIFICADOR '=' expresion ',' {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, $<myStruct.cadena>1, tipo);} inicializacion
		                    | IDENTIFICADOR '=' expresion {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, $<myStruct.cadena>1, tipo);}
                        | IDENTIFICADOR {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, $<myStruct.cadena>1, tipo);}
;

espAlmacenamiento:        TYPEDEF
                        | STATIC
                        | AUTO
                        | REGISTER
                        | EXTERN
;

declaraciones:            tipoDeDato variasVariables
                        | espSigno variasVariables
                        | espStructUnion
                        | espEnum
;

espSigno:                 SIGNED tipoDeDato {strcat($<myStruct.cadena>1, " "); strcat($<myStruct.cadena>1, tipo); strcpy(tipo, $<myStruct.cadena>1);}
                        | SIGNED {strcpy(tipo, $<myStruct.cadena>1);}
                        | UNSIGNED tipoDeDato {strcat($<myStruct.cadena>1, " "); strcat($<myStruct.cadena>1, tipo); strcpy(tipo, $<myStruct.cadena>1);}
                        | UNSIGNED {strcpy(tipo, $<myStruct.cadena>1);}
;

tipoDeDato:               CHAR                                                  {strcpy(tipo, $<myStruct.cadena>1);}
	                      | DOUBLE                                                {strcpy(tipo, $<myStruct.cadena>1);}
	                      | FLOAT                                                 {strcpy(tipo, $<myStruct.cadena>1);}
	                      | INT                                                   {strcpy(tipo, $<myStruct.cadena>1);}
	                      | LONG                                                  {strcpy(tipo, $<myStruct.cadena>1);}
	                      | SHORT                                                 {strcpy(tipo, $<myStruct.cadena>1);}
;

calificadorTipo:          CONST                                                 {strcpy(tipo, $<myStruct.cadena>1);}
                        | VOLATILE                                              {strcpy(tipo, $<myStruct.cadena>1);}
;

espStructUnion:           STRUCT IDENTIFICADOR '{' declaracionesStruct '}'      {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, $<myStruct.cadena>2, $<myStruct.cadena>1);}
                        | STRUCT '{' declaracionesStruct '}'
                        | UNION IDENTIFICADOR '{' declaracionesStruct '}'       {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, $<myStruct.cadena>2, $<myStruct.cadena>1);}
                        | UNION '{' declaracionesStruct '}'
;

declaracionesStruct:      tipoDeDato variasVariablesStruct ';'
                        | tipoDeDato variasVariablesStruct ';' declaracionesStruct
;

variasVariablesStruct:    inicializacionStruct
                        | variasVariablesStruct inicializacionStruct
;

inicializacionStruct:     IDENTIFICADOR ',' {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, $<myStruct.cadena>1, tipo);} inicializacionStruct
		                    | IDENTIFICADOR {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, $<myStruct.cadena>1, tipo);}
;

espEnum:                  ENUM IDENTIFICADOR {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, $<myStruct.cadena>2, $<myStruct.cadena>1);} '{' listaIdentificadores '}'       
;

listaIdentificadores:     IDENTIFICADOR ',' {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, $<myStruct.cadena>1, "int");} listaIdentificadores
                        | IDENTIFICADOR {ListaDeclaraciones=agregarListaDeclaracionDeVariable(ListaDeclaraciones, $<myStruct.cadena>1, "int");}
;

/*=============================================EXPRESIONES=============================================*/
/* No hay conflictos */

expresion:                expAsignacion
;

expAsignacion:            expCondicional
                        | expUnaria operAsig expAsignacion
;

operAsig:                 '='
                        | MASIGUAL
                        | MENOSIGUAL
                        | PORIGUAL
                        | DIVISIONGUAL
;

expCondicional:           expOr
                        | expOr '?' expresion ':' expCondicional
;

expOr:                    expAnd
                        | expAnd OR expOr
;

expAnd:                   expIgualdad
                        | expIgualdad AND expAnd
;

expIgualdad:              expRelacional
                        | expRelacional IGUALIGUAL expIgualdad
                        | expRelacional DIFERENTE expIgualdad
;

expRelacional:            expAditiva
                        | expAditiva '<' expRelacional
                        | expAditiva '>' expRelacional
                        | expAditiva MAYORIGUAL expRelacional
                        | expAditiva MENORIGUAL expRelacional
;

expAditiva:               expMultiplicativa
                        | expMultiplicativa '+' expAditiva
                        | expMultiplicativa '-' expAditiva
;

expMultiplicativa:        expUnaria
                        | expUnaria '*' expUnaria
                        | expUnaria '/' expUnaria
                        | expUnaria '%' expUnaria
;

expUnaria:                expSufijo
                        | MASMAS expUnaria
                        | MENOSMENOS expUnaria
                        | operUnario expUnaria
                        | SIZEOF expUnaria
;

operUnario:               '&'
                        | '*'
                        | '+'
                        | '-'
                        | '!'
;

expSufijo:                expPrimaria
                        | expSufijo '[' expresion ']'
                        | expSufijo '(' listaArgumentos ')'
                        | expSufijo '(' ')'
                        | expSufijo '.' IDENTIFICADOR
                        | expSufijo FLECHA IDENTIFICADOR
                        | expSufijo MASMAS
                        | expSufijo MENOSMENOS
;

listaArgumentos:          expAsignacion
                        | expAsignacion ',' listaArgumentos
;

expPrimaria:              IDENTIFICADOR
                        | constante
                        | LITERAL_CADENA
                        | '(' expresion ')'
;

constante:                constanteEntera
                        | CONSTANTE_CARACTER
                        | CONSTANTE_REAL
;

constanteEntera:          CONSTANTE_OCTAL
                        | CONSTANTE_DECIMAL
                        | CONSTANTE_HEXADECIMAL
;

%%

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