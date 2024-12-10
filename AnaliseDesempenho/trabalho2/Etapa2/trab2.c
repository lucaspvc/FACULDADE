#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define PACOTE_PEQUENO 40 * 8     // 40 bytes para bits
#define PACOTE_MEDIO 550 * 8      // 550 bytes para bits
#define PACOTE_GRANDE 1500 * 8    // 1500 bytes para bits
#define TAXA_TEMPO_REAL 64 * 1000 // 64 Kbps em bits por segundo

// Estrutura para o Little's Law
typedef struct {
  unsigned long int num_eventos;
  double tempo_anterior;
  double soma_areas;
} little;

// Função para gerar números uniformes
double uniforme() {
  double u = rand() / ((double)RAND_MAX + 1);
  u = 1.0 - u;
  return u;
}

// Função para gerar tempos exponenciais
double gera_tempo(double l) { return (-1.0 / l) * log(uniforme()); }

// Inicializa os valores para Little
void inicia_little(little *n) {
  n->num_eventos = 0;
  n->soma_areas = 0.0;
  n->tempo_anterior = 0.0;
}

// Sorteia o tamanho do pacote com base nas proporções
int gera_tamanho_pacote() {
  double p = uniforme(); // Gera número aleatório entre 0 e 1
  if (p <= 0.5) {
    return PACOTE_MEDIO; // 50% dos pacotes
  } else if (p <= 0.9) {
    return PACOTE_PEQUENO; // 40% dos pacotes
  } else {
    return PACOTE_GRANDE; // 10% dos pacotes
  }
}

// Calcula a capacidade do link de acordo com a ocupação desejada
double calcula_capacidade_link(double ocupacao_desejada, double taxa_chegada) {
  double media_tamanho =
      0.5 * PACOTE_MEDIO + 0.4 * PACOTE_PEQUENO + 0.1 * PACOTE_GRANDE;
  return (taxa_chegada * media_tamanho) / ocupacao_desejada;
}

// Função para criar e iniciar o arquivo de coleta de dados da simulação
void inicia_arquivo(char f[], double ocupacao_desejada, double capacidade) {
// Cria diretório "Dados" dependendo do sistema operacional (Windows/Linux)
#ifdef _WIN32
  _mkdir("Dados"); // No Windows
#else
  mkdir("Dados", 0777); // No Linux
#endif

  // Gera o caminho do arquivo
  char path[100] = "Dados/";
  strcat(path, f);

  // Abre o arquivo para escrita
  FILE *file = fopen(path, "w");
  if (!file) {
    printf("Erro ao abrir o arquivo\n");
    return;
  }
  // Escreve os cabeçalhos e parâmetros da simulação no arquivo
  fprintf(file, "#Arquivo %s \n", path);
  fprintf(file, "#Parâmetros(Ocupação: %.2f%%, Capacidade: %.3f bps)\n",
          ocupacao_desejada * 100, capacidade);
  fprintf(file, "#Coleta|Ocupação|E(n)|E(w)|lambda|Little\n\n");
  fclose(file);
}

// Função para escrever dados coletados no arquivo durante a simulação
void escreve_arquivo(char f[], int coleta, double ocupacao, double en_final,
                     double ew_final, double lambda) {
// Cria diretórios "Dados" e "Graficos" dependendo do sistema operacional
#ifdef _WIN32
  _mkdir("Dados"); // No Windows
  _mkdir("Graficos");
#else
  mkdir("Dados", 0777);    // No Linux
  mkdir("Graficos", 0777); // No Linux
#endif

  // Gera o caminho do arquivo
  char path[100] = "Dados/";
  strcat(path, f);

  // Abre o arquivo para anexar novos dados
  FILE *file = fopen(path, "a");
  if (!file) {
    printf("Erro ao abrir o arquivo");
    return;
  }

  // Escreve os dados da coleta no arquivo
  fprintf(file, "%d ", coleta);
  fprintf(file, "%.5f ", ocupacao);
  fprintf(file, "%.5f ", en_final);
  fprintf(file, "%.5f ", ew_final);
  fprintf(file, "%.5f ", lambda);
  fprintf(file, "%.20f\n", en_final - lambda * ew_final);

  fclose(file);
}

