#include <iostream>

using namespace std;



void imprimevetor(int *v) { // assinatura
    for (int * p = v; p < v + 10; p++) // corpo da função
        cout << "  " << *p;
    cout << endl;
}

void bubblesort(int *v) {
    int aux;
    for (int *p = v + 9; p > v; p--)
        for (int *q = v; q < p; q++)
            if (*q > *(q + 1)) {
                aux = *q;
                *q = *(q + 1);
                *(q + 1) = aux;
            }
}

void insertionsort(int *v) {
    int aux, j;
    for (int i = 1; i < 10; i++) {
        aux = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > aux) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = aux;
    }
}

void selectionsort(int *v) {
    int aux, min;
    for (int i = 0; i < 10; i++) {
        min = i;
        aux = v[i];
        for (int j = i + 1; j < 10; j++) {
            if (v[j] < aux) {
                aux = v[j];
                min = j;
            }
        }
        v[min] = v[i];
        v[i] = aux;
    }
}

int main(int argc, char**argv) {

    cout << endl << " Métodos de Ordenação" << endl << endl;

    //int vb0[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Vetor ordenado.
    int vb1[10] = {5, 8, 2, 0, 6, 9, 1, 4, 3, 7}; // Vetor desordenado.
    //int vb2[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; // Vetor em ordem inversa.

    cout << " Bubble Sort, vetor desordenado: " << endl;
    imprimevetor(vb1); // chamada da função
    insertionsort(vb1);
    imprimevetor(vb1);
    
    /*  cout << " Bubble Sort, vetor desordenado: " << endl;
      imprimevetor(vb1);
      bubblesort(vb1);
      imprimevetor(vb1);

    cout << " Bubble Sort, vetor em ordem inversa: " << endl;
      imprimevetor(vb2);
      bubblesort(vb2);
      imprimevetor(vb2);
     */
    return 0;
}
