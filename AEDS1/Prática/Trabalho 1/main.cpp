/* Universidade Federal de Alfenas (UNIFAL) - 2023
 * Discentes: Lucas Pessoa Oliveira Alves 2022.1.08.044
 *
 * Docente: Paulo Alexandre Bressan - Algoritimo e Estrutura de Dados I
 * 
 * Trabalho com o objetivo de adquirir conhecimentos de manipulação de valores em variáveis simples 
 * com estruturas de controle construindo estatísticas a partir de dados lidos de um arquivo-texto.
 * 
 */

#include <bits/stdc++.h> //incluindo as bibliotecas bases para c++
#include <math.h> //incluindo a biblioteca com fórmulas matemáticas

#include "cores.h" //incluindo uma biblioteca local utilizada para modificar cor do texto de saída

using namespace std;


int main(int argc, char const *argv[]) {

  cout << fixed << setprecision(2); //fixando 2 casas decimais para todo o arquivo

  //declaração das variáveis
  string modelo, marca, tipo, combustivel, cambio, direcao, cor, placa,
      placamaisbarato, placamaiscaro;
  float valortotal, potencia, valor, valormaiscaro, valormaisbarato;
  int ano, km, portas, hatch, suv, pickup, sedan, passeio, van, var, kmtotal, total, qtd2018;

  //abertura do arquivo txt
  ifstream arquivo("BD_veiculos.txt");
  if (!arquivo.is_open()) {
    cout << vermelho_G "\nErro: Arquivo não encontrado." reset << endl;
    return 1;
  }

  //atribuindo valores iniciais para as variáveis
  hatch = 0;
  valormaiscaro = 0;
  suv = 0;
  pickup = 0;
  valortotal = 0;
  sedan = 0;
  passeio = 0;
  van = 0;
  var = 0;
  kmtotal = 0;
  qtd2018 = 0;
  total = 0;
  valormaisbarato = MAXFLOAT; //atribuindo o valorfloat máximo possível para float

  
  arquivo >> modelo; //leitura da primeira variável do txt

  //iniciando uma repetição cujo a parada é ao encontrar a palavra FIM txt 
  while (modelo != "FIM") {
    //leitura do resto da linha do txt
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
    total++; // incrementação da variável contadora do total de veículos

    //contadores para as porcentagens de veículos nas categorias de tipo;
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

    // contador para porcentagem de veículos com câmbio automático 
    // e com direção hidráulica entre todos os veículos;
    if (cambio == "Automático" && direcao == "Hidráulica") {
      var++;
    }

    // placa e valor do veículo mais barato entre os veículos com potência do
     // motor 1.0, e ainda, valor da prestação do financiamento em 48 meses com
    // taxa de juros atuais (consulte na internet); taxa de financiamento do BCO DA AMAZONIA S.A. 1,11 a.m.
    if (potencia == 1.0) {
      if (valor < valormaisbarato) {
        valormaisbarato = valor;
        placamaisbarato = placa;
      }
    }

    // placa e valor do veículo mais caro com direção hidráulica e combustível
    // flex, e ainda, valor do seguro estimado (porcentagem estimada sobre o
    // valor do veículo);
    // taxa do seguro: 6% sobre o valor do veículo
    if (direcao == "Hidráulica" && combustivel == "Flex") {
      if (valor > valormaiscaro) {
        valormaiscaro = valor;
        placamaiscaro = placa;
      }
    }

    // quantidade e média de kilometragem dos veículos com 5 anos ou mais (2018).
    if (ano <= 2018) {
      kmtotal = kmtotal + km;
      qtd2018++;
    }

    arquivo >> modelo; //leitura da primeira variável da linha seguinte do txt
  }

  cout << azul_N "-------------------------------------------------------------------------------------" reset << endl;
  cout << "Porcentagem dos " magenta_S "tipos" reset " de veículos" << endl;
  // calculo das porcentagens dos tipos
  cout << "Hatch: " << verde_N << (hatch / (float)total) * 100 << "%" << reset << endl;
  cout << "Sedã: " << verde_N << (sedan / (float)total) * 100 << "%" << reset << endl;
  cout << "Passeio: " << verde_N << (passeio / (float)total) * 100 << "%" << reset << endl;
  cout << "Pick-up: " << verde_N << (pickup / (float)total) * 100 << "%" << reset << endl;
  cout << "SUV: " << verde_N << (suv / (float)total) * 100 << "%" << reset << endl;
  cout << "Van: " << verde_N << (van / (float)total) * 100 << "%" << reset << endl;
  cout << "De um total de " << magenta_S << total << reset << " veículos" << endl;
  cout << azul_N "-------------------------------------------------------------------------------------" reset << endl;


  cout << "Porcentagem de veículos com câmbio " magenta_S "automático" reset " e direção " magenta_S "hidráulica" reset << endl;
  cout << verde_N << (var / (float)total) * 100 << "%" << reset << endl; // calculo da porcentagem 
  cout << "De um total de " << magenta_S << total << reset << " veículos" << endl;
  cout << azul_N "-------------------------------------------------------------------------------------" reset << endl;
  

  cout << "Informações do veículo mais barato, com " magenta_S "1.0" reset " de potência de motor" << endl;
  cout << "Placa: " << verde_N << placamaisbarato << reset << endl;
  cout << "Valor: " verde_N "R$" << valormaisbarato << reset << endl;
  valortotal = valormaisbarato * (pow((1 + 0.0111), 48)); // calculo do valor total do financiamento
  cout << "Juros do financiamento à " magenta_S "[1,11 a.m.]" reset << endl;
  cout << "Valor da prestação do financiamento em 48 vezes: " verde_N "R$ "<< (valortotal / 48) << endl; // calculo da prestação
  cout << azul_N "-------------------------------------------------------------------------------------" reset << endl;

  cout << "Informações do veículo mais caro, com direção " magenta_S "hidráulica" reset 
        " e combustível " magenta_S "flex" reset << endl;
  cout << "Placa: " << verde_N << placamaiscaro  << reset << endl;
  cout << "Valor:" verde_N " R$ " << valormaiscaro << reset << endl;
  cout << "Valor estimado do seguro: " verde_N "R$ " << (0.06 * valormaiscaro) << reset << endl; // calculo do seguro
  cout << "Taxa de " magenta_S "6%" reset " sobre o valor do veículo" << endl;
  cout << azul_N "-------------------------------------------------------------------------------------" reset << endl;

  cout << "Veículos com " magenta_S "5" reset" anos ou mais (2018)" << endl;
  cout << "Quantidade: " << verde_N <<  qtd2018  << reset << endl;
  cout << "Média de quilometragem: " << verde_N << (kmtotal / (float)qtd2018) << endl; //calculo da média de km
  cout << azul_N "-------------------------------------------------------------------------------------" reset << endl;

  arquivo.close(); //fechamento do arquivo
  return 0;
}