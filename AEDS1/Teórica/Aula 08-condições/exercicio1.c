/*
 *Algoritmo do exercício feito em sala para descobrir o menor valor /aula 08.
 *Lucas Pessoa Oliveira Alves 
*/
#include <stdio.h>

int main (int argc, char const *argv[]){
    int a, b, c;
    printf("Insira os valor [a], [b] e [c], respectivamente: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("O menor valor é: ");
    if (a < b && a < c){
        printf("%d\n", a);
    }else if(b < c){
        printf("%d\n", b);
    }else{
        printf("%d\n", c);
    }
}