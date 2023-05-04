#include <cstdlib>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;


//sqrt = raiz quadrada, pow = potência

int main(int argc, char** argv) {

    float d, total, dx1, dx2, dy1, dy2;
    ifstream distancia ("coordenadas.txt");
    if (!distancia.is_open()){
        cout << "\nErro: Arquivo não encontrado. \n";
        return 1;
    }
    
    distancia >> dx1;
    distancia >> dy1;
    distancia >> dx2;
    distancia >> dy2;
    total=0;
    
    while(dx1!= 0 || dy1!=0){
        total = sqrt((pow (dx2-dx1,2))+(pow (dy2-dy1,2)))+total;
        cout << "Distância: "<< total << endl;
        dx1 = dx2;
        dy1 = dy2;
        distancia >> dx2;
        distancia >> dy2;
    }
    return 0;
}

