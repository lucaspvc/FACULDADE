#include <bits/stdc++.h>
#include <math.h>
#include "cores.h"
#define TAM 10

using namespace std;

int main(int argc, char const *argv[])
{
    float vetor1[TAM], vetor2[TAM];
    int x;

    ifstream arquivo("vetores.txt");
    if (!arquivo.is_open())
    {
        cout << vermelho_G "Erro: Arquivo não encontrado." reset << endl;
        return 1;
    }

    for (int i = 0; i < TAM; i++)
    {
        arquivo >> vetor1[i];
        arquivo >> vetor2[i];
    }

    cout << "Insira o valor [x] a ser multiplicado na expressão ( vetor1[i] = vetor2[i] * x):" << endl;
    cin >> x;

    for (int i = 0; i < TAM; i++)
    {
        vetor1[i] = vetor1[i] + vetor2[i] * x;
    }

    cout << "Vetor final: " magenta_N "[";
    for (int i = 0; i < TAM; i++)
    {
        verde_N;
        cout << vetor1[i];
        if (i < (TAM - 1))
        {
            cout << ", ";
        }
    }
    cout << "] " reset << endl;

    return 0;
}
