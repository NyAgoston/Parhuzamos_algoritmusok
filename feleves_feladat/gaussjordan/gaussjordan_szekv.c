#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix_operations.h"

void gauss_jordan_solver(Matrix *matrix){
    int N = matrix->N;

    double *X = (double *)malloc(matrix->N*sizeof(double));
    for (int k = 0; k <= N-1; k++)
    {
        for (int i = 0; i <= N-1; i++)
        {
            if (k != i)
            {
                for (int j = k +1 ; j <= N; j++)
                {
                    matrix->data[i][j] = matrix->data[i][j] - (matrix->data[i][k] / matrix->data[k][k]) * matrix->data[k][j];
                }
                
            }
            
        }
        
    }
    for (int i = 0; i <= N-1; i++)
    {
        X[i] = matrix->data[i][N] / matrix->data[i][i];
    }

    for (int j = 0; j <= N-1; j++)
    {
       //printf( "\nTHE VALUE OF x%d IS %lf\n",j + 1,X[j]);
    }
    free(X);
}
int main(){

    int range = 30;

    int measures[30] = {100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,2500,2600,2700,2800,2900,3000};

    for (int i = 0; i < range; i++)
    {
        Matrix matrix;

        int col = measures[i];

        int row = col + 1;

        alloc_matrix(&matrix,col,row);

        int N = matrix.N;

        double X[N];

        srand(time(NULL));

        randomfill_matrix(&matrix);
        
        //print_matrix(&matrix);
        clock_t start,end;
        double time_taken;

        start = clock();

        gauss_jordan_solver(&matrix);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Matrix size: %d, time taken: %lf\n",N,time_taken);

        FILE *fp;
        fp = fopen("data.csv","a");

        fprintf(fp,"%d %d %lf\n",1,N,time_taken);

        fclose(fp);
        

        free_matrix(&matrix);
    }
    

    

    return 0;
}
