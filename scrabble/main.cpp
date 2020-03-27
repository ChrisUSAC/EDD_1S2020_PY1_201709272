#include <iostream>
#include "ListaDoble.h"

using namespace std;

int main()
{
    ListaDoble* n = new ListaDoble();
    n->insertarFinal('f',1);
    n->insertarFinal('b',2);
    n->insertarFinal('d',3);
    n->insertarFinal('w',4);
    n->insertarFinal('e',5);
    n->imprimir();
    n->graficar();
    return 0;
}
