#include<stdio.h>
#include<string.h>

int main(){
	char cadena1[50], cadena2[50];
	int longitud1, longitud2, x, y, aux1, aux2;
	
	printf("Ingrese una cadena: ");
	fgets(cadena1, sizeof(cadena1), stdin);
	
	printf("\nIngrese otra cadena: ");
	fgets(cadena2, sizeof(cadena2), stdin);
	
	longitud1=strlen(cadena1);
	longitud2=strlen(cadena2);
	
	if(longitud1!=longitud2){
		printf("\nLas cadenas ingresadas no son anagramas");
	}else{
	
	for(x=0;x<longitud1; x++){
    	aux1=0;
		for(y=0;y<longitud1-1;y++){		
			if(cadena1[y]<=cadena1[y+1]){			
				aux1=cadena1[y];
				cadena1[y]=cadena1[y+1];
				cadena1[y+1]=aux1;
			}
		}						
	}
	
	for(x=0;x<longitud2; x++){
    	aux2=0;
		for(y=0;y<longitud2-1;y++){		
			if(cadena2[y]<=cadena2[y+1]){			
				aux2=cadena2[y];
				cadena2[y]=cadena2[y+1];
				cadena2[y+1]=aux2;
			}
		}						
	}
	
	if(strcmp(cadena1,cadena2)==0){
		printf("\nLas cadenas ingresadas son anagramas");
	}else{
		printf("\nLas cadenas ingresadas no son anagramas");
	}
}
}
