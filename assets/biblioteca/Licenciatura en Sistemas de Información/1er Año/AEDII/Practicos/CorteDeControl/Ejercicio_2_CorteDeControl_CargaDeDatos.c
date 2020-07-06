#include<stdio.h>
#include<string.h>

void iniciarArchivo();
void cargarArchivo();
void mostrarDatosArchivo();
void menu();

typedef struct{
	char nombAlumno[35];
	int nroLibreta;
	int codMateria;
	float notaAlumno;
}tRegistros;

tRegistros regNotas;

FILE *archivo;

int main(){
	menu();
	return 0;
}


void iniciarArchivo(){
	archivo = fopen("Registro_Notas.dat","wb");
}

void cargarArchivo(){
	char respuesta;
	fflush(stdin);
	printf("Desea ingresar los datos del Alumno S/N: \n");
	scanf("%c",&respuesta);
	
	while(respuesta == 's'){ 
		
		fflush(stdin);
		printf("Nombre de Alumno: \n");gets(regNotas.nombAlumno);
		printf("Numero de Libreta Universitaria: \n");scanf("%d",&regNotas.nroLibreta);
		printf("Codigo 1.Algoritmo, 2.Logica, 3.Sistemas: \n");scanf("%d",&regNotas.codMateria);
		printf("Nota por Examen: \n");scanf("%f",&regNotas.notaAlumno);
		
		fwrite(&regNotas,sizeof(regNotas),1,archivo);
		printf("Cargado....\n\n");
		
		fflush(stdin);
		printf("Desea ingresar los datos del Alumno S/N: \n");
	    scanf("%c",&respuesta);		
	}
	fclose(archivo);
}

void mostrarDatosArchivo(){
	printf("\nLos datos del Archivo........\n\n");
	archivo = fopen("Registro_Notas.dat","rb");
	printf("Libreta\tMateria\tNota\tNombre\n");
    fread(&regNotas,sizeof(regNotas),1,archivo); 
	while(!feof(archivo)){
		printf("%d \t%d \t%.1f \t%s\n",regNotas.nroLibreta,regNotas.codMateria,regNotas.notaAlumno,regNotas.nombAlumno);
		fread(&regNotas,sizeof(regNotas),1,archivo);
	}
	fclose(archivo);
}

void menu(){
	int opc;
	printf("1.Cargar Archivo Nuevo.\n");
	printf("2.Ver datos del archivo.\n");
	scanf("%d",&opc); 
	while(opc!=0){
		switch(opc){
			case 1:{
				iniciarArchivo();
    	        cargarArchivo();
				break;
			}
			case 2:{
				mostrarDatosArchivo();
				break;
			}
		}
		system("pause");
		system("cls");
		printf("1.Cargar Archivo Nuevo.\n");
	    printf("2.Ver datos del archivo.\n");
	    scanf("%d",&opc);
	}
}









