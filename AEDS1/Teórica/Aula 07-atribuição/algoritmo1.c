/*
 *Algoritmo de exemplo feito em sala.
 *Lucas Pessoa Oliveira Alves 
*/
#include <stdio.h>

int main(int argc, char const*argv[]){
    float A, B, C;
    printf("Insira o valor de [A] e [B], respectivamente: ");
    scanf("%f %f", &A, &B);
    C = (A + B) / B;
    printf("A = %.2f B = %.2f C = %.2f\n", A, B, C);
    return 0;
}
