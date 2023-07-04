#include <bits/stdc++.h>

using namespace std;

int bubblesort(int vetor[], int n){
  int v[n]={};
  int aux, contBubble;
  aux = contBubble = 0;

  for (int i = 0; i < n; i++){
   v[i] = vetor[i];
  }

  for (int i = n - 1; i > 0; i--){
    for (int j = 0; j < i; j++){
    contBubble += 2;
      if (v[j] > v[j + 1]){
        aux = v[j];
        v[j] = v[j + 1];
        v[j + 1] = aux;
        contBubble += 4;
      }
    }
  }
  return contBubble;
}

int insertionsort(int vetor[], int n){
  int aux, j, contInsertion;
  int v[n] = {};
  contInsertion = 0;

  for (int i = 0; i < n; i++){
    v[i] = vetor[i];
  }

  for (int i = 1; i < n; i++){
    aux = v[i];
    j = i - 1;
    while (j >= 0 && v[j] > aux){
      v[j + 1] = v[j];
      j--;
      contInsertion += 2;
    }
    v[j + 1] = aux;
    contInsertion += 3;
  }

  return contInsertion;
}

int selectionsort(int vetor[], int n){
  int v[n]={};
  int aux, min, contSelection;
  contSelection = 0;

  for (int i = 0; i < n; i++){
   v[i] = vetor[i];
  }
  
  for (int i = 0; i < n; i++){
    min = i;
    aux = v[i];
    for (int j = i + 1; j < n; j++){
      contSelection ++;
      if (v[j] < aux){
        aux = v[j];
        min = j;
        contSelection++;
      }
    }
    v[min] = v[i];
    v[i] = aux;
    contSelection+=4;
  }
  return contSelection;
}

void create_file_random(int n, int m){
    int vetor[n] = {};
    int random_value = 0;
    cout << "Criando arquivo com valores aleatórios..." << endl;
    srand((unsigned) time(NULL));
    ofstream out ("random.txt");
    if (!out.is_open()){
      cout << "Erro na criação do arquivo" << endl;
      exit(1);
    }
    out << n << endl;
    for (int i = 0; i < n; i++){
        random_value = rand() % m; 
        int j = 0;
        while (j < n){
            if (random_value == vetor[j]){ 
                random_value = rand() % m;  
                j = 0;
            } else {
                j++;
            }
        }
        vetor[i] = random_value;
        out << vetor[i];
        out << endl;
    }
    cout << "Arquivo criado com sucesso!"  << endl;
    out.close();
}

void ordena_vetor(int vetor[], int n, string chave){
  int aux, min;
  if (chave == "cresc"){
    for (int i = 0; i < n; i++){
    min = i;
    aux = vetor[i];
    for (int j = i + 1; j < n; j++){
      if (vetor[j] < aux){
        aux = vetor[j];
        min = j;
      }
    }
    vetor[min] = vetor[i];
    vetor[i] = aux;
   }
  } else {
    for (int i = 0; i < n; i++){
    min = i;
    aux = vetor[i];
    for (int j = i + 1; j < n; j++){
      if (vetor[j] > aux){
        aux = vetor[j];
        min = j;
      }
    }
    vetor[min] = vetor[i];
    vetor[i] = aux;
   }
  }  
}

void open_file(int vetor[], int n){
  ifstream arquivo("random.txt");
  int valor = 0;
  if (!arquivo.is_open()){
      cout << "Erro na abertura do arquivo" << endl;
      exit(1);
    }
  arquivo >> valor; //descarte da primeira linha do arquivo
  for (int i = 0; i < n ; i++){
    arquivo >> valor;
    vetor[i] = valor;
  }
  arquivo.close();
}

void header_exit_file(string filename){
  ofstream out (filename);
  if (!out.is_open()){
    cout << "Erro na criação do arquivo" << endl;
    exit(1);
  }
  out << "qtd_elementos,cont_bbs,cont_ins,cont_sel\n" << endl;
  out.close(); 
}

void exit_file(string filename, int qtd_elementos, int cont_bbs, int cont_ins, int cont_sel){
  ofstream out;
  out.open(filename, ios_base::app);
  if (!out.is_open()){
    cout << "Não foi possível abrir o arquivo de saída: " << filename << endl;
    exit(1);
  }
  out << qtd_elementos << "," << cont_bbs << "," << cont_ins << "," << cont_sel << endl;
  out.close(); 
}

