#include <cstdlib>
#include <iostream>
#include <fstream>


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
}Tveiculo;

Tveiculo * busca (Tveiculo * bd[], int tam,string placa){
    for (int i = 0; i < tam; i++)
        if (bd[i] -> placa == placa)
            return bd[i];
        return NULL;
}

int buscaindice (Tveiculo * bd[], int tam, string placa){
    for (int i = 0; i < tam; i++)
        if (bd[i] -> placa == placa)
            cout << i;
}

int main(int argc, char** argv) {
    
   /* ofstream myfile;
    myfile.open ("example.txt");
    if (myfile.is_open()){
        myfile << "This is a line. \n";
        myfile << "This is another line. \n";
        myfile.close();
    }
    else
        cout << "Unable to open file";*/
    
    ifstream myfile ("BD_veiculos.txt");
    Tveiculo * bd[50];
    int tam = 0;
    
    
    if (myfile.is_open()){
        while ( !myfile.eof() ){
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
            tam++;
        }
        myfile.close();
        
        
        for (int i = 0; i < tam; i++){
            cout<< bd[i]->modelo << "  ";
            cout<< bd[i]->marca << "  ";
            cout<< bd[i]->tipo << "  ";
            cout<< bd[i]->ano << "  ";
            cout<< bd[i]->km << "  ";
            cout<< bd[i]->potencia << "  ";
            cout<< bd[i]->combustivel << "  ";
            cout<< bd[i]->cambio << "  ";
            cout<< bd[i]-> direcao << "  ";
            cout<< bd[i]->cor << "  ";
            cout<< bd[i]->portas << "  ";
            cout<< bd[i]->placa << endl;
        }
        //Apontando os espaços vazios para NULL.
        for (int i = tam; i < 50; i++)
            bd[i] = NULL;
        
        // Removendo as structs da memória.
        for (int i = 0; i < tam; i++)
            delete (bd[i]);
    }
    else
        cout << "Arquivo não encontrado. ";
    
    
   Tveiculo * p = busca (bd, tam, "MNA7449");
        if (p){
            cout << "Veículo encontrado" << endl;
            cout << p->marca << " " << p->ano << " " << endl;
        }
        else 
            cout << "Veículo não encontrado";
    
    
    
    buscaindice (bd, tam, "MNA7449");
    
    
    return 0;
}