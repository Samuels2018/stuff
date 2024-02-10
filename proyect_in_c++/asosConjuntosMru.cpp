#include"iostream"
#include"fstream"
#include"stdlib.h"
using namespace std;

typedef struct{
	int nConjuntos, nVias, line;
	int *block, **mru, *vias, *count; //<= vector paralelo

	/*
	en la asociatividad por conjuntos se calcula =>
	marcos = via
	lineas = lias que tiene la cache
	paginas = direcciones de bloques
	n°conjuntos = n°lineas/n°vias
	n°vias = n°lineas/n°conjuntos
	n°lineas = n°vias*n°conjuntos
	ver un conjuntos como una fila y ver a una via como una columna  
	*/
}asoPConjuntos;

asoPConjuntos algorithm;

void initialMemory () {

	int ii, jj, tamCache = 512, lineTam = 16;

	algorithm.nVias = 4; // 4 columnas									
	algorithm.line = tamCache/lineTam; // 32
	algorithm.nConjuntos = algorithm.line/algorithm.nVias; // 32/4 = 8 filas

	algorithm.block = new int[algorithm.line];
	algorithm.vias = new int[algorithm.line];
	algorithm.count = new int[algorithm.line];

	for (ii = 0; ii < algorithm.line; ii++) {
		cout<<"introduce un numero para la pagina "<<ii<<": ";cin>>algorithm.block[ii];
	}

	algorithm.mru = new int*[algorithm.nConjuntos];

	for (ii = 0; ii < algorithm.nConjuntos; ii++) {
		algorithm.mru[ii] = new int[algorithm.nVias];
	}
	/*
	// n`conjuntos = cantidad de cache/n`vias filas 128
	// n`vias = n`lieas/n`conjuntos*/

	for (ii = 0; ii < algorithm.nConjuntos; ii++) {
		for (jj = 0; jj < algorithm.nVias; jj++) {
			algorithm.mru[ii][jj] = 0;
		}
	}

	return;
}


int main (int argc, char **argv) {

	int ii, fila, kk = 0 ,jj, aux, self;

	initialMemory();

	for (ii = 0; ii < algorithm.line; ii++) {
		fila = algorithm.block[ii] % algorithm.nConjuntos;

		if (algorithm.mru[fila][kk] == 0) {
			algorithm.mru[fila][kk] = algorithm.block[ii];

		}else {
			aux = 0;
			self = 0;
			for (jj = 0; jj < algorithm.nVia; jj++) {
				if (algorithm.mru[fila][jj] > 0) self++;
			}

			aux = self;
			self--;
			n[0] = -1;

			for (jj = 0; jj <= self; jj++) {
				if (algorithm.mru[fila][jj] == algorithm.block[ii]) {
					n[0] = jj;
				}
			}

			check = n[0];
			
			if (aux < algorithm.nVia) {
				if (check != -1) {
					algorithm.mru[fila][check] = algorithm.block[ii];
				}else {
					algorithm.mru[fila][aux] = algorithm.block[ii];
				} 
			}else {
				if (check != -1) {
					algorithm.mru[fila][check] = algorithm.block[ii];
				}else {
					algorithm.mru[fila][self] = algorithm.block[ii];
				}
			}
		}
	}

	for (ii = 0; ii < algorithm.nConjuntos; ii++) {
		for (jj = 0; jj < algorithm.nVias; jj++) {
			cout<<algorithm.mru[ii][jj]<<" ";
		}
		cout<<endl;
	}


	return 0;
}