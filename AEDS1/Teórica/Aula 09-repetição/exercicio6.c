#include <stdio.h>

int main(int argc, char const *argv[]){
    int termo, sinal;
    double num, den, soma;
    num=1;
    termo=1;
    sinal =1;
    den=1;
    soma = 0;
    while (termo <= 50){
        printf ("O numerador é %.2f, o denominador é %.2f e o termo é %d \n\n", num, den, termo);
        soma = soma + (sinal*(num/den));
        sinal = -1*sinal;
        termo = termo+1;
        num = num * termo;
        den = den*2+1;
    }
    printf ("A soma total é: %.2f\n", soma);



/** Código do Luizin
 * int termo, sinal;
 * double num, den, soma; //den tem que ser double pois estoura o tamanho máximo de um int
 * soma = 0
 * termo = num = den  = 1;
 * do{
 *      soma = soma + (sinal*(num/den));
 *      sinal = -1*sinal;
 *      termo = termo + 1;
 *      num = num * termo;
 *      den = den * 2 + 1;      
 * } while (termo <= 50);
 * printf("A soma é:", soma);
 *  
*/
    return 0;
}
