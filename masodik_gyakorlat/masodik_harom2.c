#include <stdio.h>
void monoton(int tomb[]);
int main(){

    int tomb[10] = {1,2,3,4,2,6,7,8,9,10};

    monoton(tomb);


    return 0;
}
void monoton(int tomb[]){
    int valto = 0;
    for (int i = 0; i < 10 - 1; i++)
    {
        if(tomb[i + 1] < tomb[i]){
            valto = 1;
        }
    }
    if(valto){
        printf("Nem Monoton novekvo!");
    }
    else{
        printf("Monoton novekvo!");
    }
    
}