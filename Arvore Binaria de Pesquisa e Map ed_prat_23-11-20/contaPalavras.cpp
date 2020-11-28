#include <iostream>
#include <cstring>

#include "MyVecNewIterator.h"
#include "MySet.h"
using namespace std;

int main(int argc, char **argv)
{
    //IMPORTANTE: argv[0] sempre guarda o nome do programa

    int numPalavras = 0;
    string palavra;

    if (argv[1] == "myvec")
    {
        MyVec<string> frase;
        bool flag = true;

        while (cin >> palavra)
        {
            numPalavras++;
            for (int i = 0; i < frase.size(); i++)
                if (frase[i] == palavra)
                {
                    flag = false;
                    break;
                }

            if (flag)
                frase.push_back(palavra);

            flag = true;
        }

        cout << numPalavras << " " << frase.size() << endl;
    }
    else
    {
        MySet<string> frase;

        while (cin >> palavra)
        {
            numPalavras++;
            frase.insert(palavra);
        }

        cout << numPalavras << " " << frase.size() << endl;
    }

    return 0;
}