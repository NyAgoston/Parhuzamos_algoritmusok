#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>

void randomfill(double **A,int N){
    for (int i = 0; i < N; i++)
    {
        
        for (int k = 0; k < N; k++)
        {
            A[i][k] = rand() % 100;           
        }
        
    }

}

void print(double **A,int N){
    for (int i = 0; i < N; i++)
    {
        
        for (int k = 0; k < N; k++)
        {
            printf("%lf ",A[i][k]);
        }
        printf("\n");
        
    }

}
double max(double *B,int N){
    double max = DBL_MIN;
    for (int i = 0; i < N; i++)
    {
        //printf("%d ",B[i]);
        if(B[i] > max){
            max = B[i];
        }
    }
    return max;
    
}

void infnorm(double **A,int N){
    double B[N];
    double seged = 0;
    
    for (int i = 0; i < N; i++)
    {
        seged = 0;
        for (int j = 0; j < N; j++)
        {
            seged += abs(A[i][j]);
            //printf("Hozzadava: %d ",A[i][j]);
        }
        B[i] = seged;
        //printf("\n");
        //printf("Eredmen: %d ",B[i]);
        
    }

    printf("The matrixes infinity norm is: %lf\n",max(B,N));
    
}

int main(){

    int N = 10000;

    double **A = (double **)malloc(N*sizeof(double));
    for (int i = 0; i < N; i++)
    {
        A[i] = (double *)malloc(N*sizeof(double));
    }
    

    srand(time(NULL));

    randomfill(A,N);

    //print(A);

    clock_t start,end;
    double time_taken;

    start = clock();

    infnorm(A,N);

    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Matrix size: %d, time taken: %lf",N,time_taken);
    return 0;
}