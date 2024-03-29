//
// Created by Lucas on 28/03/2024.
//
#include <iostream>
#include <queue>
#include <fstream>

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

// Constroi grafo
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

void leituraLabirinto(char (*maze)[MAX], const string &filePath)
{
    ifstream file(filePath);
    if (!file)
    {
        cerr << "Nao foi possivel abrir o arquivo." << endl;
        exit(1);
    }

    for (int i = 0; i < MAX; ++i)
    {
        for (int j = 0; j < MAX; ++j)
        {
            file >> maze[i][j];
        }
    }
}

int main()
{
    int op;
    int op2;
    int parent[MAX * MAX]; // Armazena o vértice pai de cada vértice no caminho encontrado.
    char maze[MAX][MAX];

    Ponto comeco = {0, 0};
    Ponto final = {8, 9};
    Ponto start = {0, 0};
    Ponto end = {0, 0};

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
            leituraLabirinto(maze, "C:\\Users\\Lucas\\Documents\\GitHub\\FACULDADE\\AEDS3\\tp02\\output\\labirinto1.txt");
            cout << "[1] Busca em Largura" << endl;
            cout << "[2] Busca em Profundidade" << endl;
            cout << "[3] Sair para o menu" << endl;
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
                    for (int i = 0; i < MAX; ++i)
                    {
                        for (int j = 0; j < MAX; ++j)
                        {
                            if (maze[i][j] == 'E')
                            {
                                comeco = {i, j};
                            }
                            if (maze[i][j] == 'S')
                            {
                                final = {i, j};
                            }
                        }
                    }
                    if (BFS(maze, comeco, final, parent))
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
                    for (int i = 0; i < MAX; ++i)
                    {
                        for (int j = 0; j < MAX; ++j)
                        {
                            if (maze[i][j] == 'E')
                                start = {i, j};
                            if (maze[i][j] == 'S')
                                end = {i, j};
                        }
                    }

                    if (DFS(maze, start, end, parent))
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
            leituraLabirinto(maze, "C:\\Users\\Lucas\\Documents\\GitHub\\FACULDADE\\AEDS3\\tp02\\output\\labirinto2.txt");
            cout << "[1] Busca em Largura" << endl;
            cout << "[2] Busca em Profundidade" << endl;
            cout << "[3] Sair para o menu" << endl;
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
                    for (int i = 0; i < MAX; ++i)
                    {
                        for (int j = 0; j < MAX; ++j)
                        {
                            if (maze[i][j] == 'E')
                            {
                                comeco = {i, j};
                            }
                            if (maze[i][j] == 'S')
                            {
                                final = {i, j};
                            }
                        }
                    }
                    if (BFS(maze, comeco, final, parent))
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
                    for (int i = 0; i < MAX; ++i)
                    {
                        for (int j = 0; j < MAX; ++j)
                        {
                            if (maze[i][j] == 'E')
                                start = {i, j};
                            if (maze[i][j] == 'S')
                                end = {i, j};
                        }
                    }

                    if (DFS(maze, start, end, parent))
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
            leituraLabirinto(maze, "C:\\Users\\Lucas\\Documents\\GitHub\\FACULDADE\\AEDS3\\tp02\\output\\labirinto3.txt");
            cout << "[1] Busca em Largura" << endl;
            cout << "[2] Busca em Profundidade" << endl;
            cout << "[3] Sair para o menu" << endl;
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
                    for (int i = 0; i < MAX; ++i)
                    {
                        for (int j = 0; j < MAX; ++j)
                        {
                            if (maze[i][j] == 'E')
                            {
                                comeco = {i, j};
                            }
                            if (maze[i][j] == 'S')
                            {
                                final = {i, j};
                            }
                        }
                    }
                    if (BFS(maze, comeco, final, parent))
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
                    for (int i = 0; i < MAX; ++i)
                    {
                        for (int j = 0; j < MAX; ++j)
                        {
                            if (maze[i][j] == 'E')
                                start = {i, j};
                            if (maze[i][j] == 'S')
                                end = {i, j};
                        }
                    }

                    if (DFS(maze, start, end, parent))
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
            leituraLabirinto(maze, "C:\\Users\\Lucas\\Documents\\GitHub\\FACULDADE\\AEDS3\\tp02\\output\\labirinto4.txt");
            cout << "[1] Busca em Largura" << endl;
            cout << "[2] Busca em Profundidade" << endl;
            cout << "[3] Sair para o menu" << endl;
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
                    for (int i = 0; i < MAX; ++i)
                    {
                        for (int j = 0; j < MAX; ++j)
                        {
                            if (maze[i][j] == 'E')
                            {
                                comeco = {i, j};
                            }
                            if (maze[i][j] == 'S')
                            {
                                final = {i, j};
                            }
                        }
                    }
                    if (BFS(maze, comeco, final, parent))
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
                    for (int i = 0; i < MAX; ++i)
                    {
                        for (int j = 0; j < MAX; ++j)
                        {
                            if (maze[i][j] == 'E')
                                start = {i, j};
                            if (maze[i][j] == 'S')
                                end = {i, j};
                        }
                    }

                    if (DFS(maze, start, end, parent))
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
            leituraLabirinto(maze, "C:\\Users\\Lucas\\Documents\\GitHub\\FACULDADE\\AEDS3\\tp02\\output\\labirinto5.txt");
            cout << "[1] Busca em Largura" << endl;
            cout << "[2] Busca em Profundidade" << endl;
            cout << "[3] Sair para o menu" << endl;
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
                    for (int i = 0; i < MAX; ++i)
                    {
                        for (int j = 0; j < MAX; ++j)
                        {
                            if (maze[i][j] == 'E')
                            {
                                comeco = {i, j};
                            }
                            if (maze[i][j] == 'S')
                            {
                                final = {i, j};
                            }
                        }
                    }
                    if (BFS(maze, comeco, final, parent))
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
                    for (int i = 0; i < MAX; ++i)
                    {
                        for (int j = 0; j < MAX; ++j)
                        {
                            if (maze[i][j] == 'E')
                                start = {i, j};
                            if (maze[i][j] == 'S')
                                end = {i, j};
                        }
                    }

                    if (DFS(maze, start, end, parent))
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
            cout << "Opcao invalida." << endl;
        }
    }
    return 0;
}