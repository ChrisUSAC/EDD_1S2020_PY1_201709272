#ifndef NODOLISTADOBLE_H
#define NODOLISTADOBLE_H
#include <iostream>
using namespace std;

class NodoListaDoble
{
    public:
        //metodo contructor del Nodo, recibe de parametro de los datos a guardar
        NodoListaDoble(char letra, int punteo);
        // metodo destructor
        virtual ~NodoListaDoble();


        char letra; // almacena la letra
        int punteo; // almacena el punteo de la letra
        //punteros del nodo siguiente y anterior
        NodoListaDoble *sig; //puntero siguiente del nodo
        NodoListaDoble *ant;  // puntero anterior del nodo

    protected:

    private:
};

#endif // NODOLISTADOBLE_H
