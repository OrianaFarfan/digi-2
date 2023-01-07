#include<stdio.h>
#include <stddef.h>

struct pru_struct {
char id1;
char id2;
char id3[10];
char *nombre;
char *domicilio;
int edad;
int varios;
};

void showinfo(struct pru_struct *empleados){
	printf("Id1:\t\t%c\n", empleados->id1);
	printf("Id2:\t\t%c\n", empleados->id2);
	printf("Id3:\t\t%s\n", empleados->id3);
	printf("Nombre:\t\t%s\n", empleados->nombre);
	printf("Direccion\t%s\n", empleados->domicilio);
	printf("Edad\t\t%d\n", empleados->edad);
	printf("Varios\t\t%d\n\n", empleados->varios);
	printf("Direccion de la estructura:\t\t0x%p\n\n", empleados);
	printf("Direccion del miembro Id1:\t\t0x%p\n", &empleados->id1);
	printf("Direccion del miembro Id2:\t\t0x%p\n", &empleados->id2);
	printf("Direccion del miembro Id3:\t\t0x%p\n", &empleados->id3);
	printf("Direccion del miembro nombre:\t\t0x%p\n", &empleados->nombre);
	printf("Direccion del miembro domicilio:\t0x%p\n", &empleados->domicilio);
	printf("Direccion del miembro edad:\t\t0x%p\n", &empleados->edad);
	printf("Direccion del miembro varios:\t\t0x%p\n", &empleados->varios);
	printf("Offset de Id1: %d bytes\n", offsetof(struct pru_struct, id1));
	printf("Offset de Id2: %d bytes\n", offsetof(struct pru_struct, id2));
	printf("Offset de Id3: %d bytes\n", offsetof(struct pru_struct, id3));
	printf("Offset de nombre: %d bytes\n", offsetof(struct pru_struct, nombre));
	printf("Offset de domicilio: %d bytes\n", offsetof(struct pru_struct, domicilio));
	printf("Offset de edad: %d bytes\n", offsetof(struct pru_struct, edad));
	printf("Offset de varios: %d bytes\n", offsetof(struct pru_struct, varios));
	
	return;
}

int main(){
	int i;
	int tmp;
	struct pru_struct empleados ={
		'B',
		'C',
		"Sensible",
		"Pedro",
		"Av. Carlos Calvo 1234",
		23,
		68,
	};
	showinfo(&empleados);
	return 0;
};