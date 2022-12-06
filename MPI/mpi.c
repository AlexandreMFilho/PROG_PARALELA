#include<stdio.h>
#include<mpi.h>

int main(int argc, char ** argv){

    int numtask, rank, rc, dest,source,tag=1,count;
    char outmsg, inmsg;
    MPI_Status stat;

    rc = MPI_Init(&argc,&argv);
    //Teste Segurança
    if(rc != MPI_SUCCESS){
        printf("Error start MPI Program. Terminating..\n");
        MPI_Abort(MPI_COMM_WORLD,rc);
    }
    MPI_Comm_size(MPI_COMM_WORLD,&numtask);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    if(rank == 0){
    dest = 1;
    source = 1;
    outmsg = 'x';
    MPI_Send(&outmsg,1,MPI_CHAR,dest,tag,MPI_COMM_WORLD);
    MPI_Recv(&inmsg,1,MPI_CHAR,source,tag,MPI_COMM_WORLD,&stat);
    }
    else{
    dest =0;
    source=0;
    outmsg='y';
    MPI_Recv(&inmsg,1,MPI_CHAR,source,tag,MPI_COMM_WORLD,&stat);
    MPI_Send(&outmsg,1,MPI_CHAR,dest,tag,MPI_COMM_WORLD);
    }

    MPI_Get_count(&stat,MPI_CHAR,&count);
    printf("Task:%d Recebeu%d char(s) da task %d with tag %d outmsg:%c inmsg:%c\n",rank,count,stat.MPI_SOURCE,stat.MPI_TAG,outmsg,inmsg);

    MPI_Finalize();
    return 0;

}

//Compilar MPI - mpicc mpi.c -o saida.out

//Rodar MPI    - mpirun ./saida.out

//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

//https://github.com/f2acode/jogo-da-vida
