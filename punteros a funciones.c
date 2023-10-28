

#include<stdio.h>
void hola1(int (*pf)(int, &a,int, &b,int, &c));
int hola(void);
int main() {
	
	hola1(hola);
	
}

int hola(void) {
	int a, b, c;
	
	printf("intro a: ");
	scanf("%d",&a);
	printf("intro b: ");
	scanf("%d",&b);
	printf("intro c: ");
	scanf("%d",&c);
	
	
	
	printf("%d %d %d",a,b,c);
}

void hola1(int (*pf)(int &a, int &b, int &c)) {
	int e, s=15;
	
	e =(pf) (a,b,c) - s;
	printf("\n%d",e);
}


