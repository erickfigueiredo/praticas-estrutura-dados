#include <iostream>
using namespace std;

#include "FigBase.h"
#include "Retangulo.h"
#include "Circulo.h"
#include "Segmento.h"

int main(){

    Retangulo r1;
    Circulo *c, c1, c2;
    Segmento s1, s2;
    
    FigBase *fg[] = {&r1, &c1, &c2, &s1, &s2};

    for(int i = 0; i < 5; i++){
        (*fg[i]).ler();
        //ou fg[i]->ler();
        cout <<":--------------------:\n"<< endl;
    }

    for(int i = 0; i < 5; i++){
        fg[i]->imprime();
        cout <<":--------------------:\n"<< endl;
    }

    for(int i = 0; i < 5; i++){
        if(c = dynamic_cast<Circulo *>(fg[i])){
            c->setRaio(2 * c->getRaio());
            c->imprime();
        }
    }

    return 0;
}