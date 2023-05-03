#include <cstdlib>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {
    float altura, soma, media;
    int contador = 0;
    soma = 0;

    printf("\tCalcúlo da média de altura de 10 pessoas\n");
    while (contador < 10) {
        printf("Insira a altura %d: ", contador+1);
        scanf(" %f", &altura); 
        while (altura < 0.00) {
            printf("\tValor inválido.");
            printf("\tInsira um valor válido (valores positivos):\n");
            scanf("%f", &altura);
        }
        soma = soma + altura;
        contador++;
    }
    media = soma / 10;
    printf("A média de altura é: %.2f", media);

    return 0;
}