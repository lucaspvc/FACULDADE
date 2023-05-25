#include <bits/stdc++.h>
#include <math.h>

#include "cores.h"

using namespace std;

int main(int argc, char const *argv[]){
    float notas[10] = {20,21,22,23,24,25,26,27,28,29};
    float acima[10] = {0,0,0,0,0,0,0,0,0,0};
    float media;
    int i, j;
    media = 0;
    j = 0;

    cout << "Primeiro valor: " << notas[0] << endl;
    cout << "Sexto valor: " << notas[5] << endl;

    
    for (i = 0; i < 10; i++){
        cout << "O " << i+1 << "º valor é: " << notas[i] << endl;
        media = media + notas[i];
    }
    media = media/i;
    cout << "A média é: " << azul_N << media << reset << endl;

    for (i = 0; i < 10; i++){
        if (notas[i] > media){
            //cout << "O valor " << notas[i] << ", na posição " << i+1 << ", está acima da média" << endl;
            acima[j] = notas[i];
            j++;
        }
    }
    cout << "Os valores acima da média são: ";
    for (i = 0 ; i < j; i++){
        cout << acima[i] << " ";

    }

    return 0;
}
