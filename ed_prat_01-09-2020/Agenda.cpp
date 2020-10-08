#include "Agenda.h"

ItemAgenda::ItemAgenda(){}

ItemAgenda::ItemAgenda(const std::string &desc, const Data &dt, const Horario &hr){
    setDesc(desc);
    setData(dt);
    setHorario(hr);
}

ItemAgenda::ItemAgenda(const ItemAgenda &ia){
    this->setDesc(ia.getDesc());
    this->setData(ia.getData());
    this->setHorario(ia.getHorario());
}

void ItemAgenda::setDesc(const std::string &desc){
    this->descricao = desc;
}

void ItemAgenda::setData(const Data &dt){
    this->d = dt;
}

void ItemAgenda::setHorario(const Horario &hr){
    this->h = hr;
}

const std::string &ItemAgenda::getDesc() const
{
    return descricao;
}

const Data &ItemAgenda::getData() const
{
    return d;
}

const Horario &ItemAgenda::getHorario() const
{
    return h;
}

Agenda::Agenda(){}

void Agenda::inserirItem(const ItemAgenda& ia){
    if(this->posDisponivel < 1000){
        iAgenda[this->posDisponivel] = ia;
        this->posDisponivel++;
    }
}

void Agenda::compromissosData(const Data& dt) const{
    for(int i = 0; i <= this->posDisponivel; i++){
        if(dt.compData(this->iAgenda[i].getData()) == 0){
            this->iAgenda[i].getHorario().imprime();
            cout << this->iAgenda[i].getDesc() << endl;
        }
    }
}
