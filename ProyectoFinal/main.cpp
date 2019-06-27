/*
    Proyecto Final POO
    Erbey Arath Hernandez Villarreal
    A00825343

    El proyecto final consiste en una aplicacion de una aerolinea que pueda ser utilizada de 4 diferentes maneras:
    1. Persona que busca comprar boleto.
    2. Personal que trabaja teniendo registro de los vuelos.

    NOTA: El numero maximo de pasajeros sera 5 (al ser aviones de lujo).
    NOTA 2: Funciona como base de datos, por lo cual de querer comprobar el guardado es necesario
    seguir en la app hasta que ya no necesite revisar mas.

    Matriculas de trabajadores:
    1. 54782
    2. 98249
    3. 10837
*/
#include <iostream>
#include <exception>
#include <string>
#include <string.h>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include "Compras.h"
#include "Registros.h"
using namespace std;

Compras mayoLAXMEX[5];
Compras junioLAXMEX[5];
Compras mayoLAXSID[5];
Compras junioLAXSID[5];
Compras mayoMEXLAX[5];
Compras junioMEXLAX[5];
Compras mayoMEXSID[5];
Compras junioMEXSID[5];
Compras mayoSIDLAX[5];
Compras junioSIDLAX[5];
Compras mayoSIDMEX[5];
Compras junioSIDMEX[5];
Control trabajador1 ("Alberto", 54782);
Cuentas trabajador2 ("Juan", 98249);
Pagos trabajador3 ("Ramon", 10837);
int lleno = 0;
int vacio = 0;

class UnvalidException : public std::exception
{
    public:
    const char* what() const throw(){
    return "Numero/Codigo no valido";}
};

class CompleteException : public std::exception
{
    public:
    const char* what() const throw(){
    return "Todos los asientos del vuelo estan ocupados";}
};

class NotMoneyException : public std::exception
{
    public:
    const char* what() const throw(){
    return "Su tarjeta no cuenta con los recursos necesarios";}
};

class NotAcceptedException : public std::exception
{
    public:
    const char* what() const throw(){
    return "Su informacion no fue valida, vuelva a intentar";}
};

void comprando(Compras viajes[5], string _destino, string _actual)
{
    int conteo = 0;
    char letra = 0;
    int numero = 0;

    for(int i = 0; i < 5; i++)
    {
        (viajes[i].comprado) ? conteo++ : i = 6;
    }

    if(conteo == 5)
    {
        throw CompleteException();
    }
    else
    {
        cout << endl;
        cout << "El costo de viaje es: " << viajes[0].getCosto() << " pesos mexicanos " << endl;
        cout << endl;
        cout << "Continuar con la compra? 'S' = Si , 'N' = No" << endl;
        cin >> letra;
        cout << endl;

        if(letra == 'S')
        {
            cout << "Ingrese su nombre completo: ";
            cin.ignore();
            getline(cin, viajes[conteo].nombre, '\n');

            cout << "Ingrese su tarjeta de 6 digitos: ";
            cin >> numero;
            if(numero < 100000 || numero > 999999)
                throw NotAcceptedException();
            viajes[conteo].setNumeroTarjeta(numero);

            cout << "Ingrese su codigo NIP de 3 digitos: ";
            cin >> numero;
            if(numero < 100 || numero > 999)
                throw NotAcceptedException();
            if(numero % 5 == 0)
                throw NotMoneyException();
            viajes[conteo].setCodigoTarjeta(numero);
            cout << endl;

            viajes[conteo].numeroVuelo = 10000 + rand() % (100000 - 10000);
            viajes[conteo].asiento = conteo+1;

            cout << "COMPRA REALIZADA" << endl;
            cout << "Informacion de vuelo" << endl;
            cout << _actual << " - " << _destino << endl;
            cout << "Nombre del pasajero: " << viajes[conteo].nombre << endl;
            cout << "Numero de vuelo: " << viajes[conteo].numeroVuelo << endl;
            cout << "Numero de asiento: " << viajes[conteo].asiento << endl;
            viajes[conteo].comprado = true;
            viajes[conteo].destino = _destino;
            viajes[conteo].actual = _actual;
            trabajador2.sumarGanancias(viajes[conteo].getCosto());
            }
            else if(letra == 'N')
            {
            }
            else
                throw UnvalidException();
    }
}

