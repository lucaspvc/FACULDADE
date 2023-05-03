/**
 * Código do Exercício 1-Aula 09
 * Lucas Pessoa Oliveira Alves
**/
#include <stdio.h>

int main(int argc, char const *argv[]){
    long int n, fat;
    printf ("Insira o valor para o cálculo da fatorial: ");
    scanf("%d", &n);
    printf("\nO fatorial de %d é : ", n);
    fat = 1;
    while (n > 0){
        fat = fat * n;
        n = n - 1;
    }
    printf("%d \n", fat);
    return 0;

    /** Código do Prof. Luiz
     * int n, fat;
     * scanf("%d", &n);
     * fat = 1;
     * while (1){
     *      if(n <= 0)
     *          break;
     *      fat = fat * n;
     *      n = n - 1;
     * }
     * printf("fatorial = %d\n", fat);
     * return 0;
    */
}