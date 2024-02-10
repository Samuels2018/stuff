#include"iostream"

using namespace std;

struct nodo {
	int data;
	nodo *sig;
} *primero, *ultimo;

void insertarNodo () {
	nodo *nuevo = new nodo;

	cout<<"ingrese el dato";
	cin>>nuevo->data;
	if (primero== NULL) {

		primero = nuevo;
		primero->sig = nuevo;
		ultimo = primero;

	}else {

		ultimo->sig = nuevo;
		nuevo->sig = primero;
		ultimo = nuevo;

	}

	return;
}

void desplegarLista () {

	nodo *actual = new nodo();
	actual = primero;
	if (primero != NULL) {

		do {
			cout<<actual->data<<" ";
			actual = actual->sig;

		}while (actual != primero);

	}else {

		cout<<"la lista se encuenra vacia";

	}

	return;
}

int main () {

	insertarNodo();
	desplegarLista();

	return 0;
}