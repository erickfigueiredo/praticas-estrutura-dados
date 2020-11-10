#include <iostream>

using namespace std;


// Insira aqui o codigo para a etapa 1....

//Voce pode adicionar includes como o abaixo...
#include "MyStack.h"
#include "MyQueue.h"
#include "MyQueue2.h"
#include <string>


void etapa1() {
	MyStack<int> mst;
	MyQueue<int> mq;

	int num;

	for(int i = 0; i < 6; i++){
		cin >> num;

		// Adicionamos o elemento nas estruturas
		mst.push(num);
		mq.push(num);
	}

	// Exibimos o topo da pilha e removemos esse elemento
	for(int i = 0; i < 6; i++){	
		cout << mst.top() << " ";
		mst.pop();
	}
	cout << endl;

	// Exibimos o primeiro elemento e removemos este da lista
	for(int i = 0; i < 6; i++){
		cout << mq.front() << " ";
		mq.pop();
	}
	cout << endl;

	/*
	Resposta: A diferença entre o funcionamento da Lista e da da Pilha é que esta última funciona no sistema LIFO, ou seja o último elemento
	a entrar é o primeiro a sair, diferentemente da fila onde o primeiro a entrar é o primeiro a sair.
	*/
}

//---------------------------------------

// Insira aqui o codigo para a etapa 2....

void etapa2() {
	MyStack<char> mst; 
	
	char c;
	
	// Enquanto puder ler
	while(cin >> c){
		// Se for qualquer um dos simbolos abrindo, adincionamos este na pilha
		if(c == '{' || c == '[' || c == '('){
			mst.push(c);
		// Verificamos se o item lido é algum dos simbolos fechando
		}else if(c == '}' || c == ']' || c == ')'){
			// Se for mas a pilha estiver vaiza, trata-se de uma inconsistencia
			if(mst.empty()){
				cout << "Inconsistente" << endl;
				return;
			}
			
			// Se os simbolos de abertura e fechamento casam, podemos retira-los da pilha
			if(c == ')' && mst.top() == '('){
				mst.pop();
			}else if(c == ']' && mst.top() == '['){
				mst.pop();
			}else if(c == '}' && mst.top() == '{'){
				mst.pop();

			// Se a pilha não esta vazia e os elementos ainda sim não casam, há inconsistencia
			}else{
				cout << "Inconsistente" << endl;
				return;
			}
		}
	}

	// Ao final, se a pilha foi completamente esvaziada significa que os simbolos existentes casaram
	if(mst.empty()){
		cout << "Consistente" << endl;
	}else{
		cout << "inconsistente" << endl;

	}
}


//---------------------------------------

// Na etapa 3 voce deve implementar MyQueue2.h e descomentar os codigos de teste abaixo...

void etapa3() {
	char operacao;
	MyQueue2<string> q;

	//le um arquivo contendo "comandos" para a fila e aplica-os a fila criada com sua classe...
	while(cin>> operacao) {
		if(operacao=='p') {
			string st;
			cin >> st;
			q.push(st); //insere um novo elemento na sua fila...
		} else if(operacao=='f') {
			cout << q.front() << "\n";
		} else if(operacao=='P') {
			q.pop();
		} else if(operacao=='e') {
			cout << ((q.empty())?"vazia":"cheia") << "\n";
		} else cout << q.size() << "\n";
	}	
}

//---------------------------------------

// Insira aqui o codigo para a etapa 4....


void etapa4() {
	MyStack<int> mst;

	int nums, index = 0;

	// Le o número de elementos
	cin >> nums;

	for(int i = 0; i < nums; i++) {
		int n;
		cin >> n;

		// Se n for maior que index preenchemos a pilha até n-1 e passamos para a próx iteração
		if(n > index) {
			// Nao precisamos inserir n na pilha, pois se ele foi impresso é porque já saiu
			for(int j = index+1; j < n; j++)
				mst.push(j);

			index = n;
			// Pula para a prox. iteração
			continue;
		}

		// Se n ==  index ou n não estiver no topo da pilha, significa que a sequencia não é possível
		if(n == index || n != mst.top()){
			cout << "NAO" << endl;
			return;
		}

		// Removemos o elemento
		mst.pop();
	}
	cout << "SIM" << endl;
}

//---------------------------------------


int main() {
	int etapa;
	cin >> etapa;
	switch(etapa) {
		case 1:
			cout << "Etapa 1" << endl;
			etapa1();
			break;
		case 2:
			cout << "Etapa 2" << endl;
			etapa2();
			break;
		case 3:
			cout << "Etapa 3" << endl;
			etapa3();
			break;
		case 4:
			cout << "Etapa 4" << endl;
			etapa4();
			break;
	}
}