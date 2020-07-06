#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define max 7

typedef int tipoVector [max];	

tipoVector A, B, C, D;

void generarVector(tipoVector);
void verVector(tipoVector);
void SeleccionDirecta(tipoVector);
void InsercionDirecta(tipoVector);
void OrdenacionPorIntercambio(tipoVector);
void OrdenacionBurbujaMejorada(tipoVector);

void generarVector(tipoVector pVector)
{
	int i;
	for (i = 0; i < max; i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d", &pVector[i]); fflush(stdin);
	}
}

void verVector(tipoVector pVector)
{
	int i;
	printf("\nContenido del vector:\n");
	for (i = 0; i < max; i++)
	{
		printf("%d\t", pVector[i]);
	}
}

void SeleccionDirecta(tipoVector pVector)
{
	//Efecto: se ordena v ascendentemente
	int i, j, posMenor;
	int valMenor, aux;
	
	for (i = 0; i < max-1; i++)  //n-1 pasadas
	{	
		valMenor = pVector[i];
		posMenor = i;
		
		for (j = i+1; j < max; j++) //el número de comparaciones decrece
		{
			if (pVector[j] < valMenor)
			{
				//se actualiza el nuevo valor menor y la posición donde se encuentra
				valMenor = pVector[j];
				posMenor = j;
			}
		}
		if (posMenor != i) 
		{
			//Si el menor no es pVector[i], se intercambian los valores
			aux = pVector[i];
			pVector[i] = pVector[posMenor];
			pVector[posMenor] = aux;
		}
	}
}

void InsercionDirecta(tipoVector pVector)
{
	int i, j;
	int aux;

	for (i = 1; i < max; i++) 	
	{
		aux = pVector[i];		
		j = i - 1;		
		while ((j >= 0) && (pVector[j] > aux))  
		{
			pVector[j+1] = pVector[j];
			//Desplazamiento de los valores mayores que pVector[i]
			j = j-1;											
		}
		pVector[j+1] = aux;		
	}
}

void OrdenacionPorIntercambio(tipoVector pVector)
{
	//Efecto: se ordena v ascendentemente 
	int i, j;
	int aux;	
	
	for (i = 0; i < max-1; i++)  //n-1 pasadas
	{
		for (j = 0; j < max-1; j++)  //n-1 comparaciones
		{
		//for (j = 1; j < max-i; j++) //->opcion2			
			if (pVector[j] > pVector[j+1])  
			{ 
				//intercambio
				aux = pVector[j];
				pVector[j] = pVector[j+1];
				pVector[j+1] = aux;
			}			
		}		
	}
}

void OrdenacionBurbujaMejorada(tipoVector pVector)
{
	//Efecto: se ordena v ascendentemente
	int i, j;
	int aux;
	bool bandera;

	bandera = false;
	i = 0;
	while ((bandera == false) && (i < max))
	{
		bandera = true;	
		for (j = 0; j < max-1; j++)		
		{
			//Se busca el menor desde atras y se situa en vi
			if (pVector[j] > pVector[j+1])
			{
				//intercambio
				aux = pVector[j];
				pVector[j] = pVector[j+1];
				pVector[j+1] = aux;
				bandera = false;
			}
		}
		i = i+1;				
	}
}

int main()
{
	printf("\nIngrese A:\n");
	generarVector(A);	
	printf("\nA:");
	verVector(A);
	SeleccionDirecta(A);
	printf("\nVector A luego de la ordenacion: ");	
	verVector(A);
	printf("\n");
	
	printf("\nIngrese B:\n");
	generarVector(B);	
	printf("\nB:");
	verVector(B);
	InsercionDirecta(B);
	printf("\nVector B luego de la ordenacion: ");	
	verVector(B);
	printf("\n");

	printf("\nIngrese C:\n");
	generarVector(C);	
	printf("\nC:");
	verVector(C);
	OrdenacionPorIntercambio(C);
	printf("\nVector C luego de la ordenacion: ");	
	verVector(C);
	printf("\n");
	
	printf("\nIngrese D:\n");
	generarVector(D);	
	printf("\nD:");
	verVector(D);
	OrdenacionBurbujaMejorada(D);
	printf("\nVector D luego de la ordenacion: ");	
	verVector(D);
	printf("\n");
		
	return 0;
}


