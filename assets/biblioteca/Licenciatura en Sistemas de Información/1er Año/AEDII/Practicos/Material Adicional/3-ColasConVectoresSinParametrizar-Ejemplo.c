/* Ejemplo de Cola con Vectores */
#include <stdio.h>
#include <stdbool.h>
#define max 5

typedef int tCola [max];	

tCola cola;
int i, frente, final;
char elemento;

void CrearColaVacia();
bool ColaVacia(); 
bool ColaLlena();
void AgregarElemento(int);
void eliminarElementoFrenteMovil();
void eliminarElementoFrenteFijo();
int PrimerElemento();
void visualizarElementos();
void Menu();

int main()
{
	CrearColaVacia();	
	Menu();
	return 0;
}

void CrearColaVacia()
{
	frente = -1;	
	final = -1;	
}

bool ColaVacia()
{
	if ((frente == -1) && (final == -1))
		return true;
	else
		return false;
}

bool ColaLlena()
{
	if (final == (max-1)) 
		return true;
	else
		return false;
}

void AgregarElemento(int pElemento)
{
	if (ColaLlena() != true)
	{		
		final = final + 1;
		cola[final] = pElemento;
		printf("Elemento Insertado! %d\n", cola[final]);
		//significa que es el primer elemento
		if (final == 0 )
			frente = 0;				
	}
	else
		printf("No hay lugar!\n");
}

void eliminarElementoFrenteMovil()
{
	if (ColaVacia() == true)
		printf("No hay elementos por eliminar!!!\n");
	else
	{
		//poner en cero o vacio el elemento del frente
		cola[frente] = 0;
		
		printf("Elemento eliminado!!!\n");		
		
		//si frente y final son iguales significa que elimine el ultimo		
		if (frente == final)
		{
			frente = -1;
			final = -1;
		}
		else
			frente =  frente + 1;					
	}
}
 
void eliminarElementoFrenteFijo()
{
	if (ColaVacia() == true)
		printf("No hay elementos por eliminar!!!\n");
	else
	{
		//poner en cero o vacio el elemento del frente
		cola[frente] = 0;
		
		printf("Elemento eliminado!!!\n");		
		
		//reacomodando...
		for (i = 0; i <= final-1; i++)
		{
			cola[i] = cola[i + 1];
		}			
		
		cola[final] = 0;
						
		if (frente == final)
		{
			frente = -1;
			final = -1;
		}
		
		else
			final = final - 1;
	}
}

int PrimerElemento()
{
	return cola[frente];
}

void visualizarElementos()
{
	int i;
	printf("Elementos en cola: \n");
	for (i = frente; i <= final; i++)
	{
		printf("%d ", cola[i]);
	}
	printf("\n\n");	
}

void Menu()
{	
	int opcion, elem;
	printf("*** Opciones disponibles ***\n");	
	printf("1- Agregar elemento  2- Eliminar elemento 3- Mostrar primer elemento\n");
	printf("4- Visualizar elementos 5- Cola Vacia? 6- Cola Llena? 0- Salir \n");	
	printf("Opcion: ");
	scanf("%d", &opcion); fflush(stdin);
	switch (opcion)
	{
		case 1:
		 	printf("Ingrese elemento entero (0 para cambiar de opcion): ");
			scanf("%d", &elem);
			while (elem != 0)
			{																
				AgregarElemento(elem);
				printf("Ingrese elemento entero (0 para cambiar de opcion): ");
				scanf("%d", &elem); fflush(stdin);
			}
			printf("\n");
			Menu();	
		    break;
		case 2:		    
		    eliminarElementoFrenteFijo();
			printf("\n");
			Menu();	
			break;
		case 3:		 
			printf("Primer elemento: %d\n\n", PrimerElemento());
			printf("Frente: %d Final:%d\n", frente, final);
			Menu();	
			break;		
		case 4:		 
			printf("*** Elementos en cola ***\n");									
			visualizarElementos();
			Menu();	
			break;
		case 5:
			printf("Cola vacia? %s\n", ColaVacia() ? "si" : "no");
			Menu();	
			break;
		case 6:
			printf("Cola llena? %s\n", ColaLlena() ? "si" : "no");
			Menu();	
			break;
		case 0:
			printf("\n");			
			break;
	}
}
