#include <bits/stdc++.h>
#include <math.h>

#include "cores.h"

using namespace std;

// # modelo marca tipo ano km potência_do_motor combustível câmbio direção cor
// portas placa valor

int main(int argc, char const *argv[]) {

  cout << fixed << setprecision(2);
  string modelo, marca, tipo, combustivel, cambio, direcao, cor, placa,
      placamaisbarato, placamaiscaro;
  float prestacao, potencia, juros, valor, valormaiscaro, valormaisbarato,
      hatch, suv, pickup, sedan, passeio, van, var, kmtotal, qtd2018, total;
  int i, ano, km, portas;

  ifstream arquivo("BD_veiculos.txt");
  if (!arquivo.is_open()) {
    cout << "\nErro: Arquivo não encontrado.\n";
    return 1;
  }

  prestacao = 0;
  hatch = 0;
  valormaiscaro = 0;
  suv = 0;
  pickup = 0;
  prestacao = 0;
  sedan = 0;
  passeio = 0;
  van = 0;
  var = 0;
  kmtotal = 0;
  qtd2018 = 0;
  total = 0;
  i = 0;

  valormaisbarato = MAXFLOAT;
  arquivo >> modelo;
  while (modelo != "FIM") {
    arquivo >> marca;
    arquivo >> tipo;
    arquivo >> ano;
    arquivo >> km;
    arquivo >> potencia;
    arquivo >> combustivel;
    arquivo >> cambio;
    arquivo >> direcao;
    arquivo >> cor;
    arquivo >> portas;
    arquivo >> placa;
    arquivo >> valor;
    total++;

    // porcentagens de veículos nas categorias de tipo;
    if (tipo == "Hatch") {
      hatch++;
    } else if (tipo == "SUV") {
      suv++;
    } else if (tipo == "Pick-up") {
      pickup++;
    } else if (tipo == "Sedã" || tipo == "Sedan") {
      sedan++;
    } else if (tipo == "Passeio") {
      passeio++;
    } else {
      van++;
    }

    // porcentagem de veículos com câmbio automático e com direção hidráulica
    // entre todos os veículos;
    if (cambio == "Automático" && direcao == "Hidráulica") {
      var++;
    }

    // placa e valor do veículo mais barato entre os veículos com potência do
    // motor 1.0, e ainda, valor da prestação do financiamento em 48 meses com
    // taxa de juros atuais (consulte na internet); a fazer: financiamento BCO
    // DA AMAZONIA S.A. 1,11 a.m. 14,14 a.a.
    if (potencia == 1.0) {
      if (valor < valormaisbarato) {
        valormaisbarato = valor;
        placamaisbarato = placa;
      }
    }

    // placa e valor do veículo mais caro com direção hidráulica e combustível
    // flex, e ainda, valor do seguro estimado (porcentagem estimada sobre o
    // valor do veículo); a fazer: seguro
    if (direcao == "Hidráulica" && combustivel == "Flex") {
      if (valor > valormaiscaro) {
        valormaiscaro = valor;
        placamaiscaro = placa;
      }
    }

    // quantidade e média de kilometragem dos veículos com 5 anos ou mais
    // (2018).
    if (ano <= 2018) {
      kmtotal = kmtotal + km;
      qtd2018++;
    }

    arquivo >> modelo;
  }

  cout << "--------------------------------------------------------------------"
          "-----------------"
       << endl;
  cout << "Porcentagem dos tipos de veículos" << endl;
  cout << "Hatch: " << (hatch / total) * 100 << "%" << endl;
  cout << "Sedã: " << (sedan / total) * 100 << "%" << endl;
  cout << "Passeio: " << (passeio / total) * 100 << "%" << endl;
  cout << "Pick-up: " << (pickup / total) * 100 << "%" << endl;
  cout << "SUV: " << (suv / total) * 100 << "%" << endl;
  cout << "Van: " << (van / total) * 100 << "%" << endl;
  cout << "De um total de " << (int)total << " veículos" << endl;
  cout << "--------------------------------------------------------------------"
          "-----------------"
       << endl;

  cout << "Porcentagem de veículos com câmbio automático e com direção "
          "hidráulica"
       << endl;
  cout << (var / total) * 100 << "%" << endl;
  cout << "De um total de " << (int)total << " veículos" << endl;
  cout << "--------------------------------------------------------------------"
          "-----------------"
       << endl;

  cout << "Informações do veículo mais barato" << endl;
  cout << "Placa: " << placamaisbarato << endl;
  cout << "Valor: R$" << valormaisbarato << endl;
  prestacao = valormaisbarato * (pow((1 + 0.0111), 48));
  cout << "Juros do financiamento à [1,11 a.m.]" << endl;
  cout << "Valor da prestação do financiamento em 48 vezes: R$"
       << (prestacao / 48) << endl;
  cout << "--------------------------------------------------------------------"
          "-----------------"
       << endl;

  cout << "Informações do veículo mais caro" << endl;
  cout << "Placa: " << placamaiscaro << endl;
  cout << "Valor: R$" << valormaiscaro <<  endl;
  cout << "Taxa de 6% sobre o valor do veículo" << endl;
  cout << "Valor estimado do seguro: R$" << (0.06 * valormaiscaro) << endl;
  cout << "--------------------------------------------------------------------"
          "-----------------"
       << endl;

  cout << "Veículos com 5 anos ou mais (2018)" << endl;
  cout << "Quantidade: " << (int)qtd2018 << endl;
  cout << "Média de quilometragem: " << (kmtotal / qtd2018) << endl;
  cout << "--------------------------------------------------------------------"
          "-----------------"
       << endl;

  arquivo.close();
  return 0;
}
