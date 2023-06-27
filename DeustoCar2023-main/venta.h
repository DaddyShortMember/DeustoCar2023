#include "sqlite3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coche.h"
#include "usuario.h"
#include "logger.h"

#ifndef VENTA_H_
#define VENTA_H_

typedef struct{
	int id;
	int idU; //idUsuario
	int idC; //idCoche
	int precio;
	char fechaV[13]; //formato: 'aaaa-mm-dd' + \0
}Venta; //32 Bytes, Malloc necesario para arrays

//Menus extras
int slmodscr(sqlite3 *db); //Opciones para modificar aspectos del venta
int slscrtscr(sqlite3 *db); //Menu de creacion de venta
int slsdltscr(sqlite3 *db); //Para borrar venta

//Funciones
Venta getVenta(sqlite3 *db, int id);
Venta creaVenta(sqlite3 *db, int idU, int idC, int precio);
void anyadirVenta(sqlite3 *db, Venta venta);

int existsVenta(sqlite3 *db, int id);
void modificarVCoche(sqlite3 *db, int idV, int idC);
void modificarVUsuario(sqlite3 *db, int idV, int idU);
void modificarVPrecio(sqlite3 *db, int idV, int precio);
void eliminarVenta(sqlite3 *db, int idV);

//Funciones Visuales
//Perfectas para malloc??:
void visualizarVentas(sqlite3 *db); //Muestra en pantalla todos los ventas, array de Usuuarios??
void imprimirVentas(sqlite3 *db); //Exporta todos los ventas existentes en un .txt, array de ventas?

#endif /* VENTA_H_ */