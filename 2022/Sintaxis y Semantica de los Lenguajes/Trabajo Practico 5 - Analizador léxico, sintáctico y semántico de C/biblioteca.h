#include <string.h>
#include <stdlib.h>
#include <stdio.h>


/* =====================    N O D O S   ===================== */

typedef struct nodoTablaDeSimbolos {
    char * identificador;
    char * tipoDato;
    char estructura;  // F= funcion, V= variable
    int cantidadDeParametros;
    struct nodoParametros * parametros;
    struct nodoTablaDeSimbolos * sig;
}detalleTablaDeSimbolos;

typedef struct nodoParametros {
    char * identificador;
    char * tipoDato;
    struct nodoParametros * sig;
}detalleParametros;

typedef struct nodoSentenciasEncontradas {
    char * tipoSentencia;
    int nroLinea;
    struct nodoSentenciasEncontradas * sig;
}detalleSentencia;


/* =====================    R E P O R T E  ===================== */

void imprimirSentencias(detalleSentencia * ListaSentencias) {
    // Para generar el reporte de sentencias
    printf("\n\n+ ---------------------------------------------------------------------------------------------------- +\n");
    printf("|                                         S E N T E N C I A S                                          |");
    printf("\n+ ---------------------------------------------------------------------------------------------------- +\n\n");
    if (ListaSentencias==NULL) {
        printf("\n No se han encontrado sentencias.\n");
        return;
    } else {
        while (ListaSentencias!=NULL) {
            printf(" En linea %i: %s\n", ListaSentencias -> nroLinea, ListaSentencias -> tipoSentencia);
            ListaSentencias = ListaSentencias -> sig;
        }
    }
}

void imprimirEstructura(detalleTablaDeSimbolos * Lista, char estructura){
    if (estructura == 'V') {
        printf("\n\n+ ---------------------------------------------------------------------------------------------------- +\n");
        printf("|                           D E C L A R A C I O N E S     V A R I A B L E S                            |");
        printf("\n+ ---------------------------------------------------------------------------------------------------- +\n\n");

        if (Lista == NULL) {
            printf("\n No se han encontrado declaraciones.\n");
            return;
        }

        while (Lista != NULL){
            // Formato para Variables
            if (Lista->estructura == 'V') {
                printf(" Nombre de variable: %s\n --Tipo: %s\n\n", Lista -> identificador, Lista -> tipoDato);
            }
            Lista = Lista -> sig;
        }

    } else {
        printf("\n+ ---------------------------------------------------------------------------------------------------- +\n");
        printf("|                                         F U N C I O N E S                                            |");
        printf("\n+ ---------------------------------------------------------------------------------------------------- +\n\n");

        if (Lista == NULL) {
            printf("\n No se han encontrado funciones.\n");
            return;
        }

        while (Lista != NULL){
            // Formato para Funciones
            if (Lista -> estructura == 'F') {
                printf(" Nombre de Funcion: %s\n --Tipo: %s\n --Cantidad de parametros: %d\n", Lista -> identificador, Lista -> tipoDato, Lista -> cantidadDeParametros);
                int i= 1;
                while(Lista -> parametros != NULL){
                    printf(" ----Parametro %d: %s\n",i, Lista -> parametros -> tipoDato);
                    Lista -> parametros = Lista -> parametros -> sig;
                    i++;
                }
                printf("\n");
            }
            Lista = Lista -> sig;
        }
    }
}

void imprimirErrores(){
    printf("+ ---------------------------------------------------------------------------------------------------- +\n");
    printf("|                                             E R R O R E S                                            |");
    printf("\n+ ---------------------------------------------------------------------------------------------------- +\n\n");
}

void generarReporte(detalleSentencia * ListaSentencias, detalleTablaDeSimbolos * TablaDeSimbolos) {
    // Para generar el reporte de Sentencias
    imprimirSentencias(ListaSentencias);
    // Para generar el reporte de Variables
    imprimirEstructura(TablaDeSimbolos, 'V');
    // Para generar el reporte de Funciones
    imprimirEstructura(TablaDeSimbolos, 'F');
}


/* =====================    S E N T E N C I A S     ===================== */

