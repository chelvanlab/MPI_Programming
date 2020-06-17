#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>

int count = 6;
int my_size;
int my_rank;
int p, q;

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &my_size);
    MPI_Status status;
    int *random_gen = new int[count];
    int *random_Mul = new int[count];
    if (my_rank == 0)
    {
        for (p = 1; p < my_size; p++)
        {
            for (q = 0; q < count; q++)
            {
                random_gen[q] = 1000 + rand() % 4000;
            }
            MPI_Send(random_gen, count, MPI_INT, p, 1, MPI_COMM_WORLD);
            MPI_Recv(random_Mul, count, MPI_INT, p, 1, MPI_COMM_WORLD, &status);
            printf("From the process %d to Root process : ", p);
            for (q = 0; q < count - 1; q++)
            {for (int i=0;i<6;i++){
        printf("%d ",gen_rendom[i]);
    }
                std::cout << random_Mul[q] << ' ';
            }
            std::cout << random_Mul[count - 1] << '\n';
        }
    }
    else
    {
        MPI_Recv(random_gen, count, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
        printf("From the Root process to process %d :", my_rank);
        for (p = 0; p < count - 1; p++)
        {
            std::cout << random_gen[p] << ' ';
        }
        std::cout << random_gen[count - 1] << '\n';
        for (p = 0; p < count; p++)
        {
            random_Mul[p] = random_gen[p] * 3;
        }
        MPI_Send(random_Mul, count, MPI_INT, 0, 1, MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}