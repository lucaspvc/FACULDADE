#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

typedef int tImagem[1000][1000];

string erro;

int carregaPGM(string nome, tImagem img, int *lin, int *col, int *tons){

    string tipo;
    ifstream arquivo(nome);
    if (!arquivo.is_open()){
        erro = "Erro: Arquivo não encontrado."; 
        return 1;
    }

    arquivo >> tipo;
    if (tipo != "P2"){
        erro = "Erro: Arquivo não tem formato P2."; 
        return 2;
    }
     
    arquivo >> *col >> *lin >> *tons;
    for (int i = 0; i < *lin; i++){
        for (int j = 0; j < *col; j++){
            arquivo >> img[i][j];
        }
    }
    arquivo.close();    
    return 0;
}

int salvaPGM(string nome, tImagem img, int lin, int col, int tons){
    ofstream arquivo(nome);
    if (!arquivo.is_open()){
        erro = "Erro: Arquivo não encontrado."; 
        return 1;
    }

    arquivo << "P2" << endl << col << " " << lin << endl << tons << endl;
    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++){
            arquivo << img[i][j] << " ";
        }
        arquivo << endl;
    }
    
    arquivo.close();
    return 0;
}

/*
 * Leitura e Escrita de arquivos no formato PGM com funções.
 */
int main(int argc, char** argv) {
    tImagem img_entrada, img_saida;
    int colunas = 10, linhas = 10, tons;
    string arquivo_entrada, arquivo_saida;

    
    // Leitura do arquivo de entrada da imagem.
    cout << " Entre com o nome da imagem de entrada: ";
    cin >> arquivo_entrada;
    arquivo_entrada = arquivo_entrada + ".pgm";
    if (carregaPGM(arquivo_entrada, img_entrada, &linhas, &colunas, &tons) != 0){
        cout << "\n" + erro + "\n";
        return 1;
    }
    
    // Construindo a imagem negativa.
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            img_saida[j][i] = tons - img_entrada[i][j];
        }
    }
    
    // Escrita do arquivo de saída da imagem.
    cout << " Entre com o nome da imagem de saída: ";
    cin >> arquivo_saida;
    arquivo_saida = arquivo_saida + ".pgm";
    if (salvaPGM(arquivo_saida, img_saida, colunas, linhas, tons) != 0){
        cout << "\n" + erro + "\n";
        return 1;
    }
 
    return 0;
}