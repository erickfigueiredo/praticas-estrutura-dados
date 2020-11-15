#ifndef AGENDA_H
#define Agenda_H


#include <string>
#include "Horario.h"
#include "Data.h"

class ItemAgenda{
    public:
        ItemAgenda();
        ItemAgenda(const std::string&, const Data&, const Horario&);
        ItemAgenda(const ItemAgenda&);
        
        void setDesc(const std::string&);
        void setData(const Data&);
        void setHorario(const Horario&);

        const std::string &getDesc() const;
        const Data &getData() const;
        const Horario &getHorario() const;

    private:
        std::string descricao;
        Data d;
        Horario h;
};

class Agenda{
    public:
        Agenda();
        void inserirItem(const ItemAgenda&);
        void compromissosData(const Data&) const;
    private:
        ItemAgenda iAgenda[1000];
        int posDisponivel = 0;
        //ItemAgenda* iAgenda = new iAgenda[1000];
};

#endif