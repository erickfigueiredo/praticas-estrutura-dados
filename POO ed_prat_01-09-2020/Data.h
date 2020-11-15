#ifndef DATA_H
#define DATA_H

#include <iostream>
using namespace std;

class Data{
    public:
        Data(int d = 1, int m = 1, int a = 2018);
        Data(const Data&);

        void setDia(int);
        void setMes(int);
        void setAno(int);

        int getDia() const;
        int getMes() const;
        int getAno() const;

        int compData(const Data&) const;
        int difDias(const Data&) const;

        Data &operator=(const Data&);

        void imprime() const;

        friend istream& operator>>(istream &, Data &);
        friend ostream& operator<<(ostream &, const Data &);

    private:
        int dia, mes, ano;
};

#endif