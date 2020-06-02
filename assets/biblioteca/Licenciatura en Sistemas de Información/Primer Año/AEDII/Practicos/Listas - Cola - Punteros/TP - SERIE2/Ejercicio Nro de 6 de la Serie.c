/*ESTACIONAMIENTO DE UN SHOPPING, AUTOMOVILES QUE LLEGAN DEL SUR Y SALEN POR EL NORTE */
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20
/*NO ME FUNCIONO PONIENDO EN -1 EL  FRENTE Y EL FINAL ... NO OLVIDAR, SOLO TE ANDUVO PONIENDO (FINAL=0, FRENTE =0,) es decir sur=0, norte=0;*/
void Crearcola();
void Ver();
void Eliminar();
void Menu();
void Disponible();
bool Colavacia();
bool Colallena();

typedef char Cola[MAX][50];
Cola cola;

int norte;
int sur;
int x=0;

int main(){
	Menu();
	return 0;
}

void Crearcola(){
	int norte = 0;
	int sur= 0;
}

bool Colavacia(){
	if (norte == 0 && sur == 0){
		return true;
	}else{
		return false;
	}
}

bool Colallena(){
	if(sur== (MAX)){
		return true;
    }else{
    	return false;
    }
}

void Agregar(){
	if(Colallena()==true){
		printf("Ya estan ocupados los %d lugares de hoy!\n",MAX);
	}else{
		x++;
		fflush(stdin);
		sur++;
		printf("Ingrese la matricula del vehiculo nro %d:",sur);
		gets(cola[sur]);
		printf("Se guardo Exitosamente\n");
	    if(sur==1){
		    norte=1;
	        printf("Es el primero de la lista!\n");
	    }
    }
	system("pause");
}

void Ver(){
	int i;
	if(!Colavacia()){
		printf("Las %d matriculas registradas son:\n",sur);
		for(i=norte;i<=sur;i++){
			printf("%s\n",cola[i]);
		}
	}else{
		printf("Lista de matriculas vacia!\n");
	}
	system("pause");
}

void Eliminar(){
	if(Colavacia()!=true){
		strcpy(cola[norte],"");
		printf("Se ha borrado del registro a la ultima matricula!\n");
		if(norte == sur){
			norte= 0;
			sur= 0;
		}else{
		    norte++;
	    }
	}else{
		printf("No hay datos en la matricula!\n");
	}
	system("pause");
}

void Disponible(){
	printf("Hay %d lugares disponibles!\n",(MAX-x));
	system("pause");
}

void Menu(){
	char resp;
	printf("Bienvenidos al estacionamiento de Shopping Centenario!\n");
	printf("a)Consultar los lugares disponibles:\n");
	printf("b)Agregar matricula de vehiculos entrantes:\n");
	printf("c)Eliminar automovil saliente:\n");
	printf("d)Mostrar todas las matricullas guardadas al momento:\n");
	printf("e)Salir:\n");
	printf("Introduce una opcion:\n");
	scanf("%c",&resp);
	while(resp!='e'){
		switch (resp){
			case 'a':{
				Disponible();
				break;
			}
			case 'b':{
				Agregar();
				break;
			}
			case 'c':{
				Eliminar();
				break;
			}
			case 'd':{
				Ver();
				break;
			}
		}
		system("cls");
		printf("Bienvenidos al estacionamiento de Shopping Centenario!\n");
	    printf("a)Consultar los lugares disponibles:\n");
	    printf("b)Agregar matricula de vehiculos entrantes:\n");
	    printf("c)Eliminar automovil saliente:\n");
	    printf("d)Mostrar todas las matricullas guardadas al momento:\n");
	    printf("e)Salir:\n");
	    printf("Introduce una opcion:\n");
	    scanf("%c",&resp);
	}
	printf("FIN DEL PROGRAMA JUAN!\n");
}


