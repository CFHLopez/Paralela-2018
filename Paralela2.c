#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv){

  int tamano, procesador;
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD, &tamano); //obtenemos el tamano
  MPI_Comm_rank(MPI_COMM_WORLD, &procesador); //captura el rank

  int numero;
  if (procesador == 0){
    numero = 9;
    for(int receptor=1;receptor<tamano;receptor++){
      MPI_Send(&numero, 1, MPI_INT, receptor, 0, MPI_COMM_WORLD);
      //dato,contador,tipo de dato, quien lo recibe
    }
  }
  else if (procesador != 0){
    int proc = 0;
    for(int rec=1;rec<tamano-1;rec++){
      MPI_Recv(&numero, rec, MPI_INT, proc, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      printf("procesador %d recv numero %d desde el procesador 0 \n", rec, numero);
    }
  }
  MPI_Finalize();
}
