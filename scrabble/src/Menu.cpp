#include "Menu.h"

ArbolABB* arbol = new ArbolABB(); // arbol que guarda los usuarios del juego
ListaDobleCDiccionario* diccio = new ListaDobleCDiccionario(); // diccionario de palabras validas del juego
Matriz* matrizJuego = new Matriz(); // matriz que sera el tablero de juego

Menu::Menu()
{
    this->archivo = new Archivo();
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
            cout<<"Opcion 2";
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
