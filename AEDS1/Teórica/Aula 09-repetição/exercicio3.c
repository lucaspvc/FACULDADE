/**
 * Código do Exercício 3-Aula 09
 * Lucas Pessoa Oliveira Alves
 **/
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int idade, maior, contador, i;
    float porcentagem;
    char sexo, cabelo, olho;
    maior = 0;
    contador = 0;
    i = 0;
    idade = 0;
    while (idade != -1){
        printf ("Insira o sexo, olho, cabelo e a idade: \n");
        scanf ("%c %c %c %d", &sexo, &olho, &cabelo, &idade);
        if(sexo == 'f' && idade >= 18 && idade <= 35 && cabelo == 'l')
            contador ++;
        i++;
        if(idade > maior)
            maior = idade;
    }
    printf ("maior idade = %d\n", maior);
    porcentagem = contador/i;
    printf ("percentual = %.2f%%\n", porcentagem *100);

    /**Código do Luizin
     * char sexo, cabelo, olho;
     * int idade, maioridade, contahab, contamulher;
     * maioridade = -1;
     * contahab = 0;
     * contamulher = 0;
     * while(1){
     *      scanf("%c %c %c %d", &sexo, &olho, &cabelo, &idade);
     *      if(idade == -1)
     *          break;
     *      contahab++;
     *      if(sexo == 'f' && idade >= 18 && idade <= 35 && cabelo == 'l')
     *          contamulher++;
     *      if(idade > maioridade)
     *          maioridade = idade;
     * }
     * printf ("maior idade = %d\n", maioridade);
     * printf ("percentual = %.2f%%\n", contamulher/contahab * 100);
    */
 return 0;
}