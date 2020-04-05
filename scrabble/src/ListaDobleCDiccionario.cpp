#include "ListaDobleCDiccionario.h"
#include<iostream>
using namespace std;
//------------------------------------------------------------------------------------------------------
//metodo constructor
ListaDobleCDiccionario::ListaDobleCDiccionario()
{
    this->primero = 0;
    this->ultimo = 0;
    this->tam  = 0;
    this->id = 0;

}
//------------------------------------------------------------------------------------------------------
//metodo destructor
ListaDobleCDiccionario::~ListaDobleCDiccionario()
{

}
//------------------------------------------------------------------------------------------------------
//metodo destructor
bool ListaDobleCDiccionario::estaVacia()
{
    return this->primero==0;
}
//------------------------------------------------------------------------------------------------------
//metodo para imprimir en consola la lista circula de inicio a fin
void ListaDobleCDiccionario::imprimir()
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
            cout<<"aux->palabra: "<<aux->palabraDiccionario<<endl;
            aux =aux->sig;
            indice++;

        }

    }
}
//------------------------------------------------------------------------------------------------------
bool ListaDobleCDiccionario::validarPalabra(string palabraAValidar)
{
    bool validacion=false;
    if(estaVacia())
    {
        cout<<"lista vacia"<<endl;
        return validacion;
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

            //evaluar si existe
            const char *a =aux->palabraDiccionario.c_str();
            const char *b =palabraAValidar.c_str();
            //comparamos con el metodo y si son iguales retorna
            if(strcmp(a,b) == 0)
            {
                validacion = true;
                return validacion; // se retorna el puntero posicionado en esa fila
            }

            aux =aux->sig;
            indice++;

        }
        return validacion;

    }
}

//------------------------------------------------------------------------------------------------------
//metodo para insertar al final el nuevo nodo
void ListaDobleCDiccionario::insertarFinal(string palabra)
{
    //se instancia el nodo a insertar
    NodoListaDobleC* n = new NodoListaDobleC(palabra,this->id++);
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
void ListaDobleCDiccionario::graficar()
{
    if(this->primero!=0)
    {
       escribir();
    }
    else
    {
    cout<<"Error lista diccionario no se puede graficar, esta vacia"<<endl;
    }
}

void ListaDobleCDiccionario::escribir()
{
    ofstream archivo;

    archivo.open("ReporteDiccionario.dot",ios::out); // abriendo o creando el archivo

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
                archivo<<identificadorr+"[label = " + "\"" + aux->palabraDiccionario + "\"" + " width=2.0 ];" + " \n";
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
    system("dot -Tpng ReporteDiccionario.dot -o ReporteDiccionario.png"); //Create
             system("ReporteDiccionario.png"); //Open
}
