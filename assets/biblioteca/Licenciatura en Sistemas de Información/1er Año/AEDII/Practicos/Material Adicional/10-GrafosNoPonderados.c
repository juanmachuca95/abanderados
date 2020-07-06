/* Grafos No Ponderados */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define n 7

typedef int tVertice;

typedef struct
{
	tVertice origen;
	tVertice destino;
	
}tArco;

typedef bool conjuntoVertices [n];
typedef bool conjuntoArcos [n][n];	

typedef struct
{
	conjuntoVertices vertices;
	conjuntoArcos arcos;
}tGrafo;

void grafoVacio(tGrafo *);
void agregaVertice(tGrafo *, tVertice);
void agregaArco(tGrafo *, tArco);
void borrarVertice(tGrafo *, tVertice);
void borrarArco(tGrafo *, tArco);
int maxVertice(tGrafo *);
void visualizarMatrizAdyacencia(tGrafo *);

tGrafo * grafo;	
tArco arco;

void grafoVacio(tGrafo * pGrafo)
{
	int x, y;
	
	for (x = 0; x < n; x++)
	{
		pGrafo->vertices[x] = 0;			
		for (y = 0; y < n; y++)
		{
			pGrafo->arcos[x][y] = 0;
		}
	}
}

void agregaVertice(tGrafo * pGrafo, tVertice vert)
{
	pGrafo->vertices[vert] = 1;	
	printf("Se agrego el vertice %d\n", vert);
}

void agregaArco(tGrafo * pGrafo, tArco arc)
{
	if((pGrafo->vertices[arc.origen] == 1) && (pGrafo->vertices[arc.destino] == 1) )
	{
		pGrafo->arcos[arc.origen][arc.destino] = 1;	
		printf("Se agrego el arco [%d, %d]\n", arc.origen, arc.destino);
	}
}

void borrarVertice(tGrafo * pGrafo, tVertice vert)
{
	pGrafo->vertices[vert] = 0;
}

void borrarArco(tGrafo * pGrafo, tArco arc)
{
	pGrafo->arcos[arc.origen][arc.destino] = 0;
}

int maxVertice(tGrafo * pGrafo)
{
	int i, max;
	max = 0;
	for (i = 0; i< n; i++)
	{
		if (pGrafo->vertices[i] == 1)
			max = i;
	}
	return max;
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
			if (pGrafo->arcos[i][j] == true)			
			{
				printf("1");
			}else
			{
				printf("0");
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
	grafoVacio(grafo);

	agregaVertice(grafo, 1);
	agregaVertice(grafo, 2);
	agregaVertice(grafo, 3);
	agregaVertice(grafo, 4);
	
	arco.origen = 1;
	arco.destino = 2;	
	agregaArco(grafo, arco);
	
	arco.origen = 2;
	arco.destino = 3;	
	agregaArco(grafo, arco);
	
	arco.origen = 3;
	arco.destino = 3;	
	agregaArco(grafo, arco);
	
	arco.origen = 3;
	arco.destino = 4;	
	agregaArco(grafo, arco);
	
	arco.origen = 4;
	arco.destino = 2;	
	agregaArco(grafo, arco);
			
	visualizarMatrizAdyacencia(grafo);
	
	return 0;
}
