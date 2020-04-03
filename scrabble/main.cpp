#include <iostream>
#include "Cola.h"
using namespace std;

int main()
{
    Cola *n = new Cola();
    n->imprimir();
    n->graficar();
    cout<<to_string(n->tamano);

    return 0;
}
