#include "usuario.h"


int usmodscr(sqlite3 *db){
	//Opciones para modificar aspectos del usuario [nombre,email,contrasenya,saldo, y permisos de admin. local]
	int res = 0;
	char qEmail[30];
	char qVar[30];
	int qSal;
	return res;
} 
int usrcrtscr(sqlite3 *db){
	//Menu de creacion de usuario
	char qNom[30];
	char qEma[30];
	char qCon[30];
	char buffer[2];
	char qBuf[30];
	char salB[11];
	int qSal;
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
	sscanf(qBuf, "%s", &qNom);
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
	sscanf(qBuf, "%s", &qEma);
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
	sscanf(qBuf, "%s", &qCon);
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
	sscanf(salB, "%d", &qSal);
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
	qUsua = creaUsuario(qNom,qEma,qCon,qSal);
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
	char* sql1 = "insert into usuario (id, nombre, mail, contrasenya, saldo) values (NULL,?, ?, ?, ?)";
	sqlite3_stmt *stmt;
	int result;
	sqlite3_prepare_v2(db, sql1, strlen(sql1) + 1, &stmt, NULL);
	sqlite3_bind_text(stmt, 1, usuario.nombre, strlen(usuario.nombre), SQLITE_STATIC);
	sqlite3_bind_text(stmt, 2, usuario.email, strlen(usuario.email), SQLITE_STATIC);
	sqlite3_bind_text(stmt, 3, usuario.contrasenya, strlen(usuario.contrasenya), SQLITE_STATIC);
	sqlite3_bind_int(stmt, 4, usuario.saldo);
	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error al introducir usuario\n");
	}else{
		printf("Usuario %s introducido\n", usuario.email);
	}
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
	
	//log report
}

int isAdmin(sqlite3 *db, char* email){
	int id;
	int result;
	int ret = 0;
	int qId;
	sqlite3_stmt *stmt;
	char* geid = "select id from Usuario where mail=?";
	//LOG??printf("select declarado\n");
	sqlite3_prepare_v2(db, geid, strlen(geid), &stmt, NULL);
	sqlite3_bind_text(stmt, 1, email, strlen(email), SQLITE_STATIC);
	//printf("select preparado\n");
	result = sqlite3_step(stmt);
	//printf("select hecho\n");
	id = sqlite3_column_int(stmt, 0);
	if(result == SQLITE_ROW){
		FILE* f;
		//printf("id del select: %d\n",id);
		f = fopen("ad.min", "r");
		//printf("archivo abierto\n");
		while (fscanf(f, "%d\n", &qId)!= EOF)
		{
			//printf("qId:%d\n",qId);
			if (qId == id){
				//printf("MATCH\n");
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
		return ret;
	}
	
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
}

void modificarContrasenya(sqlite3 *db, char* email, char* contrasenya){
	char* query = "UPDATE usuario SET contrasenya = ? WHERE mail = ?";
	sqlite3_stmt *stmt;
	int result;
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	sqlite3_bind_text(stmt, 1, contrasenya, strlen(contrasenya), SQLITE_STATIC);
	sqlite3_bind_text(stmt, 2, email, strlen(email), SQLITE_STATIC);
	result = sqlite3_step(stmt);
}

void modificarNombre(sqlite3 *db, char* email, char* nombre){
	char* query = "UPDATE usuario SET nombre = ? WHERE mail = ?";
	sqlite3_stmt *stmt;
	int result;
	sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
	sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
	sqlite3_bind_text(stmt, 2, email, strlen(email), SQLITE_STATIC);
	result = sqlite3_step(stmt);
}

void eliminarUsuario(sqlite3 *db, Usuario usuario){
	char* sql1 = "delete from usuario where id=?";
	int result;
	sqlite3_stmt *stmt;
	sqlite3_prepare_v2(db, sql1, strlen(sql1), &stmt, NULL);
	sqlite3_bind_int(stmt, 1, usuario.id);
	result = sqlite3_step(stmt);
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
	for(int i = 0; i <= numR; i++){
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
	printf("\n\n[USUARIOS IMPRESOS, PULSE CUALQUIER TECLA PARA CONTINUAR]");
	getch();
}