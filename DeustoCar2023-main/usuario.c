#include "usuario.h"
#include "sqlite3.h"
#include <stdio.h>
#include <stdlib.h>

void anyadirUsuario(sqlite3 *db, int result, Usuario usuario) {
	result = insertUsuario(db, usuario.nombre, usuario.email, usuario.contrasenya, usuario.saldo);
	if (result != SQLITE_OK) {
		printf("Error inserting new data\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
};

void modificarUsuario(sqlite3 *db, int result, Usuario usuario, char codigo[50]) {
	result = deleteUsuario(db, codigo);
	if (result != SQLITE_OK) {
		printf("Error deleting Usuario\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	result = insertUsuario(db, usuario.nombre, usuario.email, usuario.contrasenya, usuario.saldo);
	if (result != SQLITE_OK) {
		printf("Error inserting new data\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
};

void eliminarUsuario(sqlite3 *db, int result, char codigo[50]) {
	result = deleteUsuario(db, codigo);
	if (result != SQLITE_OK) {
		printf("Error deleting Usuario\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
};

void eliminarUsuarios(sqlite3 *db, int result) {
	result = deleteAllUsuarios(db);
	if (result != SQLITE_OK) {
		printf("Error deleting all users\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
};

void imprimirUsuario(sqlite3 *db, int result, Usuario u)
{
	//La contrasenya no se imprime
	printf("\nID DE USUARIO: %i \n", u.id);
	printf("EMAIL: %s \n", u.email);
	printf("NOMBRE: %s \n", u.nombre);
	printf("SALDO: %i \n \n", u.saldo);
};
