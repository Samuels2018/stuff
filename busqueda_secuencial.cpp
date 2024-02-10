//busqueda secuencial
#include"iostream"
#include"time.h"
#include"stdlib.h"
using namespace std;

int main(int argc, char **argv) {
	int ii, jj, a[5], aux, min, dato, kk = 0;
	char band = 'F';
	srand(time(NULL));
	
	for(ii=0;ii<5;ii++) {
		a[ii] = rand() %10;
		cout<<a[ii]<<" ";
	}
	cout<<endl;
	cout<<"introduce el numero que estas buscando?: ";cin>>dato;
	
	while((band =='F') && (kk<5)) {
		if(a[kk] == dato) {
			band = 'V';
		}
		kk++;
	}
	(band == 'V')?cout<<"el numero existe en la posicion "<<kk:cout<<"el numero no existe";
	
	return 0;	
}
