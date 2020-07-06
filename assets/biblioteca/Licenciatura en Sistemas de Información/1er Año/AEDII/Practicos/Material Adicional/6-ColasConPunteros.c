#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef float tElem;

typedef struct nodo
{
	tElem elem;		
    struct nodo * siguiente;    
}tApNodo;

typedef struct 
{
	tApNodo * principio;
	tApNodo * final;
}tCola;

tCola cola;

void InicializarCola();
bool ColaVacia();
void Push(tElem pElem);
void Pop();
void VisualizarElementos();
tElem PrimerElemento();

void InicializarCola()
{		
	cola.principio = NULL;
	cola.final = NULL;
}

bool  ColaVacia()
{		
	if (cola.final == NULL)
		return true;
	else
		return false;
}

void Push(tElem pElem) //Agregar elemento
{	
	tApNodo * nuevoNodo;

	nuevoNodo = malloc (sizeof(tApNodo));	
	nuevoNodo->elem = pElem;	
	nuevoNodo->siguiente = NULL; //Siempre NULL porque se ingresa x el final
	
	if (ColaVacia()== true) //significa que agrego el 1er nodo
	{	
		cola.principio = nuevoNodo;
		cola.final = nuevoNodo; 
	}
	else
	{	
		cola.final->siguiente = nuevoNodo;
		cola.final = nuevoNodo;
	}	
	printf("Elemento insertado!\n");
}

void Pop() //Quitar elemento
{	
	tApNodo * nodoAEliminar;
	if (ColaVacia() == true)
		printf("No hay elementos en cola\n");
	else
	{
		//si la cola es unitaria hay que poner en NULL los punteros
		if (cola.principio == cola.final)
		{
			nodoAEliminar = cola.principio;
			free(nodoAEliminar);
			cola.principio = NULL;
			cola.final = NULL;				
		}
		else
		{
			nodoAEliminar = cola.principio;
			cola.principio = nodoAEliminar->siguiente;
			free(nodoAEliminar);
		}
		printf("Elemento eliminado!\n");
	}	
}

void VisualizarElementos()
{
	tApNodo * colaPorRecorrer;
		
	if (ColaVacia() == true)
		printf("No hay elementos para mostrar!\n");
	else
	{
		printf("Elementos en la cola: \n");
		/*Para recorrer la cola se comienza por el principio*/
		colaPorRecorrer = cola.principio; 
		while (colaPorRecorrer != NULL)
		{
			printf("%.2f\t", colaPorRecorrer->elem);
			colaPorRecorrer = colaPorRecorrer->siguiente;
		}
		printf("\n\n");
	}
}

tElem PrimerElemento()
{
	if (ColaVacia()!=true)
	{
		return cola.principio->elem;
	}else	
	return 0;	
}

int main() 
{	
	InicializarCola();	
	printf("Cola vacia? %s\n", ColaVacia() ? "si" : "no");	
	Push(100.0);	
	printf("Cola vacia? %s\n", ColaVacia() ? "si" : "no");	
	Push(200.0);	
	Push(300.0);	
	VisualizarElementos();	
	Pop();
	VisualizarElementos();
	printf( "\nElemento al principio: %.2f \n", PrimerElemento());
	Pop();
	Pop();
	VisualizarElementos();	
	printf( "\nElemento al principio: %.2f \n", PrimerElemento());
	return 0;
}


