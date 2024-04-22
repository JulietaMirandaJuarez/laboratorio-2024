#include <stdio.h>

int x=5, y=10;
void intercambio(int *a, int *b);

int main(){
	printf("Antes del intercambio: x=%d, y=%d\n", x, y);
	intercambio(&x, &y);
	printf("Despues del intercambio: x=%d, y=%d\n", x, y);
	return 0;
}

void intercambio(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
