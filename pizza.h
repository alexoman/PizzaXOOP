#ifndef PIZZA_H
#define PIZZA_H


#include "../main.h"

class pizza
{
    private:
        std :: string denumire;
        unsigned int raza;
        bool vegetariana;
    public:
        pizza();
        pizza(std :: string, unsigned int, std :: vector<ingredient>, bool);
        pizza(const pizza&);
        pizza& operator=(const pizza&);

        unsigned int getRaza() const;
        void setRaza(unsigned int r);
        std :: string getDen() const;
        void setDen(std :: string);
        void calculPret();

        std :: istream& citire(std :: istream&);
        std :: ostream& afisare(std :: ostream&);
        friend std :: ostream operator<<(std :: ostream&, const pizza&);
        friend std :: istream operator>>(std :: istream&, pizza&);
        ~pizza();
        {

        };
};

#endif // PIZZA_H
