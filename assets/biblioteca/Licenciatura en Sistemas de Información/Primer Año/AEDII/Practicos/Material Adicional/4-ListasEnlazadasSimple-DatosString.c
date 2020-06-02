#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char tElem[25];

typedef struct nodo
{
	tElem elem;		
    struct nodo *siguiente;    
}tLista;

tLista * lista;

void InicializarLista();
bool ListaVacia();
void InsertarPrimero(tElem);
void InsertarAdelante(tElem);
void InsertarElemento(tElem);
void EliminarPrimero();
void VisualizarElementos();
int cantidadElementos();
void InsertarK(int, tElem);
void EliminarK(int);
void Menu();

void InicializarLista()
{	
	lista = NULL;	
}

bool  ListaVacia()
{
	if (lista == NULL)
		return true;
	else
		return false;
	//otra forma de hacer lo mismo:
	//return (lista == NULL);
}

void InsertarPrimero(tElem pElem)
{
	lista = malloc(sizeof(tLista));
	strcpy(lista->elem, pElem);		
	lista->siguiente = NULL;	
	printf("Primer elemento insertado!\n");
}

void InsertarAdelante(tElem pElem)
{
	tLista * nuevoNodo;
	nuevoNodo = malloc(sizeof(tLista));	
	strcpy(nuevoNodo->elem, pElem);		
	nuevoNodo->siguiente = lista;		
	lista = nuevoNodo;		
	printf("Elemento insertado!\n");	
}

void InsertarElemento(tElem pElem)
{
	if (ListaVacia() == true)
		InsertarPrimero(pElem);
	else
		InsertarAdelante(pElem);
}

void EliminarPrimero()
{
	tLista * aux;
	aux = lista;
	lista = lista->siguiente;
	free(aux); 
	printf("Primer elemento eliminado!\n");
}

void VisualizarElementos()
{
	tLista *aux; /* lo usamos para recorrer la lista */		
	aux = lista;
	if (ListaVacia() == false)
	{
		while(aux != NULL) 
		{
			printf("%s ", aux->elem);
	    	aux = aux->siguiente;
		}
	 }else printf( "\nLa lista esta vacia!!\n" );
	printf("\n\n" );	
}

int cantidadElementos()
{
	tLista *aux; /* lo usamos para recorrer la lista */		
	aux = lista;
	int cant = 0;
	if (ListaVacia() == false)
	{
		while(aux != NULL) 
		{
			cant = cant + 1;
	    	aux = aux->siguiente;
		}	
	}
	return cant;	
}

void InsertarK(int k, tElem nuevoDato)
{
	tLista * nuevoNodo, * aux; 
	int i; 
	aux = lista; 
	//El bucle avanza aux hasta el nodo k-1 
	for(i = 1; i < k-1; i++)
	{
		aux = aux->siguiente;
	}	
	//Actualización de punteros	
  	nuevoNodo = malloc(sizeof(tLista));
	strcpy(nuevoNodo->elem, nuevoDato); 
	nuevoNodo->siguiente = aux->siguiente;
  	aux->siguiente = nuevoNodo;		
}

void EliminarK(int k)
{
	tLista * nodoSuprimir, * aux;
	int i; 
	aux = lista; 
	
	//verificar que el k sea válido para el algoritmo
	//Para k=1 utilice la opcion EliminarPrimero
	if(k <= cantidadElementos() && k > 1){
		//El bucle avanza aux hasta el nodo k-1
		for(i = 1; i < k-1; i++)
		{
			aux = aux->siguiente;
		}	
		//Actualización de punteros	y liberar memoria	
		nodoSuprimir = aux->siguiente; 
		aux->siguiente = nodoSuprimir->siguiente; 
		free(nodoSuprimir);  
		
		printf("Elemento de la posicion %d eliminado\n", k);
	}else{
		printf("No se puede eliminar de la posicion %d.\n", k);
	}
	
		
}

int main() 
{	
	InicializarLista();	
	printf("Lista vacia? %s\n", ListaVacia() ? "si" : "no");	
	InsertarElemento("Maria");	
	printf("Lista vacia? %s\n", ListaVacia() ? "si" : "no");		
	InsertarElemento("Juan");	
	InsertarElemento("Pedro");	
	VisualizarElementos();
	InsertarK(3, "Jose");
	VisualizarElementos();
	InsertarK(2, "Pablo");
	VisualizarElementos();
	printf("Cantidad de elementos de la lista:  %d\n\n", cantidadElementos());
	EliminarPrimero();
	VisualizarElementos();
	EliminarK(2);
	VisualizarElementos();
	EliminarK(3);
	VisualizarElementos();

	EliminarK(2);
	VisualizarElementos();
	
	EliminarK(1);
	VisualizarElementos();
	
	printf("Cantidad de elementos de la lista:  %d\n\n", cantidadElementos());
	return 0;
}


