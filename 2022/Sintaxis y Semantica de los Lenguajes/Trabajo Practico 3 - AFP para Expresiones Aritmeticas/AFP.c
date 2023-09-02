/*Explicación Breve del Programa:

Tenemos como objetivo implementar en C un programa que permita reconocer expresiones aritméticas de suma,
resta, producto y cociente utilizando un AFP. Para eso, se tomará una expresión (Cadena de caracteres)
ingresada desde un STDIN y deberá indicar por pantalla, STDOUT, si la expresión es sintacticamente correcta o no.
El alfabeto de cual podrá estar compuestas las expresiones serán las siguientes: {0,1,2,3,4,5,6,7,8,9,+,-,*,/,(,)}

Como objetivo opcional, si la cadena no es sintácticamente correcta, se indicará al usuario dónde se encontró
el error (posición en la secuencia, qué lo produjo y que elemento se estaba esperando)
========================================================================================================*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define cantEstados 3
#define grupoDeCaracteres 6
#define cimaPila 2

/*                          V A R I A B L E S       G L O B A L E S
========================================================================================================*/

int TablaMovimientos[cantEstados][grupoDeCaracteres][cimaPila];
char num1a9[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char operadores[4] = {'+', '-', '*', '/'};

/*                                  N O D O         P I L A
========================================================================================================*/

typedef struct NodoPila{
    char simbolo;
    struct NodoPila * sig;
}Pila;

Pila * memoria = NULL;

/*                          P R O T O T I P O S     D E     F U N C I O N E S
========================================================================================================*/

void recorrerAutomataPila(char *);// Recorrer el AFP utilizando la Tabla de Movimientos cargada
void validarExpresion(int, int, int, int, char, int); // Indicar si es sintácticamente correcto o no.
void indicarError(int, int, int, int, char); // Marcar el error si no es sintácticamente correcto.
void push(char); // Realizar el push de elementos al realizar la transición
char pop(); // Realizar el pop del elemento que está en la cima de la Pila
int definirCima(); // Asignar un valor numérico a cada elemento de la Pila
int definirTipoDato(char); // Asignar un valor numérico a cada tipo de dato
void cargarTablaMovimientos(); // Llenar de datos la Tabla de Movimientos
void liberarMemoria(); // Limpiar la Memoria

/*                                              M A I N
========================================================================================================*/

int main(){
    while(1){
        // Pedir la expresión aritmética por pantalla
        char expresion[] = "$";
        printf ("Ingrese una expresion aritmetica: ");
        gets (expresion); 

        push('$'); // Cargamos la memoria de la pila
        cargarTablaMovimientos(); // Cargamos la Tabla de Movimientos
        recorrerAutomataPila(expresion);
        liberarMemoria();
        printf("\n----------------------------------------------------------------------------------\n\n");
    }
return 0;
}

/*                                          F U N C I O N E S
========================================================================================================*/

void recorrerAutomataPila(char * expresion){
    // Variables para guardar la posición del Error, el Estado Actual, la Cima y el tipoDato
    int posicionError = 0, espacios = 0, estadoActual = 0, tipoCima = 0, tipoDato;
    char error = 'e';

    for (int i = 0; i < strlen (expresion); i++){
        if ((expresion[i]) == ' ') {
            espacios = espacios + 1;
            continue;
        } // Ejecutar el siguiente ciclo for, puesto que no interesan los espacios
        
        tipoCima = definirCima();
        tipoDato = definirTipoDato(expresion[i]);
        estadoActual = TablaMovimientos[estadoActual][tipoDato][tipoCima];

        posicionError = i;
        if (estadoActual == 3) {
            error = expresion[i];
            break; // Para romper el ciclo for si ya encontró un error
        }
    }
    tipoCima = definirCima(); // Para debugging
    validarExpresion (estadoActual, tipoCima, tipoDato, posicionError, error, espacios);
}

void liberarMemoria(){
    while (memoria != NULL){
        Pila * aux = memoria;
        memoria = memoria -> sig;
        free(aux);
    }
}

void validarExpresion(int estadoActual, int tipoCima, int tipoDato, int posicionError, char error, int espacios){
    if ((estadoActual == 1 && tipoCima == 0) || (estadoActual == 2 && tipoCima == 0)){
        printf ("\nLa expresion aritmetica ingresada es sintacticamente correcta");
    } else {
        indicarError(estadoActual, tipoCima, tipoDato, posicionError, error);
        printf ("\nLa expresion aritmerica ingresada no es sintacticamente correcta. Error en la posicion: %d", (posicionError - espacios + 1));
    }
}

void indicarError(int estadoActual, int tipoCima, int tipoDato, int posicionError, char error){
    for (int i = 0; i < strlen ("Ingrese una expresion aritmetica: "); i++) printf (" ");
    for (int i = 0; i < posicionError; i++) printf (" ");
    printf ("^ Error. ");

    switch (tipoDato){
    case 0:
        printf ("Caracter invalido '%c'\n", error);
    break;

    case 1:
        printf ("Falta cierre de parentesis ')'\n");
    break;

    case 2:
        if (estadoActual == 3 && (strchr (operadores, error) != NULL)) printf ("Se espera un numero antes de '%c'\n", error);
        if (estadoActual != 3 && (strchr (operadores, error) == NULL)) printf ("Se espera un numero despues de operador\n");
    break;

    case 3:
        if (estadoActual == 3 && tipoCima == 1 && error == '(') printf ("Se espera un operador antes de '%c'\n", error);
        if (estadoActual != 3 && error != '(') printf ("Falta cierre de parentesis ')'\n");
    break;

    case 4:
        if (estadoActual == 3 && tipoCima == 0 && error == ')') printf ("Se espera un numero antes de '%c'\n", error);
        if (estadoActual != 3 && tipoCima == 1) printf ("Falta cierre de parentesis ')'\n");
    break;

    case 5:
        if (estadoActual == 3 && error == ')') printf ("Falta apertura de parentesis '('\n");
        if (estadoActual == 3 && error != ')') printf ("Caracter invalido '%c'\n", error);
    break;
    
    default:
        /* code */
    break;
    }
}

void push(char simbolo){
    // Insertar en memoria los símbolo '$' o 'R' según corresponda
    Pila * nuevaCima = NULL;
    nuevaCima = (Pila *) malloc (sizeof (Pila));
    nuevaCima -> simbolo = simbolo;

    if (memoria == NULL){ // Insertar '$'
        memoria = nuevaCima;
        nuevaCima -> sig = NULL;
    } else { // Insertar 'R'
        nuevaCima -> sig = memoria;
        memoria = nuevaCima;
    }
}

char pop(){
    // Sacar de memoria los símbolos '$' o 'R' según corresponda
    char simbolo = memoria -> simbolo;
    Pila * aux = memoria;
    memoria = memoria -> sig;
    free (aux);
    return simbolo;
}

int definirCima (){
    // Dependiendo del simbolo de la cima, retorna su Tipo
    if (memoria -> simbolo == '$') return 0;
    return 1;
}

int definirTipoDato (char dato){
    // Dependiendo del dato ingresado, retorna su tipo. Además de realizar el respectivo pop y push
    // En cada transición se realiza un "pop" del elemento que esta en la cima de la Pila. Opcionalmente podemos realizar un "push" de 0 o más elementos al realizar la transición
    if (dato == '0') {
        push(pop());
        return 0;
    }
    // "strchr" busca un caracter dentro de una cadena de texto. Si lo encuentra, devuelve un puntero a la posición en donde está. En caso contrario, devuelve NULL
    if (strchr (num1a9, dato) != NULL) {
        push(pop());
        return 1;
    }

    if (strchr (operadores, dato) != NULL) {
        push(pop());
        return 2;
    }

    if (dato == '('){
        push(pop());
        push('R');
        return 3;
    }

    if (dato == ')'){
        if (pop() == 'R') return 4;
        push('$'); // Para debugging
        return 5;
    }

    return 5;
}

/* Esta es la Tabla de Movimientos del AFP a implementar:
+--------------------+------------------------------------------------------------------------------+
|                    |                                C a r a c t e r                               |
| (Estado, CimaPila) |------------------------------------------------------------------------------+
|                    |       0       |     [1, 9]    | {+, -, *, /}  |      (       |       )       |
+--------------------+---------------+---------------+---------------+--------------+---------------+
|     (q0, $)        |       -       |    (q1, $)    |       -       |   (q0, R$)   |       -       |
|     (q1, $) +      |    (q1, $)    |    (q1, $)    |    (q0, $)    |      -       |       -       |
|     (q0, R)        |       -       |    (q1, R)    |       -       |   (q1, RR)   |       -       |
|     (q1, R)        |    (q1, R)    |    (q1, R)    |    (q0, R)    |      -       |    (q2, e)    |
|     (q2, R)        |       -       |       -       |    (q0, R)    |      -       |    (q2, e)    |
|     (q2, $) +      |       -       |       -       |    (q0, $)    |      -       |       -       |
+--------------------+---------------+---------------+---------------+--------------+---------------+
Donde:
- Alfabeto                  = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, +, -, *, /, (, )}
- Conj. de símbolos         = {$, R}
- Conj. de estados          = {q0, q1, q2}
- Conj. de estados finales  = {q1, q2}

Las filas de la matriz representan (Estados del Autómata, Cima de la Pila)
Las columnas de la matriz representan el tipo de caracter ingresado

Tipo de Datos y sus valores numéricos:
    0 - '0'
    1 - Número del 1 al 9
    2 - Operadores +, -, *, /
    3 - '('
    4 - ')'
    5 - Otro tipo de datos

Tipo de Cima y sus valores numéricos:
    0 - '$'
    1 - 'R'
*/

// Primer campo hace referencia al estado en el que se está.
// segundo campo es tipo de dato ingresado.
// Tercer campo es estado de pila.

void cargarTablaMovimientos (){
    // (q0,$)
    TablaMovimientos[0][0][0] = 3;  // '0'
    TablaMovimientos[0][1][0] = 1;  // [1 - 9]
    TablaMovimientos[0][2][0] = 3;  // {+, -, *, /}
    TablaMovimientos[0][3][0] = 0;  // '('
    TablaMovimientos[0][4][0] = 3;  // ')'
    TablaMovimientos[0][5][0] = 3;  // N/A

    // (q1,$)
    TablaMovimientos[1][0][0] = 1;
    TablaMovimientos[1][1][0] = 1;
    TablaMovimientos[1][2][0] = 0;
    TablaMovimientos[1][3][0] = 3;
    TablaMovimientos[1][4][0] = 3;
    TablaMovimientos[1][5][0] = 3;

    // (q2,$)
    TablaMovimientos[2][0][0] = 3;
    TablaMovimientos[2][1][0] = 3;
    TablaMovimientos[2][2][0] = 0;
    TablaMovimientos[2][3][0] = 3;
    TablaMovimientos[2][4][0] = 3;
    TablaMovimientos[2][5][0] = 3;
    
    // (q0,R)
    TablaMovimientos[0][0][1] = 3;
    TablaMovimientos[0][1][1] = 1;
    TablaMovimientos[0][2][1] = 3;
    TablaMovimientos[0][3][1] = 0;
    TablaMovimientos[0][4][1] = 3;
    TablaMovimientos[0][5][1] = 3;
    
    //(q1,R)
    TablaMovimientos[1][0][1] = 1;
    TablaMovimientos[1][1][1] = 1;
    TablaMovimientos[1][2][1] = 0;
    TablaMovimientos[1][3][1] = 3;
    TablaMovimientos[1][4][1] = 2;
    TablaMovimientos[1][5][1] = 3;

    // (q2,R)
    TablaMovimientos[2][0][1] = 3;
    TablaMovimientos[2][1][1] = 3;
    TablaMovimientos[2][2][1] = 0;
    TablaMovimientos[2][3][1] = 3;
    TablaMovimientos[2][4][1] = 2;
    TablaMovimientos[2][5][1] = 3;

    for (int i = 0; i < grupoDeCaracteres; i++) TablaMovimientos[3][i][0] = 3;
    for (int j = 0; j < grupoDeCaracteres; j++) TablaMovimientos[3][j][1] = 3;
}