#include <bits/stdc++.h>
#include "cores.h"

using namespace std;

typedef int tImagem[1000][1000];

string erro;

int carregaPGM(string nome, tImagem img,  int *linhas, int *colunas, int *tons){

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
     
    arquivo >> *linhas >> *colunas >> *tons;
    for (int i = 0; i < *linhas; i++){
        for (int j = 0; j < *colunas; j++){
            arquivo >> img[i][j];
        }
    }
    arquivo.close();    
    return 0;
}

int salvaPGM(string nome, tImagem img, int linhas, int colunas, int tons){
    ofstream arquivo(nome);
    if (!arquivo.is_open()){
        erro = "Erro: Arquivo não encontrado."; 
        return 1;
    }

    arquivo << "P2" << endl << linhas << " " << colunas << endl << tons << endl;
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            arquivo << img[i][j] << " ";
        }
        arquivo << endl;
    }
    
    arquivo.close();
    return 0;
}

void negativa(tImagem img_entrada, tImagem img_saida, int linhas, int colunas, int tons){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            img_saida[i][j] = tons - img_entrada[i][j];
        }
    }
}


int main() {
    tImagem img_entrada, img_saida;
    int colunas, linhas, tons;
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
    negativa(img_entrada, img_saida, linhas, colunas, tons);
    
    // Escrita do arquivo de saída da imagem.
    cout << " Entre com o nome da imagem de saída: ";
    cin >> arquivo_saida;
    arquivo_saida = arquivo_saida + ".pgm";
    if (salvaPGM(arquivo_saida, img_saida, linhas, colunas, tons) != 0){
        cout << "\n" + erro + "\n";
        return 1;
    }
 
    return 0;
}