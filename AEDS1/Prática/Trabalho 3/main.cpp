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

void ajusteBrilho(tImagem img_entrada, tImagem img_saida, int linhas, int colunas, int tons, int fator){
    int aux;
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            aux = img_entrada[i][j] + fator;
            if(aux < 0){
                aux = 0;
            }else if (aux > tons){
                aux = tons;
            }
            img_saida[i][j] = aux;
        }
    }
}

void transpor(tImagem img_entrada, tImagem img_saida, int *linhas, int *colunas){
    for (int i = 0; i < *linhas; i++) {
        for (int j = 0; j < *colunas; j++) {
            img_saida[j][i] = img_entrada[i][j];
        }
    }
}

void rotacionaDireita(tImagem img_entrada, tImagem img_saida, int *linhas, int *colunas){

    transpor(img_entrada, img_saida, linhas, colunas);
    // Inverter as colunas (rotacionar 90 graus à direita)
    for (int i = 0; i < *colunas; i++) {
        for (int j = 0, k = *linhas - 1; j < *linhas / 2; j++, k--) {
            //a função swap faz a torca sem a utilização de uma variável auxiliar
            swap(img_saida[i][j], img_saida[i][k]);
        }
    }

    // Atualizar as dimensões da imagem de saída após a rotação
    swap(*linhas, *colunas);
}

void rotacionaEsquerda(tImagem img_entrada, tImagem img_saida, int *linhas, int *colunas) {
    
    transpor(img_entrada, img_saida, linhas, colunas);

    // Inverter as linhas (rotacionar 90 graus à esquerda)
    for (int i = 0, k = *colunas - 1; i < *colunas / 2; i++, k--) {
        for (int j = 0; j < *linhas; j++) {
            //a função swap faz a torca sem a utilização de uma variável auxiliar
            swap(img_saida[i][j], img_saida[k][j]);
        }
    }

    // Atualizar as dimensões da imagem de saída após a rotação
    swap(*linhas, *colunas);
}

void binarizarImagem(tImagem img_entrada, tImagem img_saida, int linhas, int colunas, int tons, int fatorLimiar) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            // Verificar se o pixel é maior que o fator de limiar
            if (img_entrada[i][j] > fatorLimiar) {
                // Pixel maior que o limiar, define como branco (valor máximo)
                img_saida[i][j] = tons;
            } else {
                // Pixel menor ou igual ao limiar, define como preto (valor mínimo)
                img_saida[i][j] = 0;
            }
        }
    }
}

void iconizarImagem(tImagem img_entrada, tImagem img_saida, int linhas, int colunas) {
    int novaLinhas = 64;
    int novaColunas = 64;
    int tamanhoBlocoLinhas = max(1, linhas / novaLinhas);
    int tamanhoBlocoColunas = max(1, colunas / novaColunas);
    int media, soma, totalPixels;
    media = soma = totalPixels = 0;

    for (int i = 0; i < novaLinhas; i++) {
        for (int j = 0; j < novaColunas; j++) {
            // Calcular valor representativo do bloco (média dos pixels)

            for (int x = 0; x < tamanhoBlocoLinhas; x++) {
                for (int y = 0; y < tamanhoBlocoColunas; y++) {
                    int lin = i * tamanhoBlocoLinhas + x;
                    int col = j * tamanhoBlocoColunas + y;
                    if (lin < linhas && col < colunas) {
                        soma += img_entrada[lin][col];
                        totalPixels++;
                    }
                }
            }

            if (totalPixels > 0) {
                media = soma / totalPixels;
                } else {
                    media = 0;
                }
            // Definir o valor médio do bloco para todos os pixels do bloco na imagem de saída
            for (int x = 0; x < tamanhoBlocoLinhas; x++) {
                for (int y = 0; y < tamanhoBlocoColunas; y++) {
                    img_saida[i * tamanhoBlocoLinhas + x][j * tamanhoBlocoColunas + y] = media;
                }
            }
        }
    }
}

void PassaBaixa(tImagem img_entrada, tImagem img_saida, int linhas, int colunas) {
    int soma = 0; 
    for (int i = 1; i < linhas - 1; i++) {
        for (int j = 1; j < colunas - 1; j++) {
            soma = 0;
            for (int k = i - 1; k <= i + 1; k++) {
                for (int l = j - 1; l <= j + 1; l++) {
                    soma =  soma + img_entrada[k][l];
                }
            }
            img_saida[i][j] = soma / 9;
        }
    }
    for (int i = 0; i < colunas; i++) {
        img_saida[0][i] = img_entrada[0][i];
        img_saida[linhas - 1][i] = img_entrada[linhas - 1][i];
    }
    for (int j = 0; j < linhas; j++) {
        img_saida[j][0] = img_entrada[j][0];
        img_saida[j][colunas - 1] = img_entrada[j][colunas - 1];
    }
}



int main() {
    tImagem img_entrada, img_saida;
    int colunas, linhas, tons, fator;
    string arquivo_entrada, arquivo_saida;

    // Leitura do arquivo de entrada da imagem.
    cout << "Entre com o nome da imagem de entrada: ";
    cin >> arquivo_entrada;
    arquivo_entrada = arquivo_entrada + ".pgm";
    if (carregaPGM(arquivo_entrada, img_entrada, &linhas, &colunas, &tons) != 0){
        cout << "\n" + erro + "\n";
        return 1;
    }
    
    // Construindo a imagem clareada ou escurecida
    ajusteBrilho(img_entrada, img_saida, linhas, colunas, tons, fator);

    //Rotacionando a direita.
    rotacionaDireita(img_entrada, img_saida, &linhas, &colunas);

    //Rotacionando a esquerda.
    rotacionaEsquerda(img_entrada, img_saida, &linhas, &colunas);

    //binariza a imagem a partir de um fator
    binarizarImagem(img_entrada, img_saida, linhas, colunas, tons, fator);

    //iconizar a imagem
    iconizarImagem(img_entrada, img_saida, linhas, colunas);
    
    
    // Escrita do arquivo de saída da imagem.
    cout << "Entre com o nome da imagem de saída: ";
    cin >> arquivo_saida;
    arquivo_saida = arquivo_saida + ".pgm";
    if (salvaPGM(arquivo_saida, img_saida, linhas, colunas, tons) != 0){
        cout << "\n" + erro + "\n";
        return 1;
    }
 
    return 0;
}