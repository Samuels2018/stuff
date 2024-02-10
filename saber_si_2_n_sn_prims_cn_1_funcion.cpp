/* comprovar si dos numeros diferentes son primos con una funcion */

#include <iostream>
using namespace std;

int primo(int a) {
	
	int i, aux, j;
	
	j = 0;
	
	for (i = 2; i < a && j == 0; i++) {
		aux = a % i;
		if (aux == 0) {
			j = 1;
		}
	}
	
	return 0;
	
	
}

int main () {
	
	int x, y, prim1, prim2;
	
	cout<<"introuce el primer numero: ";cin>>x;
	
	cout<<"introduce el segundo numero: ";cin>>y;
	
	prim1 = primo(x);
	prim2 = primo(y);
	
	(prim1 == 0)?cout<<"el numero "<<x<<" es primo.\n\n":cout<<"el numero "<<x<<" no es primo.\n\n";
	(prim2 == 0)?cout<<"el numero "<<y<<" es primo.\n\n":cout<<"el numero "<<y<<" no es primo.\n\n";
	
	return 0;
	
}

