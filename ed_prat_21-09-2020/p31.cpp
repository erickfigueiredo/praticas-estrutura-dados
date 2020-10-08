#include "Conjunto2.h"
#include <iostream>

int main(){
    int n;
    cin >> n;
    Conjunto<int> a(n), b(n); 
    for(int i = 0; i < n; i++){
        a.insere(i+1);
        b.insere(i+1);
    }
    Conjunto<int> c = a + b;
    cout << c.pertence(10) << endl;
}   