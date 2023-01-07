#include<stdio.h>


int main(void){
	int a = 0x12345678; //Declaro el entero a con un nnumero hexadecimal
	short int b = 0xABCD; //Declaro el entero b como un short hexadecimal
	char c = 'a'; //Declaro la variable c como char, y este toma el valor de a
	int * ptr_a = &a; //El puntero ptr_a apunta al valor de a
	short int * ptr_b = &b; //El puntero ptr_b apunta al valor de b
	char * ptr_c = &c; //El puntero p´tr_c apunta al valor de c
	printf("\nValor de ptr_a:\t\t %p\n", ptr_a); //Muestra la direccion que apunta el puntero ptr_a, esto es la direccion de a
	printf("Valor de ptr_a + 1:\t %p\n", ++ptr_a); //Muestra la siguiente direccion del puntero ptr_a, como es un int, avanza 4 bits
	printf("\nValor de ptr_b:\t\t %p\n", ptr_b); //Muestra la direccion que apunta el puntero ptr_b, esto es la direccion de b
	printf("Valor de ptr_b + 1:\t %p\n", ++ptr_b); //Muestra la siguiente direccion del puntero ptr_b, como es un short, avanza 2 bits
	printf("\nValor de ptr_c:\t\t %p\n", ptr_c);//Muestra la direccion que apunta el puntero ptr_c, esto es la direccion de c
	printf("Valor de ptr_c + 1:\t %p\n", ++ptr_c);//Muestra la siguiente direccion del puntero ptr_c, como es un char, avanza 1 bit
}