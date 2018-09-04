#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
/*
AUTOR: CHRISTIÁN F. H. LÓPEZ CHÁVEZ
DESCRIPCIÓN: RELLENAR MATRIZ
FECHA: 17/08/2018
*/
using namespace std;
void MATRIZ(int M[][8]){
  int i,j;
  for(i=0;i<9;i++){
    for(j=0;j<9;j++){
      M[i][j] = 0;
    }
  }
}
void MOSTRAR(int M[][8]){
  int i,j;
  for(i=0;i<9;i++){
    for(j=0;j<9;j++){
      cout << M[i][j];
    }
    cout << endl;
  }
}
void MOSTRARF(int A[],int H){
  int i;
  for(i=0;i<H;i++){
    cout << A[i];
  }
  cout << endl;
}
void AGREGAR(int M[][8],int F[],int C[],int V[],int X){
  int i;
  for(i=0;i<X;i++){
    M[F[i]][C[i]]=V[i];
  }
}
int main(int argc, char** argv){
  int SUDOKU[8][8];
  MATRIZ(SUDOKU);
  int X, i, Y=0;
  //CONTAMOS EL LARGO DE LOS CARACTERES
  int LARGO = strlen(argv[1]);
  //CANTIDAD DE NUMEROS A AGREGAR
  int CANT = LARGO/7;
  //NUMERO DE DIGITOS
  int XXX = (3*CANT)-1;
  //ARREGLO DE LOS NUMEROS
  int NUM[XXX];
  char ARREGLO[LARGO-1];
  //PASAMOS LOS CARACTERES A UN ARREGLO
  strcpy(ARREGLO,argv[1]);
  //RECORREMOS EL ARREGLO
  for(i=0;i<LARGO;i++){
    if (ARREGLO[i]>47 && ARREGLO[i]<58){
      int X = ARREGLO[i] - 48;
      NUM[Y] = X;
      Y++;
    }
  }
  int FILAS[CANT-1];
  int COLUM[CANT-1];
  int VALOR[CANT-1];
  int F=0, C=0, V=0;
  for(i=0;i<=XXX;i=i+3){
    FILAS[F] = NUM[i];
    F++;
  }
  for(i=1;i<=XXX;i=i+3){
    COLUM[C] = NUM[i];
    C++;
  }
  for(i=2;i<=XXX;i=i+3){
    VALOR[V] = NUM[i];
    V++;
  }
  AGREGAR(SUDOKU,FILAS,COLUM,VALOR,CANT);
  MOSTRAR(SUDOKU);
}
