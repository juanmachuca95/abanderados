#include <stdio.h>
#include "Calculadora.h"

int main(){
	float a = 20.5;
	float b = 21.5;
	float resultadoSuma, resultadoResta, resultadoProducto, resultadoCociente;
	resultadoSuma = 0;
	resultadoResta = 0;
	resultadoProducto = 0; 
	resultadoCociente = 0;
	
	resultadoSuma = suma(a, b);
	printf("%.2f + %.2f = %.2f \n\n", a, b, resultadoSuma);

	resultadoResta = resta(a, b);
	printf("%.2f - %.2f = %.2f \n\n", a, b, resultadoResta);
	
	resultadoProducto = multiplicacion(a, b);
	printf("%.2f X %.2f = %.2f \n\n", a, b, resultadoProducto);
	
	resultadoCociente = division(a, b);
	printf("%.2f / %.2f = %.2f \n\n", a, b, resultadoCociente);
			
	return 0;
}
