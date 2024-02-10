//
#include"iostream"
using namespace std;

int main(int argc, char **argv) {
	int n=0, n1, min = 999, m = 0, ii=0;
	char ask;
	
	do{
		cout<<"introduce 1 numero < a 10: ";cin>>n;
		n1+= n;
		if(n > m){m = n;}
		if(n < min) {min = n;}
		ii++;
	}while(ii < 10);
	
	cout<<endl<<n1<<endl;
	cout<<"el mayor es: "<<m<<endl;
	cout<<"el menor es: "<<min;
	
	return 0;
}

