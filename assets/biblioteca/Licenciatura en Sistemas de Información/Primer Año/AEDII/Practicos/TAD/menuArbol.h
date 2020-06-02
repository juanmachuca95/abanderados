typedef struct Arbol{
	int centro;
	char caracter;
	struct Arbol *hijoIzq;
	struct Arbol *hijoDer;
}tArbol;
tArbol *arbol;

void menuArbol();

void menuArbol(int opcion){
	
	printf(":::::::MENU ARBOL::::::\n");
	
	switch (opcion){
		case 1:{
			printf("NOMBRE EN UN(CHAR) Y NUMERO DEL NODO : ");
			scanf("%d, %c",&n,&c);
			insertarNodo(n,c);
			break;
		}
		case 2:{
			
			break;
		}
	}
}

void insertarNodo(tArbol *pArbol, int num, char car){
	
	if()
	
}
