#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


//Definimos la estructura del arbol. 
typedef struct nodoArbol{
	int dato;
	struct nodoArbol *hijoIzquierdo;
	struct nodoArbol *hijoDerecho;
}tArbol;

tArbol *arbol;

tArbol * subIzquierdo();
tArbol * subDerecho();
int datoRaiz();
void crearArbol();
bool arbolVacio();
void insertarEnArbol(tArbol **, int);

void verEnPreOrden(tArbol*);
void verEnInOrden(tArbol*);
void verEnPostOrden(tArbol*);

void menu();

int cantNodos=0;

tArbol * subIzquierdo(){
	return arbol->hijoIzquierdo;
}

tArbol * subDerecho(){
	return arbol->hijoDerecho;
}

int datoRaiz(){
	return arbol->dato;
}

void crearArbol(tArbol *pArbol)
{
	pArbol = NULL;
}

bool arbolVacio(tArbol * pArbol)
{
	if(pArbol == NULL){
		return true;
	}else{
		return false;
	}
}
//un puntero toma la direccion de memoria de una variable, mientras que un doble puntero toma la direccion de memoria de un puntero
void insertarEnArbol(tArbol ** pArbol, int entero)
{
	
	if (arbolVacio(*pArbol) == true){
		*pArbol = malloc(sizeof(tArbol));
		(*pArbol)->dato = entero;
		(*pArbol)->hijoIzquierdo = NULL;
		(*pArbol)->hijoDerecho = NULL;
		cantNodos = cantNodos + 1;
	}else{
		if(entero < (*pArbol)->dato){
			
			printf("Es hijo Izquierdo. \n");
			insertarEnArbol(&(*pArbol)->hijoIzquierdo, entero);
			
		}else {
			if(entero > (*pArbol)->dato){
			
		    	printf("Es hijo Derecho. \n");
		    	insertarEnArbol(&(*pArbol)->hijoDerecho, entero);
	
            }else{
		    
				printf("El valor es duplicado!\n");
		   
		    }
		}	
	}
}


void verEnPreOrden(tArbol * pArbol)
{
	
	if(pArbol != NULL){
		printf("|%d| ",pArbol->dato);
		verEnPreOrden(pArbol->hijoIzquierdo);
		verEnPreOrden(pArbol->hijoDerecho);
	}
}

void verEnInOrden(tArbol * pArbol)
{

	if(pArbol != NULL){
		verEnInOrden(pArbol->hijoIzquierdo);
		printf("|%d| ",pArbol->dato);
		verEnInOrden(pArbol->hijoDerecho);
	}
}

void verEnPostOrden(tArbol * pArbol)
{
	if(pArbol != NULL){
		verEnPostOrden(pArbol->hijoIzquierdo);
		verEnPostOrden(pArbol->hijoDerecho);
		printf("|%d| ",pArbol->dato);
	}
}

void menu()
{
	int opcion, pEntero;
	printf("1.Ingresar datos al arbol: \n");
	printf("2.Visualizar arbol en los distintos ordenes : \n");
	printf("3.Numeros de nodos del Arbol Binario: \n");
	scanf("%d",&opcion);
	
	while(opcion!=0){
		switch (opcion){
			case 1:{
				printf("Digita el numero que debera ingresar al Arbol: ");
				scanf("%d",&pEntero);
				insertarEnArbol(&arbol,pEntero);
				break;
			}
			case 2:{
				printf("Muestra Arbol En PreOrden:\n");
				verEnPreOrden(arbol);
				printf("\nMuestra Arbol En InOrden: \n");
				verEnInOrden(arbol);
				printf("\nMuestra Arbol En PostOrden:\n");
				verEnPostOrden(arbol);
				break;
			}
			case 3:{
				printf("El numero de nodos es de %d ",cantNodos);
				break;
			}
		}
		printf("\n");
		printf("1.Ingresar datos al arbol: \n"); 
		printf("2.Visualizar arbol en los distintos ordenes : \n");
		printf("3.Numeros de nodos del Arbol Binario: \n");
    	scanf("%d",&opcion);
	}
}



int main(){
	menu();
	return 0;
}
