#include<stdio.h>
#include<stdlib.h>

/*
	Tda PILA[elemento]
	LAS OPERACIONES DEL TDA PILA SON
	
	crear_pila: ---> Pila
	es_vacia:Pila--->Logico
	talla:Pila--->Entero
	apilar:Pila X elemento--->Pila
	desapilar:Pila--->Pila
	frente:Pila--->Elemento

*/

struct Nodo{
	int elemento;
	struct Nodo* proximo;
};

struct Pila{
	int talla;
	struct Nodo* tope;
};


/*		PROTOTIPOS DE LAS DEFINICIONES DE LAS OPERACIONES DE PILA		*/
void crear_pila(struct Pila *P);
int es_vacia(struct Pila P);
int talla(struct Pila P);
int frente(struct Pila P);
void apilar(struct Pila *P, int x);
void desapilar(struct Pila *P);

int main(){
	struct Pila S;
	int i;
	crear_pila(&S);
	
	for(i=0;i <= 12;++i) apilar(&S,i);
	
	if( es_vacia(S) ) puts("ES VAXIA");
	else printf("%d",frente(S));
	
	desapilar(&S);
	printf("\nEl nuevo frente es %d\n",frente(S));
	
	
	return 0;
}


void crear_pila(struct Pila *P){
	P->tope = (struct Nodo*)malloc(sizeof(struct Nodo));
	P->tope = NULL;
	P->talla = 0;
}

int es_vacia(struct Pila P){
	return (talla(P) == 0 && P.tope == NULL);
}

int talla(struct Pila P){
	return P.talla;
}

int frente(struct Pila P){
	return P.tope->elemento;
}

void apilar(struct Pila *P,int x){
	struct Nodo* elemento = malloc(sizeof(struct Nodo));
	
	elemento->elemento = x;
	elemento->proximo = P->tope;
	P->tope = elemento;
	P->talla++;
}

void desapilar(struct Pila *P){
	struct Nodo* N;
	N = P->tope;
	P->tope = N->proximo;
	P->talla--;
}
