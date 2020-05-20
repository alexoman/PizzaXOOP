#include "../main.h"

pizza::pizza(): produs() ///
{
    denumire = "";
    raza = 0;
    vegetariana = false ;
}

pizza :: pizza (std :: string d, unsigned int r, std :: vector<igredient> v, bool opt): produs(0,v) ///
{
    denumire = d;
    raza = r;
    vegetariana = opt;
    this->calculPret();
}

pizza :: pizza(const pizza& p) ///
{
    denumire = p.denumire;
    raza = p.raza;
    ing = p.ing;
    pret = p.pret;
    vegetariana = p.vegetariana;
}

pizza& pizza :: operator=(pizza const &p) ///
{
    this->pret = p.pret;
    this->denumire = p.denumire;
    this->raza = p.raza;
    this->ing = p.ing;
    this->vegetariana =p.vegetariana;
    return *this;
};

unsigned int pizza :: getRaza() const ///
{
    return raza;
}

void pizza :: setRaza(unsigned int r) ///
{
    raza = r;
}

std :: string pizza :: getDen() const ///
{
    return denumire ;
}

void pizza :: setDen(std :: string s) ///
{
    denumire = s;
}

void pizza :: calculPret() ///
{
    pret = 0;
    for(unsigned int index = 0; index<ing.size();index++)
        pret += ing[index].getPret() * ing[index].getCantitate();
    pret += pret * manopera;
}

std :: istream& pizza :: citire(std :: istream& is)
{
    bool fis;
    char aux;

    if(&is == &std :: cin)
        fis = false;
    else
        fis = true;
    int numar_ingrediente;
    if(fis == false)
        std :: cout << "Dati denumirea: ";
    is.get();
    getline(is, denumire);
    if(fis == false)
        std :: cout << "Dati raza: ";
    is>>raza;
    if(fis == false)
        std :: cout << "Dati numarul de ingrediente: ";
    is>>numar_ingrediente;
    ing = std :: vector<ingredient>(numar_ingrediente);
    for(unsigned int index=0;index<ing.size();index++)
    {
        if(fis == false)
            std :: cout <<"Dati ingredientul de pe pozitia "<<index+1<<": "<<' \n';
        is>> ing[index];
    }

    while(fis == false && aux != 'Y' && aux != 'N')
    {
        std :: cout <<"Este pizza vegetariana ? (Y/N): ";
        is>>aux;
    }

    if (fis == true)
        try
        {
            is>>aux;
            if(aux != 'Y' && aux != 'N')
            {
                std :: cerr <<"S-a introdus o pizza in mod gresit! Nu este vegetariana!";
                throw true;
            }
        }
        catch (bool err)
        {
            vegetariana = err;
            this->calculPret();
            return is;
        }
        if(aux == 'Y')
            vegetariana = true;
        else
            vegetariana = false;
        this->calculPret();
        return is;
}

std :: ostream& pizza :: afisare(std :: ostream& os)
{
    os << "Denumirea pizzei: " <<denumire;
    os<<'\n';
    os << "Raza: "<<raza;
    os<<'\n';
    os << "Pret: "<<pret;
    os<<'\n';
    os << "Ingrediente: " <<'\n';
    for(unsigned int index = 0; index<ing.size();index++)
        os<<index+1<<". "<<ing[index]<< '\n';

    return os;
}

std :: ostream& operator<<(std :: ostream& os, const pizza& p)
{
     os << "Denumirea pizzei: " <<p.denumire;
    os<<'\n';
    os << "Raza: "<<p.raza;
    os<<'\n';
    os << "Pret: "<<p.pret;
    os<<'\n';
    os << "Ingrediente: " <<'\n';
    for(unsigned int index = 0; index<p.ing.size();index++)
        os<<index+1<<". "<<p.ing[index]<< '\n';

    return os;
}

std :: istream& operator>>(std :: istream& is, pizza& p)
{
    bool fis;
    char aux;

    if(&is == &std :: cin)
        fis=false;
    else
        fis=true;
    int numar_ingrediente;
    if(fis == false)
        std :: cout <<"Dati denumirea: ";
    is.get();
    getline(is,p.denumire);
    if(fis == false)
        std :: cout <<"Dati raza: ";
    is>>p.raza;
    if(fis == false)
        std :: cout <<"Dati nr de ingrediente: ";
    is>>p.numar_ingrediente;
    p.ing = std :: vector<ingredient>(numar_ingrediente);
    for(unsigned int index=0;index<p.ing.size();index++)
    {
        if(fis == false)
            std :: cout <<"Dati ingredientul de pe pozitia "<<index+1<<": ";
        is>>p.ing[index];
    }

    std:: cout<<"Este pizza vegetariana? (Y/N): ";
    while(fis==true && aux!='Y' && aux!='N' )
        std :: cin >> aux;
    while(fis == false && aux != 'Y' && aux!= 'N')
        std :: cin >> aux;
    if(aux=='Y')
        p.vegetariana = true;
    else
        p.vegetariana = false;
    p.calculPret();

    return is;
}
