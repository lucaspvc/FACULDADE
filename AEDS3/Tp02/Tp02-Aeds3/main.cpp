/*
/* Universidade Federal de Alfenas (UNIFAL) - 2024
 *
 * Gabriel Pereira Soares
 * Gustavo Fernandez Pascoaleto
 * Jorran Luka Andrade dos Santos
 * Letícia Freitas de Oliveira
 * Lucas Pessoa Oliveira Alves
 *
 * Docente:  Iago Augusto de Carvalho  - Algoritimo e Estrutura de Dados III
 *
 * Trabalho com o objetivo adquirir conhecimentos de Busca em Profundidade e
 * Busca em Largura de Grafos.
 */
#include <iostream>
#include <queue>

#define MAX 10 // Define o tamanho do labirinto como uma grade 10x10

using namespace std;

struct Ponto
{
    int x, y; // Estrutura de um ponto
};

bool ehValido(int x, int y, char maze[MAX][MAX])
{ // Verifica se a coordenada do ponto é valida
    return x >= 0 && x < MAX && y >= 0 && y < MAX && maze[x][y] != 'X';
}

// transforma o index em linear
int getIndex(int x, int y)
{
    return x * MAX + y;
}

// Constroi o grafo
void constroiGrafo(char maze[MAX][MAX], bool grafo[MAX * MAX][MAX * MAX])
{
    for (int x = 0; x < MAX; x++)
    {
        for (int y = 0; y < MAX; y++)
        {
            if (ehValido(x, y, maze))
            {
                int u = getIndex(x, y);
                // Conecta u com seus vizinhos validos no grafo
                if (ehValido(x + 1, y, maze))
                    grafo[u][getIndex(x + 1, y)] = true;
                if (ehValido(x - 1, y, maze))
                    grafo[u][getIndex(x - 1, y)] = true;
                if (ehValido(x, y + 1, maze))
                    grafo[u][getIndex(x, y + 1)] = true;
                if (ehValido(x, y - 1, maze))
                    grafo[u][getIndex(x, y - 1)] = true;
            }
        }
    }
}

// Função auxiliar para realizar a busca DFS no grafo
bool DFSUtil(int u, bool grafo[MAX * MAX][MAX * MAX], bool visited[], int parent[], int endIndex)
{
    visited[u] = true; // Marca o vértice atual como visitado

    if (u == endIndex)
        return true; // Se alcançou o destino, retorna verdadeiro.

    for (int v = 0; v < MAX * MAX; v++)
    {
        if (grafo[u][v] && !visited[v])
        {
            parent[v] = u;
            if (DFSUtil(v, grafo, visited, parent, endIndex))
                return true;
        }
    }

    return false; // Retorna falso se o destino não pode ser alcançado a partir de u.
}

// Realiza DFS para encontrar um caminho do labirinto
bool DFS(char maze[MAX][MAX], Ponto start, Ponto end, int parent[MAX * MAX])
{
    bool visited[MAX * MAX] = {false};          // Armazena se cada vértice foi visitado
    bool grafo[MAX * MAX][MAX * MAX] = {false}; // Representação do labirinto como um grafo
    constroiGrafo(maze, grafo);
    int startIndex = getIndex(start.x, start.y); // Índice do ponto de início
    int endIndex = getIndex(end.x, end.y);       // Índice do ponto de fim
    parent[startIndex] = -1;                     // O ponto de início não tem pai

    return DFSUtil(startIndex, grafo, visited, parent, endIndex);
}

// Realiza BFS para encontrar um caminho do labirinto
bool BFS(char maze[MAX][MAX], Ponto comeco, Ponto final, int parent[MAX * MAX])
{
    bool visited[MAX * MAX] = {false};
    queue<int> q;                                   // criacao da fila de visitados
    int comecoIndex = getIndex(comeco.x, comeco.y); // descobrindo onde esta o E e o S do labirinto
    int finalIndex = getIndex(final.x, final.y);
    q.push(comecoIndex);
    visited[comecoIndex] = true;
    parent[comecoIndex] = -1;

    bool grafo[MAX * MAX][MAX * MAX] = {false};
    constroiGrafo(maze, grafo);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        int ux = u / MAX;
        int uy = u % MAX;

        if (u == finalIndex)
            return true; // Encontrou o fim

        for (int vx = 0; vx < MAX; vx++)
        {
            for (int vy = 0; vy < MAX; vy++)
            {
                int v = getIndex(vx, vy);
                if (grafo[u][v] && !visited[v])
                {
                    q.push(v);
                    visited[v] = true;
                    parent[v] = u;
                }
            }
        }
    }
    return false;
}

