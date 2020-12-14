#include <iostream>
#include <map>
#include <numeric> // Numeric possui accumulate
#include <algorithm> // Count_if
using namespace std;

// Usando iterators da forma tradicional
double calcCRA1(map<string,double> &d){
    map<string, double>::iterator it = d.begin();

    double average = 0;

    while(it != d.end()){
        average += (*it).second;
        it++;
    }

    average /= d.size();

    return average;
}

// Usando "rage-based"
double calcCRA2(map<string,double> &d) {
    double average = 0;
    
    for(const auto& p : d) // Para cada pair <string, int> p em d
        average += p.second;
    
    average /= d.size();

    return average;
}

// Usando Structure binding | Disponivel no c++ 17
double calcCRA3(map<string,double> &d){
    double average = 0;

    for(const auto &[k,v] : d)
        average += v;
    
    average /= d.size();

    return average;
}

// Usando a Função acumulate | Disponível no c++ 11
double calcCRA4(map<string,double> &d){
    
    double average = accumulate(d.begin(), d.end(), 0, [](double v, const pair<string, double> &p){return v + p.second;})/(double)d.size();

    return average;
}

void printAsc(map<string, double> &d) {
    map <string, double>::iterator it = d.begin();
    cout << "Exibindo o resultado em ordem Crescente: \n";
    while(it != d.end()){
        cout << (*it).first << ' ' << (*it).second << '\n';
        it++;
    }
}

void printDesc(map<string, double> &d) {
    map<string, double>::reverse_iterator it = d.rbegin();  //Inicia do final
    cout << "Exibindo o resultado em ordem Decrescente: \n";
    while(it != d.rend()){
        cout << (*it).first << ' ' << (*it).second << '\n';
        it++;
    }
}

void numApproved(map<string, double> &d) {
    int num = count_if(d.begin(), d.end(), [](const pair<string, double> &p){if(p.second >=6) return true; return false;});

    cout << "Aprovados: " << num <<'\n';
}

int main() {
    map<string,double> diary;

    diary["Erick"] = 10;
    diary["Renata"] = 9.6;
    diary["Carolina"] = 8.1;
    diary["Fernanda"] = 3.9;
    diary["Junior"] = 10;
    diary["Patricio"] = 6.3;
    diary["Emanuelle"] = 7.1;
    diary["Zelia"] = 8.1;

    cout << calcCRA1(diary) << '\n';
    cout << calcCRA2(diary) << '\n';
    cout << calcCRA3(diary) << '\n';
    cout << calcCRA4(diary) << '\n';

    printAsc(diary);
    printDesc(diary);

    numApproved(diary);
}