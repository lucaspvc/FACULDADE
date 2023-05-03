/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   arvore.h
 * Author: 2022.1.08.044
 *
 * Created on 6 de dezembro de 2022, 18:03
 */

#ifndef ARVORE_H
#define ARVORE_H
#include <stdlib.h>

using namespace std;

typedef struct noArvore{
        int valor;
        noArvore * esq;
        noArvore * dir;
    }noArvore_;
    
noArvore_* inicia_arvore();

noArvore * insere (noArvore * raiz, noArvore * novo);


#endif /* ARVORE_H */

