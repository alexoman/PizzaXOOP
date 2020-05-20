#ifndef INGREDIENT_H
#define INGREDIENT_H

#include "../main.h"

class ingredient
{
    private:
        std :: string denumire;
        double pret;
        double cantitate;

    public:
        ingredient();
        ingredient(double,double,std :: string);
        ingredient(const ingredient&);
        ingredient& operator=(const ingredient&);

        std :: string getDenumire() const;
        void setDenumire(std :: string d);
        void setCantitate(double c);
        double getCantitate() const;
        void setPret(double p);
        double getPret() const;

        friend std :: ostream& operator<<(std :: ostream&, const ingredient&);
        friend std ::istream& operator>>(std :: istream&, ingredient&);

        ~ingredient()
        {

        };
};

#endif //INGREDIENT_H
