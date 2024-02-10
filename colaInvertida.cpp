//colas
#include"iostream"
#include"stdlib.h"
using namespace std;

struct nodo{
	int dato;
	nodo *sig;
};

struct cola{
	int dato;
	cola *sig;
};


void cola_invertida (nodo *&frent, nodo *&fin, cola *&pl) {
	cola *aux = new cola();

	while(frent != NULL) {
		aux->dato = frent->dato;
		cout<<aux->dato<<" ";
		frent = frent->sig;
		aux->sig = pl;
		pl = aux;
		//aux = frent;
		//frent = frent->sig;
	}


	

	return;


}

bool cola_vacia(nodo *frent) {
	return (frent ==NULL)? true: false;
}

void insertarcola(nodo *&frent, nodo *&fin, int n) {
	nodo *nuevo = new nodo();
	nuevo->dato = n;
	nuevo->sig = NULL;
	
	if(cola_vacia(frent)) {
		frent = nuevo;
	}
	else{
		fin->sig = nuevo;
	}
	fin = nuevo;
	
	
	return;
}

void eliminarcola(nodo *&frent, nodo *&fin, int &n) {
	n = frent->dato;
	nodo *aux = new nodo();
	aux = frent;
	
	if(frent == fin) {
		frent = NULL;
		fin = NULL;
	}
	else{
		frent = frent->sig;
	}
	
	delete aux;
	
	
	return;
}

int main(int argc, char** argv) {
	int n,m;
	char op;
	nodo *frent = new nodo();
	nodo *fin = new nodo();
	cola *pl = new cola();
	
	do{
		cout<<"q deseas hacer?: "<<endl;
		cout<<"1 para insertar elementos: "<<endl;
		cout<<"2 para ver los elementos insertados: "<<endl;cin>>m;
		switch(m) {
			case 1:{
				do{
            		cout<<"introduce 1 numero para agregarlo a la fila"<<endl; 
            		cout<<"o introduce 000 sino deseas introducir mas numeros: ";cin>>n;
            		if(n!=000){insertarcola(frent,fin,n);}
            		else{break;}
            	}while(n!=000);break;
			}
            case 2:
            	while(frent != NULL) {
            		eliminarcola(frent,fin,n);
            		(frent != NULL)?cout<<n<<", ":cout<<n<<endl;
            	}break;

            case 3: {
            	cola_invertida(frent, fin, pl);
            	/*while(frent != NULL) {
            		cola_invertida(frent, fin, pl);
            	}break;*/

            }
		}
		cout<<"desea realizar otra operacion?: ";cin>>op;
	}while(op =='s' || op=='S');
	
	
	return 0;
}
