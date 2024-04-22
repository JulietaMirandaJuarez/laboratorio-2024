#include<stdio.h>
#include<string.h>

int main(){
	char cadena[20];
	int longitud, x, palindromo=1;
	
	printf("Ingrese una cadena de caracteres: ");
	fflush(stdin);
	gets(cadena);
	fflush(stdin);
	
	longitud=strlen(cadena);
	
	for(x=0;x<longitud;x++){
		if(cadena[x]!=cadena[longitud-1-x]){
			palindromo=0;
		}
	}
	
	if(palindromo!=0){
		printf("Su cadena ES palindromo");
	}
	else{
		printf("Su cadena NO es palindromo");
	}
}
