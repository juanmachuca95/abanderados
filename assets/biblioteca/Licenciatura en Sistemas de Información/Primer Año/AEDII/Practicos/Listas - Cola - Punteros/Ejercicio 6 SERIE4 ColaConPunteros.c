#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
void inicializarCola();
bool colaVacia();
void agregarDatosClienntesCallCenter(char[],long int,int,int);
void ingresarDatos();
void visualizarListaDeTelefonosDeCorrientes();
void verCantidadLlamadasProcedencias();
void menu();

typedef struct nodo{
	char nomb[35];
	int dni;
	long int numCel;
	int codProce;
	struct nodo *siguiente;
}tApNodo;

typedef struct{
	tApNodo *frente;
	tApNodo *final;
}tCola;

tCola cola;


int main(){
	 menu();
	 return 0;
}

void inicializarCola(){
	cola.frente = NULL;
	cola.final = NULL;
}

bool colaVacia(){
	if(cola.final == NULL){
		return true;
	}else{
		return false;
	}
}

void agregarDatosClientesCallCenter(char v_nomb[],long int v_num, int v_dni, int v_codProce){
	tApNodo *nuevoNodo;
	nuevoNodo = malloc(sizeof(tApNodo));
	strcpy(nuevoNodo->nomb, v_nomb);
	nuevoNodo->dni = v_dni;
	nuevoNodo->numCel = v_num;
	nuevoNodo->codProce = v_codProce;
	nuevoNodo->siguiente = NULL;
	if(colaVacia()){
		cola.frente = nuevoNodo;
		cola.final = nuevoNodo;
	}else{
		cola.final->siguiente = nuevoNodo;
		cola.final = nuevoNodo;
	}
	printf("Los datos se han GUARDADO EN EL CALL CENTER!\n");
}

void ingresarDatos(){
	char vnomb[35];
	long int vnum;
	int vdni;
	int vcodProce;
	fflush(stdin);
	printf("NOMBRE Y APELLIDO: ");gets(vnomb);
	printf("NUMERO CELULAR: ");scanf("%d",&vnum);
	printf("DNI: ");scanf("%d",&vdni);
	printf("1.CORRIENTES 2.CHACO: ");scanf("%d",&vcodProce);
	
	agregarDatosClientesCallCenter(vnomb,vnum,vdni,vcodProce);
}

void visualizarListaDeTelefonosCorrientes(){
	tApNodo * recorrerCola;
	recorrerCola = cola.frente;
	int cantLlamadasCtes=0;
	
	printf("CELULARES PROCEDENTES DE CORRIENTES CAPITAL:\n");
	while(recorrerCola != NULL){
		if(recorrerCola->codProce == 1){
			printf("%i\n",recorrerCola->numCel);
			cantLlamadasCtes++;
		}
		recorrerCola = recorrerCola->siguiente;
	}
	printf("En total hay |%d| llamadas en espera de Corrientes!\n",cantLlamadasCtes);
}

void verCantidadLlamadasProcedencias(){
	tApNodo *aux;
	aux = cola.frente;
	int cantTotalLlamadas=0;
	int cantCtes=0, cantChaco=0;
	while(aux!=NULL){
		if(aux->codProce == 1){
			cantCtes++;
			printf("Celular |%d| procedente de CORRIENTES.\n",aux->numCel);
		}else{
			printf("Celular |%d| procedente de CHACO.\n",aux->numCel);
			cantChaco++;
		}
		cantTotalLlamadas++;
		aux = aux->siguiente;
	}
	printf("Las Llamadas en espera en CORRIENTES es de |%d| y en CHACO es de |%d|\n",cantCtes, cantChaco);
}

void menu(){
	int opc;
	printf("1. Agendar datos personales de las llamadas:\n");
	printf("2. Mostrar la lista de Celulares de Corrientes:\n");
	printf("3. Mostrar la cantidad total de las llamadas y sus procedencias y la cantidad total.\n");
	scanf("%d",&opc);
	while(opc!=0){
		switch(opc){
			case 1:{
				ingresarDatos();
				break;
			}
			case 2:{
				visualizarListaDeTelefonosCorrientes();
				break;
			}
			case 3:{
				verCantidadLlamadasProcedencias();
				break;
			}
		}
		system("pause");
		system("cls");
		printf("1. Agendar datos personales de las llamadas:\n");
     	printf("2. Mostrar la lista de Celulares de Corrientes:\n");
    	printf("3. Mostrar la cantidad total de las llamadas y sus procedencias y la cantidad total.\n");
    	scanf("%d",&opc);
	}
}




