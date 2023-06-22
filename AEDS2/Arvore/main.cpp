/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2022.1.08.044
 *
 * Created on 6 de dezembro de 2022, 18:02
 */

#include <cstdlib>

#include "arvore.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    noArvore_* inicia_arvore();
    
    noArvore * arv = new (noArvore);
    arv->valor = 17;
    arv->esq=new(noArvore);
    arv->esq->valor=12;
    arv->esq->esq = NULL;
    arv->dir->dir = NULL;

    return 0;
}