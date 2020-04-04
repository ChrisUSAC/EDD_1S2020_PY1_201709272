#include "Cola.h"
#include <iostream>

using namespace std;

Cola::Cola()
{
    this->primero=0;
    this->ultimo=0;
    this->tamano=0;

    llenadoInicial(); // llenado de fichas a la cola aleatorio
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
NodoCola* Cola::dequeue()
{
    NodoCola* desencolar;
    //verificar que exista un elemento a eliminar
    if(estaVacia())
    {
    cout<<"cola vaciaaaa"<<endl;
    }
    else
    {
        //se corre el puntero primero a siguiente
        desencolar = this->primero;
        this->primero =this->primero->siguiente;
        this->tamano--;
    }

    return desencolar;
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
//-----------------------------------------------------------------------------------------------------------------

void Cola::insertarInicio(int punteo, char letra)
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
        n->siguiente = this->primero;
        this->primero = n;
    }
    //aumento del atributo tamano
    this->tamano++;
}
//-----------------------------------------------------------------------------------------------------------------
int Cola::numeroRandom()
{
    int num;
    srand(time(NULL));

    num =rand()%this->tamano;
    //cout<<"numero random: "<<num<<endl;
    return num;

}

//-----------------------------------------------------------------------------------------------------------------
void Cola::insertarAleatorio(int punteo, char letra)
{
    //si la lista esta vacia, solo se le informa a usuario
    if(estaVacia())
    {
    //cout<<"Lista Vacia"<<endl;
    insertarInicio(punteo,letra);
    }
    else
    {
        //llamar a calcular el indice con un numero random
        int index = numeroRandom();

            //si se inserta al inico
            if(index == 0)
            {
                insertarInicio(punteo,letra);
            }
            //si se inserta al final
            else if(index == tamano)
            {
                enqueue(punteo,letra);
            }
            //si se inserta en el centro
            else if(index != 0 && index != tamano)
            {
                //se instancia el nodo
                NodoCola *n = new NodoCola(punteo,letra);
                //cout<<"uno del centro"<<endl;
                //se crea un nodo auxiliar para no perder la referencia
                NodoCola* aux = this->primero;
                //se crea contador para validar la posicion a eliminar
                int contador = 0;
                //se recorre la lista en busca del index
                while(aux!=0)
                {
                    // si el contador y el index coinciden se elimina el nodo
                    if(contador == index-1)
                    {
                        NodoCola* aux2 = aux->siguiente;
                        //el aux ya tiene la referencia del nodo a eliminar
                        aux->siguiente = n;
                        n->siguiente = aux2;
                        tamano++;

                        //se corta el ciclo para mejor manejo de  memoria
                        break;
                    }
                    //se recorre el puntero
                    aux =aux->siguiente;
                    contador++;
                }

            }


    }

}
//-----------------------------------------------------------------------------------------------------------------
void Cola::llenadoInicial()
{
    cout<<"Listado de letras en cola"<<endl;
    //12 a
    insertarAleatorio(1,'a');
    insertarAleatorio(1,'a');
    insertarAleatorio(1,'a');
    insertarAleatorio(1,'a');
    insertarAleatorio(1,'a');
    insertarAleatorio(1,'a');
    insertarAleatorio(1,'a');
    insertarAleatorio(1,'a');
    insertarAleatorio(1,'a');
    insertarAleatorio(1,'a');
    insertarAleatorio(1,'a');
    insertarAleatorio(1,'a');
    //12e
    insertarAleatorio(1,'e');
    insertarAleatorio(1,'e');
    insertarAleatorio(1,'e');
    insertarAleatorio(1,'e');
    insertarAleatorio(1,'e');
    insertarAleatorio(1,'e');
    insertarAleatorio(1,'e');
    insertarAleatorio(1,'e');
    insertarAleatorio(1,'e');
    insertarAleatorio(1,'e');
    insertarAleatorio(1,'e');
    insertarAleatorio(1,'e');

    //9 o
    insertarAleatorio(1,'o');
    insertarAleatorio(1,'o');
    insertarAleatorio(1,'o');
    insertarAleatorio(1,'o');
    insertarAleatorio(1,'o');
    insertarAleatorio(1,'o');
    insertarAleatorio(1,'o');
    insertarAleatorio(1,'o');
    insertarAleatorio(1,'o');
    //6 i
    insertarAleatorio(1,'i');
    insertarAleatorio(1,'i');
    insertarAleatorio(1,'i');
    insertarAleatorio(1,'i');
    insertarAleatorio(1,'i');
    insertarAleatorio(1,'i');
    //6 s
    insertarAleatorio(1,'s');
    insertarAleatorio(1,'s');
    insertarAleatorio(1,'s');
    insertarAleatorio(1,'s');
    insertarAleatorio(1,'s');
    insertarAleatorio(1,'s');
    //5 n
    insertarAleatorio(1,'n');
    insertarAleatorio(1,'n');
    insertarAleatorio(1,'n');
    insertarAleatorio(1,'n');
    insertarAleatorio(1,'n');
    // 4 l
    insertarAleatorio(1,'l');
    insertarAleatorio(1,'l');
    insertarAleatorio(1,'l');
    insertarAleatorio(1,'l');
    // 5 r
    insertarAleatorio(1,'r');
    insertarAleatorio(1,'r');
    insertarAleatorio(1,'r');
    insertarAleatorio(1,'r');
    insertarAleatorio(1,'r');
    // 5 u
    insertarAleatorio(1,'u');
    insertarAleatorio(1,'u');
    insertarAleatorio(1,'u');
    insertarAleatorio(1,'u');
    insertarAleatorio(1,'u');
    // 4 t
    insertarAleatorio(1,'t');
    insertarAleatorio(1,'t');
    insertarAleatorio(1,'t');
    insertarAleatorio(1,'t');
    //-----------------------------------2 puntos
    // 5 d
    insertarAleatorio(2,'d');
    insertarAleatorio(2,'d');
    insertarAleatorio(2,'d');
    insertarAleatorio(2,'d');
    insertarAleatorio(2,'d');
    // 2 g
    insertarAleatorio(2,'g');
    insertarAleatorio(2,'g');

    //-----------------------------------3 puntos
    // 4 c
    insertarAleatorio(3,'c');
    insertarAleatorio(3,'c');
    insertarAleatorio(3,'c');
    insertarAleatorio(3,'c');
    // 2 b
    insertarAleatorio(3,'b');
    insertarAleatorio(3,'b');
    // 2 m
    insertarAleatorio(3,'m');
    insertarAleatorio(3,'m');
    //2 p
    insertarAleatorio(3,'p');
    insertarAleatorio(3,'p');

    //-----------------------------------4 puntos
    //2 h
    insertarAleatorio(4,'h');
    insertarAleatorio(4,'h');
    //1 f
    insertarAleatorio(4,'f');
    //1 v
    insertarAleatorio(4,'v');
    //1 y
    insertarAleatorio(4,'y');
    //-----------------------------------5 puntos
    //1 q
    insertarAleatorio(5,'q');
    //-----------------------------------8 puntos
    //1 j
    insertarAleatorio(8,'j');

    //1 ñ
    insertarAleatorio(8,'ñ');
    //1 x
    insertarAleatorio(8,'x');
    //-----------------------------------10 puntos
    // 1 z
    insertarAleatorio(10,'z');


}


