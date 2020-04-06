#ifndef LISTASRECORRIDO_H
#define LISTASRECORRIDO_H
#include "NodoListaSRecorrido.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


class ListaSRecorrido
{
    public:
        ListaSRecorrido();
        virtual ~ListaSRecorrido();

        NodoListaSRecorrido* primero; // puntero que hace referencia al inicio de la lista
        NodoListaSRecorrido* ultimo; // puntero que hace referencia al final de la lista
        int tam; //tamano de la listas

        void insertarFinal(string nombre); // metodo que inserta al final
        bool estaVacia(); // metodo que informa si la lista esta vacia
        void imprimir();//imprime en consola la lista
        void graficar(); // metodo que realiza el graphiz
        void escribir(); // escribe la sintaxis dot para el reporte

    protected:

    private:
};

#endif // LISTASRECORRIDO_H
