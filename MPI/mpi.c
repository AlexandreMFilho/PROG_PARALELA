#include<stdio.h>
#include<mpi.h>

int main(int argc, char ** argv){

int numtask, rank, rc;

rc = MPI_Init(&argc,&argv);
//Teste Segurança
if(rc != MPI_SUCCESS){
    printf("Error start MPI Program. Terminating..\n");
    MPI_Abort(MPI_COMM_WORLD,rc);
}
MPI_Comm_size(MPI_COMM_WORLD,&numtask);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
printf("Numero de task:%d Meu Ranking:%d\n",numtask,rank);
    printf("Hello");
MPI_Finalize();
return 0;

}

//Compilar MPI - mpicc mpi.c -o saida.out

//Rodar MPI    - mpirun ./saida.out

//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
