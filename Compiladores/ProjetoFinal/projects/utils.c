/*+=============================================================
         UNIFAL = Universidade Federal de Alfenas.
         BACHARELADO EM CIENCIA DA COMPUTACAO.
Trabalho..: Registro e verificacao de tipos
Disciplina: Teoria de Linguagens e Compiladores
Professor.: Luiz Eduardo da Silva
Aluno.....: Lucas Pessoa Oliveira Alves
Data......: 14/12/2023
+=============================================================*/

// Tabela de Simbolos 
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Criar uma estrutura e operações para manipular uma lista de campos (necessáriamente antes da tabela declarada)
#define TAM_TAB 100

enum 
{
    INT,
    LOG,
    REG
};

char nomeTipo[3][4] = {"INT", "LOG", "REG"};

// Nova struct necessária: Lista de campos -> Lista encadeada (inserir e percorrer)
struct elemTabSimbolos
{
    char id[100]; // nome do identificador
    int end;      // endereco
    int tip;      // tipo
    int tam;      // tamanho
    int pos;      // posição na memoria
    struct no*ptno;  //lista encadeada
} tabSimb[TAM_TAB], elemTab;

//declaração dos campos de cada elemento
typedef struct lista_campos{
    char nome[100];
    int tipo;
    int pos;
    int desl;
    int tam;    
}listaCampos;

//declaração da struct de cada elemento da lista encadeada
typedef struct no *ptno;
struct no{
    struct lista_campos campos;
    ptno prox;
};

int posTab = 0; // indica a pproxima posicao livre para insercao

int buscaSimbolo (char *s) {
    int i;
    for(i = posTab - 1; strcmp(tabSimb[i].id, s) && i >= 0; i--);
    if(i == -1) {
        char msg[200];
        sprintf(msg, "Identificador [%s] nao encontrado!", s);
        yyerror(msg);
    }
    return i;
}

void insereSimbolo (struct elemTabSimbolos elem) {
    int i;
    if (posTab == TAM_TAB) yyerror("Tabela de Simbolos cheia !");
    
    for (i = posTab; strcmp(tabSimb[i].id, elem.id) && i >= 0; i--);
    if(i != -1) {
        char msg[200];
        sprintf(msg, "Identificador [%s] nao encontrado!", elem.id);
        yyerror(msg);
    }
    tabSimb[posTab] = elem;
    posTab++;
}



// Pilha Semantica
#define TAM_PILHA 100
int pilha[TAM_PILHA];
int topo = -1;

void empilha (int valor) {
    if (topo == TAM_PILHA)
        yyerror("Pilha Semantica cheia");
    pilha[++topo] = valor;
}

int desempilha () {
    if (topo == -1)
        yyerror("Pilha Semantica vazia");
    return pilha[topo--];    
}

void testaTipo(int tipo1, int tipo2, int ret) {
    int t1 = desempilha();
    int t2 = desempilha();

    if (t1 != tipo1 || t2 != tipo2) {
        yyerror("Incompatibilidade de tipo!");
    }

    empilha(ret);
}

//função de inserção na lista encadeada
ptno insereLista(ptno L, struct lista_campos campos){
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


//função de busca na lista encadeada
ptno buscaLista(ptno L, char nome[200] ){
    while (L && (strcmp (L->campos.nome, nome) != 0 ))
        L = L->prox;
    return L;
}

//função para printar a lista encadeada
void mostraLista(ptno L){
    while (L){
        if (L->prox)
            printf("(%s,%s,%d,%d,%d)=> ",
            L->campos.nome,
            nomeTipo[L->campos.tipo],
            L->campos.pos,
            L->campos.desl,
            L->campos.tam);
        else
            printf("(%s,%s,%d,%d,%d)",
            L->campos.nome,
            nomeTipo[L->campos.tipo],
            L->campos.pos,
            L->campos.desl,
            L->campos.tam);
        L = L->prox;
    }
}

void mostraTabela(){
    puts("Tabela de Simbolos");
    puts("------------------");
    printf("%15s | %s | %s | %s | %s | %s\n", "ID", "END", "TIP", "TAM", "POS", "CAMPOS");
    for (int i = 0; i < 100; i++)
        printf("-");
    for (int i = 0; i < posTab; i++){
        printf("\n%15s | %3d | %s | %3d | %3d | ",
        tabSimb[i].id,
        tabSimb[i].end,
        nomeTipo[tabSimb[i].tip],
        tabSimb[i].tam,
        tabSimb[i].pos);
        if(tabSimb[i].tip == REG){
            mostraLista(tabSimb[i].ptno);
        }
    }
    puts("");
}
