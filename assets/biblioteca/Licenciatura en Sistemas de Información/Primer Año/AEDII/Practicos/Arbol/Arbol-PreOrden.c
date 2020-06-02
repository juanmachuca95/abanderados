#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


typedef struct nodoArbol{
	int contenido;
	struct nodoArbol *hijoIzquierdo;
	struct nodoArbol *hijoDerecho;
}tArbol;

tArbol *arbol;

void recorrerEnPreorden(tArbol *);
void recorrerEnInorden(tArbol *);
void recorrerEnPostOrden(tArbol *);

void crearArbolVacio(tArbol *);
bool esArbolVacio(tArbol *);
void insertarElemento(tArbol **, int);
tArbol * subIzquiedo();
tArbol * subDerecho();
int datoRaiz();



//4     19     -7     49     100     0     22     12 
int main(){
	crearArbolVacio(arbol);
	
	insertarElemento(&arbol,4);
	insertarElemento(&arbol,19);
	insertarElemento(&arbol,-7);
	insertarElemento(&arbol,49);
	insertarElemento(&arbol,100);
	insertarElemento(&arbol,0);
	insertarElemento(&arbol,22);
	insertarElemento(&arbol,12);
	
	printf("Recorrido en Pre - Orden: ");
	recorrerEnPreorden(arbol);
    
	printf("\nRecorrido en In -  Orden: ");
    recorrerEnInorden(arbol);
    
	printf("\nRecorrido en Post - Orden: ");
	recorrerEnPostOrden(arbol);
    return 0;
}

tArbol * subIzquierdo(){
	return arbol->hijoIzquierdo;
}

tArbol *subDerecho(){
	return arbol->hijoDerecho;
}

int datoRaiz(){
	return arbol->contenido;
}

void crearArbolVacio(tArbol * pArbol){
	pArbol == NULL;
}

bool esArbolVacio(tArbol * pArbol){
	if(pArbol == NULL){
		return true;
	}else{
		return false;
	}
}

void insertarElemento(tArbol ** pArbol, int pDato){
	
	if((*pArbol) == NULL){
		(*pArbol) = malloc(sizeof(tArbol));
		
		(*pArbol)->contenido = pDato;
		(*pArbol)->hijoIzquierdo = NULL;
		(*pArbol)->hijoDerecho = NULL;
	
	}else{
		if(pDato < (*pArbol)->contenido){
			insertarElemento(&((*pArbol)->hijoIzquierdo), pDato);
		}else{
			if(pDato > (*pArbol)->contenido){
				insertarElemento(&((*pArbol)->hijoDerecho), pDato);
			}else{
				printf("Elemento Duplicado!\n");
			}
		}
	}
}


void recorrerEnPreorden(tArbol * pArbol){
	
	if(pArbol != NULL){
		printf("%d ",pArbol->contenido);
		recorrerEnPreorden((pArbol)->hijoIzquierdo);
		recorrerEnPreorden((pArbol)->hijoDerecho);
	}
}

void recorrerEnInorden(tArbol * pArbol){
	if(pArbol != NULL){
		recorrerEnInorden((pArbol)->hijoIzquierdo);
		printf("%d ",pArbol->contenido);
		recorrerEnInorden((pArbol)->hijoDerecho);
	}
}

void recorrerEnPostOrden(tArbol * pArbol){
	if(pArbol != NULL){
		recorrerEnPostOrden((pArbol)->hijoIzquierdo);
		recorrerEnPostOrden((pArbol)->hijoDerecho);
		printf("%d ",pArbol->contenido);
	}
}


