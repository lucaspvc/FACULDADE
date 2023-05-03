/**
 * Código do slide 10
 * Lucas Pessoa Oliveira Alves
 **/
#include <stdio.h>

int main(int argc, char const *argv[]){
    float a;
    printf("Escreva o valor de A: ");
    scanf("%f", &a);
    while (a >= 0){
        a = a - 1;
        printf ("%f \n", a);
    }
    puts("Fim da repetição.");
    return 0;

    /** Códgio do Prof.Luiz
     * int a;
     * scanf ("%d", &a);
     * while (1) {
     *      printf("%d\n", a);
     *      a = a - 1;
     *      if (a < 0)
     *          break; 
     * }
     * puts ("buuuuuuummmmm"); //mais rápido que printf, só aceita literal.
     * return 0;
    */
}

