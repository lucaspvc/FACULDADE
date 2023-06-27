#include <bits/stdc++.h>

using namespace std;

void bubblesort(int v[], int n){
  int aux = 0;
  for (int i = n - 1; i > 0; i--){
    for (int j = 0; j < i; j++){
        if (v[j] > v[j+1]){
            aux = v[j];
            v[j] = v[j+1];
            v[j+1] = aux;
        }
    }
  }
}

void insertionsort(int v[], int n){
  int aux, j;
    for (int i = 1; i < n; i++){
        aux = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > aux){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = aux;
    }
}

void selectionsort(int v[], int n){
  int aux, min;
    for (int i = 0; i < n; i++){
        min = i;
        aux = v[i];
        for(int j = i+1; j < n; j++){
            if (v[j] < aux){
                aux = v[j];
                min = j;
            }
        }
        v[min] = v[i];
        v[i] = aux;
    }
}

void imprimevetor(int v[], int n){
  for (int i = 0; i < n; i++)
    cout << "  " << v[i];
  cout << endl;
}

int main(int argc, char**argv){
  cout << endl << " Métodos de Ordenação" << endl << endl;

  int vb0[10] = {0,1,2,3,4,5,6,7,8,9}; // Vetor ordenado.
  int vb1[10] = {5,8,2,0,6,9,1,4,3,7}; // Vetor desordenado.
  int vb2[10] = {9,8,7,6,5,4,3,2,1,0}; // Vetor em ordem inversa.

  cout << " Selection Sort, vetor ordenado: " << endl;
  imprimevetor(vb0, 10);
  selectionsort(vb0, 10);
  imprimevetor(vb0, 10);

  cout << " Selection Sort, vetor desordenado: " << endl;
  imprimevetor(vb1, 10);
  selectionsort(vb1, 10);
  imprimevetor(vb1, 10);

  cout << " Selection Sort, vetor em ordem inversa: " << endl;
  imprimevetor(vb2, 10);
  selectionsort(vb2, 10);
  imprimevetor(vb2, 10);

  return 0;
}