#include<stdio.h>
#include<stdio.h>

void ingresarDatosA();
void ingresarDatosB();
void sumadeVectores(int *,int*);
void Proceso();

int A[5];
int B[5];
int sumaB=0;
int sumaA =0;
int total;
char respuesta;


int main(){
	Proceso();
	return 0;
}





void ingresarDatosA(){
	int i;
	
	
	for (i=0; i<5; i++){
		printf("Ingresa un numero: ");
		scanf("%d",&A[i]);
		
	}
	
	
	for(i=0; i<5; i++){
		sumaA = sumaA + A[i];
		printf("|%d| ",A[i]);
	}
	printf("La suma de los vectores A es |%d|", sumaA);
}

void ingresarDatosB(){
	int j;
	for(j=0; j<5; j++){
		printf("Ingrese un numero: ");
		scanf("%d",&B[j]);
	}
	for (j=0; j<5; j++){
		sumaB = sumaB + B[j];
		printf("|%d| ",B[j]);
	}
	printf("La suma de los vectores de B es |%d|", sumaB);
	
}

void sumadeVectores(int *x, int *z){
	total = *x + *z;
    printf("\nLa suma de vectores de A y B es || %d ||",total);
}

void Proceso(){
	printf("Cargar vector A: S/N ");
	scanf("%c",&respuesta);
	if(respuesta == 's'){
		ingresarDatosA();
		fflush(stdin);
		printf("\n\nCargar vector B: S/N ");
		scanf("%c",&respuesta);
		if (respuesta == 's'){
			ingresarDatosB();
			sumadeVectores(&sumaB, &sumaA);
		}else{
			printf("\n Fin de programa *");
		}
	}
}
