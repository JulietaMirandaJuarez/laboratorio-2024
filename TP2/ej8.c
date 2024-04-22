#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char oracion[30];
	int x, longitud, opcion, contLetra, decision;
	
	printf("\n\tIngrese una oracion: ");
	fgets(oracion, sizeof(oracion), stdin);
	
	do{
			
	printf("\n\n\tOPCIONES:");
	printf("\n\t _________________________________________________________________");
	printf("\n\t|1) Mostrar la oracion toda en mayuscula                          |");
	printf("\n\t|2) Mostrar la oracion toda en minuscula                          |");
	printf("\n\t|3) Mostrar la oracion alternando una mayuscula y una minuscula   |");
	printf("\n\t|4) Mostrar la oracion comenzando todas las palabras con mayuscula|");
	printf("\n\t|_________________________________________________________________|");

	printf("\n\n\tElija la opcion que desea realizar: ");
	scanf("%d", &opcion);
	
	longitud=strlen(oracion);
	
	switch(opcion){
		case 1:
			for(x=0;x<longitud;x++){
				if(oracion[x]>='a' && oracion[x]<='z'){
					oracion[x]=oracion[x]-32;		
				}
			}
			break;
			
		case 2: 
		    for(x=0;x<longitud;x++){
				if(oracion[x]>='A' && oracion[x]<='Z'){
					oracion[x]=oracion[x]+32;		
				}
			}
			break;
		
		case 3:
			for(x=0;x<longitud;x++){
				if((oracion[x]>='a' && oracion[x]<='z') || (oracion[x]>='A' && oracion[x]<='Z')){
					contLetra++;
				}
				
				if(contLetra%2==0){
					if(oracion[x]>='a' && oracion[x]<='z'){
					oracion[x]=oracion[x]-32;		
				    }	
				}
				else
				{
					if(oracion[x]>='A' && oracion[x]<='Z'){
					oracion[x]=oracion[x]+32;	
				    }	
				}
			}
			break;
			
		case 4:
		     for (x = 0; x < longitud; x++) {
                if (x == 0 || oracion[x - 1] == ' ') {
                    if (oracion[x] >= 'a' && oracion[x] <= 'z') {
                        oracion[x] = oracion[x] - 32;
                    }
                } else {
                    if (oracion[x] >= 'A' && oracion[x] <= 'Z'){
                        oracion[x] = oracion[x] + 32;
                    }
                }
            }
            break;
	}
	
	printf("\n\tSu oracion quedaria asi: %s", oracion);
	
	printf("\n\tQuiere volver a utilizar el programa?\n\t1- Si\n\t2- No");
	scanf("%d", &decision);
	
  }while(decision==1);
}
