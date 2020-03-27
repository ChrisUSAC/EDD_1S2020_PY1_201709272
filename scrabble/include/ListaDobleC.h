#ifndef LISTADOBLEC_H
#define LISTADOBLEC_H

#include"NodoListaDobleC.h"//se incluye el nodo
#include <iostream>
using namespace std;

class ListaDobleC
{
    public:
        //metodo constructor de la lista
        ListaDobleC();
        //metodo destructor de la lista
        virtual ~ListaDobleC();

        bool estaVacia(); // metodo que informa si la lista esta vacia
        void imprimir(); // metodo que imprime la lista en consola
        void insertarFinal(string nombre);// metodo que inserta los nuevos nodos al final de la lista

        NodoListaDobleC* primero; // puntero que indica cual es el primer nodo de la lista
        NodoListaDobleC* ultimo; // puntero que indica cual es el ultimo nodo en la lista
        int tam; // entero que indica cuantos nodos tiene la lista, es decir el tamano.

    protected:

    private:
};

#endif // LISTADOBLEC_H
