#include"iostream"
#include"stdlib.h"
#include"math.h"
using namespace std;
int x = 0;

/*en los arboles las columnas representan los nives 
mientras que las filas representan filas*/

bool comprobar(int reinas[], int n, int k) {
	int i;

	for (i = 0; i < k; i++) {
		// si las reinas estan en la misma posicion O el valor absoluto de el indices i - el indice k 
		// es igual a el valor absoluto de la posicion de la columna - la pocicion de la fila 
		// eso quiere decir que las reinas estan en un punto en que se pueden atacar mutuamente
		// no sirve esa pocion retorna falso
		if ((reinas[i] == reinas[k]) or (abs(k-i) == abs(reinas[k]) - reinas[i]) ) {
			return false;
		}
	}

	return true;
}

void Nreinas(int reinas[], int n, int k) {
	if (k == n) { // si el nivel de larbol es igual a la canidad de reinas 
		// imprimir la soluciones
		x++; // mostrar el numero de soluciones
		cout<<x;
		for (int i = 0; i < n; i++) {
			cout<<reinas[i]<<" , ";
		}
	}else {
		for (reinas[k] = 0; reinas[k] < n; reinas[k]++) {
			if (comprobar(reinas,n,k)) {
				Nreinas(reinas,n,k+1);
			}
		}
	}

	return;
}

int main () {
	int k = 0; //nivel del arbol 
	int cant; // numero de reinas
	int *reinas;

	cout<<"ingrese la cantidad de reinas";
	cin>>cant;

	reinas = new int[cant]; // declaro una canidad de reinas en la posicion del tablero

	for (int i = 0; i < cant; i++) {
		reinas[i] = -1;
	}

	Nreinas(reinas,cant, k); // soluciones que estoy buscando, 
	//las canidad de reinas, el nivel del arbol en el que estoy


	return 0;
}
