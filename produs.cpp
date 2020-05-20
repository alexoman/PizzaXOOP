#include "../main.h"

produs::produs()
{
    pret = 0;
    ing = std :: vector<ingredient>(0); //ctor
}

produs& produs :: operator=(produs const &p)
{
    this->ing = p.ing;
    this->pret = p.pret;
    return *this;
}

produs :: produs(double p, std :: vector<ingredient> v)
{
    pret = p;
    ing = v;
}

produs :: produs(const produs& p)
{
    pret = p.pret;
    ing = p.ing;
}

void produs :: setPret(double p)
{
    pret = p;
}

double produs :: getPret() const
{
    return pret;
}

std :: vector<ingredient> produs :: getIng() const
{
    return ing;
}

void produs :: setIng(std :: vector<ingredient> v)
{
    ing = v;
}

std :: istream& operator>>(std :: istream& is, produs& p)
{
    return p.citire(is);
}

std :: ostream& operator<<(std :: ostream& os, produs& p)
{
    return p.afisare(os);
}
