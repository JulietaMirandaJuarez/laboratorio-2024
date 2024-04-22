#include <stdio.h>

int contar_ocurrencias(int *arr, int size, int elemento, int *contador) {
    int i;
    
    *contador = 0;
    
    for (i = 0; i < size; i++) {
        if (*(arr + i) == elemento) { 
            (*contador)++;
        }
    }
}

int main() {
    int arreglo[] = {2, 3, 6, 6, 5, 2, 6, 2, 6, 6};
    int elemento, x, contador; 
    int size = sizeof(arreglo) / sizeof(arreglo[0]);
    
    printf("El arreglo es:\n");
    for(x=0;x<size;x++){
    	printf("%d  ", arreglo[x]);
	}
	
	printf("\nIngrese el elemento a contar: ");
	scanf("%d", &elemento);

    contar_ocurrencias(arreglo, size, elemento, &contador);

    printf("\n\nEl elemento %d aparece %d veces en el arreglo.\n", elemento, contador);

    return 0;
}

