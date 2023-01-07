#include <stdio.h>
int main(void){
	char a;
	int b = 0x12345678;
	short int c;
	printf("\n\nDireccion asignada para la variable a:\t %p\n", &a);
	printf("\nDireccion asignada para la variable b:\t %p\n", &b);
	printf("\nDireccion asignada para la variable c:\t %p\n", &c);
	
	return 0;
}