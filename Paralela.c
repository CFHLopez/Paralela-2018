#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv){

  int tamano, procesador;
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD, &tamano); //obtenemos el tamano
  MPI_Comm_rank(MPI_COMM_WORLD, &procesador); //captura el rank
    //printf("hola mundo soy el rank %d\n", procesador);
    if( procesador%2 == 0){
      printf("hola mundo soy el procesador %d de %d\n", procesador, tamano);
    }

  MPI_Finalize();
}
