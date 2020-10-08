#ifndef  CIRCULO_H
#define CIRCULO_H

#include "FigBase.h"
#include <iostream>

using namespace std;

class Circulo : public FigBase{
    public:
        Circulo(double r = 1, double x = 0, double y = 0, int esp = 1, int cor = 1, int tipo = 1);

        double getRaio() const;

        void setRaio(double);

        float area() const;
        float perimetro() const;

        void imprime() const;
        void le();
        
        friend istream& operator>>(istream &, Circulo &);
        friend ostream &operator<<(ostream&, const Circulo&);

    private:
        double raio;
};

#endif // ! CIRCULO_H
