#ifndef REGISTROS_H
#define REGISTROS_H

#include <iostream>
#include "Compras.h"
using namespace std;

class Registros:public Compras
{
    public:
        Registros();
        Registros(string);
        virtual ~Registros();
        void msg();
        void msg2();
        void desplegarVuelos();
        string name;
    private:
};

class Control:public Registros
{
    public:
        Control();
        Control(string, int);
        int getMatricula();
        void mP();
    private:
        int matricula;
};

class Cuentas:public Registros
{
    public:
        Cuentas();
        Cuentas(string, int);
        int getMatricula();
        unsigned getGanancias();
        unsigned getReembolsos();
        unsigned restarGanancias(float);
        unsigned sumarGanancias(float);
        unsigned sumarReembolsos(float);
        void mP();
    private:
        int matricula;
        unsigned ganancias = 0;
        unsigned reembolsos = 0;
};

class Pagos:public Registros
{
    public:
        Pagos();
        Pagos(string, int);
        int getMatricula();
        void mP();
    private:
        int matricula;
};

#endif // REGISTROS_H
