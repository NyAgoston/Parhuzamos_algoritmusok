#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void beker(int *also, int *felso);

int main() {
    int also;
    int felso;
     
    beker(&also,&felso);

    srand(time(NULL)); 

    int szam = (rand() % (felso - also + 1)) + also;

    printf("%d",szam);

    return 0;
}
void beker(int *also, int *felso){
    int jo_e;
    do
    {
        jo_e = 1;
        printf("Adja meg az intervallumot: \n");
        printf("also= ");
        if(scanf("%d", also) != 1)
        {
            jo_e = 0;
            printf("Rossz input!");
        }
        printf("felso= ");
        if(scanf("%d", felso) != 1 || *also > *felso)
        {
            jo_e = 0;
            printf("Rossz input!");
        }
        
        while(getchar() != '\n');
    }
    while(!jo_e);
    return;
}
      

