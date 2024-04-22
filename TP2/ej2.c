#include<stdio.h>
#include<string.h>

int main(){
	char cadena[20];
	int longitud=0, x, contVocal=0;
	
	printf("Ingrese una cadena de carecteres: ");
	fgets(cadena, sizeof(cadena), stdin);
	
	longitud=strlen(cadena);
	
	for(x=0;x<longitud;x++){
		if(cadena[x]=='a' || cadena[x]=='A' || cadena[x]=='e' || cadena[x]=='E' || cadena[x]=='i' || cadena[x]=='I' || cadena[x]=='o' || cadena[x]=='O' || cadena[x]=='u' || cadena[x]=='U'){
			contVocal++;
		}
	}
	
	printf("La cantidad de vocales es: %d", contVocal);
}
