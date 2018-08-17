#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

/*
AUTOR: CHRISTIÁN F. H. LÓPEZ CHÁVEZ
DESCRIPCIÓN: RELLENAR MATRIZ
FECHA: 17/08/2018
*/
using namespace std;

int main(int argc, char** argv){
  int M = 9;
  int MATRIZ[M-1][M-1];
  int i,j;
  for (i=0;i<M;i++){
    for(j=0;j<M;j++){
      MATRIZ[i][j] = 0;
    }
  }
  //"[0;1;7][5;3;2][8;3;9]" <- SECUENCIA DE PRUEBA
  string A;
  string V;
  string CADENA;
  string CADENA2;
  string CADENA3;
  string FINAL;
  cout << "INGRESE SECUENCIA" << endl;
  cin >> A;
  stringstream stream(A);
  //QUITAMOS LAS COMILLAS
  while (getline(stream,V,'"')){
    if (V != ""){
      CADENA = CADENA + V;
    }
  }
  //QUITAMOS EL 1ER PARENTESIS CUADRADO
  stringstream hola(CADENA);
  while (getline(hola,V,'[')){
    if (V != ""){
      CADENA2 = CADENA2 + V;
    }
  }
  //QUITAMOS EL 2DO PARENTESIS CUADRADO
  stringstream ultimo(CADENA2);
  while (getline(ultimo,V,']')){
    if(V != ""){
      CADENA3 = CADENA3 + V;
    }
  }
  //QUITAMOS EL PTO Y COMA
  stringstream casi(CADENA3);
  while (getline(casi,V,';')){
    if(V != ""){
      FINAL = FINAL + V;
      //STRING DE PUROS NUMEROS
    }
  }
  //LARGO DEL STRING
  int LARGO = FINAL.size();
  //CHAR DE NUMEROS
  char NUMEROS[LARGO-1];
  //NUMEROS DEL STRING A CHAR
  strcpy(NUMEROS,FINAL.c_str());
  int CONTADOR = 0;
  int X,Y;
  for (i=0;i<LARGO;i++){
    //RESTAMOS -48 PARA PASAR DE ASCII A INT
    if (CONTADOR == 0){
      X = NUMEROS[i]-48;
      CONTADOR++;
    }
    if (CONTADOR == 1){
      Y = NUMEROS[i]-48;
      CONTADOR++;
    }
    if (CONTADOR == 2){
      CONTADOR = 0;
      MATRIZ[X][Y] = NUMEROS[i]-48;
    }
  }
  //MOSTRAMOS EL SUDOLU FINAL RELLLENADO
  for (i=0;i<M;i++){
    for(j=0;j<M;j++){
      cout << MATRIZ[i][j];
    }
    cout << endl;
  }
}
