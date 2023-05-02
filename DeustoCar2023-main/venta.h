#ifndef VENTA_H_
#define VENTA_H_

typedef struct{
	int id;
	int idU; //idUsuario
	int idC; //idCoche
	float precio;
	char fechaV[13]; //formato: 'aaaa-mm-dd' + \0
}Venta; //32 Bytes, Malloc necesario para arrays

void anyadirVenta(sqlite3 *db, int result, Venta venta);
void modificarVenta(sqlite3 *db, int result, Venta venta);
void eliminarVenta(sqlite3 *db, int result);
void imprimirVenta(Venta venta);

#endif /* VENTA_H_ */