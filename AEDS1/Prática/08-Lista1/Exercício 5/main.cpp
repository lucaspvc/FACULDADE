#include <bits/stdc++.h>


using namespace std;

int main(int argc, char const *argv[]){
    cout << fixed << setprecision(2);
    string item;
    float venda, compra, lucro, vendaT, compraT;
    int qtdVendas, qtdCompra, menor, maior, entre;
    ifstream produto ("mercadoria.txt");
    if (!produto.is_open()){
        cout << "\nErro: Arquivo não encontrado.\n";
        return 1;
    }

    produto >> item;
   

    while (item != "fim"){
        produto >> compra;
        produto >> venda;
        qtdVendas++;
        qtdCompra++;
        lucro = ((venda - compra)/compra)*100;
        compraT = compraT + compra;
        vendaT = venda + vendaT;

        if (lucro < 10){
            menor++;
        }else if(lucro > 20){
            maior++;
        }else entre++;
        produto >> item;
    }
    cout << "Mercadorias com lucro menor do que 10%: " << menor << endl;
    cout << "Mercadorias com lucro maior do que 20%: " << maior << endl;
    cout << "Mercadorias com lucro entre 10% e 20%: " << entre << endl;
    cout << "O valor total de compras é: " << compraT << " R$" << endl;
    cout << "O valor total de vendas é: " << vendaT << " R$" << endl;
    cout << "O lucro total de compras é: " << vendaT - compraT << " R$" << ", lucrando " <<
     (((vendaT - compraT)/compraT)*100) << "% do valor total de " << compraT << " R$" << endl;

    

    return 0;
}
