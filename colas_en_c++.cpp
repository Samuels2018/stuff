//colas
#include"iostream"
#include"stdlib.h"
using namespace std;

struct nodo{
	int dato;
	nodo *sig;
};

bool cola_vacia(nodo *frent) {
	return (frent ==NULL)? true: false;
}

void insertarcola(nodo *&frent, nodo *&fin, int n) {
	nodo *nuevo = (nodo*)malloc(sizeof(nodo));
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

void mostrarcola (nodo *&frent) {

	while(frent != NULL) {
       cout<<frent->dato<<", ";
       frent = frent->sig;
    }

	//(frent != NULL)?cout<<n<<", ":cout<<n<<endl;
	return;
}

void eliminarcola(nodo *&frent, nodo *&fin, int &n) {
	//n = frent->dato;
	nodo *aux =frent;
	
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
	nodo *frent =NULL;
	nodo *fin =NULL;
	
	do{
		cout<<"q deseas hacer?: "<<endl;
		cout<<"1 para insertar elementos: "<<endl;
		cout<<"2 para ver los elementos insertados: "<<endl;
		cout<<"3 para eliminar elementos insertados: "<<endl;cin>>m;
		switch(m) {
			case 1:{
				do{
            		cout<<"introduce 1 numero para agregarlo a la fila"<<endl; 
            		cout<<"o introduce 000 sino deseas introducir mas numeros: ";cin>>n;
            		if (n != 000) insertarcola(frent,fin,n); 
            		else break;
            	}while(n!=000);
            	break;
			}
            case 2: {
            	mostrarcola(frent);
            	break;
            }
            case 3: {
            	eliminarcola(frent,fin,n);
            	break;
            }
            	
		}
		cout<<"desea realizar otra operacion?: ";cin>>op;
         
	}while(op =='s' || op=='S');
	
	
	return 0;
}
