#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <string>
#include "json.hpp"

#include "ListaDobleCDiccionario.h"
#include "Matriz.h"

using json = nlohmann::json;

using namespace std;

class Archivo
{
    public:
        Archivo();
        virtual ~Archivo();

        void leer(string ruta,ListaDobleCDiccionario& diccio,Matriz& matrizJuego,ListaDobleCDiccionario& dobleotriple);
        void guardar(json j,ListaDobleCDiccionario& diccio,Matriz& matrizJuego,ListaDobleCDiccionario& dobleotriple);

    protected:

    private:
};

#endif // ARCHIVO_H
