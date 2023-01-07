#include<stdio.h>

int main(){
	int x[5]={0, 1, 2, 3, 4}; //Lamo un vector de 5 espacios
	int *ptr; //Creo un puntero ptr
	
	ptr = &x[0]; //El puntero apunta al primer numero del vector x
	
	printf("Valor apuntado por el puntero: %d \n", *ptr); //Imprimo el valor apuntado por el puntero
	
	for (int i=0; i<5; i++)
	{
			ptr = &x[i]; //El puntero apunta a la direccion i del vector
			printf("Valor del vector apuntado por el vector: %d\n", *ptr); //Imprimo el valor apuntado por el vector
			printf("Direccion de memoria apuntado por el puntero: %d\n", ptr); //Imprimo el valor de la direccion apuntada por el vector, al correr el programa va avanzando de a 4 posiciones
	}
	
	char c[5]={0, 1, 2, 3, 4};
	char *ptr_c;
	
		for (int i=0; i<5; i++)
		{
			ptr_c = &c[i]; //El puntero apunta a la direccion i del vector
			printf("Valor del vector apuntado por el vector: %d\n", *ptr_c); //Imprimo el valor apuntado por el vector
			printf("Direccion de memoria apuntado por el puntero: %d\n", ptr_c); //Imprimo el valor de la direccion apuntada por el vector, al correr el programa va avanzando de a 1 posicion
		}
	
	return 0;
}