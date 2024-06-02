#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <chrono> // Biblioteca para cronometragem

using namespace std;
using namespace std::chrono; // Para facilitar o uso da cronometragem

// Função para calcular a "fitness" de um subconjunto
int calculateFitness(const vector<int>& subset, const vector<int>& elements, int target) {
    int sum = 0;
    for (size_t i = 0; i < subset.size(); ++i) {
        if (subset[i] == 1) { // se o bit e 1, incluimos o elemento na soma
            sum += elements[i];
        }
    }
    return abs(target - sum); // retorna a diferença absoluta para o valor alvo
}

// Função de busca local
void localSearch(vector<int>& bestSubset, const vector<int>& elements, int target, int maxIterations) {
    int bestFitness = calculateFitness(bestSubset, elements, target); // calcula a fitness da solucao inicial
    srand(time(0)); // semente para geracao de números aleatorios

    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        vector<int> newSubset = bestSubset; // cria uma nova solucao vizinha a partir da melhor solucao atual
        int indexToFlip = rand() % elements.size(); // escolhe um indice aleatorio para inverter
        newSubset[indexToFlip] = 1 - newSubset[indexToFlip]; // inverte o bit (0 -> 1 ou 1 -> 0)

        int newFitness = calculateFitness(newSubset, elements, target); // Calcula a fitness da nova solucao
        if (newFitness < bestFitness) { // se a nova solucao for melhor atualiza a melhor solucao encontrada
            bestSubset = newSubset;
            bestFitness = newFitness;
        }

        // parar se encontrarmos uma solucao perfeita (fitness == 0)
        if (bestFitness == 0) {
            break;
        }
    }

    // Imprime o resultado da busca local
    if (bestFitness == 0) {
        cout << "Encontrou um subconjunto que soma exatamente ao valor alvo." << endl;
    } else {
        cout << "Nao foi possivel encontrar um subconjunto que soma exatamente ao valor alvo." << endl;
        cout << "A solucao mais proxima encontrada tem uma diferenca de: " << bestFitness << endl;
    }

    cout << "Melhor subconjunto encontrado: ";
    for (size_t i = 0; i < bestSubset.size(); ++i) {
        if (bestSubset[i] == 1) { // Se o bit e 1, o elemento correspondente faz parte do subconjunto
            cout << elements[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int op = 0;
    int target = 0;
    int maxIterations = 0;

    cout << "Insira o valor da soma do subconjunto: " << endl;
    cin >> target; // valor alvo que desejamos alcancar com a soma dos elementos do subconjunto

    cout << "Insira o valor do máximo de interacoes: " << endl;
    cin >> maxIterations; // numero maximo de iteracoes para a busca local

    vector<int> elements;
    vector<int> bestSubset;


    while (op != 11) {
        cout << "Escolha o conjunto desejsado" << endl;
        cout << "[1] Conjunto 1" << endl;
        cout << "[2] Conjunto 2" << endl;
        cout << "[3] Conjunto 3" << endl;
        cout << "[4] Conjunto 4" << endl;
        cout << "[5] Conjunto 5" << endl;
        cout << "[6] Conjunto 6." << endl;
        cout << "[7] Conjunto 7" << endl;
        cout << "[8] Conjunto 8" << endl;
        cout << "[9] Conjunto 9" << endl;
        cout << "[10] Conjunto 10" << endl;
        cout << "[11] Sair" << endl;
        cout << "===================================================" << endl;
        cout << "Insira a opcao desejada:" << endl;

        cin >> op;

        /*
         * switch case para as opções do menu.
         */
        switch (op) {
            case 1:
                elements =  {1, 2, 3, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 35, 40, 45, 50, 55};
                bestSubset = vector<int>(elements.size(), 0);
                localSearch(bestSubset, elements, target, maxIterations);
                break;
            case 2:
                elements =  {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
                bestSubset = vector<int>(elements.size(), 0);
                localSearch(bestSubset, elements, target, maxIterations);
                break;
            case 3:
                elements =  {2, 5, 8, 14, 21, 34, 55, 89, 144, 233};
                bestSubset = vector<int>(elements.size(), 0);
                localSearch(bestSubset, elements, target, maxIterations);
                break;
            case 4:
                elements =  {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150};
                bestSubset = vector<int>(elements.size(), 0);
                localSearch(bestSubset, elements, target, maxIterations);
                break;
            case 5:
                elements =  {3, 6, 9, 27, 54, 108, 216, 432, 864, 1728, 3456, 6912, 13824, 27648, 55296};
                bestSubset = vector<int>(elements.size(), 0);
                localSearch(bestSubset, elements, target, maxIterations);
                break;
            case 6:
                elements =  {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
                bestSubset = vector<int>(elements.size(), 0);
                localSearch(bestSubset, elements, target, maxIterations);
                break;
            case 7:
                elements =  {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000};
                bestSubset = vector<int>(elements.size(), 0);
                localSearch(bestSubset, elements, target, maxIterations);
                break;
            case 8:
                elements =  {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765};
                bestSubset = vector<int>(elements.size(), 0);
                localSearch(bestSubset, elements, target, maxIterations);
                break;
            case 9:
                elements =  {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288};
                bestSubset = vector<int>(elements.size(), 0);
                localSearch(bestSubset, elements, target, maxIterations);
                break;
            case 10:
                elements =  {3, 6, 9, 15, 21, 33, 48, 75, 123, 195, 312, 501, 813, 1314, 2127, 3441, 5568, 9009, 14577, 23688};
                bestSubset = vector<int>(elements.size(), 0);
                localSearch(bestSubset, elements, target, maxIterations);
                break;
            case 11:
                cout << "Programa finalizado." << endl;
                return 0;
                break;

            default:
                cout <<  "Opção inválida."  << endl;
        }
    }

    return 0;
}
