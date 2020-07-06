#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

void inicializarPila();
void agregarDatosPila(int,int,int,float);
void ingresarDatos();
void visualizarDatosPila();
void desapilarPila();
bool pilaVacia();
void calcularRecaudado();
void menu();
void Cima();

typedef struct nodo{
	int codProducto;
	int codRubro;
	int cantProducto;
	float precioUnit;
	struct nodo *siguiente;
}tPila;

tPila *pila;


int main(){
	menu();
	return 0;
}


void inicializarPila(){
	pila = NULL;
}

bool pilaVacia(){
	if(pila == NULL){
		return true;
	}else{
		return false;
	}
}

void menu(){
	int opc;
	printf("1. Ingresar datos del producto:\n");
	printf("2. Visualizar datos:\n");
	printf("3. Desapilar elementos de la Pila:\n");
	printf("4. Mostrar total recaudado:\n");
	printf("5. Mostrar la Cima: \n");
	scanf("%d",&opc);
	
	while(opc!=0){
		switch (opc){
			case 1:{
				ingresarDatos();
				break;
			}
			case 2:{
				visualizarDatosPila();
				break;
			}
			case 3:{
				desapilarPila();
				break;
			}
			case 4:{
				calcularRecaudado();
				break;
			}
			case 5:{
				Cima();
				break;
			}
		}
		system("pause");
		system("cls");
		printf("1. Ingresar datos del producto:\n");
    	printf("2. Visualizar datos:\n");
    	printf("3. Desapilar elementos de la Pila:\n");
    	printf("4. Mostrar total recaudado:\n");
    	printf("5. Mostrar la Cima: \n");
     	scanf("%d",&opc);
	}
}

void agregarDatosPila(int vcodProducto, int vcodRubro, int vcantProducto, float vprecioPro){
	if (pilaVacia()){
		tPila * aux;
		aux = pila;
		pila = malloc(sizeof(tPila));
		pila->codProducto = vcodProducto;
		pila->codRubro = vcodRubro;
		pila->cantProducto = vcantProducto;
		pila->precioUnit = vprecioPro;
		pila->siguiente = aux;
		printf("Primer Elemento insertado!\n");
	}else{
		tPila * aux;
		aux = pila;
		pila = malloc(sizeof(tPila));
		pila->codProducto = vcodProducto;
		pila->codRubro = vcodRubro;
		pila->cantProducto = vcantProducto;
		pila->precioUnit = vprecioPro;
		pila->siguiente = aux;
		printf("Elemento insertado!\n");
	}
}

void visualizarDatosPila(){
	tPila *aux;
	aux = pila;
	printf("Los codigos para el RUBRO son: 01.Carnes /02.Verduras /03.Bebidas /04.Lacteos\n");
	printf("*******************************************\n");
	while (aux!=NULL){
		printf("Codigo Producto: %d\n Codigo Rubro: %d\n Cantidad: %d\n Precio Unitario: %.2f\n",aux->codProducto,aux->codRubro,aux->cantProducto,aux->precioUnit);
		printf("*******************************************\n");
		aux = aux->siguiente;
	}
}

void ingresarDatos(){
	int codPro, codRubro, cantPro;
	float preUnit;
	printf("Los codigos para el RUBRO son: 01.Carnes /02.Verduras /03.Bebidas /04.Lacteos\n\n");
	printf("CODIGO PRODUCTO: ");
	scanf("%d",&codPro);
	printf("CODIGO RUBRO: ");
	scanf("%d",&codRubro);
	printf("CANTIDAD: ");
	scanf("%d",&cantPro);
	printf("PRECIO UNITARIO: $");
	scanf("%f",&preUnit);
	agregarDatosPila(codPro,codRubro,cantPro,preUnit);
}


void desapilarPila(){
	tPila *aux;
	aux = pila;
	pila = pila->siguiente;
	free(aux);
	printf("El Elemento de la cima ha sido Eliminado!\n");
}


void calcularRecaudado(){
	tPila *aux;
	aux = pila;
	float recaudado = 0;
	
	while(aux!=NULL){
		recaudado = recaudado + (aux->cantProducto * aux->precioUnit);
		aux = aux->siguiente;
	}
	printf("EL MONTO TOTAL RECAUDADO POR EL SUPERMERCADO ES DE  |%.2f|\n",recaudado);
}

void Cima(){
	tPila *aux;
	aux = pila;
	printf("Codigo Producto: %d\n Codigo Rubro: %d\n Cantidad: %d\n Precio Unitario: %.2f\n",aux->codProducto,aux->codRubro,aux->cantProducto,aux->precioUnit);
}





