/* LISTAS SE */

#include <iostream>
#include <conio.h>
using namespace std;




struct NodoListaSE
{
    int info;             // Datos de el nodo
    NodoListaSE   *sgte;  // Puntero al siguiente nodo

};


/*Función ObtenerSiguiente:
Precondiciones: Recibe un puntero a cualquier nodo de una lista.
Postcondiciones: Si el puntero parámetro es distinto de NULL, y
su puntero siguiente es distinto de null, entonces devuelve el
puntero al siguiente nodo. Caso contrario devuelve NULL */
NodoListaSE *ObtenerSiguiente(NodoListaSE  *n)
{
    if (n)
        return n->sgte;
    else
        return NULL;
}


/*Procedimiento ObtenerSiguiente:
Precondiciones: Recibe una lista (puntero al primer nodo)
Postcondiciones: Muestra los datos de todos los nodos por pantalla */
void MostrarLista(NodoListaSE *milista)
{
    while (milista)
    {
        cout << milista->info << "   " << milista <<endl;
        milista = ObtenerSiguiente(milista);
    }
}


/*Función InsertarSiguiente :
Precondiciones: Recibe un puntero a nodo.
Postcondiciones: Si el puntero parámetro es distinto de NULL,inserta
un nuevo nodo con la información x a continuación del nodo apuntado
por el puntero parámetro, encandenado al nuevo nodo lo que estaba a continuación
del nodo parámetro. Si el puntero parámetro es null crea un nuevo nodo
y le cambia el valor al puntero parámetro (NULL) por la dirección del nuevo y primer
nodo.*/
void InsertarSiguiente (NodoListaSE  *&n, int x)
{
    NodoListaSE *nuevo= new NodoListaSE();
    nuevo->info=x;
    if (n)
    {
        nuevo->sgte= n->sgte;
        n->sgte = nuevo;
    }
    else
    {
        nuevo->sgte= n;
        n= nuevo;
    }
    return;
}

/*Procedimiento BorrarSiguiente:
Precondiciones: Recibe un puntero a cualquier nodo de una lista.
Postcondiciones: Elimina el nodo siguiente al nodo pasado por parámetro,
encadenando a este último todo lo que estaba a continuación
del nodo eliminado.*/
void BorrarSiguiente(NodoListaSE  *n)
{
    NodoListaSE  *aborrar = n->sgte;
    NodoListaSE  *sgteaborrar;
    if (aborrar)
        sgteaborrar= aborrar->sgte;
    else
        sgteaborrar = NULL;
    n->sgte = sgteaborrar;
    delete aborrar;
    return;
}

/*Función ObtenerUltimo:
Precondiciones: Recibe un puntero a cualquier nodo de una lista.
Postcondiciones: devuelve un puntero al último nodo. Si la lista
es vacía devuelve null */
NodoListaSE *ObtenerUltimo(NodoListaSE * p)
{
    if (p)
    {
        while (p->sgte)
        {
            p = p->sgte;
        }
    }
    return p;

}


/*Función BuscarNodo:
Precondiciones: Recibe un puntero al inicio de la lista y la info buscada
Postcondiciones: devuelve un puntero al nodo que contenga la info buscada,
si no lo encuentra devuelve null */
NodoListaSE* BuscarNodo(NodoListaSE * p, int infobuscada)
{
    while (p && (p->info != infobuscada))
    {
        p = ObtenerSiguiente(p);
    }
    return p;
}

/*Función BuscarNodoAnterior:
Precondiciones: Recibe un puntero al inicio de la lista y un puntero a un nodo.
Postcondiciones: devuelve un puntero al nodo anterior al apuntado por el puntero
parámetro. Si el puntero parámetro apunta al primer nodo o si la list está vacía,
devuelve null*/
NodoListaSE* BuscarNodoAnterior(NodoListaSE * raiz, NodoListaSE * anterior_a)
{
    NodoListaSE *p =NULL;
    if (raiz != anterior_a)
    {
        p = raiz;
        while (p && (p->sgte!= anterior_a) )
        {
            p = p->sgte;
        }
        return p;
    }
    else
        return NULL;
}

/*
procedimiento BorrarNodo:
Precondiciones: recibe por parámetro lista y el puntero al nodo a borrar.
Postcondiciones: Borra el nodo y encadena los restantes adecuadamente.
*/
void borrarNodo(NodoListaSE *& raiz, NodoListaSE * aborrar)
{
    if (raiz && aborrar)
    {
        if (aborrar==raiz)
        {
            raiz = raiz->sgte;
            delete aborrar;
        }
        else
        {
            NodoListaSE *x = BuscarNodoAnterior(raiz,aborrar);
            BorrarSiguiente(x);
        }
    }
    return;
}


/*procedimiento InsertarAlFinal:
Precondiciones: Recibe el puntero inicial de la lista y la info a agregar
Postcondiciones: crea un nuevo nodo con la info pasada por x y lo inserta al final
de la lista.*/

void InsertarAlFinal(NodoListaSE *&lista, int x)
{
    NodoListaSE *aux;
    aux=ObtenerUltimo(lista);
    if (aux)
        InsertarSiguiente(aux,x);
    else
        InsertarSiguiente(lista,x);
    return;
}


/*procedimiento borrarLista:
Precondiciones: Recibe el puntero inicial de la lista
Postcondiciones: elimina todos los nodos y deja la lista vacía (en null)*/
void borrarLista(NodoListaSE *&lista)
{
    NodoListaSE *anterior;
    NodoListaSE *paux;
    while (lista!=NULL)
    {
        anterior=NULL;
        paux= lista;
        while (paux && paux->sgte)
        {
            anterior = paux;
            paux= paux->sgte;
        }
        if (paux)
        {
            delete paux;
            if (anterior!=NULL)
                anterior->sgte=NULL;
            else
                lista =NULL;
        }
    }
    return;
}
int main()
{

    NodoListaSE *milista = NULL;
    NodoListaSE *aux;
    NodoListaSE *x;
    InsertarAlFinal(milista,5);
    InsertarAlFinal(milista,8);
    InsertarAlFinal(milista,3);
    InsertarAlFinal(milista,12);
    MostrarLista(milista);
    //Probamos obtener el ultimo
    x = ObtenerUltimo(milista);
    cout << "Usando ObtenerUltimo encontramos que el ultimo dato es: " << x->info << endl;
    //Probamos buscar el elemento d
    cout << "Buscamos un 3 con BuscarNodo."<< endl;
    x = BuscarNodo(milista,3);
    if (x)
        cout << "El dato buscado es: " << x->info << endl;
    else
        cout << "El elemento no existe" << endl;
    //Probamos buscar un elemento que no existe
    cout << "Probamos buscar un elemento que no existe, se busca un 27." << endl;
    x = BuscarNodo(milista,27);
    if (x)
        cout << "El dato buscado es: " << x->info << endl;
    else
        cout << "El elemento no existe" << endl;
    cout  << "Agregamos un 9 al lado del 8" << endl;
    x = BuscarNodo(milista,8);
    if (x)
        InsertarSiguiente(x,9);
    MostrarLista(milista);
    cout << "Probamos buscar nodo anterior al que contiene 3, para luego, desde este nodo encontrado, borrar el que contiene 3" << endl;
    x = BuscarNodoAnterior(milista,BuscarNodo(milista,3));
    BorrarSiguiente(x);
    MostrarLista(milista);
    //borra toda la lista para liberar memoria
    cout << "Borramos toda la lista con borrarLista, este procedimiento se encarga de hacer delete de todos los nodos." << endl;
    borrarLista(milista);
    char c = getch();
    return 0;
}
