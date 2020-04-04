#ifndef JUGADOR_H
#define JUGADOR_H
#include "Matriz.h" // matriz que sirve para copiar la matriz general, al validar turno
#include "ListaDoble.h" // lista de fichas de cada jugador
#include "Lista.h" // lista simple de puntajes de mayor a menor por jugador

#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class Jugador
{
    public:
        Jugador();
        virtual ~Jugador();

        void resetearjugador(); // prepara el objeto para proximos juegos

        Matriz* m; // matriz para ejecutar sus movimientos
        ListaDoble* listaFichas; // contiene las fichas de cada jugador
        Lista* puntajesIndividual; // contiene las partidas de cada jugador
        string nombrejugador;
        int punteoAcumulado;




    protected:

    private:
};

#endif // JUGADOR_H
