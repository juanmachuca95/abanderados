#include<stdio.h>
#include<string.h>
void inicializarArchivo();
void procesoArchivo();
void corteDeControl();

typedef struct{
	char nomb[35];
	int nroCliente;
	int codOperacion;
	float importe;
}tRegistro;

tRegistro regBanco;

FILE *archivo;
int cantClientes = 0;
int nroClienteAnterior, movimientoCuenta;
float totalDepositoXCliente, totalExtraccionXCliente;


int main(){
	system("pause");
	inicializarArchivo();
	procesoArchivo();
	fclose(archivo);
	return 0;
}



void inicializarArchivo(){
	archivo = fopen("Registro_Banco.dat","rb");
	fread(&regBanco,sizeof(regBanco),1,archivo);
	nroClienteAnterior = regBanco.nroCliente;
	
}

void procesoArchivo(){
	while(!feof(archivo)){
		totalDepositoXCliente=0;
		totalExtraccionXCliente=0;
		movimientoCuenta=0;
		printf("\nCuenta \t\tOperacion \tImporte \tNombre\n");
		while(!feof(archivo) && regBanco.nroCliente == nroClienteAnterior){
			
			
			if (regBanco.codOperacion == 1){
				totalExtraccionXCliente = totalExtraccionXCliente + regBanco.importe;
				movimientoCuenta++;
			}else{
				totalDepositoXCliente = totalDepositoXCliente + regBanco.importe;
				movimientoCuenta++;
			}
			printf("\n%d\t\t%d\t\t%.1f\t\t%s\n",regBanco.nroCliente,regBanco.codOperacion,regBanco.importe,regBanco.nomb);
			
			fread(&regBanco,sizeof(regBanco),1,archivo);
		}
		corteDeControl();
	}	
}

void corteDeControl(){
	
	printf("\n");
	printf("El total de Extraccion de la cuenta nro: |%d| es de: |%.1f|\n",nroClienteAnterior,totalExtraccionXCliente);
	printf("El total de Deposito de la cuenta nro |%d| es de: |%.1f|\n",nroClienteAnterior, totalDepositoXCliente);
	printf("Total de movimiento cuenta es de: |%d| operaciones\n",movimientoCuenta);
	printf("El saldo total de la cuenta se encuentra en |%.1f|\n",totalDepositoXCliente - totalExtraccionXCliente);
	printf("***********************************************************\n");
	
	nroClienteAnterior = regBanco.nroCliente;
}

