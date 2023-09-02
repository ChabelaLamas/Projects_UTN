/* =====================    N O D O S   ===================== */

typedef struct NodoConValor{ // Crear el Nodo para elementos con valor (Literales cadenas y no reconocidos)
    char * elemento;
    int valor;
    struct NodoConValor * sig;
}ConValor;

typedef struct NodoConContador{ // Crear el Nodo para elementos con contador (Identificadores y operadores/puntuación)
    char * elemento;
    int contador;
    struct NodoConContador * sig;
}ConContador;

typedef struct NodoConTipo{ // Crear el Nodo para elementos con tipo (Reservados y comentarios)
    char * elemento;
    char * tipo;
    struct NodoConTipo * sig;
}ConTipo;

typedef struct NodoEntero{ // Crear el Nodo para Enteros (Octales, Decimales y Hexadecimales)
    int valor;
    struct NodoEntero * sig;
}Entero;

typedef struct NodoReal{ // Crear el Nodo para Reales
    double valor;
    struct NodoReal * sig;
}Real;

typedef struct NodoCaracter{ // Crear el Nodo para Caracteres
    char caracter;
    struct NodoCaracter * sig;
}Caracter;


/* =====================    F U N C I O N E S   ===================== */

void agregarListaConValor (ConValor ** Lista, char * elemento, int valor){
    // Para comprobar si en la Lista ya existe el elemento a ingresar
    ConValor * aux = NULL;
    for (aux = * Lista; aux != NULL; aux = aux -> sig) {
        //strcmp: Para comprobar si dos Strings son iguales
        if (strcmp (aux -> elemento, elemento) == 0 && aux -> valor == valor) return; // Hubo coincidencia
    }
    // Para crear el Nuevo Nodo e insertar sus valores
    ConValor * nuevoElemento = NULL;
    nuevoElemento = (ConValor *) malloc (sizeof (ConValor)); // Para reservar memoria suficiente
    nuevoElemento -> elemento = strdup (elemento);
    nuevoElemento -> valor = valor;
    nuevoElemento -> sig = NULL;

    // Insertar el Nodo creado a la lista de forma ordenada (Ordenadas por valor)
    aux = * Lista;
    if (aux == NULL || valor < aux -> valor){
        // Solamente para agregar el PRIMER ELEMENTO a la lista
        nuevoElemento -> sig = * Lista;
        * Lista = nuevoElemento;
    } else {
        // Para agregar el RESTO DE ELEMENTOS a la lista, buscamos la posicion donde va insertado
        while (aux -> sig != NULL && aux -> sig -> valor < valor) aux = aux -> sig;
        if (aux -> sig != NULL) nuevoElemento -> sig = aux -> sig;
        aux -> sig = nuevoElemento;
    }
}

void agregarListaContador (ConContador ** Lista, char * valor){
    // Para comprobar si en la Lista ya existe el elemento a ingresar
    ConContador * aux = NULL;
    for (aux = * Lista; aux != NULL; aux = aux -> sig){
        //strcmp: Para compruebar si dos Strings son iguales 
        if (strcmp (aux -> elemento, valor) == 0){
            aux -> contador ++;
            return; // Hubo coincidencia
        }
    }
    // Para crear el Nuevo Nodo e insertar sus valores
    ConContador * nuevoElemento = NULL;
    nuevoElemento = (ConContador *) malloc (sizeof (ConContador)); // Para reservar memoria suficiente
    nuevoElemento -> elemento = strdup (valor);
    nuevoElemento -> contador = 1;
    nuevoElemento -> sig = NULL;
    
    aux = * Lista;
    if (aux == NULL){
        // Solamente para agregar el PRIMER ELEMENTO a la lista
        * Lista = nuevoElemento;
    } else {
        // Para agregar el RESTO DE ELEMENTOS a la lista
        while (aux -> sig != NULL) aux = aux -> sig;
        aux -> sig = nuevoElemento;
    }
}

