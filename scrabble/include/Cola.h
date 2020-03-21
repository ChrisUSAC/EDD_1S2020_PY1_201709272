#ifndef COLA_H
#define COLA_H
#include "NodoCola.h" // importacion del nodo de tipo cola

using namespace std;

class Cola
{
    public:
        Cola(); //metodo constructor
        virtual ~Cola(); //metodo destructor
        void enqueue(int punteo, char letra);//metodo para encolar
        void dequeue(); // metodo para desencolar
        bool estaVacia(); //metodo que informa si la cola esta vacia
        void imprimir(); // metodo para imprimir en consola

    protected:

    private:
        NodoCola* primero; // puntero que hace referencia al primero de la cola
        NodoCola* ultimo; // puntero que hace referencia al ultimo de la cola
        int tamano; // tamano de la cola dinamica
};
#endif // COLA_H
