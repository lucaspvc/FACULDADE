#include <cstdlib>
#include <math.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


int main(int argc, char** argv) {
    cout << fixed << setprecision(2);
    float altura,maior,somatorio, total, homens, mulheresM;
    total = homens = mulheresM = somatorio  = 0;
    string sexo;
    ifstream arquivo ("dados.txt");
    if (!arquivo.is_open()){
        cout << "\nErro: Arquivo não encontrado. \n";
        return 1;
    }
    
    arquivo >> altura;
    while(altura != 0){
        arquivo >> sexo;
        total++;
        if(altura > 1.80)
        maior++;
        if(sexo == "M"){
            somatorio = somatorio + altura;
            homens++;
            }
        if(sexo == "F" && altura < 1.70)
        mulheresM++;
        arquivo >> altura;
    }
    cout << "A porcentagem de pessoas com altura maior que 1,80 m é: " << (maior/total)*100 << "%" << endl;
    cout << "A média de altura dos homens é: "<< somatorio/homens << endl;
    cout << "A porcentagem de mulheres menores que 1,70 m entre todas as pessoas é: " << (mulheresM/total)*100 << "%" << endl;
    
    return 0;
}