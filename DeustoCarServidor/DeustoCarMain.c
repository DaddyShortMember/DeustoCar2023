#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "usuario.h"
#include "coche.h"
#include "venta.h"
#include "compra.h"
#include "sqlite3.h"



//sqlite3 *db
int lgscr(sqlite3* db); //menu de inicio de sesion
int mmenu(void); //menu principal
int carscr(sqlite3* db);//menu de visualizacion/modificacion sobre: coche
int prcscr(sqlite3* db);//menu de visualizacion/modificacion sobre: compra
int slsscr(sqlite3* db);//menu de visualizacion/modificacion sobre: venta
int usrscr(sqlite3* db);//menu de visualizacion/modificacion sobre: usuario
 
 
 //TODO:
 //*Realizar las funciones sobre la BD en la .h y la .c de su respectivo modulo

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

			admin = leerFichero();
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
					strcpy(usuario.email, "correo@gmail.com");
					strcpy(usuario.nombre, "Jon");
					strcpy(usuario.contrasenya, "contrasenya");
					strcpy(usuario.saldo, "500");


					//Usuario de prueba 2
							Usuario usuario2;

							usuario2.id = codigoUsuarioPorDefecto;
							strcpy(usuario2.email, "correo2@gmail.com");
							strcpy(usuario2.nombre, "Jaime");
							strcpy(usuario2.contrasenya, "contrasenya2");
							strcpy(usuario2.saldo, "20");


							//Usuario de prueba 3
							Usuario usuario3;

							usuario3.id = codigoUsuarioPorDefecto;
							strcpy(usuario3.email, "correo3@gmail.com");
							strcpy(usuario3.nombre, "Alex");
							strcpy(usuario3.contrasenya, "contrasenya3");
							strcpy(usuario3.saldo, "80");

							//Vuelo de prueba
									Coche coche;

									coche.id = codigoCochePorDefecto;
									strcpy(coche.marca, "seat");
									strcpy(coche.modelo, "ibiza");

									Coche coche2;

									coche2.id = codigoCochePorDefecto;
									strcpy(coche2.marca, "golf");
									strcpy(coche2.modelo, "gti");

									Coche coche3;

									coche3.id = codigoCochePorDefecto;
									strcpy(coche3.marca, "audi");
									strcpy(coche3.modelo, "tt");

									Coche coche4;

									coche4.id = codigoCochePorDefecto;
									strcpy(coche4.marca, "bmw");
									strcpy(coche4.modelo, "e46");

									Coche coche5;

									coche5.id = codigoCochePorDefecto;
									strcpy(coche5.marca, "seat");
									strcpy(coche5.modelo, "leon");





									eliminarUsuarios(db, result);
									eliminarCoches(db, result);

									anyadirUsuario(db, result, usuario);
									anyadirUsuario(db, result, usuario2);
									anyadirUsuario(db, result, usuario3);

									anyadirCoche(db, result, coche);
									anyadirCoche(db, result, coche2);
									anyadirCoche(db, result, coche3);









	int mmn = 1; //Return de Main Menu
	int lg; //Return de Log-in Screen
	int usr; // Return de sub-menus
	int usi; //User Input
	sqlite3 *db;
	sqlite3_open("DB.db", &db);
	lg = lgscr(db);
	if(lg = 1){
		while(mmn != 0){
		mmn = mmenu();
		usi = 1;
		switch(mmn){
		case 0: system("CLS");
				exit(1);
				break;
		case 1: while(usi != 0){
			usi = usrscr(db);
		}
				break;
		case 2: while(usi != 0){
		}
				break;
		case 3: while(usi != 0){
		}
				break;
		case 4: 
				break;
		default: system("CLS");
				printf("Opcion Invalida\nHas logrado salir de una funcion de manera inadecuada...\nPresiona cualquier tecla para volver a acceder al menu principal\n");
				getch();
		}
			
		}
	}
	else{
		sqlite3_close(db);
		exit(0);
	}
	
}

