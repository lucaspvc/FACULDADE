/*
 *Algoritmo do exercício 3 slide 09/aula 08.
 *Lucas Pessoa Oliveira Alves 
*/
#include <stdio.h>
int main(int argc, char const *argv[]){
    float nota;
    printf("Insira a nota do aluno: ");
    scanf("%f", &nota);
    if (nota >= 6){
        printf("O aluno está aprovado.\n");
    }else if(nota >= 4){
        printf ("O aluno está de prova final.\n");
    }else{
        printf ("O aluno está reprovado.\n ");
    }
   return 0;
}