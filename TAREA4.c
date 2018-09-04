#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
/*
AUTOR: CHRISTIÁN F. H. LÓPEZ CHÁVEZ
DESCRIPCIÓN: REVISAR SUDOKU
FECHA: 04/09/2018
*/
using namespace std;
//"[0;1;7][5;3;2][8;3;9]" <- SECUENCIA DE PRUEBA
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
void MOSTRAR_A(int A[],int H){
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
void R_FILA(int M[][8],int F,int V){
  int i;
  for (i=0;i<9;i++){
    if (M[F][i] == V){
      cout << "SE ENCUENTRA EL VALOR " << V << " EN LA FILA " << F << endl;
    }
  }
}
void R_COLU(int M[][8],int C,int V){
  int i;
  for (i=0;i<9;i++){
    if (M[i][C] == V){
      cout << "SE ENCUENTRA EL VALOR " << V << " EN LA COLUMNA " << C << endl;
    }
  }
}
void R_REGI(int M[][8],int R,int V){
  int i;
  if (R == 1){
    for (int i=0;i<3;i++){
      for (int j=0;j<3;j++){
        if (M[i][j] == V){
          cout << "EL VALOR " << V << " SE ENCUENTRA EN LA REGION " << R << endl;
        }
      }
    }
  }
  if (R == 2){
    for (int i=0;i<3;i++){
      for (int j=3;j<6;j++){
        if (M[i][j] == V){
          cout << "EL VALOR " << V << " SE ENCUENTRA EN LA REGION " << R << endl;
        }
      }
    }
  }
  if (R == 3){
    for (int i=0;i<3;i++){
      for (int j=6;j<9;j++){
        if (M[i][j] == V){
          cout << "EL VALOR " << V << " SE ENCUENTRA EN LA REGION " << R << endl;
        }
      }
    }
  }
  if (R == 4){
    for (int i=3;i<6;i++){
      for (int j=0;j<3;j++){
        if (M[i][j] == V){
          cout << "EL VALOR " << V << " SE ENCUENTRA EN LA REGION " << R << endl;
        }
      }
    }
  }
  if (R == 5){
    for (int i=3;i<6;i++){
      for (int j=3;j<6;j++){
        if (M[i][j] == V){
          cout << "EL VALOR " << V << " SE ENCUENTRA EN LA REGION " << R << endl;
        }
      }
    }
  }
  if (R == 6){
    for (int i=3;i<6;i++){
      for (int j=6;j<9;j++){
        if (M[i][j] == V){
          cout << "EL VALOR " << V << " SE ENCUENTRA EN LA REGION " << R << endl;
        }
      }
    }
  }
  if (R == 7){
    for (int i=6;i<9;i++){
      for (int j=0;j<3;j++){
        if (M[i][j] == V){
          cout << "EL VALOR " << V << " SE ENCUENTRA EN LA REGION " << R << endl;
        }
      }
    }
  }
  if (R == 8){
    for (int i=6;i<9;i++){
      for (int j=3;j<6;j++){
        if (M[i][j] == V){
          cout << "EL VALOR " << V << " SE ENCUENTRA EN LA REGION " << R << endl;
        }
      }
    }
  }
  if (R == 9){
    for (int i=6;i<9;i++){
      for (int j=6;j<9;j++){
        if (M[i][j] == V){
          cout << "EL VALOR " << V << " SE ENCUENTRA EN LA REGION " << R << endl;
        }
      }
    }
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
  R_FILA(SUDOKU,0,7);
  R_COLU(SUDOKU,3,2);
  R_REGI(SUDOKU,1,7);
}
