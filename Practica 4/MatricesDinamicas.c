#include <stdio.h>
#include <stdlib.h>

void Print(int **m, int filas, int cols)
{
 int i, j;

 for(i=0; i< filas; i++){
  for(j = 0; j< cols; j++){
   printf("%d", m[i][j]);
 }
 printf("\n");
 }
}

int main(int argc, const char *argv[])
{
 int ** mat;
 //mat almacena la dirección de arreglos que guardan direcciones de entero

 int filas = 3;
 int cols = 3;
 // limites para las matrices mat

 int i, j;
 // contadores de proposito general

 mat=(int **) malloc(filas *sizeof(int **)); //1
 //se reservo la memoria para mat, pero esta aun no apunta a nda

 for(i=0; i<filas; i++){ //2
 mat[i] = (int *) malloc(cols * sizeof(int));
 }
 //cada slot de mat almacena la direccion de cada fila, calda fila.Cada fila tiene 'cols' slots

 //utilizamos a la matriz recién creada
 for(i=0; i<filas;i++){ //3
  for(j=0;j<cols;j++){
  mat[i][j]= 100 + 100 * j + 100 * i;
   //esta operacion es para obtener los mismos resultados que en el
   // ej1.c. lo importante es que estamos guardando valores enteros
  }
 }

 //imprimimos mat completa, otra vez utilizando notacion de matrices

 //for(i=0; i<filas; i++){
 // for(j=0; j<cols; j++){
  // printf("%d\t", mat[i][j]);
 // }
  // printf("\n");
 //}


 Print(mat, filas, cols);

 for(i=0; i<filas; i++){ //4
  free(mat[i]);
}
//se devvuelve la memoria que cada arreglo pidio

free(mat); //5
//se devuelve la memoria que el arreglo  mat pidio. No olvidar que mat es un arreglo
//cuyo cada elemento guarda la direccion de un apuntador.




}
