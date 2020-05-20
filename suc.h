#ifndef BAUTURA_H
#define BAUTURA_H

#include "../main.h"

class bautura: public produs
{
    private:
        std :: string denumire;
        unsigned int inaltime;

    public:
        bautura(); ///
        bautura(std :: string, unsigned int, double); ///
        bautura(const bautura&); ///
        bautura& operator=(const bautura&); ///

        unsigned int  getInaltime() const; ///
        void setInaltime(unsigned int val); ///
        std :: string getDen() const; ///
        void setDen(std :: string); ///
        void calculPret() {};
        std :: istream& citire(std :: istream&); ///
        std :: ostream& afisare(std :: ostream&); ///
        friend  std :: ostream& operator<<(std :: ostream&, const bautura&); ///
        friend  std :: istream& operator>>(std :: istream&, bautura&); ///
        ~bautura() {
        };
};

#endif // BAUTURA_H
