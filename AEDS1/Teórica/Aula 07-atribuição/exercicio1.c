/*
 *Algoritmo do exercício 1 slide 17/aula 07.
 *Lucas Pessoa Oliveira Alves 
*/
#include <stdio.h>

int main (int argc, const char*argv[]){
    float lado, area;
    printf("Insira o valor do lado:");
    scanf ("%f", &lado);
    area = lado*lado;
    printf("\nA área é: %.2f \n", area);
}