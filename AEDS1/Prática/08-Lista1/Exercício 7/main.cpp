#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
    int segundos, seg, min, horas;
    float massaI, massaF, massa;
    seg = min = horas = massaI = massaF =0;
    cout << "Insira a massa para o cálculo da perda de sua massa:";
    cin >> massa;
    massaI = massa;
    while (massa >= 0.5){
        massa = (massa/2);
        segundos = segundos + 50;
    }
    cout << segundos << endl;
    massaF = massa;
    seg = segundos%60;
    min = (segundos/60)%60;
    horas = segundos/3600;

    cout << "A massa inicial é: " << massaI << " g" << endl;
    cout << "A massa final é: " << massaF << " g" << endl;
    cout << "O tempo até que a massa seja menor que 0,5 g é: " << horas << " horas " << min << " minutos " << seg <<  " segundos "<< endl;


    
    return 0;
}
