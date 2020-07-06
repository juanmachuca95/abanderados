#include<stdio.h>
#include"Area&Perimetro.h"

float a, b, a1, a2, a3;
float areaRectangulo, areaTriangulo, perimetroRec;
int main(){
	printf("\n****Calcular area de un Rectangulo****\n");
	printf("Ingrese la base cm2: \n");scanf("%f",&a);
	printf("Ingrese la altura cm2:\n");scanf("%f",&b);
	
	areaRectangulo = calcularAreaRectangulo(a,b);
	perimetroRec = perimetroRectangulo(a,b);
	printf("\n|||El area es igual a %.1f * %.1f = %.1f cm2|||\n",a,b, areaRectangulo);
	printf("\n|||El perimetro es de %.1f|||\n",perimetroRec);
	
	printf("\n****Calcular area de un Triangulo****\n");
	printf("ingrese la medida del lado 1: \n");scanf("%f",&a1);
	printf("Ingrese la medida del lado 2:\n");scanf("%f",&a2);
	printf("Ingrese la medida del lado 3:\n");scanf("%f",&a3);
	
	areaTriangulo = calcularAreaTriangulo(a1,a2,a3);
	printf("|||El area del triangulo es de %.1f cm2:|||\n",areaTriangulo);
	
	return 0;
}
