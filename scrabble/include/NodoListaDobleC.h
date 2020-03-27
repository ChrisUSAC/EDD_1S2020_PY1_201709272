#ifndef NODOLISTADOBLEC_H
#define NODOLISTADOBLEC_H
#include <iostream>
using namespace std;

class NodoListaDobleC
{
    public:
        //metodo constructor
        NodoListaDobleC(string nombre);

        //metodo destructor
        virtual ~NodoListaDobleC();
        NodoListaDobleC *sig; //puntero que hace referencia al siguiente nodo
        NodoListaDobleC *ant; // puntero que hace referencia al anterior nodo
        string nombre;


    protected:

    private:
};

#endif // NODOLISTADOBLEC_H
