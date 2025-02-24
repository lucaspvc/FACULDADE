#include <cstdlib>
#include <math.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[]){
    string tipo;
    char rh;
    int pessoas, contTipo;
    pessoas = contTipo = 0;
    float idade, pmax, pmin;
    cout << "Insira o tipo saguíneo da pessoa: " << endl;
    cin >> tipo;
    while (tipo != "x" || tipo != "X"){
        while (tipo != "O" && tipo != "A" && tipo != "B" && tipo != "AB") {
           cout << "Tipo sanguíneo inválido" << endl;
           cout << "Insira um tipo válido: ([O], [A], [B], [AB])" << endl;
          cin >> tipo;
        }

        cout << "Insira RH da pessoa: " << endl;
        cin >> rh;
        while (rh != '+' && rh != '-') {
            cout << "RH inválido" << endl;
            cout << "Insira um RH válido: ( [+], [-] )" << endl;
            cin >> rh;
        }

        cout << "Insira a pressão arterial máxima da pessoa: " << endl;
        cin >> pmax;
        while (pmax < 7 || pmax > 25) {
            cout << "Pressão arterial máxima inválido" << endl;
            cout << "Insira uma pressão arterial máxima válida: (entre 7 e 25)" << endl;
            cin >> pmax;
        }

        cout << "Insira a pressão arterial mínima da pessoa: " << endl;
        cin >> pmin;
        while (pmin < 2 || pmin > 20) {
            cout << "Pressão arterial miníma inválida" << endl;
            cout << "Insira uma pressão miníma máxima válida: (entre 2 e 20)" << endl;
            cin >> pmin;
        }

        cout << "Insira a idade da pessoa: " << endl;
        cin >> idade;
        while (idade < 18 || idade > 130) {
            cout << "Idade inválida" << endl;
            cout << "Insira uma idade válida: (entre 18 e 130 anos)" << endl;
            cin >> idade;
        }
        if(pmax > 14 || pmin > 10){
            pessoas++;
            if((tipo == 'A' || tipo == 'B') && rh = '-'){
                contTipo++;
            }
        }
        cout << "Insira o tipo saguíneo da pessoa: " << endl;
        cin >> tipo;
    }
    cout << "A porcentagem de pessoas com sangue A- ou B-" << (contTipo/pessoas)*100 << endl;

    return 0;
}