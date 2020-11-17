#include "Mediana.h"

void Mediana::insere(int el){
    if(!fila1.size())
        fila1.push(el);
    else if(el > fila1.top())
        fila2.push(-el);
    else
        fila1.push(el);

    if(fila1.size() - fila2.size() > 1){
        fila2.push(-fila1.top());
        fila1.pop();
    } else if(fila2.size() - fila1.size() > 1){
        fila1.push(-fila2.top());
        fila2.pop();
    }
}

int Mediana::getMediana(){
    if(fila1.size() == fila2.size())
        return (fila1.top()-fila2.top())/2;
    if(fila1.size() > fila2.size())
        return fila1.top();
    else
        return -fila2.top();
}