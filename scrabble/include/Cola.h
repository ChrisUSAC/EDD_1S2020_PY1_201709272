#ifndef COLA_H
#define COLA_H
#include "NodoCola.h" // importacion del nodo de tipo cola
#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Cola
{
    public:
        Cola(); //metodo constructor
        virtual ~Cola(); //metodo destructor
        void enqueue(int punteo, char letra);//metodo para encolar, inserta al final
        void dequeue(); // metodo para desencolar
        bool estaVacia(); //metodo que informa si la cola esta vacia
        void imprimir(); // metodo para imprimir en consola

        void graficar(); // metodo que realiza el graphiz
        void escribir(); // escribe la sintaxis dot para el reporte

        NodoCola* primero; // puntero que hace referencia al primero de la cola
        NodoCola* ultimo; // puntero que hace referencia al ultimo de la cola
        int tamano; // tamano de la cola dinamica


        void insertarInicio(int punteo,char letra); // funciona como insertar al final para la cola inicial de fichas
        int numeroRandom(); //genera un numero random delimitado por el tamano de lista
        void insertarAleatorio(int punteo,char letra); // metodo que inserta en posicion random de la lista

        void llenadoInicial(); // metodo que llena la cola aleatoriamente con las fichas
    protected:

    private:

};
#endif // COLA_H
