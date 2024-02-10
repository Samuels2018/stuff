//arboles en c++ structura de datos no liniales
#include"iostream"
#include"stdlib.h"
using namespace std;

struct nodo{
	int dato;
	nodo *izq;
	nodo *der;
	nodo *padre;
};

nodo *crear(int n, nodo *padre) {
	nodo *nuevo = (nodo*)malloc(sizeof(nodo));
	nuevo->dato = n;
	nuevo->der = NULL;
	nuevo->izq = NULL;
	nuevo->padre = padre;

	return nuevo;
}

void insetar(nodo *&arbol, int n, nodo *padre) {


	if(arbol == NULL) {
		nodo *nuevo = crear(n,padre); 
		arbol = nuevo;
	}else{
		int valorraiz = arbol->dato;//obtener el valor de la raiz
		if(n < valorraiz){
			insetar(arbol->izq,n,arbol);
		}else{
			insetar(arbol->der,n,arbol);
		}
	}

	return;
}

void mostrar(nodo *arbol, int cont) {
	int ii;

	if(arbol == NULL) {
		return;
	}else{
		mostrar(arbol->der,cont+1);
		for(ii = 0;ii<cont;ii++) {
			cout<<" ";
		}
		cout<<arbol->dato<<endl;
		mostrar(arbol->izq,cont+1);
	}

	return;
}

bool busqueda(nodo *arbol, int n) {

	if(arbol == NULL) {
		return false;
	}else if(arbol->dato == n){
		return true;
	}else if(n < arbol->dato){
		return busqueda(arbol->izq,n);
	}else{
		return busqueda(arbol->der,n);
	}
}

//recorrido de 1 arbol recorrido en pre-orden
//primero se vista la raiz,despues el sub-arbol izquierdo y despues el derecho
void preorden(nodo *arbol){

	if(arbol == NULL){
		return;
	}else{
		cout<<arbol->dato<<" ";
		preorden(arbol->izq);
		preorden(arbol->der);
	}
}

//recorrido IN-orden
//se recorre el lado izquierdo, despues la raiz y despues el derecho
void inorden(nodo *arbol){

	if(arbol == NULL){
		return;
	}else{
		inorden(arbol->izq);
		cout<<arbol->dato<<" ";
		inorden(arbol->der);
	}
}

//recorrido POST-orden
//primero se recorre el lado izquierdo, despues el derecho y por ultimo la raiz
void postorden(nodo *arbol){

	if(arbol == NULL){
		return;
	}else{
		postorden(arbol->izq);
		postorden(arbol->der);
		cout<<arbol->dato<<" ";
	}
}

//funcion para determinar el nodo mas izquierdo posible
nodo *minimo(nodo *arbol){
	if(arbol == NULL){
		return NULL;
	}else if(arbol->izq){//si tiene hijo izquierdo
		return minimo(arbol->izq);//buscamos la parte mas izquierda posible
	}else{//si no tiene hijo izquierdo
		return arbol;
	}
}

//funcion para reemplazar 1 nodo si tiene 1 solo hijo
void reemplazar(nodo *arbol, nodo *nuevo){

	if(arbol->padre){
		//arbol->padre hay q asignarle su nuevo hijo
		if(arbol->dato == arbol->padre->izq->dato){
			arbol->padre->izq = nuevo;
		}else if(arbol->dato == arbol->padre->der->dato){
			arbol->padre->der = nuevo;
		}
	}else if(nuevo){
		//procedemos a asignale su nuevo padre
		nuevo->padre = arbol->padre;
	}
}

//funcion para destruir 1 nodo q ya no apunta a nada
//y se usa si el arbol tiene  hijo
void destruirnodo(nodo *arbol){
	arbol->izq = NULL;
	arbol->der = NULL;
	delete arbol;
}

//se usa para eliminar el nodo encontrado
void eliminarnodo(nodo *arbol){
	if(arbol->izq && arbol->der){//si el nodo tiene hijo izquierdo y tiene hijo derecho, si tiene 2 hijos
		nodo *menor = minimo(arbol->der);
		arbol->dato = menor->dato;
		eliminarnodo(menor);
	}else if(arbol->izq){//si tiene hijo izquierdo
		reemplazar(arbol,arbol->izq);
		destruirnodo(arbol);
	}else if(arbol->der){
		reemplazar(arbol,arbol->der);
		destruirnodo(arbol);
	}else{//si 1 nodo no tiene hijos significa q es 1 nodo hoja
		reemplazar(arbol,NULL);
		destruirnodo(arbol);
	}

}

//eliminar nodos del arbol
void eliminar(nodo *arbol, int n){
	if(arbol == NULL){
		return;
	}else if(n < arbol->dato){
		eliminar(arbol->izq,n);
	}else if(n > arbol->dato){
		eliminar(arbol->der,n);
	}else{
		eliminarnodo(arbol);
	}
}

int main(int argc, char** argv) {
	int n, m, cont=0;
	char op;
	nodo *arbol = NULL;

	do{
		cout<<"\tq deseas hacer?: "<<endl;
		cout<<"1 para insertar elementos: "<<endl;
		cout<<"2 para ver los elementos insertados: "<<endl;
		cout<<"3 para buscar 1 elemento en el arbol: "<<endl;
		cout<<"4 para recorrer el arbol en pre-orden: "<<endl;
		cout<<"5 para recorrer el arbol en in-orden: "<<endl;
		cout<<"6 para recorrer el arbol en post-orden: "<<endl;
		cout<<"7 para eliminar 1 elemento en el arbol: "<<endl;cin>>m;
		switch(m) {
			case 1:
				do{
            		cout<<"introduce 1 numero para agregarlo a la fila"<<endl; 
            		cout<<"o introduce 000 sino deseas introducir mas numeros: ";cin>>n;
            		if(n!=000)insetar(arbol,n,NULL);else break;
            	}while(n !=000);break;
            case 2:
            	mostrar(arbol,cont);break;
            case 3:
            	cout<<"introduce el numero q deseas buscar en la lista: ";cin>>n;
            	if(busqueda(arbol,n) == true) cout<<"el elemento "<<n<<" se en cuentra en el arbol"<<endl;else cout<<"el elemento "<<n<<" no se en cuentra en el arbol"<<endl;
   	            break;
            case 4:
            	preorden(arbol);break;
            case 5:
            	inorden(arbol);break;
            case 6:
            	postorden(arbol);break;
            case 7:
            	cout<<"introduce el numero q deseas borrar del arbol: ";cin>>n;
            	eliminar(arbol,n);
         		cout<<"\n";
        }
		cout<<"\ndesea realizar otra operacion?: ";cin>>op;
	}while(op =='s' || op=='S');
	
	return 0;
}