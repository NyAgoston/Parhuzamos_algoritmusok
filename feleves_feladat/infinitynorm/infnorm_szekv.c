#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>
#include "matrix_operations.h"

void infnorm(Matrix *matrix){
    int N = matrix->N;
    double B[N];
    double seged = 0;
    
    for (int i = 0; i < N; i++)
    {
        seged = 0;
        for (int j = 0; j < N; j++)
        {
            seged += abs(matrix->data[i][j]);
            //printf("Hozzadava: %d ",A[i][j]);
        }
        B[i] = seged;
        //printf("\n");
        //printf("Eredmen: %d ",B[i]);
        
    }

    printf("The matrixes infinity norm is: %lf\n",max(B,N));
    
}

int main(){

    Matrix matrix;

    alloc_matrix(&matrix,14000,14000);

    int N = matrix.N;

    srand(time(NULL));

    randomfill_matrix(&matrix);

    //print_matrix(&matrix);

    clock_t start,end;
    double time_taken;

    start = clock();

    infnorm(&matrix);

    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Matrix size: %d, time taken: %lf",N,time_taken);

    free_matrix(&matrix);

    //File that contains data: matrix size, time_taken

    FILE *fp;
    fp = fopen("data.csv","a+");

    fprintf(fp,"%d %d %lf\n",0,N,time_taken);

    fclose(fp);

    return 0;
}