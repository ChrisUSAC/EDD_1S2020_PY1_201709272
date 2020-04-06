#include "ListaJugador.h"
//metodo constructor
//---------------------------------------------------------------------------
ListaJugador::ListaJugador()
{
    this->primero = 0;
    this->ultimo = 0;
    this->tam = 0;
}
//---------------------------------------------------------------------------
ListaJugador::~ListaJugador()
{
    //dtor
}
//---------------------------------------------------------------------------
bool ListaJugador::estaVacia()
{
 return this->primero==0;
}
//---------------------------------------------------------------------------
void ListaJugador::insertarJugador(Jugador* jugador, string nombreJugador)
{
    //creacion del nodo a guardar
    NodoListaJugador* n = new NodoListaJugador(jugador,nombreJugador);

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
//---------------------------------------------------------------------------
void ListaJugador::imprimir()
{

    NodoListaJugador* auxil=this->primero;

    if(estaVacia())
    {
        cout<<"Lista Vacia"<<endl;
    }
    else
    {
        while(true)
        {
            cout<<"**Nombre: ** "<< auxil->nombreJugador<<endl;
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
//---------------------------------------------------------------------------
NodoListaJugador* ListaJugador::existeJugador(string nombrej)
{
    NodoListaJugador* existe = this->primero;

    if(estaVacia())
    {
        cout<<"Lista Vacia"<<endl;
        return existe = 0;
    }
    else
    {
        int i =0;
        while(i < this->tam)
        {
            //evaluar si ya existe
            const char *a =existe->nombreJugador.c_str();
            const char *b =nombrej.c_str();
            //comparamos con el metodo y si son iguales retorna
            if(strcmp(a,b) == 0)
            {
            return existe; // se retorna el puntero posicionado
            }

            i++;
            existe = existe->siguiente;
        }
    return existe;

    }
}

//---------------------------------------------------------------------------
void ListaJugador::graficar()
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
//---------------------------------------------------------------------------
void ListaJugador::escribir()
{
    ofstream archivo;

    archivo.open("MejoresPunteos.dot",ios::out); // abriendo o creando el archivo

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

            NodoListaJugador* aux = this->primero;

            int id=0;
            while(aux != 0 )
            {


                string identificadorr = std::to_string(id);
                archivo<<identificadorr+"[label = " + "\"" + aux->nombreJugador +" Puntaje: "+ to_string(aux->jugador->puntajesIndividual->primero->getpuntajeJugador())+ "\"" + " width=2.0 ];" + " \n";
                aux = aux->siguiente;
                id++;
            }

            int id2=0;
            NodoListaJugador* aux2 = this->primero;
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
    system("dot -Tpng MejoresPunteos.dot -o MejoresPunteos.png"); //Create
             system("MejoresPunteos.png"); //Open

}
