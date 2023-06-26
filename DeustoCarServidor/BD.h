#include <stdio.h>
#include "sqlite3.h"
#include "usuario.h"
#include "coche.h"
#include "admin.h"


#ifndef BD_H_
#define BD_H_

int insertUsuario(sqlite3 *db, char nombre[], char email[], char contrasenya[], int saldo);
int insertCoche(sqlite3 *db, char marca[], char modelo[]);
int insertAdmin(sqlite3 *db, char nombre[], char contrasenya[]);
Usuario getUsuario(sqlite3 *db, char codigo[50]);
Coche getCoche(sqlite3 *db, char codigo[50]);
void imprimirUsuarios(sqlite3 *db);
int imprimirCoches(sqlite3 *db);
int deleteUsuario(sqlite3 *db, char codigo[50]);
int deleteCoche(sqlite3 *db, char codigo[50]);
int deleteAllUsuarios(sqlite3 *db);
int deleteAllCoches(sqlite3 *db);
//int isAdmin(sqlite3 *db, Admin admin);

#endif /* BD_H_ */

