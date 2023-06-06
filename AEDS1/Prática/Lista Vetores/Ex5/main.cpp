#include <bits/stdc++.h>
#include <math.h>
#include "cores.h"
#define TAM 10

using namespace std;

int main(int argc, char const *argv[])
{
    int qtd;
    float vetor[TAM];

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

    cout << "Vetor Inicial: " vermelho_N " [ ";
            for (int i = 0; i < qtd - 1; i++)
            {
                cout << vetor[i] << ", ";
            }
    cout << vetor[qtd - 1] << " ] " reset << endl;


    cout << "\nEliminando do vetor os números repitidos" << endl;
    for (int i = 0; i < qtd; i++){
        for (int j = i+1; j < qtd; j++){
            if (vetor[i] == vetor[j]){
                for(int k = j; k < qtd; k++){
                    vetor[k] = vetor[k+1];
                }
                qtd--;
            }
        }
    }

    cout << "Vetor Final: " vermelho_N " [ ";
            for (int i = 0; i < qtd - 1; i++)
            {
                cout << vetor[i] << ", ";
            }
    cout << vetor[qtd - 1] << " ] " reset << endl;

arquivo.close();
}