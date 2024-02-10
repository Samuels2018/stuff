//hice sto para saber si todas las librerias y funcions de C se pueden usar en C++
//y si se puede hacer pq me compilo sin erros y me dio el resultado correcto
#include"iostream"
using namespace std;

int main(int argc, char **argv) {
	char a[10];
	cout<<"introduce 1 palabra"<<endl;scanf("%[^\n]",a);cout<<a;
	return 0;
}
