#include "Jugador.h"
//-----------------------------------------------------------------------------------
Jugador::Jugador()
{
    this->m = new Matriz();
    this->listaFichas= new ListaDoble();
    this->puntajesIndividual = new Lista();
    this->punteoAcumulado = 0;
    this->nombrejugador = "";
}
//-----------------------------------------------------------------------------------
Jugador::~Jugador()
{
    //dtor
}
//-----------------------------------------------------------------------------------
void Jugador::resetearjugador()
{
    this->m = new Matriz();
    this->listaFichas= new ListaDoble();
    this->puntajesIndividual = new Lista();
    this->punteoAcumulado = 0;
    this->nombrejugador = "";
}
