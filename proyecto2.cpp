//

#include"iostream"
#include"stdlib.h"
#include"fstream"
#include"string"
using namespace std;

struct nodo {
	string buffer;
	nodo *sig;
};

bool cola_vacia (nodo *frent) {
	return (frent == NULL) ? true : false;
}

void insertar_cola (nodo *&frent, nodo *&fin, string temp) {
	nodo *nuevo = new nodo();
	nuevo->buffer = temp;
	nuevo->sig = NULL;

	if (cola_vacia(frent)) {
		frent = nuevo;
	}else {
		fin->sig = nuevo;
	}

	fin = nuevo;

	return;
}

void mostrar_cola (nodo *frent) {
	while (frent != NULL) {
		cout<<frent->buffer<<endl;
		frent = frent->sig;
	}


	return;
}

void eliminar_cola (nodo *&frent, nodo *&fin) {
	nodo *aux = frent;

	if (frent == fin) {
		frent = NULL;
		fin = NULL;
	}else {
		frent = frent->sig;
	}

	delete aux;

	return;
}

void cola () {
	int m;
	char op;
	string temp;
	nodo *frent =NULL;
	nodo *fin =NULL;
	ifstream f;
	f.open("datos_trafico.txt",ios::in);
	if(f.fail()) cout<<"el archivo no se pudo abrir \n";
	
	do{
		cout<<"\nq deseas hacer?: "<<endl;
		cout<<"1 para insertar elementos: "<<endl;
		cout<<"2 para ver los elementos insertados: "<<endl;
		cout<<"3 para eliminar elementos insertados: ";cin>>m;
		switch(m) {
			case 1:{
				while (!f.eof()) {
					getline(f,temp);
					insertar_cola(frent,fin,temp);
				}
				f.close();
				break;
			}
            case 2: {
            	mostrar_cola(frent);
            	break;
            }
            case 3: {
            	eliminar_cola(frent,fin);
            	break;
            }
            	
		}
		cout<<"desea realizar otra operacion?: ";cin>>op;
        
	}while(op =='s' || op=='S');

	return;
}




void add_nodo (nodo *&pila, string temp) {
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo->buffer = temp;
	nuevo_nodo->sig = pila;
	pila = nuevo_nodo;

	return;
}

void mostrar_pila (nodo *pila) {
	while(pila != NULL) {
		cout<<pila->buffer<<endl;
		pila = pila->sig;
	}

	return;
}

void sacar_pila (nodo *&pila) { // tengo un problema en esta funcion pero ns cual es ??
	nodo *aux = pila;
	pila = aux->sig;
	delete aux;

	return;
}

void pila () {
	int m;
	char op;
	string temp;
	nodo *pila = NULL;
	ifstream f;
	f.open("datos_trafico.txt",ios::in);
	if(f.fail()) cout<<"el archivo no se pudo abrir \n";
	
	do{
		cout<<"\nq deseas hacer?: \n";
		cout<<"1 para insertar elementos: \n";
		cout<<"2 para ver los elementos insertados: \n";
		cout<<"3 para eliminar elementos insertados: ";cin>>m;
		switch(m) {
			case 1:{
				
        		while (!f.eof()) {
					getline(f,temp);
					add_nodo(pila,temp);
				}
				f.close();
				break;
			}
            case 2:{
            	mostrar_pila(pila);
            	break;
            }

            case 3: {
            	sacar_pila(pila);
            	break;
            }
		}
		cout<<"desea realizar otra operacion?: ";cin>>op;
	}while(op =='s' || op=='S');

	return;
}


void insertar_en_lista (nodo *&list, string temp) {
	nodo *nuevo = new nodo();
	nuevo->buffer = temp;
	nodo *aux = list;
	nodo *aux1;

	while (aux != NULL) {
		aux1 = aux;
		aux = aux->sig;
	}

	if (list == aux) {
		list = nuevo;
	}else {
		aux1->sig = nuevo;
	}
	nuevo->sig = aux;

	return;
}

void mostrar_lista (nodo *list) {
	nodo *act = new nodo();
	act = list;

	while (act != NULL) {
		cout<<act->buffer<<"\n";
		act = act->sig;
	}

	return;
}

void buscar_en_lista (nodo *&list, char n) {

	string temp;
	bool band = false;
	nodo *act = new nodo();
	act = list;

	while ((act != NULL)) {
		if (act->buffer[4] == n) {
			temp = act->buffer;
			band = true;
		}
		act = act->sig;
	}

	if(band == true) cout<<"el elemento a sido encontrado"<<endl<<temp<<endl;
	else cout<<"el elemento "<<n<<" no ha sido encontrado"<<endl;

	return;
}

void eliminar_nodo (nodo *&lis, char n) {
	if(lis != NULL) {
		nodo *aux_borrar;
		nodo *anterior =NULL;
		aux_borrar =lis;
		
		while((aux_borrar != NULL) && (aux_borrar->buffer[4] != n)) {//recorremos la lista
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

void eliminar_lista(nodo *&list){//vaciar lista
	nodo *aux;
	while (list != NULL) {
		aux = list;
		list = aux->sig;
		delete aux;

	}
	return;
}

int fila() {
	int m;
	char op, n;
	string temp;
	nodo *list = new nodo();
	ifstream f;
	f.open("datos_trafico.txt",ios::in);
	if(f.fail()) cout<<"el archivo no se pudo abrir \n";
	
	do{
		cout<<"\nq deseas hacer?: "<<endl;
		cout<<"1 para insertar elementos: "<<endl;
		cout<<"2 para ver los elementos insertados: "<<endl;
		cout<<"3 para buscar 1 elemento en la lista: "<<endl;
		cout<<"4 para eliminar 1 elemento en la lista: "<<endl;
		cout<<"5 para eliminar la lista comleta: ";cin>>m;
		switch(m) {
			case 1:{
				while (!f.eof()) {
					getline(f,temp);
					insertar_en_lista(list,temp);
				}
				f.close();
				break;
			}
            case 2: {
            	mostrar_lista(list);
            	break;
            }
            case 3: {
            	cout<<"introduce el numero q deseas buscar en la lista: ";cin>>n;
            	buscar_en_lista(list,n);break;
            }
            case 4: {
            	cout<<"introduce el numero q deseas borrar en la lista: ";cin>>n;
            	eliminar_nodo(list,n);break;
            }
            case 5: {
            	eliminar_lista(list);
            	break;
            }
        }
		cout<<"\ndesea realizar otra operacion?: ";cin>>op;
	}while(op =='s' || op=='S');
	
	return 0;
}


int main (int argc, char **argv) {
	int n;

	do{
		cout<<"introduce por que metodo realizar las opracion"<<endl;
		cout<<"1 para cola\n2 para pila\n3 fila\n00 para salir: ";
		cin>>n;

		switch(n) {
			case 1: {
				cola();
				break;
			}
			case 2: {
				pila();
				break;
			}
			case 3 : {
				fila();
				break;
			}
			default: {
				cout<<"ese numero no esta dento de los parametros permitidos intentelo de nuevo";
				break;
			}
		}
	}while(n != 00);

	return 0;

}