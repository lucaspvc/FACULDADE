#include <bits/stdc++.h>
using namespace std;



typedef struct {
    string modelo;
    string marca;
    string tipo;
    int ano;
    int km;
    float potencia;
    string combustivel;
    string cambio;
    string direcao;
    string cor;
    int portas;
    string placa;
    float valor;
}Tveiculo;

void printarq(Tveiculo * bd[],int tam){ //reescrever o arquivo
    ofstream out;
    out.open("BD_veiculos_2.txt");
    for(int j = 0; j<tam;j++){  
        if( bd[j] != NULL){
         out << bd[j]->modelo << " " << bd[j]->marca << " " <<bd[j]->tipo<< " "
                    <<bd[j]->ano<< " "<<bd[j]->km<< " "<<bd[j]->potencia<< " "
                    <<bd[j]->combustivel<< " "<<bd[j]->cambio<< " "<<bd[j]->direcao<< " "
                    <<bd[j]->cor<< " "<<bd[j]->portas<< " "<<bd[j]->placa<< " "<<bd[j]->valor<< " "<< endl;
        }

    }
    out.close();
}

Tveiculo * busca (Tveiculo * bd[], int tam,string placa){
    for (int i = 0; i < tam; i++)
        if (bd[i] -> placa == placa)
            return bd[i];
        return NULL;
}

int remove_veiculo(string y, int tam, Tveiculo * bd[]){
    
    for (int i = 0; i < tam; i++){       //retirarndo o indicie desejado
        if (bd[i] -> placa == y){
            delete bd[i];
            bd[i] = NULL;    
        }
    }   
}
void insereveiculo(Tveiculo * bd[],int tam){ //inserção de um novo veículo
    if(tam == 50){
        cout << "Limite de veiculos atingido" << endl;
        return;
    }
    for(int i =0; i<50; i++){
        if(bd[i] == NULL){
            string pl;
            int k = i;
            bd[k] = new Tveiculo;
            
            cout << "Digite a placa do veiculo. Ex: AAA1234.\n"; //critério de existência no bd
            cin >> pl;
            
            Tveiculo * a;
            a = new Tveiculo;
            a = busca (bd, tam, pl);
            
            if (a == NULL){
                bd[k]->placa = pl;
                    
                cout << "Digite o modelo do veículo. Ex: KA\n";
                cin >> bd[k]->modelo;
                    
                cout << "Digite a marca do veículo. Ex: FORD.\n";
                cin >> bd[k]->marca;
                
                cout << "Digite o tipo do veículo. Ex: SUV.\n";
                cin >> bd[k]->tipo;

                cout << "Digite o ano do veículo. Ex: 2000.\n";
                cin >> bd[k]->ano;

                cout << "Digite a quilometragem do veículo. Ex: 32000.\n";
                cin >> bd[k]->km;

                cout << "Digite a potência do veículo. Ex: 1.6\n";
                cin >> bd[k]->potencia;

                cout << "Digite o tipo de combustível do veículo. Ex: Flex.\n";
                cin >> bd[k]->combustivel;

                cout << "Digite o tipo de câmbio do veículo. Ex: Manual.\n";
                cin >> bd[k]->cambio;

                cout << "Digite o tipo de direção do veículo. Ex: Hidráulica.\n";
                cin >> bd[k]->direcao;

                cout << "Digite a cor do veículo. Ex: Preto.\n";
                cin >> bd[k]->cor;

                cout << "Digite quantas portas há no veículo. Ex: 4\n";
                cin >> bd[k]->portas;
                
                cout << "Digite o valor do veículo. Ex: 00000.00\n";
                cin >> bd[k]->valor;
             
                cout <<"Veículo inserido."<< endl;
            }
            else{
                cout << "Não foi possível realizar a inserção, placa já existente.\n" << endl;
            }
            return;
        }
    }
}








void ordemplaca(Tveiculo * bd[],int tam){ 
    Tveiculo * duplicado[50];
    Tveiculo * aux;

    for(int i=0;i<tam;i++){         // passando valores para um novo vetor de struct
        duplicado[i] = bd[i];
    }

    for(int i=0; i < tam  -1;i++){
        for (int j=0; j<tam-1-i; j++){
            if (duplicado[j]-> placa > duplicado[j+1]-> placa){

                aux = duplicado[j];

                duplicado[j] = duplicado[j+1];

                duplicado[j+1] = aux; 
            }
        }
}

    for (int i = 0; i < tam; i++){                      //printando valores ordenados
            cout<< duplicado[i]->modelo << "  ";
            cout<< duplicado[i]->marca << "  ";
            cout<< duplicado[i]->tipo << "  ";
            cout<< duplicado[i]->ano << "  ";
            cout<< duplicado[i]->km << "  ";
            cout<< duplicado[i]->potencia << "  ";
            cout<< duplicado[i]->combustivel << "  ";
            cout<< duplicado[i]->cambio << "  ";
            cout<< duplicado[i]-> direcao << "  ";
            cout<< duplicado[i]->cor << "  ";
            cout<< duplicado[i]->portas << "  ";
            cout<< duplicado[i]->placa << "  ";
            cout<< duplicado[i]->valor << endl;


    }
}

