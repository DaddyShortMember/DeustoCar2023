#include "venta.h"

int slmodscr(sqlite3 *db){
	//Opciones para modificar aspectos de la venta: precio
	int res = 0;
	int flg = 0;
	char* buffer = malloc(sizeof(char)*2);
	char* idB = malloc(sizeof(int)*10);
	int qIdC; //Id coche
	int qPre;
	int qId; //Id Venta
	int choice;
	while(flg < 1){
		fflush(stdin);
		system("CLS");
		printf("[Modificacion de Venta]\n\nIntroduzca un numero identificador valido\n\n");
		fgets(idB,10,stdin);
		sscanf(idB, "%d",&qId);
		if(qId < 1 || existsVenta(db, qId) == 0){
			fflush(stdin);
			printf("Numero identificador Invalido o no existente;\nPor favor, introduzca un numero identificador valido\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
			getch();
		}else{
		fflush(stdin);
		flg++;
		}
	}
	flg--;
	while(flg == 0){
	fflush(stdin);
	system("CLS");
	printf("[MODIFICAR ATRIBUTO DE VENTA]\n");
	printf("[1] Coche en venta\n"); 
	printf("[2] Precio\n");
	printf("[0] Volver\n");
	printf("Introduzca su seleccion:\n");
	fgets(buffer,2,stdin);
	sscanf(buffer, "%d", &choice);
	switch(choice){
		case 0: flg++;
				break;
		case 1: //Mod. Coche en venta
				while(flg < 1){
					fflush(stdin);
					system("CLS");
					printf("[Modificacion de venta]\n\nIntroduzca un ID de coche valido\n\n");
					fgets(idB,10,stdin);
					sscanf(idB, "%d",&qIdC);
					if(qIdC < 1 || existsCoche(db,qIdC)){ 
						fflush(stdin);
						printf("ID de coche Invalido;\nPor favor, introduzca un ID de coche valido\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
						getch();
					}else{
						fflush(stdin);
						flg++;
					}
				}
				modificarVCoche(db, qId, qIdC);
				break;
		case 2: //Mod. precio
				while(flg < 1){
					fflush(stdin);
					system("CLS");
					printf("[Modificacion de venta]\n\nIntroduzca un precio valido\n\n");
					fgets(idB,10,stdin);
					sscanf(idB, "%d",&qPre);
					if(qPre < 0){ 
						fflush(stdin);
						printf("Precio Invalido;\nPor favor, introduzca un precio valido\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
						getch();
					}
					else{
						fflush(stdin);
						flg++;
					}
				}
				modificarVPrecio(db, qId,qPre);
				break;
		default: 
				system("CLS");
				printf("Opcion Invalida;\nPor favor, introduzca un numero que aparezca en el menu\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
				getch();
				break;
		}
	}
	flg--;
	while(flg == 0){
		system("CLS");
		printf("Quiere modificar otra venta? (1/0)\n");
		fgets(buffer,2,stdin);
		sscanf(buffer, "%d", &res);
		if(res == 1 || res == 0)
			flg++;
		else{
			printf("[Modificacion de Venta]\n\nFuncion Finalizada\nPulse cualquier tecla para continuar\n");
			getch();
		}
	}
	free(idB);
	free(buffer);
	return res;
} 
int slscrtscr(sqlite3 *db){
	//Menu de creacion de venta
	sqlite3_stmt *stmt;
	char* buffer = malloc(sizeof(char)*2);
	char* idB = malloc(sizeof(char)*10);
	char* query = malloc(sizeof(char)*128);
	int result;
	int qIdU;
	int qIdC;
	int qPre;
	int res = 0;
	Venta qVen;
	int flg = 0;
	int flg2 = 0;
	int flg3 = 0;
	while(flg < 1){
	fflush(stdin);
	system("CLS");
	printf("[Creacion de Venta]\n\nIntroduzca un precio valido\n\n");
	fgets(idB,10,stdin);
	sscanf(idB, "%d",&qPre);
	if(qPre < 1){ 
		fflush(stdin);
		printf("Precio Invalido;\nPor favor, introduzca un precio valido\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
		getch();
	}
	else{
		fflush(stdin);
		flg++;
	}
	}
	while(flg2 < 1){
	fflush(stdin);
	system("CLS");
	printf("[Creacion de Venta]\n\nIntroduzca un ID de coche valido\n\n");
	fgets(idB,10,stdin);
	sscanf(idB, "%d",&qIdC);
	sprintf(query, "SELECT * FROM venta where idCoche = %d", qIdC);
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	result = sqlite3_step(stmt);
	logAppendDB(db, query, result);
	if(qIdC < 1 || existsCoche(db, qIdC) == 0 || result == SQLITE_ROW){
		fflush(stdin);
		printf("ID de coche Invalido, repetido, o no existente;\nPor favor, introduzca un ID de coche valido\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
		getch();
	}
	else{
		fflush(stdin);
		flg2++;
	}
	}
	while(flg3 < 1){
	fflush(stdin);
	system("CLS");
	printf("[Creacion de Venta]\n\nIntroduzca un ID de usuario valido\n\n");
	fgets(idB,10,stdin);
	sscanf(idB, "%d",&qIdU);
	if(qIdU < 1 || exists2(db, qIdU) == 0){ 
		fflush(stdin);
		printf("ID de Usuario Invalido o no existente;\nPor favor, introduzca una ID de usuario valido\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
		getch();
	}else{
		fflush(stdin);
		flg3++;
		flg--;
	}
	}
	qVen = creaVenta(db, qIdU, qIdC, qPre);
	anyadirVenta(db,qVen);
	printf("[Creacion de Venta]\n\nFuncion Finalizada\nPulse cualquier tecla para continuar\n");
	getch();
	while(flg == 0){
		system("CLS");
		printf("Quiere anyadir otra venta? (1/0)\n");
		fgets(buffer,2,stdin);
		sscanf(buffer, "%d", &res);
		if(res == 1 || res == 0)
			flg++;
		else{
			printf("[Creacion de venta]\n\nFuncion Finalizada\nPulse cualquier tecla para continuar\n");
			getch();
		}
	}
	free(idB);
	free(buffer);
	sqlite3_finalize(stmt);
	free(query);
	return res;
}

int slsdltscr(sqlite3 *db){
	int res = 0;
	int flg = 0;
	char* buffer = malloc(sizeof(char)*2);
	int qId;
	char* qBuf = malloc(sizeof(char)*10);
	while(flg < 1){
		fflush(stdin);
		system("CLS");
		printf("[Modificacion de venta]\n\nIntroduzca un ID valido\n\n");
		fgets(qBuf,30,stdin);
		sscanf(qBuf, "%d",&qId);
		if(qId < 1 || existsVenta(db, qId) == 0){
			fflush(stdin);
			printf("ID Invalido o no existente;\nPor favor, introduzca un ID valido\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
			getch();
		}
		else{
		fflush(stdin);
		flg++;
		eliminarVenta(db, qId);
		}
	}
	flg--;
	while(flg == 0){
		system("CLS");
		printf("Quiere eliminar otra venta? (1/0)\n");
		fgets(buffer,2,stdin);
		sscanf(buffer, "%d", &res);
		if(res == 1 || res == 0)
			flg++;
		else{
			printf("[Creacion de venta]\n\nFuncion Finalizada\nPulse cualquier tecla para continuar\n");
			getch();
		}
	}
	free(buffer);
	free(qBuf);
	return res;
	}

//Funciones
Venta getVenta(sqlite3 *db, int id){
	sqlite3_stmt *stmt;
	Venta qVen;
	char* query = malloc(sizeof(char)*256);
	sprintf(query, "SELECT * FROM venta where id = %d", id);
	int result;
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	result = sqlite3_step(stmt);
	if (result == SQLITE_ROW) { //Si existe en la BD:
			qVen.id = sqlite3_column_int(stmt, 0);
			qVen.idU = sqlite3_column_int(stmt, 4);
			qVen.idC = sqlite3_column_int(stmt, 3);
			qVen.precio = sqlite3_column_int(stmt, 1);
			strcpy(qVen.fechaV,sqlite3_column_text(stmt, 2));
		}else{
			system("CLS");
			qVen.id = 0;
			printf("Venta no existe.");
			getch();
		}
	sqlite3_finalize(stmt);
	free(query);
	return qVen;
}

Venta creaVenta(sqlite3* db, int idU, int idC, int precio){
	Venta qVent;
	qVent.idU = idU;
	qVent.idC = idC;
	qVent.precio = precio;
	char* query2 = malloc(sizeof(char)*128);
	sprintf(query2, "SELECT date('now')");
	sqlite3_stmt *stmt;
	sqlite3_prepare_v2(db, query2, strlen(query2), &stmt, NULL);
	sqlite3_step(stmt);
	strcpy(qVent.fechaV,sqlite3_column_text(stmt, 0));
	free(query2);
	sqlite3_finalize(stmt);
	return qVent;
}

void anyadirVenta(sqlite3 *db,  Venta venta){
	char* query = malloc(sizeof(char)*256);
	char* query2 = malloc(sizeof(char)*128);
	char* qFec = malloc(sizeof(char)*13);
	int result;
	sprintf(query2, "SELECT date('now')");
	sqlite3_stmt *stmt;
	result = sqlite3_prepare_v2(db, query2, strlen(query2), &stmt, NULL);
	result = sqlite3_step(stmt);
	logAppendDB(db, query, result);
	strcpy(qFec,sqlite3_column_text(stmt, 0));
	sprintf(query, "insert into venta (id, precio, fechaVenta, idCoche, idVendedor) values (NULL,%d,'%s',%d,%d)", venta.precio, qFec, venta.idC, venta.idU);
	result = sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	logAppendDB(db, query, result);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
	}
	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error al introducir venta\n");
	}else{
		printf("venta %d introducido\n", venta.id);
	}
	free(query);
	free(query2);
	free(qFec);
	sqlite3_finalize(stmt);
}

int existsVenta(sqlite3 *db, int id){
	int result;
	int ret;
	sqlite3_stmt *stmt;
	char* geid = "select id from venta where id=?";
	sqlite3_prepare_v2(db, geid, strlen(geid), &stmt, NULL);
	sqlite3_bind_int(stmt, 1, id);
	result = sqlite3_step(stmt);
	if(result == SQLITE_ROW){
		ret = 1;
	}else{
		ret = 0;
	}
	logAppendDB(db, geid, result);
	sqlite3_finalize(stmt);
	return ret;
}


void modificarVCoche(sqlite3 *db, int idV, int idC){
	char* query = "UPDATE venta SET idCoche = ? WHERE id = ?";
	sqlite3_stmt *stmt;
	int result;
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	sqlite3_bind_int(stmt, 1, idC);
	sqlite3_bind_int(stmt, 2, idV);
	result = sqlite3_step(stmt);
	logAppendDB(db, query, result);
	sqlite3_finalize(stmt);
}

void modificarVUsuario(sqlite3 *db, int idV, int idU){
	char* query = "UPDATE venta SET idVendedor = ? WHERE id = ?";
	sqlite3_stmt *stmt;
	int result;
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	sqlite3_bind_int(stmt, 1, idU);
	sqlite3_bind_int(stmt, 2, idV);
	result = sqlite3_step(stmt);
	logAppendDB(db, query, result);
	sqlite3_finalize(stmt);
}

void modificarVPrecio(sqlite3 *db, int idV, int precio){
	char* query = "UPDATE venta SET precio = ? WHERE id = ?";
	sqlite3_stmt *stmt;
	int result;
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	sqlite3_bind_int(stmt, 1, precio);
	sqlite3_bind_int(stmt, 2, idV);
	result = sqlite3_step(stmt);
	logAppendDB(db, query, result);
	sqlite3_finalize(stmt);
}

void eliminarVenta(sqlite3 *db, int idV){
	char* sql1 = "delete from venta where id=?";
	int result;
	sqlite3_stmt *stmt;
	sqlite3_prepare_v2(db, sql1, strlen(sql1), &stmt, NULL);
	sqlite3_bind_int(stmt, 1, idV);
	result = sqlite3_step(stmt);
	logAppendDB(db, sql1, result);
	sqlite3_finalize(stmt);
}

//Funciones Visuales

//Perfectas para malloc??:
void visualizarVentas(sqlite3 *db){
	int numR; //Numero de filas. Truco: SELECT Count(*) FROM tblName
	int result;
	char* query = "SELECT MAX(id) FROM venta";
	char* query2;
	//atrib. venta
	char* qFec;
	int qIdU;
	int qIdC;
	int qPre;
	int qId;
	sqlite3_stmt *stmt;
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	result = sqlite3_step(stmt);
	numR = sqlite3_column_int(stmt, 0); //Numero de ventas: perfecto
	system("CLS");
	printf("[LISTA DE VENTAS]\n\n");
	for(int i = 0; i <= numR; i++){
		qFec = malloc(sizeof(char)*13);
		query2 = malloc(sizeof(char)*128);
		sprintf(query2, "SELECT * FROM venta where id = %d", i);
		sqlite3_prepare_v2(db, query2, strlen(query2), &stmt, NULL);
		result = sqlite3_step(stmt);
		if(result == SQLITE_ROW){
			logAppendDB(db, query2, SQLITE_DONE);
			qId = sqlite3_column_int(stmt, 0);
			qIdU = sqlite3_column_int(stmt, 4);
			qIdC = sqlite3_column_int(stmt, 3);
			qPre = sqlite3_column_int(stmt, 1);
			strcpy(qFec,sqlite3_column_text(stmt, 2));
			printf("[ID] %d [ID Usuario] %d [ID Coche] %d [Precio] %d [Fecha] %s \n", qId, qIdU, qIdC, qPre, qFec);
		}
		free(qFec);
		free(query2);
	}
	sqlite3_finalize(stmt);
	printf("\n\n[PRESIONAR CUALQUIER TECLA PARA CONTINUAR]");
	getch();
	
}
void imprimirVentas(sqlite3 *db){
	int numR; //Numero de filas. Truco: SELECT Count(*) FROM tblName
	FILE* f;
	f = fopen("ventas.export", "w");
	int result;
	char* query = "SELECT MAX(id) FROM venta";
	char* query2;
	//atrib. venta
	char* qFec;
	int qIdU;
	int qIdC;
	int qPre;
	int qId;
	sqlite3_stmt *stmt;
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	result = sqlite3_step(stmt);
	numR = sqlite3_column_int(stmt, 0); //Numero de ventas: perfecto
	system("CLS");
	printf("[IMPRIMIENDO VENTAS]\n\n");
	for(int i = numR; i > 0; i--){
		qFec = malloc(sizeof(char)*13);
		query2 = malloc(sizeof(char)*128);
		sprintf(query2, "SELECT * FROM venta where id = %d", i);
		sqlite3_prepare_v2(db, query2, strlen(query2), &stmt, NULL);
		result = sqlite3_step(stmt);
		if(result == SQLITE_ROW){
			logAppendDB(db, query2, SQLITE_DONE);
			qId = sqlite3_column_int(stmt, 0);
			qIdU = sqlite3_column_int(stmt, 4);
			qIdC = sqlite3_column_int(stmt, 3);
			qPre = sqlite3_column_int(stmt, 1);
			strcpy(qFec,sqlite3_column_text(stmt, 2));
			fprintf(f, "[ID] %d [ID Usuario] %d [ID Coche] %d [Precio] %d [Fecha] %s \n", qId, qIdU, qIdC, qPre, qFec);
		}
		free(qFec);
		free(query2);
	}
	fclose(f);
	sqlite3_finalize(stmt);
	printf("\n\n[VENTAS IMPRESAS, PULSE CUALQUIER TECLA PARA CONTINUAR]");
	getch();
}