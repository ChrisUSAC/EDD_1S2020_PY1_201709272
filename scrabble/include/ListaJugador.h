#ifndef LISTAJUGADOR_H
#define LISTAJUGADOR_H

#include "Jugador.h"
#include "NodoListaJugador.h"
#include "NodoLista.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
class ListaJugador
{
    public:
        ListaJugador();
        virtual ~ListaJugador();
        NodoListaJugador* primero; // puntero que hace referencia al inicio de la lista
        NodoListaJugador* ultimo; // puntero que hace referencia al final de la lista
        int tam; // indica cuantos elementos hay es decir nodos

        bool estaVacia(); // dice si la lista esta vacia
        void insertarJugador(Jugador* jugador,string nombreJugador);


        void imprimir();//imprime en consola la lista
        void graficar(); // metodo que realiza el graphiz
        void escribir(); // escribe la sintaxis dot para el reporte

        NodoListaJugador* existeJugador(string nombrej); // retorna el nodo donde exista el jugador

    protected:

    private:
};

#endif // LISTAJUGADOR_H