// Esta función es para el caso particular de los identificadores.
void agregarListaContadorAlfabeticamente (ConContador ** Lista, char * valor){
    // Para comprobar si en la Lista ya existe el elemento a ingresar
    ConContador * aux = NULL;
    for (aux = * Lista; aux != NULL; aux = aux -> sig){
        //strcmp: Para compruebar si dos Strings son iguales 
        if (strcmp (aux -> elemento, valor) == 0){
            aux -> contador ++;
            return; // Hubo coincidencia
        }
    }
    // Para crear el Nuevo Nodo e insertar sus valores
    ConContador * nuevoElemento = NULL;
    nuevoElemento = (ConContador *) malloc (sizeof (ConContador)); // Para reservar memoria suficiente
    nuevoElemento -> elemento = strdup (valor);
    nuevoElemento -> contador = 1;
    nuevoElemento -> sig = NULL;
    
    // Insertar el Nodo creado a la lista de forma ordenada (Ordenadas alfabeticamente)
    aux = * Lista;
    if (aux == NULL || strcmp (aux -> elemento, valor) == 1){
        // Solamente para agregar el PRIMER ELEMENTO a la lista
        nuevoElemento -> sig = * Lista;
        * Lista = nuevoElemento;
    } else {
        // Para agregar el RESTO DE ELEMENTOS a la lista, buscamos la posicion donde va insertado
        while (aux -> sig != NULL && strcmp (aux -> sig -> elemento, valor) == - 1) aux = aux -> sig;
        if (aux -> sig != NULL) nuevoElemento -> sig = aux -> sig;
        aux -> sig = nuevoElemento;
    }
}

void agregarListaTipos (ConTipo ** Lista, char * valor, char * tipo){
    // Para crear el Nuevo Nodo e insertar sus valores
    ConTipo * nuevoElemento = NULL;
    nuevoElemento = (ConTipo *) malloc (sizeof (ConTipo)); // Para reservar memoria suficiente
    nuevoElemento -> elemento = strdup (valor);
    nuevoElemento -> tipo = strdup (tipo);
    nuevoElemento -> sig = NULL;
    
    // Insertar el Nodo creado a la lista de forma ordenada (Orden de aparicion)
    ConTipo * aux = * Lista;
    if (aux == NULL){
        // Solamente para agregar el PRIMER ELEMENTO a la lista
        * Lista = nuevoElemento;
    } else {
        // Para agregar el RESTO DE ELEMENTOS a la lista
        while (aux -> sig != NULL) aux = aux -> sig;
        aux -> sig = nuevoElemento;
    }
}

void agregarEntero (Entero ** Lista, int valor){
    // Para crear el Nuevo Nodo e insertar sus valores
    Entero * nuevoEntero = NULL;
    nuevoEntero = (Entero *) malloc (sizeof (Entero)); // Para reservar memoria suficiente
    nuevoEntero -> valor = valor;
    nuevoEntero -> sig = NULL;
    
    // Insertar el Nodo creado a la lista de forma ordenada (Orden de aparicion)
    Entero * aux = * Lista;
    if (aux == NULL){
        // Solamente para agregar el PRIMER ELEMENTO a la lista
        * Lista = nuevoEntero;
    } else {
        // Para agregar el RESTO DE ELEMENTOS a la lista
        while (aux -> sig != NULL) aux = aux -> sig;
        aux -> sig = nuevoEntero;
    }
}

void agregarReales (Real ** Lista, double valor){
    // Para crear el Nuevo Nodo e insertar sus valores
    Real * nuevoReal = NULL;
    nuevoReal = (Real *) malloc (sizeof (Real)); // Para reservar memoria suficiente
    nuevoReal -> valor = valor;
    nuevoReal -> sig = NULL;
    
    // Insertar el Nodo creado a la lista de forma ordenada (Orden de aparicion)
    Real * aux = * Lista;
    if (aux == NULL){
        // Solamente para agregar el PRIMER ELEMENTO a la lista
        * Lista = nuevoReal;
    } else {
        // Para agregar el RESTO DE ELEMENTOS a la lista
        while (aux -> sig != NULL) aux = aux -> sig;
        aux -> sig = nuevoReal;
    }
}

void agregarCaracter(Caracter ** Lista, char valor){
    // Para crear el Nuevo Nodo e insertar sus valores
    Caracter * nuevoCaracter = NULL;
    nuevoCaracter = (Caracter *) malloc (sizeof (Caracter));// Para reservar memoria suficiente
    nuevoCaracter -> caracter = valor;
    nuevoCaracter -> sig = NULL;
    
    // Insertar el Nodo creado a la lista de forma ordenada (Orden de aparicion)
    Caracter * aux = * Lista;
    if (aux == NULL){
        // Solamente para agregar el PRIMER ELEMENTO a la lista
        * Lista = nuevoCaracter;
    } else {
        // Para agregar el RESTO DE ELEMENTOS a la lista
        while (aux -> sig != NULL) aux = aux -> sig;
        aux -> sig = nuevoCaracter;
    }
}

int sumarDecimales (Entero *Lista){
    Entero *aux = Lista;
    int acumulador = 0;

    while (aux != NULL){
        acumulador += aux -> valor;
        aux = aux -> sig;
    }

return acumulador;
}



