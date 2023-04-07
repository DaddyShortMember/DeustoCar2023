#include <stdio.h>
#include <stdlib.h>
#include "coche.h"
#include "usuario.h"
#include "admin.h"
#include "sqlite3.h"
#include "BD.h"

//gcc coche.c BD.c DeustoCarMain.c usuario.c sqlite3.c -o DeustoCar.exe

/*
void login(void);
void menuPrincip(void);
void menuVis(void);
void menuAdd(void);
void menuDel(void);
void menuMod(void);
*/

int main(void){
	//login();

	return 0;
};

/*
void login(void){
	system("CLS");
	int tick = 99;
	Admin a;
	int check;
	//int count = 0; metodo de seguridad para complicar/embellecer el programa: si llega a 3, se cierra el programa.
	do{
		//principio
		printf("[DeustoCar]\n");
		printf("[Admin. Local]\n\n");
		printf("Introduce una contrasenya: ");
		fflush(stdout);
		fflush(stdin);
		fgets(a.contrasenya, sizeof(Admin), stdin);
		sscanf(get, "%s", a.contrasenya);
		system("CLS");
		//back-end
		check = verificarAdmin(a);
		if check == 1
			tick++;
		else{
			system("CLS");
			printf("Administrador no encontrado\nPulse cualquier tecla para volver a intentar.");
			getch();
			system("CLS");
		}
	}while(tick == 99);
	menuPrincip();
}

void menuPrincip(void){
	char get[2] = "";
	int opcion = 0;
	int tick = 10;
	system("CLS");
	printf("\n[MENÚ ADMIN]\n");
	printf(" \n");
	printf("[1. Ver Datos]\n");
	printf("[2. Modificar Datos]\n");
	printf("[3. Subir Datos]\n");
	printf("[4. Eliminar Datos]\n");
	printf("[0. Salir]\n");
	printf("Selecciona una opción: ");
	fflush(stdout);
	fflush(stdin);
	fgets(get, 2, stdin);
	sscanf(get, "%d", &opcion);
	//switch
}

void menuVis(void){
	char get[2] = "";
	int opcion = 0;
	int tick = 10;
	system("CLS");
	printf("\n[Menu de Visualizacion]\n");
	printf(" \n");
	printf("[1. Ver Lista General de Vehiculos]\n");
	printf("[2. Ver Lista General de Usuarios]\n");
	printf("[3. Buscar Vehiculo Especifico]\n");
	printf("[4. Buscar Usuario Especifico]\n");
	printf("[0. Salir]\n");
	printf("Selecciona una opción: ");
	fflush(stdout);
	fflush(stdin);
	fgets(get, 2, stdin);
	sscanf(get, "%d", &opcion);
	//switch
}

void menuDel(void){
	char get[2] = "";
	int opcion = 0;
	int tick = 10;
	system("CLS");
	printf("\n[Menu de Eliminacion]\n");
	printf(" \n");
	printf("[1. Eliminar Usuario]\n");
	printf("[2. Eliminar Vehiculo]\n");
	printf("[0. Salir]\n");
	printf("Selecciona una opción: ");
	fflush(stdout);
	fflush(stdin);
	fgets(get, 2, stdin);
	sscanf(get, "%d", &opcion);
	//switch

void menuMod(void){
	char get[2] = "";
	int opcion = 0;
	int tick = 10;
	system("CLS");
	printf("\n[Menu de Modificacion]\n");
	printf(" \n");
	printf("[1. Modificar Usuario]\n");
	printf("[2. Modificar Vehiculo]\n");
	printf("[0. Salir]\n");
	printf("Selecciona una opción: ");
	fflush(stdout);
	fflush(stdin);
	fgets(get, 2, stdin);
	sscanf(get, "%d", &opcion);
}

	return 0;
};
*/
