#ifndef MEDIANA_H
#define MEDIANA_H

#include <iostream>
#include "MyPriorityQueue.h"
using namespace std;


class Mediana {
public:
	// Insere o elemento X na estrutura de dados
	void insere(int el);

	// Retorna a mediana dos números já inseridos 
	int getMediana();

private:
	MyVec<int> elems;
};

#endif