#include"iostream"
#include"fstream"
#include"stdlib.h"
using namespace std;

typedef struct{
	int nPage, nMarcos, aux;
	int *page, **mru, *marcos, *contador;
}ar;

typedef struct{
	int nPage, nMarcos, aux;
	int *page, **mru, *marcos;
	/*en la asociatividad por conjuntos se calcula =>
	marcos = via
	lineas = lias que tiene la cache
	paginas = direcciones de bloques
	n°conjuntos = n°lineas/n°vias
	n°vias = n°lineas/n°conjuntos
	n°lineas = n°vias*n°conjuntos
	ver un conjuntos como una fila y ver a una via como una columna  
	*/
}aso;

ar v;
aso mru;

void ciclo (int nn, int mm) {
	int ii;

	for (ii = 0; ii <= nn; ii++) {
		v.mru[ii][mm] = v.marcos[ii];
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
	v.contador = new int[v.nPage];

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

	int ii, jj, kk = 0,ll = 0, mm = 0, nn = 0;

	initialMemory();


	while (mm < v.nPage) {

		if (ll == 0 && mm == 0) { 
			v.mru[ll][mm] = v.page[kk];
			v.marcos[nn] = v.page[kk];
			kk++;
		}

		if (v.page[kk] == v.marcos[nn]) {
			if (nn == 0) {
				v.mru[ll][mm] == v.marcos[nn];
				kk++;
			}else {
				ciclo(nn,mm);
			}
		}

		if ( (v.page[kk] != v.marcos[nn]) && (mm > 0) ) {
			//cout<<"nkf";
			if (nn == 0) {
				v.mru[ll][mm] = v.marcos[nn];
				nn++;
				ll = nn;
				v.mru[ll][mm] = v.page[kk];
				v.marcos[nn] = v.page[kk];
				
				for(int i=0; i < v.nMarcos; ++i){
					if( i != nn && v.marcos[i] != 0 ) v.contador[i]++;
					else if( i == nn ) v.contador[i] = 0;
				}

			}else {
				ciclo(nn,mm);
				ll  = nn+1;
				v.mru[ll][mm] = v.page[kk];
				nn++;
				v.marcos[nn] = v.page[kk];
				for(int i=0; i < v.nMarcos; ++i){
					if( i != nn && v.marcos[i] != 0 ) v.contador[i]++;
					else if( i == nn ) v.contador[i] = 0;
				}
			}
			kk++;
		}

		mm++;

		/*
		else if (nn < v.nMarcos) {
				for (ii = 0; ii <= nn; ii++) {
					//cout<<v.marcos[ii]<<" ";
					v.mru[ii][mm] = v.marcos[ii];
				}
				ll  = nn+1;
				v.mru[ll][mm] = v.page[kk];
				nn++;
				v.marcos[nn] = v.page[kk];
			}else {
				
			}
		*/
	}

	for(int i=0; i < v.nMarcos; ++i){
		cout<<v.contador[i]<<" ";
	}


	/*for (ii = 0; ii < v.nMarcos; ii++) {
		for (jj = 0; jj < v.nPage; jj++) {
			cout<<v.mru[ii][jj]<<" ";
		}
		cout<<endl;
	}*/
	

	return 0;
}
