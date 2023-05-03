/*
 *Algoritmo do exercício 2 slide 17/aula 07.
 *Lucas Pessoa Oliveira Alves 
*/
#include <stdio.h>

int main(int argc, const char*argv[]){
    float raio, area;
    printf("Digite o valor do raio: ");
    scanf ("%f", &raio);
    area = 3.14 * raio * raio;
    printf("O círculo de raio %.2f tem área de %.2f\n", raio, area);
    return 0;
}