#ifndef  FIGBASE_H
#define FIGBASE_H

#include <iostream>
using namespace std;

class FigBase{
    public:
    FigBase(double, double, int, int, int);
    
    double getX() const;
    double getY() const;

    int getEspessura() const;
    int getCor() const;
    int getTipo() const;

    void setX(double);
    void setY(double);
    void setEspessura(int);
    void setCor(int);
    void setTipo(int);

    void imprime() const;
    void le();

    friend ostream& operator<<(ostream&,const FigBase& );

    private:
        double x, y;
        int espessura, cor, tipo;
};
#endif // ! FIGBASE_H
