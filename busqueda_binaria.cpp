//busqueda binaria
#include"iostream"
#include"time.h"
#include"stdlib.h"
using namespace std;

int main(int argc, char **argv) {
	int ii, jj, a[5], aux, min, dato, inf = 0, sup=0, half;
	char band = 'F';
	srand(time(NULL));
	
	for(ii=0;ii<5;ii++) {
		a[ii] = rand() %10;
		cout<<a[ii]<<" ";
	}
	cout<<endl;
	for(ii=0;ii<5;ii++) {
		min = ii;
		for(jj=ii+1;jj<5;jj++) {
			if(a[jj] < a[min])
			min = jj;
		}
		aux = a[ii];
		a[ii] = a[min];
		a[min] = aux;
	}
	cout<<endl;
	cout<<"introduce el numero que estas buscando?: ";cin>>dato;
	
	while(inf <= sup) {
		half = (inf+sup) / 2;
		if(a[half]== dato) {
			band = 'V';break;
		}
		if(a[half] > dato) {
			sup = half;
			half = (inf+sup)/2;
		}
		if(a[half] < dato ) {
			inf = half;
			half = (inf+sup) / 2;
		}
	}
	(band == 'V')?cout<<"el numero existe en la posicion "<<half:cout<<"el numero no existe";
	
	return 0;	
}
