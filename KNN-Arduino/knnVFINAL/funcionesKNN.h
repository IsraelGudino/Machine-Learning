//Funciones para el cómputo del algoritmo KNN Se usa este archivo para poder llamar las funciones
//calculo de distancia euclidiana entre dos puntos
double distanciaEuclidiana(double pt1[], double pt2[], int co);
//calculo de distancia euclidiana entre un punto y la base de datos
void todasDistEuclid(double pt1[], double aux[], double *atributos, int fi, int co);
//Ordenamiento de las distancias de menor a mayor conservando clase 
void ordena(double datos[], int clases[], int clasesNo[], int fi);
//Extraer los N primeros
void extraeKPrimeros(double datos[], double kPrimeros[], int clases[], int kClases[], int k);                     
//Calcula la clase que más se repite
int claseMasFrecuente(int clases[], int k);
//Mapea una clase en valor entero a un string / Maps a class integer value to a string
char* obtieneClaseString(int claseint);
//Calcula la clase de un conjunto de atributos usando KNN
int clasificaKNN(double *datos, int clasesNum[], double dato[], int k, int fi, int co);

                     
