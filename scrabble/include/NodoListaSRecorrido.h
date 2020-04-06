#ifndef NODOLISTASRECORRIDO_H
#define NODOLISTASRECORRIDO_H


#include<iostream>
using namespace std;

class NodoListaSRecorrido
{
    public:
        NodoListaSRecorrido(string nombre);
        virtual ~NodoListaSRecorrido();

        NodoListaSRecorrido* siguiente; // puntero al siguiente nodo
        string nombre; // nombre que esta en el arbol

    protected:

    private:
};

#endif // NODOLISTASRECORRIDO_H
