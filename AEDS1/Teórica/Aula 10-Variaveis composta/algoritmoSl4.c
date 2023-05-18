/**
 * Código do slide 4
 * Lucas Pessoa Oliveira Alves
 **/
#include <stdio.h>

int main(int argc, char const *argv[]){
    float i, soma, media, qtd;
    int nota[10];
    soma = i = 0;
    while(1){
        if (i > 9){
            break;
        }
        scanf ("%f", &nota[i]);
        soma = soma + nota[i];
        i++;
    }
    media = soma/10;
    qtd = 0;
    i = 0;
    while (1){
        if(i > 9){
            break;
        }
        if (nota[i] > media){
            qtd = qtd + 1;
        }
        i++;
    }
    printf ("A média de notas é %.2f, e a quantidade de notas acima da média é %.2f", media, qtd);
    
    return 0;
}
