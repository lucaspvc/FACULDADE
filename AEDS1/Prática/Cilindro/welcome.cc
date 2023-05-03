#include <stdio.h>

int main(){
    float raio, altura, volume, area;
    float pi = 3.14;
    
    printf("Cálculo do volume e área de um cilindro");
    printf("\nUtilizando pi = 3.14");
    
    printf("\nDigite o valor do raio: ");
    scanf(" %f", &raio);
    
    printf("\nDigite o valor da altura: ");
    scanf (" %f", &altura);
    
    volume = pi * (raio*raio) * altura;
    area = 2* pi * raio *(raio + altura);
    
    printf ("\nValor do volume: %.2f", volume);
    printf ("\nValor da área: %.2f", area);
}
