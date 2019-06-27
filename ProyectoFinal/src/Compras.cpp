#include "Compras.h"

Compras::Compras()
{
}

Compras::Compras(string _nombre, string _destino, string _actual, int _asiento, int _nT, int _cT, int _nV, float _costo, bool _comprado)
{
    nombre = _nombre;
    asiento = _asiento;
    numeroTarjeta = _nT;
    codigoTarjeta = _cT;
    costo = _costo;
    numeroVuelo = _nV;
    comprado = _comprado;
    destino = _destino;
    actual = _actual;
}

Compras::~Compras()
{
}

void Compras::msg()
{
    std::cout << "Seleccione el uso que dara a la aplicacion: " << std::endl;
    std::cout << "1: Compra" << std::endl;
    std::cout << "2: Cancelacion" << std::endl;
    std::cout << "3: Ver mi vuelo" << std::endl;
    std::cout << std::endl;
}

float Compras::getCosto()
{
    return costo;
}

void Compras::setNumeroTarjeta(int _nT)
{
    numeroTarjeta = _nT;
}

void Compras::setCodigoTarjeta(int _cT)
{
    codigoTarjeta = _cT;
}

void Compras::setCosto(float _costo)
{
    costo = _costo;
}

int Compras::getCodigoTarjeta()
{
    return codigoTarjeta;
}

int Compras::getNumeroTarjeta()
{
    return numeroTarjeta;
}

void Compras::mostrar()
{
    cout << endl;
    cout << "Pasajero: " << nombre << endl;
    cout << "Numero de vuelo: " << numeroVuelo << endl;
    cout << "Vuelo " << actual << " - " << destino << endl;
    cout << "Asiento: " << asiento << endl;
    cout << "Costo: " << costo << " pesos mexicanos" << endl;
    cout << "Pagado con tarjeta: ***" << numeroTarjeta % 1000 << endl;
}

void Compras::cancelar()
{
    comprado = false;
    numeroVuelo = 0;
}
