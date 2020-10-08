#ifndef RETANGULO_H
#define RETANGULO_H

#include "FigBase.h"
#include <iostream>

using namespace std;

class Retangulo:public FigBase{
    public:
        Retangulo(double altura = 1, double largura = 1, double x = 0, double y = 0, int esp = 1, int cor = 1, int tipo = 1);

        double getLargura() const;
        double getAltura() const;

        void setLargura(double);
        void setAltura(double);

        float area() const;
        float perimetro() const;

        void imprime() const;
        void le();

        friend istream& operator>>(istream&, Retangulo&);
        friend ostream& operator<<(ostream&, const Retangulo&);
        
    private:
        double altura, largura;
};

#endif // !RETANGULO_H
#define RETANGULO_H