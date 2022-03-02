#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MERET 1000000

void parameterek_sum(int* tomb);


int main(){
    int* tomb;
    int seged;
    int random;

    tomb = (signed int*) malloc(MERET * sizeof(signed int));

    
    srand(time(NULL));

    for (int i = 0; i < MERET; i++)
    {
        tomb[i] = rand()%1000 + 1;
        int seged = rand()%2;
        if(seged == 0){
            tomb[i] *= -1;
        }
    
        printf("%d ",tomb[i]);
    }

    printf("\n");
    

    clock_t start, end;
    double cpu_time_taken;
    start = clock();

    parameterek_sum(tomb);

    end = clock();
    cpu_time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Eltelt ido: %lf",cpu_time_taken);
    
    return 0; 
}

void parameterek_sum(int* tomb){
    int paros = 0;
    int paratlan = 0;
    int zeros = 0;
    int negativ = 0;
    int intervallum = 0;
    for (int i = 0; i < MERET; i++)
    {
        if(tomb[i] %2 == 0){
            paros += 1;
        }
        else{
            paratlan += 1;
        }
        if(tomb[i] == 0){
            zeros += 1;
        }
        else if(tomb[i] < 0){
            negativ += 1;
        }
        if(tomb[i] > 30 & tomb[i] < 40){
            intervallum += 1;
        }
    }
    printf("Paros elemek szama: %d\n",paros);
    printf("Paratlan elemek szama: %d\n",paratlan);
    printf("Nullak szama: %d\n",zeros);
    printf("Negativ elemek szama: %d\n",negativ);
    printf("30 es 40 koze eso elemek szama: %d\n",intervallum);
}


