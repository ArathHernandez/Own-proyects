#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
using namespace std;

class Pokemon
{
    private:
        string name;
        string type1;
        string type2;
        int total;
        int attack;
        int spAtk;
        int defense;
        int spDef;
        int HP;
        int speed;
        int generation;
        bool legendary;
    public:
        Pokemon();
        ~Pokemon();
        string getName();
        string getType1();
        string getType2();
        int getTotal();
        int getAttack();
        int getSpAtk();
        int getDefense();
        int getSpDef();
        int getHP();
        int getSpeed();
        int getGeneration();
        bool getLegendary();
        void setAtributos();
        void buffAtributos();
};

Pokemon::Pokemon()
{

}

Pokemon::~Pokemon()
{
}

Pokemon pokemones[721];

string Pokemon::getName()
{
    return name;
}

string Pokemon::getType1()
{
    return type1;
}

string Pokemon::getType2()
{
    return type2;
}

int Pokemon::getTotal()
{
    return total;
}

int Pokemon::getAttack()
{
    return attack;
}

int Pokemon::getDefense()
{
    return defense;
}

int Pokemon::getGeneration()
{
    return generation;
}

int Pokemon::getHP()
{
    return HP;
}

bool Pokemon::getLegendary()
{
    return legendary;
}

int Pokemon::getSpAtk()
{
    return spAtk;
}

int Pokemon::getSpDef()
{
    return spDef;
}

int Pokemon::getSpeed()
{
    return speed;
}

void Pokemon::buffAtributos()
{
    attack = (attack*0.25) + attack;
    defense = (defense*0.25) + defense;
    spAtk = (spAtk*0.25) + spAtk;
    spDef = (spDef*0.25) + spDef;
    HP = (HP*0.25) + HP;
    speed = (speed*0.25) + speed;
    total = attack + defense + spAtk + spDef + HP + speed;
}

void Pokemon::setAtributos()
{
    ifstream poks;
    poks.open("pokemon.csv", ios::in);

    int i = 0;

    string numero;
    string nombre;
    string tipo1;
    string tipo2;
    string acumulado;
    int ac = 0;
    string ataque;
    int atk = 0;
    string especialAtaque;
    int sa = 0;
    string defensa;
    int def = 0;
    string especialDefensa;
    int sd = 0;
    string vida;
    int life = 0;
    string velocidad;
    int rapido = 0;
    string generacion;
    int gene = 0;
    string legendario;

    while(!poks.eof())
    {
        getline(poks, numero, ',');
        getline(poks, nombre, ',');
        getline(poks, tipo1, ',');
        getline(poks, tipo2, ',');
        getline(poks, acumulado, ',');
        getline(poks, vida, ',');
        getline(poks, ataque, ',');
        getline(poks, defensa, ',');
        getline(poks, especialAtaque, ',');
        getline(poks, especialDefensa, ',');
        getline(poks, velocidad, ',');
        getline(poks, generacion, ',');
        getline(poks, legendario, '\n');

        string sName = nombre;
        string sType1 = tipo1;
        string sType2 = tipo2;
        stringstream Aux2 (acumulado);
        Aux2 >> ac;
        stringstream Aux3 (vida);
        Aux3 >> life;
        stringstream Aux4 (ataque);
        Aux4 >> atk;
        stringstream Aux5 (defensa);
        Aux5 >> def;
        stringstream Aux6 (especialAtaque);
        Aux6 >> sa;
        stringstream Aux7 (especialDefensa);
        Aux7 >> sd;
        stringstream Aux8 (velocidad);
        Aux8 >> rapido;
        stringstream Aux9 (generacion);
        Aux9 >> gene;
        string sLegendario = legendario;

        if(i>0)
        {
        if(sLegendario[0] == 'F')
            pokemones[i].legendary = false;
        else
            pokemones[i].legendary = true;

        pokemones[i].name = nombre;
        pokemones[i].type1 = sType1;
        pokemones[i].type2 = sType2;
        pokemones[i].total = ac;
        pokemones[i].defense = def;
        pokemones[i].attack = atk;
        pokemones[i].spAtk = sa;
        pokemones[i].spDef = sd;
        pokemones[i].HP = life;
        pokemones[i].speed = rapido;
        pokemones[i].generation = gene;
        }
        i++;
    }

    poks.close();
}

int main()
{
    int opcion;

    cout << "Bienvenido a PokeDerp v1.0 \n" << endl;
    cout << "1: Listar pokemon por ID" << endl;
    cout << "2: Listar cada tipo con su cantidad" << endl;
    cout << "3: Simular batalla  \n" << endl;
    cout << "Elige la opcion que desees: ";
    cin >> opcion;

    if(opcion == 1)
        cout << pokemones[1].getName() << endl;

    return 0;
}
