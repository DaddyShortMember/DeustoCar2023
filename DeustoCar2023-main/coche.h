#include "sqlite3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logger.h"

#ifndef COCHE_H_
#define COCHE_H_

typedef struct{
	int id;
	char marca[30];
	char modelo[30];
}Coche; //64Bytes, malloc necesario para arrays

//Menus extras
int vhmodscr(sqlite3 *db); //Opciones para modificar aspectos del coche [marca, modelo]
int vhccrtscr(sqlite3 *db); //Menu de creacion de coche
int vhcdltscr(sqlite3 *db); //Para borrar coche

//Funciones
Coche getCoche(sqlite3 *db, int id);
Coche creaCoche(int id,char marca[30],char modelo[30]);
void anyadirCoche(sqlite3 *db, Coche coche);
int existsCoche(sqlite3 *db, int id);
void modificarMarca(sqlite3 *db, int id, char* marca);
void modificarModelo(sqlite3 *db, int id, char* modelo);
void eliminarCoche(sqlite3 *db, int id); //NO SE ELIMINAN COCHES EN VENTA/COMPRADOS.

//Funciones Visuales
//Perfectas para malloc??:
void visualizarCoches(sqlite3 *db); //Muestra en pantalla todos los usuarios, array de Usuuarios??
void imprimirCoches(sqlite3 *db); //Exporta todos los usuarios existentes en un .txt, array de Usuarios?

#endif /* COCHE_H_ */
