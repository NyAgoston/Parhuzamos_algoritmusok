#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MERET 1000000

void *paros_paratlan(int* tomb){
    int paros = 0;
    int paratlan = 0;
    for (int i = 0; i < MERET; i++)
    {
        if(tomb[i] %2 == 0){
            paros += 1;
        }
        else{
            paratlan += 1;
        }
    }
    printf("Paros elemek szama: %d\n",paros);
    printf("Paratlan elemek szama: %d\n",paratlan);
    return NULL;
}
void *zeros(int* tomb){
    int zeros = 0;
    
    for (int i = 0; i < MERET; i++)
    {
        if(tomb[i] == 0){
            zeros += 1;
        }
        
    }
    printf("Nullak szama: %d\n",zeros);
    return NULL;
}
void *negativ(int* tomb){
    int negativ = 0;
    
    for (int i = 0; i < MERET; i++)
    {
        if(tomb[i] < 0){
            negativ += 1;
        }
        
    }
    printf("negativ elemek szama: %d\n",zeros);
    return NULL;
}
void *intervallum(int* tomb){
    int intervallum = 0;
    
    for (int i = 0; i < MERET; i++)
    {
        if(tomb[i] < 50 & tomb[i] > 30){
            intervallum += 1;
        }
        
    }
    printf("30 es 40 koze eso elemek szama: %d\n",intervallum);
    return NULL;
}
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
    }

    printf("\n");

    pthread_t elso_id;
    pthread_t masodik_id;
    pthread_t harmadik_id;
    pthread_t negyedik_id;

    clock_t start, end;
    double cpu_time_taken;
    start = clock();

    pthread_create(&elso_id, NULL, paros_paratlan(tomb), NULL);
    pthread_create(&masodik_id, NULL, zeros(tomb), NULL);
    pthread_create(&harmadik_id, NULL, negativ(tomb), NULL);
    pthread_create(&negyedik_id, NULL, intervallum(tomb), NULL);
    pthread_join(elso_id, NULL);
    pthread_join(masodik_id, NULL);
    pthread_join(harmadik_id, NULL);
    pthread_join(negyedik_id, NULL);
    printf("Muvelet befejezve!");

    end = clock();
    cpu_time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Eltelt ido: %lf",cpu_time_taken); 

    exit(0);
}