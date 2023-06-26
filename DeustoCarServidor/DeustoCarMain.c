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
			case 2: imprimirUsuario(db);
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

//prueba2


