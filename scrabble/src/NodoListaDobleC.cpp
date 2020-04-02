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

NodoListaDobleC::NodoListaDobleC(string palabraDiccionario, int id)
{
    this->sig = 0;
    this->ant = 0;
    this->palabraDiccionario=palabraDiccionario;
    this->id = id;
}
