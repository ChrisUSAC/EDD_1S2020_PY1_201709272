#include <iostream>
#include "ListaDobleC.h"

using namespace std;

int main()
{
    ListaDobleC* n = new ListaDobleC();
    n->insertarFinal("Fos");
    n->insertarFinal("Mario");
    n->insertarFinal("Chris");
    n->insertarFinal("Carlos");
    n->insertarFinal("Juan");

    n->imprimir();
    return 0;
}
