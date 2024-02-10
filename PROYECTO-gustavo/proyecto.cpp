#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define N 30

typedef struct{
	int bloque;
	int conjunto;
	char aciertoFallo;
	int tmp_cache[1000];
} resultados;

int lectura_bloques(int bloques[]);
int lectura_configuracion(int correspondencias[2],int algoritmos[2]);
int busqueda(int cache[],int vias,int x);
int lru(int conjunto[],int vias);
void bloques_aleatorios();
void escribir_en_archivo(resultados r[],int n_bloques,int n_lineas,int aciertos,int fallos,int k);
void directa(int bloques[],int n_bloques,int n_lineas);
void reemplazoAleatorio(int bloques[],int n_bloques,int conjuntos,int vias);
void reemplazoLRU(int bloques[],int n_bloques,int conjuntos,int vias);
void asociativaConjuntos(int bloques[],int n_bloques,int n_lineas);
void bienvenida();


int main(){
	bienvenida();
	
	return 0;
}

void bienvenida(){
	int op=0,bloques[1000], n_bloques=0, correspondencias[2],algoritmos[2],n_lineas=0;

	bloques_aleatorios();
	n_bloques = lectura_bloques(bloques);
	n_lineas = lectura_configuracion(correspondencias,algoritmos);
	
	cout<<"\tBIENVENIDO AL SIMULADOR DE MEMORIA CACHE\n";
	cout<<"¿QUE TIPO DE CORRESPONDENCIA DESEAS SIMULAR?\n";
	cout<<"PARA LA CORRESPONDENCIA ASOCIATIVA POR CONJUNTOS SE IMPLEMENTAN LOS REEMPLAZOS:\n";
	cout<<"Aleatorio\nLRU\n";
	cout<<"\tNOTA:Busca los resultados en el archivo resu.out\n";
	do{
		cout<<"(1)CORRESPONDENCIA DIRECTA\n(2)CORRESPONDENCIA ASOCIATIVA POR CONJUNTOS\n";
		cout<<"(3)Salir\n";
		cin>>op;
		op--;
	
		if( op == correspondencias[0] ) directa(bloques,n_bloques,n_lineas);
		else if( op == correspondencias[1] ) asociativaConjuntos(bloques,n_bloques,n_lineas);
	}while( op != 2 );
	
	
}

void bloques_aleatorios(){
	srand(time(NULL));
	int i=100,valor=0;
	FILE *p=fopen("traz.in","w+");
	
	if(p){
		while(i > 0){
			valor = rand() % 99;
			fprintf(p,"%d",valor);
			if( i > 1 ) fprintf(p,"\n");	
			--i;
		}	
	}
	fclose(p);	
}

int lectura_bloques(int bloques[]){
	FILE* flujo = fopen("traz.in","rb");
	int n_bloques=0;
	
	
	if(flujo){
		while(!feof(flujo)){
			fscanf(flujo,"%d",&bloques[n_bloques]);
			n_bloques++;
		}
		fclose(flujo);
	}
	
	return n_bloques;
}

int lectura_configuracion(int correspondencias[2],int algoritmos[2]){
	
	FILE* flujo = fopen("conf.in","rb");
	int n_lineas=0,tamanno_lineas=0,tamanno_cache=0;
	
	/*Guardo la configuracion de config.in*/
	if(flujo){
		fscanf(flujo,"%d",&tamanno_cache);
		fscanf(flujo,"%d %d",&algoritmos[0],&algoritmos[1]);
		fscanf(flujo,"%d",&tamanno_lineas);
		fscanf(flujo,"%d %d",&correspondencias[0],&correspondencias[1]);
		n_lineas = tamanno_cache / tamanno_lineas;
		
		fclose(flujo);
	}
	return n_lineas;
}