template <typename Info>
void comparar(const Info& T)
{
    try{
    for(int i = 0; i < 5; i++)
    {
        if(T == mayoLAXMEX[i].numeroVuelo){
            mayoLAXMEX[i].mostrar();
            return;}
        else if(T == mayoLAXSID[i].numeroVuelo){
            mayoLAXSID[i].mostrar();
            return;}
        else if(T == mayoMEXLAX[i].numeroVuelo){
            mayoMEXLAX[i].mostrar();
            return;}
        else if(T == mayoMEXSID[i].numeroVuelo){
            mayoMEXSID[i].mostrar();
            return;}
        else if(T == mayoSIDLAX[i].numeroVuelo){
            mayoSIDLAX[i].mostrar();
            return;}
        else if(T == mayoSIDMEX[i].numeroVuelo){
            mayoSIDMEX[i].mostrar();
            return;}
        else if(T == junioLAXMEX[i].numeroVuelo){
            junioLAXMEX[i].mostrar();
            return;}
        else if(T == junioLAXSID[i].numeroVuelo){
            junioLAXSID[i].mostrar();
            return;}
        else if(T == junioMEXLAX[i].numeroVuelo){
            junioMEXLAX[i].mostrar();
            return;}
        else if(T == junioMEXSID[i].numeroVuelo){
            junioMEXSID[i].mostrar();
            return;}
        else if(T == junioSIDLAX[i].numeroVuelo){
            junioSIDLAX[i].mostrar();
            return;}
        else if(T == junioSIDMEX[i].numeroVuelo){
            junioSIDMEX[i].mostrar();
            return;}
    }

    throw NotAcceptedException();
    }

    catch(NotAcceptedException &e)
    {
        cout << endl;
        cout << e.what() << endl;
    }
}

