//ordenamiento x seleccion
#include"iostream"
#include"time.h"
#include"stdlib.h"
using namespace std;

int main(int argc, char **argv) {
	int ii, jj, a[5], aux, min;
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
	for(ii=0;ii<5;ii++) {
		cout<<a[ii]<<" ";
	}
	
	return 0;
}
