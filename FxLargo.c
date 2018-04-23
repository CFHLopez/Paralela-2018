#include <stdio.h>
#include <mpi.h>
//nuevo
#include <stdlib.h>

//funcion contar
int contar (char* nombre){
  FILE *entrada;
  int ch, lineas;

  if ((entrada = fopen(nombre, "r")) == NULL){
     perror(nombre);
     return EXIT_FAILURE;
  }
  lineas = 0;
  while ((ch = fgetc(entrada)) != EOF){
     if (ch == '\n')
        lineas++;
  }
  fclose(entrada);
  printf("N° DE LINEAS: %d\n", lineas - 1);

  return EXIT_SUCCESS;
}

int main(int argc, char** argv){

  int tamano, procesador;
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD, &tamano); //obtenemos el tamano
  MPI_Comm_rank(MPI_COMM_WORLD, &procesador); //captura el rank
  
  contar("utem.csv");
  return 0;

  MPI_Finalize();
}
