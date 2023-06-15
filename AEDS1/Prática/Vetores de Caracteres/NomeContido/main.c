#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
    int i, j;
    char nome[30], sobrenome[30], nomecompleto[60];
    i = j = 0;

    printf("Insira o nome: ");
    scanf(" %s", nome);
    printf ("Insira o sobrenome: ");
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
    printf("O nome completo é: %s \n", nomecompleto);

    printf("Insira o nome a ser comparado: ");
    scanf(" %s", nome);

    j = 0;
    i = 0;

    while(nomecompleto[j] != '\0' && nome[i] != '\0'){
        i = 0;
        while(nome[i] == nomecompleto[j+i]){
           i++;
        }
        /*if(nome[i] == nomecompleto[j]){
            i++;
        } else{
            i = 0;
        }*/
        j++;
    }

    if(nome[i] == '\0'){
        printf("Nome encontrado.\n");
    }else{
        printf("Nome não encontrado.\n");
    }

    return 0;
}