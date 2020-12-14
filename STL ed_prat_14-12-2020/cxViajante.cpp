#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calcular_caminho( const vector< vector <int>>&matriz, const vector <int>&caminho){
    int soma = 0;
    for (int i=0; i<caminho.size()-1; i++){
        soma += matriz[caminho[i]][caminho[i+1]];
    }
    soma += matriz[caminho[caminho.size()-1]][caminho[0]];
    return soma;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> matriz(n);
    vector<int> caminho(n);
    
    for (int i=0; i<n; i++){
        caminho[i] = i;
        for (int j=0; j<n; j++){
            int distancia;
            cin >> distancia;
            matriz[i].push_back(distancia);
        }
    }

    int menor = calcular_caminho(matriz,caminho);
    while(next_permutation(caminho.begin(), caminho.end())){
        menor = min(calcular_caminho(matriz,caminho), menor);
    }

    cout << menor << endl;
}