typedef struct {
  double time;
  double type_event; // '0' para inicio da chamada '1' para chegada,
                     //'2' para saída, '3' para relatório, '4' para o fim da
                     // chamada
} Event;

typedef struct {
  Event *data;
  int size;
  int capacity;
} Heap;

void initialize(Heap *heap, int capacity) {
  heap->data = (Event *)malloc(capacity * sizeof(Event));
  heap->size = 0;
  heap->capacity = capacity;
}

void swap(Event *a, Event *b) {
  Event temp = *a;
  *a = *b;
  *b = temp;
}

void heapifyUp(Heap *heap, int index) {
  int parent = (index - 1) / 2;
  if (parent >= 0 && heap->data[parent].time > heap->data[index].time) {
    swap(&heap->data[parent], &heap->data[index]);
    heapifyUp(heap, parent);
  }
}

void heapifyDown(Heap *heap, int index) {
  int smallest = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  if (left < heap->size && heap->data[left].time < heap->data[smallest].time) {
    smallest = left;
  }
  if (right < heap->size &&
      heap->data[right].time < heap->data[smallest].time) {
    smallest = right;
  }
  if (smallest != index) {
    swap(&heap->data[index], &heap->data[smallest]);
    heapifyDown(heap, smallest);
  }
}

void insert_heap(Heap *heap, double time, char type_event) {
  if (heap->size == heap->capacity) {
    heap->capacity *= 2;
    heap->data = (Event *)realloc(heap->data, heap->capacity * sizeof(Event));
  }
  heap->data[heap->size].time = time;
  heap->data[heap->size].type_event = type_event;
  heapifyUp(heap, heap->size);
  heap->size++;
}

Event delete_heap(Heap *heap) {
  Event root = heap->data[0];
  heap->data[0] = heap->data[--heap->size];
  heapifyDown(heap, 0);
  return root;
}

// Função para criar e iniciar o arquivo de dados finais da simulação
void inicia_arquivo_final(char f[], double ocupacao_desejada,
                          double capacidade) {
// Cria diretório "Dados" dependendo do sistema operacional (Windows/Linux)
#ifdef _WIN32
  _mkdir("DadosFinais"); // No Windows
#else
  mkdir("DadosFinais", 0777); // No Linux
#endif

  // Gera o caminho do arquivo
  char path[100] = "DadosFinais/";
  strcat(path, f);

  // Abre o arquivo para escrita
  FILE *file = fopen(path, "w");
  if (!file) {
    printf("Erro ao abrir o arquivo\n");
    return;
  }
  // Escreve os cabeçalhos e parâmetros da simulação no arquivo
  fprintf(file, "#Arquivo %s \n", path);
  fprintf(file, "#Parâmetros(Ocupação: %.3f%%, Capacidade: %.3f bps)\n",
          ocupacao_desejada * 100, capacidade);
  fprintf(file, "#Coleta|Ocupação|E(n)|E(w)|lambda|Little\n\n");
  fclose(file);
}

// Função para escrever dados coletados no arquivo durante a simulação
void escreve_arquivo_final(char f[], int coleta, double ocupacao,
                           double en_final, double ew_final, double lambda) {
// Cria diretórios "Dados" e "Graficos" dependendo do sistema operacional
#ifdef _WIN32
  _mkdir("DadosFinais"); // No Windows
#else
  mkdir("DadosFinais", 0777); // No Linux
#endif

  // Gera o caminho do arquivo
  char path[100] = "DadosFinais/";
  strcat(path, f);

  // Abre o arquivo para anexar novos dados
  FILE *file = fopen(path, "a");
  if (!file) {
    printf("Erro ao abrir o arquivo");
    return;
  }

  // Escreve os dados da coleta no arquivo
  fprintf(file, "%d ", coleta);
  fprintf(file, "%.5f ", ocupacao);
  fprintf(file, "%.5f ", en_final);
  fprintf(file, "%.5f ", ew_final);
  fprintf(file, "%.5f ", lambda);
  fprintf(file, "%.20f\n", en_final - lambda * ew_final);

  fclose(file);
}

