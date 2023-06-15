#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
    char cpf[14];
    int j = 0;


    printf("Insira o CPF: ");
    scanf(" %s", cpf);
    
    for( int i = 0; cpf[i] != '\0'; i++){
        if(cpf[i] >= '0' && cpf[i] <= '9'){
            cpf[j] = cpf[i];
            j++;
        }
    }
    cpf[j] = '\0';

    printf("O CPF sem caracteres especiais é: %s \n", cpf);

    return 0;
}