template <typename Cancel>
void eliminar(const Cancel& T)
{
    try{
    for(int i = 0; i < 5; i++)
    {
        if(T == mayoLAXMEX[i].numeroVuelo){
            mayoLAXMEX[i].cancelar();
            trabajador2.restarGanancias(mayoLAXMEX[i].getCosto());
            trabajador2.sumarReembolsos(mayoLAXMEX[i].getCosto());
            return;}
        else if(T == mayoLAXSID[i].numeroVuelo){
            mayoLAXSID[i].cancelar();
            trabajador2.restarGanancias(mayoLAXSID[i].getCosto());
            trabajador2.sumarReembolsos(mayoLAXSID[i].getCosto());
            return;}
        else if(T == mayoMEXLAX[i].numeroVuelo){
            mayoMEXLAX[i].cancelar();
            trabajador2.restarGanancias(mayoMEXLAX[i].getCosto());
            trabajador2.sumarReembolsos(mayoMEXLAX[i].getCosto());
            return;}
        else if(T == mayoMEXSID[i].numeroVuelo){
            mayoMEXSID[i].cancelar();
            trabajador2.restarGanancias(mayoMEXSID[i].getCosto());
            trabajador2.sumarReembolsos(mayoMEXSID[i].getCosto());
            return;}
        else if(T == mayoSIDLAX[i].numeroVuelo){
            mayoSIDLAX[i].cancelar();
            trabajador2.restarGanancias(mayoSIDLAX[i].getCosto());
            trabajador2.sumarReembolsos(mayoSIDLAX[i].getCosto());
            return;}
        else if(T == mayoSIDMEX[i].numeroVuelo){
            mayoSIDMEX[i].cancelar();
            trabajador2.restarGanancias(mayoSIDMEX[i].getCosto());
            trabajador2.sumarReembolsos(mayoSIDMEX[i].getCosto());
            return;}
        else if(T == junioLAXMEX[i].numeroVuelo){
            junioLAXMEX[i].cancelar();
            trabajador2.restarGanancias(junioLAXMEX[i].getCosto());
            trabajador2.sumarReembolsos(junioLAXMEX[i].getCosto());
            return;}
        else if(T == junioLAXSID[i].numeroVuelo){
            junioLAXSID[i].cancelar();
            trabajador2.restarGanancias(junioLAXSID[i].getCosto());
            trabajador2.sumarReembolsos(junioLAXSID[i].getCosto());
            return;}
        else if(T == junioMEXLAX[i].numeroVuelo){
            junioMEXLAX[i].cancelar();
            trabajador2.restarGanancias(junioMEXLAX[i].getCosto());
            trabajador2.sumarReembolsos(junioMEXLAX[i].getCosto());
            return;}
        else if(T == junioMEXSID[i].numeroVuelo){
            junioMEXSID[i].cancelar();
            trabajador2.restarGanancias(junioMEXSID[i].getCosto());
            trabajador2.sumarReembolsos(junioMEXSID[i].getCosto());
            return;}
        else if(T == junioSIDLAX[i].numeroVuelo){
            junioSIDLAX[i].cancelar();
            trabajador2.restarGanancias(junioSIDLAX[i].getCosto());
            trabajador2.sumarReembolsos(junioSIDLAX[i].getCosto());
            return;}
        else if(T == junioSIDMEX[i].numeroVuelo){
            junioSIDMEX[i].cancelar();
            trabajador2.restarGanancias(junioSIDMEX[i].getCosto());
            trabajador2.sumarReembolsos(junioSIDMEX[i].getCosto());
            return;}
    }

    throw NotAcceptedException();
    }

    catch(NotAcceptedException &f)
    {
        cout << endl;
        cout << f.what() << endl;
    }
}

void mostrarPasajeros(Compras viajes[5])
{
    for(int i = 0; i < 5; i++)
    {
        cout << "Asiento " << i+1 << " : ";
        if(viajes[i].comprado)
            cout << viajes[i].nombre << endl;
        else
            cout << "NO COMPRADO" << endl;
    }
}

int capacidadVuelos(Compras viajes[5])
{
    int contar = 0;

    for(int i = 0; i < 5; i++)
    {
        if(viajes[i].comprado)
            contar++;
    }

    if(contar == 5)
        lleno++;
    else if(contar == 0)
        vacio++;

    return contar;
}

void eliminarTodos(Compras viajes[5])
{
    float perdidasTotales = 0;

    for(int i = 0; i < 5; i++)
    {
        if(viajes[i].comprado)
        {
            viajes[i].comprado = false;
            viajes[i].numeroVuelo = 0;
            trabajador2.restarGanancias(viajes[i].getCosto());
            trabajador2.sumarReembolsos(viajes[i].getCosto());
            perdidasTotales = perdidasTotales + viajes[i].getCosto();
        }
    }

    cout << endl;
    cout << "Se reembolsaron en total: " << perdidasTotales << endl;
}

