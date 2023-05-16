#include "usuario.h"


int usmodscr(sqlite3 *db){
	//Opciones para modificar aspectos del usuario [nombre,email,contrasenya,saldo, y permisos de admin. local]
	int res = 0;
	Usuario* qUsua; //Dinamico para permitir mas flexibilidad y no ocupar mucho espacio
	return res;
} 
int usrcrtscr(sqlite3 *db){
	//Menu de creacion de usuario
	char qNom[30];
	char qEma[30];
	char qCon[30];
	char buffer[2];
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
	fgets(qNom,30,stdin);
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
	fgets(qEma,30,stdin);
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
	printf("[Creacion de Usuario]\n\nIntroduzca un nombre de contrasenya valida\n\n");
	fgets(qNom,30,stdin);
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
	fgets((char*)qSal,31,stdin);
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
	char* geno = "select nombre from Usuario where email=?";
	char* geco = "select contrasenya from Usuario where email=?";
	char* geid = "select id from Usuario where email=?";
	char* gesa = "select saldo from Usuario where email=?";
	char* gema = "select email from Usuario where email=?";
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
			qUsua.id = (int) sqlite3_column_text(stmt, 0);
		}
	sqlite3_prepare_v2(db, gesa, strlen(gesa), &stmt, NULL);
	sqlite3_bind_text(stmt, 1, email, strlen(email), SQLITE_STATIC);
	result = sqlite3_step(stmt);
	if (result == SQLITE_ROW) {
			qUsua.saldo = (int) sqlite3_column_text(stmt, 0);
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
	char* sql1 = "insert into usuario (id, nombre, email, contrasenya, saldo) values (NULL,?, ?, ?, ?)";
	sqlite3_stmt *stmt;
	int result;
	sqlite3_prepare_v2(db, sql1, strlen(sql1) + 1, &stmt, NULL) ;
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
	char* geid = "select id from Usuario where email=?";
	sqlite3_prepare_v2(db, geid, strlen(geid), &stmt, NULL);
	sqlite3_bind_text(stmt, 1, email, strlen(email), SQLITE_STATIC);
	result = sqlite3_step(stmt);
	id = (int) sqlite3_column_text(stmt, 0);
	if(result == SQLITE_ROW){
		FILE* f;
		f = fopen("ad.min", "a");
		fprintf(f, "%d\n",id);
		fclose(f);
		
	}else{
		
	}
	
	//log report
}

int isAdmin(sqlite3 *db, char* email){
	int id;
	int result;
	int ret = 0;
	int qId;
	sqlite3_stmt *stmt;
	char* geid = "select id from Usuario where email=?";
	sqlite3_prepare_v2(db, geid, strlen(geid), &stmt, NULL);
	sqlite3_bind_text(stmt, 1, email, strlen(email), SQLITE_STATIC);
	result = sqlite3_step(stmt);
	id = (int) sqlite3_column_text(stmt, 0);
	if(result == SQLITE_ROW){
		FILE* f;
		f = fopen("ad.min", "r");
		while (fgets((char*) id, sizeof(id), f) != NULL)
		{
			fscanf(f, "%d", qId);
			if (qId == id)
				ret = 1;
			
		}
		fclose(f);
	}else{
		return ret;
	}
	
}
int exists(sqlite3 *db, char* email){
	int result;
	int ret;
	sqlite3_stmt *stmt;
	char* geid = "select id from Usuario where email=?";
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
void modificarUsuario(sqlite3 *db, Usuario usuario, int sel){
	
	
	//UPDATE usuario SET x = %y WHERE z
	switch(sel){
		case(0):
		//Cambiar todo
			
		break;
		case(1):
		//Cambiar nombre
			
		break;
		case(2):
		//Cambiar saldo
			
		break;
		case(3):
		//Cambiar contrasenya
			
		break;
		case(4):
		//Dar Admin
			//grantAdmin(db,
		break;
	}
}
void eliminarUsuario(sqlite3 *db, Usuario usuario){
	char* sql1 = "delete from usuario where id=?";
	int result;
	sqlite3_stmt *stmt;
	sqlite3_prepare_v2(db, sql1, strlen(sql1), &stmt, NULL);
	sqlite3_bind_text(stmt, 1, usuario.id, strlen(usuario.id), SQLITE_STATIC);
	result = sqlite3_step(stmt);
}

//Funciones Visuales

//Perfectas para malloc??:
void visualizarUsuarios(sqlite3 *db){
	
}
void imprimirUsuarios(sqlite3 *db){
	
}