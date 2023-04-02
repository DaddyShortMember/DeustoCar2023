#include "admin.h"
#include "coche.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10
#define MAX_LINE 10

Coche crearAutomovil(){

	Coche *c = (Coche*) malloc(sizeof(Coche));

	//Hay que sacar de la BD los coches y recorrerlos para poner el id
	//int id;

	printf("Introduce la marca del coche");
	fflush(stdout);
	char *linea[MAX_LINE];
	fgets(linea, MAX_LINE, stdin);
	//sscanf(linea, "%i", &id);
	clearIfNeeded(linea, MAX_LINE);
	//char* marca;
	printf("Introduce el modelo del coche");
	//char* modelo;

	c = {};

	return c;
};
Coche modificarAutomovil(){

};
void visualizarAutomovil(){

};
void eliminarAutomovil(){

};
void crearUsuario(){

};
Usuario modificarUsuario(){

};
void visualizarUsuario(){

};
void eliminarUsuario(){

};

int main(void)
{

	FILE* f;
        char c;

	int num_lines = 0;

	//abrir fichero para lectura
	f = fopen("prueba.txt", "r");

	//leer mientras no se llegue al final del fichero EOF
	while ((c = fgetc(f)) != EOF)
	{
		if (c == '\n')
			num_lines++;
		putchar(c);
	}
	//cerrar fichero
	fclose(f);

	printf("El fichero tiene %i líneas\n", num_lines);

	return 0;
}
