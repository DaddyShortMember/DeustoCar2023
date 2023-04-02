#include <stdio.h>
#include "sqlite3.h"
#include "BD.h"
#include "Usuario.h"
#include "Coche.h"
#include "Admin.h"
#include <string.h>
#include <stdlib.h>

int insertUsuario(sqlite3 *db, char nombre[], char email[], char contrasenya[], int saldo) {
	sqlite3_stmt *stmt;

	char sql[] = "insert into usuario (id, nombre, email, contrasenya, saldo) values (NULL, ?, ?, ?, ?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");
	result = sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 2, email, strlen(email), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 3, contrasenya, strlen(contrasenya), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_int(stmt, 4, saldo);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into Usuario table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

int insertCoche(sqlite3 *db, char marca[], char modelo[]) {
	sqlite3_stmt *stmt;

	char sql[] = "insert into coche (id, marca, modelo values (NULL, ?, ?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");
	result = sqlite3_bind_text(stmt, 1, marca, strlen(marca), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 2, modelo, strlen(modelo), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into Coche table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

int insertAdmin(sqlite3 *db, char nombre[], char contrasenya[]) {
	sqlite3_stmt *stmt;

	char sql[] = "insert into admin (idAdmin, nombre, contrasenya) values (NULL, ?, ?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 2, contrasenya, strlen(contrasenya), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into Admin table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

Usuario getUsuario(sqlite3 *db, char codigo[50]) {
	sqlite3_stmt *stmt;
	Usuario u;

	char sql[] = "select id, nombre, email, contrasenya, saldoo from usuario";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("SQL query prepared (SELECT)\n");

	//Los atributos de Usuario que se recibirán
	char cUsuario[100];
	char email[100];
	char dni[100];
	char password[100];
	char nombre[100];
	char saldo[100];

	printf("\n");
	printf("\n");
	printf("Recuperando usuario:\n");
		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {
				//cUsuario = sqlite3_column_int(stmt, 0);
				strcpy(cUsuario, (char *) sqlite3_column_text(stmt, 0));
				strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
				strcpy(email, (char *) sqlite3_column_text(stmt, 2));
				strcpy(password, (char *) sqlite3_column_text(stmt, 3));
				strcpy(saldo, (char*) sqlite3_column_text(stmt, 4));
				if (!strcmp(codigo, cUsuario)) {
					u.id = atoi(cUsuario);
					strcpy(u.nombre, nombre);
					strcpy(u.email, email);
					strcpy(u.contrasenya, password);
					u.saldo = (int) saldo;
				}
			}
		} while (result == SQLITE_ROW);

		printf("\n");
		printf("\n");

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
		}

		printf("Prepared statement finalized (SELECT)\n");

		return u;
}

Coche getCoche(sqlite3 *db, char codigo[50]) {
	sqlite3_stmt *stmt;
	Coche c;

	char sql[] = "select id, marca, modelo from coche";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("SQL query prepared (SELECT)\n");

	//Los atributos de Coche que se recibirán
	char id[100];
	char marca[100];
	char modelo[100];
	printf("\n");
	printf("\n");
	printf("Recuperando coche:\n");
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			strcpy(id, (char *) sqlite3_column_text(stmt, 0));
			strcpy(marca, (char *) sqlite3_column_text(stmt, 1));
			strcpy(modelo, (char *) sqlite3_column_text(stmt, 2));
			if (!strcmp(codigo, id)) {
				c.id = atoi(id);
				for (int i = 0; i < 30; ++i) {
					c.marca[i] = marca[i];
				}
				for (int i = 0; i < 30; ++i) {
					c.modelo[i] = modelo[i];
				}
				strcpy(c.marca, marca);
				strcpy(c.modelo, modelo);
			}
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("Prepared statement finalized (SELECT)\n");

	return c;
}

int imprimirUsuarios(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "select id, nombre, email, contrasenya, saldo from usuario";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	//Los atributos de Usuario que se imprimiran
	int id;
	char nombre[100];
	char email[100];
	char contrasenya[100];
	int saldo;

	printf("\n");
	printf("\n");
	printf("Mostrando usuarios:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			id = sqlite3_column_int(stmt, 0);
			strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
			strcpy(email, (char *) sqlite3_column_text(stmt, 2));
			strcpy(contrasenya, (char *) sqlite3_column_text(stmt, 3));
			saldo = sqlite3_column_int(stmt, 4);
			printf("ID: %i NOMBRE: %s EMAIL: %s CONTRASENYA: %s SALDO: %f\n", id, nombre, email, contrasenya, saldo);
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (SELECT)\n");

	return SQLITE_OK;
}

int imprimirCoches(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "select id, marca, modelo from coche";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	//Los atributos de coche que se imprimiran
	int id;
	char marca[100];
	char modelo[100];

	printf("\n");
	printf("\n");
	printf("Mostrando coches:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			id = sqlite3_column_int(stmt, 0);
			strcpy(marca, (char *) sqlite3_column_text(stmt, 1));
			strcpy(modelo, (char *) sqlite3_column_text(stmt, 2));
			printf("ID: %i MARCA: %s MODELO: %s\n", id, marca, modelo);
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (SELECT)\n");

	return SQLITE_OK;
}

int deleteUsuario(sqlite3 *db, char codigo[50]) {
	sqlite3_stmt *stmt;

	char sql[100] = "delete from usuario where id=";
	strcat(sql, codigo);

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int deleteCoche(sqlite3 *db, char codigo[50]) {
	sqlite3_stmt *stmt;

	char sql[100] = "delete from coche where id=";
	strcat(sql, codigo);

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int deleteAllUsuarios(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "delete from usuario";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int deleteAllCoches(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "delete from coche";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int isAdmin(sqlite3 *db, Admin admin) {
	sqlite3_stmt *stmt;

	char sql[] = "select id, nombre, contrasenya from admin";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("SQL query prepared (SELECT)\n");

	//Los atributos de Admin que se recibirán
	char nombre[100];
	char contrasenya[100];

	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
			strcpy(contrasenya, (char *) sqlite3_column_text(stmt, 2));
			if (!strcmp(admin.nombre, nombre) && !strcmp(admin.contrasenya, contrasenya)) {
				//1 = Es admin
				return 1;
			}
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("Prepared statement finalized (SELECT)\n");

	return 0;
}



