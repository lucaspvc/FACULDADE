#include <iostream>

using namespace std;

void imprimevetor (int *v){ //assinatura
    /*for (int i = 0; i < 10; i++) //corpo da função
        cout << " " << v[i]; 
    cout << endl;*/
    
    
    //trocando por ponteiro
    for (int *p = v; p < v + 10; p++) //corpo da função
        cout << " " << *p; 
    cout << endl;
    
    
}

void bubblesort(int *v){
    /*int aux;
    for (int i = 9; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (v[j] > v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }*/
    
    
    //Trocando para ponteiros.
    int aux;
    for (int *i = v+9; i > v; i--)
        for (int *j = v; j < i; j++)
            if (*j > *(j+1)){
                aux = *j;
                *j = *(j+1);
                *(j+1) = aux;
            }
}

void insertionsort(int  *v){
    /*int aux, j;
    for (int i = 1; i < 10; i++){
        aux = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > aux){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = aux;
    }*/
    
    //Trocando por ponteiros
    
    int aux, *j;
    for (int *i = v; i < v+10; i++){
        aux = *i;
        j = i - 1;
        while (*j >= 0 && *j > aux){
            *(j+1) = *j;
            j--;
        }
        *(j+1) = aux;
    }
    
}

int x = 11, y = 22, z = 33;//Variáveis globais.

void troca(int *a, int *b){ //a e b são parametros de uma função *a e *b é o local apontado pelo endereço
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int main (int argc, char**argv){
    
    //troca(x-5, y+7); //chamada da função.
    //y+7 e x-5 expressão aritmética que volta um inteiro
    //troca(x, y);
   // troca (&x, &y); //&x e &y são endereços do x e endereço do y.
    
    
    
            
            
    cout << endl << "Métodos de Ordenação" << endl << endl;
    
    int vb0[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //Vetor ordenado.
    int vb1[10] = {5, 8, 2, 0, 6, 9, 1, 4, 3, 7}; //Vetor desordenado.
    int vb2[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; //Vetor em ordem inversa.
    
   /*cout << "Bubble Sort, vetor ordenado: " <<endl;
    imprimevetor (vb0); //chamada da função
    bubblesort (vb0);
    imprimevetor (vb0);
    
    
    cout << endl << "Bubble Sort, vetor desordenado: " <<endl;
    imprimevetor (vb1); //chamada da função
    bubblesort (vb1);
    imprimevetor (vb1);
    
    cout << endl << "Bubble Sort, vetor em ordem inversa: " <<endl;
    imprimevetor (vb2); //chamada da função
    bubblesort (vb2);
    imprimevetor (vb2);*/
    
    //Insertion Sort
    
     cout << "Insertion Sort, vetor ordenado: " <<endl;
    imprimevetor (vb0); //chamada da função
    insertionsort(vb0);
    imprimevetor (vb0);
    
    
    cout << endl << "Insertion Sort, vetor desordenado: " <<endl;
    imprimevetor (vb1); //chamada da função
    insertionsort(vb1);
    imprimevetor (vb1);
    
    cout << endl << "Insertion Sort, vetor em ordem inversa: " <<endl;
    imprimevetor (vb2); //chamada da função
    insertionsort(vb2);
    imprimevetor (vb2);
    
return 0;
}