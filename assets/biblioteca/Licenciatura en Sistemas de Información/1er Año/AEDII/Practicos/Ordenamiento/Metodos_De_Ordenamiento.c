#include<stdio.h>
#include<assert.h>
#include<stdbool.h>

void Ordenamiento_Seleccion_Directa();
void Ordenamiento_Insercion_Directa();
void Ordenamiento_Burbuja();
void Ordenamiento_Por_Intercambio();
void Ordenamiento_Burbuja_Mejorada();

int main(){
	Ordenamiento_Seleccion_Directa();
	Ordenamiento_Insercion_Directa();
	Ordenamiento_Burbuja();
	Ordenamiento_Por_Intercambio();
	Ordenamiento_Burbuja_Mejorada();
	return 0;
}

void Ordenamiento_Seleccion_Directa(){
	printf("EL VECTOR = {4, 1, 4, 7, 0, 11}\n");
	int vector[6] = {4, 1, 4, 7, 0, 11};
	int i, j;
	int valMenor, posMenor;
	int aux;
	
	for(i=0; i<6-1; i++){
		valMenor = vector[i];
		posMenor = i;
		
		for(j=i+1; j<6; j++){
			if(vector[j] < valMenor){
				valMenor = vector[j];
				posMenor = j;
			}
		}
		
		if(posMenor != i){
			aux = vector[i];
			vector[i] = vector[posMenor];
			vector[posMenor] = aux;
		}
	}
	
	printf("El Ordenamiento por Seleccion Directa es: ");

	for(i=0; i<6; i++){
		printf("%d ",vector[i]);
	}
}

void Ordenamiento_Insercion_Directa(){
	printf("\n\nEL VECTOR = {3, 4, 6, 0, 1, 5}\n");
	int i, j, aux;
	int vector2[6] = {3,4,6,0,1,5};
	
	for(i=1; i<6; i++){
		aux = vector2[i];
		j = i-1;
		
		while(vector2[j] > aux){
			vector2[j+1] = vector2[j];//pasa los valores mayores a la derecha
			j=j-1; // esto se hace para poder comparar con la posicion anterior del vertor.
		}
		vector2[j+1]=aux;		
	}
	
	printf("El Ordenamiento por Insercion Direccta es: ");
	for(i=0; i<6; i++){
	   printf("%d ",vector2[i]);
    }
}

void Ordenamiento_Burbuja(){
	
	printf("\n\nVECTOR = {9, 2, 3, 7, 2, 0}\n");
	int vector3[6] = {9,2,3,7,2,0}; 
	
	int i, j, aux;
	
	for(i=0; i<6;i++){
		
		aux = vector3[i];
		
		for(j=1; j<6;j++){
			if(vector3[j] < vector3[j-1]){//si el vector en la segunda posicion es menor
				
				aux = vector3[j];
				vector3[j] = vector3[j-1];
				vector3[j-1] = aux;
				
			} 
		}
	}
	
	printf("El Ordenamiento Burbuja es: ");
	for(i=0; i<6; i++){
	   printf("%d ",vector3[i]);
    }
}

void Ordenamiento_Por_Intercambio(){
	
	printf("\n\nVECTOR = {9, 2, 3, 7, 2, 0}\n");
	int vector4[6] = {9,2,3,7,2,0}; 
	
	int i, j, aux;
	
	for (i=0; i<6; i++){
		
		for (j=0; j<6; j++){
			
			if(vector4[j] > vector4[j+1]){
				
				aux = vector4[j];
				vector4[j] = vector4[j+1];
				vector4[j+1] = aux;
				
			}
		}
	}
	
	printf("El Ordenamiento Por InterCambio es: ");
	for(i=0; i<6; i++){
	   printf("%d ",vector4[i]);
    }
}

void Ordenamiento_Burbuja_Mejorada(){
	
	printf("\n\nVECTOR = {20, 22, 1, 0, 3, 7}\n");
	int vector5[6] = {20,22,1,0,3,7};
	
	int i,j, aux;
	bool bandera;
	bandera = false;
	
	/* 0 = 20, 22, 1, 0, 3, 7 
	   1 = 20, 1, 22, 0, 3, 7
	   2 = 20, 1, 0, 22, 3, 7 
	   3 = 20, 1, 0, 3, 22, 7
	   4 = 20, 1, 0, 3, 7, 22
	   5 = 20, 1, 0, 3, 7, 22
	   
	   --------cierra y entra de nuevo en el bucle
	   
	*/
	
	while(bandera == false){
		bandera = true;
		
		for(i=0; i<6; i++){
			
			if(vector5[i] > vector5[i+1]){
				
				aux = vector5[i];
				vector5[i] = vector5[i+1];
				vector5[i+1] = aux;
				
				/*
				for(j=0; j<6; j++){
	                printf("%d ",vector5[j]);
                }
                printf("\n");
				*/
 				
				bandera = false;
			}
		}
	} 
	
	printf("El Ordenamiento Burbuja Mejorado es: ");
	for(i=0; i<6; i++){
	   printf("%d ",vector5[i]);
    }
}

