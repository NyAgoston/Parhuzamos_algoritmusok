#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){

    int N = 10;
    int A[N];
    int R[N];
    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        A[i] = rand() % 100;
        printf("%d ",A[i]);
    }
    printf("\n");
    

    int i = 0;
    for (int c = N - 1; c >= 0; c--)
    {
        R[i] = c;
        i = A[i];
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ",R[i]);
    }
    
    
    


    return 0;
}