#include <stdio.h>
#include <mpi.h>

/*
la idea es mandar desde el procesador 0 a todos los demas
procesadores los valores que tomamos con "ch" y en el caso de que el
procesador "x" encuentre que es "/n" se cuenta y retorna el valor final
*/

//

int contar (char* nombre, int tam, int proc){
  FILE *entrada;
  int ch, receptor;
  //inicializamos la cantidad de lineas a contar en cero
  int lineas = 0;
  //abrimos el archivo para contar sus lineas
  if ((entrada = fopen(nombre, "r")) == NULL){
     perror(nombre);
     return EXIT_FAILURE;
  }
  //forma iterativa de contar
  while ((ch = fgetc(entrada)) != EOF){
    if (procesador == 0){
      for (int receptor=0;receptor<tam;receptor++){
        MPI_Send(&ch,1,MPI_INT,receptor,0,MPI_COMM_WORLD);
      }
    }
    else if (proc != 0){
      for(int rec=1; rec<tam-1;rec++){
        MPI_Recv(&ch, rec, MPI_INT, 0,0,MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        if (ch == '\n'){
           lineas++;
        }
      }
    }
  }
  //para comunicaciones colectivas, manda mensajes desde todos los procesos a uno (proceso maestro)
  MPI_Reduce(sendbuf, recvbuf, count, datatype, op, root, comm);
  fclose(entrada);
  printf("N° DE LINEAS: %d\n", lineas - 1);

  return EXIT_SUCCESS;
}

int main(int argc, char** argv){

  int tamano, procesador;
  char nombre[20];
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD, &tamano); //obtenemos el tamano
  MPI_Comm_rank(MPI_COMM_WORLD, &procesador); //captura el MPI_Comm_rank
  printf("Introducir nombre del archivo ej: texto.txt");
  gets(nom);
  contar(nombre,tamano);

  MPI_Finalize();
}
