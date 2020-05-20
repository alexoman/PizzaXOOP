#include "main.h"

void    spatiere()
{
    std :: cout << '\n';
    for (unsigned int i = 0; i < 40; i++)
        std :: cout << "=";
    std :: cout << '\n' << '\n';
}

void    alegereP()
{
    std :: ifstream f("pizza.in");
    unsigned int n;
    produs* p;
    meniu* m = meniu :: getInstanta();

    f >> n;
    for (size_t u = 1; u <= n; u++)
    {
        p = new pizza();
        f >> *p;
        m -> adaugaPizza(dynamic_cast<pizza&>(*p));
    }
    f.close();
}

void    alegereB()
{
    std :: ifstream f("bautura.in");
    unsigned int n;
    produs* p;
    meniu* m = meniu :: getInstanta();

    f >> n;
    for (size_t u = 1; u <= n; u++)
    {
        p = new bautura();
        f >> *p;
        m -> adaugaBautura(dynamic_cast<bautura&>(*p));
    }
    f.close();
}

int main()
{
    unsigned int optiune;
    produs* p = nullptr;
    pizza* aux;
    comanda* c = nullptr;
    meniu* m = meniu :: getInstanta();

    alegereP();
    alegereB();
    while (true)
    {
        spatiere();
        std :: cout << "PIZZA AROMA:" << '\n';
        std :: cout << "1. ALEGERE MENIU" << '\n';
        std :: cout << "2. ALEGERE COMENZI" << '\n';
        std :: cout << "3. INCHIDERE PROGRAM" << '\n';
        std :: cout << "OPTIUNE: ";
        std :: cin >> optiune;
        spatiere();
        if (optiune == 1)
        {
            std :: cout << "OPTIUNI MENIU:" << '\n';
            std :: cout << "1. ADAUGARE PIZZA" << '\n';
            std :: cout << "2. ADAUGARE BAUTURA" << '\n';
            std :: cout << "3. STERGERE PRODUS" << '\n';
            std :: cout << "4. AFISARE MENIU" << '\n';
            std :: cout << "OPTIUNE: ";
            std :: cin >> optiune;

            if (optiune == 1)
            {
                spatiere();
                p = new pizza();
                std :: cin >> *p;
                m -> adaugaPizza(dynamic_cast<pizza&>(*p));
            }
            else if (optiune == 2)
            {
                spatiere();
                p = new bautura();
                std :: cin >> *p;
                m -> adaugaBautura(dynamic_cast<bautura&>(*p));
            }
            else if (optiune == 3)
            {
                spatiere();
                std :: cout << "DATI INDEXUL = ";
                std :: cin >> optiune;
                m -> eliminaProdus(optiune);
            }
            else if (optiune == 4)
            {
                spatiere();
                m -> afisare();
            }
            else
                std :: cerr << "OPERATIE NERECUNOSCUTA" << '\n';
        }
        else if (optiune == 2)
        {
            c = new comanda();
            std :: cout << "OPTIUNI COMENZI:" << '\n';
            std :: cout << "1. LIVRARE RESTAURANT" << '\n';
            std :: cout << "2. LIVRARE ACASA" << '\n';
            std :: cout << "OPTIUNE: ";
            std :: cin >> optiune;

            if (optiune == 1)
            {
                spatiere();
                m -> afisareNume();
                std :: cout << "DATI ID-URILE PRODUSELOR COMENZII: ";
                std :: cin >> optiune;
                while (optiune != 0)
                {
                    p = (m -> getProduse())[optiune - 1];
                    if ((aux = dynamic_cast<pizza*>(p)))
                        c -> addProdus<pizza>(dynamic_cast<pizza*>(p));
                    else
                        c -> addProdus<bautura>(dynamic_cast<bautura*>(p));
                    std :: cin >> optiune;
                }
                std :: cout << "COMANDA ARE PRETUL " << c -> getPret() << '\n';
                std :: cout << "S-AU COMANDAT " << c->getPizza() << " PIZZE SI " << c->getBaut() << " BAUTURI.";
            }
            else if (optiune == 2)
            {
                spatiere();
                m -> afisareNume();
                std :: cout << "DATI ID-URILE PIZZELOR COMENZII: ";
                std :: cin >> optiune;
                while (optiune != 0)
                {
                    p = (m -> getProduse())[optiune - 1];
                    if ((aux = dynamic_cast<pizza*>(p)))
                        c -> addProdus<pizza>(dynamic_cast<pizza*>(p));
                    else
                        c -> addProdus<bautura>(dynamic_cast<bautura*>(p));
                    std :: cin >> optiune;
                }
                std :: cout << "NUMARUL DE KM: ";
                std :: cin >> optiune;
                std :: cout << "COMANDA ARE PRETUL " << c -> getPret() + 0.05 * c -> getPret() * (double)(optiune / 10) << '\n';
                std :: cout << "S-AU COMANDAT " << c->getPizza() << " PIZZE SI " << c->getBaut() << " BAUTURI.";
            }
            else
                std :: cerr << "OPERATIE NERECUNOSCUTA" << '\n';

            delete c;
        }
        else if (optiune == 3)
            return 0;
    }
    return 0;
}
