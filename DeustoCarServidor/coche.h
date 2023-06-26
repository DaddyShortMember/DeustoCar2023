#include"sqlite3.h"

#ifndef COCHE_H_
#define COCHE_H_

typedef struct{
	int id;
	char marca[30];
	char modelo[30];
}Coche; //64Bytes, malloc necesario para arrays

void anyadirCoche(sqlite3 *db, int result, Coche coche);
void modificarCoche(sqlite3 *db, int result, Coche coche, char codigo[50]);
void eliminarCoche(sqlite3 *db, int result, char codigo[50]);
void imprimirCoche(Coche coche);
int insertCoche(sqlite3 *db, char marca[], char modelo[]);

#endif /* COCHE_H_ */
