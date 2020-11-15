#include "Horario.h"

Horario::Horario(int h, int m, int s){
    setHora(h);
    setMinuto(m);
    setSegundo(s);
}

Horario::Horario(const Horario& hr){
    this->setHora(hr.getHora());
    this->setMinuto(hr.getMinuto());
    this->setSegundo(hr.getSegundo());
}

void Horario::setHora(int h){
    if(h < 0){
        this->hora = 0;
    }else if(h > 23){
        this->hora = 23;
    }else{
        this->hora = h;
    }
}

void Horario::setMinuto(int m){
    if(m < 0){
        this->minuto = 0;
    }else if(m > 59){
        this->minuto = 59;
    }else{
        this->minuto = m;
    }
}

void Horario::setSegundo(int s){
    if(s < 0){
        this->minuto = 0;
    }else if(s > 59){
        this->segundo = 59;
    }else{
        this->segundo = s;
    }
}

int Horario::getHora() const{
    return this->hora;
}

int Horario::getMinuto() const{
    return this->minuto;
}

int Horario::getSegundo() const{
    return this->segundo;
}

int Horario::compHorario(const Horario& hr) const{
   if(this->difSegundos(hr) == 0){
       return 0;
   }else if (this->difSegundos(hr) >= 1){
        return 1;
   }else{
       return -1;
   }
}

Horario& Horario::operator=(const Horario &hr){
    if(this == &hr)
        return *this;
    
    this->setHora(hr.getHora());
    this->setMinuto(hr.getMinuto());
    this->setSegundo(hr.getSegundo());

    return *this;
}

int Horario::difSegundos(const Horario& hr) const{
    return (this->getSegundo() - hr.getSegundo()) + ((this->getMinuto() - hr.getMinuto())*60)+((this->getHora() - hr.getHora())*3600);
}

void Horario::imprime() const{
    cout << *this;
}

istream &operator>>(istream &is, Horario &hr){
    int h, m, s;
    is >> h >> m >> s;
    
    hr.setHora(h);
    hr.setMinuto(m);
    hr.setSegundo(s);

    return is;
}

ostream &operator<<(ostream &os, const Horario &hr){
    os << hr.getHora() << ' ' << hr.getMinuto() << ' ' << hr.getSegundo() << ' ';
    
    return os;
}