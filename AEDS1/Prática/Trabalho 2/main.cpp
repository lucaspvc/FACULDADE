#include <bits/stdc++.h>
#include <iomanip>

#include "cores.h"
#include "funcoes.cpp" // no visual studio tem que ser assim
//#include "funcoes.hpp"

using namespace std;

int main(){
  int m, intervalo, n, aux, qtd, cont_total_bbs, cont_total_ins, cont_total_sel;
  cont_total_sel = cont_total_ins = cont_total_bbs = intervalo = m = n = aux = qtd = 0;

  interface();

  cout << "Insira a " ciano "quantidade de elementos" reset " do vetor: ";
  cin >> n;
  int vetor[n] = {};

  cout << "Insira o " ciano "valor máximo" reset " possível no vetor: ";
  cin >> m;
  while (m <= n){
    cout << "Valor máximo " vermelho_N "menor" reset " que a quantidade de elementos" << endl;
    cout << "Insira um valor máximo válido : ";
    cin >> m;
  }

  cout << "Insira o " ciano "intervalo" reset " de comparação: ";
  cin >> intervalo;
  while (intervalo >= n){
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

  cont_total_bbs = bubblesort (vetor, n);
  cont_total_ins = insertionsort (vetor, n);
  cont_total_sel = selectionsort (vetor, n);
  result_print ( "ALEATÓRIO",n, cont_total_bbs, cont_total_sel, cont_total_ins);
  result_to_file(vetor, intervalo, n);

  ordena_vetor(vetor, n, "cresc");
  cont_total_bbs = bubblesort (vetor, n);
  cont_total_ins = insertionsort (vetor, n);
  cont_total_sel = selectionsort (vetor, n);
  result_print ( "CRESCENTE",n, cont_total_bbs, cont_total_sel, cont_total_ins);

  ordena_vetor(vetor, n, "dec");
  cont_total_bbs = bubblesort (vetor, n);
  cont_total_ins = insertionsort (vetor, n);
  cont_total_sel = selectionsort (vetor, n);
  result_print ( "DECRESCENTE",n, cont_total_bbs, cont_total_sel, cont_total_ins);

  return 0;
}