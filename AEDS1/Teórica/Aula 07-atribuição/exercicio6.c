/*
 *Algoritmo do exercício 6 slide 20/aula 07.
 *Lucas Pessoa Oliveira Alves 
*/
#include <stdio.h>

int main(int argc, char const *argv[]){
    float a, b, c;
    printf("Insira valor de a: ");
    scanf("%f", &a);
    printf("\nInsira valor de b: ");
    scanf("%f", &b);
    c=a+b;
    printf("\nA soma de A com B é : %.2f", c);
    c=a-b;
    printf("\nA subtração de B em A é : %.2f", c);
    c=a*b;
    printf("\nA multiplicação de A com B é : %.2f", c);
    c=a/b;
    printf("\nA divisão de A por B é : %.2f", c);
    return 0;
}
