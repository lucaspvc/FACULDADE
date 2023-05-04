#include <stdio.h>

int main(int argc, char const *argv[]){
    int idade, contador, soma;
    contador = 0;
    soma = 0;
    printf("Insira as idades:");
    scanf("%d", &idade);
    while (idade != 0){
        soma = soma + idade;
        contador ++;
        printf("Insira as idades:");
        scanf("%d", &idade);
        }
    printf("A média das idades é: %.2f\n", (float)soma/contador );

/**Código do Luizin
 * int idade, conta, soma;
 * float media;
 * conta = 0;
 * soma = 0;
 * while(1){
 *      scanf("%d",&idade);
 *      if (idade == 0)
 *          break;
 *      soma = soma + idade;
 *      conta = conta + 1;
 * }
 * media = (float) soma/conta;
 * printf("Média = %.2f\n", media);
 * 
*/

    return 0;
}
