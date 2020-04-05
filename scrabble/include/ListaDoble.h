#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include "NodoListaDoble.h"//se incluye el nodo

#include <iostream>
#include <fstream>
#include <cstring> //biblioteca para comparar strings

class ListaDoble
{
//------------------------------------------------------------------------------------------------------
    public:

        //metodo contructor de la lista
        ListaDoble();
        // metodo destructor
        virtual ~ListaDoble();

        bool estaVacia(); // metodo que informa si la lista esta vacia
        void imprimir(); // metodo que imprime la lista en consola
        void insertarFinal(char letra, int punteo); // metodo que inserta al final de la lista
        void insertarInicio(char letra, int punteo); // metodo que inserta al final de la lista


        void graficar(); // metodo que realiza el reporte graphiz
        void escribir(); // escribir el archivo de texto

        int getTam(); // retorna el tamano de la lista
        NodoListaDoble* getPrimero();

        void resetear(); // resetea la lista de fichas
        NodoListaDoble* remove_at(int index); //metodo que elimina el nodo de la lista y lo retorna para insertarlo en la matriz

        string evaluarPalabra(); // metodo que devuelve una cadena de las palabras sacadas


    protected:
//------------------------------------------------------------------------------------------------------
    private:
        NodoListaDoble* primero; // puntero que indica cual es el primer nodo de la lista
        NodoListaDoble* ultimo; // puntero que indica cual es el ultimo nodo en la lista
        int tam; // entero que indica cuantos nodos tiene la lista, es decir el tamano.
};

#endif // LISTADOBLE_H