// Imprime o caminho encontrado
void printCaminho(int parent[MAX * MAX], int index)
{
    if (index == -1)
        return;
    printCaminho(parent, parent[index]);
    cout << index / MAX << "," << index % MAX << endl;
}


int main()
{
    int op= 0; //variável para o menu 1
    int op2 = 0; //variável para o menu 2
    int parent[MAX * MAX]; // Armazena o vértice pai de cada vértice no caminho encontrado.
    char maze1[MAX][MAX] = { // Labirinto escolhido
            {'E','X','X','X','X','X','X','X','X','X'},
            {'0','0','0','X','X','X','X','X','X','X'},
            {'0','X','0','0','0','0','X','0','0','0'},
            {'0','X','0','X','X','0','X','0','X','0'},
            {'0','X','0','X','X','0','0','0','X','S'},
            {'0','X','0','X','X','X','X','X','X','X'},
            {'0','X','0','0','0','0','0','X','X','X'},
            {'0','X','X','X','X','X','0','X','X','X'},
            {'0','0','0','X','X','0','0','0','X','X'},
            {'0','X','X','X','X','0','X','0','X','X'},
    };
    char maze2[MAX][MAX] = { // Labirinto escolhido
            {'S','X','X','X','X','X','X','X','X','X'},
            {'0','0','0','X','X','X','X','X','X','X'},
            {'0','X','0','0','0','0','X','0','0','0'},
            {'0','X','0','X','X','0','X','0','X','0'},
            {'0','X','0','X','X','0','0','0','X','E'},
            {'0','X','0','X','X','X','X','X','X','X'},
            {'0','X','0','0','0','0','0','X','X','X'},
            {'0','X','X','X','X','X','0','X','X','X'},
            {'0','0','0','X','X','0','0','0','X','X'},
            {'0','X','X','X','X','0','X','0','X','X'},
    };
    char maze3[MAX][MAX] = { // Labirinto escolhido
            {'X','X','X','X','X','X','X','X','X','X'},
            {'0','0','0','X','X','X','X','X','X','X'},
            {'0','X','0','0','0','0','X','0','0','0'},
            {'0','X','0','X','X','0','X','0','X','0'},
            {'0','X','0','X','X','0','0','0','X','S'},
            {'0','X','0','X','X','X','X','X','X','X'},
            {'0','X','0','0','0','0','0','X','X','X'},
            {'0','X','X','X','X','X','0','X','X','X'},
            {'0','0','0','X','X','0','0','0','X','X'},
            {'E','X','X','X','X','0','X','S','X','X'},
    };
    char maze4[MAX][MAX] = { // Labirinto escolhido
            {'X','X','0','0','0','0','S','X','X','X'},
            {'0','0','0','X','X','X','X','X','X','X'},
            {'0','X','0','0','0','0','X','0','0','0'},
            {'0','X','0','X','X','0','X','0','X','0'},
            {'0','X','0','X','X','0','0','0','X','S'},
            {'0','X','0','X','X','X','X','X','X','X'},
            {'0','X','0','0','0','0','0','X','X','X'},
            {'0','X','X','X','X','X','0','X','X','X'},
            {'0','0','0','X','X','0','0','0','X','X'},
            {'0','X','X','X','X','0','X','E','X','X'},
    };
    char maze5[MAX][MAX] = { // Labirinto escolhido
            {'X','X','0','0','0','0','0','X','X','E'},
            {'0','0','0','X','X','X','X','X','X','0'},
            {'0','X','0','0','0','0','X','0','0','0'},
            {'0','X','0','X','X','0','X','0','X','0'},
            {'0','X','0','X','X','0','0','0','X','S'},
            {'0','X','0','X','X','X','X','X','X','X'},
            {'0','X','0','0','0','0','0','X','X','X'},
            {'0','X','X','X','X','X','0','X','X','X'},
            {'0','0','0','X','X','0','0','0','X','X'},
            {'S','X','X','X','X','0','X','0','X','X'},
    };

    Ponto comeco = {0, 0};
    Ponto final = {8, 9};
    Ponto start = {0, 0};
    Ponto end = {0, 0};

    //menu 1 para escolha dos labirintos
    while (op != 6)
    {
        cout << "======================MENU======================" << endl;
        cout << "Selecione o arquivo de entrada:" << endl;
        cout << "[1] Labirinto 1" << endl;
        cout << "[2] Labirinto 2" << endl;
        cout << "[3] Labirinto 3" << endl;
        cout << "[4] Labirinto 4" << endl;
        cout << "[5] Labirinto 5" << endl;
        cout << "[6] Sair" << endl;
        cout << "===================================================" << endl;
        cout << "Insira a opcao desejada:" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "[1] Busca em Largura" << endl;
            cout << "[2] Busca em Profundidade" << endl;
            cout << "[3] Sair para o menu" << endl;
            //menu 2 para escolha do método
            while (op2 != 3)
            {
                cout << "Insira a opcao desejada:" << endl;
                cin >> op2;
                switch (op2)
                {
                case 1:
                    // chamada de bfs
                    cout << "====================================" << endl;
                    // Localizações corrigidas caso troque o labirinto
                    for (int i = 0; i < MAX; i++)
                    {
                        for (int j = 0; j < MAX; j++)
                        {
                            if (maze1[i][j] == 'E')
                            {
                                comeco = {i, j};
                            }
                            if (maze1[i][j] == 'S')
                            {
                                final = {i, j};
                            }
                        }
                    }
                    if (BFS(maze1, comeco, final, parent))
                    {
                        cout << "Caminho encontrado:" << endl;
                        int finalIndex = getIndex(final.x, final.y);
                        printCaminho(parent, finalIndex);
                    }
                    else
                    {
                        cout << "Caminho nao encontrado." << endl;
                    }
                    break;

                case 2:
                    // Localiza  pontos de início e fim
                    for (int i = 0; i < MAX; i++)
                    {
                        for (int j = 0; j < MAX; j++)
                        {
                            if (maze1[i][j] == 'E')
                                start = {i, j};
                            if (maze1[i][j] == 'S')
                                end = {i, j};
                        }
                    }

                    if (DFS(maze1, start, end, parent))
                    {
                        cout << "Caminho encontrado:" << endl;
                        int endIndex = getIndex(end.x, end.y);
                        printCaminho(parent, endIndex);
                    }
                    else
                    {
                        cout << "Caminho nao encontrado." << endl;
                    }
                    break;
                default:
                    cout << "opcao invalida" << endl;
                }
            }
            op2 = 0;
            break;

        case 2:
            cout << "[1] Busca em Largura" << endl;
            cout << "[2] Busca em Profundidade" << endl;
            cout << "[3] Sair para o menu" << endl;
            //menu 2 para escolha do método
            while (op2 != 3)
            {
                cout << "Insira a opcao desejada:" << endl;
                cin >> op2;
                switch (op2)
                {
                case 1:
                    // chamada de bfs
                    cout << "====================================" << endl;
                    // Localizações corrigidas caso troque o labirinto
                    for (int i = 0; i < MAX; i++)
                    {
                        for (int j = 0; j < MAX; j++)
                        {
                            if (maze2[i][j] == 'E')
                            {
                                comeco = {i, j};
                            }
                            if (maze2[i][j] == 'S')
                            {
                                final = {i, j};
                            }
                        }
                    }
                    if (BFS(maze2, comeco, final, parent))
                    {
                        cout << "Caminho encontrado:" << endl;
                        int finalIndex = getIndex(final.x, final.y);
                        printCaminho(parent, finalIndex);
                    }
                    else
                    {
                        cout << "Caminho nao encontrado." << endl;
                    }
                    break;

                case 2:
                    // Localiza  pontos de início e fim
                    for (int i = 0; i < MAX; i++)
                    {
                        for (int j = 0; j < MAX; j++)
                        {
                            if (maze2[i][j] == 'E')
                                start = {i, j};
                            if (maze2[i][j] == 'S')
                                end = {i, j};
                        }
                    }

                    if (DFS(maze2, start, end, parent))
                    {
                        cout << "Caminho encontrado:" << endl;
                        int endIndex = getIndex(end.x, end.y);
                        printCaminho(parent, endIndex);
                    }
                    else
                    {
                        cout << "Caminho nao encontrado." << endl;
                    }
                    break;
                default:
                    cout << "opcao invalida" << endl;
                }
            }
            op2 = 0;
            break;
        case 3:
            cout << "[1] Busca em Largura" << endl;
            cout << "[2] Busca em Profundidade" << endl;
            cout << "[3] Sair para o menu" << endl;
            //menu 2 para escolha do método
            while (op2 != 3)
            {
                cout << "Insira a opcao desejada:" << endl;
                cin >> op2;
                switch (op2)
                {
                case 1:
                    // chamada de bfs
                    cout << "====================================" << endl;
                    // Localizações corrigidas caso troque o labirinto
                    for (int i = 0; i < MAX; i++)
                    {
                        for (int j = 0; j < MAX; j++)
                        {
                            if (maze3[i][j] == 'E')
                            {
                                comeco = {i, j};
                            }
                            if (maze3[i][j] == 'S')
                            {
                                final = {i, j};
                            }
                        }
                    }
                    if (BFS(maze3, comeco, final, parent))
                    {
                        cout << "Caminho encontrado:" << endl;
                        int finalIndex = getIndex(final.x, final.y);
                        printCaminho(parent, finalIndex);
                    }
                    else
                    {
                        cout << "Caminho nao encontrado." << endl;
                    }
                    break;

                case 2:
                    // Localiza  pontos de início e fim
                    for (int i = 0; i < MAX; i++)
                    {
                        for (int j = 0; j < MAX; j++)
                        {
                            if (maze3[i][j] == 'E')
                                start = {i, j};
                            if (maze3[i][j] == 'S')
                                end = {i, j};
                        }
                    }

                    if (DFS(maze3, start, end, parent))
                    {
                        cout << "Caminho encontrado:" << endl;
                        int endIndex = getIndex(end.x, end.y);
                        printCaminho(parent, endIndex);
                    }
                    else
                    {
                        cout << "Caminho nao encontrado." << endl;
                    }
                    break;
                default:
                    cout << "opcao invalida" << endl;
                }
            }
            op2 = 0;
            break;

        case 4:
            cout << "[1] Busca em Largura" << endl;
            cout << "[2] Busca em Profundidade" << endl;
            cout << "[3] Sair para o menu" << endl;
            //menu 2 para escolha do método
            while (op2 != 3)
            {
                cout << "Insira a opcao desejada:" << endl;
                cin >> op2;
                switch (op2)
                {
                case 1:
                    // chamada de bfs
                    cout << "====================================" << endl;
                    // Localizações corrigidas caso troque o labirinto
                    for (int i = 0; i < MAX; i++)
                    {
                        for (int j = 0; j < MAX; j++)
                        {
                            if (maze4[i][j] == 'E')
                            {
                                comeco = {i, j};
                            }
                            if (maze4[i][j] == 'S')
                            {
                                final = {i, j};
                            }
                        }
                    }
                    if (BFS(maze4, comeco, final, parent))
                    {
                        cout << "Caminho encontrado:" << endl;
                        int finalIndex = getIndex(final.x, final.y);
                        printCaminho(parent, finalIndex);
                    }
                    else
                    {
                        cout << "Caminho nao encontrado." << endl;
                    }
                    break;

                case 2:
                    // Localiza  pontos de início e fim
                    for (int i = 0; i < MAX; i++)
                    {
                        for (int j = 0; j < MAX; j++)
                        {
                            if (maze4[i][j] == 'E')
                                start = {i, j};
                            if (maze4[i][j] == 'S')
                                end = {i, j};
                        }
                    }

                    if (DFS(maze4, start, end, parent))
                    {
                        cout << "Caminho encontrado:" << endl;
                        int endIndex = getIndex(end.x, end.y);
                        printCaminho(parent, endIndex);
                    }
                    else
                    {
                        cout << "Caminho nao encontrado." << endl;
                    }
                    break;
                default:
                    cout << "opcao invalida" << endl;
                }
            }
            op2 = 0;
            break;
        case 5:
            cout << "[1] Busca em Largura" << endl;
            cout << "[2] Busca em Profundidade" << endl;
            cout << "[3] Sair para o menu" << endl;
            //menu 2 para escolha do método
            while (op2 != 3)
            {
                cout << "Insira a opcao desejada:" << endl;
                cin >> op2;
                switch (op2)
                {
                case 1:
                    // chamada de bfs
                    cout << "====================================" << endl;
                    // Localizações corrigidas caso troque o labirinto
                    for (int i = 0; i < MAX; i++)
                    {
                        for (int j = 0; j < MAX; j++)
                        {
                            if (maze5[i][j] == 'E')
                            {
                                comeco = {i, j};
                            }
                            if (maze5[i][j] == 'S')
                            {
                                final = {i, j};
                            }
                        }
                    }
                    if (BFS(maze5, comeco, final, parent))
                    {
                        cout << "Caminho encontrado:" << endl;
                        int finalIndex = getIndex(final.x, final.y);
                        printCaminho(parent, finalIndex);
                    }
                    else
                    {
                        cout << "Caminho nao encontrado." << endl;
                    }
                    break;

                case 2:
                    // Localiza  pontos de início e fim
                    for (int i = 0; i < MAX; i++)
                    {
                        for (int j = 0; j < MAX; j++)
                        {
                            if (maze5[i][j] == 'E')
                                start = {i, j};
                            if (maze5[i][j] == 'S')
                                end = {i, j};
                        }
                    }

                    if (DFS(maze5, start, end, parent))
                    {
                        cout << "Caminho encontrado:" << endl;
                        int endIndex = getIndex(end.x, end.y);
                        printCaminho(parent, endIndex);
                    }
                    else
                    {
                        cout << "Caminho nao encontrado." << endl;
                    }
                    break;
                default:
                    cout << "opcao invalida" << endl;
                }
            }
            op2 = 0;
            break;
        default:
            cout << "Programa Finalizado." << endl;
        }
    }
    return 0;
}