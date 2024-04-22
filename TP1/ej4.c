#include <stdio.h>
#include <math.h>

int main(){
	
	float lado1, lado2, hipotenusa, cateto1, cateto2;
	
	
	printf("Ingrese el lado 1:");
	scanf("%f", &lado1);
	
	printf("\nIngrese el lado 2:");
	scanf("%f", &lado2);
	
	if(lado1>lado2){
		hipotenusa= lado1;
		cateto1= lado2;
		cateto2= sqrt(lado1 * lado1 - lado2 * lado2);
	}
	else{
		hipotenusa= lado2;
		cateto1= lado1;
		cateto2= sqrt(lado2 * lado2 - lado1 * lado1);
	}
	
	printf("\nEl valor del cateto 1 es %f y el del cateto 2 es %f. La longitud de la hipotenusa es: %f", cateto1, cateto2, hipotenusa);
	
	
}
