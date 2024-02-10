#include"iostream"
#include"cstdlib"
using namespace std;

struct nodo {
	int data;
	nodo *sig;
} *fin, *lista;



void eliminarElemento () {

	nodo *aux, *r, *q;
	int ii = 0, flag = 0, valor;

	cout<<"ingrese el elemento a eliminar: ";
	cin>>valor;

	if (lista != NULL) {
		aux = lista;

		do {

			if (aux->data == valor) {

				if (aux == lista) { // si el dato a eliminar es el primero 
					r = lista;
					lista = lista->sig;
					aux = aux->sig;
					fin->sig = lista;
					r->sig = NULL;

					if (fin->sig == NULL) {

						lista = NULL;
						aux = NULL;
						delete(r);
						cout<<"elemento eliminado "<<endl;
						//return;

					}else {
						delete(r);
						cout<<"elemento eliminado "<<endl;

					}
				
				}else {
					if (aux == fin) { // si el dato a eliminar es al que apunta el fin

						r = aux;
						aux = aux->sig;
						q->sig = aux;
						fin = q;
						r->sig = NULL;
						delete(r);
						cout<<"elemento eliminado "<<endl;


					}else {
						r = aux;
						aux = aux->sig;
						q->sig = aux;
						r->sig = NULL;
						delete(r);
						cout<<"elemento eliminado "<<endl;
					}
				}

				flag = 1;

			}else {

				q = aux;
				aux = aux->sig;
				ii++;
			}

		}while(aux != lista);

		if (flag == 0) cout<<"\nnumero no encontrado "<<endl;
	
	}else cout<<"lista vacia\n";


	return;
}

void buscarElemento () {

	nodo *aux;
	int ii = 0, valor, flag = 0;

	cout<<"\ningrece el elemnto que desea buscar: ";
	cin>>valor;

	if (lista != NULL) {

		aux = lista;

		do {
			if (aux->data == valor) {
				cout<<"\nencontrado en la pocicion "<<ii<<endl;
				flag = 1;
				aux = aux->sig;
				ii++;
			
			}else {
				aux = aux->sig;
				ii++;
			}

		}while(aux != lista);

		if (flag == 0) cout<<"\n no encontrado :( "<<endl;
	
	}else {
		cout<<"lista vacia "<<endl;
	}

	return;
}

void mostrar () {

	nodo *aux;
	aux = lista;
	int ii = 0;


	if (lista != NULL) {
		while (aux != lista) {
			cout<<" "<<aux->data;
			aux = aux->sig;
			ii++;
		}
	
	}else {
		cout<<endl;
	}

	return;
}

void insertarFinal () {

	nodo *nuevo = new nodo();

	cout<<"\ningrese el dato: ";
	cin>>nuevo->data;
	nuevo->sig = NULL;

	if (lista == NULL) {
		// apunto la lista al nuevo elemento
		lista = nuevo;
		// doy espacio para oro elemento
		lista->sig = lista;
		fin = nuevo;

	}else {

		fin->sig = nuevo;
		nuevo->sig = lista;
		fin = nuevo;

	}


	return;
}


void insertarInicio () {

	nodo *nuevo = new nodo();

	cout<<"\ningrese el dato: ";
	cin>>nuevo->data;
	nuevo->sig = NULL;

	if (lista == NULL) {
		// apunto la lista al nuevo elemento
		lista = nuevo;
		// doy espacio para oro elemento
		lista->sig = lista;
		fin = nuevo;

	}else {

		nuevo->sig = lista;
		lista = nuevo;
		fin->sig = lista;

	}


	return;
}

void menu () {

	cout<<"lista Circular Enlazada\n";
	cout<<"Que deseas Hacer ?"<<endl;
	cout<<"1 para insertar al inicio\n";
	cout<<"2 para insertar al final\n";
	cout<<"3 mostrar lista\n";
	cout<<"4 buscar un elemeno\n";
	cout<<"5 eliminar un elemeno\n";
	cout<<"6 eliminar elementos\n";
	cout<<"7 para salir\n";

	return;
}

int main () {

	lista = NULL;
	int op;

	do {

		menu();
		cin>>op;

		switch(op) {
			case 1: 
				insertarInicio();
				break;

			case 2: 
				insertarFinal();
				break;

			case 3: 
				cout<<"\nlista circular";
				mostrar();
				break;

			case 4: 
				buscarElemento();
				break;

			case 5: 
				eliminarElemento();
				break;


			default:
				cout<<"opcion no valida";
		}

		cout<<endl;

	}while(op >= 1 && op < 6);

	return 0;
}