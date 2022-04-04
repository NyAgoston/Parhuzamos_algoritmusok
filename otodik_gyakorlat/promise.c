#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

struct promise{
	int eredmeny;
	bool van_eredmeny;
};
typedef struct promise Promise;

bool has_value(Promise* elso);

int get_value(Promise* elso);

int set_value(Promise* elso);

int main(){


    Promise elso;
    elso.eredmeny = -1;
    elso.van_eredmeny = false;


    bool valto = true;
    while(valto == true){
        
        if(get_value(&elso) == -1){
            printf("Meg nincs eredmeny!\n");
        }
        srand(time(NULL));
        int r = rand() % 6 + 1;
        printf("Random: %d\n",r);
        if(r == 1){
            set_value(&elso);
        }
        printf("Ujra probalkozas 3mp mulva:\n");
        for(int i = 0; i < 3; i++)
        {
            printf("%d\n",i + 1);
            sleep(1);
        }
        if(has_value(&elso) == true){
            valto = false;
        }
        
        
    }
    printf("Az eredmeny: %d",get_value(&elso));

   
    return 0;
}
bool has_value(Promise* elso){
	if(elso->eredmeny == -1){
		return false;
	}
	return true;
}

int get_value(Promise* elso){
	if(elso -> van_eredmeny == false){
		return -1;
	}
	return elso -> eredmeny;
}

int set_value(Promise* elso){
    elso->eredmeny = 2022;
}