int main()
{
    srand(time(NULL));
    int uso, numero;
    char letra, terminado;
    string destino, actual, nombre;

    for(int i = 0; i < 5; i++)
    {
        mayoLAXMEX[i].setCosto(15500.99);
        junioLAXMEX[i].setCosto(11000.50);
        mayoLAXSID[i].setCosto(33120.80);
        junioLAXSID[i].setCosto(25200.10);
        mayoMEXLAX[i].setCosto(19320.30);
        junioMEXLAX[i].setCosto(13110);
        mayoMEXSID[i].setCosto(30900.99);
        junioMEXSID[i].setCosto(22100);
        mayoSIDLAX[i].setCosto(31500.75);
        junioSIDLAX[i].setCosto(27150.60);
        mayoSIDMEX[i].setCosto(26100);
        junioSIDMEX[i].setCosto(19450.45);
    }

    cout << "Bienvenido a la aerolinea '3 destinos'" << endl;
    cout << endl;

    while(terminado != 'N'){
    try{
    cout << "Seleccione la manera de uso que dara a la aplicacion:" << endl;
    cout << "1: Compras" << endl;
    cout << "2: Personal" << endl;
    cout << endl;

    cin >> uso;
    cout << endl;

    if(uso == 1)
    {
        mayoLAXMEX[0].msg();
        cin >> numero;
        cout << endl;

        if(numero == 1)
        {
            cout << "El codigo para mayo es 'M' y para junio es 'J'" << endl;
            cout << "Escriba el codigo del mes planeado para viajar: ";
            cin >> letra;
            cout << endl;

            cout << "El codigo para Los Angeles es LAX, para CDMX es MEX y para Sidney es SID" << endl;
            cout << "Escriba el lugar de destino: ";
            cin >> destino;
            cout << "Escriba su lugar actual: ";
            cin >> actual;

            if(letra == 'M')
            {
                if(destino == "LAX")
                {
                    if(actual == "MEX")
                    {
                        comprando(mayoMEXLAX, destino, actual);
                    }
                    else if(actual == "SID")
                    {
                        comprando(mayoSIDLAX, destino, actual);
                    }
                    else
                        throw UnvalidException();
                }
                else if(destino == "MEX")
                {
                    if(actual == "LAX")
                    {
                        comprando(mayoLAXMEX, destino, actual);
                    }
                    else if(actual == "SID")
                    {
                        comprando(mayoSIDMEX, destino, actual);
                    }
                    else
                        throw UnvalidException();
                }
                else if(destino == "SID")
                {
                    if(actual == "LAX")
                    {
                        comprando(mayoLAXSID, destino, actual);
                    }
                    else if(actual == "MEX")
                    {
                        comprando(mayoMEXSID, destino, actual);
                    }
                    else
                        throw UnvalidException();
                }
                else
                    throw UnvalidException();
            }
            else if(letra == 'J')
            {
                if(destino == "LAX")
                {
                    if(actual == "MEX")
                    {
                        comprando(junioMEXLAX, destino, actual);
                    }
                    else if(actual == "SID")
                    {
                        comprando(junioSIDLAX, destino, actual);
                    }
                    else
                        throw UnvalidException();
                }
                else if(destino == "MEX")
                {
                    if(actual == "LAX")
                    {
                        comprando(junioLAXMEX, destino, actual);
                    }
                    else if(actual == "SID")
                    {
                        comprando(junioSIDMEX, destino, actual);
                    }
                    else
                        throw UnvalidException();
                }
                else if(destino == "SID")
                {
                    if(actual == "LAX")
                    {
                        comprando(junioLAXSID, destino, actual);
                    }
                    else if(actual == "MEX")
                    {
                        comprando(junioMEXSID, destino, actual);
                    }
                    else
                        throw UnvalidException();
                }
                else
                    throw UnvalidException();
            }
            else
                throw UnvalidException();
        }
        else if(numero == 2)
        {
            cout << "Escriba su numero de vuelo: ";
            cin >> numero;
            cout << endl;

            cout << "Seguro de cancelar el vuelo?" << endl;
            cout << "'S' = Si , 'N' = No: ";
            cin >> letra;

            (letra == 'S') ? eliminar(numero) : comparar(numero);
        }
        else if(numero == 3)
        {
            cout << "Escriba su numero de vuelo: ";
            cin >> numero;
            comparar(numero);
        }
        else
            throw UnvalidException();
    }
    else if(uso == 2)
    {
        trabajador1.msg();
        cin >> numero;
        cout << endl;

        if(numero == trabajador1.getMatricula())
        {
            trabajador1.msg2();
            trabajador1.mP();
            cout << endl;

            cin >> numero;
            cout << endl;

            if(numero == 1)
            {
                cout << "Numero de vuelo del pasajero: " << endl;
                cin >> numero;
                cout << endl;
                comparar(numero);
            }
            else if(numero == 2)
            {
                trabajador1.desplegarVuelos();
                cout << endl;
                cin >> numero;
                cout << endl;

                if(numero == 1)
                    mostrarPasajeros(mayoLAXMEX);
                else if(numero == 2)
                    mostrarPasajeros(mayoLAXSID);
                else if(numero == 3)
                    mostrarPasajeros(mayoMEXLAX);
                else if(numero == 4)
                    mostrarPasajeros(mayoMEXSID);
                else if(numero == 5)
                    mostrarPasajeros(mayoSIDMEX);
                else if(numero == 6)
                    mostrarPasajeros(mayoSIDLAX);
                else if(numero == 7)
                    mostrarPasajeros(junioLAXMEX);
                else if(numero == 8)
                    mostrarPasajeros(junioLAXSID);
                else if(numero == 9)
                    mostrarPasajeros(junioMEXLAX);
                else if(numero == 10)
                    mostrarPasajeros(junioMEXSID);
                else if(numero == 11)
                    mostrarPasajeros(junioSIDMEX);
                else if(numero == 12)
                    mostrarPasajeros(junioSIDLAX);
                else
                    throw UnvalidException();
            }
            else if(numero == 3)
            {
                lleno = 0;

                cout << "Vuelos llenos" << endl;
                cout << endl;

                if(capacidadVuelos(mayoLAXMEX) == 5)
                    cout << lleno << ". mayo LAX - MEX" << endl;
                if(capacidadVuelos(mayoLAXSID) == 5)
                    cout << lleno << ". mayo LAX - SID" << endl;
                if(capacidadVuelos(mayoMEXLAX) == 5)
                    cout << lleno << ". mayo MEX - LAX" << endl;
                if(capacidadVuelos(mayoMEXSID) == 5)
                    cout << lleno << ". mayo MEX - SID" << endl;
                if(capacidadVuelos(mayoSIDMEX) == 5)
                    cout << lleno << ". mayo SID - MEX" << endl;
                if(capacidadVuelos(mayoSIDLAX) == 5)
                    cout << lleno << ". mayo SID - LAX" << endl;
                if(capacidadVuelos(junioLAXMEX) == 5)
                    cout << lleno << ". junio LAX - MEX" << endl;
                if(capacidadVuelos(junioLAXSID) == 5)
                    cout << lleno << ". junio LAX - SID" << endl;
                if(capacidadVuelos(junioMEXLAX) == 5)
                    cout << lleno << ". junio MEX - LAX" << endl;
                if(capacidadVuelos(junioMEXSID) == 5)
                    cout << lleno << ". junio MEX - SID" << endl;
                if(capacidadVuelos(junioSIDMEX) == 5)
                    cout << lleno << ". junio SID - MEX" << endl;
                if(capacidadVuelos(junioSIDLAX) == 5)
                    cout << lleno << ". junio SID - LAX" << endl;
                if(lleno == 0)
                    cout << "No hay vuelos llenos" << endl;
                if(lleno == 12)
                    cout << "Todos los vuelos estan llenos" << endl;
            }
            else if(numero == 4)
            {
                vacio = 0;

                cout << "Vuelos vacios" << endl;
                cout << endl;
                if(capacidadVuelos(mayoLAXMEX) == 0)
                    cout << vacio << ". mayo LAX - MEX" << endl;
                if(capacidadVuelos(mayoLAXSID) == 0)
                    cout << vacio << ". mayo LAX - SID" << endl;
                if(capacidadVuelos(mayoMEXLAX) == 0)
                    cout << vacio << ". mayo MEX - LAX" << endl;
                if(capacidadVuelos(mayoMEXSID) == 0)
                    cout << vacio << ". mayo MEX - SID" << endl;
                if(capacidadVuelos(mayoSIDMEX) == 0)
                    cout << vacio << ". mayo SID - MEX" << endl;
                if(capacidadVuelos(mayoSIDLAX) == 0)
                    cout << vacio << ". mayo SID - LAX" << endl;
                if(capacidadVuelos(junioLAXMEX) == 0)
                    cout << vacio << ". junio LAX - MEX" << endl;
                if(capacidadVuelos(junioLAXSID) == 0)
                    cout << vacio << ". junio LAX - SID" << endl;
                if(capacidadVuelos(junioMEXLAX) == 0)
                    cout << vacio << ". junio MEX - LAX" << endl;
                if(capacidadVuelos(junioMEXSID) == 0)
                    cout << vacio << ". junio MEX - SID" << endl;
                if(capacidadVuelos(junioSIDMEX) == 0)
                    cout << vacio << ". junio SID - MEX" << endl;
                if(capacidadVuelos(junioSIDLAX) == 0)
                    cout << vacio << ". junio SID - LAX" << endl;
                if(vacio == 0)
                    cout << "No hay vuelos vacios" << endl;
                if(vacio == 12)
                    cout << "Todos los vuelos estan vacios" << endl;
            }
            else
                throw UnvalidException();
        }
        else if(numero == trabajador2.getMatricula())
        {
            trabajador2.msg2();
            trabajador2.mP();
            cout << endl;

            cin >> numero;
            cout << endl;

            if(numero == 1)
                cout << trabajador2.getGanancias() << " pesos mexicanos" << endl;
            else if(numero == 2)
                cout << trabajador2.getReembolsos() << " pesos mexicanos" << endl;
            else
                throw UnvalidException();
        }
        else if(numero == trabajador3.getMatricula())
        {
            trabajador3.msg2();
            trabajador3.mP();
            cout << endl;

            cin >> numero;
            cout << endl;

            if(numero == 1)
            {
                trabajador3.desplegarVuelos();

                cin >> numero;
                cout << endl;

                if(numero == 1)
                    eliminarTodos(mayoLAXMEX);
                else if(numero == 2)
                    eliminarTodos(mayoLAXSID);
                else if(numero == 3)
                    eliminarTodos(mayoMEXLAX);
                else if(numero == 4)
                    eliminarTodos(mayoMEXSID);
                else if(numero == 5)
                    eliminarTodos(mayoSIDMEX);
                else if(numero == 6)
                    eliminarTodos(mayoSIDLAX);
                else if(numero == 7)
                    eliminarTodos(junioLAXMEX);
                else if(numero == 8)
                    eliminarTodos(junioLAXSID);
                else if(numero == 9)
                    eliminarTodos(junioMEXLAX);
                else if(numero == 10)
                    eliminarTodos(junioMEXSID);
                else if(numero == 11)
                    eliminarTodos(junioSIDMEX);
                else if(numero == 12)
                    eliminarTodos(junioSIDLAX);
                else
                    throw UnvalidException();
            }
            else if(numero == 2)
            {
                cout << "Escriba su numero de vuelo: ";
                cin >> numero;
                cout << endl;

                cout << "Seguro de cancelar el vuelo?" << endl;
                cout << "'S' = Si , 'N' = No: ";
                cin >> letra;

                (letra == 'S') ? eliminar(numero) : comparar(numero);
            }
            else
                throw UnvalidException();
        }
        else
            throw NotAcceptedException();
    }
    else
        throw UnvalidException();}

    catch (UnvalidException &a)
    {
        cout << endl;
        cout << a.what() << endl;
    }

    catch (CompleteException &b)
    {
        cout << endl;
        cout << b.what() << endl;
    }

    catch (NotMoneyException &c)
    {
        cout << endl;
        cout << c.what() << endl;
    }

    catch (NotAcceptedException &d)
    {
        cout << endl;
        cout << d.what() << endl;
    }

    cout << endl;
    cout << "Continuar en la app?" << endl;
    cout << "'S' = Si , 'N' = No: ";
    cin >> terminado;
    cout << endl;
    }

    cout << "Muchas gracias por visitar la app" << endl;

    return 0;
}
