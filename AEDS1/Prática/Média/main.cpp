#include <cstdlib>
#include <stdio.h>
#include "cores.h"

using namespace std;

int main(int argc, char** argv) {
    float altura, soma, media, maior, menor;
    int contador = 0;
    soma = 0;
    maior = 0;
    menor = 0;

    printf("\t\tCalcúlo da média de altura de 10 pessoas\n");
    printf("\nAo finalizar as alturas insira o valor 0\n");

    printf("Insira a altura %d: ", contador + 1);
    scanf(" %f", &altura);
    while (altura < 0.00) {
        red;
        printf("\tValor inválido.\n");
        reset;
        printf("Insira um valor válido (valores positivos):\n");
        scanf("%f", &altura);
    }
    maior = altura;
    menor = altura;

    while (altura != 0) {
        soma = soma + altura;
        if (altura > maior) {
            maior = altura;
        }
        if (altura < menor) {
            menor = altura;
        }
        contador++;
        printf("Insira a altura %d: ", contador + 1);
        scanf(" %f", &altura);
        while (altura < 0.00) {
            red;
            printf("\tValor inválido.\n");
            reset;
            printf("Insira um valor válido (valores positivos):\n");
            scanf("%f", &altura);
        }
    }
    if (contador != 0) {
        media = soma / contador;
        green;
        printf("\nA média de altura é: %.2f \n", media);
        printf("O menor valor é: %.2f \n", menor);
        printf("O maior valor é: %.2f \n", maior);
    }
    return 0;
}