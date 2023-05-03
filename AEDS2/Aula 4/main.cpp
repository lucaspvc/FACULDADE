#include <iostream>

using namespace std;

int inst = 0;

int fatorial (int n){
    cout << endl << " Instância " << ++inst << " quando n = " << n;
    if (n < 2)
        return 1;
    else
        return n * fatorial (n-1);
}

int fatorial12 (int n){ //assinatura da função
    int fat = 1;
    if (n < 0)
        return -1; //-1 significa erro
    while (n > 1){
        fat = fat * n;
        n--;
    }
    return fat;
   
}

int main(int argc, char** argv) {
    int n, ft;
    cout << "Cálculo do Fatorial ..." << endl;
    cout << " Digite o valor de n -> ";
    cin >> n;
    ft = fatorial(n);
    cout << " O fatorial de " << n << " é -> " << ft << endl;
    return 0;
}