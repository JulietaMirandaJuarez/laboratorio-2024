#include <stdio.h>

int suma;
float promedio;
int arr[]={1, 2, 3, 4, 5};
void calcularSumaPromedio(int *arr, int n, int *suma, float *promedio);

int main(){
	int n=sizeof(arr)/sizeof(arr[0]);
	calcularSumaPromedio(arr, n, &suma, &promedio);
	printf("La suma es: %d\n", suma);
	printf("El promedio es: %.2f", promedio);
	
	return 0;
}


void calcularSumaPromedio(int *arr, int n, int *suma, float *promedio){
	int i;
	*suma=0;
	for(i=0;i<n;i++){
		*suma+=*(arr+i);
	}
	*promedio= (float)*suma/n;
	
}
