#include "Registros.h"

Registros::Registros()
{
}

Registros::Registros(string _nombre)
{
    name = _nombre;
}

Registros::~Registros()
{
}

Control::Control()
{

}

Control::Control(string _nombre, int _matricula) : Registros(_nombre)
{
    name = _nombre;
    matricula = _matricula;
}

Cuentas::Cuentas()
{

}

Cuentas::Cuentas(string _nombre, int _matricula) : Registros(_nombre)
{
    name = _nombre;
    matricula = _matricula;
}

Pagos::Pagos()
{

}

Pagos::Pagos(string _nombre, int _matricula) : Registros(_nombre)
{
    name = _nombre;
    matricula = _matricula;
}

void Registros::msg()
{
    std::cout << std::endl;
    std::cout << "Ingrese su matricula de 5 digitos: ";
}

void Registros::msg2()
{
    cout << "Bienvenido " << name << endl;
    cout << "Que desea hacer hoy? " << endl;
}

int Control::getMatricula()
{
    return matricula;
}

int Cuentas::getMatricula()
{
    return matricula;
}

int Pagos::getMatricula()
{
    return matricula;
}

void Control::mP()
{
    cout << "1: Revisar informacion de algun pasajero" << endl;
    cout << "2: Revisar nombres de pasajeros confirmados para un vuelo" << endl;
    cout << "3: Revisar vuelos llenos" << endl;
    cout << "4: Revisar vuelos vacios" << endl;
}

void Cuentas::mP()
{
    cout << "1: Ganancias en boletos comprados" << endl;
    cout << "2: Cantidad de dinero en reembolsos de vuelos cancelados" << endl;
}

void Pagos::mP()
{
    cout << "1: Cancelar un vuelo" << endl;
    cout << "2: Cancelar lugar a un pasajero" << endl;
}

void Registros::desplegarVuelos()
{
    cout << "Seleccione el vuelo" << endl;
    cout << "1: Mayo LAX - MEX" << endl;
    cout << "2: Mayo LAX - SID" << endl;
    cout << "3: Mayo MEX - LAX" << endl;
    cout << "4: Mayo MEX - SID" << endl;
    cout << "5: Mayo SID - MEX" << endl;
    cout << "6: Mayo SID - LAX" << endl;
    cout << "7: Junio LAX - MEX" << endl;
    cout << "8: Junio LAX - SID" << endl;
    cout << "9: Junio MEX - LAX" << endl;
    cout << "10: Junio MEX - SID" << endl;
    cout << "11: Junio SID - MEX" << endl;
    cout << "12: Junio SID - LAX" << endl;
}

unsigned Cuentas::getGanancias()
{
    return ganancias;
}

unsigned Cuentas::getReembolsos()
{
    return reembolsos;
}

unsigned Cuentas::sumarGanancias(float _ganancias)
{
    ganancias = ganancias + _ganancias;
}

unsigned Cuentas::sumarReembolsos(float _reembolsos)
{
    reembolsos = reembolsos + _reembolsos;
}

unsigned Cuentas::restarGanancias(float _reembolsos)
{
    ganancias = ganancias - _reembolsos;
}
