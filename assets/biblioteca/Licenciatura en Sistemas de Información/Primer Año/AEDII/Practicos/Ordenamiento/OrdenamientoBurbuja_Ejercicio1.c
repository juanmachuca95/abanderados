#include<stdio.h>
#define max 6


typedef int tVector[max-1];
tVector vector;

int main(){
	int vec = 0;
	int i, j;
	int aux;
	
	for (i=0; i< max-1; i++){
		printf("Carga el vector %d : ",vec++);
		scanf("%d",&vector[i]);
	}
	
	printf("Los datos guardados son: \n");
	for (i=0; i< max-1; i++){
		printf("|%d",vector[i]);
	}
	printf("|\n ");    
	
	printf("\nOrdenamiento por metodo burbuja: \n");
	
	for (i=1; i < max-1; i++){
		
		for (j=0; j< max-2; j++){
			
			if(vector[j] > vector[i]){
				
				aux = vector[j];
				vector[j] = vector[i];
				vector[i] = aux;
				
				printf("Dato cambiado %d por %d \n",vector[j],aux);
			}
		}
		
	}
	
	int k;
	printf("El vector queda de la siguiente forma!\n");
	for (k=0; k< max-1; k++){
		printf("|%d",vector[k]);
	}
	printf("|");
	
	
	return 0;
}
