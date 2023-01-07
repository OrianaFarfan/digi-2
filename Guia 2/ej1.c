#include<stdio.h>

int main()
{
	char c;
	short s;
	int i;
	long l;
	float f;
	double d;
	
	printf("Tamano del char: %d\n", sizeof(c)); //Tamaño en bytes
	printf("Tamano del short: %d\n", sizeof(s));
	printf("Tamano del int: %d\n", sizeof(i));
	printf("Tamano del long: %d\n", sizeof(l));
	printf("Tamano del float: %d\n", sizeof(f));
	printf("Tamano del double: %d\n", sizeof(d));	
	return 0;
}
