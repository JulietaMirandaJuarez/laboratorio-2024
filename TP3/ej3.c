#include<stdio.h>

int arr[]={10,20,30,40,50};
int size=sizeof(arr)/sizeof(int);
int max, min;
void max_min(int *arr, int size, int *max, int *min);

int main(){
	max_min(arr, size, &max, &min);
	printf("El maximo es %d y el minimo es %d", max, min);
}

void max_min(int *arr, int size, int *max, int *min){
	int i;
	*max=*min=*arr;
	for(i=1;i<size;i++){
		if(*(arr+i)>*max){
			*max=*(arr+i);
		}
		if(*(arr+i)<*min){
			*min=*(arr+i);
		}
	}
}

