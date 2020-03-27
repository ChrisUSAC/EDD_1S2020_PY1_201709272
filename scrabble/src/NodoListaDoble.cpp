#include "NodoListaDoble.h"

NodoListaDoble::NodoListaDoble(char letra, int punteo)
{
    sig = 0;
    ant = 0;

    this->letra = letra;
    this->punteo = punteo;
}

NodoListaDoble::~NodoListaDoble()
{

}

