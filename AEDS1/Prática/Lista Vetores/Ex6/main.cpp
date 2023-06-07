#include <bits/stdc++.h>
#include <math.h>
#include "cores.h"
#define TAM 10

using namespace std;

int main(int argc, char const *argv[])
{
    int qtd, qtd2,total, k;
    float vetor[TAM], vetor2[TAM], vetorFinal[TAM+TAM];
    total = 0;

    ifstream arquivo("vetores.txt");
    if (!arquivo.is_open())
    {
        cout << vermelho_G "Erro: Arquivo não encontrado." reset << endl;
        return 1;
    }

    arquivo >> qtd;

    for (int i = 0; i < qtd; i++)
    {
        arquivo >> vetor[i];
    }

    arquivo >> qtd2;
    for (int i = 0; i < qtd2; i++){
        arquivo >> vetor2[i];
    }
    total = qtd + qtd2;

    cout << "Vetor 1 Inicial: " vermelho_N " [ ";
            for (int i = 0; i < qtd - 1; i++)
            {
                cout << vetor[i] << ", ";
            }
    cout << vetor[qtd - 1] << " ] " reset << endl;


    cout << "Vetor 2 Inicial: " vermelho_N " [ ";
            for (int i = 0; i < qtd2 - 1; i++)
            {
                cout << vetor2[i] << ", ";
            }
    cout << vetor2[qtd2 - 1] << " ] " reset << endl;

    
    for(int i = 0; i < qtd; i++){
        vetorFinal[i] = vetor[i];
    }

    total = qtd+1;
    for(int i = 0; i < qtd; i++){
        for(int j = 0; j < qtd2; j++){
            if(vetorFinal[i] != vetor2[j]){
                vetorFinal[k] = vetor2[j];
                total++;
            }
        }
    }


    cout << "União dos vetores 1 e 2: " vermelho_N " [ ";
            for (int i = 0; i < k - 1; i++){
                cout << vetorFinal[i] << ", ";
            }
    cout << vetorFinal[k - 1] << " ] " reset << endl;

arquivo.close();
}