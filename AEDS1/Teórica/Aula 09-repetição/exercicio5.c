#include <stdio.h>

int main(int argc, char const *argv[]){
    float c, f;
    f = 50;
    while (f <= 150){
        printf ("A temperatura em ºF é: %.2f\n", f);
        printf ("A temperatura em ºC é: %.2f\n", (float) 5/9*(f-32));
        printf ("------------------------------------------------\n");
        f++;
    }
    return 0;
}
