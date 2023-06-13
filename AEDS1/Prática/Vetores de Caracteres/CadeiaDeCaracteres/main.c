#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
    int i, j;
    char nome[30], sobrenome[30], nomecompleto[60];
    i = j = 0;

    printf("Insira o nome: ");
    scanf(" %s", nome);
    printf ("\nInsira o sobrenome: ");
    scanf(" %s", sobrenome);

    while(nome[i] != '\0'){
        nomecompleto[i] = nome[i];
        i++;
    }
    nomecompleto[i]= ' ';
    i++;
    while(sobrenome[j] != '\0'){
        nomecompleto[i] = sobrenome[j];
        i++;
        j++;
    }
    nomecompleto[i]='\0';
    printf("\nO nome completo é: %s. \n", nomecompleto);

    return 0;
}