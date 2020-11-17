#ifndef MyPriorityQueue2_H
#define MyPriorityQueue2_H


#include "MyVecNewIterator.h"
#include "MyList2NewIterator.h"
#include <iostream>
using namespace std;

//Nao altere nada na interface!
template<class T>
class MyPriorityQueue2 {
public:
	void push(const T&el);
	T & top() ;
	void pop() ;
	int size() ;
private:
	MyList2<T> elementos;
};



//Altere apenas daqui para baixo...

//ATENCAO: propositalmente nao temos funcoes constantes, visto que nao implementamos iteradores
// constantes na nossa classe lista...

//inserção seja O(1),top()/pop() sejam O(n).
template<class T>
void MyPriorityQueue2<T>::push(const T&el) {
	elementos.push_back(el);
}

template<class T>
T & MyPriorityQueue2<T>::top() {
	MyList2Iterator<T> it = elementos.begin();
	MyList2Iterator<T> aux = elementos.begin();

	int cont = 0;

	while(cont < elementos.size()){
		if(*it > *aux)
			aux = it;

		it++;
		cont++;
	}

	return *aux;
}

template<class T>
void MyPriorityQueue2<T>::pop() {
	MyList2Iterator<T> it = elementos.begin();
	MyList2Iterator<T> aux = elementos.begin();

	int cont = 0;

	while(cont < elementos.size()){
		if(*it > *aux)
			aux = it;

		it++;
		cont++;
	}

	elementos.erase(aux);
}

template<class T>
int MyPriorityQueue2<T>::size() {
	return elementos.size();
}

#endif