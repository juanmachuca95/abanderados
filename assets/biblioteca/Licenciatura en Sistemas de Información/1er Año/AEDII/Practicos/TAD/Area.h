#include<math.h>

float carlcularAreaRectangulo(float,float);

float calcularAreaRectangulo(float base, float altura){
	float area;
	area = base * altura; 
	return area;
}

float calcularAreaTriangulo(float lado1, float lado2, float lado3){
	// formula de heron para caluclar el area de un triangulo sabiendo sus lados
     float semiperimetro;
	float areaTriangulo;
	float p;
	
	semiperimetro = (lado1 + lado2 + lado3) / 2;
	p = semiperimetro;
	
	areaTriangulo = p*(p - lado1)*(p - lado2)*(p - lado3);
	
	areaTriangulo = sqrt(areaTriangulo); //sqrt funcion definida para sacar la raiz 
	return areaTriangulo;	
}

