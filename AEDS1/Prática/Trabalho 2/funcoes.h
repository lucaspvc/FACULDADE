#ifndef FUNCOES_H
#define FUNCOES_H
#include <bits/stdc++.h>

using namespace std;

int bubblesort(int vetor[], int n);

int insertionsort(int vetor[], int n);

int selectionsort(int vetor[], int n);

void create_file_random(int n, int m);

void ordena_vetor(int vetor[], int n, string chave);

void open_file(int vetor[], int n);

void header_exit_file(string filename);

void exit_file(string filename, int qtd_elementos, int cont_bbs, int cont_ins, int cont_sel);

void interface();

void result_print(string entrada, int qtd_elementos, int cont_bbs, int cont_ins, int cont_sel);

void result_to_file(int vetor[], int intervalo, int n);

#endif