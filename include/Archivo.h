#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <string>

using namespace std;

class Archivo
{
    public:
        Archivo();
        virtual ~Archivo();

        string entrada,definicion;

        void Aregar();
        void leer();
        void modificar();
        void buscar();

    protected:

    private:
};

#endif // ARCHIVO_H
