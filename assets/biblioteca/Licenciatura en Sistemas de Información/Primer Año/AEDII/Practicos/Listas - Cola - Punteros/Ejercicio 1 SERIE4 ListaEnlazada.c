#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
void agregarElementosLista();
void visualizarElementosLista();
void eliminarPrimerElemento();
bool listaVacia();
void menu();


typedef struct nodo{
	char nroLib[45];
	struct nodo *siguiente;
}tLista;

tLista *lista;
char nombreNroLibreta[40];

int main(){
	menu();
	return 0;
}


bool listaVacia(){
	if(lista == NULL){
		return true;
	}else{
		return false;
	}
}


void agregarElementosLista(){
	if(listaVacia()){
		lista = malloc(sizeof(tLista));
        strcpy(lista->nroLib, nombreNroLibreta);
    	lista->siguiente = NULL;
    	printf("Primer Elemento insertado!\n");
    }else{
	    tLista * nuevoNodo;
    	nuevoNodo = malloc(sizeof(tLista));	
    	strcpy(nuevoNodo->nroLib, nombreNroLibreta);		
    	nuevoNodo->siguiente = lista;		
    	lista = nuevoNodo;		
    	printf("Elemento insertado!\n");	
   	}
}

void eliminarPrimerElemento(){
	tLista *aux;
	aux = lista;
	lista = lista->siguiente;
	free(aux);
	printf("Primer Elemento de la Lista Eliminado!\n");
}



void visualizarElementosLista(){
	tLista *aux;
	aux = lista;
	while(aux!=NULL){
		printf("%s \n",aux->nroLib);
		aux = aux->siguiente;
	}
}





void menu(){
	int opc;
	printf("1.Ingrese el nro. Libreta Universitaria:\n2.Visualizar todos los elementos de la lista\n3.Eliminar el primer elemento\n");
	printf("Ingresa opcion!\n");
	scanf("%d",&opc);
	while(opc!=0){
		switch (opc){
			case 1:{
				fflush(stdin);
				printf("Ingresa el nombre y apellido + nro de libreta universitaria:\n");
				gets(nombreNroLibreta);
				agregarElementosLista();
				break;
			}
			case 2:{
				visualizarElementosLista();
				break;
			}
			case 3:{
				eliminarPrimerElemento();
				break;
			}
		}
		system("pause");
		system("cls");
		printf("1.Ingrese el nro. Libreta Universitaria:\n2.Visualizar todos los elementos de la lista\n3.Eliminar el primer elemento\n");
	    printf("Ingresa opcion!\n");
    	scanf("%d",&opc);
	}
}




