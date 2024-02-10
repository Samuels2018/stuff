#include"iostream"
#include"fstream"
#include"stdlib.h"
#include"ctime"
#include"cstdlib"
using namespace std;

typedef struct {
	int sizeCache, sizeLine, **matrix; 
	int typeCorresp, replacePolitic;
	int *page, nVia, line, nConjuntos; // los conjuntos son las filas y las vias las columnas
	int **paraleloMat;
	char *successOrFail;
}fileConfig;

typedef struct{
	int *marcos, *contador, **matrix;
}direct;

fileConfig archivo;
direct lru;

void addFileD () {
	int ii = 0, number, jj;
	ofstream f;//o e para aniadir texto al final del archivo por eso es ofstream
	
	f.open("res.out",ios::app);//abrimos el archivo en modo de aniadir al final
	if(f.fail()) {cout<<"el archivo nose pudo abrir"<<endl;exit(-1);}

	number = archivo.line;

	f<<"Direccion del Bloque\t\t\t\t"<<"Acierto `O` Fallo\t\t\t\t";

	while (ii < archivo.line) {
		f<<archivo.page[ii]<<"\t\t\t\t\t\t\t\t\t"; // copio el contenido a el archivo 
		f<<archivo.successOrFail[ii]<<"\t\t\t\t\t\t\t\n";
		ii++;
	}

	f<<"Contenido de los bloques de cache despues de cada acceso\n";

	for (jj = 0; jj < archivo.nVia; jj++) {
		for (int kk = 0; kk < archivo.line; kk++) {
			f<<lru.matrix[jj][kk]<<" ";
		}
		f<<endl;
	}

	f.close();

	return;
}

void addFile () {
	int ii = 0, number, jj;
	ofstream f;//o e para aniadir texto al final del archivo por eso es ofstream
	
	f.open("res.out",ios::app);//abrimos el archivo en modo de aniadir al final
	if(f.fail()) {cout<<"el archivo nose pudo abrir"<<endl;exit(-1);}

	number = archivo.line;

	f<<"Direccion del Bloque\t\t\t\t"<<"Acierto `O` Fallo\t\t\t\t";

	while (ii < archivo.line) {
		f<<archivo.page[ii]<<"\t\t\t\t\t\t\t\t\t";
		f<<archivo.successOrFail[ii]<<"\t\t\t\t\t\t\t\n";
		ii++;
	}

	f<<"Contenido de los bloques de cache después de cada acceso\n";

	for (jj = 0; jj < archivo.nConjuntos; jj++) {
		for (int kk = 0; kk < archivo.nConjuntos; kk++) {
			f<<archivo.matrix[jj][kk]<<" ";
		}
		f<<endl;
	}

	f.close();

	return;
}


int checkNumberStored (int kk) {
	int ii, ver;

	ver = -1;

	for (ii = 0; ii < archivo.nVia-1; ii++) {
		if (lru.marcos[ii] == archivo.page[kk]) { // virifico si lo que est en el vector paralelo 
			ver = 0; -- es igual a la posicion del bloque
		}
	}

	return ver;

}

int directPositionNumber () {

	int ii, bigger = 0, v1[1] ,aux;

	for (ii = 0; ii < archivo.nVia; ii++) { // busco el numero mas grande 
		if (lru.contador[ii] > bigger) {
			bigger = lru.contador[ii]; // y luego almaceno la pocicion de ese numeo
			v1[0] = ii;
			aux = v1[0];
		}
	}

	aux = v1[0];

	return aux;
}

void directCiclo (int nn, int jj) {
	int ii;

	for (ii = 0; ii <= nn; ii++) {
		lru.matrix[ii][jj] = lru.marcos[ii]; // 
	}

	return;
}

