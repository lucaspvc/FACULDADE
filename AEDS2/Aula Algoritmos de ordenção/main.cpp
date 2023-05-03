#include <iostream>
#include "ordenacao.h"

using namespace std;



void imprimevetor(int *v) { // assinatura
    for (int * p = v; p < v + 10; p++) // corpo da função
        cout << "  " << *p;
    cout << endl;
}

int main(int argc, char**argv) {

    cout << endl << " Métodos de Ordenação" << endl << endl;

    int vb0[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Vetor ordenado.
    int vb1[10] = {5, 8, 2, 0, 6, 9, 1, 4, 3, 7}; // Vetor desordenado.
    int vb2[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; // Vetor em ordem inversa.

    cout << " Bubble Sort, vetor desordenado: " << endl;
    imprimevetor(vb1); // chamada da função
    insertionsort(vb1);
    imprimevetor(vb1);
    
    /*  cout << " Bubble Sort, vetor desordenado: " << endl;
      imprimevetor(vb1);
      bubblesort(vb1);
      imprimevetor(vb1);

    /*  cout << " Bubble Sort, vetor em ordem inversa: " << endl;
      imprimevetor(vb2);
      bubblesort(vb2);
      imprimevetor(vb2);
     */
    return 0;
}
