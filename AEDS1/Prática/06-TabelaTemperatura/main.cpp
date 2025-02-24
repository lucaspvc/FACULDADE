#include <cstdlib>
#include <stdio.h>

using namespace std;


int main(int argc, char** argv) {
    float tempcel, tempfah, x;
    
    tempcel = 0; //valor inicial para a variável de controle da repetição
    
    printf("Insira o valor do intervalo de 1 a 10\n");
    scanf("%f", &x);
    while (x > 10 || x < 0) {
        printf("Valor inválido.");
        printf("\tInsira um valor válido [0 a 10]:\n");
        scanf("%f", &x);
    }
    
    printf(" ___________________________________\n");
    printf("|\tCelsius    |  Fahrenheit    |\n");
    printf("|__________________|________________|\n");
    while(tempcel <= 100){ //condição de parada com a variável de controle
        tempfah = tempcel*9/5 + 32;
        printf("\t%06.2f           %06.2f    \n", tempcel, tempfah);
        tempcel = tempcel + x; //Incremento da variável de controle
    }

    return 0;
}

