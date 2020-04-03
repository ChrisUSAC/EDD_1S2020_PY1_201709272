#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <stdlib.h>

//objetos utilizados
#include "Archivo.h"
#include "ArbolABB.h"
#include "ListaDobleCDiccionario.h"
#include "Matriz.h"


using namespace std;

class Menu
{
    public:
        Menu();
        virtual ~Menu();
        void menu_inicial(); // menu que pide la carga del archivo al iniciar la aplicacion
        void menu_cargaArchivo(); // menu principal del juego,
        void menu_juego(); //menu donde permite crear jugadores, seleccionar jugadores para la partida y iniciar juego


        //objetos
        Archivo* archivo; //objeto de tipo archivo para cargar casillas dobles y triples y palabras al diccionario

    protected:

    private:
};

#endif // MENU_H
