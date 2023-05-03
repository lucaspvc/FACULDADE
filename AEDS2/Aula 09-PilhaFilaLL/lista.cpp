/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>

#include "lista.h"

using namespace std;

/**
 * Realiza a alocacao do espaco para que a lista possa comecar
 * a receber nos.
 * @return a lista vazia.
 */
tLista* inicia_lista() {
	tLista* tmp = new (tLista);
	tmp->tam = 0;
	tmp->lista = NULL;

        cout << "-A lista foi iniciada."<<endl;
	return tmp;
}

/**
 * Desaloca o espaco previamente alocado para a lista encadeada.
 * @param ptlista ponteiro para a lista.
 * @return NULL para atualizar o ponteiro da lista.
 */
tLista * encerra_lista(tLista * ptlista) {
	no * ant = ptlista->lista;
	no * pont = ptlista->lista;
	
	while(ant != NULL){
		pont = ant->prox;
		delete(ant);
		ant = pont;
	}
	delete(ptlista);
        cout << "-A lista foi removida."<<endl;
	
        return NULL;
}

/**
 * Busca pelo valor de chave passado dentro da lista encadeada.
 * @param chave a ser buscada.
 * @param ant ponteiro anterior a posicao encontrada.
 * @return verdareiro se o elemento foi encontrado.
 */
no * busca(tLista * ptlista, int valor) {
	no * ptr = ptlista->lista;
        
	while (ptr != NULL && ptr->valor != valor) {
            ptr = ptr->prox;
        }
	return ptr;
}

/**
 * Realiza a insercao do elemento no início da lista ligada.
 * @param valor a ser inserido.
 */
void insere_inicio(tLista * ptlista, int valor){
        no* p = new(no);
        p->valor = valor;
        p->prox = ptlista->lista;
        ptlista->lista = p;
        ptlista->tam++;
}

/**
 * Realiza a insercao do elemento no fim da lista ligada.
 * @param valor a ser inserido.
 */
void insere_fim(tLista * ptlista, int valor){
        if (ptlista->tam == 0)
            insere_inicio(ptlista, valor);
        else {
            no* p = ptlista->lista;
            while (p->prox != NULL)
                p = p->prox;
            p->prox = new(no);
            p->prox->valor = valor;
            p->prox->prox = NULL;
            ptlista->tam++;
        }
}

/**
 * Realiza a remocao do primeiro elemento da lista encadeada, se houver.
 * @return nulo em caso de lista vazia, senão retorna o nó removido.
 */
no * remove_inicio(tLista * ptlista){
	no * p;
	if(ptlista->tam == 0)
            return NULL;
        p = ptlista->lista;
        ptlista->lista = p->prox;
        p->prox = NULL;
        ptlista->tam--;
	return p;
}

/**
 * Realiza a remocao do último elemento da lista encadeada, se houver.
 * @return nulo em caso de lista vazia, senão retorna o nó removido.
 */
no * remove_fim(tLista * ptlista){
	no * p, * ant;

	if(ptlista->tam == 0)
            return NULL;

        p = ptlista->lista;
        while (p->prox != NULL){
            ant = p;
            p = p->prox;
        }
        if (p == ptlista->lista)
            ptlista->lista = NULL;
        else
            ant->prox = NULL;
        //p->prox = NULL;
        ptlista->tam--;
	return p;
}

/**
 * Imprime a lista encadeada.
 */
void imprime(tLista * ptlista){
	no * ptr = ptlista->lista;
        cout << "---Estado atual da lista:";
	while(ptr != NULL){
            cout << "-> ("<<ptr->valor<<") ";
            ptr = ptr->prox;
	}
        cout << endl;
}

