#include <stdio.h>
#include <time.h>
#include <stdlib.h>
double monoton_tomb(int tomb[], int index);
//((double) rand() / (RAND_MAX))
int main(){

    int tomb[10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        tomb[i] = monoton_tomb(tomb,i);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",tomb[i]);
    }
    
   
    return 0;
}
double monoton_tomb(int tomb[],int index){
    printf("Array: %d\n",tomb[index]);
    int elem = (rand() % (10000 - 10 + 1)) + 10;
    printf("Random: %d %d\n",elem,index);
    if(index == 0){
        return elem;
    }
    else if(tomb[index - 1] > elem){
        monoton_tomb(tomb,index);
    }
    else{
        printf("Visszaadott: %d %d\n",elem,index);
        printf("Tomb: %d %d\n",tomb[index -1],index -1);
        return elem;
        
    }
    
}