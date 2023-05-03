#include <cstdlib>
#include <stdio.h>

using namespace std;

int main (int argc, char** argv){
    
    int valorint = 50;
    short int valorsint = 50;
    long int valorlint = 50;
    float valorfloat = 50;
    double valordouble = 50;
    unsigned char valorchar = 'A';
    long int proximo, anterior;
    
    
    printf("\n\tTipos de Variáveis e Alocação de Memória \n\n");
    
    printf("\tVariável Int: \n");
    printf("\t\tValor Armazenado: %d\n", valorint);
    printf("\t\tEndereço na Memória: %p\n", &valorint);
    printf("\t\tQuantidade em bytes: %li\n\n", sizeof(int));
    
    printf("\tVariável Float: \n");
    printf("\t\tValor Armazenado: %.2f\n", valorfloat);
    printf("\t\tEndereço na Memória: %p\n", &valorfloat);
    printf("\t\tQuantidade em bytes: %li\n\n", sizeof(float));
    
    printf("\tVariável Double: \n");
    printf("\t\tValor Armazenado: %.2f\n", valordouble);
    printf("\t\tEndereço na Memória: %p\n", &valordouble);
    printf("\t\tQuantidade em bytes: %li\n\n", sizeof(double));
    
    printf("\tVariável Long int: \n");
    printf("\t\tValor Armazenado: %ld\n", valorlint);
    printf("\t\tEndereço na Memória: %p\n", &valorlint);
    printf("\t\tQuantidade em bytes: %li\n\n", sizeof(long int));
    
    printf("\tVariável Short int: \n");
    printf("\t\tValor Armazenado: %d\n", valorsint);
    printf("\t\tEndereço na Memória: %p\n", &valorsint);
    printf("\t\tQuantidade em bytes: %li\n\n", sizeof(short int));
    
    printf("\tVariável char: \n");
    printf("\t\tValor Armazenado: %c\n", valorchar);
    printf("\t\tValor Armazenado: %d\n", valorchar);
    printf("\t\tEndereço na Memória: %p\n", &valorchar);
    printf("\t\tQuantidade em bytes: %li\n\n", sizeof(char));
    
    //printf("\tVariável Char: \n");
    
    /*valorchar = 0;
    while (valorchar < 255){
        printf("\t\tCarcter: %c",valorchar);
        printf("\t\tCódigo: %d\n", valorchar);
        valorchar++;
    }*/
    
    anterior = 0;
    proximo = 1;
    while (proximo>anterior){
        anterior = proximo;
        proximo ++;
    }
    printf ("\n\tInferior: %u <---> Superior %u", proximo, anterior);
       
    
    
    return 0;
}