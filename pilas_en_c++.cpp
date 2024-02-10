//pilas en C++
#include"iostream"
#include"stdlib.h"
using namespace std;

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
		}
		cout<<"desea realizar otra operacion?: ";cin>>op;
	}while(op =='s' || op=='S');
	
	
	return 0;
}
