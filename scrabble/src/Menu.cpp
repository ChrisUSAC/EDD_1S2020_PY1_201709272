#include "Menu.h"

//estructuras globales
ArbolABB* arbol = new ArbolABB(); // arbol que guarda los usuarios del juego
ListaDobleCDiccionario* diccio = new ListaDobleCDiccionario(); // diccionario de palabras validas del juego
Matriz* matrizJuego = new Matriz(); // matriz que sera el tablero de juego
ListaDobleC* usuarios = new ListaDobleC();// listado de jugadores

Jugador* jugador1 = new Jugador(); // objeto con el que jugara el jugador 1
Jugador* jugador2 = new Jugador(); // objeto con el que jugara el jugador 2

Cola* colaFichas = new Cola(); // listado de fichas del juego

//variables globales para tener a los jugadores


Menu::Menu()
{
    this->archivo = new Archivo();
    this->nuevo = new nodoABB("");
    this->ficha = new NodoCola(1,'a');
    this->fichaRegreso = new NodoListaDoble('f',1);
}

Menu::~Menu()
{
    //dtor
}

//-----------------------------------------------------------------------------------------------------
void Menu::menu_inicial()
{
    bool bandera = true;
    char opcion[40]; // variable que lee la opcion seleccinada por el usuario
    int seleccion =0;

    string nombreArchivo=""; // guarda el nombre del archivo json a cargar en el juego


    system("cls"); //clear console.//

    do
    {

        cout << "--------- SCRABBLE++ ---------" << endl;
        cout<<"1- Cargar Archivo."<<endl;
        cout<<"2- Juego."<<endl;
        cout<<"3- Reportes."<<endl;
        cout<<"4- Exit."<<endl;

        cout<<"Seleccione una Opcion: ";
        cin >> opcion;
        cin.ignore(); // limpia e buffer de entrada
        seleccion = opcion[0];
        switch(seleccion)
        {
        case '1':
            bandera = false;
            system("cls"); //Clear console.//
            //ir al menu a pedir nombre del archivo
            menu_cargaArchivo();
            break;
        case '2':
            bandera = false;
            system("cls"); //Clear console.//
            // ir al menu del juego
            menu_juego();
            break;
        case '3':
            bandera = false;
            system("cls"); //Clear console.//
            cout<<"Opcion 3";
            break;
        case '4':
            bandera = false;
            exit(1);
            break;
        default:
            cout << "---------------------------------------" << endl;
            cout << "------- ERROR:  opcion invalida--------" << endl;
            cout << "---------------------------------------" << endl;
            break;
        }

    }
    while(bandera);
}
//-----------------------------------------------------------------------------------------------------
void Menu::menu_cargaArchivo()
{
    bool bandera = true;
    char opcion[40]; // variable que lee la opcion seleccinada por el usuario
    int seleccion =0;

    string nombreArchivo=""; // guarda el nombre del archivo json a cargar en el juego


    system("cls"); //clear console.//

    do
    {

        cout << "--------- Carga de Archivo ---------" << endl;
        cout<<"1- Ingresar Nombre."<<endl;
        cout<<"2- Regresar."<<endl;


        cout<<"Seleccione una Opcion: ";
        cin >> opcion;
        cin.ignore(); // limpia e buffer de entrada
        seleccion = opcion[0];
        switch(seleccion)
        {
        case '1':
            system("cls"); //Clear console.//
            //ir al menu a pedir nombre del archivo
            cout<<"Nombre del archivo .json: ";
            cin>>nombreArchivo;
            archivo->leer(nombreArchivo,*diccio,*matrizJuego);
            break;
        case '2':
            bandera = false;
            menu_inicial();
            break;
        default:
            cout << "---------------------------------------" << endl;
            cout << "------- ERROR:  opcion invalida--------" << endl;
            cout << "---------------------------------------" << endl;
            break;
        }

    }
    while(bandera);

}
//-----------------------------------------------------------------------------------------------------
void Menu::menu_juego()
{
    bool bandera = true;
    char opcion[40]; // variable que lee la opcion seleccinada por el usuario
    int seleccion =0;

    string jugadorNuevo = ""; // se le ingresa el nombre del jugador nuevo
    string j1 = ""; // sirve para almacenar al jugador 1
    string j2 = ""; // sirve para almacenar al jugador 2

    system("cls"); //clear console.//

    do
    {

        cout << "--------- Menu Juego ---------" << endl;
        cout<<"1- Crear Jugador."<<endl;
        cout<<"2- Jugar."<<endl;
        cout<<"3- Regresar."<<endl;



        cout<<"Seleccione una Opcion: "<<endl;
        cin >> opcion;
        cin.ignore(); // limpia e buffer de entrada
        seleccion = opcion[0];
        switch(seleccion)
        {
        case '1':
            system("cls"); //Clear console.//
            //ir al menu a pedir nombre del archivo
            cout<<"Nombre Jugador Nuevo: "<<endl;
            cin>>jugadorNuevo;

            //si el arbol no esta vacio buscar
            if(!arbol->empty_arbol())
            {
                //bandera = false;
                //system("cls"); //Clear console.//
                //menu_search();
                if(arbol->search_playlist(jugadorNuevo)!= 0) // evaluar si ya existe
                {
                    cout<<"Error EL usuario ya esta ocupado"<<endl;

                }
                else // ingresar si aun no existe
                {
                    nodoABB* n = new nodoABB(jugadorNuevo);
                    arbol->add(n);
                    //se agrega a la doble circular
                    usuarios->insertarFinal(jugadorNuevo);
                    cout<<"jugador Registrado Exitosamenteeee"<<endl;

                }


            }else
            {
                nodoABB* n = new nodoABB(jugadorNuevo); // se agrega al arbol
                arbol->add(n);
                //se agrega a la doble circular
                usuarios->insertarFinal(jugadorNuevo);
                cout<<"jugador Registrado Exitosamente"<<endl;
            }
            //arbol->graph();
            usuarios->graficar();

            break;
        case '2':
            bandera = false;
            if(usuarios->tam<2)
            {

                cout<<"ingrese por lo menos 2 jugadores como nuevos"<<endl;
                system("pause");
                menu_juego();
            }
            else
            {
                menu_IniciarJuego();
            }

            break;
        case '3':
            bandera = false;
            menu_inicial();
            break;
        default:
            cout << "---------------------------------------" << endl;
            cout << "------- ERROR:  opcion invalida--------" << endl;
            cout << "---------------------------------------" << endl;
            break;
        }

    }
    while(bandera);

}
//-----------------------------------------------------------------------------------------------------
void Menu::menu_IniciarJuego()
{
    system("cls");
    //char opcion[40]; // variable que lee la opcion seleccinada por el usuario
    int seleccion =0;

    string j1 = "";
    string j2 = "";

    //captura del jugador 1
    cout<<"Seleccione jugador 1"<<endl;
    usuarios->imprimir();
    cin>>seleccion;
    j1 = usuarios->enviarJugador(seleccion);
    cout<<"j1: "<<j1;
    jugador1->nombrejugador = j1;
    system("pause");

    //captura del jugador 2
    system("cls");
    cout<<"Seleccione jugador 2"<<endl;
    usuarios->imprimir();
    cin>>seleccion;
    j2 = usuarios->enviarJugador(seleccion);
    cout<<"j2: "<<j2;
    jugador2->nombrejugador = j2;

    //llenar la lista inicial de fichas de cada jugador
    int contar7 = 0;

    while(contar7<7)
    {
        char letra;
        int punteo=0;
        ficha = colaFichas->dequeue();
        letra = ficha->letra;
        punteo = ficha->punteo;

        jugador1->listaFichas->insertarFinal(letra,punteo);

        contar7++;
    }

        int contar77 = 0;

    while(contar77<7)
    {
        char letra;
        int punteo=0;
        ficha = colaFichas->dequeue();
        letra = ficha->letra;
        punteo = ficha->punteo;

        jugador2->listaFichas->insertarFinal(letra,punteo);

        contar77++;
    }

    //imprimir el listado de fichas de los jugadores
    system("cls");
    cout<<"Fichas de Jugador 1"<<endl;
    jugador1->listaFichas->imprimir();
    cout<<endl;
    system("pause");
    system("cls");
    cout<<"Fichas de Jugador 2"<<endl;
    jugador2->listaFichas->imprimir();
    cout<<endl;
    system("pause");

//****************************++++++++++++++++++++
    //turnos de juego

    bool turno = true; // si es true turno jugador 1, si es false turno jugador 2
    while(true)
    {
        if(turno) // si es verdadero le toca a jugador 1
        {
            //jugador 1
            system("cls");
            cout<<"Turno de jugador 1: "<<jugador1->nombrejugador<<endl;
            cout<<"Para terminar la partida presione Escape, sino barra espaciadora"<<endl;
            int teclaa = getch(); //caracter a evaluar
            char intTeclaa = teclaa;
            if(teclaa==27) //tecla de escape
            {
                break;
            }
            else
            {
                system("cls");
               turnoJugador1();
               turno=false; // termino su turno

            }


        }
        else
        {
            //jugador 2
            system("cls");
            cout<<"Turno de jugador 2: "<<jugador2->nombrejugador<<endl;
            cout<<"Para terminar la partida presione Escape, sino barra espaciadora"<<endl;
            int teclaa = getch(); //caracter a evaluar
            char intTeclaa = teclaa;
            if(teclaa==27) //tecla de escape
            {
                break;
            }
            else
            {
                system("cls");
               turnoJugador2();
               turno=true; // termino su turno

            }
        }

        cout<<"Para terminar la partida presione Escape, sino barra espaciadoraaaaaaaaa"<<endl;
        int tecla = getch(); //caracter a evaluar
        char intTecla = tecla;

        if(tecla==27) //tecla de escape
        {
            break;
        }



    }
    //termino la partida
}
//--------------------------------------------------------------------------------------------------
void Menu::turnoJugador1()
{
    while(true)
    {
        cout<<"1. ver fichas"<<endl;
        cout<<"2. cambiar fichas"<<endl;
        cout<<"3. colocar fichas"<<endl;
        cout<<"4. terminar turno"<<endl;

        int tecla = getch(); //caracter a evaluar
        char intTecla = tecla;

        if(tecla==49) //opcion 1
        {
            system("cls");
            cout<<"opcion 1 jugador 1"<<endl;
            jugador1->listaFichas->imprimir();
            cout<<"---------------------------"<<endl;
            system("pause");
            system("cls");
            //break;
        }


        else if(tecla==50) //opcion 2
        {
            cout<<"opcion 2 jugador 1"<<endl;

            //vaciar lista de fichas, encolarlas y luego desencolar 7
            fichaRegreso = jugador1->listaFichas->getPrimero();


            while(fichaRegreso != 0 )
            {
                colaFichas->enqueue(fichaRegreso->punteo,fichaRegreso->letra); // se regresa a la cola de fichas las 7 fichas
                fichaRegreso = fichaRegreso->sig;
            }

            //se resetea la lista de fichas del jugador
            jugador1->listaFichas->resetear();

            //se desencolan 7 fichas de la cola y se meten a la lista de fichas del jugador

            int contar7 = 0;

            while(contar7<7)
            {
                char letra;
                int punteo=0;
                ficha = colaFichas->dequeue();
                letra = ficha->letra;
                punteo = ficha->punteo;

                jugador1->listaFichas->insertarFinal(letra,punteo);

                contar7++;
            }

            cout<<"FICHAS CAMBIADAS"<<endl;
            system("pause");

            break; //esta accion de cambiar fichas, termina el turno del jugador
        }


        else if(tecla==51) //opcion 3
        {
            menuAuxiliarPonerFicchas();



            break;
        }
        else if(tecla==52) //opcion 4
        {
             cout<<"TURNO TERMINADO JUGADOR 1"<<endl;
            break;
        }


    }

}

