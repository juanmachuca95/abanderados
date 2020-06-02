#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
void inicializarPila();
bool pilaVacia();
void agregarInscriptos(char[], char[], int, float);
void ingresarDatos();
void menu();
void visualizarInscriptos();
void EliminarInscripto();
float RecaudacionEnEstudiantes();
float PorcentajeDeProfesionales();
float RecaudacionTotal();

typedef struct nodo{
	char nomb[30];
	char email[15];
	int codCategoria;
	float precInscripcion;
	struct nodo*siguiente;
}tPila;

tPila *pila;

int cantProfesionales=0;


int main(){
	menu();
	return 0;
}


void inicializarPila(){
	pila = NULL;
}

bool pilaVacia(){
	if(pila == NULL){
		return true;
	}else{
		return false;   
	}
}

void agregarInscriptos(char datNomb[],char datEmail[],int datCategoria,float datPrecio){
	if (pilaVacia()){
		tPila * nuevoNodo;
		nuevoNodo = pila;
		pila = malloc(sizeof(tPila));
		strcpy(pila->nomb, datNomb);
		strcpy(pila->email, datEmail);
		pila->codCategoria = datCategoria;
		pila->precInscripcion = datPrecio;
		pila->siguiente = nuevoNodo;
		printf("Primer Inscripto!!\n");
	}else{
		tPila * nuevoNodo;
		nuevoNodo = pila;
		pila = malloc(sizeof(tPila));
		strcpy(pila->nomb, datNomb);
		strcpy(pila->email, datEmail);
		pila->codCategoria = datCategoria;
		pila->precInscripcion = datPrecio;
		pila->siguiente = nuevoNodo;
		printf("Se ha guardado la Inscripcion!!\n");
	}
		
}

void menu(){
	int opc;
	printf("1. Inscribirse.\n");
	printf("2. Darse de baja.\n");
	printf("3. Ver lista de Inscriptos.\n");
	printf("4. Recaudacion en inscripcion de Estudiantes.\n");
	printf("5. Porcentaje y cantidad de Profesionales inscriptos.\n");
	printf("6. Recaudacion total.\n");
	scanf("%d",&opc);
	
	while(opc!=0){
		switch(opc){
			case 1:{
				ingresarDatos();
				break;
			}
			case 2:{
				EliminarInscripto();
				break;
			}
			case 3:{
				visualizarInscriptos();
				break;
			}
			case 4:{
				printf("EL TOTAL RECAUDADO EN ESTUDIANTES ES DE |%.2f| .",RecaudacionEnEstudiantes());
				break;
			}
			case 5:{
				printf("EL PORCENTAJE DE PROFESIONALES ES DE |%.2f| .\n",PorcentajeDeProfesionales());
				printf("LA CANTIDAD DE PROFESIONALES ES DE |%d| .\n",cantProfesionales);
				break;
			}
			case 6:{
				printf("RECAUDACION TOTAL DE |%.2f| \n",RecaudacionTotal());
				break;
			}
			
		}
		system("pause");
		system("cls");
		printf("1. Inscribirse.\n");
    	printf("2. Darse de baja.\n");
    	printf("3. Ver lista de Inscriptos.\n");
    	printf("4. Recaudacion en inscripcion de Estudiantes.\n");
    	printf("5. Porcentaje y cantidad de Profesionales inscriptos.\n");
    	printf("6. Recaudacion total.\n");
    	scanf("%d",&opc);
	}
}


void ingresarDatos(){
	char vnomb[35],email[30];
	int codCat;
	float monto;
	fflush(stdin);
	printf("INGRESE EL NOMBRE Y APELLIDO: ");gets(vnomb);
	fflush(stdin);
	printf("INGRESAR EMAIL: ");gets(email);
	printf("INGRESAR COD.CATEGORIA 01.ESTUDIANTES 02.PROFESIONALES 03.PUBLICO GENERAL: ");scanf("%d",&codCat);
	printf("INGRESAR MONTO DE LA INSCRIPCION $50-Estudiantes $100-Profesionales-Publico-General: ");scanf("%f",&monto);
	
	agregarInscriptos(vnomb,email,codCat,monto);
}

void visualizarInscriptos(){
	tPila *aux;
	aux = pila;
	printf("La lista de inscriptos hasta el momento: \n");
	printf("*****************************\n");
	while(aux!=NULL){
		printf("NOMBRE: %s\nEMAIL: %s\nMONTO: %.2f\n",aux->nomb,aux->email,aux->precInscripcion);
		if(aux->codCategoria == 2 || aux->codCategoria == 02){
			printf("CATEGORIA: PROFESIONAL\n");
		}else{
			if(aux->codCategoria == 1 || aux->codCategoria == 01){
				printf("CATEGORIA: ESTUDIANTE\n");
			}else{
				printf("CATEGORIA: PUBLICO GENERAL\n");
			}
		}
		printf("*****************************\n");
		aux = aux->siguiente;
	}
}

void EliminarInscripto(){
	if(pilaVacia()){
		printf("NO HAY NADA PARA ELIMINAR\n");
	}else{
		tPila *aux;
     	aux = pila;
    	pila = pila->siguiente;
    	free(aux);
    	printf("INSCRIPTO ELIMINADO! :(\n");
	}
	
}

float RecaudacionEnEstudiantes(){
	tPila *aux;
	aux = pila;
	float recaudadoEstudiantes = 0;
	
	while(aux!=NULL){
		if(aux->codCategoria == 1 || aux->codCategoria == 01){
			recaudadoEstudiantes = recaudadoEstudiantes + aux->precInscripcion;
		}
		aux = aux->siguiente;
	}
	return recaudadoEstudiantes;
}

float PorcentajeDeProfesionales(){
	tPila *aux;
	aux = pila;
	float porcentajeProfesionales;
	int cantTotal=0;
	while(aux!=NULL){
		if (aux->codCategoria == 02 || aux->codCategoria == 2){
			cantProfesionales++;
		}
		cantTotal++;
		aux = aux->siguiente;
    }
    porcentajeProfesionales = cantProfesionales * 100 / cantTotal;
    return porcentajeProfesionales;
}

float RecaudacionTotal(){
	tPila *aux;
	aux = pila;
	float recaudacionTotal=0;
	while(aux!=NULL){
		recaudacionTotal = recaudacionTotal + aux->precInscripcion;
		aux = aux->siguiente;
	}
	return recaudacionTotal;
	
}
