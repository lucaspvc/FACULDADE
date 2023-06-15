#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
    int i, j;
    char pal1[30], pal2[30], nomecompleto[60];
    i = j = 0;

    printf("Insira a primeira palavra: ");
    scanf(" %s", pal1);
    printf ("Insira a segunda palavra: ");
    scanf(" %s", pal2);

    while(pal1[i] == pal2[i] && pal1[i] != '\0' && pal2[i] != '\0'){
        i++;
    }
    if(pal1[i] == '\0' || pal2[i] == '\0'){
        printf("As palavras são iguais.\n");
    }else{
        printf("Palavras diferentes!\n");
    }
  
}