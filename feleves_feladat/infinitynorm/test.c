#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix_operations.h"

void infnorm(Matrix *matrix){
    int N = matrix->N;
    double* B = (double *)malloc(N*sizeof(double));
    double seged = 0;
    
    for (int i = 0; i < N; i++)
    {
        seged = 0;
        for (int j = 0; j < N; j++)
        {
            seged += abs(matrix->data[i][j]);
        }
        B[i] = seged;
    }

    printf("The matrixes infinity norm is: %lf\n",max(B,N));
    
}

int main()
{
  Matrix matrix;

  int size = 17000;
  alloc_matrix(&matrix,size,size);
  srand(time(NULL));

  //randomfill_matrix(&matrix);
  
  matrix.data[size-1][size-1] = 23.0;

  printf("%lf",matrix.data[size-1][size-1]);

  //infnorm(&matrix);


  return 0;
}