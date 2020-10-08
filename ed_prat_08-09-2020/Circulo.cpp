#include "Circulo.h"

const float PI = 3.141592653589;

Circulo::Circulo(double r, double x, double y, int esp, int cor, int tipo ):FigBase(x, y, esp, cor, tipo ){
    setRaio(r);
}

double Circulo::getRaio() const{
    return this->raio;
}

void Circulo::setRaio(double r){
    this->raio = r;
}

float Circulo::area() const{
    return PI * (this->getRaio() * this->getRaio());
}

float Circulo::perimetro() const{
    return 2 * (PI * this->getRaio());
}

void Circulo::le(){
    double r;

    cin >> r;

    setRaio(r);
    FigBase::le();
}

void Circulo::imprime() const{
    cout << "--- [Circulo] ---" << endl;
    FigBase::imprime();
    cout << " raio = " << this->getRaio() << endl; 
    cout << " area = " << this->area() << " perimetro = " << this->perimetro() << endl; 
}

istream& operator>>(istream &is, Circulo &c){
    c.le();
    return is;
}

ostream& operator<<(ostream &os, const Circulo &c){
    c.imprime();
    return os;
}