/* Explicación Breve del Programa:

Tenemos un archivo entrada.txt que tiene distintas palabras separadas por comas.
El programa utilizará un Autómata Finito para reconocer que tipo de palabras son estas.
Este Autómata Finito solo reconoce 3 tipos de palabras!
Constante Octal, Hexadecimal y Decimal (números enteros)
Por cada palabra que lea va a identificar en un archivo de salida (salida.txt) que tipo de palabra es.
Si la palabra no fue reconocida por el Autómata entonces dirá simplemente que no fue reconocida.
========================================================================================================*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#define cantEstados 7
#define gruposDeCaracteres 6


/*                              V A R I A B L E S       G L O B A L E S
========================================================================================================*/

int TablaTransiciones[cantEstados][gruposDeCaracteres];
char num1al7[7] = {'1','2','3','4','5','6','7'};
char letrasHexa[12] = {'a','b','c','d','e','f','A','B','C','D','E','F'};


/*                          P R O T O T I P O S     D E     F U N C I O N E S
========================================================================================================*/

void cargarTablaTransiciones(); // Llenar de datos la tabla de transiciones (La del OneDrive)
void recorrerAutomata(FILE*, FILE*); // Recorrer el autómata utilizando la Tabla de Transiciones ya cargada
int definirTipoDato(char); // Definir que tipo de dato es el leido por el autómata. (Asigna un valor numérico a cada tipo de dato)
void tipoPalabra(int,FILE*); // Dependiendo en que estado finalice, establece que tipo de constante es (lo muestra en pantalla e imprime en el archSalida).


/*                                              M A I N
========================================================================================================*/

int main(){ 
    FILE* archEntrada = fopen("Entrada.txt","r");
    if (!archEntrada){ // Analizar si el archivo de lectura "Entrada.txt" existe
        printf("El archivo \"Entrada.txt\" no existe o su nombre es incorrecto\n");
        getch();
        return 0;
    }

    FILE* archSalida = fopen("Salida.txt","w");

    cargarTablaTransiciones();
    recorrerAutomata(archEntrada,archSalida);

    fclose(archEntrada);
    fclose(archSalida);

    printf("\n=====================================\nClasificacion completada con exito!!!\n=====================================");
    getch();
    return 0;
}


/*                                         F U N C I O N E S
========================================================================================================*/

void recorrerAutomata(FILE* archEntrada, FILE* archSalida){
    char dato; // Variable para almacenar el caracter que se lee del archivo.
    int estadoActual = 0; // Variable para guardar el estado actual del autómata a medida que se va recorriendo.
    int tipoDato; // Variable para guardar el tipo de dato ingresado (Ver función definirTipoDato)

    while ((dato = getc(archEntrada)) != EOF){
        if (dato == ','){
            tipoPalabra(estadoActual,archSalida);
            estadoActual = 0; // Resetear el estado inicial para empezar a leer la próxima palabra.
            continue; // Ejecutar el siguiente ciclo del while, puesto que no nos interesa que tipo de dato es la coma.
        }

        printf("%c",dato);
        fprintf(archSalida,"%c", dato);

        tipoDato = definirTipoDato(dato);

        // Estando en un estado, se pasará al siguiente dependiendo del tipo de dato leido (Esto está indicado en la Tabla de Transiciones).
        estadoActual = TablaTransiciones[estadoActual][tipoDato];
    }

    tipoPalabra(estadoActual,archSalida);
    // Por la última palabra, que en el while no se ejecuta ya que no hay una ","
}

int definirTipoDato(char dato){ // Se toma un dato ingresado y se devuelve su tipo (para que la Tabla de Transiciones lo reconozca como tal).
    if (dato == '0'){
        return 0;
    }
    // "strchr" busca un caracter dentro de una cadena de texto. Si lo encuentra, devuelve un puntero a la posición en donde está. En caso contrario, devuelve NULL
    if (strchr(num1al7, dato) != NULL){
        return 1;
    }

    if (dato == '8' || dato == '9'){
        return 2;
    }

    if (strchr(letrasHexa, dato) != NULL){
        return 3;
    }

    if (dato =='x' || dato =='X'){
        return 4;
    }
    
    return 5;
}

