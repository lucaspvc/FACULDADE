#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <float.h>
#include <sys/stat.h>
#include <sys/types.h>


// Estrutura que armazena os dados para cálculo da Lei de Little
typedef struct {
    unsigned long int num_eventos;  // Número de eventos (clientes no sistema)
    double tempo_anterior;          // Tempo do último evento
    double soma_areas;              // Soma das áreas (eventos * tempo)
} little;

// Função que gera um número aleatório uniforme entre 0 e 1
double uniforme() {
    double u = rand() / ((double) RAND_MAX + 1);
    u = 1.0 - u;
    return u;
}

// Gera o tempo até o próximo evento com base em uma distribuição exponencial
double gera_tempo(double l) {
    return (-1.0/l) * log(uniforme());
}

// Retorna o menor valor entre dois números
double min(double n1, double n2) {
    if (n1 < n2) return n1;
    return n2;
}

// Inicializa uma estrutura do tipo little (zerando seus valores)
void inicia_little(little *n){
    n->num_eventos = 0;
    n-> soma_areas = 0.0;
    n->tempo_anterior = 0.0;
}

// Função para criar e iniciar o arquivo de coleta de dados da simulação
void inicia_arquivo(char f[], double param_chegada, double param_saida, double tempo_decorrido){
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
    if(!file){
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    // Escreve os cabeçalhos e parâmetros da simulação no arquivo
    fprintf(file, "#Arquivo %s \n", path);
    fprintf(file, "#Parametros(Chegada/saida/tempo): %.3f/%.3f/%.0f\n", param_chegada, param_saida, tempo_decorrido);
    fprintf(file, "#Coleta|Ocupação|E(n)|E(w)|lambda|Little\n\n");
    fclose(file);
}

// Função para escrever dados coletados no arquivo durante a simulação
void escreve_arquivo(char f[], int coleta, double ocupacao, double en_final,
double ew_final, double lambda){
    // Cria diretórios "Dados" e "Graficos" dependendo do sistema operacional
    #ifdef _WIN32
        _mkdir("Dados"); // No Windows
        _mkdir("Graficos");
    #else
        mkdir("Dados", 0777); // No Linux
        mkdir("Graficos", 0777); // No Linux
    #endif

    // Gera o caminho do arquivo
    char path[100] = "Dados/"; 
    strcat(path, f);

    // Abre o arquivo para anexar novos dados
    FILE *file = fopen(path, "a");
    if(!file){
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

int main (int argc, char *argv[ ] ) {
    // Inicializa o gerador de números aleatórios com base no valor de RAND_MAX
    srand(RAND_MAX);
    char nome_arquivo[20];

    //Entrada por linha de comando: tempo_chegada, tempo_atendimento, tempo_simulacao e número para dados de saida
    double param_chegada;
    param_chegada = atof(argv[1]);
    param_chegada = 1.0/param_chegada;

    double param_saida;
    param_saida = atof(argv[2]);
    param_saida = 1.0/param_saida;

    double tempo_simulacao;
    tempo_simulacao = atof(argv[3]);

    double tempo_decorrido = 0.0;

    double tempo_chegada = gera_tempo(param_chegada);
    double tempo_saida = DBL_MAX;

    double soma_ocupacao = 0.0;
    double coleta = 100.0;

    sprintf(nome_arquivo, "Coleta%d.txt", atoi(argv[4]));
    inicia_arquivo(nome_arquivo, atof(argv[1]), atof(argv[2]), atof(argv[3]));

    /**
     * variaveis little
     */
    little en;
    inicia_little(&en);
    little ew_chegadas;
    inicia_little(&ew_chegadas);
    little ew_saidas;
    inicia_little(&ew_saidas);

    unsigned long int fila = 0;
    unsigned long int fila_max = 0;

    while (tempo_decorrido <= tempo_simulacao) {
        tempo_decorrido = min(coleta, min(tempo_chegada, tempo_saida));

        if(tempo_decorrido == tempo_chegada) {
            //chegada
            if (!fila) {
                //sistema ocioso
                tempo_saida = tempo_decorrido + gera_tempo(param_saida);
                soma_ocupacao += tempo_saida - tempo_decorrido;
            } 
            fila ++;
            if (fila_max < fila) fila_max = fila;
            tempo_chegada = tempo_decorrido + gera_tempo(param_chegada);

            /**
             * little
             */
            en.soma_areas += (tempo_decorrido - en.tempo_anterior) * en.num_eventos;
            en.num_eventos++;
            en.tempo_anterior = tempo_decorrido;

            ew_chegadas.soma_areas += (tempo_decorrido - ew_chegadas.tempo_anterior) * ew_chegadas.num_eventos;
            ew_chegadas.num_eventos++;
            ew_chegadas.tempo_anterior = tempo_decorrido;
        } else if(tempo_decorrido == coleta){
            // Coleta de dados a cada 100 unidades de tempo
            en.soma_areas += (tempo_decorrido - en.tempo_anterior) * en.num_eventos;
            en.tempo_anterior = tempo_decorrido;
            ew_chegadas.soma_areas += (tempo_decorrido - ew_chegadas.tempo_anterior) * ew_chegadas.num_eventos;
            ew_chegadas.tempo_anterior = tempo_decorrido;
            ew_saidas.soma_areas += (tempo_decorrido - ew_saidas.tempo_anterior) * ew_saidas.num_eventos;
            ew_saidas.tempo_anterior = tempo_decorrido;

            double en_final = en.soma_areas/tempo_decorrido;
            double ew_final = (ew_chegadas.soma_areas - ew_saidas.soma_areas)/ew_chegadas.num_eventos;
            double lambda = ew_chegadas.num_eventos/tempo_decorrido;

            double ocupacao = (soma_ocupacao/tempo_decorrido)*100;

            escreve_arquivo(nome_arquivo, coleta, ocupacao, en_final, ew_final, lambda);
            coleta += 100;
        } else {
            //saida
            fila--;
            tempo_saida = DBL_MAX;
            if (fila) {
                tempo_saida = tempo_decorrido + gera_tempo(param_saida);
                soma_ocupacao += tempo_saida - tempo_decorrido;
            }

            /**
             * little
             */
            en.soma_areas += (tempo_decorrido - en.tempo_anterior) * en.num_eventos;
            en.num_eventos--;
            en.tempo_anterior = tempo_decorrido;

            ew_saidas.soma_areas += (tempo_decorrido - ew_saidas.tempo_anterior) * ew_saidas.num_eventos;
            ew_saidas.num_eventos++;
            ew_saidas.tempo_anterior = tempo_decorrido;
        }
    }
    
    en.soma_areas += (tempo_decorrido - en.tempo_anterior) * en.num_eventos;
    ew_chegadas.soma_areas += (tempo_decorrido - ew_chegadas.tempo_anterior) * ew_chegadas.num_eventos;
    ew_saidas.soma_areas += (tempo_decorrido - ew_saidas.tempo_anterior) * ew_saidas.num_eventos;
    
    double en_final = en.soma_areas/tempo_decorrido;
    double ew_final = (ew_chegadas.soma_areas - ew_saidas.soma_areas)/ew_chegadas.num_eventos;
    double lambda = ew_chegadas.num_eventos/tempo_decorrido;

    return 0;
}