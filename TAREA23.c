#include <iostream>
#include <fstream>
#include <sstream>
#include <mpi.h>
/*
AUTOR: CHRISTIÁN F. H. LÓPEZ CHÁVEZ
DESCRIPCIÓN: CONTAR CARRERAS
FECHA: 15/08/2018
*/
using namespace std;
int main(int argc, char* arg[]){
  ifstream infile("utem.csv");
  string LINEAS;
  MPI_Status status;
  //PROCESADOR ACTUAL
  int PROCESADOR;
  //CANT DE PROCESADORES
  int TAMANO;
  //CONTADOR DE LINEAS
  int CONTADOR = 0;
  int N = 0;
  //NUMERO A ENVIAR
  int NUMERO;
  int CONT = 1;
  //ARREGLO CONTADOR DE CARRERAS
  int C[39];
  for (int i=0;i<40;i++){
    C[i]=0;
  }
  //CARRERAS
  string CA[39];
  CA[0] = "1 Ingeniería En Gestión Turistica";
  CA[1] = "21042 Ingeniería En Prevención De Riesgos Y Medio Ambiente";
  CA[2] = "21080 Ingeniería En Química";
  CA[3] = "21076 Ingenieria Civil Industria";
  CA[4] = "21031 Ingeniería En Geomensura";
  CA[5] = "21074 Ingenieria Civil En Obras Civiles";
  CA[6] = "21012 Contador Publico Y Auditor (diurno)";
  CA[7] = "21081 Ingeniería En Comercio Internacional";
  CA[8] = "21075 Ingenieria Civil Electrónica";
  CA[9] = "21046 Bachillerato En Ciencias De La Ingeniería";
  CA[10] = "21045 Ingeniería Industrial";
  CA[11] = "21043 Trabajo Social";
  CA[12] = "21037 Ingeniería En Mecánica";
  CA[13] = "21002 Bibliotecología Y Documentación";
  CA[14] = "21024 Diseño En Comunicacion Visual";
  CA[15] = "21087 Ingeniería Civil En Prev De Riesgos Y Medio Ambiente";
  CA[16] = "21048 Ingeniería Comercial";
  CA[17] = "21039 Ingeniería En Industria Alimentaria";
  CA[18] = "21030 Ingeniería En Informática";
  CA[19] = "21032 Ingeniería En Construcción";
  CA[20] = "21036 Ingeniería En Electrónica";
  CA[21] = "21041 Ingeniería Civil En Computación Menc Informática";
  CA[22] = "21023 Diseño Industrial";
  CA[23] = "21073 Ingenieria En Biotecnología";
  CA[24] = "21047 Arquitectura";
  CA[25] = "21083 Química Industrial";
  CA[26] = "21044 Ingeniería Civil Industrial Con Mención Sistemas De Gestión";
  CA[27] = "21096 Ingeniería Civil En Mecánica";
  CA[28] = "21071 Dibujante Proyectista";
  CA[29] = "21025 Ingeniería En Transporte Y Transito";
  CA[30] = "21015 Ingeniería En Administración Agroindustrial";
  CA[31] = "21004 Cartografía";
  CA[32] = "21088 Cartografía Y Geomática";
  CA[33] = "Contador Publico Y Auditor (vespertino)";
  CA[34] = "Magister En Trabajo Social Con Especialización En Competencias Para La Accion Socioeducativa";
  CA[35] = "Ingeniería Civil Industrial";
  CA[36] = "Magister En Tecnologia Nuclear";
  CA[37] = "8091 Magister En Politicas Publicas Y Seguridad Ciudadana";
  CA[38] = "Magister En Quimica Menciòn Tecnològica De Los Materiales";
  CA[39] = "OTROS";
  string VALOR;
  //ARREGLO
  string A[13786];
  //TOMAMOS EL PROCESADOR QUE SE ESTA USANDO
  MPI::Init();
    PROCESADOR = MPI::COMM_WORLD.Get_rank();
    //TOMAMOS EL N° DE PROCESADORES
    TAMANO = MPI::COMM_WORLD.Get_size();
    int P[TAMANO-1];
    if(PROCESADOR == 0){
      //CONTAMOS EL N° DE LINEAS DEL ARCHIVO
      while(getline(infile, LINEAS)){
        stringstream stream(LINEAS);
        while (getline(stream,VALOR,',')){
          CONTADOR++;
          //POSICION DEL CODIGO DE CARRERA MAS EL NOMBRE
          if (CONTADOR == 2){
            //METEMOS TODAS LAS CARRERAS EN UN ARREGLO STRING
            //LOS 13787 DATOS
            A[N] = VALOR;
            N++;
            CONTADOR = -1;
          }
        }
      }
      //CONTADOR COMIENZA EN UNO PARA SALTARSE EL "nombre carrera"
      for(int X=1;X<13787;X++){
        NUMERO = 39;
        //COMPARAMOS PARA MANDAR EN EL SEND UN NUMERO Y NO EL STRING
        if (A[X] == "1 Ingeniería En Gestión Turistica"){NUMERO=0;}
        if (A[X] == "21042 Ingeniería En Prevención De Riesgos Y Medio Ambiente"){NUMERO=1;}
        if (A[X] == "21080 Ingeniería En Química"){NUMERO=2;}
        if (A[X] == "21076 Ingenieria Civil Industria"){NUMERO=3;}
        if (A[X] == "21031 Ingeniería En Geomensura"){NUMERO=4;}
        if (A[X] == "21074 Ingenieria Civil En Obras Civiles"){NUMERO=5;}
        if (A[X] == "21012 Contador Publico Y Auditor (diurno)"){NUMERO=6;}
        if (A[X] == "21081 Ingeniería En Comercio Internacional"){NUMERO=7;}
        if (A[X] == "21075 Ingenieria Civil Electrónica"){NUMERO=8;}
        if (A[X] == "21046 Bachillerato En Ciencias De La Ingeniería"){NUMERO=9;}
        if (A[X] == "21045 Ingeniería Industrial"){NUMERO=10;}
        if (A[X] == "21043 Trabajo Social"){NUMERO=11;}
        if (A[X] == "21037 Ingeniería En Mecánica"){NUMERO=12;}
        if (A[X] == "21002 Bibliotecología Y Documentación"){NUMERO=13;}
        if (A[X] == "21024 Diseño En Comunicacion Visual"){NUMERO=14;}
        if (A[X] == "21087 Ingeniería Civil En Prev De Riesgos Y Medio Ambiente"){NUMERO=15;}
        if (A[X] == "21048 Ingeniería Comercial"){NUMERO=16;}
        if (A[X] == "21039 Ingeniería En Industria Alimentaria"){NUMERO=17;}
        if (A[X] == "21030 Ingeniería En Informática"){NUMERO=18;}
        if (A[X] == "21032 Ingeniería En Construcción"){NUMERO=19;}
        if (A[X] == "21036 Ingeniería En Electrónica"){NUMERO=20;}
        if (A[X] == "21041 Ingeniería Civil En Computación Menc Informática"){NUMERO=21;}
        if (A[X] == "21023 Diseño Industrial"){NUMERO=22;}
        if (A[X] == "21073 Ingenieria En Biotecnología"){NUMERO=23;}
        if (A[X] == "21047 Arquitectura"){NUMERO=24;}
        if (A[X] == "21083 Química Industrial"){NUMERO=25;}
        if (A[X] == "21044 Ingeniería Civil Industrial Con Mención Sistemas De Gestión"){NUMERO=26;}
        if (A[X] == "21096 Ingeniería Civil En Mecánica"){NUMERO=27;}
        if (A[X] == "21071 Dibujante Proyectista"){NUMERO=28;}
        if (A[X] == "21025 Ingeniería En Transporte Y Transito"){NUMERO=29;}
        if (A[X] == "21015 Ingeniería En Administración Agroindustrial"){NUMERO=30;}
        if (A[X] == "21004 Cartografía"){NUMERO=31;}
        if (A[X] == "21088 Cartografía Y Geomática"){NUMERO=32;}
        if (A[X] == "Contador Publico Y Auditor (vespertino)"){NUMERO=33;}
        if (A[X] == "Magister En Trabajo Social Con Especialización En Competencias Para La Accion Socioeducativa"){NUMERO=34;}
        if (A[X] == "Ingeniería Civil Industrial"){NUMERO=35;}
        if (A[X] == "Magister En Tecnologia Nuclear"){NUMERO=36;}
        if (A[X] == "8091 Magister En Politicas Publicas Y Seguridad Ciudadana"){NUMERO=37;}
        if (A[X] == "Magister En Quimica Menciòn Tecnològica De Los Materiales"){NUMERO=38;}
        //VERIFICAMOS SI EL CONT ESTA EN ALGUN PROCESADOR DISTINTO DE 0
        //PERO QUE NO SEA MAYOR A LA CANTIDAD DE PROCESADORES
        if (CONT == TAMANO){
          CONT = 1;
        }
        //ENVIAMOS EL NUMERO DE LA CARRERA
        MPI_Send(&NUMERO,1,MPI_INT,CONT,0,MPI_COMM_WORLD);
        CONT++;
      }
    }
    else if(PROCESADOR != 0){
      MPI_Recv(&NUMERO,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
      //CUENTA LA CANT. DE VECES QUE EL PROCESADOR ACTUA
      P[PROCESADOR]++;
      //CUENTA EL NUMERO DE VECES QUE LLEGA EL VALOR "NUMERO".
      C[NUMERO]++;
    }
    //MOSTRAMOS EL NOMBRE DE LA CARRERA MAS EL TOTAL DE VECES QUE SE ENCUENTA
    for (int i=0;i<40;i++){
      cout << "CARRERA: " << CA[i] << ", CANTIDAD: " << C[i] << endl;
    }
    //MOSTRAMOS LA CANTIDAD DE VECES QUE ACTIVO CADA PROCESADOR
    for (int i=1;i<TAMANO;i++){
      cout << "PROCESADOR " << i << " CONTO: " << P[i] << endl;
    }
  MPI_Finalize();
}
