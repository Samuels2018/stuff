//Herencia
#include"iostream"
#include"stdlib.h"
using namespace std;

class persona{
	private:
		string nom;
		int age;
	public:
		persona(string,int);
		void mostrar();
};

class alumno : public persona{
	private:
		string num;
		float nota;
	public:
		alumno(string,int,string,float);
		void mostraralumno();
};

persona::persona(string _nom, int _age){
	nom = _nom;
	age = _age;
}

alumno::alumno(string _nom,int _age,string _num,float _nota) : persona(_nom,_age){
	num = _num;
	nota = _nota;
}

void persona::mostrar(){
	cout<<"Nombre: "<<nom<<endl;
	cout<<"Edad: "<<age<<endl;
}

void alumno::mostraralumno(){
	mostrar();
	cout<<"Numero del alumno: "<<num<<endl;
	cout<<"Nota final del alumno: "<<nota<<endl;
}

int main(int argc, char **argv){
	alumno a("samuel",20,17,10);

	a.mostraralumno();

	return 0;
}