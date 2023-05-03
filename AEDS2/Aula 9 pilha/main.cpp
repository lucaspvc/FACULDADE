#include <iostream>
#include <stdlib.h>
#include "pilha.h"

using namespace std;

tPilha * pilha1;

int main() {
    no * p;
    pilha1 = inicia_pilha();

    push(pilha1, 5);
    cout<<"push pilha 1: ";
    imprime(pilha1);

    push(pilha1, 10);
    cout<<"push 2: ";
    imprime(pilha1);

    push(pilha1, 15);
    cout<<"push 3: ";
    imprime(pilha1);

    push(pilha1, 12);
    cout<<"push 4: ";
    imprime(pilha1);

    push(pilha1, 20);
    cout<<"push 5: ";
    imprime(pilha1);

    p = pop(pilha1);
    cout<<"pop 1: "<< p->valor <<endl;
    delete (p);
    imprime(pilha1);

    p = pop(pilha1);
    cout<<"remove 2: "<< p->valor <<endl;
    delete (p);
    imprime(pilha1);

    p = pop(pilha1);
    cout<<"remove 3: "<< p->valor <<endl;
    delete (p);
    imprime(pilha1);

    p = pop(pilha1);
    cout<<"remove 4: "<< p->valor <<endl;
    delete (p);
    imprime(pilha1);

    p = pop(pilha1);
    cout<<"remove 5: "<< p->valor <<endl;
    delete (p);
    imprime(pilha1);

    p = pop(pilha1);
    cout<<"remove 6: "<< endl;
    delete (p);
    imprime(pilha1);

    pilha1 = encerra_pilha(pilha1);

    return (EXIT_SUCCESS);
}
