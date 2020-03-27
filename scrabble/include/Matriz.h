#ifndef MATRIZ_H
#define MATRIZ_H
#include "NodoMatriz.h"
#include "Lista.h"

#include "string"
#include "cstring" //biblioteca para comparar strings
#include <fstream>

using namespace std;

class Matriz
{
    public:
        string idMatriz;
        //metodo constructor
        Matriz();
        //metodo destructor
        virtual ~Matriz();

        //puntero de raiz
        NodoMatriz* raiz;


        //metodos de la matriz
        NodoMatriz* buscarFila(string fila); // metodo que recorre las filas y verifica si  existe
        NodoMatriz* buscarCol(string col);// metodo que recorre las columnas y verifica si existe

        void insertarElemento(string fila,string col,int punteo, char letra); //metodo de insercion de NodoMatriz

        //inserta los year en orden, nuevo es el nodo a insertar, cabeza_col es nodo referencia donde empezar
        NodoMatriz* insertar_ordenado_columna(NodoMatriz* nuevo,NodoMatriz* cabeza_col);
        //inserta los valores de mes en orden, nuevo es el nodo a insertar, cabeza_fila es nodo referencia donde empezar
        NodoMatriz* insertar_ordenado_fila(NodoMatriz* nuevo,NodoMatriz* cabeza_fila);



        //crea columna
        NodoMatriz* crear_columna(string col);
        //crear fila
        NodoMatriz* crear_fila(string fila);



        void mostrarI();//imprime la matriz en consola
        void graficar();//metodo que grafica la matriz graphiz
        void escribir(); // metodo que escribe el archivo dot para graficar la matriz

    protected:

    private:
};

#endif // MATRIZ_H
