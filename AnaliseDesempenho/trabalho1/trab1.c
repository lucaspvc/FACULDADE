#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <float.h>



typedef struct {
    unsigned long int num_eventos;
    double tempo_anterior;
    double soma_areas;
}little;



double uniforme() {
    double u = rand() / ((double) RAND_MAX + 1);
    //u == 0 --> ln(u) <-- problema
    //limitando u entre (0,1]
    u = 1.0 - u;
    return u;
}

double gera_tempo(double l) {
    return (-1.0/l) * log(uniforme());
}

double min(double n1, double n2) {
    if (n1 < n2) return n1;
    return n2;
}

void inicia_little(little *n){
    n->num_eventos = 0;
    n-> soma_areas = 0.0;
    n->tempo_anterior = 0.0;
}

void inicia_arquivo(char f[]){
    FILE *file = fopen(f, "w");
    if(!file){
        printf("erro ao abrir o arquivo:");
        return;
    }
    fprintf(file, "# Arquivo %s \n", f);
    fprintf(file, "#Coluna 1 > Ponto de coleta\n");
    fprintf(file, "#Coluna 2 > Ocupação\n");
    fprintf(file,"#Coluna 3 > E(n)\n");
    fprintf(file,"#Coluna 4 > E(w)\n");
    fprintf(file,"#Coluna 5 > lambda\n");
    fprintf(file,"#Coluna 6 > Erro de Little\n");
    fclose(file);
}

void escreve_arquivo(char f[], double coleta, double soma_ocupacao, double en_final,double ew_final, double lambda){
    FILE *file = fopen(f, "a");
    if(!file){
        printf("erro ao abrir o arquivo");
        return;
    }
    fprintf(file,"teste\n");
    fclose(file);
}

int main (int argc, char *argv[ ] ) {
    srand(time(NULL));
    char nome_arquivo[20];


    sprintf(nome_arquivo, "Coleta%d.txt", atoi(argv[4]));
    inicia_arquivo(nome_arquivo);

    double param_chegada;
    printf("Informe o tempo medio entre as chegadas: ");
    param_chegada = atof(argv[1]);
    //scanf("%lF", &param_chegada);
    param_chegada = 1.0/param_chegada;

    double param_saida;
    printf("Informe o tempo medio de atendimento: ");
    param_saida = atof(argv[2]);
    //scanf("%lF", &param_saida);
    param_saida = 1.0/param_saida;

    double tempo_simulacao;
    printf("Informe o tempo de simulacao: ");
    tempo_simulacao = atof(argv[3]);
    //scanf("%lF", &tempo_simulacao);

    double tempo_decorrido = 0.0;

    double tempo_chegada = gera_tempo(param_chegada);
    double tempo_saida = DBL_MAX;

    double soma_ocupacao = 0.0;
    double coleta = 100.0;

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

            en.soma_areas += (tempo_decorrido - en.tempo_anterior) * en.num_eventos;
            en.tempo_anterior = tempo_decorrido;
            ew_chegadas.soma_areas += (tempo_decorrido - ew_chegadas.tempo_anterior) * ew_chegadas.num_eventos;
            ew_chegadas.tempo_anterior = tempo_decorrido;
            ew_saidas.soma_areas += (tempo_decorrido - ew_saidas.tempo_anterior) * ew_saidas.num_eventos;
            ew_saidas.tempo_anterior = tempo_decorrido;

            //printf("Maior tamanho de fila: %ld\n", fila_max);
            //printf("Ocupacao: %lF\n", soma_ocupacao/tempo_decorrido);
            double en_final = en.soma_areas/tempo_decorrido;
            double ew_final = (ew_chegadas.soma_areas - ew_saidas.soma_areas)/ew_chegadas.num_eventos;
            double lambda = ew_chegadas.num_eventos/tempo_decorrido;

            //printf("================================\n");
            escreve_arquivo(nome_arquivo, coleta, soma_ocupacao, en_final, ew_final, lambda);
            //fprintf(file, "Tempo de coleta %lF\n", coleta);
            //printf("E[N]: %lF\n",en_final);
            //printf("E[W]: %lF\n", ew_final );
            //printf("Erro de Little: %.20lF\n", en_final - lambda * ew_final);
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
    


    //printf("Maior tamanho de fila: %ld\n", fila_max);
    //printf("Ocupacao: %lF\n", soma_ocupacao/tempo_decorrido);
    double en_final = en.soma_areas/tempo_decorrido;
    double ew_final = (ew_chegadas.soma_areas - ew_saidas.soma_areas)/ew_chegadas.num_eventos;
    double lambda = ew_chegadas.num_eventos/tempo_decorrido;


    //printf("E[N]: %lF\n",en_final);
    //printf("E[W]: %lF\n", ew_final );
    //printf("Erro de Little: %lF\n", en_final - lambda * ew_final);
    return 0;
}