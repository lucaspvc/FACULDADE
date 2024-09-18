/**
 * Universidade Federal de Alfenas (UNIFAL) - 2024
 * Discentes: Lucas Pessoa Oliveira Alves 2022.1.08.044
 *
 * Docente: Paulo Alexandre Bressan - Computação Paralela e Distribuída
 * Exercício
 * Faça um programa no MPI que calcule a multiplicação entre duas matrizes.
 * A quantidade de elementos das linhas da 1ª matriz e de elementos das colunas
 * da 2ª matriz deve ser passado por parâmetro na linha de execução. Cada linha
 * da matriz deve ser processada por um processo, assim, na linha de execução, a
 * quantidade de processos definirá a quantidade de colunas da 1ª matriz e de
 * linhas da 2ª matriz. As matrizes devem ser geradas pelo processo raiz, e os
 * resultados devem ser enviados também para o processo raiz.
 */

#include <assert.h>
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função que cria uma matriz aleatória linearizada (em vetor)
float *criando_matriz_aleatoria(int linha, int coluna) {
  float *matriz_aleatoria = (float *)malloc(linha * coluna * sizeof(float));
  assert(matriz_aleatoria != NULL);

  for (int i = 0; i < linha * coluna; i++) {
    matriz_aleatoria[i] =
        (rand() / (float)RAND_MAX); // Gera número aleatório entre 0 e 1
  }

  return matriz_aleatoria;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Uso: mpirun -np <numero_de_processos> ./mpi_multiplicaMatrizes "
           "<linhas_A> <colunas_B>\n");
    exit(1);
  }

  srand(time(NULL));

  MPI_Init(NULL, NULL);

  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // Argumentos
  int linhaA = atoi(argv[1]);  // Número de linhas da matriz A
  int colunaB = atoi(argv[2]); // Número de colunas da matriz B
  int colunaA = world_size; // Número de colunas da matriz A e número de linhas
                            // da matriz B

  // Verifica se o número de processos é igual ao número de linhas de A
  if (linhaA != world_size) {
    if (world_rank == 0) {
      printf("Erro: O número de linhas de A (%d) deve ser igual ao número de "
             "processos (%d).\n",
             linhaA, world_size);
    }
    MPI_Finalize();
    exit(1);
  }

  // Matrizes
  float *matrizA = NULL;
  float *matrizB = NULL;
  float *sub_matrizA = (float *)malloc(
      linhaA * sizeof(float)); // Cada processo lida com uma linha de A
  float *matrizC = (float *)malloc(
      colunaB *
      sizeof(float)); // Cada processo armazena uma linha da matriz resultante C

  if (world_rank == 0) {
    // Gera matrizes A e B no processo 0
    matrizA =
        criando_matriz_aleatoria(linhaA, colunaA); // Dimensões linhaA x colunaA
    matrizB = criando_matriz_aleatoria(colunaA,
                                       colunaB); // Dimensões colunaA x colunaB

    // Exibe as matrizes geradas no processo 0
    printf("Matriz A (%dx%d):\n", linhaA, colunaA);
    for (int i = 0; i < linhaA; i++) {
      for (int j = 0; j < colunaA; j++) {
        printf("%f ", matrizA[i * colunaA + j]);
      }
      printf("\n");
    }
    printf("\n");
    printf("=========================================\n");

    printf("Matriz B (%dx%d):\n", colunaA, colunaB);
    for (int i = 0; i < colunaA; i++) {
      for (int j = 0; j < colunaB; j++) {
        printf("%f ", matrizB[i * colunaB + j]);
      }
      printf("\n");
    }
    printf("\n");
    printf("=========================================\n");
  }

  // Distribui as linhas da matriz A para os processos
  MPI_Scatter(matrizA, colunaA, MPI_FLOAT, sub_matrizA, colunaA, MPI_FLOAT, 0,
              MPI_COMM_WORLD);

  // Broadcast da matriz B para todos os processos
  if (world_rank != 0) {
    matrizB = (float *)malloc(colunaA * colunaB * sizeof(float));
  }
  MPI_Bcast(matrizB, colunaA * colunaB, MPI_FLOAT, 0, MPI_COMM_WORLD);

  // Cada processo multiplica sua linha de A pela matriz B
  for (int i = 0; i < colunaB; i++) {
    matrizC[i] = 0.0;
    for (int j = 0; j < colunaA; j++) {
      matrizC[i] += sub_matrizA[j] * matrizB[j * colunaB + i];
    }
  }

  // Recolhe as linhas resultantes em C para o processo 0
  float *resultado = NULL;
  if (world_rank == 0) {
    resultado = (float *)malloc(linhaA * colunaB * sizeof(float));
  }
  MPI_Gather(matrizC, colunaB, MPI_FLOAT, resultado, colunaB, MPI_FLOAT, 0,
             MPI_COMM_WORLD);

  // Exibe o resultado no processo 0
  if (world_rank == 0) {
    printf("Matriz Resultante C (A x B):\n");
    for (int i = 0; i < linhaA; i++) {
      for (int j = 0; j < colunaB; j++) {
        printf("%f ", resultado[i * colunaB + j]);
      }
      printf("\n");
    }
    free(resultado);
  }

  // Libera memória
  if (world_rank == 0) {
    free(matrizA);
    free(matrizB);
  } else {
    free(matrizB);
  }

  free(sub_matrizA);
  free(matrizC);

  MPI_Finalize();
  return 0;
}
