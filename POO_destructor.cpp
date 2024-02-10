//destructor
#include"iostream"
#include"stdlib.h"
using namespace std;

class perro{
	private:
		string nom, raz;
	public:
		perro(string,string);
		~perro();//destructor
		void jugar();
		void mostrar();
};

perro::perro(string _nom, string _raz){
	nom = _nom;
	raz = _raz;
}

perro::~perro(){//destructor
}

void perro::mostrar(){
	cout<<"Nombre: "<<nom<<endl;
	cout<<"Raza: "<<raz<<endl;
}

void perro::jugar(){
	cout<<"El perro "<<nom<<" sta jugando"<<endl;
}

int main(int argc, char **argv){
	perro p("Ambar","puddunt");

	p.mostrar();
	p.jugar();

	return 0;
}