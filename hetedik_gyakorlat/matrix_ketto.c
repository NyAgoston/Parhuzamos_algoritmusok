#include <stdio.h>
#include <stdlib.h>

#define MATRIX_N 3
#define MATRIX_M 3

void parosak_szama(int matrix[3][3]);
void keresett_elem(int matrix[3][3], int n, int m);

int main(){
    int matrix[MATRIX_N][MATRIX_M] = {{2,2,4},{1,8,9},{3,4,1}};

    printf("Dejo");
    parosak_szama(matrix);
    
    printf("Adja meg a kivant koordinatakat:\n");
    int n,m;
    n = scanf("%d %d",&n,&m);
    printf("\n");

    printf("n=%d,m=%d",n,m);
    

    keresett_elem(matrix,n,m);

    
    return 0;
}

void parosak_szama(int matrix[3][3]){
    int parosok = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            if(matrix[i][k] %2 == 0){
                parosok += 1;
            }
        }
        
    }
    printf("Paros elemek szama: %d\n",parosok);
}

void keresett_elem(int matrix[3][3], int n, int m){
    
    printf("Keresett elem: %d",matrix[n][m]);
}

