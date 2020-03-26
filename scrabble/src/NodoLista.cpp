#include "NodoLista.h"

//----------------------------------------------------------------------------------------------------------------------------
//metodo constructor de la clase
NodoLista::NodoLista(string nombreJugador, int puntaje)
{
    this->nombreJugador = nombreJugador;
    this->puntaje = puntaje;
    this->siguiente = 0;//linea
}
//----------------------------------------------------------------------------------------------------------------------------
//metodo destructor
NodoLista::~NodoLista()
{

}
//----------------------------------------------------------------------------------------------------------------------------
//metodos getters
string NodoLista::getnombreJugador()
{
    return this->nombreJugador;
}

int NodoLista::getpuntajeJugador()
{
    return this->puntaje;
}

//----------------------------------------------------------------------------------------------------------------------------
//setters
void NodoLista::setnombreJugador(string nombreJugador)
{
    this->nombreJugador = nombreJugador;
}

void NodoLista::setpuntajeJugador(int puntaje)
{
    this->puntaje = puntaje;
}

//----------------------------------------------------------------------------------------------------------------------------
