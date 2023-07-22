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


/* Header File para as funções definidas no arquivo operations.cpp
 */
#ifndef OPERATIONS_H
#define OPERATIONS_H

using namespace std;

typedef int tImagem[1000][1000];

/**
 * Chamada para função para ajuste do brilho (clarear ou escurecer).
 * @param img_entrada -> imagem original.
 * @param img_saida -> imagem alterada.
 * @param linhas -> total de linhas da matriz.
 * @param colunas -> total de colunas da matriz.
 * @param tons -> número total de tons da imagem.
 * @param fator -> fator a ser usado para clarear ou escurecer
 */
void ajusteBrilho(tImagem img_entrada, tImagem img_saida, int linhas, 
        int colunas, int tons, int fator);

/**
 * Função para transpor a matriz.
 * @param img_entrada -> imagem original.
 * @param img_saida -> imagem alterada.
 * @param linhas -> total de linhas da matriz.
 * @param colunas -> total de colunas da matriz.
 */
void transpor(tImagem img_entrada, tImagem img_saida, int *linhas, int *colunas);

/**
 * Chamada para função para rotacionar a imagem à direita.
 * @param img_entrada -> imagem original.
 * @param img_saida -> imagem alterada.
 * @param linhas -> total de linhas da matriz.
 * @param colunas -> total de colunas da matriz.
 */
void rotacionaDireita(tImagem img_entrada, tImagem img_saida, int *linhas, 
        int *colunas);

/**
 * Chamada para função para rotacionar a imagem à esquerda.
 * @param img_entrada -> imagem original.
 * @param img_saida -> imagem alterada.
 * @param linhas -> total de linhas da matriz.
 * @param colunas -> total de colunas da matriz.
 */
void rotacionaEsquerda(tImagem img_entrada, tImagem img_saida, int *linhas, 
        int *colunas);

/**
 * Chamada da função para binarizar a imagem.
 * @param img_entrada -> imagem original.
 * @param img_saida -> imagem alterada.
 * @param linhas -> total de linhas da matriz.
 * @param colunas -> total de colunas da matriz.
 * @param tons -> número total de tons da imagem.
 * @param fatorLimiar -> fator para binarização da imagem.
 */
void binarizarImagem(tImagem img_entrada, tImagem img_saida, int linhas,
        int colunas, int tons, int fatorLimiar);

/**
 * Chamada da função para iconizar a imagem, ou seja, reduzi-lá para 64x64.
 * @param img_entrada -> imagem original.
 * @param img_saida -> imagem alterada.
 * @param linhas -> total de linhas da matriz.
 * @param colunas -> total de colunas da matriz.
 */
void iconizar(tImagem img_entrada, tImagem img_saida, int *linhas, int *colunas);

/**
 * Chamada da função para passar um filtro passa-baixa na imagem.
 * @param img_entrada -> imagem original.
 * @param img_saida -> imagem alterada.
 * @param linhas -> total de linhas da matriz.
 * @param colunas -> total de colunas da matriz.
 */
void passa_baixa(tImagem img_entrada, tImagem img_saida, int *linhas,
        int *colunas);

/**
 * Chamada da função para zerar os valores da matriz.
 * @param matriz -> matriz a ser zerado.
 * @param linhas -> total de linhas da matriz.
 * @param colunas -> total de colunas da matriz.
 */
void zerar_matriz(tImagem matriz, int linhas, int colunas);

using namespace std;

#endif