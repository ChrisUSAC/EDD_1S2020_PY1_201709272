#ifndef NODOLISTAJUGADOR_H
#define NODOLISTAJUGADOR_H

#include "Jugador.h"
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class NodoListaJugador
{
    public:
        NodoListaJugador(Jugador* jugador,string nombreJugador);
        virtual ~NodoListaJugador();

        NodoListaJugador* siguiente; //puntero al siguiente nodo
        Jugador* jugador; // jugador a almacenar
        string nombreJugador;

    protected:

    private:
};

#endif // NODOLISTAJUGADOR_H
