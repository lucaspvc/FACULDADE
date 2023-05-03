#ifndef PILHA_H
#define PILHA_H

#include "lista.h"

typedef tLista tPilha;

inline tPilha* inicia_pilha(){
    return inicia_lista();
};

inline tPilha * encerra_pilha(tPilha * p){
    return encerra_lista(p);
};

inline void push(tPilha * p, int valor){
    insere_inicio(p,valor);
};

inline no * pop(tPilha * p){
    return remove_fim(p);
};

#endif /* PILHA_H */