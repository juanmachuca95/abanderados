#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 20
#define NOM 30

void inicioCola();
bool colaVacia();
bool colaLlena();
void agregarPaciente(char x[]);
void atenderPaciente();
void mostrarSiguiente();
void mostrarLista();
void verTurnosDisponibles();
void menu();

typedef char tCola[MAX][NOM];

tCola vCola;

int fre,fin;

int main(){
	
	inicioCola();
	menu();
	
	return 0;
}

void inicioCola(){
	fre = -1;
	fin = -1;
}
bool colaVacia(){
	if((fre == -1)&&(fin==-1)){
		return true;
	}
	else{
		return false;
	}
}
bool colaLlena(){
	if(fin==(MAX-1)){
		return true;
	}
	else{
		return false;
	}
}
void agregarPaciente(char x[]){
	fin++;
	strcpy(vCola[fin],x);
	printf("Paciente Agregado!\n");
	if(fin == 0){
		fre = 0;
	}
}
void atenderPaciente(){
	if(fre>fin){
		printf("NO SE PUEDEN ELIMINAR PACIENTES!\n ");
	}
	else{
		if(!colaVacia()){
			printf("Se atendio al paciente : %s \n",vCola[fre]);
			fre ++;
		}
		else{
			printf("La cola esta vacia!\n");
		}
	}
}
void mostrarSiguiente(){
	if(fre>fin){
		printf("No hay pacientes!\n");
	}
	else{
		if(!colaVacia()){
		printf("El siguiente paciente es : %s \n",vCola[fre]);
	}
	else{
		printf("La cola esta vacia!\n");
	}
	}
}

void mostrarLista(){
	int i;
	if(fre>fin){
		printf("No hay pacientes que mostrar!\n");
	}
	else{
		printf("Lista de pacientes a atender \n");
		for(i=fre;i<=fin;i++){
			printf("%s \n",vCola[i]);
		}
	}
}
void verTurnosDisponibles(){
	int turnD;
	turnD = (MAX-1)-fin;
	printf("Hay un total de %d turnos disponibles\n",turnD);
}
void opc(){
	printf("Que desea Hacer?\n1-Agregar pacientes\n2-Atender Paciente\n");
	printf("3-Mostrar turnos disponibles\n4-Mostrar Pacientes a atender\n");
	printf("5-Mostrar siguiente\n0-SALIR\n");
}
void menu(){
	int resp;
	char nomb[NOM];
	printf("Bienvenido al sistema de carga de pacientes\n");
	opc();
	scanf("%d",&resp);
	while(resp!=0){
		switch(resp){
			case 1:
				if(!colaLlena()){
					printf("Ingrese nombre de paciente : ");
					scanf("%s",nomb);
					agregarPaciente(nomb);
				}
				else{
					printf("No hay lugar!\n");
				}
				break;
			case 2:
				atenderPaciente();
				break;
			case 3:
				verTurnosDisponibles();
				break;
			case 4:
				mostrarLista();
				break;
			case 5:
				mostrarSiguiente();
				break;
		}
		system("pause");
		system("cls");
		fflush(stdin);
		opc();
		scanf("%d",&resp);
	}
}


