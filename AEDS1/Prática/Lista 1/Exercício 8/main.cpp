#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
    float nascida, mortes, mortesMasc, mortes24, meses;
    string sexo;

    ifstream arquivo ("crianças.txt");
    if (!arquivo.is_open()){
        cout << "\nErro: Arquivo não encontrado.\n";
        return 1;
    }
    cout << "Insira a quantidade de crianças nascidas durante o período: ";
    cin >> nascida;

    arquivo >> sexo;
    while (sexo != "sair"){
        arquivo >> meses;
        mortes++;
        if(sexo == "m" || sexo == "M" || sexo == "masculino" || sexo == "Masculino" || sexo == "MASCULINO"){
            mortesMasc++;
        }
        if (meses <= 24){
            mortes24++;
        }
        arquivo >> sexo;
    }
    cout << "A porcentagem de crianças mortas no período é: " << ((mortes/nascida)*100) << "%" << endl;
    cout << "A porcentagem de crianças do sexo masculino mortas no período é: " << ((mortesMasc/nascida)*100) << "%" << endl;
    cout << "A porcentagem de crianças que viveram 24 meses ou menos no período é: " << ((mortes24/nascida)*100) << "%" << endl;


    return 0;
}
