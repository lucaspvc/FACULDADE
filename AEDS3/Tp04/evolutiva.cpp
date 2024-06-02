#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

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
    return {parent1, parent2};
}

// cruzamento
pair<vector<int>, vector<int>> crossover(const vector<int>& parent1, const vector<int>& parent2) {
    int crossover_point = rand() % parent1.size();
    vector<int> child1(parent1.begin(), parent1.begin() + crossover_point);
    child1.insert(child1.end(), parent2.begin() + crossover_point, parent2.end());

    vector<int> child2(parent2.begin(), parent2.begin() + crossover_point);
    child2.insert(child2.end(), parent1.begin() + crossover_point, parent1.end());

    return {child1, child2};
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
            auto [parent1, parent2] = selection(population, fitnesses);
            auto [child1, child2] = crossover(parent1, parent2);
            mutate(child1);
            mutate(child2);
            new_population.push_back(child1);
            new_population.push_back(child2);
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

int main() {
    vector<int> elements = {1, 2, 3, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 35, 40, 45, 50, 55}; // conjunto original
    int target_sum = 800;
    double best_fitness;
    vector<int> solution = genetic_algorithm(target_sum, elements, best_fitness);

    if (best_fitness == 0) {
        cout << "Encontrou um subconjunto que soma exatamente ao valor alvo." << endl;
    } else {
        cout << "Nao foi possivel encontrar um subconjunto que soma exatamente ao valor alvo." << endl;
        cout << "A solucao mais proxima encontrada tem uma diferença de: " << best_fitness << endl;
    }

    cout << "Melhor subconjunto encontrado: ";
    for (size_t i = 0; i < solution.size(); ++i) {
        if (solution[i] == 1) {
            cout << elements[i] << " ";
        }
    }
    cout << std::endl;

    return 0;
}
