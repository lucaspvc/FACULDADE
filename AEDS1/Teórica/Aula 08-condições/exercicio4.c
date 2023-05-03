/*
 *Algoritmo do exercício 4 slide 09/aula 08.
 *Lucas Pessoa Oliveira Alves 
*/
#include <stdio.h>

int main(int argc, char const *argv[]){
    float a, b, c , delta;
    printf("Insira os valores de a, b e c, respectivamente:\n");
    scanf ("%f %f %f", &a, &b, &c);
    delta = b * b - 4 * a * c;
    if(delta >= 0 )
        printf ("A equação tem reízes reais\n");
    else
        printf ("A equação NÃO tem raízes reais\n");
    return 0;
}
