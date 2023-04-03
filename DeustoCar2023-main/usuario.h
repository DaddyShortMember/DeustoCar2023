#include "sqlite3.h"

#ifndef USUARIO_H_
#define USUARIO_H_

typedef struct{
	int id;
	char nombre[30];
	char email[30];
	char contrasenya[30];
	int saldo;
}Usuario;

void anyadirUsuario(sqlite3 *db, int result, Usuario usuario);
void modificarUsuario(sqlite3 *db, int result, Usuario usuario, char codigo[50]);
void eliminarUsuario(sqlite3 *db, int result, char codigo[50]);
void eliminarUsuarios(sqlite3 *db, int result);
void imprimirUsuario(sqlite3 *db, int result, Usuario usuario);

#endif /* USUARIO_H_ */
