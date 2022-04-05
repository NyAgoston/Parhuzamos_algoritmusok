#include <stdio.h>
#include <stdlib.h>

#define MATRIX_N 3
#define MATRIX_M 3

int main(){

    int matrix[MATRIX_N][MATRIX_M] = {{1,0,0},{0,1,0},{0,0,1}};
    
    int flag = 0;
    int szamlalo = 0;
    for (int i = MATRIX_N; i < MATRIX_M; i++)
    {
        for (int k = MATRIX_N; k < MATRIX_M; k++)
        {
            printf("%d",matrix[i][k]);
            if(matrix[i][szamlalo] != 1){
                flag = 1;
            }
            
        }
        
        szamlalo += 1;
        printf("\n");
        
    }
    if(flag == 0){
        printf("A matrix egyegmatrix!");
    }else{
        printf("Nem egysegmatrix");
    }

    //diagonalis vagy nem

    int point = 0;
    for(int i = 0;i < MATRIX_N;i++)
    {
        for(int j = 0; j < MATRIX_M;j++)
        {
        if(i != j && matrix[i][j] != 0)
        {
            point=1;
            break;
        }
        }
    }
    if(point==1)
        printf("Nem diagonalis matrix");
    else
        printf("Diagonalis matrix");
    
   
    
    

    return 0;
}