/* 	
	Este programa realiza el corte sobre una archivo de alumnos por carrera, 
	ordenado según el campo de control correspondiente al código de carrera
*/
#include <stdio.h> 
#include <string.h>
typedef char string[40];
typedef struct
{	    
    int codCarrera, DNI;
    int codSexo, edad;
    string nombreApellido;
}registroAlumnos;	 

registroAlumnos regAlumno;
FILE *archivo;
int codCarreraAnt;
int cantAlumnosTotal, cantAlumnosPorCarrera;
int cantMujeres;
int sumaEdadesPorCarrera, sumaEdadesTotal;

void inicializacion();
void proceso();
void finalizacion();
void corte();

int main(){		
	inicializacion();	
	proceso();		
	finalizacion();
}

void inicializacion()
{
	/*
		Actividades al inicio del programa	
			1. Abrir archivo para lectura
			2. Leer el primer registro
			3. Guardar campo de control anterior
			4. Inicializar contadores/acumuladores generales/totales 
			5. Escribir titulos
	*/
	archivo = fopen("Alumnos.dat", "rb");	
		
    fread(&regAlumno, sizeof(regAlumno), 1, archivo);
    
	codCarreraAnt = regAlumno.codCarrera;
	
	cantAlumnosTotal = 0;	
	sumaEdadesTotal = 0;

	printf("Carrera\tDNI\tSexo\tEdad\tNombre y Apellido\n");
}

void proceso(){
	//Recorrer el archivo hasta el final (feof)
	while (!feof(archivo))
	{	
		/*
			Actividades antes de recorrer los grupos
				1. Inicializar los contadores/acumuladores parciales			
		*/			
		cantAlumnosPorCarrera = 0;
		sumaEdadesPorCarrera = 0;		
		cantMujeres = 0;		
		
		//Con este while trabajamos con cada grupo 
	    while(!feof(archivo) && regAlumno.codCarrera == codCarreraAnt) 
		{			
			/* 
				Actividades por grupo
					1. Actualizar contadores/acumuladores parciales
					2. Mostrar la línea del detalle en el caso que sea necesario
					3. Buscar el mayor/menor del grupo (parcial) en el caso que sea necesario
					4. Leer otro registro (leerRegistro)
			*/
			cantAlumnosPorCarrera = cantAlumnosPorCarrera + 1;
			sumaEdadesPorCarrera = sumaEdadesPorCarrera + regAlumno.edad;
			if(regAlumno.codSexo == 2){
				cantMujeres = cantMujeres + 1;
			}			
									
			printf("%d\t%d\t%d\t%d\t%s\n", regAlumno.codCarrera, regAlumno.DNI, regAlumno.codSexo, regAlumno.edad, regAlumno.nombreApellido);						
			
			fread(&regAlumno, sizeof(regAlumno), 1, archivo);
		}
		//Cuando termina este while significa que terminó un grupo entonces realizamos las actividades del corte
		corte();
	}
}

void corte(){      		
	/* 	
		Actividades del corte de control
			1. Mostrar subtotales (línea de totales del grupo en el caso que el ejercicio lo solicite)
			2. Guardar la clave anterior(campo de control), en este caso codCarrera 		
			3. Calcular promedios/porcentajes parciales en el caso que el problema lo requiera
			4. Actualizar contadores/acumuladores generales			
			5. Buscar el mayor/menor (general) en el caso que el problema lo requiera
			6. Inicializar los contadores/acumuladores parciales
	*/ 		
	
	cantAlumnosTotal = cantAlumnosTotal + cantAlumnosPorCarrera;
	printf("Cantidad de alumnos de la carrera %d: %d\n", codCarreraAnt, cantAlumnosPorCarrera);
	printf("Cantidad de mujeres en la carrera %d: %d\n", codCarreraAnt, cantMujeres);
	printf("Edad promedio de alumnos de la carrera %d: %.2f\n", codCarreraAnt, (float)sumaEdadesPorCarrera/cantAlumnosPorCarrera);
	printf("-------------------------------------------------------\n");
	
	codCarreraAnt = regAlumno.codCarrera;
	
	sumaEdadesTotal = sumaEdadesTotal + sumaEdadesPorCarrera;
	cantAlumnosPorCarrera = 0;
	sumaEdadesPorCarrera = 0;
	cantMujeres = 0;
	
}

void finalizacion(){
	/* 
		Actividades al finalizar
			1. Mostrar totales
			2. Calcular promedios/porcentajes generales en el caso que el problema lo requiera
		    3. Cerrar el archivo
	*/
	printf("Cantidad de alumnos de todas las carreras: %d\n", cantAlumnosTotal);
	printf("Edad promedio de alumnos: %.2f\n\n", (float)sumaEdadesTotal/cantAlumnosTotal);
	
	fclose(archivo);      
}
