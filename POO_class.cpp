//POO O' programamcion Orientada a Objetos
#include"iostream"
#include"stdlib.h"
using namespace std;

/*los atributos son las caracteristicas del objeto por ejemplo
perro: sus atributos son:
su raza 
color de pelo
y sus anios de vida

los metodos son las acciones por ejemplo
perro: sus metodos son:
comer
dormir
jugar*/

class persona{
	private://atributos
		int edad;
		string name;
	public://metodos
		persona(int,string);//constructor
		void read();
		void run();
};

persona::persona(int age, string nom){//nos sirve para inicializar los atributos
	edad = age;
	name = nom;
}

void persona::read(){
	cout<<"soy "<<name<<" y stoy leyendo 1 libro"<<endl;
}

void persona::run(){
	cout<<"soy "<<name<<" y stoy corriendo para entrenar y tengo "<<edad<<" anios"<<endl;
}

int main(int argc, char **argv){
	persona p = persona(20,"Mel");
	persona p1(19,"samuel");

	p.read();
	p1.read();
	p1.run();

	return 0;
}