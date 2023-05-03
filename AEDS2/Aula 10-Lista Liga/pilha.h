/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pilha.h
 * Author: paulo
 *
 * Created on February 4, 2021, 4:28 PM
 */

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
    insere_inicio(p, valor);
};

inline no * pop(tPilha * p){
    return remove_inicio(p);
};

#endif /* PILHA_H */