detalleSentencia * agregarListaSentencias(detalleSentencia * ListaSentencias, char * tipoSentencia, int nroLinea) {
    // Armo nuevo nodo con los datos ingresados por parametro
    detalleSentencia * nuevoNodo = NULL;
    nuevoNodo = (detalleSentencia *) malloc(sizeof (detalleSentencia)); // Reservo memoria para el nuevo nodo
    nuevoNodo -> tipoSentencia = strdup (tipoSentencia);
    nuevoNodo -> nroLinea = nroLinea;
    nuevoNodo -> sig = NULL;

    // Meto el nodo en la ListaSentencias de forma ordenada por nroLinea
    detalleSentencia * aux = ListaSentencias;

    if (aux == NULL || nroLinea < aux -> nroLinea) {
        // Para insertar el elemento en la primera posicion de la lista
        nuevoNodo -> sig = ListaSentencias;
        ListaSentencias = nuevoNodo;
    } else {
        // Para agregar el elementos en la posicion adecuada
        while (aux -> sig != NULL && aux -> sig -> nroLinea < nroLinea) aux = aux -> sig;
        if (aux -> sig != NULL) nuevoNodo -> sig = aux -> sig;
        aux -> sig = nuevoNodo;
    }

    return ListaSentencias;
}


/* =====================    C H E Q U E O S    ===================== */

int existeVariable(detalleTablaDeSimbolos * TablaDeSimbolos, char * identificador) {
    detalleTablaDeSimbolos * aux = NULL;
    // Comprobamos si esta en Tabla de Simbolos
    for (aux = TablaDeSimbolos; aux != NULL; aux = aux -> sig) {
        // strcmp: Para comprobar si dos identificadores son iguales
        
        if(strcmp (aux -> identificador, identificador) == 0 && aux -> estructura == 'V') {
            return 1; // Esta en Tabla
        }  

    }
    return 0; // No esta en Tabla
}

int tiposParametrosCorrectos(detalleParametros * ListaVerificar, detalleParametros * ListaVerificador) {
    detalleParametros * aux = NULL;
    detalleParametros * aux2 = NULL;
    // Verificamos que los tipos de los parametros sean los correctos
    for(aux = ListaVerificar, aux2 = ListaVerificador; aux != NULL && aux2 != NULL; aux = aux -> sig, aux2 = aux2 -> sig) {
        if (strcmp (aux -> tipoDato, aux2 -> tipoDato) == 0) {
            continue; // Parametro correcto
        } else {
            return 0; // Parametro incorrecto
        }
    }
    return 1;
}

// No la estamos usando actualmente.
void agregarIdentificadoresFuncion(detalleParametros * ListaAntParametros, detalleParametros * ListaDefParametros) {
    detalleParametros * aux = NULL;
    detalleParametros * aux2 = NULL;

    // Cambiamos el NULL por el identificador correspondiente
    for(aux = ListaAntParametros, aux2 = ListaDefParametros; aux != NULL && aux2 != NULL; aux = aux -> sig, aux2 = aux2 -> sig) {
        aux -> identificador = aux2 -> identificador;
    }
}

int tienePrototipo(detalleTablaDeSimbolos * funcion, detalleTablaDeSimbolos * TablaDeSimbolos, int nroLinea) {
    detalleTablaDeSimbolos * aux = NULL;
    // Verificamos que la funcion sea identica a su prototipo, si es que tiene
    for (aux = TablaDeSimbolos; aux != NULL; aux = aux -> sig) {
        // Comprobar que los dos identificadores sean iguales
        if (strcmp (aux -> identificador, funcion -> identificador) == 0 && aux -> estructura == 'F') {
            // Comprobar que los tipos de funciones sean iguales
            if (strcmp (aux -> tipoDato, funcion -> tipoDato) == 0) {
                // Para comprobar que tengan la misma cantidad de parametros
                if (aux -> cantidadDeParametros == funcion -> cantidadDeParametros) {
                    // Para comprobar que tengan los mismos tipos de parametros
                    if (!tiposParametrosCorrectos(aux -> parametros, funcion -> parametros)) {
                        printf(" Error semantico en linea %d: Tipos de parametros incorrectos en funcion %s\n", nroLinea, aux -> identificador);
                        return 1;
                    } else {
                        // agregarIdentificadoresFuncion(aux -> parametros, funcion -> parametros);
                        return 1; // Funcion correcta, pero no la agrego a la TS porque ya existe.
                    }
                } else {
                    printf(" Error semantico en linea %d: Cantidad de parametros incorrecta en funcion %s\n", nroLinea, aux -> identificador);
                    return 1;
                }
            } else {
                printf(" Error semantico en linea %d: Tipo de funcion %s incorrecto\n", nroLinea, aux -> identificador);
                return 1;
            }
        }
    }
    return 0; // Funcion correcta (Caso especial para funciones sin prototipo)
}

