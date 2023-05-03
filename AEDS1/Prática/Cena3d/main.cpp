#include <cstdlib>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;


//sqrt = raiz quadrada, pow = potência

int main(int argc, char** argv) {

    string figura;
    float area, areatotal, volume, volumetotal, raio, lado, altura;
    ifstream cena ("cena3d.txt");
    if (!cena.is_open()){
        cout << "\nErro: Arquivo não encontrado. \n";
        return 1;
    }
    
    cena >> figura;
    while(figura != "fim"){
        if(figura == "esfera"){
            cena >> raio;
            area = pow(raio,2) *4* 3.14;
            cout << "A área da esfera é: " << area << endl;
            areatotal = area + areatotal;
            volume = pow(raio,3) *(4/3)* 3.14;
            cout << "O volume do esfera é: "<< volume << endl;
            cout << "----------------------------------------------" << endl;
            volumetotal = volume + volumetotal;
        }else if(figura == "cubo"){
            cena >> lado;
            area = pow (lado, 2) *6;
            cout << "A área do cubo é: "<< area << endl;
            areatotal = area + areatotal;
            volume = pow (lado, 3);
            cout << "O volume do cubo é: "<< area << endl;
            cout << "----------------------------------------------" << endl;
            volumetotal = volume + volumetotal;
        }else{
            cena >> raio;
            cena >> altura;
            area = 2*3.14*raio*(raio+altura);
            cout << "A área do cilindro é: "<< area << endl;
            areatotal = area + areatotal;
            volume = pow(raio, 2) *3.14*altura;
            cout << "O volume do cilindro é: "<< area << endl;
            cout << "----------------------------------------------" << endl;
            volumetotal = volume + volumetotal;
        }
        cena >> figura;
    }
    cout << "O volume total da cena é: " << volumetotal<< endl;
    cout << "A área total da cena é: " << areatotal << endl;
    
    
    return 0;
}

