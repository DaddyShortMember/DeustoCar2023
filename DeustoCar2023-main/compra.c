#include "compra.h"

int prccrtscr(sqlite3 *db){
	//Menu de creacion de Compra
	sqlite3_stmt *stmt;
	char* buffer = malloc(sizeof(char)*2);
	char* idB = malloc(sizeof(char)*10);
	char* query = malloc(sizeof(char)*128);
	char* query2 = malloc(sizeof(char)*128);
	char* query3 = malloc(sizeof(char)*128);
	int result;
	int qIdUC;
	int qIdUV;
	int qIdV;
	int qIdC;
	int qPre;
	int res = 0;
	Compra qCom;
	int flg = 0;
	int flg2 = 0;
	int flg3 = 0;
	while(flg < 1){ //ID de venta
	fflush(stdin);
	system("CLS");
	printf("[Creacion de Compra]\n\nIntroduzca un ID de Venta valido\n\n"); //Obtiene una qIdV y pilla datos de la venta existente; si existe ya la venta en la tabla de compras, no se crea la compra
	fgets(idB,10,stdin);
	sscanf(idB, "%d",&qIdV);
	sprintf(query2, "SELECT * FROM compra where idVenta = %d", qIdV);
	result = sqlite3_step(stmt);
	if(qIdV < 1 || existsVenta(db,qIdV) || result == SQLITE_ROW){ 
		fflush(stdin);
		printf("ID de venta Invalido, repetido, o no existente;\nPor favor, introduzca un ID de venta valido\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
		getch();
	}
	else{
		fflush(stdin);
		flg++;
	}
	}
	while(flg2 < 1){ //ID de Usuario Comprador
	fflush(stdin);
	system("CLS");
	printf("[Creacion de Compra]\n\nIntroduzca un ID de comprador (usuario) valido\n\n");
	fgets(idB,10,stdin);
	sscanf(idB, "%d",&qIdUC);
	if(qIdUC < 1 || exists2(db, qIdC) == 0 ){
		fflush(stdin);
		printf("ID de Usuario Invalido, o no existente;\nPor favor, introduzca un ID de usuario valido\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
		getch();
	}
	else{
		fflush(stdin);
		flg2++;
	}
	}
	while(flg3 < 1){//ID Coche
	fflush(stdin);
	system("CLS");
	printf("[Creacion de Compra]\n\nIntroduzca un ID de coche valido\n\n");
	fgets(idB,10,stdin);
	sscanf(idB, "%d",&qIdC);
	sprintf(query, "SELECT idCoche FROM compra where idCoche = %d", qIdC);
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	result = sqlite3_step(stmt);
	if(qIdC < 1 || existsCoche(db, qIdC) == 0 || result == SQLITE_ROW){ 
		fflush(stdin);
		printf("ID de Coche Invalido o no existente;\nPor favor, introduzca una ID de coche valido\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
		getch();
	}else{
		fflush(stdin);
		flg3++;
		flg--;
	}
	}
	sprintf(query2, "SELECT * FROM venta where id = %d", qIdV); //Obtencion de datos de venta
	result = sqlite3_step(stmt);
	qIdUV = sqlite3_column_int(stmt, 4);
	qPre = sqlite3_column_int(stmt, 1);
	qCom = creaCompra(db, qIdUC, qIdUV, qIdC, qIdV, qPre); //(sqlite3 *db, int idUC, int idUV, int idC, int idV, int precio)
	anyadirCompra(db,qCom);
	printf("[Creacion de Compra]\n\nFuncion Finalizada\nPulse cualquier tecla para continuar\n");
	getch();
	while(flg == 0){
		system("CLS");
		printf("Quiere anyadir otra Compra? (1/0)\n");
		fgets(buffer,2,stdin);
		sscanf(buffer, "%d", &res);
		if(res == 1 || res == 0)
			flg++;
		else{
			printf("[Creacion de Compra]\n\nFuncion Finalizada\nPulse cualquier tecla para continuar\n");
			getch();
		}
	}
	free(idB);
	free(buffer);
	sqlite3_finalize(stmt);
	free(query);
	free(query2);
	free(query3);
	return res;
}

//Funciones
Compra getCompra(sqlite3 *db, int id){
	sqlite3_stmt *stmt;
	Compra qCom;
	char* query = malloc(sizeof(char)*256);
	sprintf(query, "SELECT * FROM compra where id = %d", id);
	int result;
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	result = sqlite3_step(stmt);
	if (result == SQLITE_ROW) { //Si existe en la BD:
			qCom.id = sqlite3_column_int(stmt, 0); //ID Compra
			qCom.precio = sqlite3_column_int(stmt, 1); //Precio
			strcpy(qCom.fechaC,sqlite3_column_text(stmt, 2)); //Fecha Compra
			qCom.id = sqlite3_column_int(stmt, 3); //ID Venta
			qCom.idUC = sqlite3_column_int(stmt, 4); //ID Usuario Comprador
			qCom.idUV = sqlite3_column_int(stmt, 5); //ID Usuario Vendedor
			qCom.idC = sqlite3_column_int(stmt, 6); //ID Coche
		}else{
			system("CLS");
			qCom.id = 0;
			printf("Compra no existe.");
			getch();
		}
	sqlite3_finalize(stmt);
	free(query);
	return qCom;
}

Compra creaCompra(sqlite3 *db, int idUC, int idUV, int idC, int idV, int precio){
	Compra qCom;
	qCom.idUC = idUC;
	qCom.idC = idC;
	qCom.idUV = idUV;
	qCom.idV = idV;
	qCom.precio = precio;
	char* query2 = malloc(sizeof(char)*128);
	sprintf(query2, "SELECT date('now')");
	sqlite3_stmt *stmt;
	sqlite3_prepare_v2(db, query2, strlen(query2), &stmt, NULL);
	sqlite3_step(stmt);
	strcpy(qCom.fechaC,sqlite3_column_text(stmt, 0));
	free(query2);
	sqlite3_finalize(stmt);
	return qCom;
}

void anyadirCompra(sqlite3 *db,  Compra compra){
	char* query = malloc(sizeof(char)*256);
	char* query2 = malloc(sizeof(char)*128);
	char* qFec = malloc(sizeof(char)*13);
	int result;
	sprintf(query2, "SELECT date('now')");
	sqlite3_stmt *stmt;
	result = sqlite3_prepare_v2(db, query2, strlen(query2), &stmt, NULL);
	result = sqlite3_step(stmt);
	strcpy(qFec,sqlite3_column_text(stmt, 0));
	sprintf(query, "insert into Compra (id, precio, fechaCompra, idVenta, idComprador, idVendedor, idCoche) values (NULL,%d,'%s', %d, %d, %d, %d)", compra.precio, qFec, compra.idV, compra.idUC, compra.idUV, compra.idC);
	result = sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
	}
	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error al introducir Compra\n");
	}else{
		printf("Compra %d introducido\n", compra.id);
	}
	free(query);
	free(query2);
	free(qFec);
	sqlite3_finalize(stmt);
}

int existsCompra(sqlite3 *db, int id){
	int result;
	int ret;
	sqlite3_stmt *stmt;
	char* geid = "select id from Compra where id=?";
	sqlite3_prepare_v2(db, geid, strlen(geid), &stmt, NULL);
	sqlite3_bind_int(stmt, 1, id);
	result = sqlite3_step(stmt);
	if(result == SQLITE_ROW){
		ret = 1;
	}else{
		ret = 0;
	}
	sqlite3_finalize(stmt);
	return ret;
}


void modificarCCoche(sqlite3 *db, int id, int idC){
	char* query = "UPDATE Compra SET idCoche = ? WHERE id = ?";
	sqlite3_stmt *stmt;
	int result;
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	sqlite3_bind_int(stmt, 1, idC);
	sqlite3_bind_int(stmt, 2, id);
	result = sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void modificarCUsuarioV(sqlite3 *db, int id, int idU){
	char* query = "UPDATE Compra SET idVendedor = ? WHERE id = ?";
	sqlite3_stmt *stmt;
	int result;
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	sqlite3_bind_int(stmt, 1, idU);
	sqlite3_bind_int(stmt, 2, id);
	result = sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void modificarCUsuarioC(sqlite3 *db, int id, int idU){
	char* query = "UPDATE Compra SET idComprador = ? WHERE id = ?";
	sqlite3_stmt *stmt;
	int result;
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	sqlite3_bind_int(stmt, 1, idU);
	sqlite3_bind_int(stmt, 2, id);
	result = sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void modificarCPrecio(sqlite3 *db, int id, int precio){
	char* query = "UPDATE Compra SET precio = ? WHERE id = ?";
	sqlite3_stmt *stmt;
	int result;
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	sqlite3_bind_int(stmt, 1, precio);
	sqlite3_bind_int(stmt, 2, id);
	result = sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}
//Practicamente no existe, pero esta ahi por sea caso
void eliminarCompra(sqlite3 *db, int id){
	char* sql1 = "delete from Compra where id=?";
	int result;
	sqlite3_stmt *stmt;
	sqlite3_prepare_v2(db, sql1, strlen(sql1), &stmt, NULL);
	sqlite3_bind_int(stmt, 1, id);
	result = sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

//Funciones Visuales

//Perfectas para malloc??:
void visualizarCompras(sqlite3 *db){
	int numR; //Numero de filas. Truco: SELECT Count(*) FROM tblName
	int result;
	char* query = "SELECT MAX(id) FROM Compra";
	char* query2;
	//atrib. Compra
	char* qFec;
	int qIdUC;
	int qIdC;
	int qPre;
	int qId;
	sqlite3_stmt *stmt;
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	result = sqlite3_step(stmt);
	numR = sqlite3_column_int(stmt, 0); //Numero de Compras: perfecto
	system("CLS");
	printf("[LISTA DE COMPRAS]\n\n");
	for(int i = 0; i <= numR; i++){
		qFec = malloc(sizeof(char)*13);
		query2 = malloc(sizeof(char)*128);
		sprintf(query2, "SELECT * FROM Compra where id = %d", i);
		sqlite3_prepare_v2(db, query2, strlen(query2), &stmt, NULL);
		result = sqlite3_step(stmt);
		if(result == SQLITE_ROW){
			qId = sqlite3_column_int(stmt, 0);
			qIdUC = sqlite3_column_int(stmt, 4);
			qIdC = sqlite3_column_int(stmt, 6);
			qPre = sqlite3_column_int(stmt, 1);
			strcpy(qFec,sqlite3_column_text(stmt, 2));
			printf("[ID] %d [ID Comprador] %d [ID Coche] %d [Precio] %d [Fecha] %s \n", qId, qIdUC, qIdC, qPre, qFec);
		}
		free(qFec);
		free(query2);
	}
	sqlite3_finalize(stmt);
	printf("\n\n[PRESIONAR CUALQUIER TECLA PARA CONTINUAR]");
	getch();
	
}
void imprimirCompras(sqlite3 *db){
	int numR; //Numero de filas. Truco: SELECT Count(*) FROM tblName
	FILE* f;
	f = fopen("Compras.export", "w");
	int result;
	char* query = "SELECT MAX(id) FROM Compra";
	char* query2;
	//atrib. Compra
	char* qFec;
	int qIdUC;
	int qIdUV;
	int qIdV;
	int qIdC;
	int qPre;
	int qId;
	sqlite3_stmt *stmt;
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	result = sqlite3_step(stmt);
	numR = sqlite3_column_int(stmt, 0); //Numero de Compras: perfecto
	system("CLS");
	printf("[IMPRIMIENDO COMPRAS]\n\n");
	for(int i = numR; i > 0; i--){
		qFec = malloc(sizeof(char)*13);
		query2 = malloc(sizeof(char)*128);
		sprintf(query2, "SELECT * FROM Compra where id = %d", i);
		sqlite3_prepare_v2(db, query2, strlen(query2), &stmt, NULL);
		result = sqlite3_step(stmt);
		if(result == SQLITE_ROW){
			qId = sqlite3_column_int(stmt, 0);
			qIdUC = sqlite3_column_int(stmt, 4);
			qIdUV = sqlite3_column_int(stmt, 5);
			qIdV = sqlite3_column_int(stmt, 3);
			qIdC = sqlite3_column_int(stmt, 6);
			qPre = sqlite3_column_int(stmt, 1);
			strcpy(qFec,sqlite3_column_text(stmt, 2));
			fprintf(f, "[ID] %d [ID Comprador] %d [ID Vendedor] %d [ID Venta] %d [ID Coche] %d [Precio] %d [Fecha] %s \n", qId, qIdUC, qIdUV, qIdV, qIdC, qPre, qFec);
		}
		free(qFec);
		free(query2);
	}
	fclose(f);
	sqlite3_finalize(stmt);
	printf("\n\n[CompraS IMPRESAS, PULSE CUALQUIER TECLA PARA CONTINUAR]");
	getch();
}