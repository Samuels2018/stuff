//pilas en C++
#include"stdio.h"
#include"stdlib.h"

struct nodo{
   int dato;
   nodo *sig;	
};

void addnodo(nodo *&pila, int n) {
	nodo *nuevo_nodo = (nodo*)malloc(sizeof(nodo));
	nuevo_nodo->dato = n;
	nuevo_nodo->sig = pila;
	pila = nuevo_nodo;
	
	return;
}

void sacarpila(nodo *&pila, int &n) {
	nodo *aux =pila;
	n = aux->dato;
	pila = aux->sig;
	delete aux;
	
	return;
}

int main(int argc, char **argv) {
	int n, m;
	char op;
	nodo *pila = NULL;
	
	do{
		printf("q deseas hacer?: \n");
		printf("1 para insertar elementos: \n");
		printf("2 para ver los elementos insertados: \n");scanf("%d",&m);
		switch(m) {
			case 1:
				do{
            		printf("introduce 1 numero para agregarlo a la pila\n"); 
            		printf("o introduce 000 sino deseas introducir mas numeros: \n");scanf("%d",&n);
            		if(n!=000){addnodo(pila,n);}
            		else{break;}
            	}while(n !=000);break;
            case 2:
            	while(pila != NULL) {
            		sacarpila(pila,n);
            		(pila != NULL)?printf("%d, ",n):printf("%d\n",n);
            	}break;
		}
		printf("desea realizar otra operacion?: ");scanf("%c",&op);
	}while(op =='s' || op=='S');
	
	
	return 0;
}
