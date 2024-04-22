#include<stdio.h>

int main(){
	int cantNum, vecNum[cantNum], x, y, i, opcion, aux, auxpar=0, auximpar=0, auxprimo=0;
	int cantPrimos=0, cantImpares=0, cantPares=0, primos[cantPrimos], impares[cantImpares], pares[cantPares];
	
	printf("Ingrese la dimension de su vector: ");
	scanf("%d", &cantNum);
	
	for(x=0;x<cantNum;x++){
		opcion=0;
		aux=0;
		printf("Ingrese la posicion %d: ", x);
		scanf("%d", &vecNum[x]);
		
		if(vecNum[x]%2==0){
	    	opcion=1;
		}
		else
		{
			opcion=2;
		}
		
		for(y=1;y<=vecNum[x];y++){
	 	    if(vecNum[x]%y==0){
	 	    	aux=aux+1;
			 }
	    }
	    
	    if(aux==2){
	    	opcion=3;
		}
	
	switch(opcion){
		case 1:
			cantPares= cantPares+1;
			pares[cantPares-1]=vecNum[x];
			break;
		case 2:
			cantImpares= cantImpares+1;
			impares[cantImpares-1]=vecNum[x];
			break;
		case 3:
			cantPrimos= cantPrimos+1;
			primos[cantPrimos-1]=vecNum[x];
			break;
	}	
    }
    

    
    for(x=0;x<cantPares; x++){
    	auxpar=0;
 	
		for(y=0;y<cantPares-1;y++){		
			if(pares[y]>=pares[y+1]){			
				auxpar=pares[y];
				pares[y]=pares[y+1];
				pares[y+1]=auxpar;
			}
		}						
	}
	printf("\nNumeros pares ordenados de menor a mayor: ");
	
	for(i=0;i<cantPares;i++){
		printf("%d  ", pares[i]);
	}
	
	
	
	for(x=0;x<cantPrimos; x++){
    	auxprimo=0;
 	
		for(y=0;y<cantPrimos-1;y++){		
			if(primos[y]>=primos[y+1]){			
				auxprimo=primos[y];
				primos[y]=pares[y+1];
				primos[y+1]=auxprimo;
			}
		}						
	}
	printf("\nNumeros primos ordenados de menor a mayor: ");
	
	for(i=0;i<cantPrimos;i++){
		printf("%d  ", primos[i]);
}



for(x=0;x<cantImpares; x++){
    	auximpar=0;
 	
		for(y=0;y<cantImpares-1;y++){		
			if(impares[y]<=impares[y+1]){			
				auximpar=impares[y];
				impares[y]=impares[y+1];
				impares[y+1]=auximpar;
			}
		}						
	}
	printf("\nNumeros impares ordenados de mayor a menor: ");
	
	for(i=0;i<cantImpares;i++){
		printf("%d  ", impares[i]);
}
		

	
}
