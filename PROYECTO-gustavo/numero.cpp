#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

typedef int* vector;
struct registro{
	int bloque;
	char aciertoFallo;
	int conjunto;
	vector tmp_cache;	
};

//direcciones de bloques de memoria
vector bloques;
int n_bloques=0;

//configuracion de la cache
int tamanno_cache=0;
int tamanno_lineas=0;
int n_lineas=0;
vector algoritmos;
vector correspondencias;

//resultados
struct registro* resultados;
int fallos;
int aciertos;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Leera la configuracion de la cache
void lectura_configuracion(void){
	FILE* flujo = fopen("conf.in","rb");
	algoritmos = (vector)malloc(sizeof(int)*2);
	correspondencias = (vector)malloc(sizeof(int)*2);
	
	/*Guardo la configuracion de config.in*/
	if(flujo){
		fscanf(flujo,"%d",&tamanno_cache);
		fscanf(flujo,"%d %d",&algoritmos[0],&algoritmos[1]);
		fscanf(flujo,"%d",&tamanno_lineas);
		fscanf(flujo,"%d %d",&correspondencias[0],&correspondencias[1]);
		n_lineas = tamanno_cache / tamanno_lineas;
		
		fclose(flujo);
	}
}

//leera cada bloque
void lectura_bloques(void){
	FILE* flujo = fopen("traz.in","rb");
	vector aux;
	bloques = (vector)malloc(sizeof(vector));
	aux = bloques;
	
	
	if(flujo){
		while(!feof(flujo)){
			fscanf(flujo,"%d",aux);
			aux++;
			n_bloques++;
		}
		fclose(flujo);
	}
}

//Busqueda que se efectuara para hallar un bloque, se asume que los bloques en la cache no estan ordenados
int busqueda(int cache[],int lineas,int bloque){
	int inicio,fin,medio,linea=-1;
	
	inicio = 0;
	fin = lineas-1;
	
	while(inicio <= fin){
		if(cache[inicio] == bloque) linea = inicio;
		++inicio;
	}
	return linea;
}

void escribir_en_archivo(void){
	FILE* flujo=fopen("resu.out","ab+");
	
	if(flujo){
		fprintf(flujo,"Direccion del bloque de memoria accedido\t¿Acierto o fallo?\tContenido de los bloques de cache despues\n");
		
		for(int i=0;i < n_bloques;++i){
			fprintf(flujo,"%d\t\t\t\t\t\t\t\t\t\t\t\t%c\t\t\t\t\t",resultados[i].bloque,resultados[i].aciertoFallo);
			//fprintf(flujo,"Conjunto:%d\t\t\t\t\t",resultados[i].conjunto);
			for(int k=0;k < n_lineas;++k){
				if( resultados[i].tmp_cache[k] != -1 ) fprintf(flujo,"%d  ",resultados[i].tmp_cache[k]);
				else fprintf(flujo,"-  ");
			}
			fprintf(flujo,"\n");
		}
		fprintf(flujo,"La tasa de aciertos fue de %d\nLa tasa de fallos fue de %d\n",aciertos,fallos);
		fclose(flujo);
	}
}

//Algoritmo correspondencia directa
void directa(){
	int index;
	vector tmp_cache;
	
	tmp_cache=(vector)malloc(sizeof(int)*n_lineas);
	index = 0;
	fallos = 0;
	aciertos = 0;
	
	for(int i=0;i < n_lineas;i++) tmp_cache[i] = -1;
	
	for(int i=0;i < n_bloques;++i){
		index = bloques[i] % n_lineas;
		
		if( bloques[i] == tmp_cache[index] ){
			++aciertos;
			resultados[i].aciertoFallo = 'A';
		}
		else {
			++fallos;
			resultados[i].aciertoFallo = 'F';
			tmp_cache[index] = bloques[i];
		}
		resultados[i].bloque = bloques[i];
		for(int k=0;k < n_lineas;++k) resultados[i].tmp_cache[k] = tmp_cache[k];
	}
	escribir_en_archivo();
}

