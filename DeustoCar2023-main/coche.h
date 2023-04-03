#include"sqlite3.h"

#ifndef COCHE_H_
#define COCHE_H_

typedef struct{
	int id;
	char marca[30];
	char modelo[30];
}Coche;

void anyadirCoche(sqlite3 *db, int result, Coche coche);
void modificarCoche(sqlite3 *db, int result, Coche coche, char codigo[50]);
void eliminarCoche(sqlite3 *db, int result, char codigo[50]);
void eliminarCoches(sqlite3 *db, int result);
void imprimirCoche(Coche coche);

#endif /* COCHE_H_ */
