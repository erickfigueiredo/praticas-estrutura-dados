
#include "Retangulo.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Retangulo::Retangulo(double x, double y, double largura, double altura,
    int e, int c, int t) : FigBase(x, y, e, c, t) {
    setLargura(largura);
    setAltura(altura);
}

double Retangulo::getLargura() const {
    return largura;
}

void Retangulo::setLargura(double larg) {
    largura = larg;
}

double Retangulo::getAltura() const {
    return altura;
}

void Retangulo::setAltura(double alt) {
    altura = alt;
}

float Retangulo::area() const {
    return altura * largura;
}

float Retangulo::perimetro() const {
    return 2*(largura + altura);
}

void Retangulo::imprime() const {

    cout << *this << endl;

}

void Retangulo::ler() {
    cin >> *this;
}

ostream& operator<< (ostream &out, const Retangulo &r) {
    out << "--- [Retangulo] ---" << endl;
    r.FigBase::imprime();
    out << " largura=" << r.getLargura() << " altura=" << r.getAltura() << endl;
    out << " area = " << r.area() << " perimetro = " << r.perimetro() << endl;

   return cout;
}



istream& operator>> (istream &cin, Retangulo &r) {
    double larg,alt;

    cout << "Forneca os dados do retangulo \n";
    r.FigBase::ler();
    cout << "Largura = ";
    cin >> larg; r.setLargura(larg);
    cout << "Altura = ";
    cin >> alt; r.setAltura(alt);

    return cin;
}
