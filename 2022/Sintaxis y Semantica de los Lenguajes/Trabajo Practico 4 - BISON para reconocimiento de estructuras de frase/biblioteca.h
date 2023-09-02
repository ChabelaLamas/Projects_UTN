#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* =====================    N O D O S   ===================== */

typedef struct nodoSentenciasEncontradas{ // Crear el Nodo para elementos con tipo (Reservados y comentarios)
    char * tipoSentencia;
    int nroLinea;
    struct nodoSentenciasEncontradas * sig;
}detalleSentencia;

typedef struct nodoDeclaracionesEncontradas{ // Crear el Nodo para las declaraciones encontradas
    char * identificador;
    char * tipoDato;
    struct nodoDeclaracionesEncontradas * sig;
}detalleDeclaraciones;

typedef struct nodoFuncionesEncontradas{ // Crear el Nodo para las funciones encontradas
    char * identificador;
    char * tipoDato;
    struct nodoFuncionesEncontradas * sig;
}detalleFunciones;


/* =====================    F U N C I O N E S   ===================== */

void juntarTipos (char tipo[20], char agregado[20]) {
    strcat(agregado, " ");
    strcat(agregado, tipo);
    strcpy(tipo, agregado);
}

/* = S E N T E N C I A S = */
detalleSentencia* agregarListaSentencias (detalleSentencia *ListaSentencias, char *tipoSentencia, int nroLinea){
    
    /*Armo nuevo nodo con los datos ingresados por parámetro*/
    detalleSentencia *nuevoNodo = NULL;
    nuevoNodo = (detalleSentencia *) malloc(sizeof (detalleSentencia)); //Reservo memoria para el nodo
    nuevoNodo -> tipoSentencia = strdup (tipoSentencia);
    nuevoNodo -> nroLinea = nroLinea;
    nuevoNodo -> sig = NULL;

    /* Meto el nodo en la ListaSentencias de forma ordenada por nroLinea */
    detalleSentencia *aux = ListaSentencias;

    /* Para insertar el elemento en la primera posicion de la lista */
    if (aux == NULL || nroLinea < aux -> nroLinea){
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


int recorrerListaSentencias(detalleSentencia *ListaSentencias){

    if(ListaSentencias==NULL){

        printf("\n No se han encontrado sentencias.\n");

        return 1;
    }else{
        printf("\nSENTENCIAS\n\n");

        while(ListaSentencias!=NULL){
            
            printf("Linea %i: %s\n",ListaSentencias->nroLinea,ListaSentencias->tipoSentencia);
//            printf("\n Se encontro una %s en la linea %i",ListaSentencias->tipoSentencia,ListaSentencias->nroLinea);

            ListaSentencias = ListaSentencias->sig;

        }

    }

    return 0;
}

/* = V A R I A B L E S    D E C L A R A D A S = */

detalleDeclaraciones* agregarListaDeclaracionDeVariable (detalleDeclaraciones *ListaDeclaraciones, char * identificador, char * tipoDato){
    
    /*Armo nuevo nodo con los datos ingresados por parámetro*/
    detalleDeclaraciones *nuevoNodo = NULL;
    nuevoNodo = (detalleDeclaraciones *) malloc(sizeof (detalleDeclaraciones)); //Reservo memoria para el nodo
    nuevoNodo -> tipoDato = strdup (tipoDato);
    nuevoNodo -> identificador = strdup (identificador);
    nuevoNodo -> sig = NULL;

    /*Meto el nodo en la ListaDeclaraciones*/

    detalleDeclaraciones *aux = ListaDeclaraciones;

    if (aux == NULL){
        ListaDeclaraciones = nuevoNodo;
    } else {
        
        /*Agrega las declaraciones reconocidas al final de la lista*/
        while (aux -> sig != NULL) aux = aux -> sig;

        if (aux -> sig == NULL) aux -> sig = nuevoNodo;

    }
    
    return ListaDeclaraciones;
}


int recorrerListaDeclaracionesVariables(detalleDeclaraciones *ListaDeclaraciones){
    printf("\nDECLARACIONES\n\n");

    if(ListaDeclaraciones==NULL){

        printf("\n No se han declarado variables.");
        return 1;
    }else{
        printf("Se declarararon los siguientes identificadores: \n");

        while (ListaDeclaraciones!=NULL){
            printf("--Nombre: %s -> Tipo: %s \n", ListaDeclaraciones->identificador,ListaDeclaraciones->tipoDato);
            ListaDeclaraciones = ListaDeclaraciones->sig;
        }
    }

    return 0;

}

/* = F U N C I O N E S    D E C L A R A D A S = */

detalleFunciones* agregarListaFunciones (detalleFunciones *ListaFunciones, char *identificador, char *tipoDato){
    /*Armo nuevo nodo con los datos ingresados por parámetro*/
    detalleFunciones *nuevoNodo = NULL;
    nuevoNodo = (detalleFunciones *) malloc(sizeof (detalleFunciones)); //Reservo memoria para el nodo
    nuevoNodo -> tipoDato = strdup (tipoDato);
    nuevoNodo -> identificador = strdup (identificador);
    nuevoNodo -> sig = NULL;

    /*Meto el nodo en la ListaFunciones*/

    detalleFunciones *aux = ListaFunciones;
    if (aux == NULL){
        ListaFunciones = nuevoNodo;
    } else {
        /*Agrega las funciones reconocidas al final de la lista*/
        while (aux -> sig != NULL) aux = aux -> sig;

        if (aux -> sig == NULL) aux -> sig = nuevoNodo;
    }
    
    return ListaFunciones;
}

int recorrerListaFunciones(detalleFunciones *ListaFunciones){

    if(ListaFunciones==NULL){

        printf("\n No se han declarado funciones.");

        return 1;
    }else{
        printf("\n Se declarararon las siguientes funciones: \n");

        while (ListaFunciones!=NULL){
            printf("--Nombre: %s -> Tipo: %s \n", ListaFunciones->identificador,ListaFunciones->tipoDato);
            ListaFunciones = ListaFunciones->sig;
        }
    }

    return 0;
}