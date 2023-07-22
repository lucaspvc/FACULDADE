/* Universidade Federal de Alfenas (UNIFAL) - 2023
 * Lucas Pessoa Oliveira Alves        2022.1.08.044
 * Jorran Luka Andrade dos Santos     2022.2.08.001
 *
 * Docente: Paulo Alexandre Bressan - Algoritimo e Estrutura de Dados I
 * 
 * Trabalho com o objetivo adquirir conhecimentos de manipulação de imagens em 
 * formato de matrizes implementando funcionalidades que geram novas imagens a 
 * partir de imagens lidas de arquivos-texto em formato PGM.
 */
#include "operations.h"
#include <bits/stdc++.h>

using namespace std;

typedef int tImagem[1000][1000];

/**
 * Função para ajuste do brilho (clarear ou escurecer).
 * @param img_entrada -> imagem original.
 * @param img_saida -> imagem alterada.
 * @param linhas -> total de linhas da matriz.
 * @param colunas -> total de colunas da matriz.
 * @param tons -> número total de tons da imagem.
 * @param fator -> fator a ser usado para clarear ou escurecer
 */
void ajusteBrilho(tImagem img_entrada, tImagem img_saida, int linhas,
        int colunas, int tons, int fator){
    
    int aux;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            aux = img_entrada[i][j] + fator;
            if (aux < 0) {
                aux = 0;
            } else if (aux > tons) {
                aux = tons;
            }
            img_saida[i][j] = aux;
        }
    }
}

/**
 * Função para transpor a matriz.
 * @param img_entrada -> imagem original.
 * @param img_saida -> imagem alterada.
 * @param linhas -> total de linhas da matriz.
 * @param colunas -> total de colunas da matriz.
 */
void transpor(tImagem img_entrada, tImagem img_saida, int *linhas, int *colunas) {
    for (int i = 0; i < *linhas; i++) {
        for (int j = 0; j < *colunas; j++) {
            img_saida[j][i] = img_entrada[i][j];
        }
    }
}

/**
 * Função para rotacionar a imagem à direita.
 * @param img_entrada -> imagem original.
 * @param img_saida -> imagem alterada.
 * @param linhas -> total de linhas da matriz.
 * @param colunas -> total de colunas da matriz.
 */
void rotacionaDireita(tImagem img_entrada, tImagem img_saida, int *linhas, int *colunas) {

    transpor(img_entrada, img_saida, linhas, colunas);
    // Inverter as colunas (rotacionar 90 graus à direita)
    for (int i = 0; i < *colunas; i++) {
        for (int j = 0, k = *linhas - 1; j < *linhas / 2; j++, k--) {
            // a função swap faz a torca sem a utilização de uma variável auxiliar
            swap(img_saida[i][j], img_saida[i][k]);
        }
    }

    // Atualizar as dimensões da imagem de saída após a rotação
    swap(*linhas, *colunas);
}

/**
 * Função para rotacionar a imagem à esquerda.
 * @param img_entrada -> imagem original.
 * @param img_saida -> imagem alterada.
 * @param linhas -> total de linhas da matriz.
 * @param colunas -> total de colunas da matriz.
 */
void rotacionaEsquerda(tImagem img_entrada, tImagem img_saida, int *linhas, int *colunas) {

    transpor(img_entrada, img_saida, linhas, colunas);

    // Atualizar as dimensões da imagem de saída após a rotação
    swap(*linhas, *colunas);
}

/**
 * Função para binarizar a imagem.
 * @param img_entrada -> imagem original.
 * @param img_saida -> imagem alterada.
 * @param linhas -> total de linhas da matriz.
 * @param colunas -> total de colunas da matriz.
 * @param tons -> número total de tons da imagem.
 * @param fatorLimiar -> fator para binarização da imagem.
 */
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

/**
 * Função para iconizar a imagem, ou seja, reduzi-lá para 64x64.
 * @param img_entrada -> imagem original.
 * @param img_saida -> imagem alterada.
 * @param linhas -> total de linhas da matriz.
 * @param colunas -> total de colunas da matriz.
 */
void iconizar(tImagem img_entrada, tImagem img_saida, int *linhas, int *colunas) {
    int fator_linhas = (*linhas) / 64;
    int fator_colunas = (*colunas) / 64;
    int media = 0;
    if (fator_linhas < 1) {
        fator_linhas = 1;
    }
    if (fator_colunas < 1) {
        fator_colunas = 1;
    }
    for (int i = 0; i < *linhas; i = i + fator_linhas) {
        for (int j = 0; j < *colunas; j = j + fator_colunas) {
            media = 0;
            for (int k = i; k < i + fator_linhas; k++) {
                for (int l = j; l < j + fator_colunas; l++) {
                    media = media + img_entrada[k][l];
                }
            }
            media = media / (fator_linhas * fator_colunas);
            img_saida[i / fator_linhas][j / fator_colunas] = media;
        }
    }
}

/**
 * Função para passar um filtro passa-baixa na imagem.
 * @param img_entrada -> imagem original.
 * @param img_saida -> imagem alterada.
 * @param linhas -> total de linhas da matriz.
 * @param colunas -> total de colunas da matriz.
 */
void passa_baixa(tImagem img_entrada, tImagem img_saida, int *linhas, int *colunas) {
    int soma = 0; 
    for (int i = 1; i < *linhas - 1; i++) {
        for (int j = 1; j < *colunas - 1; j++) {
            soma = 0;
            for (int k = i - 1; k <= i + 1; k++) {
                for (int l = j - 1; l <= j + 1; l++) {
                    soma = soma + img_entrada[k][l];
                }
            }
            img_saida[i][j] = soma / 9;
        }
    }
    for (int i = 0; i < *colunas; i++) {
        img_saida[0][i] = img_entrada[0][i];
        img_saida[*linhas - 1][i] = img_entrada[*linhas - 1][i];
    }
    for (int j = 0; j < *linhas; j++) {
        img_saida[j][0] = img_entrada[j][0];
        img_saida[j][*colunas - 1] = img_entrada[j][*colunas - 1];
    }
}

/**
 * Função para zerar os valores da matriz.
 * @param matriz -> matriz a ser zerado.
 * @param linhas -> total de linhas da matriz.
 * @param colunas -> total de colunas da matriz.
 */
void zerar_matriz(tImagem matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = 0;
        }
    }
}