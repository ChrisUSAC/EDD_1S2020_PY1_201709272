#include "ListaDoble.h"

using namespace std;
//------------------------------------------------------------------------------------------------------
//metodo constructor
ListaDoble::ListaDoble()
{
    this->primero = 0;
    this->ultimo = 0;
    this->tam  = 0;
}

//------------------------------------------------------------------------------------------------------
//metodo Destructor
ListaDoble::~ListaDoble()
{
    //dtor
}

//------------------------------------------------------------------------------------------------------
//metodo booleano que inidica si la lista esta vacia
bool ListaDoble::estaVacia()
{
    return this->primero == 0;
}

//------------------------------------------------------------------------------------------------------
//metodo que imprime la lista del primero al ultimo
void ListaDoble::imprimir()
{
    NodoListaDoble* aux = this->primero;//nodo auxiliar que

    if(estaVacia())
    {
        cout<<"Lista Vacia"<<endl;
    }
    else
    {
        int i=1;
        while(aux != 0 )
        {
            cout<<i<<"."<<aux->letra<<endl;
            i++;
            aux = aux->sig;
        }
    }
}
//------------------------------------------------------------------------------------------------------
//metodo que inserta al final de la lista
void ListaDoble::insertarFinal(char letra, int punteo)
{

    //se instancia el nodo
    NodoListaDoble *n = new NodoListaDoble(letra,punteo);

    //se evalua si la lista aun no tiene nodos
    if(estaVacia())
    {
    /*de ser el primer nodo a ingresar se apuntan primero y ultimo a
    dicho nodo */
    primero = n;
    ultimo = n;
    tam++; // aumenta el tamano de la lista
    }
    //si ya existe algun nodo
    else
    {
        n->ant = ultimo; // puntero siguiente del nodo se apunta a primero
        ultimo->sig = n;
        ultimo = n; // se pone la referencia del primero en el nuevo nodo
        tam++; // aumenta el tamano de la lista
    }
}

//-----------------------------------------------------------------------------------------------------------------
//metodo que realiza el reporte graphiz
void ListaDoble::graficar()
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
//-----------------------------------------------------------------------------------------------------------------
void ListaDoble::escribir()
{
    ofstream archivo;

    archivo.open("ReporteFichasJugador.dot",ios::out); // abriendo o creando el archivo

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

            NodoListaDoble* aux = this->primero;

            int id=0;
            while(aux != 0 )
            {
                string identificadorr = std::to_string(id);
                archivo<<identificadorr+"[label = " + "\"" + aux->letra + "\"" + " width=2.0 ];" + " \n";
                aux = aux->sig;
                id++;
            }

            int id2=0;
            NodoListaDoble* aux2 = this->primero;
            while(aux2->sig != 0 )
            {
                string identificadorr = std::to_string(id2);
                string identificadorr2 = std::to_string(id2+1);
                archivo<<identificadorr+" -> "+ identificadorr2 +"[dir = back];"+" \n";
                archivo<<identificadorr+" -> "+ identificadorr2 +" \n";
                aux2 = aux2->sig;
                id2++;
            }

            archivo<<"}";

    }
    archivo.close();//se cierra el archivo
    system("dot -Tpng ReporteFichasJugador.dot -o ReporteFichasJugador.png"); //Create
             system("ReporteFichasJugador.png"); //Open
}

//-----------------------------------------------------------------------------------------------------------------
//retorna el tamano de la Lista
int ListaDoble::getTam()
{
    return this->tam;
}
