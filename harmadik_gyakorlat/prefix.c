#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void szekvencialis(int* tomb,int* sztomb){
	int sum=0;
	
	for(int i = 0; i < N; i++){
		if(i==N){
			return;
		}
		sum += tomb[i];
		sztomb[i]=sum;
	}
}
void crew_prefix(int* tomb,int* crewtomb,int a, int b){
	int i,k;
	
	if(a==b){
		crewtomb[a]=tomb[a];
		return ;
	}else{
		k=(a+b)/2;
		crew_prefix(tomb,crewtomb,a,k);
		crew_prefix(tomb,crewtomb,k+1,b);
		for(i=k+1;i<=b;i++){
			crewtomb[i]+=crewtomb[k];
		}
	}
}
void kiir(int* tomb){
	for(int i = 0; i < N; i++){
		printf("%d ",tomb[i]);
	}
	printf("\n");
}


int main(){

    int tomb[N] = {2,4,1,6,3,5,9,7,8,0};
    int sztomb[N],crewtomb[N];

    szekvencialis(tomb,sztomb);

    crew_prefix(tomb,crewtomb,0,N-1);

    kiir(sztomb);
    kiir(crewtomb);
    printf("\n%d,%d,%d",tomb[N-1],crewtomb[N-1]);

    return 0;
}