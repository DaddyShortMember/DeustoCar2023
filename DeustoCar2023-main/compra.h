#ifndef COMPRA_H_
#define COMPRA_H_

typedef struct{
	int id;
	int idUC; //idUsuarioComprador
	int idUV; //idUsuarioVendedor
	int idC; //idCoche
	int idV; //idVenta
	float precio;
	char fechaC[13]; //formato: 'aaaa-mm-dd' + \0
}Compra; //40 Bytes, Malloc necesario para arrays


void anyadirCompra(sqlite3 *db, int result, Compra compra);
void modificarCompra(sqlite3 *db, int result, Compra compra);
void eliminarCompra(sqlite3 *db, int result);
void imprimirCompra(Compra compra);


#endif /* COMPRA_H_ */
