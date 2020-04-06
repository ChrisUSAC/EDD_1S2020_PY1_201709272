#include "ArbolABB.h"

//------------------------------------------------------------------------------------------------------------------------------------
//metodo constructor
ArbolABB::ArbolABB()
{
    this->root = 0;
}
//------------------------------------------------------------------------------------------------------------------------------------
void ArbolABB::add(nodoABB *nuevo)
{
    if(empty_arbol())
    {
     root = nuevo;

    }else
    {
        recursive_add(root, nuevo);
    }
}
//------------------------------------------------------------------------------------------------------------------------------------
void ArbolABB::recursive_add(nodoABB *raiz_actual, nodoABB *nuevo)
{
    if(raiz_actual->nombreJugador == nuevo->nombreJugador)
    {
        cout << "--------------------------------------" << endl;
        cout << "----- Nombre existente -----" << endl;
        cout << "--------------------------------------" << endl;

    }else if(orden_alfabetico(raiz_actual->nombreJugador, nuevo->nombreJugador)== true)
    {
        //INSERTAR IZQUIERDA
        if(raiz_actual->izquierda != 0)
        {
            recursive_add(raiz_actual->izquierda, nuevo);

        }else
        {
            raiz_actual->izquierda = nuevo;
        }


    }else if(orden_alfabetico(raiz_actual->nombreJugador, nuevo->nombreJugador)== false)
    {
        //INSERTAR DERECHA
        if(raiz_actual->nombreJugador == nuevo->nombreJugador)
        {
            cout << "--------------------------------------" << endl;
            cout << "----- nombre existente -----" << endl;
            cout << "--------------------------------------" << endl;

        }else if(raiz_actual->derecha != 0)
        {
            recursive_add(raiz_actual->derecha, nuevo);

        }else
        {
            raiz_actual->derecha = nuevo;
        }
    }
}

