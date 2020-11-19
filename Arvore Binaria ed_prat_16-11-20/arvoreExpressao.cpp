#include <iostream>
#include <cctype>
#include "MyVec.h"
using namespace std;

class ArvoreExpressao
{
public:
	void imprimeArrays() const;

	void leArvore();
	void imprimeExpressao() const;
	int avaliaValor(int index = 0) const;
	int nivelMaisNodos() const;
	int altura() const;

private:
	//Nao adicione nenhum membro de dados na sua classe!!!!
	//Funcoes auxiliares podem ser adicionadas se necessario.
	void calcNodos(int qtdNodos[], int index = 0, int level = 0) const;
	void geraExpressao(int index = 0) const;
	int altura(int nivel) const;

	MyVec<int> filhoEsquerdo;
	MyVec<int> filhoDireito;
	MyVec<char> operador;
};

void ArvoreExpressao::imprimeArrays() const
{
	for (int i = 0; i < filhoEsquerdo.size(); i++)
		cout << i << " ";
	cout << "\n";
	for (int i = 0; i < filhoEsquerdo.size(); i++)
		cout << filhoEsquerdo[i] << " ";
	cout << "\n";
	for (int i = 0; i < filhoDireito.size(); i++)
		cout << filhoDireito[i] << " ";
	cout << "\n";
	for (int i = 0; i < operador.size(); i++)
		cout << operador[i] << " ";
	cout << "\n";
}

/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/
//sua implementacao:

void ArvoreExpressao::leArvore()
{
	int numElems;

	cin >> numElems;

	int index, leftV, rightV;
	char s;

	//Dessa forma garantimos que mesmo não seja inserido em sequencia respeitará a ordem proposta
	for (int i = 0; i < numElems; i++)
	{
		operador.push_back(' ');
		filhoDireito.push_back(-1);
		filhoEsquerdo.push_back(-1);
	}

	for (int i = 0; i < numElems; i++)
	{
		cin >> index >> leftV >> rightV >> s;

		if (leftV > -1)
			filhoEsquerdo[index] = leftV;
		if (rightV > -1)
			filhoDireito[index] = rightV;

		operador[index] = s;
	}
}

void ArvoreExpressao::geraExpressao(int index) const
{
	if (isdigit(operador[index]))
	{
		cout << operador[index];
	}
	else
	{
		if (index)
			cout << '(';

		geraExpressao(filhoEsquerdo[index]);
		cout << operador[index];
		geraExpressao(filhoDireito[index]);

		if (index)
			cout << ')';
	}
}

void ArvoreExpressao::imprimeExpressao() const
{
	geraExpressao();
}

int ArvoreExpressao::avaliaValor(int index) const
{
	if (isdigit(operador[index]))
	{
		//Fazemos isso para obter o valor inteiro representado pelo caractere, pois os numeros estão em sequencia na tabela asc e ZERO está na posição 50
		return operador[index] - '0';
	}
	else
	{
		switch (operador[index])
		{
		case '+':
			return avaliaValor(filhoEsquerdo[index]) + avaliaValor(filhoDireito[index]);
			break;
		case '-':
			return avaliaValor(filhoEsquerdo[index]) - avaliaValor(filhoDireito[index]);
			break;
		case '*':
			return avaliaValor(filhoEsquerdo[index]) * avaliaValor(filhoDireito[index]);
			break;
		}
	}
	return 0;
}

int ArvoreExpressao::altura() const
{
	return altura(0) - 1;
}

int ArvoreExpressao::altura(int nivel) const
{
	int hEsq = 0, hDir = 0;

	if (filhoEsquerdo[nivel] != -1)
		hEsq = altura(filhoEsquerdo[nivel]);

	if (filhoDireito[nivel] != -1)
		hDir = altura(filhoDireito[nivel]);

	return max(hEsq, hDir) + 1;
}

int ArvoreExpressao::nivelMaisNodos() const
{
	const int h = altura() + 1;

	int nodosPorNivel[h] = {0};

	int max = nodosPorNivel[0];
	int nivelPopuloso = 0;

	//Calcula o numero de nodos por nivel
	calcNodos(nodosPorNivel);

	for (int i = 1; i < h; i++)
		if (max < nodosPorNivel[i])
		{
			max = nodosPorNivel[i];
			nivelPopuloso = i;
		}

	return nivelPopuloso + 1;
}

void ArvoreExpressao::calcNodos(int qtdNodos[], int index, int level) const
{
	if (level == index == 0)
		qtdNodos[level]++;

	if (filhoEsquerdo[index] != -1 or filhoDireito[index] != -1)
	{
		qtdNodos[++level]++;

		if (filhoEsquerdo[index] != -1)
			calcNodos(qtdNodos, filhoEsquerdo[index], level);
		if (filhoDireito[index] != -1)
			calcNodos(qtdNodos, filhoDireito[index], level);
	}

	return;
}

/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/

//Nao modifique aqui
//OBS: cada arquivo de teste começa com a descricao de uma arvore.
//A seguir, ha um numero indicando qual etapa sera testada...
int main()
{
	ArvoreExpressao a;
	a.leArvore();

	int etapa;
	cin >> etapa;
	switch (etapa)
	{
	case 1:
		cout << "Etapa 1:" << endl;
		a.imprimeArrays();
		break;
	case 2:
		cout << "Etapa 2:" << endl;
		a.imprimeExpressao();
		cout << endl;
		break;
	case 4:
		cout << "Etapa 4:" << endl;
		cout << a.avaliaValor() << endl;
		break;
	case 5:
		cout << "Etapa 5:" << endl;
		cout << a.altura() << endl;
		cout << a.nivelMaisNodos() << endl;
		break;
	default:
		cout << "Erro! Etapa invalida" << endl;
		break;
	}
}
