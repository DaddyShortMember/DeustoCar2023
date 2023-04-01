#include"coche.h"
#include"usuario.h"

#ifndef ADMIN_H_
#define ADMIN_H_

typedef struct{
	int idAdmin;
	char *nombre;
	char *contrasenya;
}Admin;

void crearAutom�vil();
Coche modificarAutom�vil();
void visualizarAutom�vil();
void eliminarAutom�vil();
void crearUsuario();
Usuario modificarUsuario();
void visualizarUsuario();
void eliminarUsuario();

#endif /* ADMIN_H_ */
