//archivos en c++
#include"iostream"
#include"fstream"
#include"stdlib.h"
using namespace std;

void write() {
	fstream f;//f e de file por eso es fstream
	f.open("prueba.txt",ios::out);
	if(f.fail()) {	//out se usa para agregar informacion al archivo y si ya tiene informacion la reemplaza por otra
       cout<<"el archivo no se pudo abrir \n\a";exit(-1);
	}
	
	f<<"archivos en C++";
	f.close();
	
	return;
}

void read() {
	ifstream f;//la i es de in por eso es ifstream
	string text;
	
	f.open("prueba.txt",ios::in); //con el in abrimos el archivo
	if(f.fail()) {cout<<"nose pudo abrir el archivo"<<endl;exit(-1);}
	
	while(getline(f,text) !=NULL) {
		cout<<text<<endl;
	}
	f.close();
	
	return;
}

void add() {
	ofstream f;//o e para aniadir texto al final del archivo por eso es ofstream
	string a;
	
	f.open("prueba.txt",ios::app);//abrimos el archivo en modo de aniadir al final
	if(f.fail()) {cout<<"el archivo nose pudo abrir"<<endl;exit(-1);}
	cout<<"introduce 1 texto: ";cin>>a;
	
	f<<"qlq mano todo bien?";
	f<<a;
	f.close();
	
	return;
}

int main(int argc, char **argv) {
	
	write();
	read();
	add();
	
	return 0;
}
