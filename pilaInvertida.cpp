//pilas en C++
#include"iostream"
#include"stdlib.h"
using namespace std;

struct nodo{
   int dato;
   nodo *sig;	
};

struct pilaInvertida{
   int dato;
   pilaInvertida *sig;	
};

void addnodo(nodo *&pila, int n) {
	nodo *nuevo_nodo = new nodo();
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
	aux->sig = NULL;
	
	return;
}

void invertir (nodo *&pila, pilaInvertida *&pl) {

	nodo *aux = new nodo();
	pilaInvertida *invrtr = new pilaInvertida();
	aux = pila;
	invrtr = pl;
	int n;
	while (pila != NULL) {
		invrtr->dato = aux->dato;
		//cout<<invrtr->dato<<" ";
		pila = aux->sig;
		invrtr->sig = pl;

		aux = aux->sig;
		pl = invrtr;

		cout<<pl->dato<<" ";

	}

	return;
}

int main(int argc, char **argv) {
	int n, m;
	char op;
	nodo *pila = new nodo();
	pilaInvertida *pl = new pilaInvertida();
	
	do{
		cout<<"q deseas hacer?: "<<endl;
		cout<<"1 para insertar elementos: "<<endl;
		cout<<"2 para ver los elementos insertados: "<<endl;cin>>m;
		switch(m) {
			case 1:
				do{
            		cout<<"introduce 1 numero para agregarlo a la pila"<<endl; 
            		cout<<"o introduce 000 sino deseas introducir mas numeros: ";cin>>n;
            		if(n!=000){addnodo(pila,n);}
            		else{break;}
            	}while(n !=000);break;
            case 2:
            	while(pila != NULL) {
            		sacarpila(pila,n);
            		(pila != NULL)?cout<<n<<", ":cout<<n<<endl;
            	}break;

            case 3: 
            		invertir(pila,pl);
            		//(pila != NULL)?cout<<n<<", ":cout<<n<<endl;
            		break;
		}
		cout<<"desea realizar otra operacion?: ";cin>>op;
	}while(op =='s' || op=='S');
	
	
	return 0;
}
