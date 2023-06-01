#include <bits/stdc++.h>
#include <math.h>
#include "cores.h"
#define TAM 10

using namespace std;

int main(int argc, char const *argv[])
{
    float vetor1[TAM], vetor2[TAM];
    int x, y, cont;
    cont = 0;
    ifstream arquivo("vetores.txt");
    if (!arquivo.is_open())
    {
        cout << vermelho_G "Erro: Arquivo não encontrado." reset << endl;
        return 1;
    }

    for (int i = 0; i < TAM; i++)
    {
        arquivo >> vetor1[i];
    }

    cout << "Insira o valor inferior a ser comparado:" << endl;
    cin >> x;
    cout << "Insira o valor superior a ser comparado:" << endl;
    cin >> y;


    for (int i = 0; i < TAM; i++)
    {
        if(vetor1[i] > x && vetor1[i] < y){
            vetor2[cont] = vetor1[i];
            cont++;
        }
    }

    cout << "Vetor final: " magenta_N "[";
    for (int i = 0; i < cont; i++)
    {
        cout << vetor2[i];
        if (i < (cont - 1))
        {
            cout << ", ";
        }
    }
    cout << "] " reset << endl;

    return 0;
}