void correspondenciaDirectaMru () { // lista

	int ii, jj, kk = 0, ll = 0, nn = 0;
	int aux, bigger = 0,  mm = 0, ver;

	lru.marcos = new int[archivo.nVia];


	for (jj = 0; jj < archivo.line; jj++) {

		if (nn == archivo.nVia-1) {
			for (ii = 0; ii < archivo.nVia; ii++) {
				aux = ii;
				lru.matrix[ii][jj] = lru.marcos[ii];
			}

			ver = checkNumberStored(kk);

			if (ver != 0) {
				lru.marcos[aux] = archivo.page[kk];
				lru.matrix[aux][jj] = archivo.page[kk];
				archivo.successOrFail[jj] = 'F';
			}else {
				for (ii = 0; ii < aux; ii++) {
					lru.matrix[ii][jj] = lru.marcos[ii];
				}
				archivo.successOrFail[jj] = 'A';
			}
			kk++;	
		}

		if (ll == 0 && jj == 0) { 
			lru.matrix[ll][jj] = archivo.page[kk];
			lru.marcos[nn] = archivo.page[kk];
			archivo.successOrFail[jj] = 'F';
			kk++;

		} 

		ver = checkNumberStored(kk);

		if (ver != -1) {

			if (nn == 0) {
				lru.matrix[ll][jj] = lru.marcos[nn];
				archivo.successOrFail[jj] = 'A';
				kk++;
			}else {
				directCiclo(nn,jj);
				archivo.successOrFail[jj] = 'A';
				kk++;
			}
		}else if ( (archivo.page[kk] != lru.marcos[nn]) && (jj > 0) ) {
			if (nn == 0) {
				lru.matrix[ll][jj] = lru.marcos[nn];
				nn++;
				ll = nn;
				lru.matrix[ll][jj] = archivo.page[kk];
				lru.marcos[nn] = archivo.page[kk];
				archivo.successOrFail[jj] = 'F';
				kk++;

			}else {
				if (nn < archivo.nVia-1) {
					directCiclo(nn,jj);
					nn++;
					ll = nn;
					lru.matrix[ll][jj] = archivo.page[kk];
					lru.marcos[nn] = archivo.page[kk];
					archivo.successOrFail[jj] = 'F';
					kk++;
				}

			}

		}

	}

	addFileD();

	for (ii = 0; ii < archivo.nVia; ii++) {
		for (jj = 0; jj < archivo.line; jj++) {
			cout<<lru.matrix[ii][jj]<<" ";
		}
		cout<<endl;
	}

	return;
}


void correspondenciaDirectaLru () { // lista

	int ii, jj, kk = 0, ll = 0, mm = 0, nn = 0;
	int aux, bigger = 0, ver;

	lru.marcos = new int[archivo.nVia];
	lru.contador = new int[archivo.nVia];

	for (jj = 0; jj < archivo.line; jj++) {

		if (nn == archivo.nVia-1) {

			ver = checkNumberStored(kk); // verifica si algun numero almacenado coincide con el nuevo 

			if ( ver != 0) {
				for (ii = 0; ii < archivo.nVia; ii++) {
					lru.matrix[ii][jj] = lru.marcos[ii];
					if (lru.matrix[ii][jj] == lru.marcos[aux]) {
						lru.marcos[aux] = archivo.page[kk];
						lru.matrix[ii][jj] = lru.marcos[ii];
						lru.contador[ii] = -1;
					}
				}

				archivo.successOrFail[jj] = 'F';

				for(int i=0; i < archivo.nVia; ++i){
					lru.contador[i]++;
				}

				aux = directPositionNumber(); // retorna la posicion del numero que lleva menos tiempo usado
				
			}else {
				for (ii = 0; ii < archivo.nVia; ii++) {
					lru.matrix[ii][jj] = lru.marcos[ii];
					if (lru.marcos[ii] == archivo.page[kk]) {
						lru.contador[ii] = 0;
					}
				}
				archivo.successOrFail[jj] = 'A';
			}
			kk++;	
		}


		if (ll == 0 && jj == 0) { 
			lru.matrix[ll][jj] = archivo.page[kk];
			lru.marcos[nn] = archivo.page[kk];
			archivo.successOrFail[jj] = 'F';
			kk++;

		} 

		ver = checkNumberStored(kk);

		if (ver != -1) {

			if (nn == 0) {
				lru.matrix[ll][jj] = lru.marcos[nn];
				archivo.successOrFail[jj] = 'A';
				kk++;
			}else {
				directCiclo(nn,jj);
				archivo.successOrFail[jj] = 'A';
				kk++;
			}
		}else if ( (archivo.page[kk] != lru.marcos[nn]) && (jj > 0) ) {
			if (nn == 0) {
				lru.matrix[ll][jj] = lru.marcos[nn];
				nn++;
				ll = nn;
				lru.matrix[ll][jj] = archivo.page[kk];
				lru.marcos[nn] = archivo.page[kk];

				for(int i=0; i < archivo.nVia; ++i){
					if( i != nn && lru.marcos[i] != 0 ) lru.contador[i]++;
					else if( i == nn ) lru.contador[i] = 0;
				}

				archivo.successOrFail[jj] = 'F';
				kk++;

			}else {
				if (nn < archivo.nVia-1) {
					directCiclo(nn,jj);
					nn++;
					ll = nn;
					lru.matrix[ll][jj] = archivo.page[kk];
					lru.marcos[nn] = archivo.page[kk];

					for(int i=0; i < archivo.nVia; ++i){
						if( i != nn && lru.marcos[i] != 0 ) lru.contador[i]++;
						else if( i == nn ) lru.contador[i] = 0;
					}

					archivo.successOrFail[jj] = 'F';
					kk++;
				}

				aux = directPositionNumber();

			}

		}

	}

	addFileD();

	for (ii = 0; ii < archivo.nVia; ii++) {
		for (jj = 0; jj < archivo.line; jj++) {
			cout<<lru.matrix[ii][jj]<<" ";
		}
		cout<<endl;
	}

	return;
}

