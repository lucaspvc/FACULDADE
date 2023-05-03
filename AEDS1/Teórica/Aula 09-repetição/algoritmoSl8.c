/**
 * Código do slide 6
 * Lucas Pessoa Oliveira Alves
 **/
#include <stdio.h>

int main(int argc, char const *argv[]){
    float a;
    printf("Escreva o valor de A: ");
    scanf("%f", &a);
    while (1){
        printf("%f\n", a);
        if(a < 0)
            break;
        a = a - 1;
    }
    puts("Fim da repetição.");
    return 0;

    /** Códgio do Prof.Luiz
     * int a;
     * scanf ("%d", &a);
     * while (1) {
     *      printf("%d\n", a);
     *      if (a < 0)
     *          break;
     *      a = a - 1; 
     * }
     * puts ("buuuuuuummmmm"); //mais rápido que printf, só aceita literal.
     * return 0;
    */
}

