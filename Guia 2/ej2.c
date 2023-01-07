#include<stdio.h>

int main()
{
	int vec[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for(int i=0; i<10; i++)
	{
		printf("Valor del vector por posicion posicion: %d\n", vec[i]);
	}
	printf("Tamano del vector:%d", sizeof(vec));
	
	return 0;
}