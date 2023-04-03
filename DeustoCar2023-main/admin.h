#include"coche.h"
#include"usuario.h"

#ifndef ADMIN_H_
#define ADMIN_H_

typedef struct{
	char contrasenya[30];
}Admin;

Coche crearAutomovil();
Coche modificarAutomovil();
void visualizarAutomovil();
void eliminarAutomovil();
Usuario crearUsuario();
Usuario modificarUsuario();
void visualizarUsuario();
void eliminarUsuario();

#endif /* ADMIN_H_ */
