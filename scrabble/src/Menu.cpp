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
            cout<<"opcion 3 jugador 1"<<endl;
            //break;
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
