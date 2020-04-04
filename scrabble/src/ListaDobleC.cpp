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
            cout<<indice<<" "<<aux->nombre<<endl;
            aux =aux->sig;
            indice++;

        }

    }
}

//------------------------------------------------------------------------------------------------------
string ListaDobleC::enviarJugador(int numero)
{
    string nombreJugador; // variable que retorna el metodo
    if(estaVacia())
    {
        cout<<"lista vacia"<<endl;
    }
    else
    {
        //nodo temporal para no mover la referecia al primero
        NodoListaDobleC* aux = this->primero;

        if(numero >= 0 && numero < this->tam)
        {

            //entero que servira para iterar el while
            int indice =0;

            //ciclo de impresion en consola
            while(indice < this->tam)
            {
                if(indice == numero)
                {
                    cout<<"se envia a "<<aux->nombre<<endl;
                    return aux->nombre;
                }

                aux =aux->sig;
                indice++;

            }

        }
        else
        {
            cout<<"opcion invalida, se le asignara jugador 0: "<<aux->nombre<<endl;
            return aux->nombre;
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
//------------------------------------------------------------------------------------------------------
void ListaDobleC::graficar()
{
    if(this->primero!=0)
    {
       escribir();
    }
    else
    {
    cout<<"Error lista vacia no se puede graficar"<<endl;
    }

}
//------------------------------------------------------------------------------------------------------
void ListaDobleC::escribir()
{
    ofstream archivo;

    archivo.open("ReporteJugadores.dot",ios::out); // abriendo o creando el archivo

    //validar que se creara correctamente
    if(archivo.fail())
    {
            cout<<"no se pudo abrir el archivo"<<endl;

    }
    else
    {

        //escribir sintaxis dot para la imagen
            archivo<<"digraph G{ \n";
            archivo<<"rankdir=LR \n";
            archivo<<"node[ shape = box] \n";

            NodoListaDobleC* aux = this->primero;

            int indice=0;
            int id=0;
            while(indice < this->tam)
            {
                string identificadorr = std::to_string(id);
                archivo<<identificadorr+"[label = " + "\"" + aux->nombre + "\"" + " width=2.0 ];" + " \n";
                aux = aux->sig;
                indice +=1;
                id++;
            }

            int condicionSalida = id;
            int id2=0;
            NodoListaDobleC* aux2 = this->primero;
            while(id2 < condicionSalida-1 )
            {
                string identificadorr = std::to_string(id2);
                string identificadorr2 = std::to_string(id2+1);
                archivo<<identificadorr+" -> "+ identificadorr2 +"[dir = back];"+" \n";
                archivo<<identificadorr+" -> "+ identificadorr2 +" \n";
                aux2 = aux2->sig;
                id2++;
            }
            string t = std::to_string(condicionSalida-1);
            archivo<<"0 -> "+t+"[dir = back];"+" \n";
            archivo<<"0 -> "+t+" \n";

            archivo<<"}";

    }
    archivo.close();//se cierra el archivo
    system("dot -Tpng ReporteJugadores.dot -o ReporteJugadores.png"); //Create
             system("ReporteJugadores.png"); //Open
}

