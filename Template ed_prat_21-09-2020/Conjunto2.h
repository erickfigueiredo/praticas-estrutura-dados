#ifndef CONJUNTO2_H
#define CONJUNTO2_H

#include <iostream>
using namespace std;

template <class T>
class Conjunto;

template <class T>
ostream &operator<<(ostream &, const Conjunto<T> &);

template <class T>
istream &operator>>(istream &, Conjunto<T> &);

template <class T>
class Conjunto{
    friend ostream &operator<< <T>(ostream &, const Conjunto<T> &);
    friend istream &operator>> <T>(istream &, Conjunto<T> &);

    public:
        Conjunto(int = 10);
        Conjunto(const Conjunto<T>&);
        ~Conjunto();

        int getNumArray() const { return numArray; }
        void incNElementos();

        bool pertence (const T&) const;
        bool insere(const T&);
        int numelementos() const;

        bool operator== (const Conjunto<T>&) const;
        Conjunto<T>& operator=(const Conjunto<T>&);
        Conjunto<T> operator+(const Conjunto<T> &);
        Conjunto<T> operator*(const Conjunto<T> &);
        Conjunto<T> operator-(const Conjunto<T> &);
        T& operator[](int i){return c[i];}
        const T& operator[](int i) const{return c[i];}

    private:
        int numElementos = 0, numArray = 0;
        T *c;
};

template <class T>
Conjunto<T>:: Conjunto(int n){
    numArray = n;
    c = new T[n];

    for(int i = 0; i < n; i++)
        c[i] = T(); //Contrutor padrão do tipo T, que retorna 0
}

template <class T>
Conjunto<T>:: Conjunto(const Conjunto<T> &other){
    this->c = NULL;
    *this = other;
}

template <class T>
Conjunto<T>::~Conjunto(){
    delete []c;
}

template <class T>
void Conjunto<T>::incNElementos(){
    numElementos++;
}

template <class T>
int Conjunto<T>::numelementos() const{
    return numElementos;
}

template <class T>
bool Conjunto<T>::pertence(const T &t) const{
    const int n = numelementos();

    for(int i = 0; i < n; i++)
        if(c[i] == t)
            return true;
    
    return false;
}

template <class T>
bool Conjunto<T>::insere(const T &t){
    if(!pertence(t) && getNumArray() > numelementos()){
        c[numelementos()] = t;
        incNElementos();
        return true;
    }
    return false;
}

template <class T>
bool Conjunto<T>::operator==(const Conjunto<T> &other) const{
    if(&other == this) return true;

    if(this->numelementos() == other.numelementos()){
        for(int i = 0; i < this->numelementos(); i++){
            if(!this->pertence(other.c[i])){
                return false;
            }
        }
        return true;
    }
    return false;
}

template <class T>
Conjunto<T>& Conjunto<T>::operator=(const Conjunto<T>& other){
    if(this == &other) {return *this;}

    delete []this->c;
    this->numArray = other.getNumArray();
    this->numElementos = other.numelementos();

    this->c = new T[this->getNumArray()];

    for(int i = 0; i < this->getNumArray(); i++){
        this->c[i] = other.c[i];
    }

    return *this;
}

template <class T>
Conjunto<T> Conjunto<T>::operator+(const Conjunto<T> &other){

    Conjunto<T> u(this->getNumArray() + other.getNumArray());

    for(int i = 0; i < this->numElementos; i++)
        u.insere(this->c[i]);
    
    for(int i = 0; i < other.numElementos; i++)
        u.insere(other.c[i]);

    return u;
}

template <class T>
Conjunto<T> Conjunto<T>::operator*(const Conjunto<T> &other){

    Conjunto<T> u;
    
    if(this->getNumArray()>=other.getNumArray()){
        u.numArray = other.getNumArray();
        u.c = new T[u.getNumArray()];

        for(int i = 0; i < other.numElementos; i++){
            if(this->pertence(other.c[i])){
                u.insere(other.c[i]);
            }
        }
    }else{
        u.numArray = this->getNumArray();
        u.c = new T[u.getNumArray()];

        for(int i = 0; i < this->numElementos; i++){
            if(other.pertence(this->c[i])){
                u.insere(this->c[i]);
            }
        }
    }
    
    return u;
}

template <class T>
Conjunto<T> Conjunto<T>::operator-(const Conjunto<T> &other){

    Conjunto<T> u;
    
    u.numArray = this->getNumArray();

    u.c = new T[u.getNumArray()];

    for(int i = 0; i < this->numElementos; i++){
        if(!other.pertence(this->c[i])){
            u.insere(this->c[i]);
        }
    }

    return u;
}

template <class T>
ostream &operator<<(ostream &os,const Conjunto<T> &conjunto){
	const int n = conjunto.numElementos;
    os << "{";
    for(int i = 0; i < n; i++){
        if(i == n-1){
            os << conjunto.c[i];
            break;
        }
        os << conjunto.c[i]<<",";
    }
    os << "}";
	return os;
}

template <class T>
istream &operator>>(istream &is, Conjunto<T> &conjunto){
    T c;
    
    //enquanto puder ser lido eh interpretado como TRUE
    while(is >> c){
        conjunto.insere(c);
    }
    return is;
}

#endif