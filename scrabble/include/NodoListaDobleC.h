#ifndef NODOLISTADOBLEC_H
#define NODOLISTADOBLEC_H
#include <iostream>
using namespace std;

class NodoListaDobleC
{
    public:
        //metodo constructor
        NodoListaDobleC(string nombre);
        NodoListaDobleC(string palabraDiccionario,int id);
        NodoListaDobleC(string dobleotriple,int x,int y);

        //metodo destructor
        virtual ~NodoListaDobleC();
        NodoListaDobleC *sig; //puntero que hace referencia al siguiente nodo
        NodoListaDobleC *ant; // puntero que hace referencia al anterior nodo

        string nombre;

        string palabraDiccionario; // guarda las palabras del diccionario
        int id; // se le asigna un id a la palabra

        int x; // casillas especiales
        int y; //


    protected:

    private:
};

#endif // NODOLISTADOBLEC_H
