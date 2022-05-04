
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>
#include "matrix_operations.h"

volatile double *B,*X;
static Matrix A;

void allocate_matrixes(int size){
  for (int i = 0; i < size; i++)
  {  
    B = (double *)malloc(size*sizeof(double));
    X = (double *)malloc(size*sizeof(double));
  }
}
void initialize_matrixes(int size){
  for (int i = 0; i < size; i++)
  {
    B[i] = ((double)rand()*(100-10))/(double)RAND_MAX + 10;
    X[i] = 0.0;
  }
}

void gauss_jordan_omp(int N) {
  int norm, row, col;  
		
  float multiplier;

  for (norm = 0; norm < N - 1; norm++) {
    #pragma omp parallel for shared(A, B) private(multiplier,row,col)
    for (row = norm + 1; row < N; row++) {
      multiplier = A.data[row][norm] / A.data[norm][norm];
      for (col = norm; col < N; col++) {
	         A.data[row][col] -= A.data[norm][col] * multiplier;
      }
      B[row] -= B[norm] * multiplier;
    }
  }
  
  
  for (row = N - 1; row >= 0; row--) {
    X[row] = B[row];
    for (col = N-1; col > row; col--) {
      X[row] -= A.data[row][col] * X[col];
    }
    X[row] /= A.data[row][row];
  }
  /*
  for (int i = 0; i < N; i++)
  {
    printf( "\nTHE VALUE OF x%d IS %lf\n",i + 1,X[i]);
  }*/
  
}

int main(){

  int size = 10;

  alloc_matrix(&A,size,size);

  srand(time(NULL));

  randomfill_matrix(&A);

  allocate_matrixes(size);

  initialize_matrixes(size);

  clock_t start,end;
  double time_taken;
  
  start = clock();

  gauss_jordan_omp(size);

  end = clock();

  time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("Matrix size: %d, time taken: %lf",size,time_taken);
  print_matrix(&A);

  return 0;
}
