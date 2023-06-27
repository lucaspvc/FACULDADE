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

int main(int argc, char const *argv[]){
        
    return 0;
}
