#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

int inst = 0, tamanho = 10;
int *z;

int* inicializa (int tam){
    int *v = (int *)malloc(tam*sizeof(int));
    int *p;
    srand(time(NULL));
    for (p = v; p < v + tam; p++){
        *p = rand() % 100;
    }
    return v;
}



void intercala1 (int p, int q, int r, int v[]){
    int *w;
    w = (int *)malloc((r-p)*sizeof (int));
    int i = p, j = q;
    int k = 0;
    while (i < q && j < r){
        if ( v[i] <= v[j])
            w[k++] = v[i++];
        else
            w[k++] = v[j++];
    }
    while (i < q)
        w[k++] = v[i++];
    while (j < r)
        w[k++] = v[j++];
    for (i = p; i < r; ++i)
        v[i] = w[i-p];
    free (w);
    
} 


void MergeSort (int p, int r, int v[]){
    if (p < r-1){
        int q = (p + r)/2;
        MergeSort (p, q, v);
        MergeSort (q, r, v);
        intercala1 (p, q, r, v);        
    }
}

int separa (int v[], int p, int r){
    int c = v[r];//pivô
    int temp, j = p;
    for (int k = p; k < r; ++k)
        if (v[k] <= c){
            temp = v[j];
            v[j] = v[k];
            v[k] = temp;
            ++j;
        }
    v[r] = v[j];
    v[j] = c;
    return j;
}

void QuickSort (int v[], int p, int r){
    if (p < r){
        int j = separa (v, p, r);
        QuickSort (v, p, j-1);
        QuickSort (v, j+1, r);
    }
}



int main(int agrv, char** argv){
    int *v;
    
    v = inicializa(10);
    
    cout << " Estado Inicial" << endl;
    for (int *p = v; p < v + 10; p++){
        cout << "  " << *p;
    }
    
    //MergeSort(0, 10, v);
    QuickSort (v, 0, 9);
    
    cout << "\n Estado Final" << endl;
    for (int i= 0; i<10; i++){
        cout << "  " << v[i];
    }
}