
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
 * Trabalho com o objetivo adquirir conhecimentos em algoritmo de caminho mínimo 
 * de grafo, utilizando C++ e Python.
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;




#define INF 1000000 // Valor alto para representar infinito

// Função que adiciona uma aresta não direcionada ponderada ao grafo
void addEdge(std::vector<std::pair<int, int>> adj[], int u, int v, int w) {
    // Adiciona a aresta do vértice 'u' para o vértice 'v' com peso 'w'
    adj[u].push_back(std::make_pair(v, w));
    // Adiciona a aresta do vértice 'v' para o vértice 'u' com peso 'w'
    adj[v].push_back(std::make_pair(u, w));
}

// Encontra o indice do vertice com a menor distancia que ainda n foi processado
int minDistance(int dist[], bool sptSet[], int V) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] < min) {
            min = dist[v], min_index = v;
        }
    }

    return min_index;
}

// Função que implementa o algoritmo de Dijkstra
void dijkstra(std::vector<std::pair<int, int>> adj[], int V, int src, int dist[]) {
    bool sptSet[V]; // Define um conjunto de vértices incluídos no caminho mais curto

    // Inicializa todas as distâncias como infinito e sptSet[] como falso
    for (int i = 0; i < V; i++) {
        dist[i] = INF; // Distância infinita inicialmente
        sptSet[i] = false; // Nenhum vértice incluído no caminho mais curto
    }

    // A distância de um vértice a ele mesmo é sempre zero
    dist[src] = 0;

    // Encontrando o caminho mais curto para todos os vértices
    for (int count = 0; count < V - 1; count++) {
        // Seleciona o vértice de distância mínima do conjunto de vértices ainda não processados
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true; // Marca o vértice selecionado como processado

        // Atualiza o valor da distância de vértices adjacentes ao vértice selecionado apenas se
        // a distância total do src ao vértice selecionado é menor que a distância atualmente armazenada
        // em dist[v] e o vértice v não está no caminho mais curto ainda
        for (auto it : adj[u]) {
            int v = it.first; // Obtém o vértice adjacente e seu peso
            int peso = it.second;
            if (!sptSet[v] && dist[u] != INF && dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso; // Atualiza a distância se uma rota mais curta for encontrada
            }
        }
    }
}

// Função que calcula a centralidade de proximidade para cada vértice
void closenessCentrality(std::vector<std::pair<int, int>> adj[], int V) {
    ofstream outFile("saida.txt"); // Abre o arquivo de saída
    if (!outFile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de saída." << std::endl; // Verifica se o arquivo foi aberto com sucesso
        return;
    }
    cout << "Closeness para cada vertice:\n"; // Imprime uma mensagem indicando o início do cálculo

    // Para cada vértice no grafo
    for (int i = 0; i < V; i++) {
        int dist[V];
        dijkstra(adj, V, i, dist); // Calcula as distâncias mais curtas a partir do vértice atual

        int totalDistance = 0;
        // Calcula a soma das distâncias mais curtas
        for (int j = 0; j < V; j++) {
            if (dist[j] != INF) {
                totalDistance += dist[j];
            } else {
                // Se um vértice estiver desconectado, a centralidade é definida como infinito
                totalDistance = INF;
                break;
            }
        }

        // Se a soma das distâncias for finita e não for zero
        if (totalDistance != INF && totalDistance != 0) {
            // Calcula a centralidade de proximidade para o vértice atual
            double closeness = (V - 1) / static_cast<double>(totalDistance);
            // Escreve o índice do vértice e sua centralidade no arquivo de saída
            outFile << i << " " << closeness << "\n";
        } else {
            // Se o vértice estiver desconectado ou em um loop, escreve uma mensagem apropriada no arquivo de saída
            outFile << "Vertice " << i << ": Desconectado ou em loop\n";
        }
    }
    outFile.close(); // Fecha o arquivo de saída
}

// imprime a lista de adjacencia 
void printGrafo(vector<pair<int, int>> adj[], int V) {
    cout << "Representacao do grafo (lista de adjacencia):\n";
    for (int i = 0; i < V; ++i) {
        cout << "verticie " << i << " -> ";
        for (auto &pair : adj[i]) {
            cout << "[" << pair.first << ", " << pair.second << "] ";
        }
        cout << "\n";
    }
}



// Função que lê um grafo de um arquivo e o armazena em uma lista de adjacência
void readGraphFromFile(const std::string filename, std::vector<std::pair<int, int>> adj[], int V) {
    ifstream file;
    file.open(filename, ios::in); // Abre o arquivo para leitura
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl; // Verifica se o arquivo foi aberto com sucesso
        return;
    }

    std::string line;
    // Lê cada linha do arquivo
    while (getline(file, line)) {
        std::istringstream iss(line);
        int u, v, w;
        // Lê os três números inteiros de cada linha (representando u, v e w)
        if (!(iss >> u >> v >> w)) {
            std::cerr << "Erro ao ler a linha: " << line << std::endl; // Em caso de erro na leitura, imprime uma mensagem de erro
            continue;
        }
        addEdge(adj, u, v, w); // Adiciona a aresta ao grafo
    }

    file.close(); // Fecha o arquivo após a leitura
}

int contaVertices(string filename){
    ifstream file;
    file.open(filename,ios::in);
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return 0;
    }
    string line;
    int u,v,w;
    int maior = 0;
    while (getline(file, line)) {
        istringstream iss(line);
        iss >> u >> v >> w;
        if(u > maior){
            maior = u;
        }

    }
    return maior +1;
}

int main() {
    string filename;
    cout << "===== MENU =====" << endl;
    cout << "Escolha algum dos seguintes grafos:" << endl;
    cout << "grafo1.txt" << endl;
    cout << "grafo2.txt" << endl;
    cout << "grafo3.txt" << endl;
    cout << "grafo4.txt" << endl;
    cout << "grafo5.txt" << endl;
    cout << "grafo6.txt" << endl;
    cout << "grafo7.txt" << endl;
    cout << "grafo8.txt" << endl;
    cout << "grafo9.txt" << endl;
    cout << "grafo10.txt" << endl;
    cout << "Digite o nome do grafo de entrada e a sua respectiva extensao: ";
    cin >> filename;

    int V = contaVertices(filename);

    vector<pair<int, int>> adj[V];
    readGraphFromFile(filename, adj, V);
    

    closenessCentrality(adj, V);

    string command = "python print.py " + filename;
    system(command.c_str());
    return 0;
}