void correspondenciaAsosciativaXconjuntosLru () {

	int ii, fila, kk = 0 ,jj, post, bigger, ll = 0;
	int aux, self, check, n[1], position[1];

	lru.marcos = new int[archivo.nConjuntos];
	lru.contador = new int[archivo.nConjuntos];

	for (ii = 0; ii < archivo.line; ii++) {
		fila = archivo.page[ii] % archivo.nConjuntos;

		if (archivo.matrix[fila][kk] == 0) {
			archivo.matrix[fila][kk] = archivo.page[ii];
			archivo.paraleloMat[fila][ll]++;
			archivo.successOrFail[ii] = 'F';

		}else {
			aux = 0;
			self = 0;
			for (jj = 0; jj < archivo.nVia; jj++) {
				if (archivo.matrix[fila][jj] > 0) self++;
			}

			aux = self;
			self--;
			n[0] = -1;

			for (jj = 0; jj <= self; jj++) {
				if (archivo.matrix[fila][jj] == archivo.page[ii]) {
					n[0] = jj;
				}
			}

			check = n[0];
			
			if (aux < archivo.nVia) {
				if (check != -1) {
					archivo.matrix[fila][check] = archivo.page[ii];
					archivo.paraleloMat[fila][ll] = 0;
					archivo.successOrFail[ii] = 'A';
				}else {
					archivo.matrix[fila][aux] = archivo.page[ii];
					archivo.paraleloMat[fila][ll]++;
					archivo.successOrFail[ii] = 'F';
				} 
			}else {
				if (check != -1) {
					archivo.matrix[fila][check] = archivo.page[ii];
					archivo.paraleloMat[fila][ll] = 0;
					archivo.successOrFail[ii] = 'A';
				}else {
					// implemento el algoritmo
					for (jj = 0; jj < archivo.nVia; jj++) {
						if (archivo.paraleloMat[fila][jj] > bigger) {
							bigger = archivo.paraleloMat[fila][jj];
							position[0] =  jj;
						}
					}
					post = position[0];

					archivo.matrix[fila][post] = archivo.page[ii];
					archivo.successOrFail[ii] = 'F';
				}
			}
		}
	}


	addFile();

	for (ii = 0; ii < archivo.nConjuntos; ii++) {
		for (jj = 0; jj < archivo.nVia; jj++) {
			cout<<archivo.matrix[ii][jj]<<" ";
		}
		cout<<endl;
	}


	return;
}

