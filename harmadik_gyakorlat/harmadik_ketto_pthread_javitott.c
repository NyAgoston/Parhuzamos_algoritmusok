#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>
#include <time.h>

#define MERET 100
#define NUMOFTHREADS 10

static int summa;
static int* tomb;

void tomb_feltoltes();

struct arg_struct {
    int arg1;
    int* arg2;
	int summa;
	int paros;
	int nulla;
	int negativ;
    int paratlan;
}args;

void szamitasik(void* param1){
    int i;
    struct arg_struct *args = param1;
    i = args -> arg1;
	tomb = args -> arg2;
	for(; i < MERET ; i += NUMOFTHREADS){
		if(tomb[i] %2 == 0){
            args -> paros++;
        }else if(tomb[i] == 0){
            args -> nulla++;
        }else if(tomb[i] < 0){
            args -> negativ++;
        }else if(tomb[i] %2 != 0){
            args -> paratlan++;
        }
        summa += tomb[i];
	}
}

int main(int argc, char* argv[])
{
    srand(time(NULL));
    tomb = (signed int*) malloc(MERET * sizeof(signed int));

    tomb_feltoltes();

    int vparos, vparatlan, vnulla,vnegativ;

    pthread_t threads[NUMOFTHREADS];
    struct arg_struct args[NUMOFTHREADS];
    for(int i = 0;i < NUMOFTHREADS;i++){
		args[i].arg1 = i;
		args[i].arg2 = tomb;
		args[i].summa = 0;
		args[i].paros = 0;
		args[i].nulla = 0;
		args[i].negativ = 0;
        args[i].paratlan = 0;
		pthread_create(&threads[i], NULL, szamitasik, (void *)&args[i]);
	}
    for(int i = 0; i < NUMOFTHREADS;i++){
		pthread_join(threads[i], NULL);
	}
    for(int i = 0;i < NUMOFTHREADS;i++){
		vparatlan+=args[i].paratlan;
		vparos+=args[i].paros;
		vnegativ+=args[i].negativ;
		vnulla+=args[i].nulla;
	}
    printf("\nodd:%d\neven:%d\nzero:%d\nnegativ:%d\n",vparos,vparatlan,vnegativ,vnulla);
    
    return 0;
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