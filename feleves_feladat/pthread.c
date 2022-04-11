#include <stdio.h>
#include <stdlib.h>

#define N 3

void solution( float a[N][N+1], int var )
{
    int k, i, l, j;
 
    for ( k = 0;k < var;k++ )
    {
        for ( i = 0;i <= var;i++ )
        {
            l = a[ i ][ k ];
 
            for ( j = 0;j <= var;j++ )
            {
                if ( i != k ){
                    a[i][j] = (a[k][k]*a[i][j])-(l*a[k][j]);
                    //printf("%f=(%f*%f)-(%f*%f) hiba%d",a[i][j],a[k][k],a[i][j],l,a[k][j],i);
                    //printf("pozicio: %d %d k:%d\n",i,j,k);
                }
            }
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j <= N; j++)
                {
                    printf("%f ",a[i][j]);
                }
                printf("\n");
        
            }
            
        }
        printf("---------------------------------------\n");
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            printf("%f ",a[i][j]);
        }
        printf("\n");
        
    }
 
    printf( "\nSolutions:" );
 
    for ( i = 0;i < var;i++ )
    {
        printf( "\nTHE VALUE OF x%d IS %f\n", i + 1,a[ i ][ var ] /a[ i ][ i ] );
    }
 
}

int main(){
    float matrix[N][N+1] = {{1,1,-1,7},{1,-1,2,3},{2,1,1,9}};

    float x[N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            printf("%f ",matrix[i][j]);
        }
        printf("\n");
        
    }
    solution(matrix,3);
      


    return 0;
}