void correspondenciaAsosciativaXconjuntosMru () { // lista

	int ii, fila, kk = 0 ,jj;
	int aux, self, check, n[1];

	for (ii = 0; ii < archivo.line; ii++) {
		fila = archivo.page[ii] % archivo.nConjuntos;

		if (archivo.matrix[fila][kk] == 0) {
			archivo.matrix[fila][kk] = archivo.page[ii];
			archivo.successOrFail[ii] = 'F';

		}else {
			aux = 0;
			self = 0;
			for (jj = 0; jj < archivo.nVia; jj++) {
				if (archivo.matrix[fila][jj] > 0) self++;
			}

			aux = self;
			self--;
			n[0] = -1;

			for (jj = 0; jj <= self; jj++) {
				if (archivo.matrix[fila][jj] == archivo.page[ii]) {
					n[0] = jj;
				}
			}

			check = n[0];
			
			if (aux < archivo.nVia) {
				if (check != -1) {
					archivo.matrix[fila][check] = archivo.page[ii];
					archivo.successOrFail[ii] = 'A';
				}else {
					archivo.matrix[fila][aux] = archivo.page[ii];
					archivo.successOrFail[ii] = 'F';
				} 
			}else {
				if (check != -1) {
					archivo.matrix[fila][check] = archivo.page[ii];
					archivo.successOrFail[ii] = 'A';
				}else {
					archivo.matrix[fila][self] = archivo.page[ii];
					archivo.successOrFail[ii] = 'F';
				}
			}
		}
	}

	for (ii = 0; ii < archivo.nConjuntos; ii++) {
		for (jj = 0; jj < archivo.nVia; jj++) {
			cout<<archivo.matrix[ii][jj]<<" ";
		}
		cout<<endl;
	}

	addFile();

	return;
}

void randomNumber () {

	int number, val = 0;
	fstream g;
	srand(time(NULL));

	g.open("traz.in",ios::out);//abrimos el archivo en modo de aniadir al final
	if(g.fail()) {cout<<"el archivo nose pudo abrir"<<endl;exit(-1);}

	number = archivo.line;

	while (number > 0) {

		val = 1+rand() % 50;
		(number > 1) ? g<<val<<"\n" : g<<val;
		number--;
	}

	g.close();

	return;
}

void fileConfiguration () {
	int ii, jj, kk = 0;
	fstream f, g; // archivo 

	f.open("conf.in",ios::in); // es el formato que se usa para leer el archivo
	if (f.fail()) {
		cout<<"el archivo no se pudo abrir \n\a";exit(-1);
	}

	g.open("traz.in",ios::in); // es el formato que se usa para leer el archivo
	if (g.fail()) {
		cout<<"el archivo no se pudo abrir \n\a";exit(-1);
	}

	while (!f.eof()) {
		f>>archivo.sizeCache;
		f>>archivo.typeCorresp;
		f>>archivo.sizeLine;
		f>>archivo.replacePolitic;
	}

	archivo.nVia = 4; // 4 columnas										
	archivo.line = archivo.sizeCache/archivo.sizeLine;
	archivo.nConjuntos = archivo.line/archivo.nVia; // 8 filas

	archivo.matrix = new int*[archivo.nConjuntos];
	archivo.paraleloMat = new int*[archivo.nConjuntos];
	lru.matrix = new int*[archivo.nVia];

	for (ii = 0; ii < archivo.nConjuntos; ii++) {
		archivo.matrix[ii] = new int[archivo.nVia];
		archivo.paraleloMat[ii] = new int[archivo.nVia];
	}

	for (ii = 0; ii < archivo.nConjuntos; ii++) {
		for (jj = 0; jj < archivo.nVia; jj++) {
			archivo.matrix[ii][jj] = 0;
			archivo.paraleloMat[ii][jj] = 0;
		}
	}

	for (ii = 0; ii < archivo.nVia; ii++) {
		lru.matrix[ii] = new int[archivo.line];
	}

	for (ii = 0; ii < archivo.nVia; ii++) {
		for (jj = 0; jj < archivo.line; jj++) {
			lru.matrix[ii][jj] = 0;
		}
	}

	archivo.page = new int[archivo.line];
	archivo.successOrFail = new char[archivo.line];

	randomNumber();

	while (!g.eof()) {
		g>>archivo.page[kk];
		kk++;
	}

	f.close();
	g.close();


	return;

}


int main (int argc, char **argv) {

	fileConfiguration();

	if (archivo.typeCorresp == 0) { // corespondencia directa 
		if (archivo.replacePolitic == 0) { // lru

			correspondenciaDirectaLru();

		}else { // mru
			correspondenciaDirectaMru();
		}
	}else { // correspondencia asociativa por conjuntos
		if (archivo.replacePolitic == 0) { // lru
			correspondenciaAsosciativaXconjuntosLru();
		}else { // mru
			correspondenciaAsosciativaXconjuntosMru();
		}
	}

	return 0;
}
