/*
 * File:   main.cpp
 * Author: Gustavo Fernandez Pascoaleto 2021.1.08.009
 * Letícia Freitas de Oliveira 2018.1.08.051
 * Lucas Pessoa Oliveira Alves 2022.1.08.044
 *
 *
 * Created on 30 de novembro de 2022, 21:10
 */

#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/*
 * Declarãço da struct Tveículo,
 * onde é criado todos os campos existente
 * para cada carro do BD.
 */
typedef struct {
    string modelo;
    string marca;
    string tipo;
    int ano;
    int km;
    float potencia;
    string combustivel;
    string cambio;
    string direcao;
    string cor;
    int portas;
    string placa;
    float valor;
} Tveiculo;

/*
 * Declaração da struct No, com os campos "veiculo",
 * apontando para o a struct Tveiculo com as características do carro
 * e o "prox" que aponta para o próximo nó da lista ligada.
 */
typedef struct no {
    Tveiculo *veiculo;
    struct no *prox;
} No;

/**
 * Função para a escrita das características do veículo a ser inserido.
 * @param placa, critéria de existência do carro.
 * @return newcarro, o carro inserido.
 */
Tveiculo *new_carro(string placa) {
    Tveiculo *newcarro = new (Tveiculo);

    newcarro->placa = placa;

    cout << "Digite o modelo do veículo. Ex: KA\n";
    cin >> newcarro->modelo;

    cout << "Digite a marca do veículo. Ex: FORD.\n";
    cin >> newcarro->marca;

    cout << "Digite o tipo do veículo. Ex: SUV.\n";
    cin >> newcarro->tipo;

    cout << "Digite o ano do veículo. Ex: 2000.\n";
    cin >> newcarro->ano;

    cout << "Digite a quilometragem do veículo. Ex: 32000.\n";
    cin >> newcarro->km;

    cout << "Digite a potência do veículo. Ex: 1.6\n";
    cin >> newcarro->potencia;

    cout << "Digite o tipo de combustível do veículo. Ex: Flex.\n";
    cin >> newcarro->combustivel;

    cout << "Digite o tipo de câmbio do veículo. Ex: Manual.\n";
    cin >> newcarro->cambio;

    cout << "Digite o tipo de direção do veículo. Ex: Hidráulica.\n";
    cin >> newcarro->direcao;

    cout << "Digite a cor do veículo. Ex: Preto.\n";
    cin >> newcarro->cor;

    cout << "Digite quantas portas há no veículo. Ex: 4\n";
    cin >> newcarro->portas;

    cout << "Digite o valor do veículo. Ex: 00000.00\n";
    cin >> newcarro->valor;

    cout << "  Veículo inserido.\n" << endl;

    return newcarro;
}

/**
 * Função para a busca da placa a ser inserida na lista, sendo esse o critério
 * de existência do arquivo.
 * @param lista, a lista ligada utilizada com todos os carros
 * @param placa, critério de existência do carro no BD.
 * @return o carro removido.
 */
No *buscar(No *lista, string placa) {
    No *removido = NULL;
    while (lista && lista->veiculo->placa != placa) {
        lista = lista->prox;
    }
    removido = lista;
    return removido;
}

/**
 * Função para a inserção do veículo na lista ligada.
 * @param lista, lista ligada dos carros.
 * @param placa, placa do carro a ser inserido, sendo também o critério de
 * existência.
 * @return nó do carro que foi inserido.
 */
No *insere_veiculo(No **lista, string placa) {

    No *novo = new (No);
    novo->veiculo = new_carro(placa);
    novo->prox = *lista;
    *lista = novo;
    return novo;
}

/**
 * Função da remoção de um veículo da lista.
 * @param lista, lista ligada dos carros.
 * @param placa, placa do carro a ser removido.
 * @return nó do carro removido.
 */
No *remove_veiculo(No **lista, string placa) {

    No *aux = *lista;
    No *remover = NULL;

    if ((*lista)->veiculo->placa == placa) {
        remover = *lista;
        *lista = remover->prox;
    } else {
        aux = *lista;
        while (aux->prox != NULL && aux->prox->veiculo->placa != placa) {
            aux = aux->prox;
        }

        if (aux->prox) {
            remover = aux->prox;
            aux->prox = remover->prox;
        }
    }
    return remover;
}

/**
 * Função para escrever a lista ligada no arquivo TXT.
 * @param lista, lista ligada dos carros
 */
