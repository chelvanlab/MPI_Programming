#include <mpi.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

    MPI_Init(&argc, &argv);

    int my_rank;
    MPI_Status status;

    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    time_t t;
    srand((unsigned)time(&t));
    
    // Root process generate 6 Random number send to other process
    for (int i = 0; i < 6; i++)
    {
        if (my_rank == 0)
        {

            int random_number = 1000 + rand() % 5000;

            MPI_Send(&random_number, 1, MPI_INT, 1, 99, MPI_COMM_WORLD);
            printf("process %d sent %d\n", my_rank, random_number);
        }
    }

    // The process receive the numbers and print in a line and multiply each numbers by 3 and send to root process
    for (int i = 0; i < 6; i++)
    {
        if (my_rank == 1)
        {
            int received_num;

            MPI_Recv(&received_num, 1, MPI_INT, 0, 99, MPI_COMM_WORLD, &status);
            printf("Re: - %d ", received_num);

            int scale_multiplay = received_num * 3;

            MPI_Send(&scale_multiplay, 1, MPI_INT, 0, 99, MPI_COMM_WORLD);
        }
    }

    // Receive 6 numbers multiply by 3
    for (int i = 0; i < 6; i++)
    {
        if (my_rank == 0)
        {
            int received_num;

            MPI_Recv(&received_num, 1, MPI_INT, 1, 99, MPI_COMM_WORLD, &status);
            printf("R-Re;- %d ", received_num);
        }
    }

    MPI_Finalize();

    return 0;
}