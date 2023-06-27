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
                contSelection;
            }
        }
        v[min] = v[i];
        v[i] = aux;
    }
    return contSelection;
}

void imprimevetor(int v[], int n, int cont){
  for (int i = 0; i < n; i++)
    cout << "  " << v[i];
  cout << endl;
}

int main(int argc, char const *argv[]){

    return 0;
}