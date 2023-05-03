#include <iostream>

using namespace std;

void imprimevetor1 (int *v){
    for (int i = 0; i < 4; i++)
        cout << " " << v[i];
    cout << endl;
}

void imprimevetor2 (int *v){
    for (int i = 0; i < 6; i++)
        cout << " " << v[i];
    cout << endl;
}

int main (int argc, char**argv){
    
    int a[4] = {0, 3, 6, 9};
    int b[6] = {1, 2, 4, 5, 7, 8};
    int c[10];
    int i = 0, j = 0, k = 0;
    
    cout << " Vetor A " << endl;
    imprimevetor1  (a);
    
    cout << " Vetor B " << endl;
    imprimevetor2  (b);
    
    cout << " Soma dos Vetores " << endl;
    
    
    while (i < 4 && j<6){
        if ( a[i] < b[j]){
            c[k] = a[i];
            i++;
            k++;
        } else {
            c[k] = b[j];
            j++;
            k++;
        }
    }
    if (i < 4)
        while (i < 4){
            c[k] = a[i];
            i++;
            k++;
        }   
            
    if (j < 6) {
        while (j < 6)
            c[k] = b[j];
            j++;
            k++;
    }
    for (k = 0; k < 10; k++)
        cout << c[k] << " ";
    cout << endl;
    
}