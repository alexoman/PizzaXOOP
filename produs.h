#ifndef PRODUS_H
#define PRODUS_H


#include "../main.h"

class produs
{
    protected:
        double pret;
        std :: vector<ingredient> ing;
        const double manopera = 0.02;
    public:
        produs();
        produs(double, std :: vector<ingredient>);
        produs(const produs&);
        produs& operator=(produs const&);

    virtual double getPret() const;
    virtual void setPret(double = 0);
    std :: vector<ingredient> getIng() const;
    void setIng(std :: vector<ingredient>);

    virtual std :: string getDen() const = 0;
    virtual std :: istream& citire(std :: istream&) = 0;
    virtual std :: ostream& afisare(std :: ostream&) = 0;
    friend std :: istream& operator>>(std :: istream&, produs&);
    friend std :: ostream& operator<<(std :: ostream&, produs&);

    virtual void calculPret() = 0;
    virtual ~produs()
    {

    };
};

#endif // PRODUS_H
