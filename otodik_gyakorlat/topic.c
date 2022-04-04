#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int szamlalo = 1;

struct topic{
	char nev[100];
    char szoveg[100];
    int azonosito;
};
typedef struct topic Topic;

void subscribe(Topic* topic,char nev[]){
	strcpy(topic->nev,nev);
}

void publish(Topic* topic,char nev[]){
	strcpy(topic->nev,nev);
}

int main()
{

    Topic egy;
    Topic ketto;
    Topic harom;
    subscribe(&egy,"Alfonz");
    subscribe(&ketto,"Bela");
    subscribe(&harom,"Cila");

    publish(&egy,"Nagyon tetszik ez a Topic");
    publish(&egy,"Nekem annyira nem tetszik ez a topic");
    publish(&egy,"Elmegy ez a topic");
    
	
	return 0;
}