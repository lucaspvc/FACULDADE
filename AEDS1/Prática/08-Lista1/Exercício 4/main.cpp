#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
    int m, n;
    float xmaior, ymaior, x, y,expressao, maior;

    cout << "Digite o valor de m: " << endl;
    cin >> m;
    cout << "Digite o valor de n: " << endl;
    cin >> n;
    maior = expressao = 0;
    x = xmaior = ymaior = 0;

    while (x <= m){
        y = 0;
        while (y <= n){
            expressao = (x * y)-(pow(x,2))+y;
            if(expressao > maior){
                maior = expressao;
                xmaior = x;
                ymaior = y;
            }
            y = y + 0.1;
        }        
        x = x + 0.1;
    }
    cout << "O maior resultado é: " << maior << endl;
    cout << "[x] vale: " << xmaior << " e [y] vale: "<< ymaior << endl;
    
    return 0;
}
