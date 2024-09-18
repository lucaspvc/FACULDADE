/**
 * Universidade Federal de Alfenas (UNIFAL) - 2024
 * Discentes: Lucas Pessoa Oliveira Alves 2022.1.08.044
 *
 * Docente: Paulo Alexandre Bressan - Computação Paralela e Distribuída
 * Exercício
 * 1º faça um programa com a estrutura mestre/escravo, onde:
 *
 * -mestre: gera uma quantidade aleatória entre 1000 e 2000 números de valores
 * aleatórios entre 0 e 99, e envia para cada escravo.
 *
 * -escravo: recebe os valores gerados pelo mestre, calcula a somatŕoaia dos
 * valores e devolve para o mestre.
 *
 * 2º No program abaixo, realize M vezes a geração de valores, onde M deve ser 5
 * vezes o número de processos iniciados. O mestre deve enviar os valores
 * gerados para os escravos que terminarem primeiro. Para deixar o trabalho dos
 * escravos mais demorados, utilize float ou aumente a quantidade de numeros
 * gerados para cada escravo.
 */


#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 2000

/*
* Função para gerar os números aleatórios entre 0 e 99.
*/
void gerar_numeros_aleatorios(int *vector, int size) {
  for (int i = 0; i < size; i++) {
    vector[i] = rand() % 100;
  }
}

/*
* Função para calcular o somatório.
*/
int calcular_somatorio(int *numbers, int size) {
  int summatory = 0;
  for (int i = 0; i < size; i++) {
    summatory += numbers[i];
  }
  return summatory;
}

/*
* Função para o Mestre enviar informações aos escravos
*/
void mestre(int world_size) {
  int vector[MAX_NUMBERS];
  int tag_parada = 0;

  srand(time(NULL));

  for (int slave = 1; slave < world_size; slave++) {
    int size = (rand() % 1001) + 1000;
    gerar_numeros_aleatorios(vector, size);
    MPI_Send(vector, size, MPI_INT, slave, tag_parada, MPI_COMM_WORLD);
  }

  for (int slave = 1; slave < world_size * 5; slave++) {
    int temp;
    MPI_Status status;

    MPI_Recv(&temp, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD,
             &status);
    printf("O mestre recebeu o somatório %d do escravo %d.\n", temp,
           status.MPI_SOURCE);

    int size = (rand() % 1001) + 1000; 
    gerar_numeros_aleatorios(vector, size);
    MPI_Send(vector, size, MPI_INT, status.MPI_SOURCE, tag_parada,
             MPI_COMM_WORLD);
  }

  int parar = 0;
  for (int slave = 1; slave < world_size; slave++) {
    tag_parada = 1;
    MPI_Send(&parar, 1, MPI_INT, slave, tag_parada, MPI_COMM_WORLD);
  }
}

/*
* Função onde os Escravos recebem as informações dos Mestres
*/
void escravo(void) {
  MPI_Status status;
  int numbers[MAX_NUMBERS];
  int size;

  MPI_Recv(numbers, MAX_NUMBERS, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD,
           &status);
  MPI_Get_count(&status, MPI_INT, &size);

  while (status.MPI_TAG != 1) {
    int summatory = calcular_somatorio(numbers, size);
    MPI_Send(&summatory, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    MPI_Recv(numbers, MAX_NUMBERS, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD,
             &status);
    MPI_Get_count(&status, MPI_INT, &size);
  }
}

int main(void) {
  MPI_Init(NULL, NULL);

  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

  if (world_rank == 0) {
    mestre(world_size);
  } else {
    escravo();
  }

  MPI_Barrier(MPI_COMM_WORLD);
  MPI_Finalize();
}