#include <iostream>

using namespace std;

int inst = 0;

void fibonacci (int n, int ult, int penult){
    //cout << endl << " Instância " << ++inst << " ";
    cout << ult << " ";
    if (ult + penult < n)
        fibonacci (n, ult+penult, ult);
}

int main (int argc, char**argv){
    int n, ft;
    cout << "Cálculo da Sequência de Fibonacci ..." << endl;
    cout << "Digite o valor de n -> ";
    cin >> n;
    cout << "Sequência -> ";
    fibonacci (n, 1, 0);
    cout << endl;
    return 0;
}