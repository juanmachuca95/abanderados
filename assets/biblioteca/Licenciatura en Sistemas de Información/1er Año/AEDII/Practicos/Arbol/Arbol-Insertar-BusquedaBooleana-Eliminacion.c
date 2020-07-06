#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct nodoArbol{
	int raiz;
	struct nodoArbol *hijoIzquierdo;
	struct nodoArbol *hijoDerecho;
}tArbol;

tArbol * arbol;

void crearArbol(tArbol*);
bool arbolVacio(tArbol*);
void insertar_en_Arbol(tArbol**, int);
void busquedaEnArbol(tArbol*, int);
void eliminarElementoDelArbol(tArbol**, int);
tArbol * buscar_min(tArbol*);
void menu();
int contarEnInorden(tArbol*);
int cont=0;

int main(){
	crearArbol(arbol);
	menu();
	return 0;
}


void crearArbol(tArbol * pArbol){
	pArbol = NULL;
}

bool arbolVacio(tArbol * pArbol){
	if(pArbol == NULL){
		return true;
	}else{
		return false;
	}
}

void insertar_en_Arbol(tArbol**pArbol, int pDato){
	
	if(arbolVacio(*pArbol)==true){
		
		*pArbol = malloc(sizeof(tArbol));
		(*pArbol)->raiz = pDato;
		(*pArbol)->hijoIzquierdo = NULL;
		(*pArbol)->hijoDerecho = NULL;
		
	}else{
		if(pDato < (*pArbol)->raiz){
			insertar_en_Arbol(&(*pArbol)->hijoIzquierdo, pDato);
		}else{
			if(pDato > (*pArbol)->raiz){
				insertar_en_Arbol(&(*pArbol)->hijoDerecho, pDato);
			}else{
				printf("El valor es duplicado!\n");
			}
		}
	}
}

void busquedaEnArbol(tArbol * pArbol, int pDato){
	
	if(arbolVacio(pArbol) == true){
		printf("El valor ingresado no existe! \n");
	}else{
		if(pDato < pArbol->raiz){
			busquedaEnArbol(pArbol->hijoIzquierdo, pDato);
		}else{
			if(pDato > pArbol->raiz){
				busquedaEnArbol(pArbol->hijoDerecho, pDato);
			}else{
				printf("El valor %d se ha encontrado en el Arbol\n",pDato);
			}
		}
	}
}

void eliminarElementoDelArbol(tArbol ** pArbol, int pDato){
	
	tArbol * aux;
	
	if(arbolVacio(*pArbol) == true){
		printf("El dato no fue encontrado!\n");
	}else{
		if(pDato < (*pArbol)->raiz){
			eliminarElementoDelArbol(&(*pArbol)->hijoIzquierdo, pDato);
		}else{
			if(pDato > (*pArbol)->raiz){
				eliminarElementoDelArbol(&(*pArbol)->hijoDerecho, pDato);
			}else{
				if((*pArbol)->hijoIzquierdo == NULL){
					aux = (*pArbol)->hijoDerecho;
					*pArbol = (*pArbol)->hijoDerecho;
					free(aux);
					printf("Eliminado!\n");
				}else{
					if((*pArbol)->hijoDerecho == NULL){
						aux = (*pArbol)->hijoIzquierdo;
						*pArbol = (*pArbol)->hijoIzquierdo;
						free(aux);
						printf("Eliminado!\n");
					}else{
						aux = buscar_min((*pArbol)->hijoDerecho);
						(*pArbol)->raiz = aux->raiz;					
						eliminarElementoDelArbol(&((*pArbol)->hijoDerecho), (*pArbol)->raiz);	
					}
				}
			}
		}
	}
}


tArbol * buscar_min(tArbol * pArbol)
{
	if (pArbol == NULL)
		return NULL;
	else
		if (pArbol->hijoIzquierdo == NULL)
			return pArbol;
		else
			return buscar_min(pArbol->hijoIzquierdo);
}

void menu(){
	int menu, opc, pdato;
	do{
		printf("Arbol: 4-3-1-6-8-7-13 \n\n");
		printf("1. Para agregar al Arbol. \n");
		printf("2. Para buscar un dato. \n");;
		printf("3. Para Elmininar un dato del Arbol. \n");
		printf("4. Arbol Pre- Cargado.\n");
		printf("5. Cantidad de Nodos de un Arbol.\n");
		printf("Que deseas hacer??. : ");
		scanf("%d",&opc);
		
		switch(opc){
			case 1:{
				printf("Numero: ");
				scanf("%d",&pdato);
				insertar_en_Arbol(&arbol, pdato);
				break;
			}
			case 2:{
				printf("Buscar: ");
				scanf("%d",&pdato);
				busquedaEnArbol(arbol, pdato);
				break;
			}
			case 3:{
				printf("Eliminar: ");
				scanf("%d",&pdato);
				eliminarElementoDelArbol(&arbol, pdato);
				break;
			}
			case 4:{
				insertar_en_Arbol(&arbol, 4);
				insertar_en_Arbol(&arbol, 3);
				insertar_en_Arbol(&arbol, 1);
				insertar_en_Arbol(&arbol, 6);
				insertar_en_Arbol(&arbol, 8);
				insertar_en_Arbol(&arbol, 7);
				insertar_en_Arbol(&arbol, 13);
				break;
			}
			case 5:{
				printf("Cantidad de Nodos ingresados = |%d|.",contarEnInorden(arbol));
				break;
			}
		}
		printf("\n*1.MENU - 0.SALIR**: ");
		scanf("%d",&menu);
		system("pause");
	    system("cls");
	}while(menu != 0);
}


int contarEnInorden(tArbol * pArbol){
    	if(pArbol != NULL){
    		contarEnInorden(pArbol->hijoIzquierdo);
         	cont = cont +1;
         	contarEnInorden(pArbol->hijoDerecho);
    	}
    	return cont;
}
