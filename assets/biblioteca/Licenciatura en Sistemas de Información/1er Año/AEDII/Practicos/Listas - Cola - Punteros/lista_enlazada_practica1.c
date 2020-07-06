#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void inicializarLista();
bool listaVacia();
void agregarDatosVenta(int,int,float,char[]);
int cantidadMedVendidos();
void menu();
void listarMedicamentos();
void eliminarCualquierVenta(int);
int cantidadElementos();


typedef struct nodo{
	char descripcion[35];
	int codBarra;
	int cant;
	float precio;
	struct nodo *siguiente;
}tLista;
tLista *lista;

int main(){
	menu();
	return 0;
}

void inicializarLista(){
	lista = NULL;
}

bool listaVacia(){
	if(lista == NULL){
		return true;
	}else{
		return false;
	}
}

void agregarDatosVenta(int v_codBarra,int v_cant,float v_precio,char v_descripcion[]){
	if(listaVacia()){
		lista = malloc(sizeof(tLista));
		lista->codBarra = v_codBarra;
		lista->cant = v_cant;
		lista->precio = v_precio;
		strcpy(lista->descripcion,v_descripcion);
		lista->siguiente = NULL;
		printf("Venta Guardada!\n");
	}else{
		tLista *nuevoNodo;
		nuevoNodo = malloc(sizeof(tLista));
		nuevoNodo->codBarra = v_codBarra;
		nuevoNodo->cant = v_cant;
		nuevoNodo->precio = v_precio;
		strcpy(nuevoNodo->descripcion,v_descripcion);
		nuevoNodo->siguiente = lista;
		lista = nuevoNodo;
		printf("Nueva Venta Guardada!\n");
	}
}

int cantidadMedVendidos(){
	int cantVendidos=0;
	if (listaVacia()){
		printf("La lista esta vacia de Ventas:\n");
	}else{
		tLista *aux;
		aux = lista;
		while(aux!=NULL){
			cantVendidos = cantVendidos + aux->cant;
			aux = aux->siguiente;
		}
	}
	return cantVendidos;
}

void eliminarCualquierVenta(int k){
	tLista *aux, *nodoSuprimir;
	aux = lista;
	int i;
	if(listaVacia()){
		printf("lista Vacia!\n");
	}else{
		if(k <= cantidadElementos() && k > 1){	
			for (i = 1; i < k-1; i++){
				 aux = aux->siguiente;		 
	     	}
		     nodoSuprimir = aux->siguiente;
      		aux->siguiente = nodoSuprimir->siguiente;
     		free(nodoSuprimir);
	     	printf("La venta numero |%d| ha sido elimina:\n",k);
		}else{
			printf("La venta de la posicion |%d| no se puede eliminar:\n",k);
		}
	}
}
void listarMedicamentos(){
	tLista *aux;
	aux = lista;
	if(listaVacia()){
		printf("Lista Vacia!\n");
	}else{
		while(aux!=NULL){
			printf("%s\n",aux->descripcion);
			aux = aux->siguiente;
		}
	}
}

void menu(){
	int opc;
	int v_k;
	printf("1.agregar datos venta\n2.Mostrar cantidad de medicamentos\n3.listar medicamentos\n4.eliminar cualquier venta:\n");
	scanf("%d",&opc);
	while(opc!=0){
		switch(opc){
			case 1:{
				char n[35];
				int cantidad, codigo;
				float precioMedicina;
				
				printf("CODIGO BARRA:\n");scanf("%d",&codigo);
				fflush(stdin);
				printf("DESCRIPCION: \n");gets(n);
				printf("CANTIDAD: \n");scanf("%d",&cantidad);
				printf("PRECIO: \n");scanf("%f",&precioMedicina);
				
				agregarDatosVenta(codigo,cantidad,precioMedicina,n);
				
			     break;
			}
			case 2:{
				printf("la cantidad de medicamentos vendidos es de %d \n",cantidadMedVendidos());
				break;
			}
			case 3:{
				listarMedicamentos();
				break;
			}
			case 4:{
				
				printf("Ingrese el numero de venta que quiere Eliminar: \n");
				scanf("%d",&v_k);
				eliminarCualquierVenta(v_k);
				break;
			}
			
		}
		system("pause");
		system("cls");
		printf("1.agregar datos venta\n2.Mostrar cantidad de medicamentos\n3.listar medicamentos\n4.eliminar cualquier venta:\n");
          scanf("%d",&opc);    
	}
}

int cantidadElementos(){
	int cantElementos =0;
	tLista *aux;
	aux = lista;
	
	while(aux!= NULL){
		cantElementos++;
		aux = aux->siguiente;
	}
	return cantElementos;
}

