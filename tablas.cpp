//
#include"iostream"
using namespace std;

int main(int argc, char **argv) {
	
	cout<<"\tLas Tablas de Multiplicar"<<endl<<endl;
	
	for(int ii=1; ii<=12; ii++) {
		for(int jj=1;jj<=12;jj++) {
			cout<<ii<<"*"<<jj<<"="<<ii*jj<<endl;
		}
		cout<<endl;
	}
	
	return 0;
}
