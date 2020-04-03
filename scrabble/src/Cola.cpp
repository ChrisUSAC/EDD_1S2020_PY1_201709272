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


void Cola::graficar()
{
    if(this->primero!=0)
    {
       escribir();
    }
    else
    {
    cout<<"Error cola vacia no se puede graficar :( "<<endl;
    }

}

void Cola::escribir()
{
    ofstream archivo;

    archivo.open("ColaFichasJuego.dot",ios::out); // abriendo o creando el archivo

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

            NodoCola* aux = this->primero;

            int id=0;
            while(aux != 0 )
            {
                string identificadorr = std::to_string(id);
                archivo<<identificadorr+"[label = " + "\"" + aux->letra +" puntos: "+ to_string(aux->punteo)+ "\"" + " width=2.0 ];" + " \n";
                aux = aux->siguiente;
                id++;
            }

            int id2=0;
            NodoCola* aux2 = this->primero;
            while(aux2->siguiente != 0 )
            {
                string identificadorr = std::to_string(id2);
                string identificadorr2 = std::to_string(id2+1);
                archivo<<identificadorr+" -> "+ identificadorr2 +" \n";
                aux2 = aux2->siguiente;
                id2++;
            }

            archivo<<"}";

    }
    archivo.close();//se cierra el archivo
    system("dot -Tpng ColaFichasJuego.dot -o ColaFichasJuego.png"); //Create
             system("ColaFichasJuego.png"); //Open

}

