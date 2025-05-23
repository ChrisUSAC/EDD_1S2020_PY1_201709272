#include "Menu.h"

//estructuras globales
ArbolABB* arbol = new ArbolABB(); // arbol que guarda los usuarios del juego
ListaDobleCDiccionario* diccio = new ListaDobleCDiccionario(); // diccionario de palabras validas del juego

ListaDobleCDiccionario* diccioCordenadas = new ListaDobleCDiccionario(); // diccionario coordenadas especiales

Matriz* matrizJuego = new Matriz(); // matriz que sera el tablero de juego
ListaDobleC* usuarios = new ListaDobleC();// listado de jugadores

Jugador* jugador1 = new Jugador(); // objeto con el que jugara el jugador 1
Jugador* jugador2 = new Jugador(); // objeto con el que jugara el jugador 2

Cola* colaFichas = new Cola(); // listado de fichas del juego

ListaJugador* Players = new ListaJugador(); // almacena los jugadores con partidas, sus score y sus listas de juegos

ListaSRecorrido* Recorrido = new ListaSRecorrido();


//variables globales para tener a los jugadores

string ultimoArchivoCargado = "c.json"; //se creo uno por defecto para el inicio de las partidas, si es que no se cargo ningun archivo

int primeraPartida = 0; // si es 0 no guarda a jugadores al iniciar partida

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
            system("cls"); //Clear console.//
            cout<<"Opcion 3";
            menu_reportes();

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
            ultimoArchivoCargado = nombreArchivo; // se le guarda el ultimo archivo cargado
            //reseteo de palabras por si se cargan nuevos archivos
            diccio->resetear();
            diccioCordenadas->resetear();
            matrizJuego->resetear();
            archivo->leer(nombreArchivo,*diccio,*matrizJuego,*diccioCordenadas);
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
void Menu::menu_reportes()
{
    bool bandera = true;
    char opcion[40]; // variable que lee la opcion seleccinada por el usuario
    int seleccion =0;

    system("cls"); //clear console.//

    do
    {

        cout << "--------- Reportes Aplicacion ---------" << endl;
        cout<<"1- Diccionario Palabras."<<endl;
        cout<<"2- Cola de fichas Disponibles."<<endl;
        cout<<"3- Arbol binario de busqueda."<<endl;
        cout<<"4- Recorridos Arbol."<<endl;
        cout<<"5- Historial de Puntajes Jugadores con Partidas Terminadas."<<endl;
        cout<<"6- Top Punteos."<<endl;
        cout<<"7- Tablero de Juego."<<endl;
        cout<<"8. Fichas Jugadores En Partida"<<endl;
        cout<<"9. Regresar. "<<endl;


        cout<<"Seleccione una Opcion: ";
        cin >> opcion;
        cin.ignore(); // limpia e buffer de entrada
        seleccion = opcion[0];
        switch(seleccion)
        {
        case '1':
            system("cls"); //Clear console.//
            diccio->graficar();
            break;
        case '2':
            system("cls"); //Clear console.//
            colaFichas->graficar();
            cout<<"Tamano cola de fichas: "<<endl;
            cout<<to_string(colaFichas->tamano)<<endl;
            system("pause"); //pause
            system("cls"); //Clear console.//
            break;
        case '3':
            system("cls"); //Clear console.//
            arbol->graph();
            system("pause"); //pause
            break;
        case '4':
            system("cls"); //Clear console.//
            cout<<"Recorrido Preorder"<<endl;
            arbol->preorder();
            cout<<endl;
            system("pause");
            cout<<"Recorrido inorder"<<endl;
            arbol->inorder();
            cout<<endl;
            system("pause");
            cout<<"Recorrido postorder"<<endl;
            arbol->postorder();
            cout<<endl;
            system("pause");
            system("cls"); //Clear console.//
            break;
        case '5':
            system("cls"); //Clear console.//
            break;
        case '6':
            system("cls"); //Clear console.//
            Players->imprimir();
            system("pause");
            Players->graficar();
            break;
        case '7':
            system("cls"); //Clear console.//
            matrizJuego->graficar();
            break;
        case '8':
            system("cls"); //Clear console.//
            cout<<"Fichas jugador1: "<<jugador1->nombrejugador<<endl;
            jugador1->listaFichas->graficar();
            system("pause"); //pause
            cout<<"Fichas jugador2: "<<jugador2->nombrejugador<<endl;
            jugador2->listaFichas->graficar();
            system("pause"); //pause
            system("cls"); //Clear console.//
            break;
        case '9':
            system("cls"); //Clear console.//
            bandera = false;
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

                jugador1->resetearjugador();
                jugador2->resetearjugador();
                //reseteo de palabras por si se cargan nuevos archivos
                diccio->resetear();
                diccioCordenadas->resetear();
                matrizJuego->resetear();
                archivo->leer(ultimoArchivoCargado,*diccio,*matrizJuego,*diccioCordenadas);
                //antes de iniciar el juego se resetea
                colaFichas->resetear(); // resetea la cola anterior por si acabo una partida
                colaFichas->llenadoInicial(); // llena la lista de fichas por si hay una partida nueva
                menu_IniciarJuego();
                menu_inicial();


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

//-----------------------------------------------------------------------------------------
        //termino la partida
if(jugador1->punteoAcumulado > jugador2->punteoAcumulado)
{
    cout<<"Felicidades Gano: "<<jugador1->nombrejugador<<" Total Puntos: "<<to_string(jugador1->punteoAcumulado)<<endl;
    system("pause");
}
else if(jugador2->punteoAcumulado > jugador1->punteoAcumulado)
{
    cout<<"Felicidades Gano: "<<jugador2->nombrejugador<<" Total Puntos: "<<to_string(jugador2->punteoAcumulado)<<endl;
    system("pause");
}
else
{
    cout<<"Resultado... Empate. "<<endl;
    system("pause");
}


        //guardar a los de la primera partida
                //si es la primera partida
                if(primeraPartida==0)
                {
                    cout<<"Primera Partida//// a guardarlos "<<endl;
                    system("pause");
                    jugador1->puntajesIndividual->insertar(jugador1->nombrejugador,jugador1->punteoAcumulado);
                    jugador2->puntajesIndividual->insertar(jugador2->nombrejugador,jugador2->punteoAcumulado);
                    Players->insertarJugador(jugador1,jugador1->nombrejugador);
                    Players->insertarJugador(jugador2,jugador2->nombrejugador);

                }else
                {
                    jugador1->puntajesIndividual->insertar(jugador1->nombrejugador,jugador1->punteoAcumulado);

                    jugador2->puntajesIndividual->insertar(jugador2->nombrejugador,jugador2->punteoAcumulado);

                    //evaluar si existe ya algun jugador con ese nombre
                    NodoListaJugador* existe = Players->existeJugador(jugador1->nombrejugador);

                    if(existe!=0)
                    {
                        cout<<"ya existe el jugador"<<endl;
                        system("pause");

                        existe->jugador->puntajesIndividual = jugador1->puntajesIndividual;

                    }
                    else
                    {
                    Players->insertarJugador(jugador1,jugador1->nombrejugador);

                    }

                    //evaluar si existe ya algun jugador con ese nombre
                    NodoListaJugador* existe2 = Players->existeJugador(jugador2->nombrejugador);

                    if(existe2!=0)
                    {
                        cout<<"ya existe el jugador2"<<endl;
                        system("pause");
                        existe2->jugador->puntajesIndividual = jugador2->puntajesIndividual;

                    }
                    else
                    {
                    Players->insertarJugador(jugador2,jugador2->nombrejugador);

                    }

                }

        primeraPartida+=1;

    //guardar en lista jugadores, resetear listas correspondientes y dejar a jugadores para futuros usos
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
            menuAuxiliarPonerFicchas2();
            break;
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
                int punteoRonda =0;
                punteoRonda = insertandoPalabra(fichasSacadas->getTam(),*fichasSacadas);
                matrizJuego->graficar();
                system("cls");
                cout<<"palabra Insertada "<<endl;
                cout<<"Graficando Resultado "<<endl;
                cout<<"Puntos de la Palabra: "<<to_string(punteoRonda)<<endl;
                jugador1->punteoAcumulado += punteoRonda;  //se le agrega al puntaje de partida lo que va acumulando el jugador
                cout<<"Puntos Totales de la partida: "<<to_string(jugador1->punteoAcumulado)<<endl;

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
                int punteoRonda=0;
                punteoRonda = insertandoPalabra(fichasSacadas->getTam(),*fichasSacadas);

                matrizJuego->graficar();
                system("cls");
                cout<<"palabra Insertada "<<endl;
                cout<<"Graficando Resultado "<<endl;
                cout<<"Puntos de la Palabra: "<<to_string(punteoRonda)<<endl;
                jugador1->punteoAcumulado += punteoRonda;  //se le agrega al puntaje de partida lo que va acumulando el jugador
                cout<<"Puntos Totales de la partida: "<<to_string(jugador1->punteoAcumulado)<<endl;

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
//--------------------------------------------------------------------------------------------------
void Menu::menuAuxiliarPonerFicchas2()

{
    ListaDoble* fichasSacadas = new ListaDoble(); // lista de fichas que se van sacando para validar
    string lexemaPalabraFormada = ""; // concatena cada char que se va sacando de la lista, para validar que la palabra sea valida

    while(true)
    {
        system("cls");
        cout<<"opcion 3 jugador 2"<<endl;
        jugador2->listaFichas->imprimir();
        cout<<"Escape para validar palabra."<<endl;
        cout<<"Seleccione ficha a colocar: "<<endl;
        int opcionNum = getch(); //caracter a evaluar

        NodoListaDoble* aux=0; //nodo que se evalua si trae algo

        if(opcionNum==49)// numero 1
        {
            aux = jugador2->listaFichas->remove_at(0);
        }
        else if(opcionNum==50)// numero 2
        {
            aux = jugador2->listaFichas->remove_at(1);
        }
        else if(opcionNum==51)// numero 3
        {
            aux = jugador2->listaFichas->remove_at(2);
        }
        else if(opcionNum==52)// numero 4
        {
            aux = jugador2->listaFichas->remove_at(3);
        }
        else if(opcionNum==53)// numero 5
        {
            aux = jugador2->listaFichas->remove_at(4);
        }
        else if(opcionNum==54)// numero 6
        {
            aux = jugador2->listaFichas->remove_at(5);
        }
        else if(opcionNum==55)// numero 7
        {
            aux = jugador2->listaFichas->remove_at(6);
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

                        jugador2->listaFichas->insertarFinal(letra,punteo);

                    }


                    contar++;
                }
                int punteoRonda =0;
                punteoRonda = insertandoPalabra2(fichasSacadas->getTam(),*fichasSacadas);
                matrizJuego->graficar();
                system("cls");
                cout<<"palabra Insertada "<<endl;
                cout<<"Graficando Resultado "<<endl;
                cout<<"Puntos de la Palabra: "<<to_string(punteoRonda)<<endl;
                jugador2->punteoAcumulado += punteoRonda;  //se le agrega al puntaje de partida lo que va acumulando el jugador
                cout<<"Puntos Totales de la partida: "<<to_string(jugador2->punteoAcumulado)<<endl;

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
                    jugador2->listaFichas->insertarFinal(regreso->letra,regreso->punteo);
                    regreso = regreso->sig;
                    contar++;
                }


            }

            break;
        }
        else // envia a remover un indice inexistente por defecto, lo que terminara su turno en evaluacion futura
        {
            aux = jugador2->listaFichas->remove_at(11);
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
            if(jugador2->listaFichas->estaVacia())
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

                        jugador2->listaFichas->insertarFinal(letra,punteo);

                    }


                    contar++;
                }
                int punteoRonda=0;
                punteoRonda = insertandoPalabra2(fichasSacadas->getTam(),*fichasSacadas);

                matrizJuego->graficar();
                system("cls");
                cout<<"palabra Insertada "<<endl;
                cout<<"Graficando Resultado "<<endl;
                cout<<"Puntos de la Palabra: "<<to_string(punteoRonda)<<endl;
                jugador2->punteoAcumulado += punteoRonda;  //se le agrega al puntaje de partida lo que va acumulando el jugador
                cout<<"Puntos Totales de la partida: "<<to_string(jugador2->punteoAcumulado)<<endl;

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
                        jugador2->listaFichas->insertarFinal(regreso->letra,regreso->punteo);
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
                    jugador2->listaFichas->insertarFinal(regreso->letra,regreso->punteo);
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
int Menu::insertandoPalabra(int cantidadLetras,ListaDoble& letrasColocar)
{
    int punteoRonda = 0; // variable que almacena los puntos de la ronda
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
        //recorre todas las letras a colocar en el tablero para determinar su punteo
        NodoListaDoble* aux = letrasColocar.getPrimero();
        while(aux!=0)
        {
            //booleano que servira para saber si ya se conto como doble o triple
            bool yalosume = false;

            matrizJuego->insertarElemento(to_string(posy),to_string(posx),aux->punteo,aux->letra,"f");
            system("cls");
            //evaluar el valor de la ficha y si es doble o triple y sumarlo al conteo de puntos de ronda
                           // cout<<"posx luego de insertar en matriz un caracter: "<<to_string(posx)<<endl;
                            //cout<<"posy luego de insertar en matriz un caracter: "<<to_string(posy)<<endl;


            //validar punteo por ronda
            NodoListaDobleC* dobleotriple = diccioCordenadas->primero;

            if(diccioCordenadas->estaVacia())
            {
            //cout<<"lista vacia"<<endl;

            }
            else
            {
                //entero que servira para iterar el while
                int indice =0;

                //ciclo de validacion de punteo
                while(indice < diccioCordenadas->tam)
                {


                    //validar si es una posicion doble o triple

                    string dicedoble = "doble";
                    string dicetriple = "triple";
                    const char *a =dobleotriple->nombre.c_str(); // si dice doble
                    const char *b =dicedoble.c_str();
                    const char *c =dicetriple.c_str();

                    //comparamos con el metodo y si dice doble
                    if(strcmp(a,b) == 0)
                    {
                        if(dobleotriple->x == posx && dobleotriple->y == posy)
                        {
                            int sumar = 0;
                            sumar = aux->punteo*2;
                            punteoRonda += sumar;
                            //cout<<"posx "<<to_string(posx)<<endl;
                            //cout<<"posy "<<to_string(posy)<<endl;
                            //cout<<"valor de letra doble: "<<to_string(sumar)<<endl;
                            yalosume = true;
                            //system("pause");
                        }
                    }
                    //comparar si dice triple
                    else if(strcmp(a,c) == 0)
                    {
                        if(dobleotriple->x == posx && dobleotriple->y == posy)
                        {
                            int sumar = 0;
                            sumar = aux->punteo*3;
                            punteoRonda += sumar;
                            //cout<<"posx "<<to_string(posx)<<endl;
                            //cout<<"posy "<<to_string(posy)<<endl;
                            //cout<<"valor de letra triple: "<<to_string(sumar)<<endl;
                            yalosume = true;
                            //system("pause");
                        }

                    }

                    dobleotriple =dobleotriple->sig;
                    indice++;
                }

            }

            if(yalosume==false)
            {
                punteoRonda += aux->punteo;
                //cout<<"valor de letra simple: "<<to_string(aux->punteo);
                //system("pause");
            }

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
            //booleano que servira para saber si ya se conto como doble o triple
            bool yalosume = false;

            matrizJuego->insertarElemento(to_string(posy),to_string(posx),aux->punteo,aux->letra,"f");
            system("cls");
            //evaluar el valor de la ficha y si es doble o triple y sumarlo al conteo de puntos de ronda
                           // cout<<"posx luego de insertar en matriz un caracter: "<<to_string(posx)<<endl;
                            //cout<<"posy luego de insertar en matriz un caracter: "<<to_string(posy)<<endl;


            //validar punteo por ronda
            NodoListaDobleC* dobleotriple = diccioCordenadas->primero;

            if(diccioCordenadas->estaVacia())
            {
            //cout<<"lista vacia"<<endl;

            }
            else
            {
                //entero que servira para iterar el while
                int indice =0;

                //ciclo de validacion de punteo
                while(indice < diccioCordenadas->tam)
                {


                    //validar si es una posicion doble o triple

                    string dicedoble = "doble";
                    string dicetriple = "triple";
                    const char *a =dobleotriple->nombre.c_str(); // si dice doble
                    const char *b =dicedoble.c_str();
                    const char *c =dicetriple.c_str();

                    //comparamos con el metodo y si dice doble
                    if(strcmp(a,b) == 0)
                    {
                        if(dobleotriple->x == posx && dobleotriple->y == posy)
                        {
                            int sumar = 0;
                            sumar = aux->punteo*2;
                            punteoRonda += sumar;
                            //cout<<"posx "<<to_string(posx)<<endl;
                            //cout<<"posy "<<to_string(posy)<<endl;
                            //cout<<"valor de letra doble: "<<to_string(sumar)<<endl;
                            yalosume = true;
                            //system("pause");
                        }
                    }
                    //comparar si dice triple
                    else if(strcmp(a,c) == 0)
                    {
                        if(dobleotriple->x == posx && dobleotriple->y == posy)
                        {
                            int sumar = 0;
                            sumar = aux->punteo*3;
                            punteoRonda += sumar;
                            //cout<<"posx "<<to_string(posx)<<endl;
                            //cout<<"posy "<<to_string(posy)<<endl;
                            //cout<<"valor de letra triple: "<<to_string(sumar)<<endl;
                            yalosume = true;
                            //system("pause");
                        }

                    }

                    dobleotriple =dobleotriple->sig;
                    indice++;
                }

            }

            if(yalosume==false)
            {
                punteoRonda += aux->punteo;
                //cout<<"valor de letra simple: "<<to_string(aux->punteo);
                //system("pause");
            }


            posy++;
            aux = aux->sig;
        }

    }

    return punteoRonda;
}
//-------------------------------------------------------------------------------------------------------------------------------------
int Menu::insertandoPalabra2(int cantidadLetras, ListaDoble& letrasColocar)
{
    int punteoRonda = 0; // variable que almacena los puntos de la ronda
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
        //recorre todas las letras a colocar en el tablero para determinar su punteo
        NodoListaDoble* aux = letrasColocar.getPrimero();
        while(aux!=0)
        {
            //booleano que servira para saber si ya se conto como doble o triple
            bool yalosume = false;

            matrizJuego->insertarElemento(to_string(posy),to_string(posx),aux->punteo,aux->letra,"f");
            system("cls");
            //evaluar el valor de la ficha y si es doble o triple y sumarlo al conteo de puntos de ronda
                           // cout<<"posx luego de insertar en matriz un caracter: "<<to_string(posx)<<endl;
                            //cout<<"posy luego de insertar en matriz un caracter: "<<to_string(posy)<<endl;


            //validar punteo por ronda
            NodoListaDobleC* dobleotriple = diccioCordenadas->primero;

            if(diccioCordenadas->estaVacia())
            {
            //cout<<"lista vacia"<<endl;

            }
            else
            {
                //entero que servira para iterar el while
                int indice =0;

                //ciclo de validacion de punteo
                while(indice < diccioCordenadas->tam)
                {


                    //validar si es una posicion doble o triple

                    string dicedoble = "doble";
                    string dicetriple = "triple";
                    const char *a =dobleotriple->nombre.c_str(); // si dice doble
                    const char *b =dicedoble.c_str();
                    const char *c =dicetriple.c_str();

                    //comparamos con el metodo y si dice doble
                    if(strcmp(a,b) == 0)
                    {
                        if(dobleotriple->x == posx && dobleotriple->y == posy)
                        {
                            int sumar = 0;
                            sumar = aux->punteo*2;
                            punteoRonda += sumar;
                            //cout<<"posx "<<to_string(posx)<<endl;
                            //cout<<"posy "<<to_string(posy)<<endl;
                            //cout<<"valor de letra doble: "<<to_string(sumar)<<endl;
                            yalosume = true;
                            //system("pause");
                        }
                    }
                    //comparar si dice triple
                    else if(strcmp(a,c) == 0)
                    {
                        if(dobleotriple->x == posx && dobleotriple->y == posy)
                        {
                            int sumar = 0;
                            sumar = aux->punteo*3;
                            punteoRonda += sumar;
                            //cout<<"posx "<<to_string(posx)<<endl;
                            //cout<<"posy "<<to_string(posy)<<endl;
                            //cout<<"valor de letra triple: "<<to_string(sumar)<<endl;
                            yalosume = true;
                            //system("pause");
                        }

                    }

                    dobleotriple =dobleotriple->sig;
                    indice++;
                }

            }

            if(yalosume==false)
            {
                punteoRonda += aux->punteo;
                //cout<<"valor de letra simple: "<<to_string(aux->punteo);
                //system("pause");
            }

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
            //booleano que servira para saber si ya se conto como doble o triple
            bool yalosume = false;

            matrizJuego->insertarElemento(to_string(posy),to_string(posx),aux->punteo,aux->letra,"f");
            system("cls");
            //evaluar el valor de la ficha y si es doble o triple y sumarlo al conteo de puntos de ronda
                           // cout<<"posx luego de insertar en matriz un caracter: "<<to_string(posx)<<endl;
                            //cout<<"posy luego de insertar en matriz un caracter: "<<to_string(posy)<<endl;


            //validar punteo por ronda
            NodoListaDobleC* dobleotriple = diccioCordenadas->primero;

            if(diccioCordenadas->estaVacia())
            {
            //cout<<"lista vacia"<<endl;

            }
            else
            {
                //entero que servira para iterar el while
                int indice =0;

                //ciclo de validacion de punteo
                while(indice < diccioCordenadas->tam)
                {


                    //validar si es una posicion doble o triple

                    string dicedoble = "doble";
                    string dicetriple = "triple";
                    const char *a =dobleotriple->nombre.c_str(); // si dice doble
                    const char *b =dicedoble.c_str();
                    const char *c =dicetriple.c_str();

                    //comparamos con el metodo y si dice doble
                    if(strcmp(a,b) == 0)
                    {
                        if(dobleotriple->x == posx && dobleotriple->y == posy)
                        {
                            int sumar = 0;
                            sumar = aux->punteo*2;
                            punteoRonda += sumar;
                            //cout<<"posx "<<to_string(posx)<<endl;
                            //cout<<"posy "<<to_string(posy)<<endl;
                            //cout<<"valor de letra doble: "<<to_string(sumar)<<endl;
                            yalosume = true;
                            //system("pause");
                        }
                    }
                    //comparar si dice triple
                    else if(strcmp(a,c) == 0)
                    {
                        if(dobleotriple->x == posx && dobleotriple->y == posy)
                        {
                            int sumar = 0;
                            sumar = aux->punteo*3;
                            punteoRonda += sumar;
                            //cout<<"posx "<<to_string(posx)<<endl;
                            //cout<<"posy "<<to_string(posy)<<endl;
                            //cout<<"valor de letra triple: "<<to_string(sumar)<<endl;
                            yalosume = true;
                            //system("pause");
                        }

                    }

                    dobleotriple =dobleotriple->sig;
                    indice++;
                }

            }

            if(yalosume==false)
            {
                punteoRonda += aux->punteo;
                //cout<<"valor de letra simple: "<<to_string(aux->punteo);
                //system("pause");
            }


            posy++;
            aux = aux->sig;
        }

    }

    return punteoRonda;
}
