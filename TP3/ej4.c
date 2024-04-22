#include <stdio.h>

int arr1[]={10,20,30,40,50};
int size=sizeof(arr1)/sizeof(int);
int arr2[5];
int i;
void copiarArreglo(int *arr1, int *arr2, int size);

int main(){
	copiarArreglo(arr1,arr2,size);
	printf("El segundo arreglo es: ");
	for(i=0;i<size;i++){
		printf("%d ", arr2[i]);
	}
}

void copiarArreglo(int *arr1, int *arr2, int size){
	int i;
	for(i=0;i<size;i++){
		*(arr2+i)=*(arr1+i);
	}
}
