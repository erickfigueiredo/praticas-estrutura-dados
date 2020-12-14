#include <iostream>
#include "MyVecNewIterator.h"

using namespace std;

int main()
{
    MyVec<int> digitos(11, 0);

    int d, qtd, sum = 0;
    string CPF;

    cin >> qtd;

    for (int i = 0; i < qtd; i++)
    {
        cin >> CPF;
        cin.ignore();

        for (int j = 0; j < 9; j++)
        {
            digitos[j] = CPF[j] - '0';

            sum += (10 - j) * digitos[j];
        }

        d = (sum * 10) % 11;
        sum = 0;

        if (d != 10)
            digitos[9] = d;
        else
            digitos[9] = 0;

        for (int j = 0; j < 10; j++)
            sum += (11 - j) * digitos[j];

        d = (sum * 10) % 11;
        sum = 0;

        if (d != 10)
            digitos[10] = d;
        else
            digitos[10] = 0;

        cout << digitos[9] << digitos[10] << '\n';
    }

    return 0;
}