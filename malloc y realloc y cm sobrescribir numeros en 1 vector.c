

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void aleatorio(int *v, int n);

int main(int argc, char **argv[]) {
	
	int ii, jj, kk;
	int n = 10;
	int *v;
	
	v = (int *)malloc(n*sizeof(int));
	if(v == NULL) {
		printf("no ha podido reserva espacio de memoria");
	}
	else{
		aleatorio(v,n);
		
		for(ii =0; ii <n; ii++) {
			jj = ii+1;
			while(jj <n) {
				if(*(v+ii) == *(v+jj)) {
					for(kk = jj; kk+1 < n; kk++) {
						*(v+kk) = *(v+kk+1);
					}
					n--;
				}
				else{
					jj++;
				}
			}
		}
		v = (int *)realloc(v,n*sizeof(int)); // realloc se usa para conservar los elementos exitentes en un vector dinamico pq si uso malloc los puedes borrar
		if(v == NULL) {
	    	printf("no ha podido reserva espacio de memoria");
	    }
	    else{
	    	for(ii =0; ii < n; ii++) {
	    		printf("%d, ",*(v+ii));
			}
			printf("\n");
		}
	}
	
	free(v); //  free se usa libera la memoria que se esta utilizando
	return 0;  // pq sino se libera la memoria se almacenara en la memoria ram como ocupada y consume recursos
}

void aleatorio(int *v, int n) {
	
	int ii;
	srand(time(NULL));
	
	for(ii =0; ii < n; ii++) {
		*(v+ii) = rand() % 3;
		printf("%d, ",*(v+ii));
	}
	printf("\n");
}
