#include <iostream>
#include "ListaDobleCDiccionario.h"
using namespace std;

int main()
{
    ListaDobleCDiccionario* n = new ListaDobleCDiccionario();
    n->insertarFinal("hola");
    n->insertarFinal("como");
    n->insertarFinal("estas");
    n->insertarFinal("el");
    n->insertarFinal("dia");
    n->insertarFinal("de");
    n->imprimir();
    n->graficar();
    return 0;
}
