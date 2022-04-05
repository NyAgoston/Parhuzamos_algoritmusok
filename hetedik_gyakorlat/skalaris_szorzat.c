#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define DIMENSION 100

int main(){
    int a_vektor[DIMENSION];
    int b_vektor[DIMENSION];
    srand(time(NULL));

    for (int i = 0; i < DIMENSION; i++)
    {
        int a,b;
        a = rand() % 100 + 1;
        b = rand() % 100 + 1;

        a_vektor[i] = a;
        b_vektor[i] = b;

        printf("a%d=%d,b%d=%d",i,a_vektor[i],i,b_vektor[i]);

    }
    printf("\n");
    

    int s = 0;

    for (int i = 0; i < DIMENSION; i++)
    {
        s += a_vektor[i] * b_vektor[i];
    }

    printf("A ket vektor skalaris szorzata: %d",s);
    





    return 0;
}