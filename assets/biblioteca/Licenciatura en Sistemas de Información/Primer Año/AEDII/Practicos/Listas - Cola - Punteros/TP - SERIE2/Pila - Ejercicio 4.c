#include<stdio.h>
#include<stdbool.h>
#define max 8
bool pilaVacia();
bool pilaLlena();
void agregarContenedor();
void desapilarContenedor();
void menu();

typedef long int tpila[max-1];
tpila pila;

int tope=-1;
int cod;
int egresaron=0;
int ingresaron=0;
 
int main(){
	menu();
	return 0;
} 

bool pilaLlena(){
	if (tope == max-1){
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

void agregarContenedor(){
	printf("Ingresa el Codigo del contenedor: \n");
	scanf("%i",&cod);
	if(pilaLlena()!=true){
		tope = tope +1;
		pila[tope] = cod;
		ingresaron++;
		printf("Elemento Guardado!\n");
	}else{
		printf("No hay lugar!\n");
	}
}
void desapilarContenedor(){
	if(pilaVacia()!=true){
		cod = pila[tope];
		tope=tope-1;
		egresaron++;
	}else{
		printf("La pila esta Vacia!\n");
	}
}

void menu(){
	int opc;
	printf("1.Agregar Contenedor:\n");
	printf("2.Desapilar Contenedor:\n");
	printf("3.Mostrar cuantos entraron y cuantos salieron:\n");
	scanf("%d",&opc);
	while(opc!=0){
		switch(opc){
			case 1:{
				agregarContenedor();
				break;
			}
			case 2:{
				desapilarContenedor();
				break;
			}
			case 3:{
				printf("La cantidad de Contenedores INGRESADOS ES DE |%d| Y la cantidad de EGRESADOS ES DE |%d| Contenedores\n",ingresaron,egresaron);
				break;
			}
		}
		system("pause");
		system("cls");
		printf("1.Agregar Contenedor:\n");
     	printf("2.Desapilar Contenedor:\n");
    	printf("3.Mostrar cuantos entraron y cuantos salieron:\n");
    	scanf("%d",&opc);
	}
}
