
#include "Circulo.h"
#include <iostream>

using namespace std;

const float PI = 3.141592653589;

Circulo::Circulo(double x, double y, double raio,
                 int e, int c, int t) : FigBase(x, y, e, c, t) {
    setRaio(raio);
}

double Circulo::getRaio() const {
    return raio;
}

void Circulo::setRaio(double r) {
    raio = r;
}

float Circulo::area() const {
    return PI * raio * raio;
}

float Circulo::perimetro() const {
    return 2 * PI * raio;
}

void Circulo::imprime() const {
     cout << *this << endl;
}

void Circulo::ler(){
    cin >> *this;
}


ostream& operator<< (ostream &out, const   Circulo &c) {
    out << "--- [Circulo] ---" << endl;
    c.FigBase::imprime();
    out << " raio=" << c.getRaio() << endl;
    out << " area = " << c.area() << " perimetro = " << c.perimetro() << endl;
    
   return out;
}

istream& operator>> (istream &cin, Circulo &c) {
    double r;

    cout << "Forneca os dados do Circulo \n";
    c.FigBase::ler();
    cout << "Raio = ";
    cin >> r; c.setRaio(r);

    return cin;
}