int verificarExistencia(char * identificador, detalleParametros * ListaArgumentos, detalleTablaDeSimbolos * TablaDeSimbolos, int cantidadArgumentos, int nroLinea){
    detalleTablaDeSimbolos * aux = NULL;
    // Verificamos que exista la funcion llamada
    for (aux = TablaDeSimbolos; aux != NULL; aux = aux -> sig) {
        // Comprobamos que sean las mismas funciones
        if (strcmp(aux -> identificador, identificador) == 0 && aux -> estructura == 'F') {
            // Comprobamos cantidad de parametros
            if (aux -> cantidadDeParametros == cantidadArgumentos) {
                // Comprobar que los tipos de argumentos sean los correctos
                if (!tiposParametrosCorrectos(ListaArgumentos, aux -> parametros)) {
                    printf(" Error semantico en linea %d: Tipos de argumentos incorrectos en llamada de funcion %s\n", nroLinea, identificador);
                    return 0;
                } else {
                    return 1; // Funcion encontrada
                }
            } else {
                printf(" Error semantico en linea %d: Cantidad de argumentos incorrectos en llamada de funcion %s\n", nroLinea, identificador);
                return 0;
            }
        }
    }
    printf(" Error semantico en linea %d: No existe la funcion %s\n", nroLinea, identificador);
    return 0;
}


/* =====================    T A B L A S   D E   S I M B O L O S    ===================== */

detalleTablaDeSimbolos * agregarAListaDeSimbolos(detalleTablaDeSimbolos * TablaDeSimbolos, char * identificador, char * tipoDato, char estructura, detalleParametros * ListaParametros, int cantidadDeParametros, int nroLinea) {
    detalleTablaDeSimbolos * aux = NULL;

    if (estructura == 'V'){ // Variables
        for (aux = TablaDeSimbolos; aux != NULL; aux = aux -> sig) {
            // Comprobamos si hay doble declaracion de variables
            if (strcmp(aux -> identificador, identificador) == 0 && aux -> estructura == 'V') {
                printf(" Error semantico en linea %d: Doble declaracion del identificador %s\n", nroLinea, identificador);
                return TablaDeSimbolos; // Hubo coincidencia
            }
        }
    }
    
    // Armo nuevo nodo con los datos ingresados por parametro
    detalleTablaDeSimbolos * nuevoNodo = NULL;
    nuevoNodo = (detalleTablaDeSimbolos *) malloc(sizeof (detalleTablaDeSimbolos)); // Reservo memoria para el nodo
    nuevoNodo -> tipoDato = strdup (tipoDato);
    nuevoNodo -> identificador = strdup (identificador);
    nuevoNodo -> estructura = estructura;
    nuevoNodo -> cantidadDeParametros = cantidadDeParametros;
    nuevoNodo -> parametros = ListaParametros;
    nuevoNodo -> sig = NULL;

    if (estructura == 'F') { // Funciones
        // Meto el nodo en la ListaFunciones
        if(tienePrototipo (nuevoNodo, TablaDeSimbolos, nroLinea)){
            return TablaDeSimbolos;
        } 
    }

    // Meto el nodo en la TablaDeSimbolos
    aux = TablaDeSimbolos;

    if (aux == NULL){
        TablaDeSimbolos = nuevoNodo;
    } else {
        // Agrega las declaraciones reconocidas al final de la lista
        while (aux -> sig != NULL) aux = aux -> sig;
        if (aux -> sig == NULL) aux -> sig = nuevoNodo;
    }
    
    return TablaDeSimbolos;
}


/* =====================    P A R A M E T R O S     ===================== */

detalleParametros * agregarListaParametros(detalleParametros * ListaParametros, char * identificador, char * tipoDato){
    // Armo nuevo nodo con los datos ingresados por parametro
    detalleParametros *nuevoNodo = NULL;
    nuevoNodo = (detalleParametros *) malloc(sizeof (detalleParametros)); // Reservo memoria para el nodo
    nuevoNodo -> tipoDato = strdup (tipoDato);
    nuevoNodo -> identificador = strdup (identificador);
    nuevoNodo -> sig = NULL;

    // Meto el nodo en la ListaParametros
    detalleParametros *aux = ListaParametros;
    if (aux == NULL){
        ListaParametros = nuevoNodo;
    } else {
        // Agrega los parametros reconocidos al final de la lista
        while (aux -> sig != NULL) aux = aux -> sig;

        if (aux -> sig == NULL) aux -> sig = nuevoNodo;
    }
    
    return ListaParametros;
}