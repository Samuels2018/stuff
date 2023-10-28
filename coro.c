
#include<stdio.h>

typedef struct {
	char cedula[10];
	char fechaDeNacimiento[10];
	char nombreDelCandidato[20];
	int voto;

}datos;

int main () {
	int cantidadDeAlumnos, candidatosAPostularse, ii = 1, jj;
	int votoEnBlanco = 0, voto;
	int votoNulo = 0, verificarVotos, aux;

	printf("introdusca la cantidad de estudiantes: ");
	scanf("%d", &cantidadDeAlumnos);
	printf("introdusca el numero de candidatos a postularse: ");
	scanf("%d", &candidatosAPostularse);
	datos postulados[candidatosAPostularse];
	jj = candidatosAPostularse;
	while (jj > 0) {
		printf("introdusca la cedula del candidato %d ",ii);
		scanf("%s", postulados[ii].cedula);
		printf("introdusca la fecha de nacimiento %d ",ii);
		scanf("%s", postulados[ii].fechaDeNacimiento);
		printf("introdusca el nombre del candidato a postularse %d ",ii);
		scanf("%s", postulados[ii].nombreDelCandidato);
		jj--;
		ii++;
	}

	ii = 1;
	jj = candidatosAPostularse;

	while(cantidadDeAlumnos > 0 || voto  < 0) {
		printf("introdusca el numero del candidato por el cual quisiera votar \n");
		while (jj > 0) {
			printf("%d) para %s\n",jj,postulados[jj].nombreDelCandidato);
			jj--;

		}
		scanf("%d",voto);

		if (voto == 0) {
			votoEnBlanco++;
		
		}else if(voto > candidatosAPostularse){

			votoNulo++;
		
		}else{

			postulados[voto].voto++;
		}

				
		cantidadDeAlumnos--;
		ii++;
	}

	jj = candidatosAPostularse;

	printf("cantidad de votos %d \n", ii);
	printf("cantidad de votos nulos %d \n", votoNulo);
	printf("cantidad de votos en blanco %d \n", votoEnBlanco);
	while (jj > 0) {
		verificarVotos = postulados[jj].voto;
		if (verificarVotos < postulados[jj-1].voto) {
			verificarVotos = postulados[jj-1].voto;
		}
		jj--;
	}

	printf("%s %s %s %d\n",postulados[jj].cedula,postulados[jj].fechaDeNacimiento,postulados[jj].nombreDelCandidato,postulados[jj].voto);
		

	

	return 0;
}