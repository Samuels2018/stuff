//Metodos Constructores y Modificadores (Getters y Setters)
#include"iostream"
#include"stdlib.h"
using namespace std;

class punto{
	private:
		int x,y;
	public:
		punto();
		void setpunto(int,int);//setter
		int getpuntoX();//getter primero se pone d q tipo son los valores q se van a mostrar o pantalla
		int getpuntoY();//pero solo se pueden mostrar ls valores 1x1 ya que se usa return
};

punto::punto(){

}

//setters: ns sirve para establecer o dar valores a nuestros atributs
void punto::setpunto(int _x, int _y){
	x = _x;
	y = _y;
}

int punto::getpuntoX(){
	return x;
}

int punto::getpuntoY(){
	return y;
}
/*no se puede igualar variabes q sten dentro de la clase en el main ni tampoco imprimirlas 
ya q solo se pueden mandar a llamar o dar stos valores si estan definidos en la clase o
alguna funcion desde la clase*/
int main(int argc, char **argv){
	punto p;

	//pero aun nose como introducir elementos or teclado ya q d sta forma no me deja
	p.setpunto(10,50);
	cout<<p.getpuntoX()<<endl;
	cout<<p.getpuntoY()<<endl;

	return 0;
}