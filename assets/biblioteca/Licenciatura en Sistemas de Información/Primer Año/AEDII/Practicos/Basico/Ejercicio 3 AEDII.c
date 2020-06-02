#include<stdio.h>
#include<string.h>

void insertarFrase();
void invertirFrase();
void procesarFrase();
void preguntar();

char frase[100];
char respuesta;
int i=0;
int j;
	

int main(){
	procesarFrase();
	return 0;
}


void insertarFrase(){
	fflush(stdin);
	printf("INGRESA UNA FRASE: ");
	gets(frase);
	system ("cls");
	printf("La frase ingresada es \n''%s''\n",frase);
	
}

void procesarFrase(){
	
	do {
		insertarFrase();
		invertirFrase();
		preguntar();
	}while(respuesta == 's' || respuesta == 'S');
}

void preguntar(){
	
	fflush(stdin);
	printf("\n\nINGRESAR NUEVA FRASE S/N : ");
	scanf("%c",&respuesta);
	system ("cls");
	
}

void invertirFrase(){
	
	while(frase[i] != '\0'){// Primero le dio un indice a cada caracter del texto ingresado
	    i++;
    }	
    system("pause\n\n");
	printf("\n**LA FRASE INVERTIDA ES**\n");
	printf(" ''");
	for( j=i; j>=0; j--){ // igual "j" a la cantidad de caracteres del texto, por ejemplo 10, este descendera en uno, mientras "j" sea mayor o igual a 0, 
		printf("%c",frase[j]);// asi pues mostrara cada caracter desde el final hacia el principio.
	}
	printf(" ''");
	i=0; 
}
