#include<stdio.h>
#include<stdbool.h>
#define max 20
bool pilaVacia();
bool pilaLlena();
void menu();
void agregarPila();
void mostrarPila();
void desapilarPila();
int topePila();

typedef int tpila[max-1];
tpila pila;

int tope = -1;
int suma=0;
int pulgadas;

int main(){
	menu();
	return 0;
}

bool pilaLlena(){
	if(tope == max-1){
		return true;
	}else{
		return false;
	}
}

bool pilaVacia(){
	if(tope == -1){
		return true;
	}else{
		return false;
	}
}

void menu(){
	int opc;
	printf("1.Ingresar pulgadas de televisores LED.\n");
	printf("2.Listar los elementos de la pila:\n");
	printf("3.Desapilar elementos de la pila:\n");
	printf("4.Mostrar el elemento tope:\n");
	printf("5.Mostrar la cantidad de elementos:\n");
	scanf("%d",&opc);
	while(opc!=0){
		switch (opc){
			case 1:{
				agregarPila();
				break;
			}
			case 2:{
				mostrarPila();
				break;
			}
			case 3:{
				desapilarPila();
				break;
			}
			case 4:{
				printf("El elemento tope es ||%d|| \n",topePila());
				break;
			}
			case 5:{
				printf("La cantidad de elementos de la pila es de ||%d||*\n",suma);
				break;
			}
		}
		system("pause");
		system("cls");
		printf("1.Ingresar pulgadas de televisores LED.\n");
	    printf("2.Listar los elementos de la pila:\n");
    	printf("3.Desapilar elementos de la pila:\n");
    	printf("4.Mostrar el elemento tope:\n");
    	printf("5.Mostrar la cantidad de elementos:\n");
     	scanf("%d",&opc);
    }

}

void agregarPila(){
	int pulgadas;
	printf("Ingresar las pulgadas del televisor LED: \n");
	scanf("%d",&pulgadas);
	if(pilaVacia()==true){
		tope = tope +1;
		pila[tope] = pulgadas;
		suma++;
		printf("Se ha guardado el PRIMER elemento!\n");
	}else{
		if(pilaLlena()!= true){
			if(pila[tope]>=pulgadas){
				tope = tope +1;
				pila[tope]= pulgadas;
				suma++;
			}else{
				printf("La pulgadas de este televisor NO PUEDE SER MAYOR A LA ANTERIOR!\n");
			}
		}else{
			printf("No hay lugar!\n");
		}
	}
}

void mostrarPila(){
	int i;
	for(i=0;i<=tope;i++){
		printf("|%d|\n",pila[i]);
	}
}

void desapilarPila(){
	if(pilaVacia()!=true){
		pulgadas = pila[tope];
		tope = tope -1;
		suma--;
		printf("Elemento Eliminado!\n");
	}else{
		printf("La pila esta VACIA!\n");
	}
}

int topePila(){
	return pila[tope];
}
