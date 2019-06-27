#ifndef COMPRAS_H
#define COMPRAS_H

#include <iostream>
using namespace std;

class Compras
{
    public:
        Compras();
        Compras(string, string, string, int, int, int, int, float, bool);
        virtual ~Compras();
        void msg();
        float getCosto();
        void setNumeroTarjeta(int);
        void setCodigoTarjeta(int);
        void setCosto(float);
        void mostrar();
        void cancelar();
        int getNumeroTarjeta();
        int getCodigoTarjeta();
        int asiento;
        int numeroVuelo;
        string nombre;
        string destino;
        string actual;
        bool comprado = false;

    private:
        int numeroTarjeta;
        int codigoTarjeta;
        float costo;
};

#endif // COMPRAS_H
