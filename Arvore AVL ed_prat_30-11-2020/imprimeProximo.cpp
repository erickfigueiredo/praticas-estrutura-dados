#include <iostream>
#include "MySet.h"

using namespace std;

int main() {
    MySet<int> set;

    char action;
    int num;

    while(cin>>action>>num) {

        if(action == 'C') {
            set.insert(num);
        } else {
            MySet<int>::iterator it = set.find(num);

            if (it != NULL){
                it++;
                if(it != set.end())
                    cout << *it << '\n';
                else
                    cout << "FALHA\n";    
            }
            else
                cout << "FALHA\n";
        }
    }
    return 0;
}