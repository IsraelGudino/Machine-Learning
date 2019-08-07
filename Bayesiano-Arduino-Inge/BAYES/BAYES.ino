#include "datos.h"
float test [5] ={6.6,2.9,4.6,1.3,2};
// 3 etiquetas 
// 30 datos por etiqueta
float prob_x;
float dist;
float dist_mayor=0.1;
int col=0;
int col1=0;
int fil=0;
float aux=0;
int i=0;
int etiqueta=0;
int resultado;
//////////////////////////////////////////////
//P(x)
//|1|2|3| -> etiquetas
//|2|1|0| -> contador de etiquetas en el círculos
float cont_x [2][3];
////////////////////////////////////////
//P(etiqueta)
//|1  |2  |3  |
//|0.3|0.3|0.3|
float prob_prio [2][3];
/////////////////////////////////////
//P(x/etiqueta)
// |1  |2  |3  |
// |0.2|0.5|0.3|
float pro[2][3];
/////////////////////////////////////
//vector numero total por cada etiquetas
float total_eti[2][3];
// |1  |2  |3  |
// |30 |30 |30 |
/////////////////////////
//vector de resultados
float bayes [3];

///////////////////////
void setup() {
Serial.begin(9600);
 //llenar vectores con etiquetas 
 for(;col<3;col++){
    pro[0][col]= col+1;
    prob_prio[0][col]= col+1;
    cont_x[0][col]= col+1;
     total_eti [0][col]= col+1;
  }
  col=0;
  //metodo para contar el numero de elementos por etiqueta
    for(;col<3;col++){
       for(fil=0;fil<90;fil++){
          if(matriz[fil][4]==total_eti[0][col]){
            total_eti[1][col]=aux++;
          }
      }
      aux=0;
  }
   col=0;
   fil=0;
   // se calcula la probabilidad de cada etiqueta
   for(;col<3;col++){
     prob_prio[1][col]=total_eti[1][col]/90;
    }
 
  col=0;
  aux=0;
  fil=0;
}

void loop() {
  // distancia entre la nueva instancia y el conjunto de entrenamiento
    for(;fil<90;fil++){
       for(col=0;col<4;col++){
          dist= dist+pow(matriz[fil][col]-test[col],2);
        }
        dist=sqrt(dist);
        //se elije a la distancia mayor 
        if(dist>dist_mayor){
          dist_mayor=dist;
        }
        dist=0;
      }
      // se realiza la distancia pero ahora se divide para el número mayor y normalizar 
      for(fil=0;fil<90;fil++){
        for(col=0;col<4;col++){
            dist= dist+pow(matriz[fil][col]-test[col],2);
          }
          dist=sqrt(dist);
          dist=dist/dist_mayor;
          //rango de la circunferencia para eleccion de datos cercanos a la nueva instancia
          if(dist<0.17){
              aux++;
           // se almacena el numero de datos por etiqueta que se encuentran dentro del círculo   
              for(col1=0;col1<3;col1++){
                   if(matriz[fil][4]==cont_x[0][col1])
                     cont_x[1][col1]++;
                }
            }
      }
      col=0;

    // se realiza la probabilidad de cada etiqueta para asignarlas en un vector      
      for(;col<3;col++){
        //por cuestiones de programación, si no se cuenta con datos de etiqueta dentro 
        //del círculo se pone probabilidad de cero
         if(cont_x[1][col]==0){
           bayes[col]=0;
          }
          else{
            // formula de bayes
            bayes[col]=(cont_x[1][col]/total_eti[1][col]*(prob_prio[1][col]))/(aux/90); ////
          }
        }
       // se determina la etiqueta que tenga la mayor probabilidad variables co i y j
       for(;i<3;i++){
                if(bayes[i]>etiqueta){
                 etiqueta=bayes[i]; 
                 resultado=cont_x[0][i];
                }  
        }
        Serial.print("Etiqueta:");
        Serial.println(resultado);
       delay(5000);
}
