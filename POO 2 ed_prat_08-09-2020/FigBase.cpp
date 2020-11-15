#include "FigBase.h"

FigBase::FigBase(double x, double y, int esp, int cor, int tipo){
    setX(x);
    setY(y);
    setEspessura(esp);
    setCor(cor);
    setTipo(tipo);
}

double FigBase::getX() const{
    return this->x;
}

double FigBase::getY()const{
    return this->y;
}

int FigBase::getEspessura() const{
    return this->espessura;
}

int FigBase::getCor() const{
    return this->cor;
}

int FigBase::getTipo() const{
    return this->tipo;
}

void FigBase::setX(double x){
    this->x = x;
}

void FigBase::setY(double y){
    this->y = y;
}

void FigBase::setEspessura(int esp){
    if(esp < 1){
        this->espessura = 1;
    }else if(esp > 5){
        this->espessura = 5;
    }else{
        this->espessura = esp;
    }
}
void FigBase::setCor(int cor){
    if(cor < 1){
        this->cor = 1;
    }else if(cor > 5){
        this->cor = 5;
    }else{
        this->cor = cor;
    }
}
void FigBase::setTipo(int tipo){
    if(tipo < 1){
        this->tipo = 1;
    }else if(tipo > 3){
        this->tipo = 3;
    }else{
        this->tipo = tipo;
    }
}

void FigBase::imprime() const{
    cout << " Atributos da linha: " << endl;
    cout << "     Espessura = " << this->getEspessura() << endl;
    cout << "     Cor       = " << this->getCor() << endl;        cout << "     Tipo      = " << this->getTipo() << endl;
    cout << " x = " << this->getX() << " y = " << this->getY() << endl;
}

void FigBase::le(){
    double x, y;
    int esp, cor, tipo;

    cin >> x >> y >> esp >> cor >> tipo; 

    setX(x);
    setY(y);
    setEspessura(esp);
    setCor(cor);
    setTipo(tipo);
}

ostream& operator<<(ostream& os, const FigBase& fb){
    fb.imprime();
    return os;
}

