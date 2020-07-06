#include<stdio.h>
void abrirArchivo();
void cargarArchivo();
void visualizar();
void menu();
void agregarDatosNuevos();

typedef struct{
	char nomb[35];
	int nroCliente;
	int codOperacion;
	float importe;
}tRegistroBanc;

tRegistroBanc regBanco;


FILE *archivo;

int main(){
	menu();
	return 0;
}


void abrirArchivo(){
	archivo = fopen("Registro_Banco.dat","wb");
}

void cargarArchivo(){
	char respuesta;
	abrirArchivo();
	fflush(stdin);
	printf("Cargar datos en el archivo S/N: ");
	scanf("%c",&respuesta);
	
	printf("************************\n");
	while(respuesta == 's' || respuesta == 'S'){
		fflush(stdin);
		printf("INGRESA EL NOMBRE DEL CLIENTE: ");gets(regBanco.nomb);
		printf("INGRESA EL NUMERO DE CLIENTE: ");scanf("%d",&regBanco.nroCliente);
		printf("INGRESA EL CODIGO DE OPERACION 1.TRANSACCION 2.DEPOSITO: ");scanf("%d",&regBanco.codOperacion);
		printf("INGRESA EL IMPORTA DE LA OPERACION: ");scanf("%f",&regBanco.importe);
		
		fwrite(&regBanco,sizeof(regBanco),1,archivo);
		
		printf("Datos guardados!\n");
		system("pause");
		system("cls");
		
		fflush(stdin);
		printf("Cargar datos en el archivo S/N: ");
	    scanf("%c",&respuesta);
	}
}

void menu(){
	int opc;
	printf("1.Cargar Archivo Nuevo.\n");
	printf("2.Ver datos del archivo.\n");
	scanf("%d",&opc);
	while(opc!=0){
		switch(opc){
			case 1:{
    	        agregarDatosNuevos();
				break;
			}
			case 2:{
				visualizar();
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

void visualizar(){
	archivo = fopen("Registro_Banco.dat","rb");
	fread(&regBanco,sizeof(tRegistroBanc),1,archivo);
	printf("Nro. Cliente \tCod.Operacion \tImporte \tNombre\n");
	while(!feof(archivo)){
		printf("%d \t\t%d \t\t%.1f \t\t%s\n",regBanco.nroCliente,regBanco.codOperacion,regBanco.importe,regBanco.nomb);
		fread(&regBanco,sizeof(regBanco),1,archivo);
	}
	fclose(archivo);
}


void agregarDatosNuevos(){
	abrirArchivo();
	cargarArchivo();
	fclose(archivo);
}
