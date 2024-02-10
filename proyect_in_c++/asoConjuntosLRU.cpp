#include"iostream"
#include"fstream"
#include"stdlib.h"
using namespace std;

typedef struct{
	int nPage, nMarcos, aux;
	int *page, **mru, *marcos, *contador;
}ar;

ar v;

int fn (int kk) {
	int ii, ver;

	ver = -1;

	for (ii = 0; ii < v.nMarcos-1; ii++) {
		if (v.marcos[ii] == v.page[kk]) {
			ver = 0;
		}
	}

	return ver;

}

int a () {

	int ii, bigger = 0, v1[1] ,aux;

	for (ii = 0; ii < v.nMarcos; ii++) {
		if (v.contador[ii] > bigger) {
			bigger = v.contador[ii];
			v1[0] = ii;
			aux = v1[0];
		}
	}

	aux = v1[0];

	return aux;
}

void ciclo (int nn, int jj) {
	int ii;

	for (ii = 0; ii <= nn; ii++) {
		v.mru[ii][jj] = v.marcos[ii];
	}

	return;
}

void initialMemory () {

	int ii, jj;

	cout<<"introduce el numero de paginas: ";cin>>v.nPage;
	v.page = new int[v.nPage];

	for (ii = 0; ii < v.nPage; ii++) {
		cout<<"introduce un numero para la pagina "<<ii<<": ";cin>>v.page[ii];
	}

	cout<<"introduce el numero de marcos: ";cin>>v.nMarcos;
	v.marcos = new int[v.nMarcos];
	v.contador = new int[v.nMarcos];

	v.mru = new int*[v.nMarcos];
	
	for(ii =0; ii < v.nMarcos; ii++) {
		v.mru[ii] = new int[v.nPage];
	}

	for (ii = 0; ii < v.nMarcos; ii++) {
		for (jj = 0; jj < v.nPage; jj++) {
			v.mru[ii][jj] = 0;
		}
	}

	return;
}


int main (int argc, char **argv) {

	int ii, jj, kk = 0, ll = 0, mm = 0, nn = 0;
	int aux, bigger = 0, ver;

	initialMemory();


	for (jj = 0; jj < v.nPage; jj++) {

		if (nn == v.nMarcos-1) {

			ver = fn(kk);

			if ( ver != 0) {
				for (ii = 0; ii < v.nMarcos; ii++) {
					v.mru[ii][jj] = v.marcos[ii];
					if (v.mru[ii][jj] == v.marcos[aux]) {
						v.marcos[aux] = v.page[kk];
						v.mru[ii][jj] = v.marcos[ii];
						v.contador[ii] = -1;
					}
				}

				for(int i=0; i < v.nMarcos; ++i){
					v.contador[i]++;
				}

				aux = a();
				
			}else {
				for (ii = 0; ii < v.nMarcos; ii++) {
					v.mru[ii][jj] = v.marcos[ii];
					if (v.marcos[ii] == v.page[kk]) {
						v.contador[ii] = 0;
					}
				}
			}
			kk++;	
		}


		if (ll == 0 && jj == 0) { 
			v.mru[ll][jj] = v.page[kk];
			v.marcos[nn] = v.page[kk];
			kk++;

		} 

		ver = fn(kk);

		if (ver != -1) {

			if (nn == 0) {
				v.mru[ll][jj] = v.marcos[nn];
				kk++;
			}else {
				ciclo(nn,jj);
				kk++;
			}
		}else if ( (v.page[kk] != v.marcos[nn]) && (jj > 0) ) {
			if (nn == 0) {
				v.mru[ll][jj] = v.marcos[nn];
				nn++;
				ll = nn;
				v.mru[ll][jj] = v.page[kk];
				v.marcos[nn] = v.page[kk];

				for(int i=0; i < v.nMarcos; ++i){
					if( i != nn && v.marcos[i] != 0 ) v.contador[i]++;
					else if( i == nn ) v.contador[i] = 0;
				}
				kk++;

			}else {
				if (nn < v.nMarcos-1) {
					ciclo(nn,jj);
					nn++;
					ll = nn;
					v.mru[ll][jj] = v.page[kk];
					v.marcos[nn] = v.page[kk];

					for(int i=0; i < v.nMarcos; ++i){
						if( i != nn && v.marcos[i] != 0 ) v.contador[i]++;
						else if( i == nn ) v.contador[i] = 0;
					}
					kk++;
				}

				aux = a();
				//aux = fn(bigger);

			}

		}

	}


	for (ii = 0; ii < v.nMarcos; ii++) {
		for (jj = 0; jj < v.nPage; jj++) {
			cout<<v.mru[ii][jj]<<" ";
		}
		cout<<endl;
	}
	

	return 0;
}