//------------------------------------------------------------------------------------------------------------------------------------
bool ArbolABB::empty_arbol()
{
    return this->root == 0;
}
//------------------------------------------------------------------------------------------------------------------------------------
bool ArbolABB::orden_alfabetico(string dato_root, string dato_nodo)
{
    const char *dato_raiz = dato_root.c_str();
    const char *dato_nuevo_nodo = dato_nodo.c_str();

    if(strcmp(dato_raiz, dato_nuevo_nodo) > 0)
    {
        //dato_nuevo_nodo = a, dato_raiz = b
        //INSERTAR EN LA IZQUIERDA
        return true;
    }
     //INSERTAR EN LA DERECHA
    return false;
}
//------------------------------------------------------------------------------------------------------------------------------------
//Search  in ArbolABB
nodoABB* ArbolABB::search_playlist(string nombre)
{
    return recursive_seachPlaylist(root, nombre);

}
//------------------------------------------------------------------------------------------------------------------------------------
nodoABB* ArbolABB::recursive_seachPlaylist(nodoABB* actual, string nombre)
{
    nodoABB *aux = 0;
    if(actual!= 0)
    {
         if(actual->nombreJugador== nombre) //Raiz
        {
            return actual;
        }
        if(actual->izquierda != 0)//Izquierda
        {
            aux = recursive_seachPlaylist(actual->izquierda, nombre);
        }

        if(actual->derecha != 0 && aux == 0)// Derecha
        {
           aux = recursive_seachPlaylist(actual->derecha, nombre);
        }
    }
    //cout<<"el usuario aun no existe"<<endl;
    return aux;
}
//------------------------------------------------------------------------------------------------------------------------------------
void ArbolABB::graph()
{
    if(!empty_arbol())
    {
        ofstream archivo;
        archivo.open("ArbolABB.dot",ios::out);//Create file
        if(!archivo.good()) //Verificar si existe un error al abrir
        {
            cout << "----------------------------------------------" << endl;
            cout << "------- ERROR FILE: Can't generate file ------" << endl;
            cout << "----------------------------------------------" << endl;

        }else
        {
            archivo << "digraph ArbolBB{ " << endl;

            archivo << "\n";
            archivo << "rankdir=TB;" << endl;

            archivo << "\n";
            archivo << "node [shape = record];" << endl;

            /*---------- ID NODE ----------*/
            string arbolGraph = "";
            graph_arbol(arbolGraph,root);

            archivo << arbolGraph;

             archivo << "\n";
             archivo << "}" << endl;
             archivo.close();

             system("dot -Tpng ArbolABB.dot -o ArbolABB.png"); //Create image
             system("ArbolABB.png"); //Open image
        }
    }
}
//------------------------------------------------------------------------------------------------------------------------------------
void ArbolABB::graph_arbol(string &arbolGraph, nodoABB *actual)
{
    if(actual!= 0)
    {

        /*Asignacion de ID*/
        if(actual->izquierda != 0 && actual->derecha != 0) // tiene Hijo izquierdo y Derecho.
        {
            arbolGraph = arbolGraph+"N_"+actual->nombreJugador+"[label =\"<HI>|"+ actual->nombreJugador + "|<HD>\"]; \n";

        }else if(actual->izquierda != 0) // Solo tiene hijo IZQUIERDO
        {
            arbolGraph = arbolGraph+"N_"+actual->nombreJugador+"[label =\"<HI>|"+ actual->nombreJugador + "\"]; \n";

        }else if(actual->derecha != 0)//Solo tiene hijo DERECHO
        {
            arbolGraph = arbolGraph+"N_"+actual->nombreJugador+"[label =\""+ actual->nombreJugador + "|<HD>\"]; \n";
        }else
        {
            arbolGraph = arbolGraph+"N_"+actual->nombreJugador+"[label =\""+ actual->nombreJugador + "\"]; \n";
        }

        graph_arbol(arbolGraph, actual->izquierda); //hijo izquiedo del nodo

        if(actual->izquierda != 0)//ENLAZAR HIJO IZQUIERDO
        {
            arbolGraph = arbolGraph + "N_" + actual->nombreJugador + ":HI -> N_" +actual->izquierda->nombreJugador + "\n";
        }

        graph_arbol(arbolGraph, actual->derecha); //hijo derecho del nodo

        if(actual->derecha != 0) // ENZLAZAR HIJO DERECHO
        {
        arbolGraph = arbolGraph + "N_" + actual->nombreJugador + ":HD -> N_" + actual->derecha->nombreJugador + "\n";
        }
    }
}
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
void ArbolABB::inorder()
{
    if(!empty_arbol())
    {
        recursive_inorder(root);
    }
}
//------------------------------------------------------------------------------------------------------------------------------------
void ArbolABB::recursive_inorder(nodoABB *actual)
{
    if(!empty_arbol())
    {
        //IZQUIERDA
        if(actual->izquierda != 0)
        {
            recursive_inorder(actual->izquierda);
        }

        //RAIZ
        cout << " [ " << actual->nombreJugador <<" ]->" ;

        //DERECHA
        if(actual->derecha != 0)
        {
            recursive_inorder(actual->derecha);
        }
    }
}
//------------------------------------------------------------------------------------------------------------------------------------
void ArbolABB::preorder()
{
    if(!empty_arbol())
    {
        recursive_preorder(root);
    }
}
//------------------------------------------------------------------------------------------------------------------------------------
void ArbolABB::recursive_preorder(nodoABB *actual)
{
    if(!empty_arbol())
    {
        //RAIZ
        cout << " [ " << actual->nombreJugador <<" ]->" ;

        //IZQUIERDA

        if(actual->izquierda != 0)
        {
            recursive_preorder(actual->izquierda);
        }



        //DERECHA
        if(actual->derecha != 0)
        {
            recursive_preorder(actual->derecha);
        }
    }
}
//------------------------------------------------------------------------------------------------------------------------------------
void ArbolABB::postorder()
{
    if(!empty_arbol())
    {
        recursive_postorder(root);
    }
}
//------------------------------------------------------------------------------------------------------------------------------------
void ArbolABB::recursive_postorder(nodoABB *actual)
{
    if(!empty_arbol())
    {


        //IZQUIERDA

        if(actual->izquierda != 0)
        {
            recursive_postorder(actual->izquierda);
        }


        //DERECHA
        if(actual->derecha != 0)
        {
            recursive_postorder(actual->derecha);
        }
        //RAIZ
        cout << " [ " << actual->nombreJugador <<" ]->" ;
    }
}
