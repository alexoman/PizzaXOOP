#include "meniu.h"

meniu* meniu :: instanta = nullptr;

unsigned int meniu :: getNrProduse()
{
    return nr_produse;
}

std :: vector<produs*>meniu :: getProduse()
{
    return v;
}

void meniu :: adaugaPizza(const pizza& p)
{
    try
    {
        for (std :: size_t u=0;u<v.size();u++)
            if(v[u]->getDen() == p.getDen())
                throw 403;
    }
    catch (int err)
    {
        std :: cerr << " ERROR CODE PIZZA " << err << '\n';
        return ;
    }

    produs* aux = new pizza(p);
    v.push_back(aux);
}

void meniu :: adaugaBautura(const bautura& p)
{
    try
    {
        for (std :: size_t u=0;u<v.size();u++)
            if(v[u]->getDen() == p.getDen())
                throw 403;
    }
    catch (int err)
    {
        std :: cerr<< "ERROR CODE BAUTURA" << err << '\n';
        return ;
    }
     produs* aux = new bautura(p);
     v.push_back(aux);
}

void meniu :: eliminareProdus(unsigned int i)
{
    try
    {
        if(i > v.size()+1)
            throw 404;
    }
    catch (int err)
    {
        std :: cerr<<"ERROR CODE:"<<err<<'\n';
        return ;
    }
    if(v.size()==1)
        v.clear();
    else
        v.erase(v.begin()+i-1,v.begin()+i);
}

void meniu :: afisare()
{
    for (std ::  size_t u=0;u<v.size();u++)
    {
        std::cout<<"PRODUSUL "<<u+1<<'\n';
        std::cout<< *v[u];
    }
    std::cout<<'\n';
}

void meniu :: afisareNume()
{
    for (std :: size_t u=0;u<v.size();u++)
        std :: cout<<u+1<< ". " <<v[u] ->getDen()<< " - " << v[u] -> getPret() <<'\n';
    std :: cout << '\n';
}
