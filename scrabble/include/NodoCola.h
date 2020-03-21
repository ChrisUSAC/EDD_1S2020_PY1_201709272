#ifndef NODOCOLA_H
#define NODOCOLA_H


class NodoCola
{
    public:

        NodoCola(int punteo,char letra); //metodo constructor del nodo
        virtual ~NodoCola(); //metodo destructor

        NodoCola* siguiente; //puntero del nodo hacia el siguiente
        int punteo; // punteo de la letra.
        char letra; // letra que se almacena.
    protected:

    private:
};

#endif // NODOCOLA_H
