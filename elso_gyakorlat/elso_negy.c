#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
int main() {
   
    srand(time(NULL)); 

    int szam = (rand() % (1000 - 500 + 1)) + 500;

    printf("%d\n",szam);
    // random 10 es 100 kozott
    float lebego = ((float)rand()/RAND_MAX)*(float)(100.0);

    printf("%lf",lebego);



    return 0;
}
