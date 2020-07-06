/* Grafos Ponderados */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define n 7

typedef int tPeso;

typedef int tVertice;

typedef struct 
{	 
	tVertice origen;
	tVertice destino;		
	tPeso peso;	
}tArco;
 	
typedef bool conjuntoVertices [n];
typedef tPeso conjuntoArcos [n][n];

typedef struct 
{	 		
	conjuntoVertices vertices;
	conjuntoArcos arcos;			
}tGrafo;

void grafoVacioP(tGrafo *);
void agregaVertice(tGrafo *, tVertice);
void agregaArcoP(tGrafo *, tArco);
void borrarVertice(tGrafo *, tVertice);
void borrarArco(tGrafo *, tArco);
int maxVertice(tGrafo *);
void visualizarMatrizPesos(tGrafo *);
void visualizarMatrizAdyacencia(tGrafo *);

tGrafo * grafo;	
tArco arco;	

void grafoVacioP(tGrafo * pGrafo)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		pGrafo->vertices[i] = 0;	
		for (j = 1; j <= n; j++)
		{		
			pGrafo->arcos[i][j]= 0;
		}	
	}
}

void agregaVertice(tGrafo * pGrafo, tVertice vert)
{
	pGrafo->vertices[vert] = 1;
	printf("Se agrego el vertice %d\n", vert);
}

void agregaArcoP(tGrafo * pGrafo, tArco arc)
{
	if(( pGrafo->vertices[arc.origen] == 1) && (pGrafo->vertices[arc.destino] == 1))
	{
		pGrafo->arcos[arc.origen][arc.destino] = arc.peso;	
		printf("Se agrego el arco [%d, %d]\n", arc.origen, arc.destino);
	}					
}

void borrarVertice(tGrafo * pGrafo, tVertice ver)
{
	pGrafo->vertices[ver] = 0;
}

void borrarArco(tGrafo * pGrafo, tArco arc)
{
	pGrafo->arcos[arc.origen][arc.destino] = 0;
}

int maxVertice(tGrafo * pGrafo)
{
	int i, max;
	max = 0;
	for (i = 1; i <= n; i++)
	{	
		if (pGrafo->vertices[i] == 1)
		{
			max = i;
		}				
	}
	return max;
}

void visualizarMatrizPesos(tGrafo * pGrafo)
{
	int i, j, maxVer;
	printf("\nMATRIZ DE PESOS\n\n");
	maxVer = maxVertice(pGrafo);
	for (i = 1; i<= maxVer; i++)
	{
		for (j = 1; j<= maxVer; j++)
		{
			printf("%d ", pGrafo->arcos[i][j]);			
		}	
		printf("\n");
	}
}

void visualizarMatrizAdyacencia(tGrafo * pGrafo)
{	
	int i, j, maxVer;
	printf("\nMATRIZ DE ADYACENCIA\n\n");
	maxVer = maxVertice(pGrafo);
	for (i = 1; i<= maxVer; i++)
	{
		for (j = 1; j<= maxVer; j++)
		{
			if (pGrafo->arcos[i][j] == 0)			
			{
				printf("0");
			}else
			{
				printf("1");
			}
			printf(" ");
		}	
			printf("\n");
	}
}

int main()
{	
	//Inicializar el puntero del grafo	
	grafo = NULL;
	grafo = malloc(sizeof(tGrafo));
	grafoVacioP(grafo);

	agregaVertice(grafo, 1);
	agregaVertice(grafo, 2);
	agregaVertice(grafo, 3);
	
	arco.origen = 1;
	arco.destino = 2;
	arco.peso =5;
	agregaArcoP(grafo, arco);
	
	arco.origen = 2;
	arco.destino = 3;
	arco.peso = 10;
	agregaArcoP(grafo, arco);
	
	arco.origen = 3;
	arco.destino= 3;
	arco.peso =15;
	agregaArcoP(grafo, arco);	
		
	visualizarMatrizPesos(grafo);
	visualizarMatrizAdyacencia(grafo);
	return 0;
}