void tipoPalabra(int estActual,FILE* archSalida){ // Escribir en el archivo y en pantalla que tipo de palabra se leyó.
    char* tipoConstante[15];

    switch (estActual){
        case 1: 
        case 5:
        strcpy(tipoConstante,"Octal"); break;
        case 2: 
        strcpy(tipoConstante,"Decimal"); break;
        case 4: 
        strcpy(tipoConstante,"Hexadecimal"); break;
        default: 
        strcpy(tipoConstante,"No reconocida"); break;
    }

    printf(" -> %s\n", tipoConstante);
    fprintf(archSalida," -> %s\n", tipoConstante);
}


/* Esta es la tabla de transiciones del OneNote de Sintaxis! (https://onedrive.live.com/redir?resid=73A86BFF829778D1%21269&authkey=%21AO1GED7Gink1j1g&page=View&wd=target%28AF.one%7C98d52e32-fca4-4b4d-9e51-a21304f9edc1%2FEjemplo%20Constantes%20Enteras%20de%20C%7Cc06b2d48-a235-485d-8c64-e0219aa9cb46%2F%29)
- Las filas de la matriz representan los estados del autómata. (Hay 6 estados, del q0 al q6)
- Las columnas de la matriz representan el tipo de caracter ingresado. (Hay 6 tipos de datos definidos en el autómata)

Tipos de Datos y sus valores numéricos:
    0 -> '0'
    1 -> Números del 1 al 7
    2 -> Números 8 y 9
    3 -> Letras a-f y A-F
    4 -> 'x' y 'X'
    5 -> Otro tipo de dato (no nos interesa cual)

Para qué sirve la Tabla de Transiciones?
Sirve para saber cual es el estado siguiente dado un estado actual y un dato ingresado!
Así es como se recorre un autómata!!! Pasando de un estado al otro a medida que vamos leyendo los caracteres de la palabra.*/

void cargarTablaTransiciones(){
    TablaTransiciones[0][0] = 1;
    TablaTransiciones[0][1] = 2;
    TablaTransiciones[0][2] = 2;
    TablaTransiciones[0][3] = 6;
    TablaTransiciones[0][4] = 6;
    TablaTransiciones[0][5] = 6;

    TablaTransiciones[1][0] = 5;
    TablaTransiciones[1][1] = 5;
    TablaTransiciones[1][2] = 6;
    TablaTransiciones[1][3] = 6;
    TablaTransiciones[1][4] = 3;
    TablaTransiciones[1][5] = 6;

    TablaTransiciones[2][0] = 2;
    TablaTransiciones[2][1] = 2;
    TablaTransiciones[2][2] = 2;
    TablaTransiciones[2][3] = 6;
    TablaTransiciones[2][4] = 6;
    TablaTransiciones[2][5] = 6;

    TablaTransiciones[3][0] = 4;
    TablaTransiciones[3][1] = 4;
    TablaTransiciones[3][2] = 4;
    TablaTransiciones[3][3] = 4;
    TablaTransiciones[3][4] = 6;
    TablaTransiciones[3][5] = 6;

    TablaTransiciones[4][0] = 4;
    TablaTransiciones[4][1] = 4;
    TablaTransiciones[4][2] = 4;
    TablaTransiciones[4][3] = 4;
    TablaTransiciones[4][4] = 6;
    TablaTransiciones[4][5] = 6;

    TablaTransiciones[5][0] = 5;
    TablaTransiciones[5][1] = 5;
    TablaTransiciones[5][2] = 6;
    TablaTransiciones[5][3] = 6;
    TablaTransiciones[5][4] = 6;
    TablaTransiciones[5][5] = 6;

    for (int i=0;i<cantEstados;i++){
        TablaTransiciones[6][i] = 6;
    }

 // La única fila que se cargó usando un for fue la última ya que todos sus campos son iguales.
 // Se podría haber cargado el resto de las filas de una manera similar, pero así nos parece más entendible.
}