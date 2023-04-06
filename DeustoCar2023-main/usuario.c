#include "usuario.h"
#include "sqlite3.h"
#include <stdio.h>
#include <stdlib.h>
/*
void anyadirUsuario(sqlite3 *db, int result, Usuario usuario){

};

void modificarUsuario(sqlite3 *db, int result, Usuario usuario, char codigo[50]){

};

void eliminarUsuario(sqlite3 *db, int result, char codigo[50]){

};

void eliminarUsuarios(sqlite3 *db, int result){

};

void imprimirUsuario(sqlite3 *db, int result, Usuario usuario){

};
*/



// Función auxiliar para convertir un Usuario a una cadena de caracteres
char* usuarioToString(Usuario usuario){
    char* str = malloc(sizeof(char)*200);
    sprintf(str, "ID: %d\nNombre: %s\nEmail: %s\nContraseña: %s\nSaldo: %d\n",
        usuario.id, usuario.nombre, usuario.email, usuario.contrasenya, usuario.saldo);
    return str;
}

// Añadir un usuario a la base de datos
void anyadirUsuario(sqlite3 *db, int result, Usuario usuario){
    char* sql = malloc(sizeof(char)*200);
    sprintf(sql, "INSERT INTO usuarios (id, nombre, email, contrasenya, saldo) VALUES (%d, '%s', '%s', '%s', %d)",
        usuario.id, usuario.nombre, usuario.email, usuario.contrasenya, usuario.saldo);
    result = sqlite3_exec(db, sql, 0, 0, 0);
    if (result != SQLITE_OK){
        printf("Error al añadir usuario: %s\n", sqlite3_errmsg(db));
    }
    free(sql);
}

// Modificar un usuario en la base de datos
void modificarUsuario(sqlite3 *db, int result, Usuario usuario, char codigo[50]){
    char* sql = malloc(sizeof(char)*200);
    sprintf(sql, "UPDATE usuarios SET id=%d, nombre='%s', email='%s', contrasenya='%s', saldo=%d WHERE codigo='%s'",
        usuario.id, usuario.nombre, usuario.email, usuario.contrasenya, usuario.saldo, codigo);
    result = sqlite3_exec(db, sql, 0, 0, 0);
    if (result != SQLITE_OK){
        printf("Error al modificar usuario: %s\n", sqlite3_errmsg(db));
    }
    free(sql);
}

// Eliminar un usuario de la base de datos
void eliminarUsuario(sqlite3 *db, int result, char codigo[50]){
    char* sql = malloc(sizeof(char)*200);
    sprintf(sql, "DELETE FROM usuarios WHERE codigo='%s'", codigo);
    result = sqlite3_exec(db, sql, 0, 0, 0);
    if (result != SQLITE_OK){
        printf("Error al eliminar usuario: %s\n", sqlite3_errmsg(db));
    }
    free(sql);
}

// Eliminar todos los usuarios de la base de datos
void eliminarUsuarios(sqlite3 *db, int result){
    char* sql = "DELETE FROM usuarios";
    result = sqlite3_exec(db, sql, 0, 0, 0);
    if (result != SQLITE_OK){
        printf("Error al eliminar usuarios: %s\n", sqlite3_errmsg(db));
    }
}

// Imprimir la información de un usuario
void imprimirUsuario(sqlite3 *db, int result, Usuario usuario){
    printf("%s", usuarioToString(usuario));
}

