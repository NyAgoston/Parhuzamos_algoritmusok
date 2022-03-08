#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>
#include <time.h>
#define MERET 1000000

static int* tomb;

void tomb_feltoltes();

void *sum(void * vargp)
{
	int sum = 0;
    for (int i = 0; i < MERET; i++)
    {
        sum += tomb[i];
    }
    printf("A tomb osszege: %d\n",sum);
    
	return NULL;
}
void *parosparatlan(void *vargp){
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
void *zeros(void *vargp){
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
void *negativ(void *vargp){
    int negativ = 0;
    
    for (int i = 0; i < MERET; i++)
    {
        if(tomb[i] < 0){
            negativ += 1;
        }
        
    }
    printf("negativ elemek szama: %d\n",negativ);
    return NULL;
}
void *intervallum(void *vargp){
    int intervallum = 0;
    
    for (int i = 0; i < MERET; i++)
    {
        if(tomb[i] < -100 & tomb[i] > 100){
            intervallum += 1;
        }
        
    }
    printf("-100 es 100 koze eso elemek szama: %d\n",intervallum);
    return NULL;
}

int main()
{

    srand(time(NULL));
    tomb = (signed int*) malloc(MERET * sizeof(signed int));

    tomb_feltoltes();
    

	pthread_t summa;
    pthread_t paros_paratlan;
    pthread_t nullak;
    pthread_t negativ_szamok;
    pthread_t intervallumon_belul;


	printf("Before Thread\n");

    clock_t start, end;
    double cpu_time_taken;
    start = clock();

	pthread_create(&summa, NULL, sum, NULL);
    pthread_create(&paros_paratlan, NULL, parosparatlan, NULL);
    pthread_create(&nullak, NULL, zeros, NULL);
    pthread_create(&negativ_szamok, NULL, negativ, NULL);
    pthread_create(&intervallumon_belul, NULL, intervallum, NULL);

	pthread_join(summa, NULL);
    pthread_join(paros_paratlan, NULL);
    pthread_join(nullak, NULL);
    pthread_join(negativ_szamok, NULL);
    pthread_join(intervallumon_belul, NULL);

    end = clock();
    cpu_time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Eltelt ido: %lf\n",cpu_time_taken); 

	printf("After Thread\n");

    FILE *fp;
    fp = fopen("ketto_pthread.csv","a");
    fprintf(fp,"%d %lf\n",MERET,cpu_time_taken);
    fclose(fp);

	exit(0);
}

void tomb_feltoltes(){
    for (int i = 0; i < MERET; i++)
    {
        tomb[i] = rand()%500 + 1;
        int seged = rand()%2;
        if(seged == 0){
            tomb[i] *= -1;
        }
    
        //printf("%d ",tomb[i]);
    }
    printf("\n");
}
