#include<stdio.h>
#include<string.h>
void abrirArchivo();
void procesoArchivo();
void corteDeControl();



typedef struct{
	char nombAlumno[35];
	int nroLibreta;
	int codMateria;
	float notaAlumno;
}tRegistro;

tRegistro regNotas;

FILE *archivo;

int nroLibretaAnt;
int cantNotas=0;
float acumularNotas, acumularNotasLog, acumularNotasSis;
float proAlg, proLog, proSis;



int main(){
	abrirArchivo();
	procesoArchivo();
	fclose(archivo);
	return 0;
}

void abrirArchivo(){
	archivo = fopen("Registro_Notas.dat"," rb");
	fread(&regNotas,sizeof(regNotas),1,archivo);
	nroLibretaAnt = regNotas.nroLibreta;
	
}

void procesoArchivo(){
	int cantNotasAlgoritmo, cantNotasLogica, cantNotasSistema;
	float notasAlgoritmo, notasLogica, notasSistemas;
	
	
	while(!feof(archivo)){
		
		printf("\n datos por nro Libreta %d *\n\n",nroLibretaAnt);
		while(!feof(archivo) && regNotas.nroLibreta == nroLibretaAnt){
			
			if(regNotas.codMateria == 1){
				cantNotas++;
				acumularNotas = acumularNotas + regNotas.notaAlumno;
				proAlg = acumularNotas / cantNotas;
			}else{
				if(regNotas.codMateria == 2){
					cantNotas++;
			     	acumularNotas = acumularNotas + regNotas.notaAlumno;
					proLog = acumularNotas / cantNotas;
				}else{
					if(regNotas.codMateria == 3){
						cantNotas++;
			          	acumularNotas = acumularNotas + regNotas.notaAlumno;
			  	     	proSis = acumularNotas / cantNotas;
					}
 				}	
			}
			printf("%d \t%d \t%.1f \t%s\n",regNotas.nroLibreta,regNotas.codMateria,regNotas.notaAlumno,regNotas.nombAlumno);
			fread(&regNotas,sizeof(regNotas),1,archivo);
		}

		corteDeControl();
	}
}

void corteDeControl(){

	
	printf("\nPromedios\n");
	printf("Algoritmo |%.1f| Logica |%.1f| Sistemas |%.1f|\n",proAlg,proLog,proSis);
	
	nroLibretaAnt = regNotas.nroLibreta;
	
	acumularNotas = 0; 
	cantNotas = 0;
	
}

