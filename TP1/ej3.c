#include <stdio.h>
#include <math.h>

int main(){
	
	float cateto1, cateto2, hipotenusa;
	
	
	printf("Ingrese el valor del cateto 1: ");
	scanf("%f", &cateto1);
	
	printf("\nIngrese el valor del cateto 2: ");
	scanf("%f", &cateto2);
	
	hipotenusa= sqrt(cateto1 * cateto1 + cateto2 * cateto2);
	
	printf("\nLa longitud de la hipotenusa es: %f", hipotenusa);
	
	
}
