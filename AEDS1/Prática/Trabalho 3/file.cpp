/* Universidade Federal de Alfenas (UNIFAL) - 2023
 * Lucas Pessoa Oliveira Alves 2022.1.08.044
 *
 * Docente: Paulo Alexandre Bressan - Algoritimo e Estrutura de Dados I
 * 
 * Trabalho com o objetivo de compreender as diferenças entre os métodos de ordenação não recursivos,
 * conhecer uma forma de comparação de algoritmos e aprender como relatar os experimentos realizados.
 */
#include <bits/stdc++.h>
#include "file.h"

using namespace std;

typedef int tImagem[1000][1000];


string erro;


int carregaPGM(string nome, tImagem img, int *linhas, int *colunas, int *tons){
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
    arquivo >> *colunas >> *linhas >> *tons;
    for (int i = 0; i < *linhas; i++){
        for (int j = 0; j < *colunas; j++)
        {
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
    arquivo << "P2" << endl
            << colunas << " " << linhas << endl
            << tons << endl;
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            arquivo << img[i][j] << " ";
        }
        arquivo << endl;
    }
    arquivo.close();
    return 0;
}