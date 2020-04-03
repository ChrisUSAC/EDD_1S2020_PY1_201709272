#include <iostream>
#include "Menu.h"
#include "Matriz.h"

using namespace std;

int main()
{
    /*
    Menu* menu = new Menu();
    menu->menu_inicial();
    */
    Matriz* m = new Matriz();


    m->insertarElemento("1","1",0,'a',"doble");
    m->insertarElemento("1","2",0,'u',"triple");
    m->insertarElemento("1","3",0,'t',"");
    m->insertarElemento("1","4",0,'o',"");
    m->graficar();

    return 0;
}
