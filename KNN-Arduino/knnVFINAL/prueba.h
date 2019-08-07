//Dataset de test

const int fi2 = 10; // numero de filas de la BD
const int co2 = 5; // numero de columnas (atributos o datos)

// atributos: conjunto de entrenamiento
double atributos2[fi2][co2] = {
{0,24.78,27.9,18.2,5.04152},
{0,26.89,27.68,20.15,7.5119},
{0.61,25.82,27.4,18.99,10.5119},
{0.42,24.92,27.32,17.92,10.7935},
{0,24.88,27.76,19.02,10.7935},
{1.51,28.21,26.91,25.97,11.3358},
{2.11,27.8,27.03,15.61,10.7935},
{1.6,27.6,28.13,16.19,8.63134},
{1.59,27.49,28.78,16.62,11.068},
{1.91,28.14,26.74,15.17,9.61769}};

/*clases de la base de datos 
No presencia de alchohol=0,Presencia de alcohol=1
*/
int clasesNo2[fi2] = {
0,
0,
0,
0,
0,
1,
1,
1,
1,
1};
