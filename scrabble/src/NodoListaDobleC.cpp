#include "NodoListaDobleC.h"

NodoListaDobleC::NodoListaDobleC(string nombre)
{
    this->sig = 0;
    this->ant = 0;
    this->nombre = nombre;
}

NodoListaDobleC::~NodoListaDobleC()
{
    //dtor
}
