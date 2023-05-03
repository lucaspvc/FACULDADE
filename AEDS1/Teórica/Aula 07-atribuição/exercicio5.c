/*
 *Algoritmo do exercício 5 slide 20/aula 07.
 *Lucas Pessoa Oliveira Alves 
*/
#include <stdio.h>

int main(int argc, char const *argv[]){
    float a, b, aux;
    printf("Insira o valor de A:\n");
    scanf("%f", &a);
    printf("Insira o valor de B:\n");
    scanf("%f", &b);
    aux = a;
    a = b;
    b = aux;
    printf("[A] agora é: %.2f \n", a);
    printf("[B] agora é: %.2f \n", b);
    return 0;
}