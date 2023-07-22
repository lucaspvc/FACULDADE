/* Universidade Federal de Alfenas (UNIFAL) - 2023
 * Lucas Pessoa Oliveira Alves        2022.1.08.044
 * Jorran Luka Andrade dos Santos     2022.2.08.001
 *
 * Docente: Paulo Alexandre Bressan - Algoritimo e Estrutura de Dados I
 * 
 * Trabalho com o objetivo adquirir conhecimentos de manipulação de imagens em 
 * formato de matrizes implementando funcionalidades que geram novas imagens a 
 * partir de imagens lidas de arquivos-texto em formato PGM.
 */

#include <bits/stdc++.h>
//#include "operations.h"
#include "cores.h"
#include "operations.cpp" //vs code

using namespace std;

typedef int tImagem[1000][1000];

string erro;

/**
 * Função que carrega a imagem em PGM para uma matriz.
 * @param filename -> nome do arquivo a ser carregado.
 * @param img -> matriz onde vai ser guardado a matriz da imagem.
 * @param linhas -> total de linhas da matriz.
 * @param colunas -> total de colunas da matriz.
 * @param tons -> número total de tons da imagem.
 * @return -> retorna 0 se o arquivo for aberto, retorna 1 caso o arquivo não 
 * for encotrado, retorna 2 caso o arquivo não seja p2.
 */
int carregaPGM(string nome, tImagem img, int *linhas, int *colunas, int *tons) {
    string tipo;
    ifstream arquivo(nome);
    if (!arquivo.is_open()) {
        erro = "Erro: Arquivo não encontrado.";
        return 1;
    }
    arquivo >> tipo;
    if (tipo != "P2") {
        erro = "Erro: Arquivo não tem formato P2.";
        return 2;
    }
    arquivo >> *colunas >> *linhas >> *tons;
    for (int i = 0; i < *linhas; i++) {
        for (int j = 0; j < *colunas; j++) {
            arquivo >> img[i][j];
        }
    }
    arquivo.close();
    return 0;
}

/**
 * Função que carrega a imagem em PGM para uma matriz.
 * @param filename -> nome do arquivo a ser carregado.
 * @param img -> matriz onde vai ser guardado a matriz da imagem.
 * @param linhas -> total de linhas da matriz.
 * @param colunas -> total de colunas da matriz.
 * @param tons -> número total de tons da imagem.
 * @return -> retorna 0 se o arquivo for aberto, retorna 1 caso o arquivo não 
 * for encotrado, retorna 2 caso o arquivo não seja p2.
 */
int salvaPGM(string nome, tImagem img, int linhas, int colunas, int tons) {
    ofstream arquivo(nome);
    if (!arquivo.is_open()) {
        erro = "Erro: Arquivo não encontrado.";
        return 1;
    }
    arquivo << "P2" << endl << colunas << " " << linhas << endl << tons << endl;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            arquivo << img[i][j] << " ";
        }
        arquivo << endl;
    }
    arquivo.close();
    return 0;
}

