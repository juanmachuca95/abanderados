#include<stdio.h>
#include<stdbool.h>
#define max 12
bool pilaLlena();
bool pilaVacia();
void menu();
void agregarElementosPila();
void mostrarPila();
void desapilarPila();
float topePila();
float promedioPesos();

typedef float tpila[max-1];
tpila pila;

int tope = -1;
float peso;
int suma =0;


int main(){
	menu();
	return 0;
}



void menu(){
	char opc;
	printf("a) Cargar la pila con los pesos de los discos \nb) Listar los pesos de los discos apilados.\nc) A medida que cada gimnasta quita un disco, este debe ser eliminado de la pila\nd) Detectar cual es el elemento (disco) que se encuentra en el tope.\ne) Mostrar la cantidad de elementos (discos).\nf) Calcular el promedio de pesos de los discos que tiene la pila");
	printf("Ingresa opcion: \n");
	scanf("%c",&opc);
	while(opc!= '0'){
		switch (opc){
			case 'a':{
				agregarElementosPila();
				break;
			}
			case 'b':{
				mostrarPila();
				break;
			}
			case 'c':{
				desapilarPila();
				break;
			}
			case 'd':{
				printf("El elemento tope es una pesa de |%f| kg \n",topePila());
				break;
			}
			case 'e':{
				printf("Actualmente hay |%d| Discos en total \n",suma);
				break;
			}
			case 'f':{
				promedioPesos();
				break;
			}
		}
		system("pause");
		system("cls");
		printf("a) Cargar la pila con los pesos de los discos \nb) Listar los pesos de los discos apilados.\nc) A medida que cada gimnasta quita un disco, este debe ser eliminado de la pila\nd) Detectar cual es el elemento (disco) que se encuentra en el tope.\ne) Mostrar la cantidad de elementos (discos).\nf) Calcular el promedio de pesos de los discos que tiene la pila");
    	fflush(stdin);
		printf("Ingresa opcion: \n");
    	scanf("%c",&opc);
	}
	
}


bool pilaLlena(){
	if(tope == max-1){
		return true;
	}else{
		return false;
	}
}

bool pilaVacia(){
	if(tope == -1){
		return true;
	}else{
		return false;
	}
}

void agregarElementosPila(){
    if(pilaLlena()!= true){
		printf("Ingresa el PESO de los Discos en Kg.: ");
		scanf("%f",&peso);
		if (peso > 10 && peso < 100){
			tope = tope +1;
			pila[tope] = peso;
			suma++;
			printf("Elemento Guardado! \n");
		}else{
			printf("Esta peso es IMCOMPATIBLE! \n");
		}
	}else{
		printf("No hay lugar para mas Discos! \n");
	}
}

void mostrarPila(){
	int i;
	
	for (i=0;i<=tope;i++){
		printf("|%.2f| ",pila[i]);
	}
}

void desapilarPila(){
	if(pilaVacia()!= true){
		peso = pila[tope];
		tope = tope -1;
		suma--;
		printf("Disco quitado!\n");
	}else{
		printf("No hay elementos que quitar de la Pila!\n");
	}
}

float topePila(){
	return pila[tope];
}

float promedioPesos(){
	float promedio =0;
	int j;
	for (j=0; j<=tope; j++){
		promedio = promedio + pila[j];
	}
	printf("El promedio de pesos que tiene la pila es de |%.2f|\n",promedio);
}
