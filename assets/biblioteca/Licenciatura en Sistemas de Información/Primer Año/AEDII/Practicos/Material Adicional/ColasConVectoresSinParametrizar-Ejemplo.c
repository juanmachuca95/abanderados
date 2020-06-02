/* Ejemplo de Cola con Vectores */
/*Autor: Cátedra Algoritmos y Estructuras de Datos II*/
#include <stdio.h>
#include <stdbool.h>

const max = 5;

typedef int tCola [5];	

tCola cola;
int i, frente, final;
char elemento;

void crearColaVacia();
bool colaVacia(); 
bool colaLlena();
void agregarElemento(int);
void eliminarElementoFrenteMovil();
void eliminarElementoFrenteFijo();
int primerElemento();
void visualizarElementos();
void menu();

int main() {
	crearColaVacia();	
	menu();
	return 0;
}

void crearColaVacia() {
	frente = -1;	
	final = -1;	
}

bool colaVacia() {
	if ((frente == -1) && (final == -1))
		return true;
	else
		return false;
}

bool colaLlena() {
	if (final == (max-1)) 
		return true;
	else
		return false;
}

void agregarElemento(int pElemento) {
	if (!colaLlena() ) 	{		
		final = final + 1;
		cola[final] = pElemento;
		printf("Elemento Insertado!\n");
		//significa que es el primer elemento
		if (final == 0 )
			frente = 0;				
	} else {
		printf("No hay lugar!\n");
	}	
}

void eliminarElementoFrenteMovil() {
	if (colaVacia() == true)
		printf("No hay elementos por eliminar!!!\n");
	else {
		//poner en cero o vacio el elemento del frente
		cola[frente] = 0;
		
		printf("Elemento eliminado!!!\n");		
		
		//si frente y final son iguales significa que elimine el ultimo		
		if (frente == final) {
			frente = -1;
			final = -1;
		} else
			frente =  frente + 1;					
	}
}

void eliminarElementoFrenteFijo() {
	if (colaVacia() == true)
		printf("No hay elementos por eliminar!!!\n");
	else {
		//poner en cero o vacio el elemento del frente
		cola[frente] = 0;
		
		printf("Elemento eliminado!!!\n");		
		
		//reacomodando...
		for (i = frente; i <= final-1; i++) {
			cola[i] = cola[i + 1];
		}			
		
		cola[final] = 0;
						
		if (frente == final) {
			frente = -1;
			final = -1;
		} else
			final = final - 1;
	}
}

int primerElemento() {
	return cola[frente];
}

void visualizarElementos() {
	int i;
	printf("Elementos en cola: \n");
	for (i = frente; i <= final; i++) {
		printf("%d ", cola[i]);
	}
	printf("\n\n");	
}

void menu() {	
	int opcion, elem;
	printf("*** Opciones disponibles ***\n");	
	printf("1- Agregar elemento  2- Eliminar elemento 3- Mostrar primer elemento\n");
	printf("4- Visualizar elementos 5- Cola Vacia? 6- Cola Llena? 0- Salir \n");	
	printf("Opcion: ");
	scanf("%d", &opcion); fflush(stdin);
	switch (opcion) {
		case 1:
		 	printf("Ingrese elemento entero (0 para cambiar de opcion): ");
			scanf("%d", &elem);
			while (elem != 0) {																
				agregarElemento(elem);
				printf("Ingrese elemento entero (0 para cambiar de opcion): ");
				scanf("%d", &elem); fflush(stdin);
			}
			printf("\n");
			system("cls");
			menu();	
		    break;
		case 2:		    
		    eliminarElementoFrenteFijo();
			printf("\n");
			menu();	
			break;
		case 3:		 
			printf("Primer elemento: %d\n\n", primerElemento());
			printf("Frente: %d Final:%d\n", frente, final);
			menu();	
			break;		
		case 4:		 
			printf("*** Elementos en cola ***\n");									
			visualizarElementos();
			menu();	
			break;
		case 5:
			printf("Cola vacia? %s\n", colaVacia() ? "si" : "no");
			menu();	
			break;
		case 6:
			printf("Cola llena? %s\n", colaLlena() ? "si" : "no");
			menu();	
			break;
		case 0:
			printf("\n");			
			break;
	}
}
