#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct nodoArbol{
	int dato;
	struct nodoArbol * hijoIzquierdo;
	struct nodoArbol * hijoDerecho;
}tArbol;

tArbol * arbol;

void crearArbol(tArbol*);
bool esArbolVacio(tArbol*);
void insertar_Arbol(tArbol**,int);
void buscarDatosEnArbol(tArbol*,int);
void menu();

int main(){
	crearArbol(arbol);
	menu();
	return 0;
}

void crearArbol(tArbol * pArbol){
	pArbol = NULL;
}

bool esArbolVacio(tArbol * pArbol){
	if(pArbol == NULL){
		return true;
	}else{
		return false;
	}
}

void insertar_Arbol(tArbol ** pArbol, int entPositivo){
	
	if(esArbolVacio(*pArbol)==true){
		
		(*pArbol) = malloc(sizeof(tArbol));
		(*pArbol)->dato = entPositivo;
		(*pArbol)->hijoIzquierdo = NULL;
		(*pArbol)->hijoDerecho = NULL;
	
	}else{
		if(entPositivo < (*pArbol)->dato){
			insertar_Arbol(&((*pArbol)->hijoIzquierdo), entPositivo);
		}else{
			if(entPositivo > (*pArbol)->dato){
				insertar_Arbol(&((*pArbol)->hijoDerecho), entPositivo);
			}else{
				printf("Valor Duplicado!\n");
			}
		}
	}
}

void buscarDatosEnArbol(tArbol * pArbol, int pDato){
	
	if (esArbolVacio(pArbol)== true){
		printf("El dato no existe!\n");
	}else{
		if(pDato < pArbol->dato){
			buscarDatosEnArbol(pArbol->hijoIzquierdo, pDato);
		}else{
			if(pDato > pArbol->dato){
				buscarDatosEnArbol(pArbol->hijoDerecho, pDato);
			}else{
     			printf("El %d si, existe en el Arbol\n",pDato);
			}
		}
	}	
}

void menu(){
	int opc, menu;
	do{
		printf("1.Ingresa elementos en el Arbol.\n");
		printf("2.Buscar un dato en el Arbol.\n");
		printf("Que deseas hacer¿?: ");
		scanf("%d",&opc);
		switch (opc){
			case 1:{
				int num;
				printf("Ingresa un entero positivo al Arbol: ");
				scanf("%d",&num);
				if(num < 0){
					printf("Error\n");
				}else{
					insertar_Arbol(&arbol, num);
				}
				break;
			}
			case 2:{
				int busqeDato;
				printf("Digite el numero que quiere buscar : ");
				scanf("%d",&busqeDato);
				buscarDatosEnArbol(arbol, busqeDato);
				break;
			}		
		}
		system("pause");
		system("cls");
		printf("Ingresar al Menu ¿? 1.Continua 0.Salir\n");
		scanf("%d",&menu);
		
	}while(menu!=0);
}
