#include<stdio.h>

//funcion sleep, (retardo 1000 milisegundos equivale a 1 segundo);//

int cuentaRegresiva(int);

int num;
int main(){
	
	printf("En cuantos segundos inicia la cuenta : ");
	scanf("%d",&num);
	cuentaRegresiva(num);
	
	return 0;
}

int cuentaRegresiva(int n){
	if(n < 0){
		printf("El tiempo se ha agotado!\n");
	}else{
		system("cls");
		printf("%d ", n );
		sleep(1);
		n = cuentaRegresiva(n - 1);
	}
}
