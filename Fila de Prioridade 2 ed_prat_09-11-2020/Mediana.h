#ifndef MEDIANA_H
#define MEDIANA_H

#include "MyPriorityQueue.h"
#include <cmath>

class Mediana {
public:
	// Insere o elemento X na estrutura de dados
	void insere(int el);

	// Retorna a mediana dos números já inseridos 
	int getMediana();

private:
	MyPriorityQueue <int> fila1, fila2;
	int index = 0;
};

#endif