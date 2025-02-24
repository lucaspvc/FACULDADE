#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
    float paisA, paisB, taxaA, taxaB;
    int ano;
    ano = 0;
    paisA = 90000000;
    paisB = 200000000;
    taxaA = 0.03;
    taxaB = 0.015;
    while (paisB > paisA){
        paisA = (paisA*taxaA) + paisA;
        paisB = (paisB*taxaB) + paisB;
        ano++;
    }
    cout << "São necessários " << ano << " para que a populção do país A ultrapasse a do país B" << endl;
    return 0;
}