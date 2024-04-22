#include <stdio.h>

int main(){
	 int num, esPrimo, i;
	 
	 printf("  Ingrese un numero: ");
	 scanf("%d", &num);
	 
	for ( i = 2; i <= num; i++) {
            if (num % i == 0) {
                esPrimo = 0; // Si el número es divisible por algún número menor o igual que su raíz cuadrada, no es primo
                break; // Salir del bucle, ya que ya no es necesario seguir verificando
            }
        }
    if(esPrimo) {
        printf("\n  Es un numero primo.\n");
    }
	else {
        printf("\n  No es un numero primo.\n");
    }
}
