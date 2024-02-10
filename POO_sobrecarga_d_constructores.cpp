//sobrecarga de constructores
#include"iostream"
#include"stdlib.h"
using namespace std;

class fecha{
	private:
		int dia;
		int mes;
		int anio;
	public:
		fecha(int,int,int);
		fecha(int);
		//fechas(int); 
		void mostrar();
};

fecha::fecha(int _dia,int _mes,int _anio){
	dia=_dia;
	mes = _mes;
	anio = _anio;
}
//puse como comentarios ste constructor pq stoy usando otro
//y no puedo usar los 2 q staria pasando 1 entero a la mismo cnstructor y eso no se puede hacer
/*fecha::fecha(int date){
	anio = int(date/10000);
	mes = int((date-anio*10000)/100);
	dia = int((date-anio*10000-mes*100));
}*/

fecha::fecha(int dat){
	dia = dat%100;dat/=100;
	mes = dat%100;dat/=100;
	anio = dat%10000;dat/=10000;
}

void fecha::mostrar(){
	cout<<"la fecha es: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

int main(int argc, char **argv){
	fecha hoy(11,01,2018);
	fecha ayer(20180110);
	//fecha test(20180220);

	hoy.mostrar();
	ayer.mostrar();
	//test.mostrar();

	return 0;
}