void printarq(No *lista) {

    ofstream out;
    out.open("BD_veiculos_2.txt");
    while (lista != NULL) {
        out << lista->veiculo->modelo << " " << lista->veiculo->marca << " "
                << lista->veiculo->tipo << " " << lista->veiculo->ano << " "
                << lista->veiculo->km << " " << lista->veiculo->potencia << " "
                << lista->veiculo->combustivel << " " << lista->veiculo->cambio << " "
                << lista->veiculo->direcao << " " << lista->veiculo->cor << " "
                << lista->veiculo->portas << " " << lista->veiculo->placa << " "
                << lista->veiculo->valor << " " << endl;
        lista = lista->prox;
    }
}

/**
 * Função para inserção de um novo veículo a partir da leitura do BD, arquivo
 * TXT.
 * @param lista, lista ligada dos carros.
 * @param novo, novo nó a ser alocado na lista ligada.
 */
void inseredotxt(No **lista, No *novo) {
    No *aux = *lista;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

/**
 * Função para a ordenação da lista de acordo com a placa.
 * @param lista, lista ligada dos carros.
 * @param ordenado, nó para ajudar na ordenação.
 */
void ordenacao(No *lista, No **ordenado) {
    no *aux;
    *ordenado = NULL;

    while (lista) {
        No *novo = new (No);
        novo->veiculo = lista->veiculo;

        if (*ordenado == NULL) {
            novo->prox = NULL;
            *ordenado = novo;
        } else if (novo->veiculo->placa < (*ordenado)->veiculo->placa) {
            novo->prox = *ordenado;
            *ordenado = novo;
        } else {
            aux = *ordenado;
            while (aux->prox != NULL &&
                    novo->veiculo->placa > aux->prox->veiculo->placa) {
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
        }
        lista = lista->prox;
    }
    aux = *ordenado;
    while (aux) {
        cout << aux->veiculo->modelo << " ";
        cout << aux->veiculo->placa << endl;
        aux = aux->prox;
    }
}

/*
 * Função para empilhar(inserir na pilha) os carros.
 * @param pilha, a pilha de carros que já foram empilhados.
 * @param aux, nó para o carro a ser inserido.
 * @return novo, o nó do veículo que foi empilhado (inserido na pilha).
 */
No *empilhar(No *pilha, No *aux) {
    No *novo = new (No);
    novo->prox = pilha;
    novo->veiculo = aux->veiculo;
    return novo;
}

/*
 * Função para desempiplhar(retirar da pilha) o carro.
 * @param pilha, pilha dos carros.
 */
void desempilha(No **pilha) {
    if (*pilha != NULL) {
        No *remover = *pilha;
        *pilha = remover->prox;
    }
}

/*
 * Função para inserir no fim da fila.
 * @param fila, a fila ligada.
 * @param aux, nó a ser inserido na fila.
 */
void insereFim(No ** fila, No * aux) {
    No *auxfila;
    No * novo = new (No);
    novo->prox = NULL;
    novo ->veiculo = aux->veiculo;

    if (*fila == NULL) {
        *fila = novo;
    } else {
        auxfila = *fila;
        while (auxfila->prox != NULL) {
            auxfila = auxfila->prox;
        }
        auxfila->prox = novo;
    }

}

/**
 * Função para remover o carro do inicio.
 * @param fila, a fila ligada.
 * @return nó do carro removido.
 */
No *removeInicio(No ** fila) {
    No * remover = NULL;

    if (*fila) {
        remover = *fila;
        *fila = remover->prox;
    }
    return remover;
}

int main() {
    /*
     * Declaração de variáveis utilizadas.
     */
    No *fila = NULL;
    No *pilha = NULL;
    No *lista = NULL;
    No *ordenado = NULL;


    No *aux;
    int newop = 0;
    string placa;
    char resposta;
    No *buscado;
    No *removido;

    /*
     * Abertura e leitura do arquivo TXT para a lista ligada.
     */
    ifstream myfile("BD_veiculos_2.txt");

    if (myfile.is_open()) {
        do {
            No *novoNo = new (No);
            inseredotxt(&lista, novoNo);

            Tveiculo *newveiculo = new (Tveiculo);
            myfile >> newveiculo->modelo;
            myfile >> newveiculo->marca;
            myfile >> newveiculo->tipo;
            myfile >> newveiculo->ano;
            myfile >> newveiculo->km;
            myfile >> newveiculo->potencia;
            myfile >> newveiculo->combustivel;
            myfile >> newveiculo->cambio;
            myfile >> newveiculo->direcao;
            myfile >> newveiculo->cor;
            myfile >> newveiculo->portas;
            myfile >> newveiculo->placa;
            myfile >> newveiculo->valor;
            novoNo->veiculo = newveiculo;

        } while (!myfile.eof());

        myfile.close();
    } else
        cout << "\n\n\n ARQUIVO NÃO ENCONTRADO. \n\n\n" << endl;
    aux = lista;

    /*
     * Escrita do menu na tela.
     */
    while (newop != 7) {
        cout << "[1] Incluir novo veículo." << endl;
        cout << "[2] Busca por placa e remoção." << endl;
        cout << "[3] Construir fila." << endl;
        cout << "[4] Ordenação por placa." << endl;
        cout << "[5] Construir pilha." << endl;
        cout << "[6] Relatório." << endl;
        cout << "[7] Sair do programa." << endl;
        cout << "Insira a opção desejada:" << endl;
        aux = lista;

        cin >> newop;

        /*
         * switch case para as opções do menu.
         */
        switch (newop) {
            case 1:
                cout << "Digite a placa do veículo. Ex: HJA9065" << endl;
                cin >> placa;

                buscado = buscar(lista, placa);
                if (buscado) {
                    cout << "Carro já existente\n" << endl;
                } else {
                    insere_veiculo(&lista, placa);
                }
                break;

            case 2:
                cout << "Insira a placa:" << endl;
                cin >> placa;
                buscado = buscar(lista, placa);

                if (buscado) {
                    cout << "Veículo encontrado." << endl;
                    cout << "Deseja remover o veículo? [S]=sim ou [N]=não" << endl;
                    cin >> resposta;
                    if (resposta == 'S' || resposta == 's') {
                        removido = remove_veiculo(&lista, placa);
                        cout << "Veículo removido\n" << endl;
                    } else {
                        cout << "Veículo não removido do BD." << endl;
                    }
                } else {
                    cout << "Veículo não existente no BD." << endl;
                }
                break;

            case 3:
                cout << "Construção da fila.\n" << endl;
                while (aux) {
                    if (aux->veiculo->cambio == "Automático") {
                        insereFim(& fila, aux);

                    } else {
                        removido = removeInicio(&fila);
                    }
                    aux = aux->prox;
                }
                cout << "Final da fila" << endl;
                while (fila) {
                    cout << fila->veiculo->modelo << " " << fila->veiculo->placa;
                    cout << "\n";
                    fila = fila->prox;
                }
                cout << "Início da fila" << endl;
                cout << "\n";
                break;

            case 4:

                cout << "Ordenação por placa.\n";
                ordenacao(lista, &ordenado);
                cout << "\n";
                break;

            case 5:
                cout << "Construção da pilha.\n";
                while (aux) {
                    if (aux->veiculo->direcao == "Hidráulica") {
                        pilha = empilhar(pilha, aux);
                    } else {
                        desempilha(&pilha);
                    }
                    aux = aux->prox;
                }
                cout << "Topo da pilha" << endl;
                while (pilha) {
                    cout << pilha->veiculo->modelo << " " << pilha->veiculo->placa;
                    cout << "\n";
                    pilha = pilha->prox;
                }
                cout << "Base da pilha" << endl;
                cout << "\n";
                break;


            case 6:
                aux = lista;
                while (aux) {
                    cout << aux->veiculo->modelo << " " << aux->veiculo->marca << " "
                            << aux->veiculo->tipo << " " << aux->veiculo->ano << " "
                            << aux->veiculo->km << " " << aux->veiculo->potencia << " "
                            << aux->veiculo->combustivel << " " << aux->veiculo->cambio << " "
                            << aux->veiculo->direcao << " " << aux->veiculo->cor << " "
                            << aux->veiculo->portas << " " << aux->veiculo->placa << " "
                            << aux->veiculo->valor << " " << endl;
                    aux = aux->prox;
                }
                break;

            case 7:
                cout << "Programa finalizado." << endl;
                printarq(lista);
                while (lista) {
                    No * deletando = lista;
                    lista = lista->prox;
                    free(deletando);
                }
                while (fila) {
                    No * deletando = fila;
                    fila = fila->prox;
                    free(deletando);
                }
                while (pilha) {
                    No * deletando = pilha;
                    pilha = pilha->prox;
                    free(deletando);
                }
                return 0;
                break;

            default:
                cout << "\n\t\tOpção inválida.\n\n";
        }
    }
}