void directa(int bloques[],int n_bloques,int n_lineas){
	int index=0,fallos=0,aciertos=0;
	int tmp_cache[n_lineas];
	resultados r[n_bloques];
	
	for(int i=0;i < n_lineas;i++) tmp_cache[i] = -1;
	
	for(int i=0;i < n_bloques;++i){
		index = bloques[i] % n_lineas;
		
		if( bloques[i] == tmp_cache[index] ){
			++aciertos;
			r[i].aciertoFallo = 'A';
		}
		else {
			++fallos;
			r[i].aciertoFallo = 'F';
			tmp_cache[index] = bloques[i];
		}
		r[i].bloque = bloques[i];
		for(int k=0;k < n_lineas;++k) r[i].tmp_cache[k] = tmp_cache[k];
	}
	escribir_en_archivo(r,n_bloques,n_lineas,aciertos,fallos,0);
}

void escribir_en_archivo(resultados r[],int n_bloques,int n_lineas,int aciertos,int fallos,int k){
	FILE* flujo=fopen("resu.out","ab+");
	float tasaFallos,tasaAciertos;
	
	tasaFallos = (fallos/n_bloques);
	tasaAciertos = (aciertos/n_bloques)*100;
	
	if(flujo){
		switch(k){
			case 0:
				fprintf(flujo,"Resultados de la Correspondencia Directa\n");
				fprintf(flujo,"Direccion del bloque de memoria accedido\t¿Acierto o fallo?\tContenido de los bloques de cache despues\n");
				for(int i=0;i < n_bloques;++i){
					fprintf(flujo,"%d\t\t\t\t\t\t\t\t\t\t\t\t%c\t\t\t\t\t",r[i].bloque,r[i].aciertoFallo);
					
					for(int k=0;k < n_lineas;++k){
						if( r[i].tmp_cache[k] != -1 ) fprintf(flujo,"%d  ",r[i].tmp_cache[k]);
						else fprintf(flujo,"-  ");
					}
					fprintf(flujo,"\n");
				};break;
				
			case 1:
				fprintf(flujo,"Resultados de la Correspondencia Asociativa por Conjuntos con Reemplazo Aleatorio\n");
				fprintf(flujo,"Direccion del bloque de memoria accedido\t¿Acierto o fallo?\tConjunto\t");
				fprintf(flujo,"Contenido de las vias del conjunto de cache despues\n");
				
				for(int i=0;i < n_bloques;++i){
					fprintf(flujo,"%d\t\t\t\t\t\t\t\t\t\t\t\t%c\t\t\t\t\t",r[i].bloque,r[i].aciertoFallo);
					fprintf(flujo,"%d\t\t\t\t\t",r[i].conjunto);
					for(int k=0;k < n_lineas;++k){
						if( r[i].tmp_cache[k] != -1 ) fprintf(flujo,"%d  ",r[i].tmp_cache[k]);
						else fprintf(flujo,"-  ");
					}
					fprintf(flujo,"\n");
				};break;
			
			case 2:
				fprintf(flujo,"Resultados de la Correspondencia Asociativa por Conjuntos con Reemplazo LRU\n");
				fprintf(flujo,"Direccion del bloque de memoria accedido\t¿Acierto o fallo?\tConjunto\t");
				fprintf(flujo,"Contenido de las vias del conjunto de cache despues\n");
				
				for(int i=0;i < n_bloques;++i){
					fprintf(flujo,"%d\t\t\t\t\t\t\t\t\t\t\t\t%c\t\t\t\t\t",r[i].bloque,r[i].aciertoFallo);
					fprintf(flujo,"%d\t\t\t\t\t",r[i].conjunto);
					for(int k=0;k < n_lineas;++k){
						if( r[i].tmp_cache[k] != -1 ) fprintf(flujo,"%d  ",r[i].tmp_cache[k]);
						else fprintf(flujo,"-  ");
					}
					fprintf(flujo,"\n");
				};break;
		}
		fprintf(flujo,"Siendo un total de %d aciertos\n",aciertos);
		fprintf(flujo,"Siendo un total de %d fallos\n\n\n",fallos);
		fclose(flujo);
	}
}

void asociativaConjuntos(int bloques[],int n_bloques,int n_lineas){
	int conjuntos,vias;
	
	vias = 4;
	conjuntos = n_lineas/vias;
	
	reemplazoAleatorio(bloques,n_bloques,conjuntos,vias);
	reemplazoLRU(bloques,n_bloques,conjuntos,vias);
}

