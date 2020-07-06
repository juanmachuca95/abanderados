#include<stdio.h>
#include<string.h>
void ingresarDatos();
void procesarDatos();
void preguntaInicio();

char nomb[40];
char respuesta;
int horas;
int horasExtras;
float salarioTotal;
float salarioNormal = 525;


int main(){
	
	printf("CALCULAR SALARIO DE LOS TRABAJADORES \n\n");
	
	preguntaInicio();
	procesarDatos();
	
	return 0;
	
}



void ingresarDatos(){
	fflush(stdin);
	printf("\nSISTEMA PARA CALCULAR EL SALARIO REAL: \n");
	printf("TRABAJOR : ");gets(nomb);
	printf("HORAS DE TRABAJO POR SEMANA: ");
	scanf("%d",&horas);
	printf("-----------------------\n");
	
}

void procesarDatos(){
	
	while(respuesta == 's' || respuesta == 'S'){
		ingresarDatos();
		if(horas > 35){
    		horasExtras = horas - 35;
    		salarioTotal = salarioNormal + (horasExtras * 22); 
    		horasExtras = 0;
    	}else{
	    	if(horas == 35){
	    		salarioTotal = salarioNormal;
	    	}else{
	    		salarioTotal = horas * 15;
	    	}
	    }
    	printf("SI | %s | TRABAJO | %d | HORAS \n",nomb,horas);
    	printf("SU SALARIO CORRESPONDIENTE ES DE : $ %2.f \n",salarioTotal);
    	preguntaInicio();
	}
		
}

void preguntaInicio(){
	fflush(stdin);
	printf("\nDESEA AGREGAR DATOS: S/N \n");
	scanf("%c",&respuesta);
	system("cls");
	
}



