void interface(){
  cout << " __   __  _______  _______  _______  ______   _______  _______                    " << endl;
  cout << "|  |_|  ||       ||       ||       ||      | |       ||       |                   " << endl;
  cout << "|       ||    ___||_     _||   _   ||  _    ||   _   ||  _____|                   " << endl;
  cout << "|       ||   |___   |   |  |  | |  || | |   ||  | |  || |_____                    " << endl;
  cout << "|       ||    ___|  |   |  |  |_|  || |_|   ||  |_|  ||_____  |                   " << endl;
  cout << "| ||_|| ||   |___   |   |  |       ||       ||       | _____| |                   " << endl;
  cout << "|_|   |_||_______|  |___|  |_______||______| |_______||_______|                   " << endl;
  cout << " ______   _______                                                                 " << endl;
  cout << "|      | |       |                                                                " << endl;
  cout << "|  _    ||    ___|                                                                " << endl;
  cout << "| | |   ||   |___                                                                 " << endl;
  cout << "| |_|   ||    ___|                                                                " << endl;
  cout << "|       ||   |___                                                                 " << endl;
  cout << "|______| |_______|                                                                " << endl;
  cout << " _______  ______    ______   _______  __    _  _______  _______  _______  _______ " << endl;
  cout << "|       ||    _ |  |      | |       ||  |  | ||   _   ||       ||   _   ||       |" << endl;
  cout << "|   _   ||   | ||  |  _    ||    ___||   |_| ||  |_|  ||       ||  |_|  ||   _   |" << endl;
  cout << "|  | |  ||   |_||_ | | |   ||   |___ |       ||       ||       ||       ||  | |  |" << endl;
  cout << "|  |_|  ||    __  || |_|   ||    ___||  _    ||       ||      _||       ||  |_|  |" << endl;
  cout << "|       ||   |  | ||       ||   |___ | | |   ||   _   ||     |_ |   _   ||       |" << endl;
  cout << "|_______||___|  |_||______| |_______||_|  |__||__| |__||_______||__| |__||_______|" << endl;                                                  
  cout << "==================================================================================" << endl;
}

void result_print(int qtd_elementos, int cont_bbs, int cont_ins, int cont_sel){
  
}

void result_to_file(int vetor[], int intervalo, int n){
  int cont_bbs, cont_ins, cont_sel;
  cont_bbs = cont_ins = cont_sel = 0;
  for (int i = 1; i <= n; i += intervalo){
    cont_bbs = bubblesort(vetor, i);
    cont_ins = insertionsort(vetor, i);
    cont_sel = selectionsort(vetor, i);
    exit_file("ALEATORIO.txt", i, cont_bbs, cont_ins, cont_sel );

    ordena_vetor(vetor, i, "cresc");
    cont_bbs = bubblesort(vetor, i);
    cont_ins = insertionsort(vetor, i);
    cont_sel = selectionsort(vetor, i);
    exit_file("CRESCENTE.txt", i, cont_bbs, cont_ins, cont_sel );

    ordena_vetor(vetor, i, "dec");
    cont_bbs = bubblesort(vetor, i);
    ordena_vetor(vetor, i, "dec");
    cont_ins = insertionsort(vetor, i);
    ordena_vetor(vetor, i, "dec");
    cont_sel = selectionsort(vetor, i);
    exit_file("DECRESCENTE.txt", i, cont_bbs, cont_ins, cont_sel );
  }
}
int main(int argc, char const *argv[]){

  int m, intervalo, n, aux, qtd, cont_sel, cont_ins, cont_bbs, cont_total_bbs, cont_total_ins, cont_total_sel;
  cont_total_sel = cont_total_ins = cont_total_bbs = cont_sel = cont_bbs = cont_ins = intervalo = m = n = aux = qtd = 0;

  interface();

  cout << "Insira a quantidade de elementos do vetor: ";
  cin >> n;
  int vetor[n] = {};

  cout << "Insira o valor maximo: ";
  cin >> m;
  while (m <= n){
    cout << "Valor maximo menor que a quantidade de elementos" << endl;
    cout << "Insira outro valor maximo: ";
    cin >> m;
  }

  cout << "Insira o intervalo de comparação: ";
  cin >> intervalo;
  while (intervalo >= n){
    cout << "Itervalo maior que a quantidade de elementos" << endl;
    cout << "Insira um intervalo válido: ";
    cin >> intervalo;
  }

  cout << "==================================================================================" << endl;
  
  create_file_random(n, m);
  open_file(vetor, n);
  header_exit_file("ALEATORIO.txt");
  header_exit_file("CRESCENTE.txt");
  header_exit_file("DECRESCENTE.txt");
  cout << "==================================================================================" << endl;

  cont_total_bbs = bubblesort (vetor, n);
  cont_total_ins = insertionsort (vetor, n);
  cont_total_sel = selectionsort (vetor, n);


  result_to_file(vetor, intervalo, n);


  return 0;
}