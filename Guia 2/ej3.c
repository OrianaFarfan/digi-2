#include<stdio.h>


int suma(int valor1, int valor2){
	int res;
	res = valor1 + valor2;
return res;
}

int main()
{
	int valor1, valor2, res;
	
	printf("Introducir el primer entero: ");
	scanf("%d", &valor1);
	printf("\nIntroduce el segundo entero: ");
	scanf("%d", &valor2);
	res = suma(valor1, valor2);
	printf("\nResultado de la suma: %d", res);
	
	return 0;
}