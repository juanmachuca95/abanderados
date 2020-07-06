#include<stdio.h>
void designaMatriz();
int columnas;
int filas;
int i, j, n, m;
int matriz[0][0];



int main(){
	designaMatriz();
	return 0;
}

void designaMatriz(){
	printf("Ingresa el numero de filas: ");
	scanf("%d",&filas);
	printf("Ingresa el numero de columnas: ");
	scanf("%d",&columnas);
	
	matriz[0][0] = matriz[0+filas][0+columnas];
	
	for(i=0; i<filas; i++){
		for(j=0; j<columnas; j++){
			printf("  -  ");
		}
		printf("\n\n");
	}
}



