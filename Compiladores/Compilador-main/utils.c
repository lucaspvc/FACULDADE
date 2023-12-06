// Tabela de Simbolos 
#include <stdarg.h>

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
} tabSimb[TAM_TAB], elemTab;

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
    tabSimb[posTab++] = elem;    
}

void mostraTabela()
{
    puts("Tabela de Simbolos");
    puts("------------------");
    printf("%30s | %s | %s\n", "ID", "END", "TIP");
    for (int i = 0; i < 50; i++)
        printf("-");
    for (int i = 0; i < posTab; i++)
        printf("\n%30s | %3d | %s",
        tabSimb[i].id,
        tabSimb[i].end,
        nomeTipo[tabSimb[i].tip]);
    puts("");
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


typedef struct no*ptno;
struct no{
    char info;
    ptno prox;
};

ptno insere(ptno L, char infor){
    ptno p, new;
    new = (ptno) malloc(sizeof(struct no));
    new->info = info;
    new->prox = NULL;
    p = L;
    while (p && p->prox){
        p = p->prox;
    }
    if (p){
        p->prox = new;
    }else{
        L = new;
    }
    return L;
}

ptno busca(ptno L, char info){
    while (L && L->info!=info){
        L=L->prox;
    }
    return L;    
}

void mostra(ptno L){
    printf("[");
    while (L){
        if(L->prox){
            printf("%c", L->info);
        }else{
            printf("%c", L->info);
        }
        L = L->prox;
    }
    printf("]\n");
}