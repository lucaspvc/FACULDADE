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
    matriz_aleatoria[i] = (rand() / (float)RAND_MAX); // Gera número aleatório entre 0 e 1
  }

  return matriz_aleatoria;
}

// Função para calcular sendcounts e displs
void calcula_sendcounts_displs(int total_elementos, int num_procs, int *sendcounts, int *displs) {
  int base_elementos = total_elementos / num_procs;
  int resto = total_elementos % num_procs;

  displs[0] = 0;

  for (int i = 0; i < num_procs; i++) {
    sendcounts[i] = base_elementos + (i < resto ? 1 : 0);
    if (i > 0) {
      displs[i] = displs[i - 1] + sendcounts[i - 1];
    }
  }
}

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Uso: mpirun -np <numero_de_processos> ./mpi_somaMatrizes <numero_de_linhas> <numero_de_colunas>\n");
    exit(1);
  }
  srand(time(NULL));

  MPI_Init(NULL, NULL);

  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  int linha = atoi(argv[1]);
  int coluna = atoi(argv[2]);
  int total_elementos = linha * coluna;

  // Arrays para sendcounts e displs
  int *sendcounts = (int *)malloc(world_size * sizeof(int));
  int *displs = (int *)malloc(world_size * sizeof(int));

  // Cálculo de sendcounts e displs para Scatterv
  calcula_sendcounts_displs(total_elementos, world_size, sendcounts, displs);


  // Matrizes
  float *matrizX = NULL;
  float *matrizY = NULL;
  float *sub_matrizX = (float *)malloc(sendcounts[world_rank] * sizeof(float));
  float *sub_matrizY = (float *)malloc(sendcounts[world_rank] * sizeof(float));
  float *sub_matrizResultante = (float *)malloc(sendcounts[world_rank] * sizeof(float));
  
  if (world_rank == 0) {
      printf("Exibição do sendcounts e displs:\n");
      printf("sendcounts: ");
      for(int i = 0; i < world_size; i++) {
          printf("%d ", sendcounts[i]);
      }
      printf("\ndispls: ");
      for(int i = 0; i < world_size; i++) {
          printf("%d ", displs[i]);
      }
      printf("\n=======================================\n");

      // Gera matrizes X e Y no processo 0
      matrizX = criando_matriz_aleatoria(linha, coluna);
      matrizY = criando_matriz_aleatoria(linha, coluna);

      // Exibe a matriz X para verificação completa
      printf("Matriz X (gerada no processo %d):\n", world_rank);
      for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
          printf("%f ", matrizX[i * coluna + j]);
        }
        printf("\n");
      }
      printf("\n");

      // Exibe a matriz Y para verificação completa
      printf("Matriz Y (gerada no processo %d):\n", world_rank);
      for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
          printf("%f ", matrizY[i * coluna + j]);
        }
        printf("\n");
      }
      printf("============================================\n");
  }

  // Distribui partes da matriz X e Y para os processos
  MPI_Scatterv(matrizX, sendcounts, displs, MPI_FLOAT, sub_matrizX, sendcounts[world_rank], MPI_FLOAT, 0, MPI_COMM_WORLD);
  MPI_Scatterv(matrizY, sendcounts, displs, MPI_FLOAT, sub_matrizY, sendcounts[world_rank], MPI_FLOAT, 0, MPI_COMM_WORLD);
  MPI_Barrier(MPI_COMM_WORLD);


  // Soma local das submatrizes X e Y (parte paralela)
  for (int i = 0; i < sendcounts[world_rank]; i++) {
    sub_matrizResultante[i] = sub_matrizX[i] + sub_matrizY[i];
  }

  /*
  // Depuração: Exibir o que cada processo recebeu
  printf("Processo %d recebeu %d elementos de matrizX e matrizY:\n", world_rank, sendcounts[world_rank]);
  printf("Submatriz X (Processo %d):\n", world_rank);
  for (int i = 0; i < sendcounts[world_rank]; i++) {
    printf("%f ", sub_matrizX[i]);
  }
  printf("\n\n");

  printf("Submatriz Y (Processo %d):\n", world_rank);
  for (int i = 0; i < sendcounts[world_rank]; i++) {
    printf("%f ", sub_matrizY[i]);
  }
  printf("\n\n");

  printf("Submatriz Resultante (Processo %d):\n", world_rank);
  for (int i = 0; i < sendcounts[world_rank]; i++) {
    printf("%f ", sub_matrizResultante[i]);
  }
  printf("\n=================================================\n");
  */
  
  // Processo 0 vai reunir os resultados
  float *matrizResultante = NULL;
  if (world_rank == 0) {
    matrizResultante = (float *)malloc(total_elementos * sizeof(float));
  }

  MPI_Gatherv(sub_matrizResultante, sendcounts[world_rank], MPI_FLOAT, matrizResultante, sendcounts, displs, MPI_FLOAT, 0, MPI_COMM_WORLD);
  if (world_rank == 0) {
    printf("Matriz Resultante (X + Y) no processo 0:\n");
    for (int i = 0; i < linha; i++) {
      for (int j = 0; j < coluna; j++) {
        printf("%f ", matrizResultante[i * coluna + j]);
      }
      printf("\n");
    }
  }

  // Libera memória
  if (world_rank == 0) {
    free(matrizX);
    free(matrizY);
    free(matrizResultante);
  }

  free(sub_matrizX);
  free(sub_matrizY);
  free(sub_matrizResultante);
  free(sendcounts);
  free(displs);

  MPI_Barrier(MPI_COMM_WORLD);
  MPI_Finalize();

  return 0;
}
