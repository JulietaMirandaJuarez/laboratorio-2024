#include <stdio.h>

int main(){
	int cantNum, x, vec[cantNum], esPrimo=0, noPrimo=0;
	
	printf("Ingrese la cantidad de numeros a informar: ");
	scanf("%d", &cantNum);
	
	for(x=0; x<cantNum; x++){
		printf("Ingrese el numero %d:", x+1);
		scanf("%d", &vec[x]);
		
		if(vec[x]%2!=0 || vec[x]==2){
	 	esPrimo++;
	 }
	 else{
	 	noPrimo++;
	 }
	}
	
	printf("\nLa cantidad de numeros ingresadas es %d", cantNum);
	printf("\nLa cantidad de numeros que son primos es %d", esPrimo);
	printf("\nLa cantidad de numeros que no son primos es %d", noPrimo);
}
