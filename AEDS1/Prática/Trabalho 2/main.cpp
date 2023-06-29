#include <bits/stdc++.h>

using namespace std;

int bubblesort(int v[], int n){
  int aux, contBubble;
  aux = contBubble = 0;
  for (int i = n - 1; i > 0; i--){
    for (int j = 0; j < i; j++){
        if (v[j] > v[j+1]){
            aux = v[j];
            v[j] = v[j+1];
            v[j+1] = aux;
        }
    }
  }
  return 0;
}

int insertionsort(int v[], int n){
  int aux, j, contInsertion;
  contInsertion = 0;
    for (int i = 1; i < n; i++){
        aux = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > aux){
            v[j+1] = v[j];
            j--;
            contInsertion++;
        }
        v[j+1] = aux;
    }
    return contInsertion;
}

int selectionsort(int v[], int n){
  int aux, min, contSelection;
  contSelection = 0;
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
        contSelection++;
    }
    return contSelection;
}

void imprimevetor(int v[], int n){
  for (int i = 0; i < n; i++)
    cout << v[i] << " ";
  cout << endl;
}

int main(int argc, char const *argv[]){

  int contSelection;
  int vb0[10] = {0,1,2,3,4,5,6,7,8,9}; // Vetor ordenado.
  int vb1[10] = {9,8,2,0,6,5,1,4,3,7}; // Vetor desordenado.
  int vb2[10] = {9,8,7,6,5,4,3,2,1,0}; // Vetor em ordem inversa.

 /* cout << "Selection Sort, vetor ordenado: " << endl;
  imprimevetor(vb0, 10);
  contSelection = selectionsort(vb0, 10);
  imprimevetor(vb0, 10);
  cout << "Contagem: " << contSelection << endl;

  cout << "Selection Sort, vetor desordenado: " << endl;
  imprimevetor(vb1, 10);
  contSelection = selectionsort(vb1, 10);
  imprimevetor(vb1, 10);
  cout << "Contagem: " << contSelection << endl;

  cout << "Selection Sort, vetor em ordem inversa: " << endl;
  imprimevetor(vb2, 10);
  contSelection = selectionsort(vb2, 10);
  imprimevetor(vb2, 10);
  cout << "Contagem: " << contSelection << endl;*/

  /*cout << " Buble Sort, vetor ordenado: " << endl;
  imprimevetor(vb0, 10);
  bubblesort(vb0, 10);
  imprimevetor(vb0, 10);

  cout << " Bubble Sort, vetor desordenado: " << endl;
  imprimevetor(vb1, 10);
  bubblesort(vb1, 10);
  imprimevetor(vb1, 10);

  cout << " Bubble Sort, vetor em ordem inversa: " << endl;
  imprimevetor(vb2, 10);
  bubblesort(vb2, 10);
  imprimevetor(vb2, 10);*/

    cout << " Insertion Sort, vetor ordenado: " << endl;
  imprimevetor(vb0, 10);
  contSelection = insertionsort(vb0, 10);
  imprimevetor(vb0, 10);
  cout << "Contagem: " << contSelection << endl;

  cout << " Insertion Sort, vetor desordenado: " << endl;
  imprimevetor(vb1, 10);
  contSelection = insertionsort(vb1, 10);
  imprimevetor(vb1, 10);
  cout << "Contagem: " << contSelection << endl;


  cout << " Insertion Sort, vetor em ordem inversa: " << endl;
  imprimevetor(vb2, 10);
  contSelection = insertionsort(vb2, 10);
  imprimevetor(vb2, 10);
  cout << "Contagem: " << contSelection << endl;


    return 0;
}