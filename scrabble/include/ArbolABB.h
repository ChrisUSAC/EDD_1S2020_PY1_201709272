#ifndef ARBOLABB_H
#define ARBOLABB_H
#include "nodoABB.h"
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
using namespace std;


class ArbolABB
{
    public:

        ArbolABB(); // metodo constructor
        bool empty_arbol(); // indica si el arbol esta vacio
        void graph();  // grafica el arbol
        void add(nodoABB *nuevo); //metodo para agregar un jugador al arbol

        nodoABB* search_playlist(string nombre); // metodo para buscar en el arbol

        void inorder();  // recorrido inorden del arbol
        void preorder();  // recorrido preorder del arbol
        void postorder();  // recorrido postorder del arbol

    protected:

    private:

        void recursive_add(nodoABB *actual, nodoABB *temp); //metodo recursivo de agregar

        void recursive_inorder(nodoABB *actual); // metodo recursivo de recorrido inorden
        void recursive_preorder(nodoABB *actual); // metodo recursivo de recorrido preorder
        void recursive_postorder(nodoABB *actual); // metodo recursivo de recorrido postorder

        nodoABB* recursive_seachPlaylist(nodoABB* actual, string nombre); // metodo recursivo de buscar
        bool orden_alfabetico(string dato_root, string dato_nodo); // indica si el dato es insertado hacia derecha o hacia izquierda
        nodoABB *root; // puntero a la raiz del arbol


        void graph_arbol(string &arbolGraph, nodoABB *actual);
};

#endif // ARBOLABB_H
