#include <iostream>
#include "MyMap.h"

using namespace std;

int main()
{
    MyMap<string, int> map;
    string palavra;

    int cont = 0;

    MyMap<string, int>::iterator it = nullptr;
    while (cin >> palavra)
    {
        it = map.find(palavra);
        if (it == NULL)
            map[palavra] = cont++;

        cout << palavra << " " << map[palavra] << endl;
    }
    return 0;
}