int main() {
    tImagem img_entrada, img_saida;
    int colunas, linhas, tons, fator, op, op2;
    string arquivo_entrada, arquivo_saida;
    op = op2 = 0;

    cout << "\tLista de imagens disponíveis: " << endl;
    cout << verde_N "corinthians | homer | jorran | stanford | teletubbies" 
            reset << endl << endl;

    // Leitura do arquivo de entrada da imagem.
    cout << "Entre com o nome da imagem de entrada: ";
    cin >> arquivo_entrada;
    arquivo_entrada = arquivo_entrada + ".pgm";
    if (carregaPGM(arquivo_entrada, img_entrada, &linhas, &colunas, &tons) != 0) {
        cout << "\n" vermelho_G + erro + reset "\n";
        return 1;
    }

    while (op != 8) {
        cout << "====================== " azul_N "MENU" reset 
                " ======================" << endl;
        cout << verde_N "[1]" reset " Escurecer ou clarear a imagem." << endl;
        cout << verde_N "[2]" reset " Rotacionar a imagem à direita." << endl;
        cout << verde_N "[3]" reset " Rotacionar a imagem à esquerda." << endl;
        cout << verde_N "[4]" reset " Binarizar a imagem." << endl;
        cout << verde_N "[5]" reset " Iconizar a imagem(reduzi-lá para 64x64)." 
                << endl;
        cout << verde_N "[6]" reset " Aplicar o filtro passa-baixa na imagem." 
                << endl;
        cout << verde_N "[7]" reset " Carregar nova imagem." << endl;
        cout << verde_N "[8]" reset " Sair do programa." << endl;
        cout << "===================================================" << endl;
        cout << "Insira a opção desejada:" << endl;


        cin >> op;

        /*
         * switch case para as opções do menu.
         */
        switch (op) {
            case 1:
                while (op2 != 3) {
                    cout << verde_N"[1]" reset " Clarear a foto." << endl;
                    cout << verde_N"[2]" reset " Escurecer a foto." << endl;
                    cout << verde_N"[3]" reset " Voltar para o menu principal."
                            << endl;
                    cout << "Insira a opção desejada:" << endl;
                    cin >> op2;
                    switch (op2) {
                        case 1:
                            cout << "Insira o fator de clareamento [0 a 255]: ";
                            cin >> fator;
                            while (fator < 0 || fator > 255) {
                                cout << vermelho_G "Valor inválido." reset 
                                        << endl;
                                cout << "Insira um valor válido: ";
                                cin >> fator;
                            }
                            ajusteBrilho(img_entrada, img_saida, linhas, colunas,
                                    tons, fator);
                            // Escrita do arquivo de saída da imagem.
                            cout << "Entre com o nome da imagem de saída: ";
                            cin >> arquivo_saida;
                            arquivo_saida = arquivo_saida + ".pgm";
                            if (salvaPGM(arquivo_saida, img_saida, linhas,
                                    colunas, tons) != 0) {
                                cout << "\n" vermelho_N + erro + reset "\n";
                                return 1;
                            }
                            zerar_matriz(img_saida, linhas, colunas);
                            cout << "Arquivo salvo com " verde_N "sucesso!" 
                                    reset << endl;
                            break;

                        case 2:
                            cout << "Insira o fator de escurecimento [0 a 255]: ";
                            cin >> fator;
                            while (fator < 0 || fator > 255) {
                                cout << vermelho_G "Valor inválido." reset << endl;
                                cout << "Insira um valor válido: ";
                                cin >> fator;
                            }
                            ajusteBrilho(img_entrada, img_saida, linhas, colunas,
                                    tons, (-fator));
                            // Escrita do arquivo de saída da imagem.
                            cout << "Entre com o nome da imagem de saída: ";
                            cin >> arquivo_saida;
                            arquivo_saida = arquivo_saida + ".pgm";
                            if (salvaPGM(arquivo_saida, img_saida, linhas,
                                    colunas, tons) != 0) {
                                cout << "\n" vermelho_N + erro + reset "\n";
                                return 1;
                            }
                            zerar_matriz(img_saida, linhas, colunas);
                            cout << "Arquivo salvo com " verde_N "sucesso!" 
                                    reset << endl;
                            break;

                        default:
                            if (op2 == 3) {
                                cout << "Retornou ao Menu!" << endl;
                            } else
                                cout << vermelho_G "Opção inválida." reset 
                                        << endl;
                            break;
                    }
                }
                break;

            case 2:
                rotacionaDireita(img_entrada, img_saida, &linhas, &colunas);
                // Escrita do arquivo de saída da imagem.
                cout << "Entre com o nome da imagem de saída: ";
                cin >> arquivo_saida;
                arquivo_saida = arquivo_saida + ".pgm";
                if (salvaPGM(arquivo_saida, img_saida, linhas, colunas, tons) != 0) {
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
                if (salvaPGM(arquivo_saida, img_saida, linhas, colunas, tons) != 0) {
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
                if (salvaPGM(arquivo_saida, img_saida, linhas, colunas, tons) != 0) {
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
                if (salvaPGM(arquivo_saida, img_saida, 64, 64, tons) != 0) {
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
                if (salvaPGM(arquivo_saida, img_saida, linhas, colunas,
                        tons) != 0) {
                    cout << "\n" vermelho_N + erro + reset "\n";
                    return 1;
                }
                zerar_matriz(img_saida, linhas, colunas);
                cout << "Arquivo salvo com " verde_N "sucesso!" reset << endl;
                break;

            case 7:
                cout << "\tLista de imagens disponíveis: " << endl;
                cout << verde_N "corinthians | homer | jorran | stanford | "
                        "teletubbies" reset << endl << endl;
                // Leitura do arquivo de entrada da imagem.
                cout << "Entre com o nome da imagem de entrada: ";
                cin >> arquivo_entrada;
                arquivo_entrada = arquivo_entrada + ".pgm";
                if (carregaPGM(arquivo_entrada, img_entrada, &linhas, &colunas,
                        &tons) != 0) {
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