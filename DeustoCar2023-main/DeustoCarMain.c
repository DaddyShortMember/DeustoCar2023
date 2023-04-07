
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "coche.h"
#include "admin.h"
#include "BD.h"
#include "sqlite3.h"
#include <winsock2.h>
#include <math.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

int main(void)
{
	FILE *f;

	f = fopen("log.txt", "a");
	if (fopen("log.txt", "a") == NULL) {
		printf("Error al abrir el fichero de log\n");
	} else {
		fprintf(f, "------------------------------------------------------------------------------\n\n");
	}
	fclose(f);

	sqlite3 *db;

	int result = sqlite3_open("DB.db", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
	}

	f = fopen("log.txt", "a");
	if (fopen("log.txt", "a") == NULL) {
		printf("Error al abrir el fichero de log\n");
	} else {
		fprintf(f, "Abriendo la base de datos\n");
	}
	fclose(f);

	Admin admin;
	//Para insertar el admin en la BD la primera vez:
	//strcpy(admin.nUsuario, "admin");
	//strcpy(admin.password, "admin");
	//insertAdmin(db, admin.nUsuario, admin.password);

	admin = readConfigFile();
	//printfs para pruebas
	//printf("Usuario: %s\n", admin.nUsuario);
	//printf("Contrasena: %s\n", admin.password);
	//Si n = 0, no se han encontrado los datos de Admin en la BD y no se puede acceder al administrador local
	//Si n = 1, se permite el acceso al administrador local
	int n = isAdmin(db, admin);
	//printf("%d", n);

	if (n) {
		int codigoUsuarioPorDefecto = 0;
		int codigoCochePorDefecto = 0;

		//Usuario de prueba
		Usuario usuario;
		usuario.id = codigoUsuarioPorDefecto;
		strcpy(usuario.email, "correoUsuario@gmail.com");
		strcpy(usuario.saldo, "500");
		strcpy(usuario.contrasenya, "lac0ntrasenya");
		strcpy(usuario.nombre, "Nombre");


		//Usuario de prueba 2
		Usuario usuario2;

		usuario2.id = codigoUsuarioPorDefecto;
		strcpy(usuario2.email, "correoUsuario2@gmail.com");
		strcpy(usuario2.saldo, "1000");
		strcpy(usuario2.contrasenya, "contrasenya2");
		strcpy(usuario2.nombre, "Jon");


		//Usuario de prueba 3
		Usuario usuario3;

		usuario3.id = codigoUsuarioPorDefecto;
		strcpy(usuario3.email, "correoUsuario3@gmail.com");
		strcpy(usuario3.saldo, "300");
		strcpy(usuario3.contrasenya, "XXXasdfXXX3451");
		strcpy(usuario3.nombre, "Alvaro");


		//Usuario de prueba 4
		Usuario usuario4;

		usuario4.id = codigoUsuarioPorDefecto;
		strcpy(usuario4.email, "correoUsuario4@gmail.com");
		strcpy(usuario4.saldo, "1500");
		strcpy(usuario4.contrasenya, "1234Alba1234");
		strcpy(usuario4.nombre, "Alba");


		//Usuario de prueba 5
		Usuario usuario5;

		usuario5.id = codigoUsuarioPorDefecto;
		strcpy(usuario5.email, "correoUsuario5@gmail.com");
		strcpy(usuario5.saldo, "360");
		strcpy(usuario5.contrasenya, "87329Lpow65");
		strcpy(usuario5.nombre, "Luis");


		//Usuario de prueba 6
		Usuario usuario6;

		usuario6.id = codigoUsuarioPorDefecto;
		strcpy(usuario6.email, "correoUsuario6@gmail.com");
		strcpy(usuario6.saldo, "700");
		strcpy(usuario6.contrasenya, "NoTengoContrasenya");
		strcpy(usuario6.nombre, "Patricia");


		//Usuario de prueba 7
		Usuario usuario7;

		usuario7.id = codigoUsuarioPorDefecto;
		strcpy(usuario7.email, "correoUsuario7@gmail.com");
		strcpy(usuario7.saldo, "950");
		strcpy(usuario7.contrasenya, "contrasenya1");
		strcpy(usuario7.nombre, "Diego");


		//Usuario de prueba 8
		Usuario usuario8;

		usuario8.id = codigoUsuarioPorDefecto;
		strcpy(usuario8.email, "correoUsuario8@gmail.com");
		strcpy(usuario8.saldo, "200");
		strcpy(usuario8.contrasenya, "NeretxU99");
		strcpy(usuario8.nombre, "Nerea");


		//Usuario de prueba 9
		Usuario usuario9;

		usuario9.id = codigoUsuarioPorDefecto;
		strcpy(usuario9.email, "correoUsuario9@gmail.com");
		strcpy(usuario9.saldo, "560");
		strcpy(usuario9.contrasenya, "lac0ntrasenya");
		strcpy(usuario9.nombre, "Alvaro");


		//Coche de prueba
		Coche coche;

		coche.id = codigoCochePorDefecto;
		coche.marca = 20;
		coche.modelo = 10;
		strcpy(coche.marca, "Seat");
		strcpy(coche.modelo, "Ibiza");


		//Coche de prueba 2
		Coche coche2;

		coche2.id = codigoCochePorDefecto;
		coche2.marca = 2;
		coche2.modelo = 5;
		strcpy(coche2.marca, "Audi");
		strcpy(coche2.modelo, "R8");


		//Coche de prueba 3
		Coche coche3;

		coche3.id = codigoCochePorDefecto;
		coche3.marca = 250;
		coche3.modelo = 75;
		strcpy(coche3.marca, "Bmw");
		strcpy(coche3.modelo, "E46");


		//Coche de prueba 4
		Coche coche4;

		coche4.id = codigoCochePorDefecto;
		coche4.marca = 400;
		coche4.modelo = 250;
		strcpy(coche4.marca, "Audi");
		strcpy(coche4.modelo, "TT");


		//Coche de prueba 5
		Coche coche5;

		coche5.id = codigoCochePorDefecto;
		coche5.marca = 50;
		coche5.modelo = 50;
		strcpy(coche5.marca, "Seat");
		strcpy(coche5.modelo, "Leon");


		//Coche de prueba 6
		Coche coche6;

		coche6.id = codigoCochePorDefecto;
		coche6.marca = 5;
		coche6.modelo = 4;
		strcpy(coche6.marca, "Bmw");
		strcpy(coche6.modelo, "E36");


		//Coche de prueba 7
		Coche coche7;

		coche7.id = codigoCochePorDefecto;
		coche7.marca = 2;
		coche7.modelo = 4;
		strcpy(coche7.marca, "Seat");
		strcpy(coche7.modelo, "Cupra");


		//Coche de prueba 8
		Coche coche8;

		coche8.id = codigoCochePorDefecto;
		coche8.marca = 4;
		coche8.modelo = 3;
		strcpy(coche8.marca, "Audi");
		strcpy(coche8.modelo, " A3");


		//Coche de prueba 9
		Coche coche9;

		coche9.id = codigoCochePorDefecto;
		coche9.marca = 3;
		coche9.modelo = 5;
		strcpy(coche9.marca, "Audi");
		strcpy(coche9.modelo, "A1");

		//Coche de prueba 10
		Coche coche10;

		coche10.id = codigoCochePorDefecto;
		coche10.marca = 6;
		coche10.modelo = 10;
		strcpy(coche10.marca, "GOLF");
		strcpy(coche10.modelo, "GTI");


		eliminarUsuarios(db, result);
		eliminarCoches(db, result);
		anyadirUsuario(db, result, usuario);
		anyadirUsuario(db, result, usuario2);
		anyadirUsuario(db, result, usuario3);
		anyadirUsuario(db, result, usuario4);
		anyadirUsuario(db, result, usuario5);
		anyadirUsuario(db, result, usuario6);
		anyadirUsuario(db, result, usuario7);
		anyadirUsuario(db, result, usuario8);
		anyadirUsuario(db, result, usuario9);
		anyadirCoches(db, result, coche);
		anyadirCoches(db, result, coche2);
		anyadirCoches(db, result, coche3);
		anyadirCoches(db, result, coche4);
		anyadirCoches(db, result, coche5);
		anyadirCoches(db, result, coche6);
		anyadirCoches(db, result, coche7);
		anyadirCoches(db, result, coche8);
		anyadirCoches(db, result, coche9);
		anyadirCoches(db, result, coche10);
		/*//Para probar si los datos entran como deben en la BD
		imprimirUsuarios(db);
		imprimirCoches(db);*/



	}
}
