#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    MPI_Init(NULL,NULL);

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    int number;
    number = world_rank;

    printf("Hello world from processor %s, rank %d out of %d processors\n",
     processor_name, world_rank, world_size);

    if(world_rank == 0){
        MPI_Ssend(&number, 1, MPI_INT, world_rank+1, 0, MPI_COMM_WORLD);
        MPI_Recv(&number, 1, MPI_INT, world_size-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }else{
        MPI_Recv(&number, 1, MPI_INT, world_rank-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Ssend(&number, 1, MPI_INT,(world_rank+1)%world_size, 0, MPI_COMM_WORLD);
        printf("Process %d received number %d from other process\n", world_rank, number);
    }

    MPI_Finalize();
}