int main(int argc, char *argv[]) {
  if (argc != 7) {
    fprintf(stderr,
            "Uso: %s <Taxa Chegada> <Tempo Simulacao(s)> <Ocupacao1> "
            "<Ocupacao2> <Ocupacao3> <Ocupacao4>\n",
            argv[0]);
    return 1;
  }

  srand(RAND_MAX);

  double taxa_chegada;
  taxa_chegada = atof(argv[1]);
  double tempo_simulacao;
  tempo_simulacao = atof(argv[2]);
  double parametro_chegada = taxa_chegada;

  // Contadores
  int cont_pequeno, cont_medio, cont_grande;

  double ocupacao_desejada[] = {atof(argv[3]), atof(argv[4]), atof(argv[5]),
                                atof(argv[6])};
  double capacidades[4];

  for (int i = 0; i < 4; i++) {
    cont_pequeno = 0;
    cont_medio = 0;
    cont_grande = 0;

    capacidades[i] =
        calcula_capacidade_link(ocupacao_desejada[i], taxa_chegada);
    printf("\nCapacidade do link para %.0f%% de ocupação: %.2f bits/s\n",
           ocupacao_desejada[i] * 100, capacidades[i]);

    char nome_arquivo[20];
    char nome_arquivo_real[30];
    char nome_arquivo_total[30];

    sprintf(nome_arquivo, "ColetaWeb%.0f.txt", ocupacao_desejada[i] * 100);
    inicia_arquivo(nome_arquivo, ocupacao_desejada[i], capacidades[i]);
    sprintf(nome_arquivo_real, "ColetaChamadaReal%.0f.txt",
            ocupacao_desejada[i] * 100);
    inicia_arquivo(nome_arquivo_real, ocupacao_desejada[i], capacidades[i]);
    sprintf(nome_arquivo_total, "ColetaTotal%.0f.txt",
            ocupacao_desejada[i] * 100);
    inicia_arquivo(nome_arquivo_total, ocupacao_desejada[i], capacidades[i]);

    double tempo_decorrido = 0.0;
    double tempo_chegada = gera_tempo(parametro_chegada);
    double tempo_saida = DBL_MAX;

    unsigned long int fila = 0;

    unsigned long int fila_chamadas = 0;

    double soma_ocupacao = 0.0;
    double coleta = 100.0;
    double soma_ocupacao_chamadas = 0.0;
    double duracao_total_chamadas = 0.0;

    unsigned long int chamada_ativas = 0;
    double capacidade_link = capacidades[i];
    double tempo_chamada = gera_tempo(1.0 / 30.0);
    double intervalo_chamada;
    double duracao_chamada;

    double en_total, ew_total, lambda_total, erro_little_total;

    // Variáveis do Little's Law
    little en;
    inicia_little(&en);
    little ew_chegadas;
    inicia_little(&ew_chegadas);
    little ew_saidas;
    inicia_little(&ew_saidas);

    little en_chamadas_tempo_real;
    inicia_little(&en_chamadas_tempo_real);
    little ew_chamadas_tempo_real;
    inicia_little(&ew_chamadas_tempo_real);
    little ew_saidas_chamadas_tempo_real;
    inicia_little(&ew_saidas_chamadas_tempo_real);

    Heap heap;
    initialize(&heap, 10);

    // Insere eventos iniciais no heap
    insert_heap(&heap, tempo_chegada, 1); // chegada
    insert_heap(&heap, tempo_saida, 2);   // saida
    insert_heap(&heap, coleta, 3);        // coleta
    insert_heap(&heap, tempo_chamada, 0); // evento inicial de chamada

    while (tempo_decorrido <= tempo_simulacao) {
      Event evento_atual = delete_heap(&heap);
      tempo_decorrido = evento_atual.time;

      // Chegada
      if (evento_atual.type_event == 1) {
        int tamanho_pacote = gera_tamanho_pacote();

        // Atualiza os contadores
        if (tamanho_pacote == PACOTE_PEQUENO)
          cont_pequeno++;
        else if (tamanho_pacote == PACOTE_MEDIO)
          cont_medio++;
        else if (tamanho_pacote == PACOTE_GRANDE)
          cont_grande++;

        double tempo_atendimento = (double)tamanho_pacote / capacidade_link;

        if (fila == 0) {
          tempo_saida = tempo_decorrido + tempo_atendimento;
          insert_heap(&heap, tempo_saida, 2);
          soma_ocupacao += tempo_atendimento;
        }

        fila++;

        tempo_chegada = tempo_decorrido + gera_tempo(parametro_chegada);
        insert_heap(&heap, tempo_chegada, 1);

        // Atualiza o Little's Law
        en.soma_areas += (tempo_decorrido - en.tempo_anterior) * en.num_eventos;
        en.num_eventos++;
        en.tempo_anterior = tempo_decorrido;

        ew_chegadas.soma_areas +=
            (tempo_decorrido - ew_chegadas.tempo_anterior) *
            ew_chegadas.num_eventos;
        ew_chegadas.num_eventos++;
        ew_chegadas.tempo_anterior = tempo_decorrido;
      } else if (evento_atual.type_event == 3) {
        int total_pacotes = cont_pequeno + cont_medio + cont_grande;
        if (total_pacotes > 0) {
          // Relatório Web
          en.soma_areas +=
              (tempo_decorrido - en.tempo_anterior) * en.num_eventos;
          en.tempo_anterior = tempo_decorrido;
          ew_chegadas.soma_areas +=
              (tempo_decorrido - ew_chegadas.tempo_anterior) *
              ew_chegadas.num_eventos;
          ew_chegadas.tempo_anterior = tempo_decorrido;
          ew_saidas.soma_areas += (tempo_decorrido - ew_saidas.tempo_anterior) *
                                  ew_saidas.num_eventos;
          ew_saidas.tempo_anterior = tempo_decorrido;

          double en_final = en.soma_areas / tempo_decorrido;
          double ew_final = (ew_chegadas.soma_areas - ew_saidas.soma_areas) /
                            ew_chegadas.num_eventos;
          double lambda = ew_chegadas.num_eventos / tempo_decorrido;

          double ocupacao = (soma_ocupacao / tempo_decorrido) * 100;
          escreve_arquivo(nome_arquivo, tempo_decorrido, ocupacao, en_final,
                          ew_final, lambda);

          // Relatório chamada em tempo real
          en_chamadas_tempo_real.soma_areas +=
              (tempo_decorrido - en_chamadas_tempo_real.tempo_anterior) *
              en_chamadas_tempo_real.num_eventos;
          en_chamadas_tempo_real.tempo_anterior = tempo_decorrido;
          ew_chamadas_tempo_real.soma_areas +=
              (tempo_decorrido - ew_chamadas_tempo_real.tempo_anterior) *
              ew_chamadas_tempo_real.num_eventos;
          ew_chamadas_tempo_real.tempo_anterior = tempo_decorrido;
          ew_saidas_chamadas_tempo_real.soma_areas +=
              (tempo_decorrido - ew_saidas_chamadas_tempo_real.tempo_anterior) *
              ew_saidas_chamadas_tempo_real.num_eventos;
          ew_saidas_chamadas_tempo_real.tempo_anterior = tempo_decorrido;

          double en_final_chamadas =
              en_chamadas_tempo_real.soma_areas / tempo_decorrido;
          double ew_final_chamadas =
              (ew_chamadas_tempo_real.soma_areas -
               ew_saidas_chamadas_tempo_real.soma_areas) /
              ew_chamadas_tempo_real.num_eventos;
          double lambda_chamadas =
              ew_chamadas_tempo_real.num_eventos / tempo_decorrido;

          double ocupacao_chamadas =
              (soma_ocupacao_chamadas / tempo_decorrido) * 100;
          escreve_arquivo(nome_arquivo_real, tempo_decorrido, ocupacao_chamadas,
                          en_final_chamadas, ew_final_chamadas,
                          lambda_chamadas);
          // Calculando métricas totais
          double soma_areas_en_total =
              en.soma_areas + en_chamadas_tempo_real.soma_areas;
          double soma_areas_ew_total =
              (ew_chegadas.soma_areas + ew_chamadas_tempo_real.soma_areas) -
              (ew_saidas.soma_areas + ew_saidas_chamadas_tempo_real.soma_areas);

          unsigned long int total_eventos_chegadas =
              ew_chegadas.num_eventos + ew_chamadas_tempo_real.num_eventos;

          en_total = soma_areas_en_total / tempo_decorrido;
          ew_total = soma_areas_ew_total / total_eventos_chegadas;
          lambda_total = total_eventos_chegadas / tempo_decorrido;

          // Verificando a Lei de Little
          erro_little_total = fabs(en_total - (lambda_total * ew_total));

          // Salvando no arquivo total
          escreve_arquivo(nome_arquivo_total, tempo_decorrido, 0.0, en_total,
                          ew_total, lambda_total);

        } else {
          printf("Tempo: %.0f\n", coleta);
          printf("  Nenhum pacote rfoi recebido.\n");
        }
        coleta += 100.0;
        insert_heap(&heap, coleta, 3);
      }
      // Saída
      else if (evento_atual.type_event == 2) {
        fila--;
        tempo_saida = DBL_MAX;
        if (fila > 0) {
          int tamanho_pacote = gera_tamanho_pacote();
          double tempo_atendimento = (double)tamanho_pacote / capacidade_link;
          tempo_saida = tempo_decorrido + tempo_atendimento;
          insert_heap(&heap, tempo_saida, 2);
          soma_ocupacao += (double)tamanho_pacote / capacidade_link;
        } else {
          tempo_saida = DBL_MAX;
          insert_heap(&heap, tempo_saida, 2);
        }

        // Atualiza o Little's Law
        en.soma_areas += (tempo_decorrido - en.tempo_anterior) * en.num_eventos;
        en.num_eventos--;
        en.tempo_anterior = tempo_decorrido;

        ew_saidas.soma_areas += (tempo_decorrido - ew_saidas.tempo_anterior) *
                                ew_saidas.num_eventos;
        ew_saidas.num_eventos++;
        ew_saidas.tempo_anterior = tempo_decorrido;
      } else if (evento_atual.type_event == 0) {
        // Início de uma chamada
        chamada_ativas++;
        duracao_chamada = gera_tempo(1.0 / 60.0);
        duracao_total_chamadas += duracao_chamada;

        if (fila_chamadas == 0) {
          insert_heap(&heap, tempo_decorrido + duracao_chamada, 4);
          soma_ocupacao_chamadas +=
              (TAXA_TEMPO_REAL * duracao_chamada) / capacidade_link;
        }
        fila_chamadas++;

        // Início da proxima chamada no heap
        tempo_chamada = tempo_decorrido + gera_tempo(1.0 / 30.0);
        insert_heap(&heap, tempo_chamada, 0);

        // Atualiza o Little's Law
        en_chamadas_tempo_real.soma_areas +=
            (tempo_decorrido - en_chamadas_tempo_real.tempo_anterior) *
            en_chamadas_tempo_real.num_eventos;
        en_chamadas_tempo_real.num_eventos++;
        en_chamadas_tempo_real.tempo_anterior = tempo_decorrido;

        ew_chamadas_tempo_real.soma_areas +=
            (tempo_decorrido - ew_chamadas_tempo_real.tempo_anterior) *
            ew_chamadas_tempo_real.num_eventos;
        ew_chamadas_tempo_real.num_eventos++;
        ew_chamadas_tempo_real.tempo_anterior = tempo_decorrido;

      } else if (evento_atual.type_event == 4) {
        // Fim da chamada
        fila_chamadas--;
        if (chamada_ativas > 0)
          chamada_ativas--;

        if (fila_chamadas > 0) {
          insert_heap(&heap, tempo_decorrido + duracao_chamada, 4);
          soma_ocupacao_chamadas +=
              (TAXA_TEMPO_REAL * duracao_chamada) / capacidade_link;
        } else {
          insert_heap(&heap, DBL_MAX, 4);
        }

        // Atualiza o Little's Law
        en_chamadas_tempo_real.soma_areas +=
            (tempo_decorrido - en_chamadas_tempo_real.tempo_anterior) *
            en_chamadas_tempo_real.num_eventos;
        en_chamadas_tempo_real.num_eventos--;
        en_chamadas_tempo_real.tempo_anterior = tempo_decorrido;

        ew_saidas_chamadas_tempo_real.soma_areas +=
            (tempo_decorrido - ew_saidas_chamadas_tempo_real.tempo_anterior) *
            ew_saidas_chamadas_tempo_real.num_eventos;
        ew_saidas_chamadas_tempo_real.num_eventos++;
        ew_saidas_chamadas_tempo_real.tempo_anterior = tempo_decorrido;
      }
    }
    ew_chegadas.soma_areas += (tempo_decorrido - ew_chegadas.tempo_anterior) *
                              ew_chegadas.num_eventos;
    ew_saidas.soma_areas +=
        (tempo_decorrido - ew_saidas.tempo_anterior) * ew_saidas.num_eventos;

    ew_chamadas_tempo_real.soma_areas +=
        (tempo_decorrido - ew_chamadas_tempo_real.tempo_anterior) *
        ew_chamadas_tempo_real.num_eventos;
    ew_saidas_chamadas_tempo_real.soma_areas +=
        (tempo_decorrido - ew_saidas_chamadas_tempo_real.tempo_anterior) *
        ew_saidas_chamadas_tempo_real.num_eventos;

    // Web
    double en_final = en.soma_areas / tempo_decorrido;
    double ew_final = (ew_chegadas.soma_areas - ew_saidas.soma_areas) /
                      ew_chegadas.num_eventos;
    double lambda = ew_chegadas.num_eventos / tempo_decorrido;
    double ocupacao = (soma_ocupacao / tempo_decorrido) * 100;

    char valores_finais[30];
    sprintf(valores_finais, "ColetaWeb%.0f.txt", ocupacao_desejada[i] * 100);
    inicia_arquivo_final(valores_finais, ocupacao_desejada[i], capacidade_link);
    escreve_arquivo_final(valores_finais, coleta, ocupacao, en_final, ew_final,
                          lambda);

    // Chamadas
    double en_final_chamadas =
        en_chamadas_tempo_real.soma_areas / tempo_decorrido;
    double ew_final_chamadas = (ew_chamadas_tempo_real.soma_areas -
                                ew_saidas_chamadas_tempo_real.soma_areas) /
                               ew_chamadas_tempo_real.num_eventos;
    double lambda_chamadas =
        ew_chamadas_tempo_real.num_eventos / tempo_decorrido;
    double ocupacao_chamadas = (soma_ocupacao_chamadas / tempo_decorrido) * 100;

    char valores_finaisChamada[50];
    sprintf(valores_finaisChamada, "ColetaChamadasReal%.0f.txt",
            ocupacao_desejada[i] * 100);
    inicia_arquivo_final(valores_finaisChamada, ocupacao_desejada[i],
                         capacidade_link);
    escreve_arquivo_final(valores_finaisChamada, coleta, ocupacao_chamadas,
                          en_final_chamadas, ew_final_chamadas,
                          lambda_chamadas);

    // Calculando métricas totais
    double soma_areas_en_total =
        en.soma_areas + en_chamadas_tempo_real.soma_areas;
    double soma_areas_ew_total =
        (ew_chegadas.soma_areas + ew_chamadas_tempo_real.soma_areas) -
        (ew_saidas.soma_areas + ew_saidas_chamadas_tempo_real.soma_areas);

    unsigned long int total_eventos_chegadas =
        ew_chegadas.num_eventos + ew_chamadas_tempo_real.num_eventos;

    en_total = soma_areas_en_total / tempo_decorrido;
    ew_total = soma_areas_ew_total / total_eventos_chegadas;
    lambda_total = total_eventos_chegadas / tempo_decorrido;

    // Verificando a Lei de Little
    erro_little_total = fabs(en_total - (lambda_total * ew_total));

    char valores_finaisTotal[50];
    sprintf(valores_finaisTotal, "ColetaTotal%.0f.txt",
            ocupacao_desejada[i] * 100);
    inicia_arquivo_final(valores_finaisTotal, ocupacao_desejada[i],
                         capacidade_link);
    escreve_arquivo_final(valores_finaisTotal, coleta, 0.0, en_total, ew_total,
                          lambda_total);

    free(heap.data);
  }

  return 0;
}