#include "Retangulo.h"

Retangulo::Retangulo(double altura, double largura, double x, double y, int esp, int cor, int tipo ):FigBase(x, y, esp, cor, tipo){
    setAltura(altura);
    setLargura(largura);
}

double Retangulo::getAltura() const{
    return this->altura;
}

double Retangulo::getLargura() const{
    return this->largura;
}

void Retangulo::setLargura(double larg){
    this->largura = larg;
}

void Retangulo::setAltura(double alt){
    this->altura = alt;
}

float Retangulo::area() const{
    return this->altura * this->largura;
}

float Retangulo::perimetro()const{
    return this->altura*2 + this->largura*2;
}
void Retangulo::imprime() const{
    cout << "--- [Retangulo] ---" << endl;
    FigBase::imprime();
    cout << " largura = " << getLargura() << " altura = " << getAltura() << endl;  
    cout << " area = " << area() << " perimetro = " << perimetro() << endl;
}

void Retangulo::le() {
    double altura, largura;

    cin >> altura >> largura; 

    setAltura(altura);
    setLargura(largura);
    FigBase::le();
}

istream& operator>>(istream &is, Retangulo &r){
    r.le();
    return is;
}

ostream& operator<<(ostream &os, const Retangulo &r){
    r.imprime();
    return os;
}