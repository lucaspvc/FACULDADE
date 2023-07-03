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
  arquivo >> valor; //descarte da primeira linha d o arquivo
  for (int i = 0; i < n ; i++){
    arquivo >> valor;
    vetor[i] = valor;
  }
}


int main(int argc, char const *argv[]){

  int contador;
  int m, intervalo, n, aux, qtd;
  intervalo = m = n = aux = qtd = 0;

  cout << "Insira a quantidade de elementos do vetor: ";
  cin >> n;
  cout << "Insira o valor maximo do intervalo: ";
  cin >> m;
  while (m <= n){
    cout << "Valor maximo menor que a quantidade de elementos" << endl;
    cout << "Insira outro valor maximo: ";
    cin >> m;
  }
  cout << "Insira o intervalo de comparação: ";
  cin >> intervalo;
  cout << "------------------------------------------" << endl;
  int vetor[n] = {};
  
  create_file_random(n, m);
  open_file(vetor, n);
  cout << "------------------------------------------" << endl;

  cout << "Contagem no metodo InsertionSort com vetor aleatorio: ";
  contador = insertionsort(vetor, n);
  cout << contador << endl;

  cout << "Contagem no metodo BubbleSort com vetor aleatorio: ";
  contador = bubblesort(vetor, n);
  cout << contador << endl;

  cout << "Contagem no metodo SelectionSort com vetor aleatorio: ";
  contador = selectionsort(vetor, n);
  cout << contador << endl;
  cout << "------------------------------------------" << endl;


  ordena_vetor(vetor, n, "cresc");
  cout << "Contagem no metodo InsertionSort com vetor crescente: ";
  contador = insertionsort(vetor, n);
  cout << contador << endl;
  
  cout << "Contagem no metodo BubbleSort com vetor crescente: ";
  contador = bubblesort(vetor, n);
  cout << contador << endl;

  cout << "Contagem no metodo SelectionSort com vetor crescente: ";
  contador = selectionsort(vetor, n);
  cout << contador << endl;  
  cout << "------------------------------------------" << endl;


  ordena_vetor(vetor, n, "dec");
  cout << "Contagem no metodo InsertionSort com vetor decrescente: ";
  contador = insertionsort(vetor, n);
  cout << contador << endl;

  ordena_vetor(vetor, n, "dec");
  cout << "Contagem no metodo BubbleSort com vetor decrescente: ";
  contador = bubblesort(vetor, n);
  cout << contador << endl;

  ordena_vetor(vetor, n, "dec");
  cout << "Contagem no metodo SelectionSort com vetor decrescente: ";
  contador = selectionsort(vetor, n);
  cout << contador << endl;
  cout << "------------------------------------------" << endl;


  return 0;
}