#include <iostream>
#include "Archivo.h"
using namespace std;

int main()
{
    Archivo* n = new Archivo();
    n->leer("b.json");

    return 0;
}