//--------------------------------------------------------------------------------------------------
void Menu::turnoJugador2()
{
    while(true)
    {
        cout<<"1. ver fichas"<<endl;
        cout<<"2. cambiar fichas"<<endl;
        cout<<"3. colocar fichas"<<endl;
        cout<<"4. terminar turno"<<endl;

        int tecla = getch(); //caracter a evaluar
        char intTecla = tecla;

        if(tecla==49) //opcion 1
        {
            system("cls");
            cout<<"opcion 1 jugador 2"<<endl;
            jugador2->listaFichas->imprimir();
            cout<<"---------------------------"<<endl;
            system("pause");
            system("cls");
            //break;
        }


        else if(tecla==50) //opcion 2
        {
            cout<<"opcion 2 jugador 2"<<endl;

            //vaciar lista de fichas, encolarlas y luego desencolar 7
            fichaRegreso = jugador2->listaFichas->getPrimero();


            while(fichaRegreso != 0 )
            {
                colaFichas->enqueue(fichaRegreso->punteo,fichaRegreso->letra); // se regresa a la cola de fichas las 7 fichas
                fichaRegreso = fichaRegreso->sig;
            }

            //se resetea la lista de fichas del jugador
            jugador2->listaFichas->resetear();

            //se desencolan 7 fichas de la cola y se meten a la lista de fichas del jugador

            int contar7 = 0;

            while(contar7<7)
            {
                char letra;
                int punteo=0;
                ficha = colaFichas->dequeue();
                letra = ficha->letra;
                punteo = ficha->punteo;

                jugador2->listaFichas->insertarFinal(letra,punteo);

                contar7++;
            }

            cout<<"FICHAS CAMBIADAS"<<endl;
            system("pause");

            break; //esta accion de cambiar fichas, termina el turno del jugador
        }

        else if(tecla==51) //opcion 3
        {
            cout<<"opcion 3 jugador 2"<<endl;
            //break;
        }
        else if(tecla==52) //opcion 4
        {
             cout<<"TURNO TERMINADO JUGADOR 2"<<endl;
            break;
        }


    }

}
//--------------------------------------------------------------------------------------------------
void Menu::menuAuxiliarPonerFicchas()
{
    ListaDoble* fichasSacadas = new ListaDoble(); // lista de fichas que se van sacando para validar
    string lexemaPalabraFormada = ""; // concatena cada char que se va sacando de la lista, para validar que la palabra sea valida

    while(true)
    {
        system("cls");
        cout<<"opcion 3 jugador 1"<<endl;
        jugador1->listaFichas->imprimir();
        cout<<"Escape para validar palabra."<<endl;
        cout<<"Seleccione ficha a colocar: "<<endl;
        int opcionNum = getch(); //caracter a evaluar

        NodoListaDoble* aux=0; //nodo que se evalua si trae algo

        if(opcionNum==49)// numero 1
        {
            aux = jugador1->listaFichas->remove_at(0);
        }
        else if(opcionNum==50)// numero 2
        {
            aux = jugador1->listaFichas->remove_at(1);
        }
        else if(opcionNum==51)// numero 3
        {
            aux = jugador1->listaFichas->remove_at(2);
        }
        else if(opcionNum==52)// numero 4
        {
            aux = jugador1->listaFichas->remove_at(3);
        }
        else if(opcionNum==53)// numero 5
        {
            aux = jugador1->listaFichas->remove_at(4);
        }
        else if(opcionNum==54)// numero 6
        {
            aux = jugador1->listaFichas->remove_at(5);
        }
        else if(opcionNum==55)// numero 7
        {
            aux = jugador1->listaFichas->remove_at(6);
        }
        else if(opcionNum==27)// numero Escape
        {

            //el usuario pidio validar su palabra
            lexemaPalabraFormada = fichasSacadas->evaluarPalabra();
            cout<<"palabra a buscar en el diccionario: "<<lexemaPalabraFormada<<endl;

            //si la palabra existe, entonces colocar en el tablero y sumar puntos, luego terminar el turno
            if(diccio->validarPalabra(lexemaPalabraFormada))
            {
                cout<<"la palabra si existe: "<<lexemaPalabraFormada<<endl;

                //darle la cantidad de fichas de la palabra
                int  contar = 0;
                while(contar < fichasSacadas->getTam())
                {
                    if(colaFichas->tamano!=0)
                    {
                        char letra;
                        int punteo=0;
                        ficha = colaFichas->dequeue();
                        letra = ficha->letra;
                        punteo = ficha->punteo;

                        jugador1->listaFichas->insertarFinal(letra,punteo);

                    }


                    contar++;
                }
                insertandoPalabra(fichasSacadas->getTam(),*fichasSacadas);
                matrizJuego->graficar();
                system("cls");
                cout<<"palabra Insertada "<<endl;
                cout<<"Graficando Resultado "<<endl;

            }
            //de no ser valida la palabra formada, regresar las fichas al jugador
            else
            {
                cout<<"Regresando fichas al jugador..."<<endl;
                cout<<"tama;o de la lista: "<<to_string(fichasSacadas->getTam());
                //ciclo que regresa las fichas

                NodoListaDoble* regreso = fichasSacadas->getPrimero();
                int  contar = 0;
                while(contar < fichasSacadas->getTam())
                {
                    jugador1->listaFichas->insertarFinal(regreso->letra,regreso->punteo);
                    regreso = regreso->sig;
                    contar++;
                }


            }

            break;
        }
        else // envia a remover un indice inexistente por defecto, lo que terminara su turno en evaluacion futura
        {
            aux = jugador1->listaFichas->remove_at(11);
        }



        //evaluar si aux es diferente de nulo, es decir si saco un nodo de la lista doble
        if(aux!=0)
        {
            cout<<"se extrajo: letra "<<aux->letra<<" valor: "<<to_string(aux->punteo)<<endl;
            //insertar en la lista de sacadas
            fichasSacadas->insertarFinal(aux->letra,aux->punteo);

        }
        else
        {
            //primero evaluar si la lista esta vacia, es decir si uso sus 7 fichas
            if(jugador1->listaFichas->estaVacia())
            {
                //de estar vacia validar palabra del diccionario formada
                lexemaPalabraFormada = fichasSacadas->evaluarPalabra();
                cout<<"palabra a buscar en el diccionario: "<<lexemaPalabraFormada<<endl;

                //si la palabra existe, entonces colocar en el tablero y sumar puntos, luego terminar el turno
                if(diccio->validarPalabra(lexemaPalabraFormada))
            if(diccio->validarPalabra(lexemaPalabraFormada))
            {
                cout<<"la palabra si existe: "<<lexemaPalabraFormada<<endl;

                //darle la cantidad de fichas de la palabra
                int  contar = 0;
                while(contar < fichasSacadas->getTam())
                {
                    if(colaFichas->tamano!=0)
                    {
                        char letra;
                        int punteo=0;
                        ficha = colaFichas->dequeue();
                        letra = ficha->letra;
                        punteo = ficha->punteo;

                        jugador1->listaFichas->insertarFinal(letra,punteo);

                    }


                    contar++;
                }
                insertandoPalabra(fichasSacadas->getTam(),*fichasSacadas);
                matrizJuego->graficar();
                system("cls");
                cout<<"palabra Insertada "<<endl;
                cout<<"Graficando Resultado "<<endl;

            }
                //de no ser valida la palabra formada, regresar las fichas al jugador
                else
                {
                    cout<<"Regresando fichas al jugador..."<<endl;
                    cout<<"tama;o de la lista: "<<to_string(fichasSacadas->getTam());
                    //ciclo que regresa las fichas

                    NodoListaDoble* regreso = fichasSacadas->getPrimero();
                    int  contar = 0;
                    while(contar < fichasSacadas->getTam())
                    {
                        jugador1->listaFichas->insertarFinal(regreso->letra,regreso->punteo);
                        regreso = regreso->sig;
                        contar++;
                    }


                }

            }
            else
            {
                //regresar las que se saquen si es que se saca alguna
                cout<<"opcion invalida, pierdes turno"<<endl;
                cout<<"Regresando fichas al jugador..."<<endl;
                cout<<"tama;o de la lista: "<<to_string(fichasSacadas->getTam());
                //ciclo que regresa las fichas

                NodoListaDoble* regreso = fichasSacadas->getPrimero();
                int  contar = 0;
                while(contar < fichasSacadas->getTam())
                {
                    jugador1->listaFichas->insertarFinal(regreso->letra,regreso->punteo);
                    regreso = regreso->sig;
                    contar++;
                }
            }


            break;
        }
        system("pause");
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------
void Menu::insertandoPalabra(int cantidadLetras,ListaDoble& letrasColocar)
{
    system("cls");
    cout<<"Mostrando Tablero: "<<endl;
    matrizJuego->graficar();
    system("cls");
    system("pause");
    int posx = 1;
    int posy = 1;
    cout<<"Posicion inicial x deseada: "<<endl;
    cin>>posx;
    cout<<"Posicion inicial y deseada: "<<endl;
    cin>>posy;
    cout<<"Desea un ingreso horizontal o vertical: "<<endl;
    cout<<"1. Horizontal "<<endl;
    cout<<"2. Vertical "<<endl;
    int eleccion=1;
    cin>>eleccion;

    //se ingresa horizontal
    if(eleccion==1)
    {
        NodoListaDoble* aux = letrasColocar.getPrimero();
        while(aux!=0)
        {
            matrizJuego->insertarElemento(to_string(posy),to_string(posx),aux->punteo,aux->letra,"f");
            //evaluar el valor de la ficha y si es doble o triple y sumarlo al conteo de puntos de ronda
            posx++;
            aux = aux->sig;
        }


    }
    //se ingresa vertical
    else if(eleccion==2)
    {
        NodoListaDoble* aux = letrasColocar.getPrimero();
        while(aux!=0)
        {
            matrizJuego->insertarElemento(to_string(posy),to_string(posx),aux->punteo,aux->letra,"f");
            //evaluar el valor de la ficha y si es doble o triple y sumarlo al conteo de puntos de ronda
            posy++;
            aux = aux->sig;
        }

    }

}

