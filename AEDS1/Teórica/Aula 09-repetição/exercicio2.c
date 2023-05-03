/**
 * Código do Exercício 2-Aula 09
 * Lucas Pessoa Oliveira Alves
 **/
#include <stdio.h>

int main(int argc, char const *argv[]) {
  int peso, maior, menor, id, idmenor, idmaior, i, contador;
  i = 1;
  printf("Escreva o peso e o id do boi %d: ", i);
  scanf("%d %d", &peso, &id);
  menor = peso;
  maior = peso;
  while (i <= 5) {
    i++;
    printf("\nEscreva o peso e o id do boi %d: ", i);
    scanf("%d %d", &peso, &id);
    if (maior < peso) {
      maior = peso;
      idmaior = id;
    } else if (menor > peso) {
      menor = peso;
      idmenor = id;
    }
  }
  printf("O maior boi tem peso %d e id %d\n", maior, idmaior);
  printf("O menor boi tem peso %d e id %d\n", menor, idmenor);

  /** RESOLUÇÃO DO LUIZIN
   * int id, peso, conta, idgordo, pesomaior, idmagro, pesomenor;
   * pesomaior = -1;
   * pesomenor = 1000000000;
   * conta = 0;
   * while(1){
   * conta = conta + 1;
   * scanf ("%d %d", &id, &peso);
   *    if (peso > pesomaior){
   *      pesomaior = peso;
   *      idgordo = id;
   *    }
   *    if (peso < pesomenor){
   *      pesomenor = peso;
   *      idmagro = id;
   *    }
   *    if (conta >= 9)
   *      break;
   * }
   * printf("Mais gordo, id = %d, peso = %d\n", idgordo, pesomaior);
   * printf("Mais magro, id = %d, peso = %d\n", idmagro, pesomenor);
   * 
   * //Para fazer o redirecionamento de arquivo txt para leitura a partir do scanf basta fazer [executável < .txt]
  */
  return 0;
}