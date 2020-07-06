#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAX 30
void Crearcola();
bool Colavacia();
bool Colallena();
void Agregar();
void Ver();
void Eliminar();
void Disponible();
void Menu();
void Opciones();

int fin, fre;

typedef char Cola[MAX][80];
Cola cola;

int main(){
	Menu();
	return 0;
}
void Crearcola(){
	int fre=0;
	int fin=0;
}
bool Colavacia(){
	if (fin == 0 && fre == 0){
		return true;
	}else{
		return false;
	}
}
bool Colallena(){
	if(fin == MAX){
		return true;
	}else{
		return false;
	}
}
void Agregar(){
	if(Colallena()==true){
		printf("No hay lugares disponibles para guardar embarcaciones!n");
	}else{
		fflush(stdin);
		fin++;
		printf("Registra los datos de la embarcacion:\n");
		gets(cola[fin]);
		printf("Datos guardados\n");
		if(fin == 1){
			fre = 1;
			printf("Se agrego la primer embarcacion!\n");
		}
	}
	system("pause");
}
void Ver(){
	int i;
	if(Colallena()==true){
		printf("No hay elementos en la Cola!\n");
	}else{
		for(i=fre;i<=fin;i++){
			printf("%s\n",cola[i]);
		}
	}
	system("pause");
}
void Eliminar(){
	if(Colavacia()==true){
		printf("La cola de Embarcaciones esta VACIA!\n");
	}else{
		strcpy(cola[fre],"");
		printf("Embarcacion borrada!\n");
		if(fre==fin){
			fre=0;
			fin=0;
		}else{
			fre++;
		}
	}
	system("pause");
}
void Disponible(){
	printf("Hay %d lugares disponibles!\n",(MAX-fin));
	system("pause");
}
void Menu(){
	char resp;
	Opciones();
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
				Ver();
				break;
			}
			case 'd':{
				Eliminar();
				break;
			}
		}
		system("cls");
		Opciones();
		scanf("%c",&resp);
	}
	printf("Fin del programa!\n");
}
void Opciones(){
	printf("Bienvenidos a la Represa Yacireta!\n");
	printf("a)Consultar disponibilidad de embarcaciones!\n");
	printf("b)Agregar embarcacion a la Cola!\n");
	printf("c)Ver las embarcaciones registradas!\n");
	printf("d)Eliminar embarcacion saliente!\n");
	printf("e)Salir!\n");
	printf("Ingresa opcion!:\n");
}






