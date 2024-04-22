#include <stdio.h>


int main(){
	int dia, mes, anio, dni, edad=0;
	char nombre[20], apellido[20];
	
	printf("Ingrese su nombre: ");
	scanf("%s", &nombre);
	
	printf("\nIngrese su apellido: ");
	scanf("%s", &apellido);
	
	printf("\nIngrese su dia de nacimiento: ");
	scanf("%d", &dia);
	
	printf("\nIngrese el numero de su mes de nacimiento: ");
	scanf("%d", &mes);
	
	printf("\nIngrese su anio de nacimiento: ");
	scanf("%d", &anio);
	
	printf("\nIngrese su dni: ");
	scanf("%d", &dni);
	
	edad= 2024 - anio;
	
    if(anio>=2008){
		if(mes>9 || (mes==9 && dia>=30)){
			edad=edad-1;
		}
		if(edad<16){
		printf("\nSu edad es %d.", edad);
		printf("\nNo puede votar");
	    }else{
	    	printf("\nSu edad es %d.", edad);
		    printf("\nPuede votar");
		}
	}
	
    if(anio<2008){
		
		if(mes>=9){
			edad=edad-1;
		}
		if(edad==16 || edad<18){
		printf("\nSu edad es %d.", edad);
		printf("\nPuede votar");
	    }
	    if(edad>18 && edad<80){
		printf("\nSu edad es %d.", edad);
		printf("\nDebe votar");
	    }
	    if(edad>=80){
		printf("\nSu edad es %d.", edad);
		printf("\nPuede votar");
	    }
	}	
	
}
