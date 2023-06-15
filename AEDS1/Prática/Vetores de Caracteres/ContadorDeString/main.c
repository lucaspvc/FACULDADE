#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
    char cpf[14];
    int j, k;
    j = k = 0;


    printf("Insira o CPF: ");
    scanf(" %s", cpf);
    
    for( int i = 0; cpf[i] != '\0'; i++){
        if(cpf[i] >= '0' && cpf[i] <= '9'){
            cpf[j] = cpf[i];
            j++;
        }
        k++;
    }
    cpf[j] = '\0';

    printf("O CPF sem caracteres especiais é: %s \n", cpf);
    printf("O tamanho da string original é: %d \n", k);
    printf("O tamanho da string final é: %d \n", j);


    return 0;
}