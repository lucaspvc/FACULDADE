#include <bits/stdc++.h>

using namespace std;

// # modelo marca tipo ano km potência_do_motor combustível câmbio direção cor portas placa valor

int main(int argc, char const *argv[]){
    string modelo, marca, tipo, combustivel, cambio, direcao, cor, placa, modelomaisbarato, placamaiscaro;
    float potencia, valor, valormaiscaro, valormaisbarato;
    int ano, km, portas, hatch, suv, pickup, sedan, passeio, van, var, kmtotal, qtd2018, total;
    ifstream arquivo ("BD_veiculos.txt");
    if (!arquivo.is_open()){
        cout << "\nErro: Arquivo não encontrado.\n";
        return 1;
    }

    arquivo >> modelo;
    while(modelo != "FIM"){
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
        if(tipo == "Hatch"){
            hatch++;
        } else if(tipo == "SUV"){
            suv++;
        } else if(tipo == "Pick-up"){
            pickup++;
        } else if(tipo == "Sedã" || tipo == "Sedan"){
            sedan++;
        } else if(tipo == "Passeio"){
            passeio++;
        } else{
            van++;
        }

        //porcentagem de veículos com câmbio automático e com direção hidráulica entre todos os veículos;
        if(cambio == "Automático" && direcao == "Hidráulica"){
            var++;
        }

        //placa e valor do veículo mais barato entre os veículos com potência do motor 1.0, e ainda, valor 
        //da prestação do financiamento em 48 meses com taxa de juros atuais (consulte na internet);
        //a fazer: financiamento
        if(potencia == 1.0){
            if(valor < valormaisbarato){
                valormaisbarato =  valor;
                modelomaisbarato = modelo;
            }
        }

        //placa e valor do veículo mais caro com direção hidráulica e combustível flex, e ainda, valor
        //do seguro estimado (porcentagem estimada sobre o valor do veículo);
        //a fazer: seguro
        if(direcao == "Hidráulica" && combustivel == "Flex"){
            if(valor > valormaiscaro){
                valormaiscaro = valor;
                placamaiscaro = placa;
            }
        }

        //quantidade e média de kilometragem dos veículos com 5 anos ou mais (2018).
        if(ano <= 2018){
            kmtotal = kmtotal + km;
            qtd2018++;
        }

       arquivo >> modelo;
    }
    arquivo.close();
    return 0;
}
