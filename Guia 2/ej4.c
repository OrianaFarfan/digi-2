#include<stdio.h>

int main()
{
	int x = 1, y = 2; //Se inicializan los valores de x e y. 
	int *ptr; //Indico el que el valor de ptr representa una direccion de memoria
	
	printf("Valor de X: %d\n", x); //Imprimo el valor de X

	ptr = &x; //El puntero toma el valor de la direccion de X
	printf("Direccion del valor de X dado por le puntero: %d\n", ptr); //Imprimo el valor del puntero que contiene la información de la direccion de memoria de X
	
	y = *ptr; //Y toma el valor apuntado por el puntero, en este caso Y toma el valor de X
	*ptr = 0; //Le doy un nuevo valor a la direccion apuntada por el puntero, este sigue apuntando a la misma direccion pero su valor ahora es de 0
	printf("Valor de Y: %d\n", y); //Imprimo el valor de Y
	ptr = &y; //El puntero toma el valor de la direccion de Y
	printf("Direccion del valor de Y dado por le puntero: %d\n", ptr); //Imprimo el valor del puntero que contiene la información de la direccion de memoria de Y
	
	return 0;
}