#include "../main.h"

ingredient::ingredient()
{
    pret = 0;
    cantitate = 0;
    denumire = "";
}

ingredient :: ingredient(double p,double c,std :: string d)
{
    pret = p;
    cantitate = c;
    denumire = d;
}

ingredient :: ingredient(const ingredient & i)
{
    pret = i.pret;
    cantitate = i.cantitate;
    denumire = i.denumire;
}

ingredient& ingredient :: operator=(cont ingredient& i)
{
    this->denumire = i.denumire;
    this->pret = i.pret;
    this->cantitate = i.cantitate;
    return *this;
}

std :: string ingredient :: getDenumire() const
{
    return denumire;
}

void ingredient :: setDenumire(std :: string d)
{
    denumire = d;
}

double ingredient :: getPret() const
{
    return pret;
}

void ingredient :: setPret(double p)
{
    pret = p;
}

double ingredient :: getCantitate() const
{
    return cantitate;
}

void ingredient :: setCantitate(double c)
{
    cantitate = c;
}

std :: ostream& operator <<(std :: ostream& os, const ingredient& i)
{
    os << i.denumire << ' - ' << i.pret << ' - ' << i.cantitate;
    return os;
}

std :: istream& operator>>(std :: istream& is, ingredient& i)
{
    bool fis;

    if(&is == &std :: cin)
        fis = false;
    else
        fis = true;
    if(fis == false)
        std :: cout << "Pret ingredient: ";
    is >> i.pret;
    if (fis == false)
        std :: cout <<"Cantitate ingredient: ";
    is >> i.cantitate;
    if(fis == false)
        std :: cout <<"Denumire ingredient: ";
    is.get();
    getline(is,i.denumire);
    return is;

}
