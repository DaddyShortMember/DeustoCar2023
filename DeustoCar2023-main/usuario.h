#include "sqlite3.h"

#ifndef USUARIO_H_
#define USUARIO_H_

typedef struct{
	int id;
	char nombre[30];
	char email[30];
	char contrasenya[30];
	int saldo;
}Usuario; //100 Bytes, malloc necesario para arrays

//Menus extras
void usmodscr(void); //Opciones para modificar aspectos del usuario [nombre,email,contrasenya,saldo, y permisos de admin. local]

//Funciones
Usuario getUser(sqlite3 *db, int result);
void anyadirUsuario(sqlite3 *db, int result, Usuario usuario);
void grantAdmin(sqlite3 *db, int result, FILE *f, Usuario usuario);
void modificarUsuario(sqlite3 *db, int result, Usuario usuario);
void eliminarUsuario(sqlite3 *db, int result);

//Funciones Visuales
Usuario creaUsuario(char nombre[30],char email[30],char contrasenya[30],int saldo);
//Perfectas para malloc??:
void visualizarUsuarios(sqlite3 *db, int result); //Muestra en pantalla de 10 en 10, array de Usuuarios??
void imprimirUsuarios(sqlite3 *db, int result); //Exporta todos los usuarios existentes en un .txt, array de Usuarios?

#endif /* USUARIO_H_ */
