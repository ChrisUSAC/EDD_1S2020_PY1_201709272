#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H
#include <string>
#include "NodoLista.h"
#include "Lista.h"

using namespace std;


class NodoMatriz
{
    public:

        //punteros del nodo
        NodoMatriz* sig;
        NodoMatriz* ant;
        NodoMatriz* arriba;
        NodoMatriz* abajo;


        //almacenadores de informacion
        string mensaje; // almacena lo que imprimen las cabeceras
        string fila; //almacena la fila del tablero
        string col; // almacena la columna del tablero
        int punteo; // almacena el puntaje de la letra
        char letra; // almacena la letra a buscar

        //metodo constructor de nodo tipo cabecera
        NodoMatriz(string col,string fila,string mensaje);
        //constructor para los datos almacenado en la matriz
        NodoMatriz(string fila,string col,int punteo,char letra);
        //metodo destructor
        virtual ~NodoMatriz();

    protected:

    private:
};

#endif // NODOMATRIZ_H
