#ifndef NODOABB_H
#define NODOABB_H
#include <string.h>
#include <iostream>
using namespace std;

class nodoABB
{
    public:
        //metodo constructor
        nodoABB(string nombreJugador);
        virtual ~nodoABB();

        string nombreJugador; // almacena el nombre del jugador, debe ser unico
        nodoABB *izquierda;
        nodoABB *derecha;

    protected:

    private:
};

#endif // NODOABB_H
