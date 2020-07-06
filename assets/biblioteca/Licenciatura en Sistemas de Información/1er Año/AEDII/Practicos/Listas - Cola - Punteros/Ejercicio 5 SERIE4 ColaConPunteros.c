#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h> 
void inicializarCola();
bool colaVacia();
void agregarDatosClientes(char[],int,int);
void ingresarDatosBanco();
void eliminarTurno();
void visualizarCola();
void cantTransaccionesYConsultas();
void menu();
	
typedef struct nodo{
	char nomb[45];
	int motivo;
	int nroTurno;
	struct nodo *siguiente;
}tApNodo;

typedef struct{
	tApNodo *principio;
	tApNodo *final;
}tCola;

tCola cola;

int main(){
	menu();
	return;
}

void menu(){
	int opc;
	printf("1.INGRESAR DATOS PARA EMITIR TICKET Y TURNO:\n");
	printf("2. VISUALIZAR LAS PERSONAS PARA LA ATENCION:\n");
	printf("3. ELIMINAR UN TURNO Y TICKET:\n");
	printf("4. DEVOLVER LA CANTIDAD DE PERSONAS PARA TRANSACCION Y CONSULTAS:\n");
	scanf("%d",&opc);
	while(opc!=0){
		switch(opc){
			case 1:{
				ingresarDatosBanco();
				break;
			}
			case 2:{
				visualizarCola();
				break;
			}
			case 3:{
				eliminarTurno();
				break;
			}
			case 4:{
				cantTransaccionesYConsultas();
				break;
			}
		}
		system("pause");
		system("cls");
		printf("1.INGRESAR DATOS PARA EMITIR TICKET Y TURNO:\n");
    	printf("2. VISUALIZAR LAS PERSONAS PARA LA ATENCION:\n");
    	printf("3. ELIMINAR UN TURNO Y TICKET:\n");
    	printf("4. DEVOLVER LA CANTIDAD DE PERSONAS PARA TRANSACCION Y CONSULTAS:\n");
    	scanf("%d",&opc);
	}
}

void inicializarCola(){
	cola.principio = NULL;
	cola.final = NULL;
}

bool colaVacia(){
	if(cola.final == NULL){
		return true;
	}else{
		return false;
	}
}

void agregarDatosClientes(char v_nomb[], int v_mot, int v_nroTur){
	tApNodo *nuevoNodo;
	nuevoNodo = malloc(sizeof(tApNodo));
	strcpy(nuevoNodo->nomb, v_nomb);
	nuevoNodo->motivo = v_mot;
	nuevoNodo->nroTurno = v_nroTur; 
	nuevoNodo->siguiente = NULL;
	if(colaVacia()){
		cola.principio = nuevoNodo;
		cola.final = nuevoNodo;
	}else{
		cola.final->siguiente = nuevoNodo;
		cola.final = nuevoNodo;
	}
	printf("El turno y el TICKET han sidos generados!\n");
}

void ingresarDatosBanco(){
	char vnomb[40];
	int vmot, vnroTur;
	fflush(stdin);
	printf("NOMBRE Y APELLIDO: ");gets(vnomb);
	printf("MOTIVO 01.TRANSACCION 02.CONSULTA: ");scanf("%d",&vmot);
	printf("NUMERO DEL TURNO: ");scanf("%d",&vnroTur);
	
	agregarDatosClientes(vnomb,vmot,vnroTur);
}

void eliminarTurno(){
	tApNodo *nodoEliminar;
	if(colaVacia()){
		printf("No hay turnos ni tickets!\n");
	}else{
		if(cola.principio == cola.final){
			nodoEliminar = cola.principio;
			free(nodoEliminar);
			cola.principio = NULL;
			cola.final = NULL;
			printf("El turno se ha eliminado con Exito!\n");
		}else{
			nodoEliminar = cola.principio;
			cola.principio = nodoEliminar->siguiente;
			free(nodoEliminar);
			printf("El turno se ha eliminado con Exito!\n");
		}
	}
}

void visualizarCola(){
	tApNodo * aux;
	aux = cola.principio;
	printf("*********************\n");
	while(aux!=NULL){
		printf("NOMBRE Y APELLIDO: %s\nTURNO: %d\n",aux->nomb,aux->nroTurno);
		if(aux->motivo == 1){
			printf("MOTIVO ''TRANSACCIONES''\n");
		}else{
			printf("MOTIVO ''CONSULTAS''\n");
		}
		printf("*********************\n");
		aux = aux->siguiente;
	}
}

void cantTransaccionesYConsultas(){
	tApNodo *aux;
	aux = cola.principio;
	
	int cantTransacciones=0;
	int cantConsultas=0;
	
	while(aux!=NULL){
		if(aux->motivo == 1 || aux->motivo == 01){
			cantTransacciones++;
		}else{
			cantConsultas++;
		}
		aux = aux->siguiente;
	}
	printf("HAY |%d| PERSONAS PARA TRANSACCIONES\n",cantTransacciones);
	printf("HAY |%d| PERSONAS PARA CONSULTAS\n",cantConsultas);
}




