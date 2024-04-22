#include<stdio.h>

char cad[20];
char cad2[20];
char cad3[20];
void concatenar(char *cad,char *cad2,char *cad3){
	int dim1 = strlen(cad);
	int dim2 = strlen(cad2);
	int x,y;
	for(x=0;x<dim1;x++){
		*(cad3+x)=*(cad+x);
	}
	for(y=0;y<dim2;y++){
		*(cad3+x+y)=*(cad2+y);
	}
}


int main(){
	printf("Ingrese su primera cadena: ");
	scanf("%s", &cad);
	printf("\nIngrese su segunda cadena: ");
	scanf("%s", &cad2);

	concatenar(cad,cad2,cad3);
	printf("\nCadena final: %s",cad3);
}

