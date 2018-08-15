#include <iostream>
#include <fstream>
#include <sstream>
#include <mpi.h>
/*
AUTOR: CHRISTIÁN F. H. LÓPEZ CHÁVEZ
DESCRIPCIÓN: INTENTO DE PARALELIZAR
FECHA: 15/08/2018
*/
using namespace std;
int main(int argc, char* arg[]){
  //cambiar a "utem.csv" para pruebas
  ifstream infile(argv[1]);
  string LINEAS;
  MPI_Status status;

  int PROCESADOR;
  int TAMANO;
  int CONTADOR = 0;
  int NUMERO;

  MPI::Init();
  //TOMAMOS EL PROCESADOR QUE SE ESTA USANDO
  PROCESADOR = MPI::COMM_WORLD.Get_rank();
  //TOMAMOS EL N° DE PROCESADORES
  TAMANO = MPI::COMM_WORLD.Get_size();
  if(PROCESADOR == 0){
    //CONTAMOS EL N° DE LINEAS DEL ARCHIVO
    while(getline(infile, LINEAS)){
      CONTADOR++;
    }
    NUMERO = CONTADOR/TAMANO;
    cout << "LINEAS TOTALES = " << CONTADOR << endl;
    cout << "EL PROCESADOR 0 CONTO " << NUMERO + (CONTADOR-(NUMERO*TAMANO)) << " LINEAS." << endl;
    for(int X = 1; X < TAMANO; X++){
        MPI_Send(&NUMERO,1,MPI_INT,X,0,MPI_COMM_WORLD);
    }
  }
  else if(PROCESADOR != 0){
    MPI_Recv(&NUMERO,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    cout << "EL PROCESADOR " << PROCESADOR << " CONTO " << NUMERO << " LINEAS." << endl;
  }
  MPI_Finalize();
}
