/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   arvore.cpp
 * Author: 2022.1.08.044
 *
 * Created on 6 de dezembro de 2022, 18:04
 */

#include<bits/stdc++.h>
#include "arvore.h"

noArvore_* inicia_arvore() {
    noArvore_*tmp;
    tmp = NULL;
    return tmp;
}

noArvore_ * insere(noArvore * tmp, noArvore * novo) {
    noArvore_*aux;
    aux=tmp;
    if (aux == NULL) 
        return novo;
    if (aux->valor > novo->valor)
        aux->esq = insere(aux->esq, novo);
    else
        aux->dir = insere(aux->dir, novo);
    return aux;
}

