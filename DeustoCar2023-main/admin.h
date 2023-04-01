#include"coche.h"
#include"usuario.h"

#ifndef ADMIN_H_
#define ADMIN_H_

typedef struct{
	int idAdmin;
	char *nombre;
	char *contrasenya;
}Admin;

void crearAutomóvil();
Coche modificarAutomóvil();
void visualizarAutomóvil();
void eliminarAutomóvil();
void crearUsuario();
Usuario modificarUsuario();
void visualizarUsuario();
void eliminarUsuario();

#endif /* ADMIN_H_ */
