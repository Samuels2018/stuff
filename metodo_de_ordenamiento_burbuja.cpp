//ordenamiento por el metodo de la burbuja
#include"iostream"
#include"time.h"
#include"stdlib.h"
using namespace std;

int main(int argc, char **argv) {
	int a[5], aux, ii, jj;
	srand(time(NULL));
	for(ii=0;ii<5;ii++) {
		a[ii] = rand();
		cout<<a[ii]<<" ";
	}
	cout<<endl;
	
	for(ii=0;ii<5;ii++) {
		for(jj=0; jj<5;jj++) {
			if(a[jj] > a[jj+1]) {
				aux = a[jj];
				a[jj] = a[jj+1];
				a[jj+1] = aux;
			}
		}
	}
	cout<<endl;
	for(ii=0;ii<5;ii++) {
		cout<<a[ii]<<" ";
	}
	
	return 0;
}
