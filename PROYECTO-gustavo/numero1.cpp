#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

typedef int* vector;
struct registro{
	int bloque;
	char aciertoFallo;
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
	FILE* flujo=fopen("resu.out","wb");
	
	if(flujo){
		fprintf(flujo,"Direccion del bloque de memoria accedido\t¿Acierto o fallo?\tContenido de los bloques de cache despues\n");
		
		for(int i=0;i < n_bloques;++i){
			fprintf(flujo,"%d\t\t\t\t\t\t\t\t\t\t\t\t%c\t\t\t\t\t",resultados[i].bloque,resultados[i].aciertoFallo);
			
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

//Algoritmo correspondencia directa con Algoritmo Reemplazo LRU
void directaLRU(void){
	int tmp_cache[n_lineas],paralelo[n_lineas],lru,tmp,index;
	
	for(int i=0;i < n_lineas;++i) tmp_cache[i] = -1;	//inicializando cache
	for(int i=0;i < n_lineas;++i) paralelo[i] = 0;	
	
	lru=0; //posicion de la linea de reemplazo
	tmp=0;
	fallos=0;
	aciertos=0;
	index = 0;
	
	for(int i=0;i < n_bloques;++i){
		index = busqueda(tmp_cache,n_lineas,bloques[i]); //busco el bloque en la cache
		
		if( index < 0 ){ //el bloque no se encontro
			index = busqueda(tmp_cache,n_lineas,-1); //busco una linea vacia
			
			if( index < 0 ){ //la linea no se encontro
				for(int k=0;k < n_lineas;++k){ //identifico la linea que mas tiempo lleva sin ser identificada
					if( tmp < paralelo[k] ) {
						tmp = paralelo[k];
						lru = k; //esa linea se guarda en lru
					}
				}
				tmp = 0;
				tmp_cache[lru] = bloques[i]; //se guarda el bloque en el lru
				
				for(int k=0;k < n_lineas;++k){ //como no se usaron las demas lineas entonces estas aumentan en 1
					if( k == lru ) paralelo[lru] = 0; //la que acaba de ser usada se reinicia
					else paralelo[k]++;
				}
			}
			else{
				for(int k=0;k < n_lineas;++k){
					if( tmp_cache[k] != -1 ) paralelo[k]++;
				}
				
				tmp_cache[index] = bloques[i]; //guardo el bloque en ella
			}
			++fallos;
			resultados[i].aciertoFallo = 'F';
		}
		else {
			for(int k=0;k < n_lineas;++k){
				if( k == index ) paralelo[k] = 0;
				else paralelo[k]++;
			}
			++aciertos;
			resultados[i].aciertoFallo = 'A';
		}
		resultados[i].bloque = bloques[i];
		for(int k=0;k < n_lineas;++k) resultados[i].tmp_cache[k] = tmp_cache[k];
	}
	escribir_en_archivo();
}

//Algoritmo correspondencia directa con Reemplazo Aleatorio
void directaAleatoria(void){
	srand(time(NULL));
	int tmp_cache[n_lineas],index;
	
	fallos = 0;
	aciertos = 0;
	index = 0;
	
	for(int i=0;i < n_lineas;++i) tmp_cache[i] = -1;
	
	for(int i=0;i < n_bloques;++i){
		index = busqueda(tmp_cache,n_lineas,bloques[i]);
		
		if( index < 0 ){
			index = busqueda(tmp_cache,n_lineas,-1);
			
			if( index < 0 ) index = rand()%n_lineas;
			
			tmp_cache[index] = bloques[i];
			++fallos;
			resultados[i].aciertoFallo = 'F';
		}
		else{
			++aciertos;
			resultados[i].aciertoFallo = 'A';
		}
		resultados[i].bloque = bloques[i];
		for(int k=0;k < n_lineas;++k) resultados[i].tmp_cache[k] = tmp_cache[k];
	}
	escribir_en_archivo();
}

void asociativaConjuntos(void){
	
}

//menu
void bienvenida(void){
	int op=0;
	resultados = (struct registro*)malloc(sizeof(struct registro)*n_bloques);
	
	for(int i=0;i < n_bloques;++i) resultados[i].tmp_cache = (vector)malloc(sizeof(int)*n_lineas);
	
	cout<<"\tBIENVENIDO AL SIMULADOR DE MEMORIA CACHE\n";
	cout<<"¿QUE TIPO DE CORRESPONDENCIA DESEAS SIMULAR?\n";
	cout<<"PARA AMBAS CORRESPONDENCIA SE IMPLEMENTARAN LAS POLITICAS DE REEMPLAZO\n";
	cout<<"Aleatorio\nLRU\n";
	cout<<"(1)CORRESPONDENCIA DIRECTA\n (2)CORRESPONDENCIA ASOCIATIVA POR CONJUNTOS\n";
	do{
		cin>>op;
	}while(op <= 0 || op >= 3);
	
	op--;
	
	if( op == algoritmos[0] ) directaAleatoria();
	else if( op == algoritmos[1] ) asociativaConjuntos();
}

int main(int argc, char** argv) {
	lectura_configuracion();
	lectura_bloques();
	bienvenida();
	
	return 0;
}
