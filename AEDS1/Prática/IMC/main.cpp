#include <cstdlib>
#include <stdio.h>

using namespace std;
int main() {
    float peso, altura, imc;
    
    printf("\tCálculo de IMC\n");
    
    printf("\tInsira o peso(entre 50kg e 250kg):");
    scanf("%f", &peso);
    while(peso < 50 || peso > 250){
        printf("\tValor inválido.");
        printf("\tInsira um valor válido: ");
        scanf("%f", &peso);
    }
    
    printf("\tInsira a altura em metros (entre 0.5m e 2.50m):");
    scanf("%f", &altura);
    while(altura < 0.5 || altura > 2.50){
        printf("\tValor inválido.");
        printf("\tInsira um valor válido: ");
        scanf("%f", &altura);
    }
        
    imc = (peso/(altura*altura));
    
    if(imc < 16){
        printf("\tO cálculo de IMC indica-> BAIXO PESO(GRAU I) IMC = %.2f.", imc);       
    }else if(imc < 16.99){
        printf("\tO cálculo de IMC indica-> BAIXO PESO(GRAU II) IMC = %.2f.", imc);        
    }else if(imc < 18.49){
        printf("\tO cálculo de IMC indica-> BAIXO PESO(GRAU III) IMC = %.2f.", imc);        
    }else if(imc < 24.99){
        printf("\tO cálculo de IMC indica-> PESO ADEQUADO IMC = %.2f.", imc);       
    }else if(imc < 29.99){
        printf("\tO cálculo de IMC indica-> SOBREPESO IMC = %.2f.", imc);
    }else if(imc < 34.99 ){
        printf("\tO cálculo de IMC indica-> OBESIDADE(GRAU I) IMC = %.2f.", imc);       
    }else if(imc < 39.99){
        printf("\tO cálculo de IMC indica-> OBESIDADE(GRAU II) IMC = %.2f.", imc);       
    }else{
        printf("\tO cálculo de IMC indica-> OBESIDADE(GRAU III) IMC = %.2f.", imc);       
    }
}