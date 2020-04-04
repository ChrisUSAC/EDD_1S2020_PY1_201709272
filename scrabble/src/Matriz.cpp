#include "Matriz.h"

//------------------------------------------------------------------------------------------------------
//metodo constructor
Matriz::Matriz()
{
    //se pone el puntero raiz sobre este nodo
    this->raiz=new NodoMatriz("0","0","raiz");
    this->idMatriz = "Raiz";
}
//------------------------------------------------------------------------------------------------------
//metodo destructor
Matriz::~Matriz()
{
    //dtor
}
//------------------------------------------------------------------------------------------------------
//metodo que busca fila, de no existir se retorna un puntero null
NodoMatriz* Matriz::buscarFila(string fila)
{
    //referencia al inicio del cubo
    NodoMatriz* temp = this->raiz;
    //ciclo que recorre las filas
    while(temp!=0)
    {
        //evaluar si ya existe
        const char *a =temp->fila.c_str();
        const char *b =fila.c_str();
        //comparamos con el metodo y si son iguales retorna
        if(strcmp(a,b) == 0)
        {
            return temp; // se retorna el puntero posicionado en esa fila
        }
        //se hace el corrimiento hacia abajo
        temp = temp->abajo;

    }

    //si no encuentra el mes retorna un nulo
    return temp;
}
//------------------------------------------------------------------------------------------------------
//metodo que busca columna, de no existir retorna un null
NodoMatriz* Matriz::buscarCol(string col)
{
    //referencia al inicio del cubo
    NodoMatriz* temp = this->raiz;
    //ciclo que recorre las columnas
    while(temp!=0)
    {
        //castear de string a entero
        int a = atoi(temp->col.c_str());
        int b = atoi(col.c_str());
        //evaluar si son iguales
        if(a==b)
        {
            return temp;
        }
        temp = temp->sig;
    }
    //si no encuentra columna retorna un nulo
    return temp;

}
//------------------------------------------------------------------------------------------------------
//insercion general
void Matriz::insertarElemento(string fila,string col,int punteo, char letra,string dobleotriple)
{
    //se crea primero el nodo a insertar
    NodoMatriz* nuevo = new NodoMatriz(fila,col,punteo,letra,dobleotriple);

    //creacion de punteros para guardar mes(columna) y year(fila) si existen
    NodoMatriz* nodoColumna = buscarCol(col);
    NodoMatriz* nodoFila = buscarFila(fila);

    //caso 1, (columna) y  (fila) no existe
    if(nodoColumna==0 && nodoFila==0)
    {
        //crear columna
        nodoColumna = crear_columna(col);
        //crear fila
        nodoFila = crear_fila(fila);
        //insertar ordenado columna
        nuevo = insertar_ordenado_columna(nuevo,nodoFila);
        //insertar ordenado fila
        nuevo = insertar_ordenado_fila(nuevo,nodoColumna);
        return;
    }
    // caso 2, (columna) no existe pero  (fila) si existe
    else if(nodoColumna==0 && nodoFila!=0)
    {
        //crear columna
        nodoColumna = crear_columna(col);
        //insertar ordenado columna
        nuevo = insertar_ordenado_columna(nuevo,nodoFila);
        //insertar ordenado fila
        nuevo = insertar_ordenado_fila(nuevo,nodoColumna);
    }
    //caso 3, (columna) si existe pero (fila) no existe
    else if(nodoColumna!=0 && nodoFila==0)
    {
        //crear fila
        nodoFila = crear_fila(fila);
        //insertar ordenado columna
        nuevo = insertar_ordenado_columna(nuevo,nodoFila);
        //insertar ordenado fila
        nuevo = insertar_ordenado_fila(nuevo,nodoColumna);
    }
    // caso 4, (columna) y (fila) si existe
    else if(nodoColumna!=0 && nodoFila!=0)
    {

        //de lo contrario quiere decir que las cabeceras existen
        //insertar ordenado columna
        nuevo = insertar_ordenado_columna(nuevo,nodoFila);
        //insertar ordenado fila
        nuevo = insertar_ordenado_fila(nuevo,nodoColumna);



    }
}
//------------------------------------------------------------------------------------------------------
NodoMatriz* Matriz::insertar_ordenado_columna(NodoMatriz* nuevo, NodoMatriz* cabeza_col)
{

    NodoMatriz* temp = cabeza_col;
    //utilizado para ver si el elemento nuevo se coloca antes es decir si bandera es true
    bool bandera = false;

    while(true)
    {
        //evaluar si la posicion en col es la misma
        //castear de  string a entero
        int a = atoi(temp->col.c_str());
        int b = atoi(nuevo->col.c_str());
        //si son iguales hacer una sobre escritura
        if(a == b)
        {
            //si la posicion es ltea misma sobre escribe
            return temp;
        }
        else if(a > b)
        {
            //es decir se va a insertar antes
            bandera = true;
            break; // romper el ciclo infinito while
        }
        //si el siguiente no es nulo
        if(temp->sig != 0)
        {
            temp = temp->sig;
        }
        else
        {
            //tengo que insertar despues del temp el nuevo, bandera sigue en falso
            break;
        }
    }
    //evaluar si bandera es verdadero
    if(bandera)
    {
        //insercion antes de temporal es decir entre dos nodos
        nuevo->sig = temp;
        temp->ant->sig = nuevo;
        nuevo->ant = temp->ant;
        temp->ant = nuevo;
    }
    else
    {
        //insercion al final
        temp->sig = nuevo;
        nuevo->ant = temp;
    }

    //se retorna el nuevo insertado
    return nuevo;
}
//------------------------------------------------------------------------------------------------------
NodoMatriz* Matriz::insertar_ordenado_fila(NodoMatriz* nuevo, NodoMatriz* cabeza_fila)
{
    NodoMatriz* temp = cabeza_fila;
    bool bandera = false;

    while(true)
    {
        //evaluar si ya existe fila
        int a = atoi(temp->fila.c_str());
        int b = atoi(nuevo->fila.c_str());
        //si son iguales hacer una sobre escritura
        if(a==b)
        {
            //si mes es el mismo sobre escribe
            return temp;
        }
        else if(a>b)
        {
            bandera =true;
            break;
        }
        //si el siguiente no es nulo
        if(temp->abajo != 0)
        {
            temp = temp->abajo;
        }

        else
        {
            //tengo que insertar al final ya
            break;
        }
    }
    //evaluar si bandera es verdadero
    if(bandera)
    {
        //insercion antes de temporal es decir entre dos nodos
        nuevo->abajo = temp;
        temp->arriba->abajo = nuevo;
        nuevo->arriba = temp->arriba;
        temp->arriba = nuevo;
    }
    else
    {
        //insercion al final
        temp->abajo = nuevo;
        nuevo->arriba = temp;
    }

    //se retorna el nuevo insertado
    return nuevo;

}
//------------------------------------------------------------------------------------------------------
NodoMatriz* Matriz::crear_columna(string col)
{
    //puntero que apunta a la cabeza
    NodoMatriz* cabeza_columna = this->raiz;

    NodoMatriz* n = new NodoMatriz(col,"0","cabecera columna");
    //crear cabezera para columna
    NodoMatriz* columna = this->insertar_ordenado_columna(n,cabeza_columna);
    return columna;

}
//------------------------------------------------------------------------------------------------------
NodoMatriz* Matriz::crear_fila(string fil)
{
    //puntero que apunta a la cabeza
    NodoMatriz* cabeza_fila = this->raiz;

    NodoMatriz* n = new NodoMatriz("0",fil,"cabecera fila");
    //crear cabecera para fila
    NodoMatriz* fila = this->insertar_ordenado_fila(n,cabeza_fila);
    return fila;
}
//------------------------------------------------------------------------------------------------------

