#include "Data.h"

Data::Data(int d, int m, int a){
    setDia(d);
    setMes(m);
    setAno(a);
}

Data::Data(const Data &dt){
    this->setDia(dt.getDia());
    this->setMes(dt.getMes());
    this->setAno(dt.getAno());
}

void Data::setDia(int d){
    if(d < 1){
        this->dia = 1;
    }else if(d > 30){
        this->dia = 30;
    }else{
        this->dia = d;
    }
}

void Data::setMes(int m){
    if(m < 1){
        this->mes = 1;
    }else if(m > 12){
        this->mes = 12;
    }else{
        this->mes = m;
    }
}

void Data::setAno(int a){
    if(a < 2018){
        this->ano = 2018;
    }else if(a > 2020){
        this->ano = 2020;
    }else{
        this->ano = a;
    }
}

int Data::getDia() const{
    return this->dia;
}

int Data::getMes() const{
    return this->mes;
}

int Data::getAno() const{
    return this->ano;
}

int Data::compData(const Data& dt) const{
   if(this->difDias(dt) == 0){
       return 0;
   }else if (this->difDias(dt) >= 1){
        return 1;
   }else{
       return -1;
   }
}

int Data::difDias(const Data& dt) const{
    return (this->getDia() - dt.getDia())+((this->getMes() - dt.getMes())*30)+((this->getAno() - dt.getAno())*365);
}

void Data::imprime() const{
    cout << *this;
}

Data& Data::operator=(const Data &dt){
    if(this == &dt)
        return *this;
    
    this->setDia(dt.getDia());
    this->setMes(dt.getMes());
    this->setAno(dt.getAno());

    return *this;
}

istream &operator>>(istream &is, Data &dt){
    int d, m, a;
    is >> d >> m >> a;

    dt.setDia(d);
    dt.setMes(m);
    dt.setAno(a);
    
    return is;
}

ostream &operator<<(ostream &os, const Data &dt){
    os << dt.getDia() << ' ' << dt.getMes() << ' ' << dt.getAno();

    return os;
}