void imprimirReporte (FILE* archInforme,ConContador * listaIdentificadores, ConValor * listaLiteralesCadena, ConTipo * listaReservadas, Entero * listaDecimales, Entero * listaOctales, Entero * listaHexadecimales, Real * listaReales, Caracter * listaCaracteres, ConContador * listaOperadoresPuntuacion, ConTipo * listaComentarios, ConValor * listaNoReconocidos){
    printf (" ---------------------------------------------------------------------------------------\n");
    printf (" ===================================  R E P O R T E  ===================================\n");
    printf (" ---------------------------------------------------------------------------------------\n");

    if (listaIdentificadores != NULL){
        printf (" -> Identificadores hallados: \n\n");
        fprintf(archInforme, " -> Identificadores hallados: \n\n");
        char* vezOVeces;
        while(listaIdentificadores != NULL){
            vezOVeces = (listaIdentificadores -> contador == 1) ? "vez" : "veces";
            printf ("\t- %s: Aparece %d %s\n", listaIdentificadores -> elemento, listaIdentificadores -> contador, vezOVeces);
            fprintf (archInforme,"\t- %s: Aparece %d %s\n", listaIdentificadores -> elemento, listaIdentificadores -> contador, vezOVeces);
            listaIdentificadores = listaIdentificadores -> sig;
        }
        printf ("\n------------------------------------------------------------------------");
        fprintf (archInforme,"\n------------------------------------------------------------------------");
    } 
    if (listaLiteralesCadena != NULL){
        printf ("\n -> Literales cadenas hallados: \n\n");  
        fprintf(archInforme, "\n -> Literales cadenas hallados: \n\n");
        while(listaLiteralesCadena != NULL){
            printf ("\t- %s: Tiene longitud %d\n", listaLiteralesCadena -> elemento, listaLiteralesCadena -> valor);
            fprintf(archInforme,"\t- %s: Tiene longitud %d\n", listaLiteralesCadena -> elemento, listaLiteralesCadena -> valor);
            listaLiteralesCadena = listaLiteralesCadena -> sig;
        }
        printf ("\n------------------------------------------------------------------------");
        fprintf (archInforme,"\n------------------------------------------------------------------------");
    }
    if (listaReservadas != NULL){
        printf ("\n -> Palabras Reservadas halladas: \n\n");
        fprintf(archInforme, "\n -> Palabras Reservadas halladas: \n\n");
        while(listaReservadas != NULL){
            printf ("\t- %s: Palabra reservada de tipo %s\n", listaReservadas -> elemento, listaReservadas -> tipo);
            fprintf (archInforme,"\t- %s: Palabra reservada de tipo %s\n", listaReservadas -> elemento, listaReservadas -> tipo);
            listaReservadas = listaReservadas -> sig;
        }
        printf ("\n------------------------------------------------------------------------");
        fprintf (archInforme,"\n------------------------------------------------------------------------");
    }
    if (listaOctales != NULL){
        printf ("\n -> Constantes enteras octal halladas:\n\n");
        fprintf(archInforme,"\n -> Constantes enteras octal halladas:\n\n");
        while(listaOctales != NULL){
            if (listaOctales -> valor != 0) {
                printf ("\t- 0"); 
                fprintf(archInforme, "\t- 0"); 
            }
            if (listaOctales -> valor == 0) {
                printf ("\t- "); 
                fprintf(archInforme, "\t- ");
            }
            
            printf ("%o --> Constante de valor decimal: %d\n", listaOctales -> valor, listaOctales -> valor);
            fprintf (archInforme,"%o --> Constante de valor decimal: %d\n", listaOctales -> valor, listaOctales -> valor);
            listaOctales = listaOctales -> sig;
        }
        
        printf ("\n------------------------------------------------------------------------");
        fprintf (archInforme,"\n------------------------------------------------------------------------");
    }
    if (listaDecimales != NULL){
        printf ("\n -> Constantes enteras decimal halladas:\n\n");
        fprintf(archInforme, "\n -> Constantes enteras decimal halladas:\n\n");
        int contadorDecimales = sumarDecimales (listaDecimales);
        while(listaDecimales != NULL){
            printf ("\t- Constante decimal de valor: %d\n", listaDecimales -> valor);
            fprintf (archInforme,"\t- Constante decimal de valor: %d\n", listaDecimales -> valor);
            listaDecimales = listaDecimales -> sig;
        }
        printf("\n\tTotal sumado: %d\n", contadorDecimales);
        fprintf(archInforme, "\n\tTotal sumado: %d\n", contadorDecimales);

        printf ("\n------------------------------------------------------------------------");
        fprintf (archInforme,"\n------------------------------------------------------------------------");
    }
    if (listaHexadecimales != NULL){
        printf ("\n -> Constantes enteras hexadecimal halladas:\n\n");
        fprintf (archInforme,"\n -> Constantes enteras hexadecimal halladas:\n\n");
        while(listaHexadecimales != NULL){
            printf ("\t- 0x%x --> Constante de valor decimal: %d\n", listaHexadecimales -> valor, listaHexadecimales -> valor);
            fprintf (archInforme,"\t- 0x%x --> Constante de valor decimal: %d\n", listaHexadecimales -> valor, listaHexadecimales -> valor);
            listaHexadecimales = listaHexadecimales -> sig;
        }
        
        printf ("\n------------------------------------------------------------------------");
        fprintf (archInforme,"\n------------------------------------------------------------------------");
    }
    if (listaReales != NULL){
        printf("\n -> Constantes real halladas:\n\n");
        fprintf(archInforme,"\n -> Constantes real halladas:\n\n");
        while(listaReales != NULL){
            double parteEntera;
            // modf: Separa parte entera y la parte decimal de un numero tipo "double"
            printf ("\t- %f\t Parte entera: %d\t Parte decimal: %f\n", listaReales -> valor, (int) parteEntera, modf(listaReales -> valor, &parteEntera));
            fprintf (archInforme, "\t- %f\t Parte entera: %d\t Parte decimal: %f\n", listaReales -> valor, (int) parteEntera, modf(listaReales -> valor, &parteEntera));
            
            listaReales = listaReales -> sig;
        }
        
        printf ("\n------------------------------------------------------------------------");
        fprintf (archInforme,"\n------------------------------------------------------------------------");
    }
    if (listaCaracteres != NULL){
        printf ("\n -> Constantes caracter halladas:\n\n");
        fprintf(archInforme,"\n -> Constantes caracter halladas:\n\n");
        int contador = 0;
        
        while(listaCaracteres != NULL){
            contador++;
            printf ("\t- %d) '%c'\n", contador, listaCaracteres -> caracter);
            fprintf (archInforme, "\t- %d) '%c'\n", contador , listaCaracteres -> caracter);
            listaCaracteres = listaCaracteres -> sig;
        }

        printf ("\n------------------------------------------------------------------------");
        fprintf (archInforme,"\n------------------------------------------------------------------------");
    
    }
    if (listaOperadoresPuntuacion != NULL){
        printf ("\n -> Operadores/caracteres de puntuacion hallados: \n\n");
        fprintf(archInforme,"\n -> Operadores/caracteres de puntuacion hallados: \n\n");
        char* vezOVeces;
        while(listaOperadoresPuntuacion != NULL){
            vezOVeces = (listaOperadoresPuntuacion -> contador == 1) ? "vez" : "veces";
            printf ("\t- %s Aparece %d %s\n", listaOperadoresPuntuacion -> elemento, listaOperadoresPuntuacion -> contador, vezOVeces);
            fprintf (archInforme,"\t- %s Aparece %d %s\n", listaOperadoresPuntuacion -> elemento, listaOperadoresPuntuacion -> contador, vezOVeces);
            listaOperadoresPuntuacion = listaOperadoresPuntuacion -> sig;
        }

        printf ("\n------------------------------------------------------------------------");
        fprintf (archInforme,"\n------------------------------------------------------------------------");
    }
    if (listaComentarios != NULL){
        printf ("\n -> Comentarios hallados: \n\n");
        fprintf(archInforme,"\n -> Comentarios hallados: \n\n");
        while(listaComentarios != NULL){
            printf ("\n- Comentario de %s:\n%s\n\n", listaComentarios -> tipo, listaComentarios -> elemento);
            fprintf(archInforme,"\n- Comentario de %s:\n%s\n\n", listaComentarios -> tipo, listaComentarios -> elemento);
            listaComentarios = listaComentarios -> sig;
            
        }
        printf ("------------------------------------------------------------------------");
        fprintf (archInforme,"\n------------------------------------------------------------------------");
    }
    if (listaNoReconocidos != NULL){
        printf ("\n -> Caracteres no reconocidos hallados: \n\n");
        fprintf (archInforme,"\n -> Caracteres no reconocidos hallados: \n\n");
        while(listaNoReconocidos != NULL){
            printf ("\t- %s ubicado en la linea %d\n", listaNoReconocidos -> elemento, listaNoReconocidos -> valor);
            fprintf (archInforme, "\t- %s Ubicado en la linea %d\n", listaNoReconocidos -> elemento, listaNoReconocidos -> valor);

            listaNoReconocidos = listaNoReconocidos -> sig;
        }
    }
}
