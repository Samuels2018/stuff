/*listas enlazadas simples: |dato1|->|dato2|->|dato3|->|dato4|->|NULL|
listas doblemente enlazadas |dato1|<->|dato2|<->|dato3|<->|dato4|<->|NULL|
listas circulares simple |dato1|->|dato2|->|dato3|->|dato4|->|NULL|->|dato1|
listas circulares doblemente enlazadas |dato1|<->|dato2|<->|dato3|<->|dato4|<->|NULL|->|dato1|->|dato4|*/

#include"iostream"
#include"stdlib.h"
using namespace std;

struct nodo{
	int dato;
	nodo *sig;
};

void insertarlista(nodo *&lis, int n) {
	nodo *nuevo = new nodo();
	nuevo->dato = n;
	nodo *aux = lis;
	nodo *aux1;
	
	while((aux != NULL) && (aux->dato < n )) {
		aux1 = aux;
		aux = aux->sig;
	}
	
	if(lis == aux) {
		lis = nuevo;
	}
	else{
		aux1->sig = nuevo;
	}
	
	nuevo->sig = aux;
	
	
	return;
}

void mostrarlista(nodo *lis) {
	nodo *act = (nodo*)malloc(sizeof(nodo));
	act = lis;
	
	while(act != NULL) {
		cout<<act->dato<<" ";
		act = act->sig;
	}
	
	
	return;
}

void buscarlista(nodo *lis, int n) {
	bool band = false;
	nodo *act = (nodo*)malloc(sizeof(nodo));
	act = lis;
	
	while((act != NULL) && (act->dato <=n)){
		if(act->dato == n) {
			band  = true;
		}
		act = act->sig;
	}
	
	if(band == true) {cout<<"el elemento "<<n<<" ha sido encontrado"<<endl;}
	else{cout<<"el elemento "<<n<<" no ha sido encontrado"<<endl;}
	
	return;
}

void eliminarnodo(nodo *&lis, int n) {
	if(lis != NULL) {
		nodo *aux_borrar;
		nodo *anterior =NULL;
		aux_borrar =lis;
		
		while((aux_borrar != NULL) && (aux_borrar->dato != n)) {//recorremos la lista
			anterior = aux_borrar;
			aux_borrar = aux_borrar->sig;
		}
		
		if(aux_borrar == NULL) {//el elemento no ha sido encontrado
			cout<<"el elemento "<<n<<" no ha sido encontrado"<<endl;
		}//el primer elemento es el q vams a eliminar
		else if(anterior == NULL) {
			lis = lis->sig;
			delete aux_borrar;
		}
		else{//el elemento esta en la lista 
			anterior->sig = aux_borrar->sig;
			delete aux_borrar;
		}
	}
	
	return;
}

void eliminarlista(nodo *&lis, int &n){//vaciar lista
	nodo *aux = lis;
	n =aux->dato;
	lis = aux->sig;
	delete aux;

	return;
}

int main(int argc, char **argv) {
	int n,m;
	char op;
	nodo *lis = (nodo*)malloc(sizeof(nodo));
	
	do{
		cout<<"\tq deseas hacer?: "<<endl;
		cout<<"1 para insertar elementos: "<<endl;
		cout<<"2 para ver los elementos insertados: "<<endl;
		cout<<"3 para buscar 1 elemento en la lista: "<<endl;
		cout<<"4 para eliminar 1 elemento en la lista: "<<endl;
		cout<<"5 para eliminar la lista comleta: "<<endl;cin>>m;
		switch(m) {
			case 1:
				do{
            		cout<<"introduce 1 numero para agregarlo a la fila"<<endl; 
            		cout<<"o introduce 000 sino deseas introducir mas numeros: ";cin>>n;
            		if(n!=000){insertarlista(lis,n);}
            		else{break;}
            	}while(n !=000);break;
            case 2:
            	mostrarlista(lis);break;
            case 3:
            	cout<<"introduce el numero q deseas buscar en la lista: ";cin>>n;
            	buscarlista(lis,n);break;
            case 4:
            	cout<<"introduce el numero q deseas borrar en la lista: ";cin>>n;
            	eliminarnodo(lis,n);break;
            case 5:
            	while(lis != NULL){
            		eliminarlista(lis,n);
            		cout<<n<<" ";
            	}cout<<"\n";break;
        }
		cout<<"\ndesea realizar otra operacion?: ";cin>>op;
	}while(op =='s' || op=='S');
	
	return 0;
}
