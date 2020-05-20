#ifndef MENIU_H
#define MENIU_H

#include "../main.h"

void SPATIERE();

class meniu
{
    private:
        std :: vector<produs*> v;
        unsigned int nr_produse;
        static meniu* instanta;
        meniu()
        {

        };
    public:
        unsigned int getNrProduse();
        std :: vector<produs*> getProduse();
        void adaugaPizza(const pizza&);
        void adaugaBautura(const bautura&);
        void eliminareProdus(unsigned int);
        void afisare();
        void afisareNume();
        static meniu* getInstanta()
        {
            if(instanta == nullptr)
                instanta = new meniu();
            return instanta;
        }
    virtual ~meniu()
    {
        nr_produse = 0;
        v.clear();
        delete instanta;
    }
};

#endif // MENIU_H
