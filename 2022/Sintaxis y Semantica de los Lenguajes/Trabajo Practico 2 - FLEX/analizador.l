/* Explicación Breve del Programa:

Objetivo: Utilizar Flex/Lex para generar un codigo C que implemente un analizador lexico.
Dicho programa C permitira reconocer de un 'archivo.c' de entrada (En nuestro caso llamado 'entrada.c')
todas las categorias lexicas de C y además de comentarios:
- Constantes Enteras Decimal
- Constantes Enteras Octal, Hexadecimal (Con su valor en decimal)
- Constantes Real (Indicando Mantisa y Parte Entera)
- Constantes Caracter
- Literales Cadenas (Con su Longitud)
- Palabras Reservadas
- Identificadores (Con cant. de apariciones)
- Caracteres de Puntuacion/operadores de C (Con cant. de apariciones)
- Comentarios de Una y Multiples Lineas
- Cadenas y/o caracteres no reconocidos (Indicando el nº de Linea)

(Al finalizar, debe dar como salida en pantalla un reporte)


/* =====================    O P C I O N E S     ===================== */

%option noyywrap
/* yylineno: Utilizado para obtener el numero de linea */
%option yylineno

/* =====================    D E F I N I C I O N E S     ===================== */
%{

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "libFunciones.h"

// Para crear las listas necesarias
Caracter * listaCaracteres = NULL;
ConContador * listaIdentificadores = NULL;
ConContador * listaOperadoresPuntuacion = NULL;
ConTipo * listaReservadas = NULL;
ConTipo * listaComentarios = NULL;
ConValor * listaLiteralesCadena = NULL;
ConValor * listaNoReconocidos = NULL;
Entero * listaOctales = NULL;
Entero * listaDecimales = NULL;
Entero * listaHexadecimales = NULL;
Real * listaReales = NULL;

%}

/* =====================    A L I A S      ===================== */

CONSTANTE_DECIMAL               [1-9][0-9]*
CONSTANTE_OCTAL                 0[0-7]*
CONSTANTE_HEXADECIMAL           0[xX][0-9A-Fa-f]+
CONSTANTE_REAL                  [0-9]*\.[0-9]+([eE][\+\-]?[0-9]+)?|[0-9]+\.([eE][\+\-]?[0-9]+)?|[0-9]([eE][\+\-]?[0-9]+)?
CONSTANTE_CARACTER              '.'
LITERAL_CADENA                  \".*\"
RESERVADA_DATO                  int|double|float|char|long|short|unsigned|signed|const|static|struct
RESERVADA_CONTROL               else|switch|break|for|void|continue|while|if|do|case|return|default
RESERVADA_OTRA                  auto|enum|register|typedef|extern|sizeof|union|goto|volatile|_Packed
IDENTIFICADOR                   [_a-zA-Z][_a-zA-Z0-9]*
PUNTUADOR_OPERADOR              =|==|!=|\+=|<=|>=|>|<|\+|\-|\*|\/|%|\,|;|\.|:|sizeof|\+\+|!|&|&&|(\|\|)|\(|\)|\{|\}|\[|\]
COMENTARIO_UNA_LINEA            \/\/.*
COMENTARIO_VARIAS_LINEAS        \/\*[^\*\/]*\*\/

/* =====================    R E G L A S    ===================== */

%%

{CONSTANTE_OCTAL}                      agregarEntero(&listaOctales, strtol(yytext, NULL, 8));
{CONSTANTE_DECIMAL}                    agregarEntero(&listaDecimales, atoi(yytext));
{CONSTANTE_HEXADECIMAL}                agregarEntero(&listaHexadecimales, strtol(yytext, NULL, 16));
{CONSTANTE_REAL}                       agregarReales(&listaReales, atof(yytext));
{CONSTANTE_CARACTER}                   agregarCaracter(&listaCaracteres, yytext[1]);
{LITERAL_CADENA}                       agregarListaConValor(&listaLiteralesCadena, yytext, strlen (yytext) - 2);
{RESERVADA_DATO}                       agregarListaTipos(&listaReservadas, yytext, "Dato");
{RESERVADA_CONTROL}                    agregarListaTipos(&listaReservadas, yytext, "Control");
{RESERVADA_OTRA}                       agregarListaTipos(&listaReservadas, yytext, "Otras");
{IDENTIFICADOR}                        agregarListaContadorAlfabeticamente(&listaIdentificadores, yytext);
{PUNTUADOR_OPERADOR}                   agregarListaContador(&listaOperadoresPuntuacion, yytext);
{COMENTARIO_UNA_LINEA}                 agregarListaTipos(&listaComentarios, yytext, "una linea");
{COMENTARIO_VARIAS_LINEAS}             agregarListaTipos(&listaComentarios, yytext, "varias lineas");
\n
\t 
" "
.                                      agregarListaConValor(&listaNoReconocidos, yytext, yylineno);

%%

/* =====================    C O D I G O    C   ===================== */

int main (){
    yyin = fopen("entrada.c", "r");
    yyout = fopen("salida.txt", "w");

    yylex();

    FILE* archInforme = fopen("informe.txt","w");

    imprimirReporte(archInforme,listaIdentificadores, listaLiteralesCadena, listaReservadas, listaDecimales, listaOctales, listaHexadecimales, listaReales, listaCaracteres, listaOperadoresPuntuacion, listaComentarios, listaNoReconocidos);

    fclose(yyin);
    fclose(yyout);
    fclose(archInforme);
    getch();
    return 0;
}
