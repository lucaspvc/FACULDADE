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
  float prestacao, potencia, valor, valormaiscaro, valormaisbarato, 
      hatch, suv, pickup, sedan, passeio, van, var, kmtotal, qtd2018, total;
  int ano, km, portas;

  ifstream arquivo("BD_veiculos.txt");
  if (!arquivo.is_open()) {
    cout << vermelho_G "\nErro: Arquivo não encontrado." reset << endl;
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

  cout << azul_N "-------------------------------------------------------------------------------------" reset << endl;
  cout << "Porcentagem dos " magenta_S "tipos" reset " de veículos" << endl;
  cout << "Hatch: " << verde_N << (hatch / total) * 100 << "%" << reset << endl;
  cout << "Sedã: " << verde_N << (sedan / total) * 100 << "%" << reset << endl;
  cout << "Passeio: " << verde_N << (passeio / total) * 100 << "%" << reset << endl;
  cout << "Pick-up: " << verde_N << (pickup / total) * 100 << "%" << reset << endl;
  cout << "SUV: " << verde_N << (suv / total) * 100 << "%" << reset << endl;
  cout << "Van: " << verde_N << (van / total) * 100 << "%" << reset << endl;
  cout << "De um total de " << magenta_S << (int)total << reset << " veículos" << endl;
  cout << azul_N "-------------------------------------------------------------------------------------" reset << endl;


  cout << "Porcentagem de veículos com câmbio " magenta_S "automático" reset " e direção " magenta_S "hidráulica" reset << endl;
  cout << verde_N << (var / total) * 100 << "%" << reset << endl;
  cout << "De um total de " << magenta_S << (int)total << reset << " veículos" << endl;
  cout << azul_N "-------------------------------------------------------------------------------------" reset << endl;
  

cout << "Informações do veículo mais barato, com " magenta_S "1.0" reset " de potência de motor" << endl;
  cout << "Placa: " << verde_N << placamaisbarato << reset << endl;
  cout << "Valor: " verde_N "R$" << valormaisbarato << reset << endl;
  prestacao = valormaisbarato * (pow((1 + 0.0111), 48));
  cout << "Juros do financiamento à " magenta_S "[1,11 a.m.]" reset << endl;
  cout << "Valor da prestação do financiamento em 48 vezes: " verde_N "R$ "<< (prestacao / 48) << endl;
  cout << azul_N "-------------------------------------------------------------------------------------" reset << endl;

  cout << "Informações do veículo mais caro, com direção " magenta_S "hidráulica" reset 
        " e combustível " magenta_S "flex" reset << endl;
  cout << "Placa: " << verde_N << placamaiscaro  << reset << endl;
  cout << "Valor:" verde_N " R$ " << valormaiscaro << reset << endl;
  cout << "Valor estimado do seguro: " verde_N "R$ " << (0.06 * valormaiscaro) << endl;
  cout << "Taxa de " magenta_S "6%" reset " sobre o valor do veículo" << endl;
  cout << azul_N "-------------------------------------------------------------------------------------" reset << endl;

  cout << "Veículos com " magenta_S "5" reset" anos ou mais (2018)" << endl;
  cout << "Quantidade: " << verde_N <<  (int)qtd2018  << reset << endl;
  cout << "Média de quilometragem: " << verde_N << (kmtotal / qtd2018) << endl;
  cout << azul_N "-------------------------------------------------------------------------------------" reset << endl;

  arquivo.close();
  return 0;
}