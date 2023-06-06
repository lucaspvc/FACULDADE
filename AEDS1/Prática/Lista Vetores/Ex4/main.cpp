#include <bits/stdc++.h>
#include <math.h>
#include "cores.h"
#define TAM 40

using namespace std;

int main(int argc, char const *argv[])
{
    float x, vetor1[TAM], vetor2[TAM], vetor3[TAM], maiorvalor, valor, menorvalor;
    char q;
    int k, j, cont, newop, posmenor, posmaior;
    maiorvalor = k = cont = newop = j = x = 0;
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

    for (int i = 0; i < TAM; i++)
    {
        if(vetor1[i] < menorvalor){
            menorvalor = vetor1[i];
        } 
        if (vetor1[i] > maiorvalor){
            maiorvalor = vetor1[i];
        }
    }

    while (newop != 6)
    {
        cout << "[1] Encontrar o menor e o maior valor do vetor." << endl;
        cout << "[2] Procura de um valor no vetor." << endl;
        cout << "[3] Número de ocorrências de um valor no vetor." << endl;
        cout << "[4] Se o valor for par, multiplica por 2. Caso contrário atribui 0." << endl;
        cout << "[5] Incrementação do vetor com o fator inserido." << endl;
        cout << "[6] Sair do programa." << endl;
        cout << "Insira a opção desejada: ";
        cin >> newop;
        switch (newop)
        {
        case 1:
            for (int i = 0; i < TAM; i++)
            {
                if (vetor1[i] <= menorvalor)
                {
                    menorvalor = vetor1[i];
                    vetor2[j] = i;
                    j++;
                }
                if (vetor1[i] >= maiorvalor)
                {
                    maiorvalor = vetor1[i];
                    vetor3[k] = i;
                    k++;
                }
            }
            cout << "O menor valor é: " amarelo_N << menorvalor << reset " na(s) posição(s): " amarelo_N;
            for (int i = 0; i < j; i++)
            {
                cout << vetor2[i] << " ";
            }
            cout << endl;
            j = 0;

            cout << reset "O maior valor é: " amarelo_N << maiorvalor << reset " na(s) posição(s): " amarelo_N;
            for (int i = 0; i < k; i++)
            {
                cout << vetor3[i] << " ";
            }
            cout << endl;
            k = 0;

            cout << reset "Deseja sair do programa? S/N" << endl;
            cin >> q;
            while (q != 'n' && q != 'N')
            {
                if (q == 'S' || q == 's')
                {
                    newop = 6;
                    cout << vermelho_G "Programa finalizado." reset << endl;
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
            cout << "Insira o valor a ser procurado: ";
            cin >> valor;

            for (int i = 0; i < TAM; i++)
            {
                if (valor == vetor1[i])
                {
                    vetor2[j] = i;
                    j++;
                }
            }

            cout << "O valor " amarelo_N << valor << reset " foi encontrado na(s) posição(s): ";
            for (int i = 0; i < j; i++)
            {
                cout << amarelo_N << vetor2[i] << " " reset;
            }
            j = 0;

            cout << "\nDeseja sair do programa? S/N" << endl;
            cin >> q;
            while (q != 'n' && q != 'N')
            {
                if (q == 's' || q == 'S')
                {
                    newop = 6;
                    cout << vermelho_G "Programa finalizado." reset << endl;
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
            cout << "Insira o valor a ser procurado: ";
            cin >> valor;

            for (int i = 0; i < TAM; i++)
            {
                if (valor == vetor1[i])
                {
                    j++;
                }
            }

            cout << "O valor " amarelo_N << valor << reset " ocorre " amarelo_N << j << reset " vezes no vetor." << endl;
            j = 0;

            cout << "Deseja sair do programa? S/N" << endl;
            cin >> q;
            while (q != 'n' && q != 'N')
            {
                if (q == 's' || q == 'S')
                {
                    newop = 6;
                    cout << vermelho_G "Programa finalizado." reset << endl;
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
        case 4:
            for (int i = 0; i < TAM; i++)
            {
                if ((int)vetor1[i] % 2 == 0)
                {
                    vetor2[i] = vetor1[i] * 2;
                }
                else
                {
                    vetor2[i] = 0;
                }
            }
            cout << "Vetor final: " amarelo_N " [ ";
            for (int i = 0; i < TAM - 1; i++)
            {
                cout << vetor2[i] << ", ";
            }
            cout << vetor2[TAM - 1] << "] " reset << endl;

            cout << "Deseja sair do programa? S/N" << endl;
            cin >> q;
            while (q != 'n' && q != 'N')
            {
                if (q == 's' || q == 'S')
                {
                    newop = 6;
                    cout << vermelho_G "Programa finalizado." reset << endl;
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
        case 5:
            cout << "Insira o fator de incrementação: ";
            cin >> x;

            for (int i = 0; i < TAM; i++)
            {
                vetor2[i] = vetor1[i] + x;
                if (vetor2[i] < 0)
                {
                    vetor2[i] = 0;
                }
                else if (vetor2[i] > 255)
                {
                    vetor2[i] = 255;
                }
            }
            cout << "Caso o valor final seja maior que 255, limita-se em 255." << endl;
            cout << "Caso o valor final seja menor que 0, limita-se em 0." << endl;

            cout << "Vetor final: " amarelo_N " [ ";
            for (int i = 0; i < TAM - 1; i++)
            {
                cout << vetor2[i] << ", ";
            }
            cout << vetor2[TAM - 1] << "] " reset << endl;

            cout << "Deseja sair do programa? S/N" << endl;
            cin >> q;
            while (q != 'n' && q != 'N')
            {
                if (q == 's' || q == 'S')
                {
                    newop = 6;
                    cout << vermelho_G "Programa finalizado." reset << endl;
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
        default:
            cout << vermelho_G "Programa finalizado." reset << endl;
        }
    }
arquivo.close();
}