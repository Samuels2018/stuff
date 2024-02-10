	#include"iostream"
#include"fstream"
#include"stdlib.h"
using namespace std;

typedef struct{
	int nPage, nMarcos, aux;
	int *page, **mru, *marcos;
}ar;

ar v;

void func (int kk, int ll, int mm, int nn) {
	if (nn == 0) {
		v.mru[ll][mm] = v.page[kk];
		ll  = nn+1;
		v.mru[ll][mm] = v.page[kk];
	}else {
		for (int ii = 0; ii < nn; ii++) {
			//v.mru[ii][mm] = v.marcos[ii];
			//ll++;
			v.mru[ii][mm] = 5;
		}
		ll  = nn;
		v.mru[ll][mm] = v.page[kk];
	}
}

int main (int argc, char **argv) {

	int ii, jj, kk = 0,ll = 0, mm = 0, nn = 0;
	//ar v;

	cout<<"introduce el numero de paginas: ";cin>>v.nPage;
	v.page = new int[v.nPage];

	for (ii = 0; ii < v.nPage; ii++) {
		cout<<"introduce un numero para la pagina "<<ii<<": ";cin>>v.page[ii];
	}

	cout<<"introduce el numero de marcos: ";cin>>v.nMarcos;
	v.marcos = new int[v.nMarcos];
	//cout<<"lffef";

	v.mru = new int*[v.nMarcos];
	
	for(ii =0; ii < v.nMarcos; ii++) {
		v.mru[ii] = new int[v.nPage];
	}

	for (ii = 0; ii < v.nMarcos; ii++) {
		for (jj = 0; jj < v.nPage; jj++) {
			v.mru[ii][jj] = 0;
			//v.marcos[jj] = 0;
		}
	}


	while (mm < v.nPage) {
		//cout<<"nkf";

		if (v.mru[0][0]) { 
			v.mru[0][0] = v.page[kk];
			v.marcos[nn] = v.page[kk];
			kk++;
		}

		/*if (v.page[kk] == v.marcos[nn]) {
			if (ll == 0) {
				v.mru[ll][mm] == v.page[kk];
				//cout<<v.mru[ll][mm]<<" ";
				nn++;
				v.marcos[nn] = v.page[kk];
				kk++;
				mm++;
			}else {
				for (ii = 0; ii <= nn; ii++) {
					v.mru[ii][mm] = v.marcos[ii];
				//ll++;
				}
			}
		}*/

		if (v.page[kk] != v.marcos[nn]) {
			cout<<"nkf";
			mm++;
			// kk, ll, mm, nn
			func (kk ,ll, mm ,nn);
			nn++;
			v.marcos[nn] = v.page[kk];
			kk++;
		}

		/*if () {

		}*/

		//ll++;
	}


	for (ii = 0; ii < v.nMarcos; ii++) {
		for (jj = 0; jj < v.nPage; jj++) {
			cout<<v.mru[ii][jj]<<" ";
		}
		cout<<endl;
	}
	

	return 0;
}

/*int main (int argc, char **argv) {


	cout<<"introduce el numero de paginas: ";cin>>nPage;
	for (ii = 0; ii < nPage; ii++) {
		cout<<"introduce un numero para la pagina "<<ii<<": ";cin>>page[ii];
	}

	cout<<"introduce el numero de marcos: ";cin>>nMarcos;

	for (ii = 0; ii < nMarcos; ii++) {
		for (jj = 0; jj < nPage; jj++) {
			mru[ii][jj] = 0;
		}
	}

	cout<<endl;

	for (ii = 0; ii < nMarcos; ++ii) {
		marcos[ii] = 0;
	}

	while (ll < nMarcos) {
		while (mm < nPage) {

			if ((ll == 0) && (mm == 0)) {
				mru[ll][mm] = page[kk];
				aux = page[kk];
				mm++;
				kk++;
			} 

			if (page[kk] == aux) {
				mru[ll][mm] = page[kk];
				marcos[kk] = page[kk];
				kk++;
				mm++;
			}

			if (page[kk] != aux || ll != nMarcos) {
				mru[ll][mm] = aux;
				ll++;
				mru[ll][mm] = page[kk];
			}else{
				//cout<<"ksacavavjkn";
				ll = 0;
				mm++;
				mru[ll][mm] = aux;
				mru[ll][mm] = page[kk];

			}

			/*if (nMarcos) {
				falta logica logica
			}

			aux = page[kk];

			//cout<<page[kk]<<" "<<aux;
			mm++;
			kk++;

		}
		//if(!nMarcos) ll++;	
	}

	for (ii = 0; ii < nMarcos; ii++) {
		for (jj = 0; jj < nPage; jj++) {
			cout<<mru[ii][jj]<<" ";
		}
		cout<<endl;
	}


	return 0;
}*/
