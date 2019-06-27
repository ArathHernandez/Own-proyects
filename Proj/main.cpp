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
        int number;
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
        void setLegendary(bool _true);
        void setNumber(int _num);
        void setName(string _nombre);
        void setType1(string _sType1);
        void setType2(string _sType2);
        void setTotal(int _ac);
        void setDefense(int _def);
        void setAttack(int _atk);
        void setSpAtk(int _sa);
        void setSpDef(int _sd);
        void setHP(int _life);
        void setSpeed(int _rapido);
        void setGeneration(int _gene);
        void buffAtributos();
};

Pokemon::Pokemon()
{

}

Pokemon::~Pokemon()
{
}

Pokemon *pokemones = new Pokemon[721];

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

void Pokemon::setLegendary(bool _true)
{
    legendary = _true;
}

void Pokemon::setNumber(int _num)
{
    number = _num;
}

void Pokemon::setName(string _nombre)
{
    name = _nombre;
}

void Pokemon::setType1(string _sType1)
{
    type1 = _sType1;
}

void Pokemon::setType2(string _sType2)
{
    type2 = _sType2;
}

void Pokemon::setTotal(int _ac)
{
    total = _ac;
}

void Pokemon::setDefense(int _def)
{
    defense = _def;
}

void Pokemon::setAttack(int _atk)
{
    attack = _atk;
}

void Pokemon::setSpAtk(int _sa)
{
    spAtk = _sa;
}

void Pokemon::setSpDef(int _sd)
{
    spDef = _sd;
}

void Pokemon::setHP(int _life)
{
    HP = _life;
}

void Pokemon::setSpeed(int _rapido)
{
    speed = _rapido;
}

void Pokemon::setGeneration(int _gene)
{
    generation = _gene;
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

void setAtributos()
{
    ifstream poks;
    string texto;
    poks.open("pokemon.csv");

    string numero;
    int num = 0;
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

    for(int i= 0; !poks.eof(); i++)
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

        stringstream Aux (numero);
        Aux >> num;
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

        if(sLegendario[0] == 'F')
            (*(pokemones+i)).setLegendary (false);
        else
            (*(pokemones+i)).setLegendary(true);

        (*(pokemones+i)).setNumber(num);
        (*(pokemones+i)).setName(nombre);
        (*(pokemones+i)).setType1(sType1);
        (*(pokemones+i)).setType2(sType2);
        (*(pokemones+i)).setTotal(ac);
        (*(pokemones+i)).setDefense(def);
       (*(pokemones+i)).setAttack(atk);
        (*(pokemones+i)).setSpAtk(sa);
        (*(pokemones+i)).setSpDef(sd);
        (*(pokemones+i)).setHP(life);
        (*(pokemones+i)).setSpeed(rapido);
        (*(pokemones+i)).setGeneration(gene);

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
    //cin >> opcion;

    setAtributos();

    cout << pokemones[1].getName() << endl;

    return 0;
}


