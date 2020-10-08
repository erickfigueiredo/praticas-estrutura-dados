#include "Segmento.h"

Segmento::Segmento(double x2, double y2, double x, double y,int esp, int cor, int tipo ):FigBase(x, y, esp, cor, tipo){

}

double Segmento::getX2() const{
    return this->x2;
}

double Segmento::getY2() const{
    return this->y2;
}

void Segmento::setX2(double x2){
    this->x2 = x2;
}

void Segmento::setY2(double y2){
    this->y2 = y2;
}

float Segmento::area()const{
    return 0;
}

float Segmento::perimetro()const{
    return 0;
}

void Segmento::le(){
    double x2, y2;

    cin >> x2 >> y2;

    setX2(x2);
    setY2(y2);
    FigBase::le();
}

void Segmento::imprime()const{
    cout << "--- [Segmento] ---" << endl;
    //Para chamar um metodo da classe usamos o "operador de resolução de escopo"
    FigBase::imprime();
    cout << " x2 = " << this->getX2() << " y2 = " << this->getY2() << endl; 
    cout << " area = " << this->area() << " perimetro = " << this->perimetro() << endl;
}

istream& operator>>(istream &is, Segmento &s){
    s.le();
    return is;
}

ostream& operator<<(ostream &os, const Segmento &s){
    s.imprime();
    return os;
}
