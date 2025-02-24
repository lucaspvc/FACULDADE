#include <stdio.h>
using namespace std;

int main() {
    float nota1, nota2, notatrab, media;
    printf("\n\tDigita a nota 1(nota entre 0 e 10):");
    scanf("%f", &nota1);
    while (nota1 < 0 || nota1 > 10) {
        printf("\tNota inválida.\n");
        printf("\tDigite uma nota válida:");
        scanf("%f", &nota1);
    }

    printf("\n\tDigite a nota 2(nota entre 0 e 10):");
    scanf("%f", &nota2);
    while (nota2 < 0 || nota1 > 10) {
        printf("\tNota inválida.\n");
        printf("\tDigite uma nota válida:");
        scanf("%f", &nota2);
    }
    printf("\n\tDigite a nota do trabalho(nota entre 0 e 10):");
    scanf("%f", &notatrab);
    while (notatrab < 0 || nota1 > 10) {
        printf("\tNota inválida.\n");
        printf("\tDigite uma nota válida:");
        scanf("%f", &notatrab);
    }

    media = (3 * nota1 + 3 * nota2 + 4 * notatrab) / 10;
    printf("\tMédia de AEDs I: %.1f\n\n", media);

    if (media >= 6.0) {
        printf("\tVocê está aprovado\n");
    } else {
        printf("\tVocê está reprovado.\n");
    }
    return 0;
}