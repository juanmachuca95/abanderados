#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

void menu();
void agregarDatosLista();
bool listaVacia();
void mostrarPorcentajeMenores();
void promedioEdades();
void visualizarLista();

char vnombPaciente[25];
int vdniPaciente, vedadPaciente, cantTotal=0;


typedef struct nodo{
	char nombPaciente[25];
	int dniPaciente;
	int edadPaciente;
	struct nodo *siguiente;
}tLista;

tLista *lista;

int main(){
	menu();
	return 0;
}


bool listaVacia(){
	if(lista == NULL){
		return true;
	}else{
		return false;
	}
}

void agregarDatosLista(){
	if(listaVacia()){
		lista = malloc(sizeof(tLista));
		strcpy(lista->nombPaciente, vnombPaciente);
		lista->dniPaciente = vdniPaciente;
		lista->edadPaciente = vedadPaciente;
		lista->siguiente = NULL;
		cantTotal++;
		printf("Primer Elemento Ingresado!\n");
	}else{
		tLista *nuevoNodo;
		nuevoNodo = malloc(sizeof(tLista));
		strcpy(nuevoNodo->nombPaciente, vnombPaciente);
		nuevoNodo->dniPaciente = vdniPaciente;
		nuevoNodo->edadPaciente = vedadPaciente;
		nuevoNodo->siguiente = lista;
		lista = nuevoNodo;
		cantTotal++;
		printf("Se ha guardado el Elemento!\n");	
	}
}

void menu(){
	int opc; 
	printf("1. Ingresar Apellido-Nombre, DNI, Edad del Paciente:\n");
	printf("2. Mostrar el promedio de edades de los pacientes:\n");
	printf("3. Mostrar el porcentaje de Pacientes menores de 5 años:\n");
	printf("4. Visualizar a todos los pacientes de la lista:\n");
	scanf("%d",&opc);
	while(opc!=0){
		switch (opc){
			case 1:{
				fflush(stdin);
				printf("NOMBRE Y APELLIDO: ");gets(vnombPaciente);
				printf("DNI: ");scanf("%d",&vdniPaciente);
				printf("EDAD: ");scanf("%d",&vedadPaciente);
				agregarDatosLista();
				break;
			}
			case 2:{
				promedioEdades();
				break;
			}
			case 3:{
				mostrarPorcentajeMenores();
				break;
			}
			case 4:{
				visualizarLista();
				break;
			}
		}
		system("pause");
		system("cls");
		printf("1. Ingresar Apellido-Nombre, DNI, Edad del Paciente:\n");
		printf("2. Mostrar el promedio de edades de los pacientes:\n");
		printf("3. Mostrar el porcentaje de Pacientes menores de 5 años:\n");
		printf("4. Visualizar a todos los pacientes de la lista:\n");
		scanf("%d",&opc);
	}
}

void mostrarPorcentajeMenores(){
	int cantMenores =0;
	float porcentajeMenores;
	tLista * aux;
	aux = lista;
	
	while(aux!=NULL){
		if(aux->edadPaciente < 5){
			cantMenores = cantMenores + 1;
		}
		aux = aux->siguiente;
	}
	
	porcentajeMenores = cantMenores*100 / cantTotal;
	printf("El porcentaje de menores de 5 es de |%.2f| porciento. \n",porcentajeMenores);
}

void promedioEdades(){
	int promedioEdad =0;
	tLista *aux;
	aux = lista;
	
	while(aux!=NULL){
		promedioEdad = promedioEdad + aux->edadPaciente;
		aux = aux->siguiente;
	}
	printf("El promedio edades es de |%d| ... \n",promedioEdad);
}

void visualizarLista(){
	tLista *aux;
	aux = lista;
	printf("************************************\n");
	while(aux!=NULL){
		printf("NOMBRE: %s\nDNI: %d\nEDAD: %d\n",aux->nombPaciente,aux->dniPaciente,aux->edadPaciente);
		aux = aux->siguiente;
		printf("*************************************\n");
	}
}