void maisprox(Tveiculo * bd[],int tam,float n){
    int caunt = 0;
    int maior;
    float modulo[10];
    Tveiculo * valorprox [10];

    for(int i = 0; i < 10; i++){   // preenche os 10 primeiros valores do bd
        if(caunt < 10){
            valorprox[i] = bd[i];
            modulo[i] = abs(n - valorprox[i]->valor);
            caunt++;
        }
    }

    for(int i = 0; i < 10; i++){   //salva o maior valor
        if(i == 0){
            maior = modulo[i];
            caunt = i;
        }
        else if(modulo[i] > maior){
            maior = modulo[i];
            caunt = i;
        }
    }

    for(int i = 10; i < tam; i++){      //percorre o resto do banco de dados, colocando menores posicoes no vetor
        if(   (abs(n - bd[i]->valor)) < maior  ){
            valorprox[caunt] = bd[i];
            modulo[caunt] = abs(n - bd[i]->valor);
        }

        for(int i = 0; i < 10; i++){   //salva o maior valor
            if(i == 0){
                maior = modulo[i];
                caunt = i;
            }
            else if(modulo[i] > maior){
                maior = modulo[i];
                caunt = i;
            }
        } 

    }

    Tveiculo * aux;                 //ordena e printa em ordem de proximidade com o valor escolhido
    float aux2;
    for(int i = 0; i < 10-1;i++){
        for (int j=0; j<10-1-i; j++){
            if (modulo[j] > modulo[j+1]){
                aux2 = modulo[j];
                modulo[j] = modulo[j+1];
                modulo[j+1] = aux2; 

                aux = valorprox[j];
                valorprox[j] = valorprox[j+1];
                valorprox[j+1] = aux; 
            }
        }
    }

    cout <<"Os 10 carros com valor mais próximos são:\n";
    for (int i = 0; i < 10; i++){
        cout<< valorprox[i]->modelo << "  ";
        cout<< valorprox[i]->marca << "  ";
        cout<< valorprox[i]->tipo << "  ";
        cout<< valorprox[i]->ano << "  ";
        cout<< valorprox[i]->km << "  ";
        cout<< valorprox[i]->potencia << "  ";
        cout<< valorprox[i]->combustivel << "  ";
        cout<< valorprox[i]->cambio << "  ";
        cout<< valorprox[i]-> direcao << "  ";
        cout<< valorprox[i]->cor << "  ";
        cout<< valorprox[i]->portas << "  ";
        cout<< valorprox[i]->placa << "  ";
        cout<< valorprox[i]->valor << endl;
    }
}






int main(int argc, char** argv){
    
    ifstream myfile ("BD_veiculos_2.txt");
    Tveiculo * bd[50];
    Tveiculo * p;
    p = new Tveiculo;
    int tam = -1;
    int x;
    string y;
    int u;                                    //declaração das variáves usadas
    
    
    if (myfile.is_open()){                      // passando txt para o vetor de ponteiros para struct
        do {
            tam++;
            bd[tam] = new Tveiculo; 
            myfile >> bd[tam]->modelo;
            myfile >> bd[tam]->marca;
            myfile >> bd[tam]->tipo;
            myfile >> bd[tam]->ano;
            myfile >> bd[tam]->km;
            myfile >> bd[tam]->potencia;
            myfile >> bd[tam]->combustivel;
            myfile >> bd[tam]->cambio;
            myfile >> bd[tam]->direcao;
            myfile >> bd[tam]->cor;
            myfile >> bd[tam]->portas;
            myfile >> bd[tam]->placa;
            myfile >> bd[tam]->valor;
        }while(!myfile.eof() );
        myfile.close();
        
                                        
        for (int i = tam; i < 50; i++)   //Apontando os espaços vazios para NULL.
            bd[i] = NULL;
        
      
    }
    else
        cout << "\n\n\n ARQUIVO NÃO ENCONTRADO. \n\n\n" << endl;

    int newop = 0;
    while(newop!=6){                                                   //printar o menu na tela
        cout << "[1] Incluir novo veículo." << endl;
        cout << "[2] Busca por placa e remoção." << endl;
        cout << "[3] Buscar os 10 veículos próximos." << endl;
        cout << "[4] Ordenação por placa." << endl;
        cout << "[5] Autores do projeto." << endl;
        cout << "[6] Sair do programa." << endl;
        
    
        cout<< "Insira a opção desejada:"<< endl;
        
        cin >> newop;   
        switch(newop){
        case 1:
            insereveiculo(bd,tam);
            tam++;
            break;
            
        case 2:
            int u;
            cout<< "\nInsira a placa:" << endl;
            cin >> y;
            p = busca (bd, tam, y);
            if (p){
                cout << "Veículo encontrado:" << endl;
                cout << p->modelo << " " << p->marca << " " << p->ano << " " << endl;
                cout << "Deseja remover o veículo? [1]=sim ou [2]=não" << endl;
                cin >> u;

                while(u!= 1 && u!= 2){
                    cout << "Digite um valor valido";
                    cin >> u;
                }

                if( u == 1 ){
                    remove_veiculo(y,tam,bd);
                    cout << "Veículo removido\n\n\n\n";
                    printarq(bd,tam);
                    cout << "Programa finalizado."<< endl;
                    return 0;                    
                    break;
                }else if ( u == 2 ){
                    cout << "Veículo não removido\n\n\n\n";
                    break;
                }
            }
            cout << "Veículo não encontrado.\n\n\n\n";
            break;
            
        case 3:
            float v;
            cout << "\nBusca pelos 10 veículos mais próximos.";
            cout << "\nDigite o valor: \n";
            cin >> v;
            maisprox(bd,tam,v);
            break;
        
        case 4:
            cout << "\nOrdenação por placa.\n";
            ordemplaca(bd, tam);
            break;
            
        case 5:
             cout << "Autores:Gustavo Fernandez Pascoaleto 2021.1.08.009\n \tLetícia Freitas de Oliveira 2018.1.08.051\n \tLucas Pessoa Oliveira Alves 2022.1.08.044\n\n";
             break;
                
            
        case 6:
            printarq(bd,tam);
            cout << "Programa finalizado."<< endl;
            return 0;
            break;

        default:
            cout <<"\n\t\tOpção inválida.\n\n";
        } 
    } 
    
    return 0;
    
}