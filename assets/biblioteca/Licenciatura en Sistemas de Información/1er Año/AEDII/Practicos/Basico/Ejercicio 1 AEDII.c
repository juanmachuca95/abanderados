#include<stdio.h>		
#include<string.h>

void _mostrarResultado();
void _ingresarDatos();
void _procesarDatos();


char nombApe[40];
int nroCuenta;
int cantDeudor = 0;
int cantAcreedor = 0;
int saldo;
char respuesta;

int main (){
	_procesarDatos();
	_mostrarResultado();	
	
	
	return 0;
}

void _ingresarDatos(){
	
	fflush(stdin);
	printf("NOMBRE Y APELLIDO : \n");
	gets(nombApe);
	printf("NRO CUENTA : \n");
	scanf("%d",&nroCuenta);
	printf("SALDO EN CUENTA : \n");
	scanf("%d",&saldo);
	printf("----------------------\n\n");
	
}

void _procesarDatos(){
	printf("***********BANCO NACION ARGENTINA*************\n");
	printf("Programa para calcular cuantas cuentas con saldo negativo y positivo se ingresan. \n\n");
	
	
	printf("DESEA INGRESAR DATOS DE CUENTA S/N :\n");
	scanf("%s",&respuesta);
	
	while(respuesta == 's' || respuesta == 'S'){
		_ingresarDatos();
		if( saldo < 0){
			cantDeudor++;
		}else{
			cantAcreedor++;
		}
		fflush(stdin);
		printf("DESEA INGRESAR DATOS DE CUENTA S/N: \n");
		scanf("%c",&respuesta);
	}
}

void _mostrarResultado(){
	system("cls");
	printf("HAY  || %d || CUENTAS CON SALDO NEGATIVO Y HAY || %d || CUENTAS CON SALDO POSITIVO \n\n\n\n",cantDeudor, cantAcreedor);
}
