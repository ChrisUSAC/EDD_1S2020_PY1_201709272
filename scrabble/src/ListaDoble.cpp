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
//metodo que inserta al inicio
void ListaDoble::insertarInicio(char letra, int punteo)
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
        n->sig = primero;
        primero->ant = n;
        primero = n;
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
//-----------------------------------------------------------------------------------------------------------------
//retorna el puntero primero de la Lista
NodoListaDoble* ListaDoble::getPrimero()
{
    return this->primero;
}
//-----------------------------------------------------------------------------------------------------------------
void ListaDoble::resetear()
{
    this->primero = 0;
    this->ultimo = 0;
    this->tam  = 0;

}
//-----------------------------------------------------------------------------------------------------------------
NodoListaDoble* ListaDoble::remove_at(int index)
{
    //se crea un nodo auxiliar para no perder la referencia
    NodoListaDoble* aux = this->primero;

    //si la lista esta vacia, solo se le informa a usuario
    if(estaVacia())
    {
    cout<<"Lista Vacia"<<endl;
    return aux;
    }
    else
    {
        //se verifica que el indice exista en la lista
        if(index >=0 && index<tam)
        {

            //si solo existe un nodo en la lista
            if(index == 0 && tam == 1)
            {
                //los punteros de la lista se apuntan a 0
                this->primero=0;
                this->ultimo=0;
                //se reduce el tamano de la lista
                tam--;
                return aux;
            }
            //si existe mas de un nodo en la lista
            else
            {
                //si se elimina al primero
                if(index == 0)
                {
                    this->primero = primero->sig;
                    this->primero->ant = 0;
                    cout<<"Elimino Primero"<<endl;
                    tam--;
                    return aux;
                }
                //si se elimina al ultimo
                else if(index == tam-1)
                {
                    aux = this->ultimo;
                    this->ultimo= ultimo->ant;
                    this->ultimo->sig=0;
                    cout<<"Elimino ultimo"<<endl;
                    tam--;
                    return aux;
                }
                //si se elimina uno del centro
                else if(index != 0 && index != tam-1)
                {
                    cout<<"uno del centro"<<endl;

                    //se crea contador para validar la posicion a eliminar
                    int contador = 0;
                    //se recorre la lista en busca del index
                    while(aux!=0)
                    {
                    // si el contador y el index coinciden se elimina el nodo
                        if(contador == index)
                        {
                        //el aux ya tiene la referencia del nodo a eliminar
                        aux->ant->sig = aux->sig;
                        aux->sig->ant = aux->ant;
                        //se apuntan a nulos los punteros del eliminado
                        aux->ant = 0;
                        aux->sig =0;
                        //se descuenta el nodo de la lista
                        tam--;
                        return aux;
                        //se corta el ciclo para mejor manejo de  memoria
                        break;
                        }
                    //se recorre el puntero
                    aux =aux->sig;
                    contador++;
                    }

                }
            }

        }
        else
        {
        cout<<"El indice indicado no existe"<<endl;
        return aux=0;
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
string ListaDoble::evaluarPalabra()
{
    string palabraFormada="";

    NodoListaDoble* aux = this->primero;//nodo auxiliar

    if(estaVacia())
    {
        cout<<"Lista Vacia"<<endl;
    }
    else
    {
        while(aux != 0 )
        {

            palabraFormada += aux->letra;
            aux = aux->sig;
        }
    }
    return palabraFormada;

}
