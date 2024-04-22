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
	
	
    if(anio>2008 || (anio==2008 && mes>9) || (anio==2008 && mes==9 && dia>=30)){
    	printf("\n Usted no puede votar");
	}else{
		printf("\n Usted puede votar");
	}
}
	
