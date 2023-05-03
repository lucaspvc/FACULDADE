#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

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

typedef struct no {
  Tveiculo *veiculo;
  struct no *prox;
} No;

Tveiculo * new_carro() {
  Tveiculo *newcarro = new (Tveiculo);
  
  
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

  cout << "Veículo inserido." << endl;

  return newcarro;
}

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

No *insere_veiculo(No **lista) {
  No *novo = new (No);
  novo->veiculo = new_carro();
  novo->prox = *lista;
  *lista = novo;
  return novo;
}


No *busca_veiculo(No *lista, string placa) {

  if (lista) {
    while (lista->prox != NULL) {
      if (lista->veiculo->placa == placa) {
      }
      lista = lista->prox;
    }
  }
  return lista;
}


No *remove_veiculo(No **lista, string placa) {
  No *aux = *lista;
  No *remover;

  if ((*lista)->veiculo->placa == placa) {
    remover = *lista;
    *lista = remover->prox;
  } else {
    aux = *lista;
    while (aux->prox != NULL && aux->veiculo->placa != placa) {
      aux = aux->prox;
    }

    if (aux->prox) {
      remover = aux->prox;
      aux->prox = remover->prox;
    }
  }
  return remover;
}


void insere_do_txt(No **lista, Tveiculo *novoveiculo) {
  No *novo = new (No);
  novo->veiculo = novoveiculo;
  novo->prox = *lista;
  *lista = novo;
}

int main() {
  No *lista = NULL;
  No *aux;

  int newop = 0;
  string placa;
  char resposta;
  No *buscado;
  No *removido;
  ifstream myfile("BD_veiculos_2.txt");

  if (myfile.is_open()) {
    while (!myfile.eof()) {
      Tveiculo *novoveiculo = new (Tveiculo);
      myfile >> novoveiculo->modelo;
      myfile >> novoveiculo->marca;
      myfile >> novoveiculo->tipo;
      myfile >> novoveiculo->ano;
      myfile >> novoveiculo->km;
      myfile >> novoveiculo->potencia;
      myfile >> novoveiculo->combustivel;
      myfile >> novoveiculo->cambio;
      myfile >> novoveiculo->direcao;
      myfile >> novoveiculo->cor;
      myfile >> novoveiculo->portas;
      myfile >> novoveiculo->placa;
      myfile >> novoveiculo->valor;
      insere_do_txt(&lista, novoveiculo);
    }
    myfile.close();
  }

  while (newop != 6) {
    cout << "[1] Incluir novo veículo." << endl;
    cout << "[2] Busca por placa e remoção." << endl;
    cout << "[3] " << endl;
    cout << "[4] Ordenação por placa." << endl;
    cout << "[5] " << endl;
    cout << "[6] Sair do programa." << endl;
    cout << "Insira a opção desejada:" << endl;
    aux = lista;
    cin >> newop;
    switch (newop) {
    case 1:

      insere_veiculo(&lista);

      break;

    case 2:

      cout << "\nInsira a placa:" << endl;
      cin >> placa;
      buscado = busca_veiculo(lista, placa);

      cout << buscado->veiculo->modelo << " " << buscado->veiculo->placa;

      if (buscado != NULL) {
        cout << "Deseja remover esse veiculo?\n";
        while (resposta != 's' | resposta != 'S' | resposta != 'n' |
               resposta != 'N') {
          cout << "\n\t\tOpção inválida.\n\n";
          cin >> resposta;
        }

        if (resposta == 's' | resposta == 'S' | resposta == 'n' |
            resposta == 'N') {
          removido = remove_veiculo(&lista, placa);
          cout << "Veiculo removido: ";
          cout << removido->veiculo->modelo << " " << buscado->veiculo->placa
               << "\n";
        } else {
          cout << "Não existe carro com esta placa.\n";
        }

        break;

      case 3:

        break;

      case 4:
        cout << "\nOrdenação por placa.\n";
        break;

      case 5:
        aux = lista;
        while (aux) {
          cout << aux->veiculo->modelo << endl;
          aux = aux->prox;
        }

        break;

      case 6:

        printarq(lista);
        cout << "Programa finalizado." << endl;

        return 0;

        break;

      default:
        cout << "\n\t\tOpção inválida.\n\n";
      }
    }
  }
}