void asociativaConjuntosLRU(void){
	
	vector conjunto,*tmp_cache,*cache_paralela,paralelo;
	int index,lru,conj,vias,tmp;
	
	//mi cache de 1024 tendra 64 lineas, cada conjunto tendra 4 vias entonces seran 16 conjuntos
	//pero para prueba tendra 8 lineas, cada conjunto tendra 2 vias entonces seran 4 conjuntos
	index=0;
	lru=0;
	vias = 2;
	tmp = 0;
	conj = n_lineas/vias;
	//reservo espacio en la memoria para los conjuntos(filas)
	tmp_cache = (vector*)malloc(sizeof(vector)*conj);
	cache_paralela = (vector*)malloc(sizeof(vector)*conj);
	conjunto = (vector)malloc(sizeof(int)*vias);
	paralelo = (vector)malloc(sizeof(int)*vias);
	//reservo espacio en la memoria para las vias(columnas)
	for(int i=0;i < conj;++i){
		tmp_cache[i] = (vector)malloc(sizeof(int)*vias);
		cache_paralela[i] = (vector)malloc(sizeof(int)*vias);
	}
	//una vez reservado el espacio en memoria para mi cache con sus filas(conjuntos) y columnas(vias)
	//inicializo las lineas de mi cache y mi cache paralela
	for(int i=0;i < conj;++i){
		for(int k=0;k < vias;++k){
			tmp_cache[i][k] = -1;
			cache_paralela[i][k] = 0;
		}
	}
	
	for(int i=0;i < n_bloques;++i){
		cout<<"Bloque:"<<bloques[i]<<"\n";
		index = bloques[i] % conj;
		index = (index < 0) ? index*(-1) : index; 
		
		for(int k=0;k < vias;++k){
			conjunto[k] = tmp_cache[index][k];
			paralelo[k] = cache_paralela[index][k];
		}
		index = busqueda(conjunto,vias,bloques[i]);

		if( index < 0 ){
			index = busqueda(conjunto,vias,-1);
			
			if( index < 0 ){
				for(int k=0;k < vias;++k){
					if( tmp < paralelo[k] ){
						tmp = paralelo[k];
						lru = k;
					}
				}
				tmp = 0;
				conjunto[lru] = bloques[i];
				
				for(int k=0;k < vias;++k){
					if( k == lru ) paralelo[lru] = 0;
					else paralelo[k]++;
				} 
			}
			else {
				for(int k=0;k < vias;++k) if( conjunto[k] != -1 ) paralelo[k]++;
				conjunto[index] = bloques[i];
			}
			++fallos;
			resultados[i].aciertoFallo = 'F';
		}
		else {
			for(int k=0;k < vias;++k){
				if( index == k ) paralelo[k] = 0;
				else paralelo[k]++; 
			}
			++aciertos;
			resultados[i].aciertoFallo = 'A';
		}
		index = bloques[i] % conj;
		index = (index < 0) ? index*(-1) : index;
		resultados[i].bloque = bloques[i];
		resultados[i].conjunto = index;
		
		for(int k=0;k < vias;++k){
			tmp_cache[index][k] = conjunto[k];
			cache_paralela[index][k] = paralelo[k];
			resultados[i].tmp_cache[k] = conjunto[k]; //ahora este campo de estructura no es una cache sino un conjunto
		}
	}
	escribir_en_archivo();
}

void asociativaConjuntosAleatoria(void){
	srand(time(NULL));
	vector *tmp_cache,conjunto;
	int index,conj,vias,tmp,bloque;
	
	index = 0;
	vias = 2;
	conj = n_lineas/vias;
	aciertos = 0;
	fallos = 0;
	bloque = 0;
	tmp_cache = (vector*)malloc(sizeof(vector)*conj);
	conjunto = (vector)malloc(sizeof(int)*vias);
	for(int i=0;i < conj;++i) tmp_cache[i] = (vector)malloc(sizeof(int)*vias);
	
	for(int i=0;i < conj;++i) for(int j=0;j < vias;++j) tmp_cache[i][j] = -1;
	//lectura_bloques();
	
	for(int b=0;b < n_bloques;++b){
		index = bloques[b] % conj;
		index = (index < 0) ? index*(-1) : index;
		
		for(int i=0;i < vias;++i) conjunto[i] = tmp_cache[index][i];
		tmp = busqueda(conjunto,vias,bloques[b]);
		
		if( tmp < 0 ){
			tmp = busqueda(conjunto,vias,-1);
			
			if( tmp < 0 ) tmp = rand() % vias;
			tmp_cache[index][tmp] = bloques[b];
			++fallos;
			resultados[b].aciertoFallo = 'F';
		}
		else {
			++aciertos;
			resultados[b].aciertoFallo = 'A';
		}
		resultados[b].bloque = bloques[b];
		resultados[b].conjunto = index;
		for(int a=0;a < vias;++a) resultados[b].tmp_cache[a] = tmp_cache[index][a];
	}
	escribir_en_archivo();
}

//menu
void bienvenida(void){
	int op=0,sub=0;
	resultados = (struct registro*)malloc(sizeof(struct registro)*n_bloques);
	
	for(int i=0;i < n_bloques;++i) resultados[i].tmp_cache = (vector)malloc(sizeof(int)*n_lineas);
	
	cout<<"\tBIENVENIDO AL SIMULADOR DE MEMORIA CACHE\n";
	cout<<"¿QUE TIPO DE CORRESPONDENCIA DESEAS SIMULAR?\n";
	cout<<"PARA AMBAS CORRESPONDENCIA SE IMPLEMENTARAN LAS POLITICAS DE REEMPLAZO\n";
	cout<<"Aleatorio\nLRU\n";
	cout<<"\tNOTA:Busca los resultados en el archivo resu.out\n";
	do{
		cout<<"(1)CORRESPONDENCIA DIRECTA\n(2)CORRESPONDENCIA ASOCIATIVA POR CONJUNTOS\n";
		cout<<"(3)Salir\n";
		cin>>op;
		
		op--;
	
		if( op == correspondencias[0] ) directa();
		else if( op == correspondencias[1] ){
			//asociativaConjuntosLRU();
			asociativaConjuntosAleatoria();
		}
	}while( op != 2 );
}

int main(int argc, char** argv) {
	lectura_configuracion();
	lectura_bloques();
	bienvenida();
	
	return 0;
}