void Matriz::mostrarI() {

	if (this->raiz != 0) {
		NodoMatriz* columna = this->raiz;
		while (columna != 0) {
			cout << "columna-> "<< columna->col << " , "<< "columna->fila " << columna->fila  << endl;
			NodoMatriz* dato = columna->abajo;
			while (dato != 0) {
				cout << "dato->an "<< dato->col << " , "<< "dato->mes " << dato->fila  << endl;

				dato = dato->abajo;
			}
			columna = columna->sig;
		}
	}
}


//--------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//metodo que realiza el reporte graphiz
void Matriz::graficar()
{
    if(this->raiz->sig!=0)
    {
       escribir();
    }
    else
    {
    cout<<"Error matriz vacia no se puede graficar"<<endl;
    }

}
//-----------------------------------------------------------------------------------------------------------------
void Matriz::escribir()
{
    ofstream archivo;

    archivo.open("ReporteMatriz.dot",ios::out); // abriendo o creando el archivo

    //validar que se creara correctamente
    if(archivo.fail())
    {
            cout<<"no se pudo abrir el archivo"<<endl;

    }
    else
    {
        //escribir sintaxis dot para la imagen
            archivo<<"digraph M{ \n";
            archivo<<"node[ shape = box] \n";
            archivo<<this->idMatriz+"[label = "+"\""+this->idMatriz+"\""+", width=1.5, group = 1];"+" \n"+" \n";
//--------------------------------------------------------------------------------------------------------------------------------
            NodoMatriz* aux = this->raiz->abajo;

            //asignacion de id a las filas recorrido de raiz hacia abajo hasta ser nulo
            int id=0;
            while(aux != 0 )
            {
                string identificadorr = std::to_string(id);

                archivo<<"f"+identificadorr+"[label = " + "\"" + aux->fila + "\"" + " width=2.0 , group = 1 ];" + " \n";


                //archivo<<"f"+identificadorr+"[label = " + "\"" + aux->fila + "\"" + " width=2.0 , group = 1 ];" + " \n";
                aux->mensaje = "f"+identificadorr; // se le mete al nodo en el atributo mensaje el identificador unico
                cout<<"aux->mensaje+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++: "<<aux->mensaje<<endl;
                aux = aux->abajo;
                id++;
            }
            //id--; // se reduce 1 por que no entra cuando es null al while
            //asignacion de enlaces para las filas
            int id2=0;
            NodoMatriz* aux2 = this->raiz->abajo;
            while(aux2->abajo != 0 )
            {
                string identificadorr = std::to_string(id2);
                string identificadorr2 = std::to_string(id2+1);
                archivo<<"f"+identificadorr+" -> "+"f"+identificadorr2 +"[dir = back];"+" \n";
                archivo<<"f"+identificadorr+" -> "+"f"+identificadorr2 +" \n";
                aux2 = aux2->abajo;
                id2++;

            }
//--------------------------------------------------------------------------------------------------------------------------------
            NodoMatriz* aux3 = this->raiz->sig;

            //asignacion de id a las columnas recorrido de raiz hacia derecha hasta ser nulo
            int id3=0;
            //id que indica los grupos, empieza en dos por que son grupos de columnas
            int idaux = 2;
            while(aux3 != 0 )
            {
                string identificadorr = std::to_string(id3);
                string idauxx = std::to_string(idaux);
                archivo<<"c"+identificadorr+"[label = " + "\"" + aux3->col + "\"" + " width=2.0 , group = "+idauxx+" ];" + " \n";
                aux3->mensaje = "c"+identificadorr; // se le mete al nodo en el atributo mensaje el identificador unico
                cout<<"aux3->mensaje+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++: "<<aux3->mensaje<<endl;

                aux3 = aux3->sig;
                id3++;
                idaux++;
            }
            //id3--; // se reduce 1 por que no entra cuando es null al while
            //asignacion de enlaces para las columnas
            int id4=0;
            NodoMatriz* aux4 = this->raiz->sig;
            while(aux4->sig != 0 )
            {
                string identificadorr = std::to_string(id4);
                string identificadorr2 = std::to_string(id4+1);
                archivo<<"c"+identificadorr+" -> "+"c"+identificadorr2 +"[dir = back];"+" \n";
                archivo<<"c"+identificadorr+" -> "+"c"+identificadorr2 +" \n";
                aux4 = aux4->sig;
                id4++;

            }
//--------------------------------------------------------------------------------------------------------------------------------

            archivo<<" Raiz -> f0 [dir = back];  \n";
            archivo<<" Raiz -> f0 ; \n";
            archivo<<" Raiz -> c0 [dir = back]; \n";
            archivo<<" Raiz -> c0 ; \n";

            cout<<"contador de filas id:";
            cout<<id<<endl;
            cout<<"contador de columnas id3:";
            cout<<id3<<endl;
            id--; // para que tenga el indice de la fila
//--------------------------------------------------------------------------------------------------------------------------------

            archivo<<"{rank = same;Raiz;";
            int id5 = 0;
            id3--; // para que tenga el indice de la columna
            string concatenarRank;
            while(id5<=id3)
            {
                string cc = std::to_string(id5);
                concatenarRank += "c"+cc+";";
                id5++;
            }

            archivo<<concatenarRank+"} \n";
//--------------------------------------------------------------------------------------------------------------------------------

        //id3 tiene las columnas existentes

        int correColumna =0;
        int idNodo = 0;
        int grupC = 2;

		NodoMatriz* columna = this->raiz->sig;
		cout<<"entrara al primer while"<<endl;
		cout<<"eentres de entrar al while correColumna: "<<correColumna<<endl;
		cout<<"id3 antes del while "<<id3<<endl;

		while (correColumna <= id3) {
			cout << "columna->col "<< columna->col << " , "<< "columna->mfila " << columna->fila << endl;

			NodoMatriz* dato = columna->abajo;
			while (dato != 0) {
			    string iden = std::to_string(idNodo);
                string corrc = std::to_string(grupC); //grupo al que pertenece
                string corrc2 = std::to_string(correColumna); //columna a la que pertenece

                if(dato->dobleotriple=="doble")
                {

                    archivo<<"n"+iden+"[label = "+ "\"" +dato->letra+ "\"" +" width = 1.5,fillcolor = lightskyblue,style = filled,group ="+corrc+"]; \n"; // esta linea esta bien
                }
                else if(dato->dobleotriple=="triple")
                {

                    archivo<<"n"+iden+"[label = "+ "\"" +dato->letra+ "\"" +" width = 1.5,fillcolor = red,style = filled, group ="+corrc+"]; \n"; // esta linea esta bien
                }
                else
                {
                    archivo<<"n"+iden+"[label = "+ "\"" +dato->letra+ "\"" +" width = 1.5, group ="+corrc+"]; \n"; // esta linea esta bien
                }


                archivo<<"n"+iden+"[label = "+ "\"" +dato->letra+ "\"" +" width = 1.5, group ="+corrc+"]; \n"; // esta linea esta bien
                dato->mensaje = "n"+iden; // se le mete al nodo en el atributo mensaje el identificador unico
                cout<<"dato->mensaje: //////////////////////////////////////////////////////////////////////////////////////// "<<dato->mensaje<<endl;
                //archivo<<"c"+corrc2+" -> n"+iden+" [dir = back];  \n";
                //archivo<<"c"+corrc2+" -> n"+iden+"\n";


				cout << "dato->col "<< dato->col << " , "<< "dato->fila " << dato->fila << " , " << "dato->letra "<< dato->letra << endl;

				dato = dato->abajo;
				idNodo++;


			}
			correColumna++; // me dice que columna es es decir el indice de (c#indice)
			grupC++;
			columna = columna->sig;
		}

//--------------------------------------------------------------------------------------------------------------------------------
//enlaces verticales

        //aqui se deben de enlazar los nodos
        //id3 tiene las columnas existentes

        //idNodo ya tiene el numero de nodos que se metio a la matriz es decir los elementos

        cout<<"entrara al ultimo while"<<endl;
		NodoMatriz* columnaa = this->raiz->sig;
		while (columnaa != 0)
        {
			NodoMatriz* datooo = columnaa;
			while (datooo != 0)
            {
                if(datooo->abajo!=0)
                {
                cout<<"datooo->mensaje: "<<datooo->mensaje<<endl;
                cout<<"datooo->abajo->mensaje: "<<datooo->abajo->mensaje<<endl;
                archivo<<datooo->mensaje+" -> "+datooo->abajo->mensaje+" [dir = back];  \n";
                archivo<<datooo->mensaje+" -> "+datooo->abajo->mensaje+"\n";

                datooo = datooo->abajo;
                }else
                {
                break;
                }

			}
            columnaa = columnaa->sig;
		}

//--------------------------------------------------------------------------------------------------------------------------------
//enlaces horizontales
        cout<<"entrara al ultimo while"<<endl;
		NodoMatriz* columnaaa = this->raiz->abajo;
		while (columnaaa != 0)
        {

			NodoMatriz* datooo = columnaaa;
			while (datooo != 0)
            {
                if(datooo->sig!=0)
                {
                cout<<"datooo->mensaje: "<<datooo->mensaje<<endl;
                cout<<"datooo->abajo->mensaje: "<<datooo->sig->mensaje<<endl;
                archivo<<datooo->mensaje+" -> "+datooo->sig->mensaje+" [dir = back];  \n";
                archivo<<datooo->mensaje+" -> "+datooo->sig->mensaje+"\n";

                datooo = datooo->sig;
                }else
                {
                break;
                }
			}
            columnaaa = columnaaa->abajo;
		}
//--------------------------------------------------------------------------------------------------------------------------------

        cout<<"entrara al ultimo while"<<endl;
		NodoMatriz* columnaaz = this->raiz->abajo;
		while (columnaaz != 0)
        {
            string rank="{rank = same;";
			NodoMatriz* datooo = columnaaz;
			while (datooo != 0)
            {
                cout<<"datooo->mensaje: "<<datooo->mensaje<<endl;
                rank += datooo->mensaje+";";
                datooo = datooo->sig;

			}
			rank+="} \n";
			archivo<<rank;
            columnaaz = columnaaz->abajo;
		}
//--------------------------------------------------------------------------------------------------------------------------------





            archivo<<"}";

    }
    archivo.close();//se cierra el archivo
    system("dot -Tpng ReporteMatriz.dot -o ReporteMatriz.png"); //Create
             system("ReporteMatriz.png"); //Open
}
//----------------------------------------------------------------------------------------------------------------

