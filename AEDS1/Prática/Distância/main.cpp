#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {
    float valor;
    ifstream coordenada("coordenada.txt");
    float soma, media, maior, menor;
    int contador = 0;
    soma = 0;
    maior = 0;
    menor = 0;

    if (!coordenada.is_open()) {
        cout << "\nErro: Arquivo não encontrado.\n";
        return 1;
    }

    coordenada >> valor;
    menor = maior = valor;

    while (valor != 0) {
        printf("Altura %d: ", contador + 1);
        cout << valor << endl;
        soma = soma + valor;
        if (valor > maior) {
            maior = valor;
        }
        if (valor < menor) {
            menor = valor;
        }
        coordenada >> valor;
        contador++;
    }


    if (contador != 0) {
        media = soma / contador;
        printf("\nA média de altura é: %.2f \n", media);
        printf("O menor valor é: %.2f \n", menor);
        printf("O maior valor é: %.2f \n", maior);
    }
    coordenada.close();

    return 0;
}