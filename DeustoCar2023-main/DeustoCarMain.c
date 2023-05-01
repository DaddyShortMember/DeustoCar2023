#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*
#include "usuario.h"
#include "coche.h"
#include "admin.h"
#include "venta.h"
#include "compra.h"
#include "BD.h"
#include "sqlite3.h"
*/



void lgscr(void); //menu de inicio de sesion
void mmenu(void); //menu principal
void carscr(void);//menu de visualizacion/modificacion sobre: coche
void prcscr(void);//menu de visualizacion/modificacion sobre: compra
void slsscr(void);//menu de visualizacion/modificacion sobre: venta
void usrscr(void);//menu de visualizacion/modificacion sobre: usuario
void cfgscr(void);//menu de configuracion; permite modificar ciertos parametros
/* Ideas de parametros:
[para mas libertad de configuracion]
-extension de fichero de log (si se guarda como .txt, o como .log, o como el admin prefiera
[para gestion de memoria fisica]
-control de impresion de log (que se guarda, si todos los pasos, o lo mas importante, o solo errores)
 */
 
 
 //TODO:
 //*Arreglar parte de menus (esta hecho el martes)
 //*Guardar en un fichero .bin o lo que sea las IDs (que concuerden con la BD) de los admins.
 //*Realizar las funciones sobre la BD en la .h y la .c de su respectivo modulo

int main(void)
{

	lgscr();

	
}

void lgscr(void){
	int flg = 0;
	int flg2 = 1;
	int sec = 0;
	char usi[31];
	//RD
	while(flg < 1){
		if(sec == 3)
			exit(1);
	system("CLS");
	printf("Cliente de Admin. Local\n\n\n\n");
	printf("Introduzca su usuario:\n");
	fgets(usi,31,stdin);
	if(usi[0] == '0'){
		sec++;
		fflush(stdin);
	}
	else{
		printf("%s",usi);
		fflush(stdin);
		getch();
		flg++;
	}
	//if usuario no existe: advertencia, else flg2-- && flg3 = 0
	//do-while(flg3 < 1)
	}
	while(flg2 > 0){
		if(sec == 3)
			exit(1);
	system("CLS");
	printf("Cliente de Admin. Local\n\n\n\n");
	printf("Introduzca su contrasenya:\n");
	fgets(usi,31,stdin);
	if(usi[0] == '0'){
		fflush(stdin);
		sec++;
	}
	else{
		printf("%s",usi);
		fflush(stdin);
		flg2--;
		getch();
		mmenu();
	}
	}
	//if usuario.id =! adminID.bin(!!GUARDADO EN FICHERO LOCAL):  advertencia, flg2 = 1 && sec++, else mmenu(); 
	//if sec == 3 (o numero de intentos maximos cualquiera): exit
	exit(1);
}

void mmenu(void){
	int flg = 0;
	char buffer[3]; 
	int usi;
	while(flg == 0){//while flg == 0;
	system("CLS");
	printf("Cliente de Admin. Local\n");
	printf("[MENU PRINCIPAL]\n");
	printf("[1] Usuarios\n");
	printf("[2] Coches\n");
	printf("[3] Ventas\n");
	printf("[4] Compras\n");
	printf("[0] Salida\n");
	fgets(buffer,3,stdin);
	sscanf(buffer, "%d" &usi);
	switch(usi){
		case 0: exit(10);
		case 1: usrscr();
				flg++;
				break;
		case 2: carscr();
				flg++;
				break;
		case 3: slsscr();
				flg++;
				break;
		case 4: prcscr();
				flg++;
				break;
		default: printf("");
		
		
	}
	
	//switch(usi):
	
	}
	//if usi > 4 || < 0: pedir al usuario que vuelva a intentar, else llamar a la funcion correspondiente
	
}

