#include<stdio.h>
#include<string.h>

int main(){
	char cadena[50], reemplazar[1], nuevo[1];
	int longitud, x;
	
	printf("Ingrese una cadena de caracteres: ");
	fgets(cadena, sizeof(cadena), stdin);
	
	printf("\nIngrese el caracter a reemplazar: ");
	scanf(" %c", &reemplazar);
	
	printf("\nIngrese el caracter nuevo: ");
	scanf(" %c", &nuevo);
	
	longitud=strlen(cadena);
	
	for(x=0;x<longitud;x++){
		if(cadena[x]==reemplazar[0]){
			cadena[x]=nuevo[0];
		}
	}
	
	printf("\nCadena final: %s", cadena);
	
	
}
