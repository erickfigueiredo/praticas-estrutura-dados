#ifndef SEGMENTO_H
#define SEGMENTO_H

#include "FigBase.h"
#include <iostream>

using namespace std;

class Segmento:public FigBase{
    public:

    //adicione valores-padrao para os argumentos dos construtores de Retangulo, Circulo e Segmento pois antes de 
    //ler valores para objetos de tais classes os objetos serao criados utilizando o construtor sem argumentos.

    Segmento(double x2 = 0, double y2 = 0, double x = 0, double y = 0, int esp = 1, int cor = 1, int tipo = 1);

    double getX2() const;
    double getY2() const;

    void setX2(double);
    void setY2(double);

    float area() const;
    float perimetro() const;

    void imprime() const;
    void le();

    friend istream& operator>>(istream&, Segmento&);
    friend ostream& operator<<(ostream&, const Segmento&);
    
    private:
        double x2, y2;
};

#endif // !SEGMENTO_H
