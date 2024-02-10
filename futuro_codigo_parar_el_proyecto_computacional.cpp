//futuro codigo parar el proyecto computacional
//n = 150217; -> ano = n%0.01; n /=100; mes = n %0.01; n /=100; dia = n%0.01; n /=100;

#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;


int main(int argc, char **argv) {
	
	int cant, dia, mes; 
    int anio, dia1, mes1, anio1;
	int dde, dds, ii=1;
	
	cout<<"introduce la fecha de entrada: ";cin>>dde;
	cout<<"introduce la fecha de salida: ";cin>>dds;
    anio = dde%10000; dde /= 10000;
    mes = dde% 100; dde /= 100;
    dia = dde%100; dde /= 100;
    anio1 = dds%10000; dds /= 10000;
    mes1 = dds% 100; dds /= 100;
    dia1 = dds%100; dds /= 100;
   
   while(anio <= anio1) {
    	while((mes <= mes1) && (mes < 12)) {	
			while(((dia != dia1) || (dia <= dia1)) && (dia<30)) {
				dia++;
				ii++;
			}
			mes++;
			dia=1;
			ii++;		
		}
		anio++;
		mes=1;
		dia =1;
		ii++;
	}
	cout<<ii<<" dias";
	
	/*if((dia == dia1) && (mes < mes1)) {
		dia++;
		ii++;
	}
	else if((mes == mes1) && ( anio < anio1)) {
		mes++;
		cant = 30-dia;
		dia =1;
		ii += cant;
	}
	
	while((anio <= anio1) && (mes <= mes1) && (dia != dia1)){
		if(dia > 29) {
            dia = 01;
            mes++;
            ii++;
        }
		else if(mes > 11) {
            mes =01;
            dia =01;
            anio++;
            ii++;
		}
		else if((mes == mes1) && ( anio < anio1)) {
    		mes++;
    		cant = 30-dia;
    		dia =1;
    		ii += cant;
    	}
        dia++;
        ii++;
	}
	cout<<ii;*/
	
	return 0;
}  
