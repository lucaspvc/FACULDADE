#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int i, m, n, aux, qtd;
    bool existe;
    i = m = n = aux = qtd = 0;
    ofstream out;
    out.open("random.txt");
    srand(time(NULL));

    cout << "Insira a quantidade de elementos do vetor: ";
    cin >> n;
    cout << "Insira o valor máximo do intervalo: ";
    cin >> m;
    int vetor[n];
    
    while(i < n){
        vetor[i] = rand()%m;
        existe = false;
        for (int j = 0; j < i; j++){
            if (vetor[j] == vetor[i]){
                existe = true;
            }
        }
        if(!existe){
            i++;
        }
    }

    out << n << endl;
    for (int i = 0; i < n - 1; i++){
        cout << vetor[i] << endl;
        out << vetor[i] << endl;
    }
    out << vetor[n - 1];
    cout << vetor [n - 1] << endl;

    return 0;
}
