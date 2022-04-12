#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

static int N = 500;

void random(double A[N][N]){
    for (int i = 0; i < N; i++)
    {
        
        for (int k = 0; k < N; k++)
        {
            A[i][k] = rand() % 100;           
        }
        
    }

}

void print(double A[N][N]){
    for (int i = 0; i < N; i++)
    {
        
        for (int k = 0; k < N; k++)
        {
            printf("%lf ",A[i][k]);
        }
        printf("\n");
        
    }

}
double max(double B[]){
    double max = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        //printf("%d ",B[i]);
        if(B[i] > max){
            max = B[i];
        }
    }
    return max;
    
}

void infnorm(double A[N][N]){
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

    printf("The matrixes infinity norm is: %lf\n",max(B));
    
}

int main(){

    double A[N][N];

    srand(time(NULL));

    random(A);

    //print(A);

    clock_t start,end;
    double time_taken;

    start = clock();

    infnorm(A);

    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Matrix size: %d, time taken: %lf",N,time_taken);

    return 0;
}