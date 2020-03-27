#include "ListaDobleC.h"

#include<iostream>
using namespace std;
//------------------------------------------------------------------------------------------------------
//metodo constructor
ListaDobleC::ListaDobleC()
{
    this->primero = 0;
    this->ultimo = 0;
    this->tam  = 0;
}
//------------------------------------------------------------------------------------------------------
//metodo destructor
ListaDobleC::~ListaDobleC()
{
    //dtor
}
//------------------------------------------------------------------------------------------------------
//metodo que informa si la lista esta vacia
bool ListaDobleC::estaVacia()
{
    return this->primero==0;
}
//------------------------------------------------------------------------------------------------------
//metodo para imprimir en consola la lista circula de inicio a fin
void ListaDobleC::imprimir()
{
    if(estaVacia())
    {
        cout<<"lista vacia"<<endl;
    }
    else
    {
        //nodo temporal para no mover la referecia al primero
        NodoListaDobleC* aux = this->primero;
        //entero que servira para iterar el while
        int indice =0;

        //ciclo de impresion en consola
        while(indice < this->tam)
        {
            cout<<"aux->nombre: "<<aux->nombre<<endl;
            aux =aux->sig;
            indice++;

        }

    }
}
//------------------------------------------------------------------------------------------------------
//metodo para insertar al final el nuevo nodo
void ListaDobleC::insertarFinal(string nombre)
{
    //se instancia el nodo a insertar
    NodoListaDobleC* n = new NodoListaDobleC(nombre);
    //es evalua si la lista esta vacia
    if(estaVacia())
    {
        //apuntar primero y ultimo al nuevo nodo
        this->primero = n;
        this->ultimo = n;
        //crear circulo
        this->primero->ant = n;
        this->ultimo->sig = n;
    }
    else
    {
        //si ya existe uno
        this->ultimo->sig = n;
        n->ant = this->ultimo;
        this->ultimo = n;
        this->ultimo->sig = this->primero;
        this->primero->ant = this->ultimo;

    }
    //se aumenta el tamano de la lista
    this->tam++;
}
