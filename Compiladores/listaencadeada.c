#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_TAB 100

enum 
{
    INT,
    LOG,
    REG
};

char nomeTipo[3][4] = {"INT", "LOG", "REG"};

typedef struct lista_campos
{
    char nome[100];
    int tipo;
    int pos;
    int desl;
    int tam;    
}listaCampos;

typedef struct no *ptno;
struct no
{
    struct lista_campos campos;
    ptno prox;
};

struct elemTabSimbolos
{
    char id[100]; // nome do identificador
    int end;      // endereco
    int tip;      // tipo
    int tam;      // tamanho
    int pos;      // posição na memoria
    struct lista_campos *campos;
} tabSimb[TAM_TAB], elemTab;

ptno insere(ptno L, struct lista_campos campos)
{
    ptno p;
    ptno new;
    new = (ptno)malloc(sizeof(struct no));
    new->campos= campos;
    new->prox = NULL;
    p = L;
    while (p && p->prox)
        p = p->prox;
    if (p)
        p->prox = new;
    else
        L = new;
    return L;
}

ptno busca(ptno L, struct lista_campos campos)
{
    while (L && (strcmp (L->campos.nome, campos.nome) != 0 ))
        L = L->prox;
    return L;
}

void mostra(ptno L)
{
    while (L)
    {
        if (L->prox)
            printf("( %s | %s | %d | %d | %d ) => ",
            L->campos.nome,
            nomeTipo[L->campos.tipo],
            L->campos.pos,
            L->campos.desl,
            L->campos.tam);
        else
            printf("( %s | %s | %d | %d | %d ) \n",
            L->campos.nome,
            nomeTipo[L->campos.tipo],
            L->campos.pos,
            L->campos.desl,
            L->campos.tam);
        L = L->prox;
    }
}

int main () {
    struct lista_campos lista;
    ptno L = NULL;
    strcpy(lista.nome, "AAA");
    lista.pos = 0;
    lista.tam = 1;
    lista.tipo = 1;
    lista.desl = 0;
    L = insere(L, lista);

     strcpy(lista.nome, "BBB");
    lista.pos = 1;
    lista.tam = 1;
    lista.tipo = 0;
    lista.desl = 0;
    L = insere(L, lista);

    strcpy(lista.nome, "CCC");
    lista.pos = 2;
    lista.tam = 1;
    lista.tipo = 2;
    lista.desl = 0;
    L = insere(L, lista);


    strcpy(lista.nome, "CC");
    //mostra(L);
     if (busca(L, lista))
         puts("achou\n");
     else
         puts("não achou\n");
}