#include "NodoListaJugador.h"
//-----------------------------------------------------------------------------------------------
//metodo constructor
NodoListaJugador::NodoListaJugador(Jugador* jugador,string nombreJugador)
{
    this->jugador = jugador;
    this->nombreJugador = nombreJugador;
    this->siguiente = 0;

}

NodoListaJugador::~NodoListaJugador()
{

}
