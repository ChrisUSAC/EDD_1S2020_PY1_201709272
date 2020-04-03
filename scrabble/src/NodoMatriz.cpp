#include "NodoMatriz.h"

//metodo destructor
NodoMatriz::~NodoMatriz()
{
    //dtor
}
//------------------------------------------------------------------------------------------------------
//metodo constructor para el nodo de tipo cabezera
NodoMatriz::NodoMatriz(string col,string fila,string mensaje)
{
    //inicializar puntero en nulo
    this->sig = 0;
    this->ant = 0;
    this->arriba = 0;
    this->abajo = 0;

    //nombre a mostrar en el grafico
    this->mensaje = mensaje;
    this->col = col;
    this->fila = fila;
    this->dobleotriple = "f";



}
//------------------------------------------------------------------------------------------------------
//metodo constructor para el nodo que almacena letras del juego en tablero
NodoMatriz::NodoMatriz(string fila,string col,int punteo,char letra,string dobleotriple)
{
    //inicializar puntero en nulo
    this->sig = 0;
    this->ant = 0;
    this->arriba = 0;
    this->abajo = 0;

    //almacenamiento de la informacion
    this->fila = fila;
    this->col = col;
    this->punteo = punteo;
    this->letra = letra;
    this->dobleotriple = dobleotriple;

}
//------------------------------------------------------------------------------------------------------
