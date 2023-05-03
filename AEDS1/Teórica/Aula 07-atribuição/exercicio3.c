/*
 *Algoritmo do exercício 3 slide 18/aula 07.
 *Lucas Pessoa Oliveira Alves 
*/
#include <stdio.h>

int main (int argc, const char*argv[]){
    float valor, inss, horas, salario;
    printf("Insira o valor da aula por aula:");
    scanf("%f", &valor);
    printf("\nInsira o desconto do INSS:");
    scanf("%f", &inss);
    printf("\nInsira a quantidade de horas trabalhadas no mês:");
    scanf("%f", &horas);
    salario = valor*horas*((100- inss)/100);
    printf("\nO salário líquido é: %.2f \n", salario);
}