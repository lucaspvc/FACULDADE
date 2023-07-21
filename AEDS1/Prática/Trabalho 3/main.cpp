#include <bits/stdc++.h>
//#include "operations.h"
//#include "file.h"
#include "operations.cpp"
#include "file.cpp"
#include "cores.h"

using namespace std;

typedef int tImagem[1000][1000];

int main(){
    tImagem img_entrada, img_saida;
    int colunas, linhas, tons, fator, op, op2;
    string arquivo_entrada, arquivo_saida;
    op = op2 = 0;

    // Leitura do arquivo de entrada da imagem.
    cout << "Entre com o nome da imagem de entrada: ";
    cin >> arquivo_entrada;
    arquivo_entrada = arquivo_entrada + ".pgm";
    if (carregaPGM(arquivo_entrada, img_entrada, &linhas, &colunas, &tons) != 0)
    {
        cout << "\n" vermelho_G + erro + reset "\n";
        return 1;
    }

    while (op != 8){
        cout << "====================== " azul_N "MENU" reset " ======================"<< endl;
        cout << verde_N "[1]" reset " Escurecer ou clarear a imagem." << endl;
        cout << verde_N "[2]" reset " Rotacionar a imagem à direita." << endl;
        cout << verde_N "[3]" reset " Rotacionar a imagem à esquerda." << endl;
        cout << verde_N "[4]" reset " Binarizar a imagem." << endl;
        cout << verde_N "[5]" reset " Iconizar a imagem(reduzi-lá para 64x64)." << endl;
        cout << verde_N "[6]" reset " Aplicar o filtro passa-baixa na imagem." << endl;
        cout << verde_N "[7]" reset " Carregar nova imagem." << endl;
        cout << verde_N "[8]" reset " Sair do programa." << endl;
        cout << "==================================================="<< endl;
        cout << "Insira a opção desejada:" << endl;
        

        cin >> op;

        /*
         * switch case para as opções do menu.
         */
        switch (op){
        case 1:
            while (op2 != 3){
                cout << verde_N"[1]" reset " Clarear a foto." << endl;
                cout << verde_N"[2]" reset " Escurecer a foto." << endl;
                cout << verde_N"[3]" reset " Voltar para o menu principal." << endl;
                cout << "Insira a opção desejada:" << endl;
                cin >> op2;
                switch (op2){
                case 1:
                    cout << "Insira o fator de clareamento [0 a 255]: ";
                    cin >> fator;
                    ajusteBrilho(img_entrada, img_saida, linhas, colunas, tons, fator);
                    // Escrita do arquivo de saída da imagem.
                    cout << "Entre com o nome da imagem de saída: ";
                    cin >> arquivo_saida;
                    arquivo_saida = arquivo_saida + ".pgm";
                    if (salvaPGM(arquivo_saida, img_saida, linhas, colunas, tons) != 0)
                    {
                        cout << "\n" vermelho_N + erro + reset "\n";
                        return 1;
                    }
                    zerar_matriz(img_saida, linhas, colunas);
                    cout << "Arquivo salvo com " verde_N "sucesso!" reset << endl;
                    break;

                case 2:
                    cout << "Insira o fator de escurecimento [0 a 255]: ";
                    cin >> fator;
                    ajusteBrilho(img_entrada, img_saida, linhas, colunas, tons, (-fator));
                    // Escrita do arquivo de saída da imagem.
                    cout << "Entre com o nome da imagem de saída: ";
                    cin >> arquivo_saida;
                    arquivo_saida = arquivo_saida + ".pgm";
                    if (salvaPGM(arquivo_saida, img_saida, linhas, colunas, tons) != 0){
                        cout << "\n" vermelho_N + erro + reset "\n";
                        return 1;
                    }
                    zerar_matriz(img_saida, linhas, colunas);
                    cout << "Arquivo salvo com " verde_N "sucesso!" reset << endl;
                    break;

                default:
                    if (op2 == 3)
                    {
                        cout << "Retornou ao Menu!" << endl;
                    }
                    else
                        cout << vermelho_G "Opção inválida." reset << endl;
                    break;
                }
            }
            break;

        case 2:
            rotacionaDireita(img_entrada, img_saida, &linhas, &colunas);
            // Escrita do arquivo de saída da imagem.
            cout << "Entre com o nome da imagem de saída: ";
            cin >> arquivo_saida;
            arquivo_saida = arquivo_saida + ".pgm";teb
            if (salvaPGM(arquivo_saida, img_saida, linhas, colunas, tons) != 0){
                cout << "\n" vermelho_N + erro + reset "\n";
            return 1;
            }
            cout << "Arquivo salvo com " verde_N "sucesso!" reset << endl;
            break;

        case 3:
            rotacionaEsquerda(img_entrada, img_saida, &linhas, &colunas);
            // Escrita do arquivo de saída da imagem.
            cout << "Entre com o nome da imagem de saída: ";
            cin >> arquivo_saida;
            arquivo_saida = arquivo_saida + ".pgm";
            if (salvaPGM(arquivo_saida, img_saida, linhas, colunas, tons) != 0){
                cout << "\n" vermelho_N + erro + reset "\n";
            return 1;
            }
            zerar_matriz(img_saida, linhas, colunas);
            cout << "Arquivo salvo com " verde_N "sucesso!" reset << endl;
            break;

        case 4:
            cout << "Insira o fator limiar para a binarização: ";
            cin >> fator;
            binarizarImagem(img_entrada, img_saida, linhas, colunas, tons, fator);
            // Escrita do arquivo de saída da imagem.
            cout << "Entre com o nome da imagem de saída: ";
            cin >> arquivo_saida;
            arquivo_saida = arquivo_saida + ".pgm";
            if (salvaPGM(arquivo_saida, img_saida, linhas, colunas, tons) != 0){
                cout << "\n" vermelho_N + erro + reset "\n";
            return 1;
            }
            zerar_matriz(img_saida, linhas, colunas);
            cout << "Arquivo salvo com " verde_N "sucesso!" reset << endl;
            break;

        case 5:
            iconizar(img_entrada, img_saida, &linhas, &colunas);
            // Escrita do arquivo de saída da imagem.
            cout << "Entre com o nome da imagem de saída: ";
            cin >> arquivo_saida;
            arquivo_saida = arquivo_saida + ".pgm";
            if (salvaPGM(arquivo_saida, img_saida, 64, 64, tons) != 0){
                cout << "\n" vermelho_N + erro + reset "\n";
            return 1;
            }
            zerar_matriz(img_saida, 64, 64);
            cout << "Arquivo salvo com " verde_N "sucesso!" reset << endl;
            break;
        
        case 6:
            passa_baixa(img_entrada, img_saida, &linhas, &colunas);
            // Escrita do arquivo de saída da imagem.
            cout << "Entre com o nome da imagem de saída: ";
            cin >> arquivo_saida;
            arquivo_saida = arquivo_saida + ".pgm";
            if (salvaPGM(arquivo_saida, img_saida, linhas, colunas, tons) != 0){
                cout << "\n" vermelho_N + erro + reset "\n";
            return 1;
            }
            zerar_matriz(img_saida, linhas, colunas);
            cout << "Arquivo salvo com " verde_N "sucesso!" reset << endl;
        break;
        
        case 7:
            // Leitura do arquivo de entrada da imagem.
            cout << "Entre com o nome da imagem de entrada: ";
            cin >> arquivo_entrada;
            arquivo_entrada = arquivo_entrada + ".pgm";
            if (carregaPGM(arquivo_entrada, img_entrada, &linhas, &colunas, &tons) != 0){
                cout << "\n" vermelho_N + erro + reset "\n";
            return 1;
            }
            cout << "Arquivo aberto com " verde_N "sucesso!" reset << endl;
        break;
        
        case 8:
            cout << "Programa finalizado." << endl;
            return 0;
        break;

        default:
            cout << vermelho_G "Opção inválida." reset << endl;
        }
    }

    return 0;
}