int busqueda(int cache[],int vias,int x){
	int inicio,fin,medio,via=-1;
	
	inicio = 0;
	fin = vias-1;
	
	while(inicio <= fin){
		if(cache[inicio] == x){
			via = inicio;
			inicio = fin+1;
		}
		++inicio;
	}
	return via;
}

void reemplazoAleatorio(int bloques[],int n_bloques,int conjuntos,int vias){
	srand(time(NULL));
	
	int tmp_cache[conjuntos][vias],conjunto,index,aciertos,fallos,tmp[vias];
	resultados r[n_bloques];
	
	index = 0;
	aciertos = 0;
	fallos = 0;
	
	for(int i=0;i < conjuntos;++i) for(int j=0;j < vias;++j) tmp_cache[i][j] = -1;
	
	for(int b=0;b < n_bloques;++b){
		conjunto = bloques[b] % conjuntos;

		for(int i=0;i < vias;++i) tmp[i] = tmp_cache[conjunto][i];
		index = busqueda(tmp,vias,bloques[b]);
		
		if( index < 0 ){
			index = busqueda(tmp,vias,-1);
			
			if( index < 0 ) index = rand() % vias;
			tmp_cache[conjunto][index] = bloques[b];
			++fallos;
			r[b].aciertoFallo = 'F';
		}
		else {
			++aciertos;
			r[b].aciertoFallo = 'A';
		}
		r[b].bloque = bloques[b];
		r[b].conjunto = conjunto;
		for(int a=0;a < vias;++a) r[b].tmp_cache[a] = tmp_cache[conjunto][a];
	}
	escribir_en_archivo(r,n_bloques,vias,aciertos,fallos,1);
}

int lru(int conjunto[],int vias){
	int via=0,mayor=0;
	
	for(int k=0;k < vias;++k){
		if( mayor < conjunto[k] ){
			mayor = conjunto[k];
			via = k;
		}
	}
	return via;
}

void reemplazoLRU(int bloques[],int n_bloques,int conjuntos,int vias){
	int tmp[vias],tmp_cache[conjuntos][vias],cache_paralela[conjuntos][vias],tmp2[vias];
	int conjunto,index,fallos,aciertos;
	resultados r[n_bloques];
	
	conjunto = 0;
	index = 0;
	fallos = 0;
	aciertos = 0;
	
	for(int i=0;i < conjuntos;++i){
		for(int k=0;k < vias;++k){
			tmp_cache[i][k] = -1;
			cache_paralela[i][k] = 0;
		}
	}
	
	for(int i=0;i < n_bloques;++i){
		conjunto = bloques[i] % conjuntos;
		
		for(int k=0;k < vias;++k){
			tmp[k] = tmp_cache[conjunto][k];
			tmp2[k] = cache_paralela[conjunto][k];
		}
		index = busqueda(tmp,vias,bloques[i]);

		if( index < 0 ){
			index = busqueda(tmp,vias,-1);
			
			if( index < 0 ){
				index = lru(tmp2,vias);
				tmp_cache[conjunto][index] = bloques[i];
				
				for(int k=0;k < vias;++k){
					if( k == index ) cache_paralela[conjunto][k] = 0;
					else cache_paralela[conjunto][k]++;
				} 
			}
			else {
				for(int k=0;k < vias;++k) if( cache_paralela[conjunto][k] != -1 ) cache_paralela[conjunto][k]++;
				tmp_cache[conjunto][index] = bloques[i];
			}
			++fallos;
			r[i].aciertoFallo = 'F';
		}
		else {
			for(int k=0;k < vias;++k){
				if( index == k ) cache_paralela[conjunto][k] = 0;
				else cache_paralela[conjunto][k]++; 
			}
			++aciertos;
			r[i].aciertoFallo = 'A';
		}
		r[i].bloque = bloques[i];
		r[i].conjunto = conjunto;
		
		for(int k=0;k < vias;++k) r[i].tmp_cache[k] = tmp_cache[conjunto][k];
	}
	escribir_en_archivo(r,n_bloques,vias,aciertos,fallos,2);
}
