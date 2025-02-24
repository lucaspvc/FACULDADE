#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    float valor;
    ifstream teclado ("entrada.txt");
    if (!teclado.is_open()){
        cout << "\nErro: Arquivo não encontrado.\n";
        return 1;
    }
    
    teclado >> valor;
    cout << "valor: " << valor << endl;
    while ( valor != 0 ){
        teclado >> valor;
        cout << "valor: " << valor << endl;
    }
    teclado.close();
    
    return 0;
}

