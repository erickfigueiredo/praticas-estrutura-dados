/*
TAD MyVec
- Representa uma lista implementada por contiguidade
- Interface similar a da classe Vector do STL
- Criado por Salles Magalhaes em 19/02/2018

*/

#ifndef MyVec_H__
#define MyVec_H__

#include <iostream>
#include <string>
#include <ostream>

//Excessao usada pela classe MyVec
class MyVecException {
private:
	std::string msg;
public:
	MyVecException (const std::string &msg0): msg(msg0) { }
	const std::string & what() const { return msg; }
};

template<class T>
class MyVec {
public:
	template<class T2>
	friend std::ostream& operator<<(std::ostream &, const MyVec<T2> &);

	//construtores/destrutures/etc
	MyVec();
	MyVec(int n, const T&init=T());

	//destrutor
	~MyVec() { destroy(); };

	//Construtor de copia
	MyVec(const MyVec &);
	MyVec & operator=(const MyVec &);

	//funcoes de acesso
	T &operator[](int pos) {return data[pos];}
	const T &operator[](int pos) const {return data[pos];}
	void push_back(const T&);
	void resize(int newSize);
	void insert(const T&,int pos);
	void clear();

	int eraseMatchingElements(const T&);
	void sortedInsert(const T&);

	void empty() const {return size() == 0;};
	int size() const {return dataSize;};


private:
	T *data; //membro de dados data, que devera armazenar os elementos da lista
	int dataSize; //quantos elementos ha na lista?
	int dataCapacity; //quantos elementos atualmente cabem na lista? 

	void create();
	void destroy();
	void resizeCapacity(int newCapacity);
};

template<class T>
void MyVec<T>::push_back(const T&elem) {
	if(dataSize == dataCapacity){
		if(dataCapacity == 0){
			resizeCapacity(1);
		}else{
			resizeCapacity(2 * dataCapacity);
		}
	}
	data[dataSize++] = elem;
}

template<class T>
void MyVec<T>::resize(int newSize) {
	if(newSize >= dataCapacity) { //primeiro temos que realocar o vector...
		resizeCapacity(newSize); //para o resize vamos usar o tamanho exato caso seja necessario realocar o vector..
	}

	for(int i = dataSize;i<newSize;i++) { //preencha a parte "extra" do vector com valores "em branco"
		data[i] = T();
	}

	dataSize = newSize;
}

template <class T>
void MyVec<T>::sortedInsert(const T& elem){

	if(dataSize == 0){
		insert(elem, 0);
		return;
	}
	
	int i = 0;

	for(i = 0; i < dataSize; i++){
		if(elem <= data[i]){
			insert(elem, i);
			return;
		}
	}

	insert(elem, i);
}

/*
Exercicio: como alocar mais memoria poderia ajudar?
	Resposta: Alocando mais memorias criariamos um novo vetor que copiaria os elementos para suas novas posições em um único for,
	sem a necessidade de mover todos os elementos a frente do match uma casa à esquerda por vez.

Exercício (escreva a resposta a esse exercício em comentários por cima da sua implementação da funcao eraseMatchingElements): 
qual a ordem de complexidade (pior caso) da função eraseMatchingElements ? e’ possivel melhorar isso?
	Resposta: O(n²), sim poderiamos criar outro vetor e copiar para o vetor do objeto apenas os elementos queridos pelo usuário,
	tendo assim um algoritmo O(n).

*/

template<class T>
int MyVec<T>::eraseMatchingElements(const T& elem){

	int dataSizeOriginal = dataSize;

		for(int i = 0; i < dataSize; i++){
			if(data[i] == elem){
				for(int j = i; j < dataSize-1; j++){
					data[j] = data[j+1];
				}
				dataSize--;
				i--;
			}
		}

	return dataSizeOriginal-dataSize;
}

//insere o elemento na posicao pos e move os elementos ja presentes no vetor
// pos pode ser:
//   uma posicao apos o final do vetor (para inserir na ultima posicao) 
//   ou uma posicao ja existente (nesse caso os elementos nessa posicao e apos ela serao movidos "para a frente")

template<class T>
void MyVec<T>::insert(const T&elem,int pos) {
	if(pos > dataSize || pos < 0) {
		throw MyVecException("Erro na funcao insert: posicao invalida");
	}

	if(dataSize == dataCapacity) { //preciso redimensionar?
		if(dataCapacity == 0)
		/*
		Exercicio: Por que e' preciso testar isso?
			Resposta: Precisamos fazer essa verificação, pois como estamos por padrão multiplicando a dataCapacity por 2
			sendo este 0, o aumento da capacidade nunca ocorreria.
		*/
			resizeCapacity(1);
		else
			resizeCapacity(dataCapacity*2);
	}	

	for(int i=dataSize;i>pos;i--)
		data[i] = data[i-1];
	data[pos] = elem;
	dataSize++;
}

template<class T>
void MyVec<T>::clear() {
	destroy();
	create();
}

template<class T>
void MyVec<T>::resizeCapacity(int newCapacity) {
	if(dataCapacity < newCapacity){
		T *newData = new T[dataSize];

		for(int i = 0; i < dataSize; i++) newData[i] = data[i];

		delete []data;
		dataCapacity = newCapacity;
		data = new T[dataCapacity];

		for(int i = 0; i < dataCapacity; i++){
			if(i < dataSize)
				data[i] = newData[i];
			else
				data[i] = T();
		}

		delete []newData;
	}
}

template<class T>
void MyVec<T>::destroy() {
	delete []data;
	dataSize = dataCapacity = 0;
}

template<class T>
void MyVec<T>::create() {
	data = NULL;
	dataSize = dataCapacity = 0;
}

template<class T>
MyVec<T>::MyVec() {
	create();
}

template<class T>
MyVec<T>::MyVec(int n, const T&init) {
	dataSize = dataCapacity = n;
	data = new T[n];

	for(int i = 0; i < dataSize; i++) data[i] = init;
}


//Construtor de copia
template<class T>
MyVec<T>::MyVec(const MyVec &other) {
	this->data = NULL;
	*this = other;
}

template<class T>
MyVec<T> & MyVec<T>::operator=(const MyVec &other) {
	if(this==&other) return *this; 
	destroy();
	/*
	Exercicio: por que precisamos disso?
		Resposta: Precisamos da função destroy para redefinir o objeto chamado, desalocando a memória utilizada 
		por ele e redefinir os valores de dataSize e dataCapacity para zero.
	*/
	dataCapacity = other.dataCapacity;
	dataSize = other.dataSize;
	/*
	Exercicio: data = other.data; <- por que nao podemos fazer isso?
		Resposta: Sem a sobrecarga do operador de atribuição, teriamos a cópia bit a bit do objeto. Porém como
		estamos dentro da implementação da sobrecarga do operador de atribuição não podemos fazer essa operação,
		pois chamaria o próprio operador em um loop infinito ou faria a cópia bit a bit.
	*/
	data = new T[dataCapacity];
	for(int i=0;i<dataSize;i++) data[i] = other.data[i];
	return *this;
}

template<class T2>
std::ostream& operator<<(std::ostream &out, const MyVec<T2> &v) {
	out << "Size: " << v.size() << "\n";
	out << "Capacity: " << v.dataCapacity << "\n";
	for(int i=0;i<v.size();i++) out << v.data[i] << " ";
	out << "\n";
	return out;
}

#endif