#include <stdio.h>
#define MAX 5
int main(int argc, char const *argv[])
{
    int vetor[MAX];
    int maior, menor, soma, media, acimaMedia;
    for (int i = 0, i < MAX; i++){
        scanf("%d", vetor + 1);
    }
    soma = maior = menor = vetor[0];
    for (int i = 1; i < MAX; i++){
        if (vetor[i] > maior){
            maior = vetor[i];
        }
        if (vetor[i] < menor){
            menor = vetor[i];
        }
        soma = soma + vetor[i];
    }
    media = soma/MAX;
    acimaMedia = 0;
    return 0;
}
