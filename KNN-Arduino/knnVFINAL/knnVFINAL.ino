#include "funcionesKNN.h"
#include "dataset.h""
#include "prueba.h"
double dato[co];
void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("Clasificación con KKN");
  delay(500);
  Serial.println("Calculando exactitud del algoritmo");
  obtieneMejorK();
}
void loop() {
}
// Calcula la exactitud del algoritmo KNN dada un valor a k 
double calculaExactitud(int k){
  int i, j, cl;
  int buenos = 0, malos = 0;
  double exactitud = 0;
  double dato2[co];
  for(i=0; i<fi2; i++){
    for(j=0; j<co2; j++){
      // extraer un dato de prueba.h
      dato2[j] = atributos2[i][j];
    }  
    // clasificarlo
    cl = clasificaKNN((double*)atributos, clasesNo, dato2, k, fi, co);
    // comparar la clase
    if(cl == clasesNo2[i]){
      buenos = buenos + 1;  
    }
    else{
      malos = malos + 1;  
    }
  }
  exactitud = ((double)buenos/(double)fi2)*100;
  Serial.println("--");
  Serial.print("k = "); Serial.print(k); 
  Serial.print(", Aciertos: "); Serial.print(buenos);
  Serial.print(", Errores: "); Serial.print(malos);
  Serial.print(", Exactitud = "); Serial.println(exactitud,1);
  return exactitud; 
}
// Calcula la k que proporciona mejor exactitud
void obtieneMejorK(){
  double exactitudTemp = 0, exactitud = 0;
  int kTemp = 1, k = 1;  
// calcular todas la exactitud con la que clasifica variando k 
  for(int k=1; k<10; k++){
    exactitud = calculaExactitud(k); 
    if(exactitud > exactitudTemp){
        exactitudTemp = exactitud;
        kTemp = k;
    }      
  }
  Serial.println("Mejor k: "); Serial.println(kTemp);
  Serial.println("Exactitud: "); Serial.println(exactitudTemp);
}
