#include "usuario.h"


int usmodscr(sqlite3 *db){
	//Opciones para modificar aspectos del usuario [nombre,email,contrasenya,saldo, y permisos de admin. local]
	int res = 0;
	int flg = 0;
	char* qEma = malloc(sizeof(char)*30);
	char* qVar = malloc(sizeof(char)*30);
	char* qBuf = malloc(sizeof(char)*30);
	char* buffer = malloc(sizeof(char)*3);
	char* salB = malloc(sizeof(int)*10);
	int* qSal = malloc(sizeof(int));
	int choice;
	while(flg < 1){
		fflush(stdin);
		system("CLS");
		printf("[Modificacion de Usuario]\n\nIntroduzca un correo electronico valido\n\n");
		fgets(qBuf,30,stdin);
		sscanf(qBuf, "%s", qEma);
		if(strlen(qEma) > 30 || exists(db, qEma) == 0){
			fflush(stdin);
			printf("Email Invalido o no existente;\nPor favor, introduzca un email valido\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
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
	printf("[MODIFICAR ATRIBUTO DE USUARIO]\n");
	printf("[1] Contrasenya\n"); 
	printf("[2] Nombre\n"); 
	printf("[3] Saldo\n");
	printf("Introduzca su seleccion:\n");
	fgets(buffer,3,stdin);
	sscanf(buffer, "%d", &choice);
	switch(choice){
		case 1: //Mod. Contrasenya
				while(flg < 1){
					fflush(stdin);
					system("CLS");
					printf("[Modificacion de Usuario]\n\nIntroduzca una contrasenya valida\n\n");
					fgets(qBuf,30,stdin);
					sscanf(qBuf, "%s", qVar);
					if(strlen(qVar) > 30){ 
						fflush(stdin);
						printf("Contrasenya Invalida;\nPor favor, introduzca una contrasenya valida\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
						getch();
					}else{
						fflush(stdin);
						flg++;
					}
				}
				modificarContrasenya(db, qEma, qVar);
				break;
		case 2: //Mod. Nombre
				while(flg < 1){
					fflush(stdin);
					system("CLS");
					printf("[Modificacion de Usuario]\n\nIntroduzca un nombre valido\n\n");
					fgets(qBuf,30,stdin);
					sscanf(qBuf, "%s", qVar);
					if(strlen(qVar) > 30){ 
						fflush(stdin);
						printf("Nombre Invalido;\nPor favor, introduzca un nombre valido\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
						getch();
					}else{
						fflush(stdin);
						flg++;
					}
				}
				modificarNombre(db, qEma, qVar);
				break;
		case 3: //Mod. Saldo
				while(flg < 1){
					fflush(stdin);
					system("CLS");
					printf("[Modificacion de Usuario]\n\nIntroduzca un saldo valido\n\n");
					fgets(salB,11,stdin);
					sscanf(salB, "%d", qSal);
					if(qSal < 0){ 
						fflush(stdin);
						printf("Saldo Invalido;\nPor favor, introduzca un saldo valido\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
						getch();
					}
					else{
						fflush(stdin);
						flg++;
					}
				}
				modificarSaldo(db, qEma,(int)&qSal);
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
		printf("Quiere modificar otro usuario? (1/0)\n");
		fgets(buffer,2,stdin);
		sscanf(buffer, "%d", &res);
		if(res == 1 || res == 0)
			flg++;
		else{
			printf("[Modificacion de Usuario]\n\nFuncion Finalizada\nPulse cualquier tecla para continuar\n");
			getch();
		}
	}
	free(qEma);
	free(qVar);
	free(qBuf);
	free(buffer);
	free(salB);
	free(qSal);
	return res;
} 
int usrcrtscr(sqlite3 *db){
	//Menu de creacion de usuario
	char* qNom = malloc(sizeof(char)*30);
	char* qEma = malloc(sizeof(char)*30);
	char* qCon = malloc(sizeof(char)*30);
	//char buffer[2];
	char* buffer = malloc(sizeof(char)*2);
	char* qBuf = malloc(sizeof(char)*30);
	char* salB = malloc(sizeof(char)*10);
	int* qSal = malloc(sizeof(int));
	int res = 0;
	Usuario qUsua;
	int flg = 0;
	int flg2 = 0;
	int flg3 = 0;
	int flg4 = 0;
	while(flg < 1){
	fflush(stdin);
	system("CLS");
	printf("[Creacion de Usuario]\n\nIntroduzca un nombre de usuario valido\n\n");
	fgets(qBuf,30,stdin);
	sscanf(qBuf, "%s", qNom);
	if(strlen(qNom) > 30){ 
		fflush(stdin);
		printf("Usuario Invalido;\nPor favor, introduzca un usuario valido\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
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
	printf("[Creacion de Usuario]\n\nIntroduzca un correo electronico valido\n\n");
	fgets(qBuf,30,stdin);
	sscanf(qBuf, "%s", qEma);
	if(strlen(qEma) > 30 || exists(db, qEma) == 1){
		fflush(stdin);
		printf("Email Invalido o repetido;\nPor favor, introduzca un email valido\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
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
	printf("[Creacion de Usuario]\n\nIntroduzca una contrasenya valida\n\n");
	fgets(qBuf,30,stdin);
	sscanf(qBuf, "%s", qCon);
	if(strlen(qCon) > 30){ 
		fflush(stdin);
		printf("Contrasenya Invalida;\nPor favor, introduzca una contrasenya valida\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
		getch();
	}else{
		fflush(stdin);
		flg3++;
	}
	}
	while(flg4 < 1){
	fflush(stdin);
	system("CLS");
	printf("[Creacion de Usuario]\n\nIntroduzca un saldo valido\n\n");
	fgets(salB,11,stdin);
	sscanf(salB, "%d", qSal);
	if(qSal < 0){ 
		fflush(stdin);
		printf("Saldo Invalido;\nPor favor, introduzca un saldo valido\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
		getch();
	}
	else{
		fflush(stdin);
		flg4++;
		flg--;
	}
	}
	qUsua = creaUsuario(qNom,qEma,qCon,(int)&qSal);
	anyadirUsuario(db,qUsua);
	printf("[Creacion de Usuario]\n\nFuncion Finalizada\nPulse cualquier tecla para continuar\n");
	getch();
	while(flg == 0){
		system("CLS");
		printf("Quiere anyadir otro usuario? (1/0)\n");
		fgets(buffer,2,stdin);
		sscanf(buffer, "%d", &res);
		if(res == 1 || res == 0)
			flg++;
		else{
			printf("[Creacion de Usuario]\n\nFuncion Finalizada\nPulse cualquier tecla para continuar\n");
			getch();
		}
	}
	free(qNom);
	free(qCon);
	free(qEma);
	free(buffer);
	free(qBuf);
	free(salB);
	free(qSal);
	return res;
}

int usrdltscr(sqlite3 *db){
	int res = 0;
	int flg = 0;
	char* buffer = malloc(sizeof(char)*2);
	char* qEma = malloc(sizeof(char)*30);
	char* qBuf = malloc(sizeof(char)*30);
	while(flg < 1){
		fflush(stdin);
		system("CLS");
		printf("[Modificacion de Usuario]\n\nIntroduzca un correo electronico valido\n\n");
		fgets(qBuf,30,stdin);
		sscanf(qBuf, "%s", qEma);
		if(strlen(qEma) > 30 || exists(db, qEma) == 0){
			fflush(stdin);
			printf("Email Invalido o no existente;\nPor favor, introduzca un email valido\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
			getch();
		}
		else{
		fflush(stdin);
		flg++;
		eliminarUsuario(db, qEma);
		}
	}
	flg--;
	while(flg == 0){
		system("CLS");
		printf("Quiere anyadir otro usuario? (1/0)\n");
		fgets(buffer,2,stdin);
		sscanf(buffer, "%d", &res);
		if(res == 1 || res == 0)
			flg++;
		else{
			printf("[Creacion de Usuario]\n\nFuncion Finalizada\nPulse cualquier tecla para continuar\n");
			getch();
		}
	}
	free(buffer);
	free(qBuf);
	free(qEma);
	return res;
	}

//Funciones
Usuario getUser(sqlite3 *db, char* email){
	sqlite3_stmt *stmt;
	Usuario qUsua;
	int result;
	char* geno = "select nombre from Usuario where mail=?";
	char* geco = "select contrasenya from Usuario where mail=?";
	char* geid = "select id from Usuario where mail=?";
	char* gesa = "select saldo from Usuario where mail=?";
	char* gema = "select mail from Usuario where mail=?";
	sqlite3_prepare_v2(db, gema, strlen(gema), &stmt, NULL);
	sqlite3_bind_text(stmt, 1, email, strlen(email), SQLITE_STATIC);
	result = sqlite3_step(stmt);
	if (result == SQLITE_ROW) { //Si existe el email en la BD:
	strcpy(qUsua.email, (char*) sqlite3_column_text(stmt, 0));
	sqlite3_prepare_v2(db, geno, strlen(geno), &stmt, NULL);
	sqlite3_bind_text(stmt, 1, email, strlen(email), SQLITE_STATIC);
	result = sqlite3_step(stmt);
	if (result == SQLITE_ROW) {
			strcpy(qUsua.nombre, (char*) sqlite3_column_text(stmt, 0));
		}
	sqlite3_prepare_v2(db, geco, strlen(geco), &stmt, NULL);
	sqlite3_bind_text(stmt, 1, email, strlen(email), SQLITE_STATIC);
	result = sqlite3_step(stmt);
	if (result == SQLITE_ROW) {
			strcpy(qUsua.contrasenya, (char*) sqlite3_column_text(stmt, 0));
		}
	sqlite3_prepare_v2(db, geid, strlen(geid), &stmt, NULL);
	sqlite3_bind_text(stmt, 1, email, strlen(email), SQLITE_STATIC);
	result = sqlite3_step(stmt);
	if (result == SQLITE_ROW) {
			qUsua.id = sqlite3_column_int(stmt, 0);
		}
	sqlite3_prepare_v2(db, gesa, strlen(gesa), &stmt, NULL);
	sqlite3_bind_text(stmt, 1, email, strlen(email), SQLITE_STATIC);
	result = sqlite3_step(stmt);
	if (result == SQLITE_ROW) {
			qUsua.saldo = sqlite3_column_int(stmt, 0);
		}
		}else{
			system("CLS");
			qUsua.id = 0;
			printf("Usuario no existe.");
			getch();
		}
	sqlite3_finalize(stmt);
	return qUsua;
}

Usuario creaUsuario(char nombre[30],char email[30],char contrasenya[30],int saldo){
	Usuario qUsua;
	strcpy(qUsua.nombre, nombre);
	strcpy(qUsua.email, email);
	strcpy(qUsua.contrasenya, contrasenya);
	qUsua.saldo = saldo;
	return qUsua;
}

void anyadirUsuario(sqlite3 *db,  Usuario usuario){
	//char* sql1 = "insert into usuario (id, nombre, mail, contrasenya, saldo) values (NULL,?, ?, ?, ?)";
	char* query = malloc(sizeof(char)*256);
	sprintf(query, "insert into usuario (id, nombre, mail, contrasenya, saldo) values (NULL,%s, %s, %s, %d)", usuario.nombre, usuario.email, usuario.contrasenya, usuario.saldo);
	sqlite3_stmt *stmt;
	int result;
	sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
	//sqlite3_bind_text(stmt, 1, usuario.nombre, strlen(usuario.nombre), SQLITE_STATIC);
	//sqlite3_bind_text(stmt, 2, usuario.email, strlen(usuario.email), SQLITE_STATIC);
	//sqlite3_bind_text(stmt, 3, usuario.contrasenya, strlen(usuario.contrasenya), SQLITE_STATIC);
	//sqlite3_bind_int(stmt, 4, usuario.saldo);
	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error al introducir usuario\n");
	}else{
		printf("Usuario %s introducido\n", usuario.email);
	}
	sqlite3_finalize(stmt);
}
void grantAdmin(sqlite3 *db, char* email){
	//Fichero de texto, por favor.
	int id;
	int result;
	sqlite3_stmt *stmt;
	char* geid = "select id from Usuario where mail=?";
	sqlite3_prepare_v2(db, geid, strlen(geid), &stmt, NULL);
	sqlite3_bind_text(stmt, 1, email, strlen(email), SQLITE_STATIC);
	result = sqlite3_step(stmt);
	id = sqlite3_column_int(stmt, 0);
	if(result == SQLITE_ROW){
		FILE* f;
		f = fopen("ad.min", "a");
		fprintf(f, "%d\n",id);
		fclose(f);
	}else{
		printf("Usuario no existe.");
	}
	
	sqlite3_finalize(stmt);
}

int isAdmin(sqlite3 *db, char* email){
	int id;
	int result;
	int ret = 0;
	int qId;
	sqlite3_stmt *stmt;
	char* geid = "select id from Usuario where mail=?";
	sqlite3_prepare_v2(db, geid, strlen(geid), &stmt, NULL);
	sqlite3_bind_text(stmt, 1, email, strlen(email), SQLITE_STATIC);
	result = sqlite3_step(stmt);
	id = sqlite3_column_int(stmt, 0);
	if(result == SQLITE_ROW){
		FILE* f;
		f = fopen("ad.min", "r");
		while (fscanf(f, "%d\n", &qId)!= EOF)
		{
			if (qId == id){
				ret = 1;
			}
		}
		fclose(f);
		if(ret == 1)
			printf("MATCH");
		else
			printf("NO MATCH\n");
	}else{
		printf("Usuario no existe en el sistema\n");
	}
	sqlite3_finalize(stmt);
	return ret;
}
int exists(sqlite3 *db, char* email){
	int result;
	int ret;
	sqlite3_stmt *stmt;
	char* geid = "select id from Usuario where mail=?";
	sqlite3_prepare_v2(db, geid, strlen(geid), &stmt, NULL);
	sqlite3_bind_text(stmt, 1, email, strlen(email), SQLITE_STATIC);
	result = sqlite3_step(stmt);
	if(result == SQLITE_ROW){
		ret = 1;
	}else{
		ret = 0;
	}
	sqlite3_finalize(stmt);
	return ret;
}

int passCheck(sqlite3 *db, char* email, char* contrasenya){
	int result;
	int ret;
	sqlite3_stmt *stmt;
	char* geid = "select contrasenya from Usuario where mail=?";
	sqlite3_prepare_v2(db, geid, strlen(geid), &stmt, NULL);
	sqlite3_bind_text(stmt, 1, email, strlen(email), SQLITE_STATIC);
	result = sqlite3_step(stmt);
	if(result == SQLITE_ROW){
		char* qCon = sqlite3_column_text(stmt, 0);
		if(strcmp(qCon,contrasenya) == 0)
			ret = 1;
		else
			ret = 0;
	}else{
		ret = 0;
	}
	sqlite3_finalize(stmt);
	return ret;
}

void modificarSaldo(sqlite3 *db, char* email, int saldo){
	char* query = "UPDATE usuario SET saldo = ? WHERE mail = ?";
	sqlite3_stmt *stmt;
	int result;
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	sqlite3_bind_int(stmt, 1, saldo);
	sqlite3_bind_text(stmt, 2, email, strlen(email), SQLITE_STATIC);
	result = sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void modificarContrasenya(sqlite3 *db, char* email, char* contrasenya){
	char* query = "UPDATE usuario SET contrasenya = ? WHERE mail = ?";
	sqlite3_stmt *stmt;
	int result;
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	sqlite3_bind_text(stmt, 1, contrasenya, strlen(contrasenya), SQLITE_STATIC);
	sqlite3_bind_text(stmt, 2, email, strlen(email), SQLITE_STATIC);
	result = sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void modificarNombre(sqlite3 *db, char* email, char* nombre){
	char* query = "UPDATE usuario SET nombre = ? WHERE mail = ?";
	sqlite3_stmt *stmt;
	int result;
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
	sqlite3_bind_text(stmt, 2, email, strlen(email), SQLITE_STATIC);
	result = sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void eliminarUsuario(sqlite3 *db, char* email){
	char* sql1 = "delete from usuario where mail=?";
	int result;
	sqlite3_stmt *stmt;
	sqlite3_prepare_v2(db, sql1, strlen(sql1), &stmt, NULL);
	sqlite3_bind_text(stmt, 1, email, strlen(email), SQLITE_STATIC);
	result = sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

//Funciones Visuales

//Perfectas para malloc??:
void visualizarUsuarios(sqlite3 *db){
	int numR; //Numero de filas. Truco: SELECT Count(*) FROM tblName
	int result;
	char* query = "SELECT MAX(id) FROM usuario";
	char* query2;
	//atrib. usuario
	char* qNom;
	char* qEma;
	char* qCon;
	int qSal;
	int qId;
	sqlite3_stmt *stmt;
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	result = sqlite3_step(stmt);
	numR = sqlite3_column_int(stmt, 0); //Numero de usuarios: perfecto
	system("CLS");
	printf("[LISTA DE USUARIOS]\n\n");
	for(int i = 0; i <= numR; i++){
		qEma = malloc(sizeof(char)*30);
		qNom = malloc(sizeof(char)*30);
		qCon = malloc(sizeof(char)*30);
		query2 = malloc(sizeof(char)*128);
		sprintf(query2, "SELECT * FROM usuario where id = %d", i);
		sqlite3_prepare_v2(db, query2, strlen(query2), &stmt, NULL);
		result = sqlite3_step(stmt);
		if(result == SQLITE_ROW){
			qId = sqlite3_column_int(stmt, 0);
			strcpy(qNom,sqlite3_column_text(stmt, 1));
			strcpy(qEma,sqlite3_column_text(stmt, 2));
			strcpy(qCon,sqlite3_column_text(stmt, 3));
			qSal = sqlite3_column_int(stmt, 4);
			printf("[ID] %d [Nombre] %s [E-Mail] %s [Contrasenya] %s [Saldo] %d \n", qId, qNom, qEma, qCon, qSal);
		}
		free(qEma);
		free(qNom);
		free(qCon);
		free(query2);
	}
	sqlite3_finalize(stmt);
	printf("\n\n[PRESIONAR CUALQUIER TECLA PARA CONTINUAR]");
	getch();
	
}
void imprimirUsuarios(sqlite3 *db){
	int numR; //Numero de filas. Truco: SELECT Count(*) FROM tblName
	FILE* f;
	f = fopen("usuarios.export", "w");
	int result;
	char* query = "SELECT MAX(id) FROM usuario";
	char* query2;
	//atrib. usuario
	char* qNom;
	char* qEma;
	int qSal;
	sqlite3_stmt *stmt;
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	result = sqlite3_step(stmt);
	numR = sqlite3_column_int(stmt, 0); //Numero de usuarios: perfecto
	system("CLS");
	printf("[IMPRIMIENDO USUARIOS]\n\n");
	for(int i = numR; i > 0; i--){
		qEma = malloc(sizeof(char)*30);
		qNom = malloc(sizeof(char)*30);
		query2 = malloc(sizeof(char)*128);
		sprintf(query2, "SELECT * FROM usuario where id = %d", i);
		sqlite3_prepare_v2(db, query2, strlen(query2), &stmt, NULL);
		result = sqlite3_step(stmt);
		if(result == SQLITE_ROW){
			strcpy(qNom,sqlite3_column_text(stmt, 1));
			strcpy(qEma,sqlite3_column_text(stmt, 2));
			qSal = sqlite3_column_int(stmt, 4);
			fprintf(f, "[Nombre] %s [E-Mail] %s [Saldo] %d \n", qNom, qEma, qSal);
		}
		free(qEma);
		free(qNom);
		free(query2);
	}
	fclose(f);
	sqlite3_finalize(stmt);
	printf("\n\n[USUARIOS IMPRESOS, PULSE CUALQUIER TECLA PARA CONTINUAR]");
	getch();
}