#include <iostream>
#include <stdlib.h>
#include "lista.h"

using namespace std;

tLista * lista1;

/*
 * 
 */
int main() {
    no * p;
    lista1 = inicia_lista();

    insere_inicio(lista1, 5);
    cout<<"insere 1: ";
    imprime(lista1);

    insere_inicio(lista1, 10);
    cout<<"insere 2: ";
    imprime(lista1);

    insere_fim(lista1, 15);
    cout<<"insere 3: ";
    imprime(lista1);

    insere_fim(lista1, 12);
    cout<<"insere 4: ";
    imprime(lista1);

    insere_inicio(lista1, 20);
    cout<<"insere 5: ";
    imprime(lista1);

    p = remove_inicio(lista1);
    cout<<"remove 1: "<< p->valor <<endl;
    delete (p);
    imprime(lista1);

    p = remove_fim(lista1);
    cout<<"remove 2: "<< p->valor <<endl;
    delete (p);
    imprime(lista1);

    p = remove_inicio(lista1);
    cout<<"remove 3: "<< p->valor <<endl;
    delete (p);
    imprime(lista1);

    p = remove_fim(lista1);
    cout<<"remove 4: "<< p->valor <<endl;
    delete (p);
    imprime(lista1);

    p = remove_fim(lista1);
    cout<<"remove 5: "<< p->valor <<endl;
    delete (p);
    imprime(lista1);

    p = remove_inicio(lista1);
    cout<<"remove 6: "<< endl;
    delete (p);
    imprime(lista1);

    lista1 = encerra_lista(lista1);

    return (EXIT_SUCCESS);
}
