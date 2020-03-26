#include <iostream>
#include "Lista.h"
#include "NodoLista.h"

using namespace std;

int main()
{
    Lista *a = new Lista();
    a->insertar("a",100);
    a->insertar("d",0);
    a->insertar("f",2);
    a->insertar("Luis",15);
    a->insertar("Mario",10);
    a->insertar("Julio",40);
    a->insertar("Pedro",17);
    a->insertar("Martin",18);
    a->insertar("Chris",3);
    a->graficar();


    return 0;
}
