#include "NodoListaDobleC.h"
//lista de jugadores para iniciar partida
NodoListaDobleC::NodoListaDobleC(string nombre)
{
    this->sig = 0;
    this->ant = 0;
    this->nombre = nombre;
}
//para las coordenadas especiales
NodoListaDobleC::NodoListaDobleC(string dobleotriple,int x,int y)
{
    this->sig = 0;
    this->ant = 0;
    this->nombre = dobleotriple;
    this->x = x;
    this->y = y;

}

NodoListaDobleC::~NodoListaDobleC()
{
    //dtor
}

//para las palabras del diccionario
NodoListaDobleC::NodoListaDobleC(string palabraDiccionario, int id)
{
    this->sig = 0;
    this->ant = 0;
    this->palabraDiccionario=palabraDiccionario;
    this->id = id;
}
