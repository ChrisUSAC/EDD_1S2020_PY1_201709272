#include "Cola.h"
#include <iostream>

using namespace std;

Cola::Cola()
{
    this->primero=0;
    this->ultimo=0;
    this->tamano=0;
}

Cola::~Cola()
{
    //dtor
}
//-----------------------------------------------------------------------------------------------------------------
//metodo booleano
bool Cola::estaVacia()
{
    //si no tiene elementos la lista el tamano es 0
    return this->tamano==0;
}
//-----------------------------------------------------------------------------------------------------------------
//metodo encolar
void Cola::enqueue(int punteo, char letra)
{
    //creacion del nodo contenedor de cola
    NodoCola* n = new NodoCola(punteo,letra);

    //verificar si esta vacia la cola
    if(estaVacia())
    {
        this->primero = n;
        this->ultimo = n;
    }
    else
    {
        this->ultimo->siguiente = n;
        this->ultimo = n;
    }
    //aumento del atributo tamano
    this->tamano++;
}

//-----------------------------------------------------------------------------------------------------------------
//metodo desencolar
void Cola::dequeue()
{
    //verificar que exista un elemento a eliminar
    if(estaVacia())
    {
    cout<<"cola vaciaaaa"<<endl;
    }
    else
    {
        //se corre el puntero primero a siguiente
        this->primero =this->primero->siguiente;
        this->tamano--;
    }


}

//-----------------------------------------------------------------------------------------------------------------
//metodo que imprime en consola
void Cola::imprimir()
{
    if(estaVacia())
    {
        cout<<"cola vacia"<<endl;
    }
    else{

        NodoCola* aux = this->primero;
        while(aux!=0)
        {
            cout<<"Letra: "<<aux->letra<<" Punteo: "<<aux->punteo<<endl;
            aux = aux->siguiente;
        }

    }

}

