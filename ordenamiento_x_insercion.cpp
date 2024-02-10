//ordenamiento x insercion
#include"iostream"
#include"time.h"
#include"stdlib.h"
using namespace std;

int main(int argc, char **argv) {
	int ii, jj, a[5], aux, pos;
	srand(time(NULL));
	
	for(ii=0;ii<5;ii++) {
		a[ii] = rand() %10;
		cout<<a[ii]<<" ";
	}
	cout<<endl;
	for(ii=0;ii<5;ii++) {
		pos = ii;
		aux = a[ii];
		while((pos>0) && (aux< a[pos-1])) {
			a[pos] = a[pos-1];
			pos--;
		}
		a[pos] = aux;
	}
	for(ii=0;ii<5;ii++) {
		cout<<a[ii]<<" ";
	}
	
	return 0;
}
