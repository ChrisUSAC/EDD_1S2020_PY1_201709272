#include <iostream>
#include "ListaDobleC.h"
using namespace std;

int main()
{
    ListaDobleC * n = new ListaDobleC();
    n->insertarFinal("Chris");
    n->insertarFinal("Maria");
    n->insertarFinal("Juan");
    n->insertarFinal("Pedro");
    n->insertarFinal("Maro");
    n->insertarFinal("D");
    n->insertarFinal("Ultimo");
    n->graficar();
    return 0;
}
