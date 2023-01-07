#include<stdio.h>

void swap(int *a, int *b){
	int temp;
	temp = *a; //Valor temporal toma el valor de apuntado por el puntero a (x)
	*a = *b; //El valor apuntado por a toma el valor apuntado por b(y)
	*b = temp; //El valor apuntado por b ahora es el valor temporal (x)
	return;
}


int main(){
	int x = 1, y = 2;
	printf("Valores originales:\tx = %d, y = %d\n", x, y);
	swap(&x, &y);
	printf("Valores nuevos:\t\tx = %d, y = %d\n", x, y);
	
	return 0;
}