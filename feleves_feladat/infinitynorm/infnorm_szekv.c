#include "matrix_operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>

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
    free(B);
    
}

int main(){

    int range = 39;

    int measures[39] = {100,200,300,400,500,600,700,800,900,1000,1500,2000,2500,3000,3500,4000,4500,5000,5500,6000,6500,7000,7500,8000,8500,9000,9500,10000,10500,11000,11500,12000,12500,13000,13500,14000,14500,15000,15500};

    for (int i = 0; i < range; i++)
    {
        Matrix matrix;

        int size = measures[i];

        alloc_matrix(&matrix,size,size);

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

        printf("Matrix size: %d, time taken: %lf\n",N,time_taken);

        //File that contains data: matrix size, time_taken

        FILE *fp;
        fp = fopen("data.csv","a+");

        fprintf(fp,"%d %d %lf\n",0,N,time_taken);

        fclose(fp);

        free_matrix(&matrix);
    }

    return 0;
}