#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
    int i;
    char pal1[30];
    

    printf("Insira a palavra a ser convertida: ");
    scanf(" %s", pal1);

    for(i = 0; pal1[i] != '\0'; i++){
        if(pal1[i] >= 'a' && pal1[i] <= 'z'){
            pal1[i] = pal1[i] - 32;
        }
    }    
    printf ("A palavra convertida é: %s \n", pal1);
    return 0;
}