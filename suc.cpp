#include "../main.h"

bautura :: bautura(): produs() ///
{
    denumire = "";
    inaltime = 0;
}

bautura :: bautura(std :: string den, unsigned int val, double p): produs(0, std :: vector<ingredient>()) ///
{
    denumire = den;
    inaltime = val;
    pret = p;
}

bautura :: bautura(const bautura& p) ///
{
    denumire = p.denumire;
    inaltime = p.inaltime;
    pret = p.pret;
}

bautura& bautura :: operator=(bautura const &p) ///
{
    this->pret = p.pret;
    this->denumire = p.denumire;
    this->inaltime = p.inaltime;
    return *this;
};

unsigned int  bautura :: getInaltime() const ///
{
    return inaltime;
}

void bautura :: setInaltime(unsigned int val) ///
{
    inaltime = val;
}

std :: string bautura :: getDen() const ///
{
    return denumire;
}

void bautura :: setDen(std :: string s) ///
{
    denumire = s;
}

std :: istream& bautura :: citire(std :: istream& is)
{
    bool fis;

    if (&is == &std :: cin)
        fis = false;
    else
        fis = true;

    if (fis == false)
        std :: cout << "Dati denumirea: ";
    is.get();
    getline(is, denumire);
    if (fis == false)
        std :: cout << "Dati inaltimea: ";
    is >> inaltime;
    if (fis == false)
        std :: cout << "Dati pretul: ";
    is >> pret;

    return is;
}

std :: ostream& bautura :: afisare(std :: ostream& os)
{
    os << "Denumirea bauturii: " << denumire;
    os << '\n';
    os << "Inaltimea: " << inaltime;
    os << '\n';
    os << "Pret: " << pret;
    os << '\n';

    return os;
}


std :: ostream&  operator<<(std :: ostream& os, const bautura& p) ///
{
    os << "Denumirea bauturii: " << p.denumire;
    os << '\n';
    os << "Inaltimea: " << p.inaltime;
    os << '\n';
    os << "Pret: " << p.pret;
    os << '\n';

    return os;
}

std :: istream&  operator>>(std :: istream& is, bautura& p) ///
{
    bool fis;

    if (&is == &std :: cin)
        fis = false;
    else
        fis = true;

    if (fis == false)
        std :: cout << "Dati denumirea: ";
    is.get();
    getline(is, p.denumire);
    if (fis == false)
        std :: cout << "Dati inaltimea: ";
    is >> p.inaltime;
    if (fis == false)
        std :: cout << "Dati pretul: ";
    is >> p.pret;

    return is;
}
