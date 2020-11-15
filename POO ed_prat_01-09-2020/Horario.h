#ifndef HORARIO_H
#define HORARIO_H

#include <iostream>
using namespace std;

class Horario{
    public:
        Horario(int h= 0, int m= 0, int s= 0);
        Horario(const Horario&);

        void setHora(int);
        void setMinuto(int);
        void setSegundo(int);

        int getHora() const;
        int getMinuto() const;
        int getSegundo() const;

        int compHorario(const Horario&) const;
        int difSegundos(const Horario&) const;

        void imprime()const;

        Horario &operator=(const Horario&);

        friend istream &operator>>(istream &, Horario &);
        friend ostream &operator<<(ostream &, const Horario &);

    private:
        int hora, minuto, segundo;
};

#endif