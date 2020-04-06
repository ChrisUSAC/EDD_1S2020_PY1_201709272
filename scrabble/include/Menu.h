#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <conio.h>

//objetos utilizados
#include "Archivo.h"
#include "ArbolABB.h"
#include "nodoABB.h"
#include "ListaDobleCDiccionario.h"
#include "Matriz.h"
#include "cstring" //biblioteca para comparar strings
#include "string"
#include "ListaDobleC.h" // lista de usuarios del juego
#include "NodoCola.h" // utilizado para llenar la cola de fichas de los jugadores
#include "Cola.h" // cola de fichas del juego
#include "Jugador.h"
#include "NodoListaDoble.h"

#include "ListaJugador.h" // lista que sirve para el top y para puntajes individuales
#include "NodoListaJugador.h"

#include "ListaSRecorrido.h"

using namespace std;

class Menu
{
    public:
        Menu();
        virtual ~Menu();
        void menu_inicial(); // menu que pide la carga del archivo al iniciar la aplicacion
        void menu_cargaArchivo(); // menu principal del juego,
        void menu_juego(); //menu donde permite crear jugadores, seleccionar jugadores para la partida y iniciar juego
        void menu_reportes(); // menu que despliega los reportes de la ultima partida jugada

        void menu_IniciarJuego(); // menu donde se seleeccionan los dos jugadores a participar
        void turnoJugador1(); //turno jugador 1
        void turnoJugador2(); //turno jugador 2

        void menuAuxiliarPonerFicchas();
        void menuAuxiliarPonerFicchas2();
        int insertandoPalabra(int cantidadLetras, ListaDoble& letrasColocar); // se coloca en el tablero ya sea en posicion vertical u horizontal
        int insertandoPalabra2(int cantidadLetras, ListaDoble& letrasColocar); // se coloca en el tablero ya sea en posicion vertical u horizontal


        //objetos
        Archivo* archivo; //objeto de tipo archivo para cargar casillas dobles y triples y palabras al diccionario

        nodoABB* nuevo;
        NodoCola * ficha; // usado para repartir fichas
        NodoListaDoble* fichaRegreso; // usado para extrar la informacion e insertarla en la cola nuevamente


    protected:

    private:
};

#endif // MENU_H
