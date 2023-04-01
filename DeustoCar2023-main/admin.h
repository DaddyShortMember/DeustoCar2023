#include"coche.h"
#include"usuario.h"

#ifndef ADMIN_H_
#define ADMIN_H_

typedef struct{
	int idAdmin;
	char *nombre;
	char *contrasenya;
}Admin;

void crearAutomovil();
Coche modificarAutomovil();
void visualizarAutomovil();
void eliminarAutomovil();
void crearUsuario();
Usuario modificarUsuario();
void visualizarUsuario();
void eliminarUsuario();

#endif /* ADMIN_H_ */
