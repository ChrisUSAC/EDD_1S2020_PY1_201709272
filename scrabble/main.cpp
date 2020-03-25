#include <iostream>
#include "ArbolABB.h"
#include "nodoABB.h"
using namespace std;

int main()
{
    ArbolABB* n = new  ArbolABB();
    nodoABB* nu = new nodoABB("Daniel");
    nodoABB* a = new nodoABB("Carmen");
    nodoABB* b = new nodoABB("Luis");
    nodoABB* c = new nodoABB("Aymme");
    nodoABB* d = new nodoABB("Berceli");
    nodoABB* e = new nodoABB("Gabriela");

    n->add(nu);
    n->add(a);
    n->add(b);
    n->add(c);
    n->add(d);
    n->add(e);
    n->graph();

    return 0;
}
