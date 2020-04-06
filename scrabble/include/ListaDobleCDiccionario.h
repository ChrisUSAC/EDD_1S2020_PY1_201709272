#ifndef LISTADOBLECDICCIONARIO_H
#define LISTADOBLECDICCIONARIO_H
#include"NodoListaDobleC.h"//se incluye el nodo
#include <iostream>
#include <fstream>
#include <cstring> //biblioteca para comparar strings
using namespace std;


class ListaDobleCDiccionario
{
    public:
        ListaDobleCDiccionario();
        virtual ~ListaDobleCDiccionario();

        bool estaVacia(); // metodo que informa si la lista esta vacia
        void imprimir(); // metodo que imprime la lista en consola
        void insertarFinal(string palabra);// metodo que inserta los nuevos nodos al final de la lista
        void insertarFinalCoordenadaEspecial(string dobleotriple,int x, int y);// metodo que inserta los nuevos nodos al final de la lista

        NodoListaDobleC* primero; // puntero que indica cual es el primer nodo de la lista
        NodoListaDobleC* ultimo; // puntero que indica cual es el ultimo nodo en la lista
        int tam; // entero que indica cuantos nodos tiene la lista, es decir el tamano.
        int id; // asignacion de id a las palabras

        void graficar(); // metodo que realiza el reporte graphiz
        void escribir(); // escribir el archivo de texto

        bool validarPalabra(string palabraAValidar); // metodo que devuelve true si la palabra existe en el diccionario

        void resetear(); // resetea las palabras del diccionario


    protected:

    private:
};

#endif // LISTADOBLECDICCIONARIO_H
