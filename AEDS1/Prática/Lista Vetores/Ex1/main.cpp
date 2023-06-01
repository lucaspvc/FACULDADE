#include <bits/stdc++.h> 
#include <math.h> 
#include "cores.h"
#define TAM 10

using namespace std;

int main(int argc, char const *argv[]){
    float vetor1[TAM], vetor2[TAM], vetor3[TAM];
    
    ifstream arquivo("vetores.txt");
    if (!arquivo.is_open()) {
        cout << vermelho_G "\nErro: Arquivo não encontrado." reset << endl;
        return 1;
        }

    for (int i = 0; i < TAM; i++){
        arquivo >> vetor1[i];
        arquivo >> vetor2[i];
        }
    for (int i = 0; i < TAM; i++){
        vetor3[i]=vetor1[i]+vetor2[i];
        }

    cout << "vetor 3: " magenta_N "[";
    for (int i = 0; i < TAM; i++){
        cout << vetor3[i];
        if (i < (TAM-1)){
            cout << ", ";
        }
        }
    cout <<  "] " reset << endl;

    return 0;
}