int lgscr(sqlite3* db){ //DB + return int?
	int ret;
	int flg = 0;
	int flg2 = 1;
	int sec = 0;
	char usi[31];
	char buf[30];
	char mail[31];
	int zz = 1;
	while(flg < 1){
	fflush(stdin);
		if(sec == 3){
			system("CLS");
			flg++;
			ret = 0;
		}
	system("CLS");
	printf("Cliente de Admin. Local\n\n\n\n");
	printf("Introduzca su email:\n");
	fgets(buf,30,stdin);;
	sscanf(buf, "%s", &usi);
	if(isAdmin(db,usi) == 0){
		sec++;
		fflush(stdin);
		if(sec < 3)
			printf("Email Invalido;\nPor favor, introduzca un email valido\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
		else
			printf("Email Invalido;\nCerrando Programa\n[PRESIONE CUALQUIER TECLA PARA SALIR]\n");
		getch();
	}
	else{
		fflush(stdin);
		strcpy(mail, usi);
		flg++;
	}
	}
	while(flg2 > 0){
		if(sec == 3){
			system("CLS");
			flg2--;
			ret = 0;
		}
	system("CLS");
	printf("Cliente de Admin. Local\n\n\n\n");
	printf("Introduzca su contrasenya:\n");
	fgets(buf,30,stdin);
	sscanf(buf, "%s", &usi);
	if(passCheck(db,mail,usi) == 0){
		sec++;
		fflush(stdin);
		if(sec < 3)
			printf("Contrasenya Incorrecta;\nPor favor, introduzca la contrasenya correcta\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
		else
			printf("Contrasenya Incorrecta;\nCerrando Programa\n[PRESIONE CUALQUIER TECLA PARA SALIR]\n");
		getch();
	}
	else{
		fflush(stdin);
		flg2--;
	}
	}
	return ret;
}

int mmenu(void){ //Int
	fflush(stdin);
	int ret = 1;
	int flg = 0;
	char buffer[3]; 
	int usi;
	while(flg == 0){
	system("CLS");
	printf("Cliente de Admin. Local\n");
	printf("[MENU PRINCIPAL]\n");
	printf("[1] Usuarios\n");
	printf("[2] Coches\n");
	printf("[3] Ventas\n");
	printf("[4] Compras\n");
	printf("[0] Salida\n");
	printf("Introduzca su seleccion:\n");
	fflush(stdin);
	fgets(buffer,3,stdin);
	sscanf(buffer, "%d", &usi);
	switch(usi){
		case 0: system("CLS");
				ret = usi;
				flg++;
				break;
		case 1: fflush(stdin);
				system("CLS");
				ret = usi;
				flg++;
				break;
		case 2: fflush(stdin);
				system("CLS");
				ret = usi;
				flg++;
				break;
		case 3: fflush(stdin);
				system("CLS");
				ret = usi;
				flg++;
				break;
		case 4: fflush(stdin);
				system("CLS");
				ret = usi;
				flg++;
				break;
		default: system("CLS");
				printf("Opcion Invalida;\nPor favor, introduzca un numero que aparezca en el menu\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
				getch();
	}
	
	}
	return ret;
}

int carscr(sqlite3* db){ //DB + int
	int flg = 0;
	int usi;
	int ret = 1;
	char buffer[3];
	while(flg == 0){
	fflush(stdin);
	system("CLS");
	printf("Cliente de Admin. Local\n");
	printf("[MENU COCHES]\n");
	printf("[1] Visualizar\n"); 
	printf("[2] Imprimir\n"); //Lista entetera de coches [id,marca,modelo] a fichero coche.txt
	printf("[3] Anyadir\n");
	printf("[4] Modificar\n");
	printf("[5] Eliminar\n");
	printf("[0] Vuelta\n");
	printf("Introduzca su seleccion:\n");
	fgets(buffer,3,stdin);
	sscanf(buffer, "%d", &usi);
	switch(usi){
		case 0: fflush(stdin);
				system("CLS");
				ret = usi;
				flg++;
				break;
		case 1: 
				
				break;
		case 2: 
				break;
		case 3: 
				break;
		case 4: 
				break;
		case 5: 
				break;
		default: system("CLS");
				printf("Opcion Invalida;\nPor favor, introduzca un numero que aparezca en el menu\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
				getch();
	}
}
	return ret;
}

int prcscr(sqlite3* db){ //DB + int
	int flg = 0;
	int ret = 1;
	char buffer[3];
	int usi;
	while(flg == 0){
	fflush(stdin);
	system("CLS");
	printf("Cliente de Admin. Local\n");
	printf("[MENU COMPRAS]\n");
	printf("[1] Visualizar\n"); //25 mas recientes
	printf("[2] Imprimir\n"); //Lista entera de compras [id,idUC,idUV,idC,fecha,precio]
	printf("[0] Vuelta\n");
	printf("Introduzca su seleccion:\n");
	fgets(buffer,3,stdin);
	sscanf(buffer, "%d", &usi);
	switch(usi){
		case 0: fflush(stdin);
				system("CLS");
				ret = usi;
				flg++;
				break;
		case 1: 
				break;
		case 2: 
				break;
		case 3: 
				break;
		default: system("CLS");
				printf("Opcion Invalida;\nPor favor, introduzca un numero que aparezca en el menu\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
				getch();
	}
	return ret;
}}

int slsscr(sqlite3* db){ //DB + int
	int flg = 0;
	int ret = 1;
	char buffer[3];
	int usi;
	while(flg == 0){
	fflush(stdin);
	system("CLS");
	printf("Cliente de Admin. Local\n");
	printf("[MENU VENTAS]\n");
	printf("[1] Visualizar\n"); //25 mas recientes
	printf("[2] Imprimir\n"); //Lista entera de compras [id,idUC,idUV,idC,fecha,precio]
	printf("[3] Importar\n");
	printf("[4] Modificar\n");
	printf("[5] Eliminar\n");
	printf("[0] Vuelta\n");
	printf("Introduzca su seleccion:\n");
	fgets(buffer,3,stdin);
	sscanf(buffer, "%d", &usi);
	switch(usi){
		case 0: fflush(stdin);
				system("CLS");
				ret = usi;
				flg++;
				break;
		case 1: 
				break;
		case 2: 
				break;
		case 3: 
				break;
		case 4: 
				break;
		case 5: 
				break;
		default: system("CLS");
				printf("Opcion Invalida;\nPor favor, introduzca un numero que aparezca en el menu\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
				getch();
	}
	return ret;
}}

int usrscr(sqlite3* db){ //DB + int
	int ret;
	int flg = 0;
	int flg2 = 1;
	char buffer[3];
	int usi;
	while(flg == 0){
		fflush(stdin);
		system("CLS");
		flg2 = 1;
		printf("Cliente de Admin. Local\n");
		printf("[MENU USUARIOS]\n");
		printf("[1] Visualizar\n");
		printf("[2] Imprimir\n");
		printf("[3] Anyadir\n");
		printf("[4] Modificar\n");
		printf("[5] Eliminar\n");
		printf("[0] Vuelta\n");
		printf("Introduzca su seleccion:\n");
		fgets(buffer,3,stdin);
		sscanf(buffer, "%d", &usi);
		switch(usi){
			case 0:	fflush(stdin);
					system("CLS");
					ret = usi;
					flg++;
					break;
			case 1: visualizarUsuarios(db);
					break;
			case 2: imprimirUsuarios(db);
					break;
			case 3: while(flg2 == 1){
					flg2 = usrcrtscr(db);
					}
					break;
			case 4: while(flg2 == 1){
						flg2 = usmodscr(db);
					}
					break;
			case 5: while(flg2 == 1){
						flg2 = usrdltscr(db);
					}
					break;
			default: system("CLS");
					printf("Opcion Invalida;\nPor favor, introduzca un numero que aparezca en el menu\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR]\n");
					getch();
		}
	}
	return ret;
}
