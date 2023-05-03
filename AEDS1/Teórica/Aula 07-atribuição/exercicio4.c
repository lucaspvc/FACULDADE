/*
 *Algoritmo do exercício 4 slide 19/aula 07.
 *Lucas Pessoa Oliveira Alves 
*/
#include <stdio.h>

int main (int argc, const char*argv[]){
    float distancia, tempo, velocidade, litros;
    printf ("Insira a velocidade média:");
    scanf ("%f", &velocidade);
    printf ("\nInsira o tempo gasto:");
    scanf ("%f", &tempo);
    distancia = velocidade * tempo;
    litros = distancia/12;
    printf("\nA quantidade de litros usados foi: %.2f", litros);
    printf("\nA distância percorrida foi: %.2f \n", distancia);
}