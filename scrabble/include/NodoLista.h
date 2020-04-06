#ifndef NODOLISTA_H
#define NODOLISTA_H

#include<iostream>
using namespace std;

class NodoLista
{
    public:
        //metodo constructor
        NodoLista(string nombreJugador, int puntaje);
        //metodo destructor
        virtual ~NodoLista();
        NodoLista* siguiente; //puntero al siguiente nodo

        //getters
        string getnombreJugador();
        int getpuntajeJugador();

        //setters
        void setnombreJugador(string nombreJugador);
        void setpuntajeJugador(int puntaje);

    protected:

    private:
        //atributos
        string nombreJugador; // guarda nombre del jugador
        int puntaje; // puntaje de la partida del jugador
};

#endif // NODOLISTA_H
