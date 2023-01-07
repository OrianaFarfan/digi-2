#include<stdio.h>
#define MAX 20

int strlen(char *s){
	int n;
	for (n=0; *s != '\0'; s++)
	{
		n++;
	}
	return n;
}

int lenght(char *s){
	int n;
	char *ptr;	//Creo un puntero char
	ptr = s;	//El puntero apunta a la palabra
	while(*ptr != '\0')		//Quiero que cuente hasta que llegue al final
	{
		ptr++;				//Avanzo a traves de la palabra
	}
	n = ptr-s;	//Resto la posicion en el que se encuentra el final de caracter copn el inicio de caracter
	return n;	//Devuelvo el numero de veces que sumo el contador
}




int main(){
	char palabra[MAX];	//Palabra de maximo 20 caracteres
	int nro, tam;		//Declaro dos enteros
	
	printf("Inserte una palabra: ");
	scanf("%s", palabra);	//Escaneo la palabra
	nro = strlen(palabra);
	printf("El largo de la cadena es: %d\n", nro);
	
	tam = lenght(palabra);
	printf("El largo de la cadena es: %d", tam);
	return 0;
}