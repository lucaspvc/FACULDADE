/* Universidade Federal de Alfenas (UNIFAL) - 2023
 * Lucas Pessoa Oliveira Alves 2022.1.08.044
 *
 * Docente: Paulo Alexandre Bressan - Algoritimo e Estrutura de Dados I
 * 
 * Trabalho com o objetivo de compreender as diferenças entre os métodos de ordenação não recursivos,
 * conhecer uma forma de comparação de algoritmos e aprender como relatar os experimentos realizados.
 * 
 * Material utilizado:
 * - Métodos de ordenação disponibilizado na disciplina AEDS II
 *  disponível em: https://github.com/lucaspvc/FACULDADE/blob/main/AEDS2/Aula 2/
 */

#include <bits/stdc++.h>
#include <iomanip>
#include "cores.h"
#include "funcoes.h"
#include "funcoes.cpp"
using namespace std;

int main() {
    int m, // variável utilizada para guardar o valor máximo possível no vetor
        intervalo, // variável utilizada para guardar o intervalo de comparação
        n, // variável utilizada para guardar o tamanho do vetor
        cont_total_bbs, // variável utilizada para guardar o contador do bubble sort
        cont_total_ins, // variável utilizada para guardar o contador do insertion sort
        cont_total_sel; // variável utilizada para guardar o contador do selection sort
    
    cont_total_sel = cont_total_ins = cont_total_bbs = intervalo = m = n = 0;

    interface();

    cout << "Insira a " ciano "quantidade de elementos" reset " do vetor: ";
    cin >> n;
    int vetor[n] = {};

    cout << "Insira o " ciano "valor máximo" reset " possível no vetor: ";
    cin >> m;
    while (m <= n) {
        cout << "Valor máximo " vermelho_N "menor" reset " que a quantidade de elementos" << endl;
        cout << "Insira um valor máximo válido : ";
        cin >> m;
    }

    cout << "Insira o " ciano "intervalo" reset " de comparação: ";
    cin >> intervalo;
    while (intervalo >= n) {
        cout << "Itervalo " vermelho_N "maior" reset " que a quantidade de elementos" << endl;
        cout << "Insira um intervalo válido: ";
        cin >> intervalo;
    }

    cout << "=============================================================================================" << endl;

    create_file_random(n, m);
    open_file(vetor, n);
    header_exit_file("ALEATORIO.txt");
    header_exit_file("CRESCENTE.txt");
    header_exit_file("DECRESCENTE.txt");
    cout << "=============================================================================================" << endl;

    cont_total_bbs = bubblesort(vetor, n);
    cont_total_ins = insertionsort(vetor, n);
    cont_total_sel = selectionsort(vetor, n);
    result_print("ALEATÓRIO", n, cont_total_bbs, cont_total_sel, cont_total_ins);
    result_to_file(vetor, intervalo, n);

    sort_vector(vetor, n, "cresc");
    cont_total_bbs = bubblesort(vetor, n);
    cont_total_ins = insertionsort(vetor, n);
    cont_total_sel = selectionsort(vetor, n);
    result_print("CRESCENTE", n, cont_total_bbs, cont_total_sel, cont_total_ins);

    sort_vector(vetor, n, "dec");
    cont_total_bbs = bubblesort(vetor, n);
    cont_total_ins = insertionsort(vetor, n);
    cont_total_sel = selectionsort(vetor, n);
    result_print("DECRESCENTE", n, cont_total_bbs, cont_total_sel, cont_total_ins);

    return 0;
}