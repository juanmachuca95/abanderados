#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int tElem;

typedef struct nodoArbol
{
	tElem contenido;			
    struct nodoArbol *hijoIzdo;    
    struct nodoArbol *hijoDcho;    
}tArbol;

tArbol * arbol;

void CrearArbolVacio(tArbol *);
bool EsArbolVacio(tArbol *);
tArbol * SubIzquierdo();
tArbol * SubDerecho();
int DatoRaiz();
void RecorrerEnPreorden(tArbol *);
void RecorrerEnInorden(tArbol *);
void RecorrerEnPostorden(tArbol *);
void Insertar(tArbol **, tElem);
void Eliminar(tArbol **, tElem);
tArbol * buscar_min(tArbol *);
bool Buscar(tArbol *, tElem);
void Buscar2(tArbol *, tElem);

void CrearArbolVacio(tArbol * pArbol)
{
	pArbol = NULL;		
}

bool EsArbolVacio(tArbol * pArbol)
{
	if (pArbol == NULL)
		return true;
	else
		return false;	
}

//Función que devuelve el Nodo Izquierdo
tArbol * SubIzquierdo()
{
	return arbol->hijoIzdo;
}

//Función que devuelve el Nodo Derecho
tArbol * SubDerecho()
{
	return arbol->hijoDcho;
}

tElem DatoRaiz()
{
	return arbol->contenido;	
}

//Primero se lee el valor del nodo y después se recorren los sub-árboles.
void RecorrerEnPreorden(tArbol * pArbol)
{
	if (pArbol != NULL)
	{
		printf("%d ", pArbol->contenido);
		RecorrerEnPreorden(pArbol->hijoIzdo);
		RecorrerEnPreorden(pArbol->hijoDcho);
	}
}

//Primero se recorre el sub-árbol izquierdo
//luego se lee el valor del nodo y, finalmente
//se recorre el sub-árbol derecho
void RecorrerEnInorden(tArbol * pArbol)
{
	if (pArbol != NULL)
	{		
		RecorrerEnInorden(pArbol->hijoIzdo);
		printf("%d ", pArbol->contenido);
		RecorrerEnInorden(pArbol->hijoDcho);
	}
}

//Se visitan primero los sub-árboles izquierdo y derecho y después se lee el valor del nodo
void RecorrerEnPostorden(tArbol * pArbol) //muestro como caracter
{
	if (pArbol != NULL)
	{		
		RecorrerEnPostorden(pArbol->hijoIzdo);		
		RecorrerEnPostorden(pArbol->hijoDcho);		    	
		printf("%d ", pArbol->contenido);			
	}
}

void Insertar(tArbol ** pArbol, int pDato)
{ 	
	//si el árbol está vacío: if ((*pArbol) == NULL) 
	if (EsArbolVacio(*pArbol)) 
	{ 
		(*pArbol) = malloc(sizeof(tArbol));		
		/* si la memoria está asignada, entonces asigna el dato */
		if ((*pArbol) != NULL) 
		{ 
			(*pArbol)->contenido = pDato;
			(*pArbol)->hijoIzdo = NULL;
			(*pArbol)->hijoDcho = NULL;
		} 
		else 
		{
			printf("No hay memoria disponible!\n", pDato);
		} 
	}
	else 
	{		
		if (pDato < (*pArbol)->contenido) 
		{
			Insertar(&((*pArbol)->hijoIzdo), pDato);
		} 
		else if (pDato > (*pArbol)->contenido) 
		{
			Insertar(&((*pArbol)->hijoDcho), pDato);
		} else 
		{ 
			printf("Valor duplicado!\n");
		}
	}
}

void Eliminar(tArbol ** pArbol, int elem)
{
	tArbol * aux;

	if (EsArbolVacio(*pArbol))
		printf("Elemento no encontrado! \n");   // No existe el nodo
	else 
	{
		if (elem < (*pArbol)->contenido) //seguir por la izquierda
			Eliminar(&((*pArbol)->hijoIzdo), elem);			
		else 
		{
			if (elem > (*pArbol)->contenido) //seguir por la derecha
				Eliminar(&((*pArbol)->hijoDcho), elem);
			else //buscar el elemento a eliminar
			{				
				if ((*pArbol)->hijoIzdo == NULL) //solo un hijo derecho
				{
					aux = *pArbol;
					*pArbol = (*pArbol)->hijoDcho;
					free(aux);
				}
				else   
				{
					if ((*pArbol)->hijoDcho == NULL) //solo un hijo izquierdo
					{
						aux = *pArbol;
						*pArbol = (*pArbol)->hijoIzdo;
						free(aux);
					}
					else //entonces tiene 2 hijos, se reemplaza con el menor del subarbol derecho
					{
						aux = buscar_min((*pArbol)->hijoDcho);
						(*pArbol)->contenido = aux->contenido;					
						Eliminar(&((*pArbol)->hijoDcho), (*pArbol)->contenido);													
					}
				}
			}
		}
	}
}

//Devuelve el nodo del elemento menor
tArbol * buscar_min(tArbol * pArbol)
{
	if (pArbol == NULL)
		return NULL;
	else
		if (pArbol->hijoIzdo == NULL)
			return pArbol;
		else
			return buscar_min(pArbol->hijoIzdo);
}


bool Buscar(tArbol * pArbol ,int pDato)
//Devuelve un puntero al nodo con dato, si el dato está en arbol, o nil en otro caso
{
	if (pArbol == NULL)
		return false;
	else 		
		if (pDato < pArbol->contenido)
			return Buscar(pArbol->hijoIzdo, pDato);
		else 
			if (pDato > pArbol->contenido)
				return Buscar(pArbol->hijoDcho, pDato);
			else 
				return true;
}


void Buscar2(tArbol * pArbol ,int pDato)
//Devuelve la respuesta afirmativa, si el dato está en arbol, o mensaje correspondiente en otro caso
{
	if (pArbol == NULL){
			printf("No existe el elemento!\n");
	}else{	
		if (pDato < pArbol->contenido){
			Buscar2(pArbol->hijoIzdo, pDato);
		}else{ 
			if (pDato > pArbol->contenido){
				Buscar2(pArbol->hijoDcho, pDato);
			}else{
				printf("\nSi Existe el %d!\n",pDato);
			}
		}
	}
}

int main() 
{	

	CrearArbolVacio(arbol);	

	Insertar(&arbol, 32);
	Insertar(&arbol, 64);
	Insertar(&arbol, 20);	
	Insertar(&arbol, 10);
	Insertar(&arbol, 50);	
	Insertar(&arbol, 45);
	Insertar(&arbol, 44);	
	Insertar(&arbol, 50);	
	Insertar(&arbol, 51);		
		
	printf("\nPostOrden: \n");
	RecorrerEnPostorden(arbol);

	printf("\n\nPreOrden: \n");
	RecorrerEnPreorden(arbol);	
	
	printf("\n\nInOrden: \n");
	RecorrerEnInorden(arbol);
	
	Eliminar(&arbol, 50);
	
	printf("\n\nInOrden despues de eliminar: \n");
	RecorrerEnInorden(arbol);
	
	printf("\n\nexiste el valor 3? %s\n", Buscar(arbol, 3) ? "si" : "no");
	printf("\nexiste el valor 50? %s\n", Buscar(arbol, 50) ? "si" : "no");
	
	Buscar2(arbol, 11);
	
	return 0;
}
