#include "usuario.h"
#include "sqlite3.h"
#include <stdio.h>
#include <stdlib.h>

void usmodscr(void){
	
} //Opciones para modificar aspectos del usuario [nombre,email,contrasenya,saldo, y permisos de admin. local]

//Funciones
Usuario getUser(sqlite3 *db, int result){
	
}
void anyadirUsuario(sqlite3 *db, int result, Usuario usuario){
	
}
void grantAdmin(sqlite3 *db, int result, FILE *f, Usuario usuario){
	
}
void modificarUsuario(sqlite3 *db, int result, Usuario usuario){
	
}
void eliminarUsuario(sqlite3 *db, int result){
	
}

//Funciones Visuales
Usuario creaUsuario(char nombre[30],char email[30],char contrasenya[30],int saldo){
	
}
//Perfectas para malloc??:
void visualizarUsuarios(sqlite3 *db, int result){
	
}
void imprimirUsuarios(sqlite3 *db, int result){
	
}