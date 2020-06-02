#include<stdio.h>
#include<stdbool.h>
#define max 10

bool pilaLlena();
bool pilaVacia();
void agregarElementosPila();
void mostrarPila();
void sumaPila();
void menu(); 

typedef float tpila[max-1];
tpila pila;

int tope = -1;
float datos;

int main(){
	menu();
	return 0;
}



bool pilaVacia(){
	if (tope == -1){
		return true;
	}else{
		return false;
	}
}

bool pilaLlena(){
	if(tope == max-1){
		return true;
	}else{
		return false;
	}
}

void agregarElementosPila(){
	if (pilaLlena()!=true){
		printf("Ingresar un numero real : ");
	    scanf("%f",&datos);
		tope = tope +1;
		pila[tope] = datos;
		printf("Elemento guardado!\n");
	}else{
		printf("No hay lugar\n");
	}
}

void mostrarPila(){
	int i;
	for(i=0;i<=tope;i++){
		printf("|%.2f| ",pila[i]);
	}
}

void sumaPila(){
	int j;
	float suma = 0;
	for(j=0;j<=tope;j++){
		suma = suma + pila[j]; 
	}
	printf("La suma de los valores de la pila es ''%.2f''\n",suma); 
}

void menu(){
	int opcion;
	printf("***Opciones Disponibles***\n");
	printf("1. Agregar elemento a la Pila.\n");
	printf("2. Mostrar elementos de la Pila.\n");
	printf("3. Mostrar la sumas de todos los elementos.\n");
	printf("Elige una opcion\n");
	scanf("%d",&opcion);
	while (opcion !=0){
		switch (opcion){
		case 1:{
			agregarElementosPila();
			break;
		}
		case 2:{
			mostrarPila();
			break;
		}
		case 3:{
			sumaPila();
			break;
		}
	}
	system("pause");
	system("cls");
	printf("***Opciones Disponibles***\n");
	printf("1. Agregar elemento a la Pila.\n");
	printf("2. Mostrar elementos de la Pila.\n");
	printf("3. Mostrar la sumas de todos los elementos.\n");
	printf("Elige una opcion: \n");
	scanf("%d",&opcion);
    }
}

