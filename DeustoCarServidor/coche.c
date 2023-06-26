#include "coche.h"
#include "BD.h"
#include "sqlite3.h"
#include <stdio.h>

void anyadirCoche(sqlite3 *db, int result, Coche coche){
	result = insertCoche(db, coche.marca, coche.modelo);
	if (result != SQLITE_OK) {
		printf("Error inserting new data\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
};

void modificarCoche(sqlite3 *db, int result, Coche coche, char codigo[50]){
	result = deleteCoche(db, codigo);
	if (result != SQLITE_OK) {
		printf("Error deleting Coche\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	result = insertCoche(db, coche.marca, coche.modelo);
	if (result != SQLITE_OK) {
		printf("Error inserting new data\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
};

void eliminarCoche(sqlite3 *db, int result, char codigo[50]){
	result = deleteCoche(db, codigo);
	if (result != SQLITE_OK) {
		printf("Error deleting Coche\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
};

void eliminarCoches(sqlite3 *db, int result){
	result = deleteAllCoches(db);
	if (result != SQLITE_OK) {
		printf("Error deleting all cars\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
};

void imprimirCoche(Coche coche){
	char marca[30] = {};
	char modelo[30] = {};

	for (int i = 0; i < 30; ++i) {
		marca[i] = coche.marca[i];
	}

	for (int i = 0; i < 30; ++i) {
		modelo[i] = coche.modelo[i];
	}

	printf("\nID DEL COCHE: %i \n", coche.id);
	printf("MARCA DEL COCHE: %s \n", coche.marca);
	printf("MODELO DEL COCHE: %s \n", coche.modelo);
};
