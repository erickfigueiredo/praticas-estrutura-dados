#include <iostream>
#include <cstring>

#include "MyVecNewIterator.h"
using namespace std;

int main(int argc, char **argv)
{
    //IMPORTANTE: argv[0] sempre guarda o nome do programa
    string opcao = argv[1];

    string palavra;
    int numPalavras = 0;

    if (opcao == "myvec")
    {
        MyVec<string> frase;

        bool insere = true;
        while (cin >> palavra)
        {
            numPalavras++;

            for (int i = 0; i < frase.size(); i++)
                if (frase[i] == palavra)
                {
                    insere = false;
                    break;
                }

            if (insere)
                frase.push_back(palavra);

            insere = true;
        }
    }
    else
    {
        MySet<string> frase;

        while (cin >> palavra)
        {
            numPalavras++;
            frase.insert(palavra);
        }
    }

    cout << numPalavras << " " << frase.size() << endl;

    return 0;
}