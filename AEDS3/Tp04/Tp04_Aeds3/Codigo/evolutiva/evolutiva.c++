/* Universidade Federal de Alfenas (UNIFAL) - 2024
 *
 * Gabriel Pereira Soares
 * Letícia Freitas de Oliveira
 * Gustavo Fernandez Paschoaleto
 * Pedro Henrique de Almeida
 * Lucas Pessoa Oliveira Alves  
 * Jorran Luka Andrade dos Santos   
 *
 * Docente: Iago Carvalho - Algoritimo e Estrutura de Dados III
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <chrono> // Biblioteca para cronometragem

using namespace std;
using namespace chrono;


const int POPULATION_SIZE = 100;
const int MAX_GENERATIONS = 1000;
const double MUTATION_RATE = 0.01;

// funcao de fitness
double fitness(const vector<int>& individual, const vector<int>& elements, int target_sum) {
    int total = 0;
    for (size_t i = 0; i < individual.size(); ++i) {
        if (individual[i] == 1) {
            total += elements[i];
        }
    }
    return abs(target_sum - total);
}

// selecionando
pair<vector<int>, vector<int>> selection(const vector<vector<int>>& population, const vector<double>& fitnesses) {
    vector<int> parent1, parent2;
    double sumFitness = 0;
    for (double fit : fitnesses) {
        sumFitness += fit;
    }

    // seleciona dois pais com base na roleta viciada
    for (int i = 0; i < 2; ++i) {
        double randValue = ((double) rand() / RAND_MAX) * sumFitness;
        double cumulative = 0;
        for (size_t j = 0; j < population.size(); ++j) {
            cumulative += fitnesses[j];
            if (cumulative >= randValue) {
                if (i == 0) {
                    parent1 = population[j];
                } else {
                    parent2 = population[j];
                }
                break;
            }
        }
    }
    return make_pair(parent1, parent2);
}

// cruzamento
pair<vector<int>, vector<int>> crossover(const vector<int>& parent1, const vector<int>& parent2) {
    int crossover_point = rand() % parent1.size();
    vector<int> child1(parent1.begin(), parent1.begin() + crossover_point);
    child1.insert(child1.end(), parent2.begin() + crossover_point, parent2.end());

    vector<int> child2(parent2.begin(), parent2.begin() + crossover_point);
    child2.insert(child2.end(), parent1.begin() + crossover_point, parent1.end());

    return make_pair(child1, child2);
}

//mutacao
void mutate(vector<int>& individual) {
    for (size_t i = 0; i < individual.size(); ++i) {
        if (((double) rand() / RAND_MAX) < MUTATION_RATE) {
            individual[i] = individual[i] == 0 ? 1 : 0;
        }
    }
}

//iniciando pop
vector<vector<int>> initialize_population(int size, int subset_length) {
    vector<vector<int>> population(size, vector<int>(subset_length));
    for (auto& individual : population) {
        for (auto& gene : individual) {
            gene = rand() % 2;
        }
    }
    return population;
}

//genetico
vector<int> genetic_algorithm(int target_sum, const vector<int>& elements, double& best_fitness) {
    srand(time(0));
    vector<vector<int>> population = initialize_population(POPULATION_SIZE, elements.size());
    vector<int> best_solution;
    best_fitness = INFINITY;

    for (int generation = 0; generation < MAX_GENERATIONS; ++generation) {
        vector<double> fitnesses(population.size());
        for (size_t i = 0; i < population.size(); ++i) {
            fitnesses[i] = 1.0 / (1 + fitness(population[i], elements, target_sum));
        }

        vector<vector<int>> new_population;
        for (int i = 0; i < POPULATION_SIZE / 2; ++i) {
            pair<vector<int>, vector<int>> parents = selection(population, fitnesses);
            pair<vector<int>, vector<int>> children = crossover(parents.first, parents.second);
            mutate(children.first);
            mutate(children.second);
            new_population.push_back(children.first);
            new_population.push_back(children.second);
        }
        population = new_population;

        //verifica se encontros a solucao
        for (const auto& individual : population) {
            double current_fitness = fitness(individual, elements, target_sum);
            if (current_fitness < best_fitness) {
                best_fitness = current_fitness;
                best_solution = individual;
            }
            int total = 0;
            for (size_t i = 0; i < individual.size(); ++i) {
                if (individual[i] == 1) {
                    total += elements[i];
                }
            }
            if (total == target_sum) {
                best_fitness = 0;
                return individual;
            }
        }
    }
    return best_solution;
}

int main(int argc, char *argv[]) {
    //int op = 0; //(leitura pelo teclado)
    //int target_sum = 0; //(leitura pelo teclado)
    double best_fitness;

    cout << "Insira o valor da soma do subconjunto: " << endl;
    //cin >> target_sum; // Valor alvo que desejamos alcançar com a soma dos elementos do subconjunto //(leitura pelo teclado)
    
    int target_sum = atoi(argv[1]); // leitura por meio de makefile
    cout << target_sum << endl;

    vector<int> elements;
    vector<int> solution;

    for (int i = 2; i < argc; ++i)
    { // leitura por meio de makefile
        int op = atoi(argv[i]);
        if (op == 11)
        {
            break;
        }

    //while (op != 11) { //(leitura pelo teclado)
        cout << "Escolha o conjunto desejado" << endl;
        cout << "[1] Conjunto 1" << endl;
        cout << "[2] Conjunto 2" << endl;
        cout << "[3] Conjunto 3" << endl;
        cout << "[4] Conjunto 4" << endl;
        cout << "[5] Conjunto 5" << endl;
        cout << "[6] Conjunto 6" << endl;
        cout << "[7] Conjunto 7" << endl;
        cout << "[8] Conjunto 8" << endl;
        cout << "[9] Conjunto 9" << endl;
        cout << "[10] Conjunto 10" << endl;
        cout << "[11] Sair" << endl;
        cout << "===================================================" << endl;
        cout << "Insira a opcao desejada:" << endl;

        //cin >> op; //(leitura pelo teclado)

        cout << "Opcao selecionada: " << op << endl;

        /*
         * switch case para as opções do menu.
         */
        switch (op) {
            case 1:
                // Conjunto original
                elements = {1, 2, 3, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 35, 40, 45, 50, 55};
                break;
            case 2:
                // Conjunto pequeno e simples
                elements = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
                break;
            case 3:
                // Conjunto pequeno com variação de valores
                elements = {2, 5, 8, 14, 21, 34, 55, 89, 144, 233};
                break;
            case 4:
                // Conjunto médio e uniforme
                elements = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150};
                break;
            case 5:
                // Conjunto médio com variação
                elements = {3, 6, 9, 27, 54, 108, 216, 432, 864, 1728, 3456, 6912, 13824, 27648, 55296};
                break;
            case 6:
                // Conjunto grande e aleatório
                elements = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89,
                            97};
                break;
            case 7:
                // Conjunto grande com números grandes
                elements = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700,
                            1800, 1900, 2000};
                break;
            case 8:
                // Conjunto sequência de Fibonacci
                elements = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765};
                break;
            case 9:
                // Conjunto potências de 2
                elements = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072,
                            262144, 524288};
                break;
            case 10:
                // Conjunto misto com números pequenos e grandes
                elements = {3, 6, 9, 15, 21, 33, 48, 75, 123, 195, 312, 501, 813, 1314, 2127, 3441, 5568, 9009, 14577,
                            23688};
                break;
            case 11:
                cout << "Programa finalizado." << endl;
                return 0;
                break;

            default:
                cout << "Opcao invalida." << endl;
        }

        auto start = high_resolution_clock::now();
        solution = genetic_algorithm(target_sum, elements, best_fitness);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        if (best_fitness == 0) {
            cout << "Encontrou um subconjunto que soma exatamente ao valor alvo." << endl;
        } else {
            cout << "Nao foi possivel encontrar um subconjunto que soma exatamente ao valor alvo." << endl;
            cout << "A solucao mais proxima encontrada tem uma diferenca de: " << best_fitness << endl;
        }

        cout << "Melhor subconjunto encontrado: ";
        for (size_t i = 0; i < solution.size(); ++i) {
            if (solution[i] == 1) {
                cout << elements[i] << " ";
            }
        }
        cout << endl;
        cout << "Tempo de execucao: " << duration.count() << " microsegundos" << endl;
        cout << "O valor da soma de subconjunto escolhido foi: " << target_sum << endl;
        cout << endl;
    }

    return 0;
}