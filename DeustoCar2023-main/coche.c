#include"coche.h"

int vhmodscr(sqlite3 *db){
	//Opciones para modificar aspectos del coche
	int res = 0;
	int flg = 0;
	int qId;
	char* qVar = malloc(sizeof(char)*30);
	char* qBuf = malloc(sizeof(char)*30);
	char* buffer = malloc(sizeof(char)*3);
	char* idB = malloc(sizeof(int)*10);
	int qSal;
	int choice;
	while(flg < 1){
		fflush(stdin);
		system("CLS");
		printf("[Modificacion de Coche]\n\nIntroduzca un numero identificador valido\n\n");
		fgets(idB,10,stdin);
		sscanf(idB, "%d",&qId);
		if(qId < 1|| existsCoche(db, qId) == 0){
			fflush(stdin);
			printf("Numero identificador Invalido o no existente;\nPor favor, introduzca un numero identificador valido\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
			getch();
		}
		else{
		fflush(stdin);
		flg++;
		}
	}
	free(qBuf);
	qBuf = malloc(sizeof(char)*30);
	flg--;
	while(flg == 0){
	fflush(stdin);
	system("CLS");
	printf("[MODIFICAR ATRIBUTO DE COCHE]\n");
	printf("[1] Marca\n"); 
	printf("[2] Modelo\n"); 
	printf("[0] Volver\n");
	printf("Introduzca su seleccion:\n");
	fgets(buffer,3,stdin);
	sscanf(buffer, "%d", &choice);
	switch(choice){
		case 0: flg++;
				break;
		case 1: //Mod. Marca
				while(flg < 1){
					fflush(stdin);
					system("CLS");
					printf("[Modificacion de Coche]\n\nIntroduzca una marca valida\n\n");
					fgets(qBuf,30,stdin);
					sscanf(qBuf, "%s", qVar);
					if(strlen(qVar) > 30){ 
						fflush(stdin);
						printf("Marca Invalida;\nPor favor, introduzca una marca valida\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
						getch();
					}else{
						fflush(stdin);
						flg++;
					}
				}
				modificarMarca(db, qId, qVar);
				break;
		case 2: //Mod. Modelo
				while(flg < 1){
					fflush(stdin);
					system("CLS");
					printf("[Modificacion de Coche]\n\nIntroduzca un modelo valido\n\n");
					fgets(qBuf,30,stdin);
					sscanf(qBuf, "%s", qVar);
					if(strlen(qVar) > 30){ 
						fflush(stdin);
						printf("Modelo Invalido;\nPor favor, introduzca un modelo valido\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
						getch();
					}else{
						fflush(stdin);
						flg++;
					}
				}
				modificarModelo(db, qId, qVar);
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
		printf("Quiere modificar otro coche? (1/0)\n");
		fgets(buffer,2,stdin);
		sscanf(buffer, "%d", &res);
		if(res == 1 || res == 0)
			flg++;
		else{
			printf("[Modificacion de Coche]\n\nFuncion Finalizada\nPulse cualquier tecla para continuar\n");
			getch();
		}
	}
	free(qVar);
	free(qBuf);
	free(buffer);
	return res;
} 
int vhccrtscr(sqlite3 *db){
	//Menu de creacion de Coche
	char* qMod = malloc(sizeof(char)*30);
	char* qMar = malloc(sizeof(char)*30);
	char* buffer = malloc(sizeof(char)*2);
	char* qBuf = malloc(sizeof(char)*30);
	int res = 0;
	Coche qCoch;
	int flg = 0;
	int flg2 = 0;
	while(flg < 1){
	fflush(stdin);
	system("CLS");
	printf("[Creacion de Coche]\n\nIntroduzca una marca valida\n\n");
	fgets(qBuf,30,stdin);
	sscanf(qBuf, "%s", qMar);
	if(strlen(qMar) > 30){ 
		fflush(stdin);
		printf("Marca Invalida;\nPor favor, introduzca una marca valida\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
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
	printf("[Creacion de Coche]\n\nIntroduzca un modelo valido\n\n");
	fgets(qBuf,30,stdin);
	sscanf(qBuf, "%s", qMod);
	if(strlen(qMod) > 30){
		fflush(stdin);
		printf("Modelo Invalido;\nPor favor, introduzca un modelo valido\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
		getch();
	}
	else{
		fflush(stdin);
		flg2++;
	}
	}
	qCoch = creaCoche(0,qMar,qMod);
	anyadirCoche(db,qCoch);
	printf("[Creacion de Coche]\n\nFuncion Finalizada\nPulse cualquier tecla para continuar\n");
	getch();
	while(flg == 0){
		system("CLS");
		printf("Quiere anyadir otro coche? (1/0)\n");
		fgets(buffer,2,stdin);
		sscanf(buffer, "%d", &res);
		if(res == 1 || res == 0)
			flg++;
		else{
			printf("[Creacion de Coche]\n\nFuncion Finalizada\nPulse cualquier tecla para continuar\n");
			getch();
		}
	}
	free(qMod);
	free(qMar);
	free(buffer);
	free(qBuf);
	return res;
}

int vhcdltscr(sqlite3 *db){
	int res = 0;
	int flg = 0;
	char* buffer = malloc(sizeof(char)*2);
	int qId;
	char* qBuf = malloc(sizeof(char)*10);
	while(flg < 1){
		fflush(stdin);
		system("CLS");
		printf("[Modificacion de Coche]\n\nIntroduzca un numero identificador valido\n\n");
		fgets(qBuf,10,stdin);
		sscanf(qBuf,"%d",&qId);
		if(qId < 1 || existsCoche(db,qId) == 0){
			fflush(stdin);
			printf("ID Invalida o no existente;\nPor favor, introduzca una ID valida\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
			getch();
		}
		else{
		fflush(stdin);
		flg++;
		eliminarCoche(db, qId);
		}
	}
	flg--;
	while(flg == 0){
		system("CLS");
		printf("Quiere anyadir otro coche? (1/0)\n");
		fgets(buffer,2,stdin);
		sscanf(buffer, "%d", &res);
		if(res == 1 || res == 0)
			flg++;
		else{
			printf("[Creacion de Coche]\n\nFuncion Finalizada\nPulse cualquier tecla para continuar\n");
			getch();
		}
	}
	free(buffer);
	free(qBuf);
	return res;
	}

//Funciones
Coche getCoche(sqlite3 *db, int id){
	sqlite3_stmt *stmt;
	Coche qCoch;
	int result;
	char* gemo = "select modelo from coche where id=?";
	char* gema = "select marca from coche where id=?";
	char* geid = "select id from coche where id=?";
	sqlite3_prepare_v2(db, geid, strlen(geid), &stmt, NULL);
	sqlite3_bind_int(stmt, 1, id);
	result = sqlite3_step(stmt);
	if (result == SQLITE_ROW) { //Si existe el email en la BD:
	qCoch.id = sqlite3_column_int(stmt, 0);
	sqlite3_prepare_v2(db, gemo, strlen(gemo), &stmt, NULL);
	sqlite3_bind_int(stmt, 1, id);
	result = sqlite3_step(stmt);
	if (result == SQLITE_ROW) {
			strcpy(qCoch.modelo, (char*) sqlite3_column_text(stmt, 0));
		}
	sqlite3_prepare_v2(db, gema, strlen(gema), &stmt, NULL);
	sqlite3_bind_int(stmt, 1, id);
	result = sqlite3_step(stmt);
	if (result == SQLITE_ROW) {
			strcpy(qCoch.marca, (char*) sqlite3_column_text(stmt, 0));
		}
	}else{
		system("CLS");
		qCoch.id = 0;
		printf("Coche no existe.");
		getch();
		}
	sqlite3_finalize(stmt);
	return qCoch;
}

Coche creaCoche(int id,char marca[30],char modelo[30]){
	Coche qCoch;
	strcpy(qCoch.marca, marca);
	strcpy(qCoch.modelo, modelo);
	return qCoch;
}

void anyadirCoche(sqlite3 *db, Coche coche){
	char* query = malloc(sizeof(char)*256);
	sqlite3_stmt *stmt;
	int result;
	sprintf(query, "insert into coche (id, marca, modelo) values (NULL,'%s','%s')", coche.marca, coche.modelo);
	result = sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
	}
	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error al introducir coche\n");
	}else{
		printf("coche %s introducido\n", coche.modelo);
	}
	sqlite3_finalize(stmt);
}

int existsCoche(sqlite3 *db, int id){
	int result;
	int ret;
	sqlite3_stmt *stmt;
	char* geid = "select id from coche where id = ?";
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

void modificarMarca(sqlite3 *db, int id, char* marca){
	char* query = "UPDATE coche SET marca = ? WHERE id = ?";
	sqlite3_stmt *stmt;
	int result;
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	sqlite3_bind_text(stmt, 1, marca, strlen(marca), SQLITE_STATIC);
	sqlite3_bind_int(stmt, 2, id);
	result = sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void modificarModelo(sqlite3 *db, int id, char* modelo){
	char* query = "UPDATE coche SET modelo = ? WHERE id = ?";
	sqlite3_stmt *stmt;
	int result;
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	sqlite3_bind_text(stmt, 1, modelo, strlen(modelo), SQLITE_STATIC);
	sqlite3_bind_int(stmt, 2, id);
	result = sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void eliminarCoche(sqlite3 *db, int id){
	char* sql1 = "delete from coche where id=?";
	int result;
	sqlite3_stmt *stmt;
	sqlite3_prepare_v2(db, sql1, strlen(sql1), &stmt, NULL);
	sqlite3_bind_int(stmt, 1, id);
	result = sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

//Funciones Visuales

//Perfectas para malloc??:
void visualizarCoches(sqlite3 *db){
	int numR; //Numero de filas. Truco: SELECT Count(*) FROM tblName
	int result;
	char* query = "SELECT MAX(id) FROM coche";
	char* query2;
	//atrib. coche
	char* qMod;
	char* qMar;
	int qId;
	sqlite3_stmt *stmt;
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	result = sqlite3_step(stmt);
	numR = sqlite3_column_int(stmt, 0); //Numero de coche: perfecto
	system("CLS");
	printf("[LISTA DE COCHES]\n\n");
	for(int i = 0; i <= numR; i++){
		qMar = malloc(sizeof(char)*30);
		qMod = malloc(sizeof(char)*30);
		query2 = malloc(sizeof(char)*128);
		sprintf(query2, "SELECT * FROM coche where id = %d", i);
		sqlite3_prepare_v2(db, query2, strlen(query2), &stmt, NULL);
		result = sqlite3_step(stmt);
		if(result == SQLITE_ROW){
			qId = sqlite3_column_int(stmt, 0);
			strcpy(qMar,sqlite3_column_text(stmt, 1));
			strcpy(qMod,sqlite3_column_text(stmt, 2));
			printf("[ID] %d [Marca] %s [Modelo] %s \n", qId, qMar, qMod);
		}
		free(qMod);
		free(qMar);
		free(query2);
	}
	sqlite3_finalize(stmt);
	printf("\n\n[PRESIONAR CUALQUIER TECLA PARA CONTINUAR]");
	getch();
	
}
void imprimirCoches(sqlite3 *db){
	int numR; //Numero de filas. Truco: SELECT Count(*) FROM tblName
	FILE* f;
	f = fopen("coches.export", "w");
	int result;
	char* query = "SELECT MAX(id) FROM coche";
	char* query2;
	//atrib. coche
	char* qMod;
	char* qMar;
	int qId;
	sqlite3_stmt *stmt;
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	result = sqlite3_step(stmt);
	numR = sqlite3_column_int(stmt, 0); //Numero de coches: perfecto
	system("CLS");
	printf("[IMPRIMIENDO COCHES]\n\n");
	for(int i = numR; i > 0; i--){
		qMod = malloc(sizeof(char)*30);
		qMar = malloc(sizeof(char)*30);
		query2 = malloc(sizeof(char)*128);
		sprintf(query2, "SELECT * FROM coche where id = %d", i);
		sqlite3_prepare_v2(db, query2, strlen(query2), &stmt, NULL);
		result = sqlite3_step(stmt);
		if(result == SQLITE_ROW){
			strcpy(qMar,sqlite3_column_text(stmt, 1));
			strcpy(qMod,sqlite3_column_text(stmt, 2));
			qId = sqlite3_column_int(stmt, 0);
			fprintf(f, "[ID] %d [Marca] %s [Modelo] %s \n", qId, qMar, qMod);
		}
		free(qMar);
		free(qMod);
		free(query2);
	}
	fclose(f);
	sqlite3_finalize(stmt);
	printf("\n\n[COCHES IMPRESOS, PULSE CUALQUIER TECLA PARA CONTINUAR]");
	getch();
}