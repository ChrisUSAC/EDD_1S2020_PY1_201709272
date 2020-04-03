#include <iostream>
#include "Cola.h"
using namespace std;

int main()
{
    Cola* n = new Cola();
    n->enqueue(1,'v');
    n->enqueue(3,'c');
    n->enqueue(4,'d');
    n->enqueue(2,'e');
    n->enqueue(6,'g');
    n->enqueue(5,'r');
    n->dequeue();
    n->enqueue(1,'v');
    n->imprimir();
    n->graficar();
    return 0;
}
