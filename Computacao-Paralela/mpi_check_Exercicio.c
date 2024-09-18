#include <mpi.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  MPI_Init(NULL, NULL);
  const int MAX_NUMBERS = 2000;

  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

  if (world_rank == 0) {
    srand(time(NULL));
    int vector[MAX_NUMBERS];
    for(int slave = 1; slave < world_size; slave++) {
      int size = (rand() % (1000 + 1)) + 1000;
      int expected_summatory = 0;

      for (int index = 0; index < size; index++) {
        int random_number = (int)(rand() % (99 + 1));
        vector[index] = random_number;
        expected_summatory += random_number;
      }

      printf("O somatorio esperado do slave %d é %d. \n", slave, expected_summatory);
      MPI_Send(vector, size, MPI_INT, slave, 0, MPI_COMM_WORLD);
    }

    for (int slave = 1; slave < world_size; slave++) {
      int temp;
      MPI_Status status;
      MPI_Recv(&temp, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
      

      printf(" O mestre recebeu o somatório %d. \n", temp, 0);

    }

  } else {
    MPI_Status status;
    int numbers[MAX_NUMBERS];
    int size;

    MPI_Recv(numbers, MAX_NUMBERS, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
    MPI_Get_count(&status, MPI_INT, &size);
    
    int summatory = 0;

    for(int index = 0; index < size; index++) {
      summatory += numbers[index]; 
    }

    MPI_Send(&summatory, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
  }

MPI_Finalize();
}