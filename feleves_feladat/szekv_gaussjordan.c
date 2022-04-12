#include <stdio.h>
#include <stdlib.h>

void gauss_jordan(float matrix[3][4], int N){

    int pivot = 0;
    float l,seged;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            matrix[i][pivot] /= matrix[i][pivot];
            if(j > pivot){
                matrix[i][j] /= matrix[i][pivot];
            }
            for (int k = 0; k <= N; k++)
            {
                l = matrix[j+1][k] /= matrix[i][pivot];
                seged = matrix[i][pivot] * l * -1;
                matrix[j+1][k] += seged;
                //printf("%f ",matrix[j+1][k]);
            }
            
        }
        pivot++;
        
    }
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            printf("%f ",matrix[i][j]);
        }
        printf("\n");
        
    }
}

int main(){

    int N = 3;

    float matrix[3][4] = {{1,1,-1,7},{1,-1,2,3},{2,1,1,9}};

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            printf("%f ",matrix[i][j]);
        }
        printf("\n");
        
    }

    gauss_jordan(matrix,N);

    


    return 0;
}