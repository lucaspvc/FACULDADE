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
  return 0;
}