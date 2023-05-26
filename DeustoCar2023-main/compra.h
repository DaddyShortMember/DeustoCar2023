#include "sqlite3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coche.h"
#include "usuario.h"
#include "venta.h"

#ifndef COMPRA_H_
#define COMPRA_H_

typedef struct{
	int id;
	int idUC; //idUsuarioComprador
	int idUV; //idUsuarioVendedor
	int idC; //idCoche
	int idV; //idVenta
	int precio;
	char fechaC[13]; //formato: 'aaaa-mm-dd' + \0
}Compra; //40 Bytes, Malloc necesario para arrays

//Menus extras
int prccrtscr(sqlite3 *db); //Menu de creacion de compra

//Funciones
Compra getCompra(sqlite3 *db, int id);
Compra creaCompra(sqlite3 *db, int idUC, int idUV, int idC, int idV, int precio);
void anyadirCompra(sqlite3 *db, Compra compra);

int existsCompra(sqlite3 *db, int id);
void modificarCCoche(sqlite3 *db, int id, int idC);
void modificarCUsuarioC(sqlite3 *db, int id, int idU);
void modificarCUsuarioV(sqlite3 *db, int id, int idU);
void modificarCPrecio(sqlite3 *db, int id, int precio);
void eliminarCompra(sqlite3 *db, int id);

//Funciones Visuales
//Perfectas para malloc??:
void visualizarCompras(sqlite3 *db); //Muestra en pantalla todos los ventas, array de Usuuarios??
void imprimirCompras(sqlite3 *db); //Exporta todos los ventas existentes en un .txt, array de ventas?


#endif /* COMPRA_H_ */