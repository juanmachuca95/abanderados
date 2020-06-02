/* Ejemplo de Pila con Vectores */
/*Autor: Cátedra Algoritmos y Estructuras de Datos II*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define max 5

typedef int tPila [max];	

tPila pila;
tPila v_pila2;

//Prototipado de las funciones
void crearPilaVacia( int * pTope);
bool pilaVacia(int); 
bool pilaLlena(int);
void apilar(int, int*);
void desapilar(int*);
int cima(int);
void visualizarElementos(int);
int sumarElementos(int);

int main(){
	int tope;
	crearPilaVacia(&tope);	
	/*	este ejercicio no contempla el pedido de datos por teclado porque se realizó 
		solo a manera de ejemplificar para mostrar cómo utilizar los procedimientos y/o funciones	
	*/
	printf("Pila vacia? %s\n", pilaVacia(tope) ? "si" : "no");	
	apilar(3, &tope);
	printf("Pila vacia? %s\n", pilaVacia(tope) ? "si" : "no");
	apilar(9, &tope);
	apilar(12, &tope);
	apilar(17, &tope);	
	visualizarElementos(tope);	
	desapilar(&tope);	
	printf("Elementos en pila luego de desapilar: \n");	
	visualizarElementos(tope);	
	printf("Elemento en la cima de la pila: %d \n\n", cima(tope));	
	apilar(25, &tope);	
	printf("Elementos en pila luego de agregar el 5: \n");	
	visualizarElementos(tope);	
	apilar(33, &tope), &tope;
	apilar(7, &tope);		
	printf("Elementos en pila luego de agregar 6 y 7: \n");	
	visualizarElementos(tope);	
	
	printf("Suma: %d", sumarElementos(tope));
	
	return 0;
}

void crearPilaVacia(int* pTope){
	*pTope = -1;	
}

bool pilaVacia(int pTope){
	if (pTope == -1) 
		return true;
	else
		return false;
}

bool pilaLlena(int pTope){
	if (pTope == (max-1)) 
		return true;
	else
		return false;
}

void apilar(int pElemento, int* pTope){
	if (pilaLlena(*pTope) != true)
	{		
		*pTope = *pTope + 1;
		pila[*pTope] = pElemento;		
		printf("Elemento Insertado! %d\n", pila[*pTope]);
	}
	else
		printf("Pila Llena!\n");
}

void desapilar(int* pTope){
	if (pilaVacia(*pTope) == true)
		printf("Pila Vacia!!!\n");
	else
	{
		pila[*pTope] = 0;
		*pTope = *pTope - 1;
		printf("Elemento eliminado!!!\n");		
	}
}

int cima(int pTope){
	return pila[pTope];
}

void visualizarElementos(int pTope){
	int i;
	printf("Elementos en pila: \n");
	for (i = 0; i <= pTope; i++)	{
		printf("%d ", pila[i]);
	}
	printf("\n\n");	
}

int sumarElementos(int pTope){
	int i;
	int suma = 0;
	for (i = 0; i <= pTope; i++)	{
		suma = suma + pila[i];
	}
	return suma;
}



	

