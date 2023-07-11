/* Universidade Federal de Alfenas (UNIFAL) - 2023
 * Lucas Pessoa Oliveira Alves 2022.1.08.044
 *
 * Docente: Paulo Alexandre Bressan - Algoritimo e Estrutura de Dados I
 * 
 * Trabalho com o objetivo de compreender as diferenças entre os métodos de ordenação não recursivos,
 * conhecer uma forma de comparação de algoritmos e aprender como relatar os experimentos realizados.
 */

/* Header File para as funções definidas no arquivo funcoes.cpp
 * 
 */
#ifndef FUNCOES_H
#define FUNCOES_H
#include <bits/stdc++.h>

using namespace std;

/*
 * Chamada da função de ordenação bubble sort.
 * @param vetor -> vetor a ser ordenado
 * @param n -> tamanho total do vetor
 * @return contBubble -> retorna um número inteiro sobre quantas vezes houve manipulação no vetor
 */
int bubblesort(int vetor[], int n);

/*
 * Chamada da função de ordenação insertion sort
 * @param vetor -> vetor a ser ordenado
 * @param n -> tamanho total do vetor
 * @return contInssertion -> retorna um número inteiro sobre quantas vezes houve manipulação no vetor
 */
int insertionsort(int vetor[], int n);

/*
 * Chamada da função de ordenação selection sort
 * @param vetor -> vetor a ser ordenado
 * @param n -> tamanho total do vetor
 * @return contSelection -> retorna um número inteiro sobre quantas vezes houve manipulação no vetor
 */
int selectionsort(int vetor[], int n);

/*
 * Chamada para função de criação de um arquivo com um vetor aleatório com 
 * valores aleatórios e não repetidos 
 * @param n -> tamanho do vetor a ser criado
 * @param m -> valor máximo do intervalo para pegar os valores aleatórios
 */
void create_file_random(int n, int m);

/*
 * Chamada para a função de ordenação crescente ou decrescente alterando o vetor original 
 * @param vetor -> vetor a ser ordenado
 * @param n -> tamanho do vetor a ser ordenado
 * @param chave -> palavra chave para a função diferenciar se ordena crescente ou decrescente
 */
void sort_vector(int vetor[], int n, string chave);

/*
 * Chamada da função para leitura do arquivo com o vetor gerado 
 * @param vetor -> vetor onde será guardado os valores
 * @param n -> tamanho do vetor
 */
void open_file(int vetor[], int n);

/*
 * Chamada para função que inicializa e faz um cabeçalho no arquivo de saída 
 * @param filename -> nome do arquivo de saída
 */
void header_exit_file(string filename);

/*
 * Chamada da função para guardar no arquivo de saída as informações necessaŕias 
 * @param filename -> nome do arquivo a ser alterado
 * @param qtd_elementos -> quantidade total de elementos
 * @param cont_bbs -> número de vezes que o vetor é utilizado no método bubble sort
 * @param cont_sel -> número de vezes que o vetor é utilizado no método selection sort
 * @param cont_ins -> número de vezes que o vetor é utilizado no método insertion sort
 */
void exit_file(string filename, int qtd_elementos, int cont_bbs, int cont_sel, int cont_ins);

/*
 * Chamada para função que printa na tela uma interface 
 */
void interface();

/**
 * Chamada para função que printa na tela os resultados finais de cada ordenação
 * @param entrada -> string para saber como está a entrada do vetor (ordenado, crescente, decrescente)
 * @param qtd_elementos -> quantidade de elementos
 * @param cont_bbs -> número de vezes que o vetor é utilizado no método bubble sort
 * @param cont_sel -> número de vezes que o vetor é utilizado no método selection sort
 * @param cont_ins -> número de vezes que o vetor é utilizado no método insertion sort
 */
void result_print(string entrada, int qtd_elementos, int cont_bbs, int cont_sel, int cont_ins);

/*
 * Chamada para função que faz os métodos em um intervalo fornecido pelo usário e 
 * guarda no arquivo de saída 
 * @param vetor -> vetor a ser ordenado
 * @param intervalo -> qual intervalo de comparação o método deve usar
 * @param n -> tamanho do vetor
 */
void result_to_file(int vetor[], int intervalo, int n);

#endif