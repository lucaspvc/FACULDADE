#include <cstdlib>
#include <stdio.h>

using namespace std;

int main() {
    float l1, l2, l3;
    printf("\t\t Programa para saber qual tipo é o triângulo!\n");

    printf("\tInsira o lado 1 (valores positivos):\n");
    scanf("%f", &l1);
    while (l1 < 0) {
        printf("\tValor inválido.");
        printf("\tInsira um valor válido (valores positivos):\n");
        scanf("%f", &l1);
    }

    printf("\tInsira o lado 2 (valores positivos):\n");
    scanf("%f", &l2);
    while (l2 < 0) {
        printf("\tValor inválido.");
        printf("\tInsira um valor válido: (valores positivos)\n ");
        scanf("%f", &l2);
    }

    printf("\tInsira o lado 3 (valores positivos):\n");
    scanf("%f", &l3);
    while (l3 < 0) {
        printf("\tValor inválido.");
        printf("\tInsira um valor válido (valores positivos):\n ");
        scanf("%f", &l3);
    }

    if (l1 >= l2 + l3 || l2 >= l1 + l3 || l3 >= l1 + l2) {
        printf("\tOs lados fornecidos não formam um triângulo!\n");
    } else if (l1 == l2 && l2 == l3) {
        printf("\tO tipo do triângulo é -> TRIÂNGULO EQUILÁTERO\n");
    } else {
        if (l1 == l2 && l1 != l3 || l1 == l3 && l1 != l2) {
            printf("\tO tipo do triângulo é -> TRIÂNGULO ISÓSCELES\n");
        } else {
            printf("\tO tipo do trinângulo é -> TRIÂNGULO ESCALENO\n");
        }
        if (l1 * l1 == l2 * l2 + l3 * l3 || l2 * l2 == l1 * l1 + l3 * l3 || l3 * l3 == l1 * l1 + l2 * l2) {
            printf("\tO triângulo também é -> TRIÂNGULO RETÂNGULO");
        }

    }





    /*
     * condição de existência do triângulo = 
     * | l2 - l3 | < l1 < l2 + l3
     * | l1 - l3 | < l2 < l1 + l3
     * | l1 - l2 | < l3 < l1 + l2
     
     * Triângulo Equilátero
     * l1=l2=l3 (l1 == l2 && l1 == l3)
     * 
     * Triângulo Isósceles
     * l1=l2 ou l1=l2 e l1!=l2 ou l1!=l2 (l1==l2 && l1!=l3 || l1==l3 && l1!=l2)
     * 
     * Triângulo escaleno
     * lmain.cpp:74:1: error: expected declaration before ‘}’ token1!=l2!=l3 (l1!=l2 && l2!=l3)
     * 
     * Triângulo retangulo
     * l1*l1 = l2*l2 + l3*l3 ou l2*l2 = l1*l1 + l3*l3 ou l3*l3 = l1*l1 + l2*l2
     * 
     */
}

