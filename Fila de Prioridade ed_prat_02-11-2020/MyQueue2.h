#ifndef MyQueue2_H__
#define MyQueue2_H__

#include "MyStack.h"
#include <iostream>
using namespace std;

template<class T>
class MyQueue2 {
public:
	MyQueue2() {} 

	void push(const T&el);
	const T front() ; //Nesta implementacao vamos permitir retorno por copia...
	void pop() ;

	bool empty() ;
	int size() ;

private:
	MyStack<T> pilha1; //nao mude nada nessa interface!!!
	MyStack<T> pilha2; //nao mude nada nessa interface!!!
};


template<class T>
void MyQueue2<T>::push(const T&el){
	// Vai inserir na pilha 1
	pilha1.push(el);
}

template<class T>
void MyQueue2<T>::pop(){
	// Se a pilha 2 estiver vazia, copia os dados da pilha 1 para a pilha 2, dando o pop na pilha1
	if(pilha2.empty()){
		while(!pilha1.empty()){
			// Assim o último elemento de p1, será o primeiro de p2
			pilha2.push(pilha1.top());
			pilha1.pop();
		}
	}

	if(!pilha2.empty())
		// Remove o elemento do topo da pilha 2, que representa o primeiro da lista
		pilha2.pop();
	
}

template<class T>
const T MyQueue2<T>::front(){
	// Se a pilha 2 estiver vazia, copia os dados da pilha 1 para a pilha 2, dando o pop na pilha1
	if(pilha2.empty()){
		while(!pilha1.empty()){
			// Assim o último elemento de p1, será o primeiro de p2
			pilha2.push(pilha1.top());
			pilha1.pop();
		}
	}

	if(!pilha2.empty())
		// Retorna o primeiro elemento da fila
		return pilha2.top();
	
	// Se a lista estiver vazia, retornamos o construtor padrão do tipo armazenado na lista
	return T();
}

template<class T>
bool MyQueue2<T>::empty(){
	return (pilha1.empty() && pilha2.empty());
}

template<class T>
int MyQueue2<T>::size(){
	return pilha1.size() + pilha2.size();
}

#endif