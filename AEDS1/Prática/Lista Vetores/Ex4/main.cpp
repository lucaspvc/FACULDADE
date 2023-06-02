#include <bits/stdc++.h>
#include <math.h>
#include "cores.h"
#define TAM 10

using namespace std;

int main(int argc, char const *argv[])
{
    float vetor1[TAM], vetor2[TAM], maiorvalor, menorvalor;
    char q;
    int x, y, cont, newop, posmenor, posmaior;
    maiorvalor = cont = newop = 0;
    menorvalor = MAXFLOAT;
    

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

    while (newop != 6)
    {
        cout << "[1] Encontrar o menor e o maior valor do vetor." << endl;
        cout << "[2] ." << endl;
        cout << "[3] " << endl;
        cout << "[4] Ordenação por placa." << endl;
        cout << "[5] " << endl;
        cout << "[6] Sair do programa." << endl;
        cout << "Insira a opção desejada:" << endl;
        cin >> newop;
        switch (newop)
        {
        case 1:
            for (int i = 0; i < TAM; i++)
            {
                if (vetor1[i] < menorvalor)
                {
                    menorvalor = vetor1[i];
                    posmenor = i;
                }
                else if (vetor1[i] > maiorvalor)
                {
                    maiorvalor = vetor1[i];
                    posmaior = i;
                }
            }
            cout << "O menor valor é: " amarelo_N<< menorvalor << reset " na posição: " amarelo_N<< posmenor << endl;
            cout << reset "O maior valor é: " amarelo_N << maiorvalor << reset " na posição: " amarelo_N << posmaior << reset <<  endl;

            cout << "Deseja sair do programa? S/N" << endl;
            cin >> q;
            while (q != 'n' && q != 'N'){
                if (q == 'S' || q == 's')
                {
                    newop = 6;
                    break;
                }
                else
                {
                    cout << "Opção inválida." << endl;
                    cout << "Deseja sair do programa? S/N" << endl;
                    cin >> q;
                }
            }
            break;

        case 2:

            cout << "Deseja sair do programa? S/N" << endl;
            cin >> q;
            while (q != 'n' && q != 'N')
            {
                if (q == 's' || q == 'S')
                {
                    newop = 6;
                    break;
                }
                else
                {
                    cout << "Opção inválida." << endl;
                    cout << "Deseja sair do programa? S/N" << endl;
                    cin >> q;
                }
            }
            break;

        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            cout << vermelho_G "Programa finalizado." reset << endl;
        }

        for (int i = 0; i < TAM; i++)
        {
            if (vetor1[i] > x && vetor1[i] < y)
            {
                vetor2[cont] = vetor1[i];
                cont++;
            }
        }
    }

    /*cout << "Vetor final: " magenta_N "[";
    for (int i = 0; i < cont - 1; i++)
    {
        cout << vetor2[i] << ", ";
    }
    cout << vetor2[cont - 1] << "] " reset << endl;*/

    return 0;
}
