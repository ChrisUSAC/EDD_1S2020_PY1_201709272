#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <string>
#include "json.hpp"

using json = nlohmann::json;

using namespace std;

class Archivo
{
    public:
        Archivo();
        virtual ~Archivo();

        void leer(string ruta);
        void guardar(json j);

    protected:

    private:
};

#endif // ARCHIVO_H
