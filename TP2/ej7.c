#include <stdio.h>
#include <string.h>

int main(){
	char final[50], cadena1[50], cadena2[50], cadena3[50], cadena4[50], cadena5[50];
	int x, longitud;
	
	printf("Ingrese la primer cadena: ");
	fgets(cadena1, sizeof(cadena1), stdin);
	
	printf("\nIngrese la segunda cadena: ");
	fgets(cadena2, sizeof(cadena2), stdin);
	
	printf("\nIngrese la tercera cadena: ");
	fgets(cadena3, sizeof(cadena3), stdin);
		
	printf("\nIngrese la cuarta cadena: ");
	fgets(cadena4, sizeof(cadena4), stdin);
	
	printf("\nIngrese la quinta cadena: ");
	fgets(cadena5, sizeof(cadena5), stdin);
	
	longitud=strlen(cadena1);
	
	for(x=0;x<longitud;x++){
		if(cadena1[x]==cadena2[x] && cadena1[x]==cadena3[x] && cadena1[x]==cadena4[x] && cadena1[x]==cadena5[x]){
			final[x]=cadena1[x];
		}
	}
	printf("\n\narEn las 5 cadenas coincide lo siguiente: %s", final);
}
