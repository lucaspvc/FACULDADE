/*
*Exercício para aprovação e reprovação do aluno
*Lucas Pessoa Oliveira Alves
*/
#include <stdio.h>

int main() {
    float n1, n2, n3;
    printf ("\n Insira a primeira nota do aluno: ");
    scanf("%f", &n1);
    printf (" %.2f", n1);
    
    printf ("\n Insira a segunda nota do aluno: ");
    scanf("%f", &n2);
    printf (" %.2f", n2);
    
    printf ("\n Insira a terceira nota do aluno: ");
    scanf("%f", &n3);
    printf (" %.2f\n", n3);
    
    printf("\t Média de AEDs I: %.2f \n\n", (3 * n1 + 3 * n2 + 4 * n3) / 10);
    printf("\t Se a média for igual ou superior a 6.0, você está APROVADO.\n");
    printf("\t Se a média for inferior a 6.0, você está REPROVADO.\n");

    
    return 0;
}
