#include "Archivo.h"
#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

Archivo::Archivo()
{
    //ctor
}

Archivo::~Archivo()
{
    //dtor
}

//-----------------------------------------------------------------------------------------------------------------
void Archivo::leer(string ruta,ListaDobleCDiccionario& diccio,Matriz& matrizJuego,ListaDobleCDiccionario& dobleotriple)
{

    ifstream archivo; //variable que facilita la lectura del archivo
    string rutaRelativa = "carga\\"+ruta; //modelo para ejecucion en codeblocks
    json jj;

    cout<<"rutaRelativa : "<<rutaRelativa<<endl;

    const char *rutaR = rutaRelativa.c_str(); // se para el string a const char para el metodo open

    //abre el archivo
    archivo.open(rutaR, ios::in);

    cout<<"\n";
    if(archivo.fail())
    {
        cout<<"Error, no se encontro el archivo"<<endl;

    }
    else
    {
    //si se abre bien el archivo entonces jalar los datos al objeto json

    archivo >> jj;
    }


    archivo.close();//cierra el archivo

    //metodo que crea los objetos en memoria
    guardar(jj,diccio,matrizJuego,dobleotriple);

}

//-----------------------------------------------------------------------------------------------------------------
//metodo para guardar los objetos en las estructuras
void Archivo::guardar(json j,ListaDobleCDiccionario& diccio,Matriz& matrizJuego,ListaDobleCDiccionario& dobleotriple)
{
    int dimension; //variable que guarda la dimension del tablero
    int doblex;
    int dobley;

    int triplex;
    int tripley;
    string palabra;

    dimension = j["dimension"];

    cout << "dimension: " << dimension << endl; // dimension del tablero


        //for para casillas dobles
        //cout<<"casillas dobles: "<<endl;
        for(const auto& dobles : j["casillas"]["dobles"])
        {
            doblex = dobles["x"];
            dobley = dobles["y"];

            cout<<doblex<<endl;
            cout<<dobley<<endl;
            cout<<"\n"<<endl;
            matrizJuego.insertarElemento(to_string(dobley),to_string(doblex),0,' ',"doble");
            dobleotriple.insertarFinalCoordenadaEspecial("doble",doblex,dobley);


        }
        //for para casillas triples
        //cout<<"casillas triples: "<<endl;
        for(const auto& triples : j["casillas"]["triples"])
        {
            triplex = triples["x"];
            tripley = triples["y"];

            cout<<triplex<<endl;
            cout<<tripley<<endl;
            cout<<"\n"<<endl;
            matrizJuego.insertarElemento(to_string(tripley),to_string(triplex),0,' ',"triple");
            dobleotriple.insertarFinalCoordenadaEspecial("triple",triplex,tripley);

        }

        // for para palabras del diccionario
        cout<<"Diccionario: "<<endl;
        for(const auto& diccionario : j["diccionario"])
        {
            palabra = diccionario["palabra"];
            //cout<<"Diccionario: "<<endl;
            cout<<palabra<<endl;
            diccio.insertarFinal(palabra);

        }
        //diccio.graficar();
        //matrizJuego.graficar();

    system("cls");
    cout<<"Carga Realizada Exitosamente"<<endl;



}
