//rellenar 1 matriz cn numers al azr && mostrar sus 2 diagonales
#include"iostream"
#include"time.h"
#include"stdlib.h"
using namespace std;

int main(int argc, char **argv) {
	int a[3][3];
	srand(time(NULL));
	
	for(int ii=0; ii<3; ii++) {
		for(int jj=0; jj<3; jj++) {
			a[ii][jj]= rand() % 10;
		}
	}
	for(int ii=0; ii<3; ii++) {
		for(int jj=0; jj<3; jj++) {
			cout<<a[ii][jj]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int ii=0; ii<3; ii++) {
	    cout<<a[ii][ii]<<" ";
	}
	cout<<endl;
	for(int jj=0; jj<3; jj++) {
		cout<<a[jj][2-jj]<<" ";
	}
	
	return 0;
}
