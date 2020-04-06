#include "ListaSRecorrido.h"
//---------------------------------------------------------------------------------
//metodo constructor
ListaSRecorrido::ListaSRecorrido()
{
    this->primero=0;
    this->ultimo=0;
    this->tam=0;

}
//---------------------------------------------------------------------------------
ListaSRecorrido::~ListaSRecorrido()
{

}
//---------------------------------------------------------------------------------
void ListaSRecorrido::insertarFinal(string nombre)
{
    //creacion del nodo a guardar
    NodoListaSRecorrido* n = new NodoListaSRecorrido(nombre);

    //evaluar si esta vacia la lista aun
    if(estaVacia())
    {
        //se le iguala el primero y el ultimo
        this->primero = n;
        this->ultimo = n;
        this->tam++;
    }
    else
    {
        this->ultimo->siguiente = n;
        this->ultimo = n;
        this->tam++;
        //cout<<"insercion al final///////////"<<tam-1<<endl;

    }
}
//---------------------------------------------------------------------------------
bool ListaSRecorrido::estaVacia()
{
    //si no contiene elementos retorna un true
    return this->primero==0;
}
//---------------------------------------------------------------------------------
void ListaSRecorrido::imprimir()
{

    NodoListaSRecorrido* auxil=this->primero;

    if(estaVacia())
    {
        cout<<"Lista Vacia"<<endl;
    }
    else
    {
        while(true)
        {
            cout<<"**Nombre: *** "<< auxil->nombre<<endl;
        if(auxil == this->ultimo)
        {
            break;
        }
        else
        {
            auxil = auxil->siguiente;
        }
        }

    }

}
//---------------------------------------------------------------------------------
void ListaSRecorrido::graficar()
{
    if(this->primero!=0)
    {
       escribir();
    }
    else
    {
    cout<<"Error lista vacia no se puede graficar :( "<<endl;
    }

}
//---------------------------------------------------------------------------------
void ListaSRecorrido::escribir()
{
    ofstream archivo;

    archivo.open("Recorridos.dot",ios::out); // abriendo o creando el archivo

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

            NodoListaSRecorrido* aux = this->primero;

            int id=0;
            while(aux != 0 )
            {
                string identificadorr = std::to_string(id);
                archivo<<identificadorr+"[label = " + "\"" + aux->nombre + "\"" + " width=2.0 ];" + " \n";
                aux = aux->siguiente;
                id++;
            }

            int id2=0;
            NodoListaSRecorrido* aux2 = this->primero;
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
    system("dot -Tpng Recorridos.dot -o Recorridos.png"); //Create
             system("Recorridos.png"); //Open

}
//---------------------------------------------------------------------------------
