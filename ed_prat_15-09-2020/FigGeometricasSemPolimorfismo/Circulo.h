
#ifndef __CIRCULO_H
#define __CIRCULO_H

#include "FigBase.h"
#include <iostream>
using std::istream;
using std::ostream;

class Circulo : public FigBase {

friend ostream& operator<< (ostream &, const Circulo &);
friend istream& operator>> (istream &, Circulo &);

private:
    double raio;

public:
    Circulo(double=0.0, double=0.0, double=0.0, int=1, int=1, int=1);
    double getRaio() const;
    void setRaio(double);
    float area() const;
    float perimetro() const;
    void ler();
    void imprime() const;
};

#endif