void carscr(void){
	int flg = 0;
	int usi;
	char buffer[3];
	while(flg == 0){
	system("CLS");
	printf("Cliente de Admin. Local\n");
	printf("[MENU COCHES]\n");
	printf("[1] Visualizar\n");
	printf("[2] Exportar\n");
	printf("[3] Importar\n");
	printf("[4] Modificar\n");
	printf("[5] Eliminar\n");
	printf("[0] Vuelta\n");
	fgets(buffer,3,stdin);
	sscanf(buffer, "%d" &usi);
	switch(usi){
		case 0: exit(10);
		case 1: usrscr();
				flg++;
				break;
		case 2: carscr();
				flg++;
				break;
		case 3: slsscr();
				flg++;
				break;
		case 4: prcscr();
				flg++;
				break;
		default: printf("");
	
	}
	//if usi > 5 || < 0: pedir al usuario que vuelva a intentar, else realizar operacion indicada
}

void prcscr(void){
	int flg = 0;
	char buffer[3];
	int usi;
	//while flg == 0;
	while(flg == 0){
	system("CLS");
	printf("Cliente de Admin. Local\n");
	printf("[MENU COMPRAS]\n");
	printf("[1] Visualizar\n");
	printf("[2] Imprimir\n");
	printf("[3] Importar\n"); //?? Posible, posible (Rollback)
	printf("[4] Modificar\n"); //quitar esta opcion
	printf("[5] Eliminar\n"); //quitar esta opcion
	printf("[0] Vuelta\n");
	fgets(buffer,3,stdin);
	sscanf(buffer, "%d" &usi);
	switch(usi){
		case 0: exit(10);
		case 1: usrscr();
				flg++;
				break;
		case 2: carscr();
				flg++;
				break;
		case 3: slsscr();
				flg++;
				break;
		case 4: prcscr();
				flg++;
				break;
		default: printf("");
	}
	//if usi > 3?? || < 0: pedir al usuario que vuelva a intentar, else realizar operacion indicada
}

void slsscr(void){
	int flg = 0;
	char buffer[3];
	int usi;
	//while flg == 0;
	while(flg == 0){
	system("CLS");
	printf("Cliente de Admin. Local\n");
	printf("[MENU VENTAS]\n");
	printf("[1] Visualizar\n");
	printf("[2] Exportar\n");
	printf("[3] Importar\n");
	printf("[4] Modificar\n");
	printf("[5] Eliminar\n");
	printf("[0] Vuelta\n");
	fgets(buffer,3,stdin);
	sscanf(buffer, "%d" &usi);
	switch(usi){
		case 0: exit(10);
		case 1: usrscr();
				flg++;
				break;
		case 2: carscr();
				flg++;
				break;
		case 3: slsscr();
				flg++;
				break;
		case 4: prcscr();
				flg++;
				break;
		default: printf("");
	}
	//if usi > 5 || < 0: pedir al usuario que vuelva a intentar, else realizar operacion indicada
}

void usrscr(void){
	int flg = 0;
	char buffer[3];
	int usi;
	//while flg == 0;
	while(flg == 0){
	system("CLS");
	printf("Cliente de Admin. Local\n");
	printf("[MENU COCHES]\n");
	printf("[1] Visualizar\n");
	printf("[2] Imprimir\n");
	printf("[3] Exportar\n");
	printf("[4] Modificar\n");
	printf("[5] Eliminar\n");
	printf("[0] Vuelta\n");
	fgets(buffer,3,stdin);
	sscanf(buffer, "%d" &usi);
	switch(usi){
		case 0: exit(10);
		case 1: usrscr();
				flg++;
				break;
		case 2: carscr();
				flg++;
				break;
		case 3: slsscr();
				flg++;
				break;
		case 4: prcscr();
				flg++;
				break;
		default: printf("");
	}
	//if usi > 5 || < 0: pedir al usuario que vuelva a intentar, else realizar operacion indicada
}

void cfgscr(void){
	int flg = 0;
	char buffer[3];
	int usi;
	while(flg == 0){
	//while flg == 0;
	system("CLS");
	printf("Cliente de Admin. Local\n");
	printf("[CONFIG]\n");
	printf("[1] Control de Extension de Fichero (PARAMETRO ACTUAL: )\n");
	printf("[2] Control de Nivel de Log (PARAMETRO ACTUAL: )\n");
	printf("[0] Vuelta\n");
	fgets(buffer,3,stdin);
	sscanf(buffer, "%d" &usi);
	switch(usi){
		case 0: exit(10);
		case 1: usrscr();
				flg++;
				break;
		case 2: carscr();
				flg++;
				break;
		case 3: slsscr();
				flg++;
				break;
		case 4: prcscr();
				flg++;
				break;
		default: printf("");
	}
}