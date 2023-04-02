#include "admin.h"
#include "coche.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10
#define MAX_LINE 10

Coche crearAutomovil(){

	Coche *c = (Coche*) malloc(sizeof(Coche));

	//Hay que sacar de la BD los coches y recorrerlos para poner el id
	//int id;

	printf("Introduce la marca del coche");
	fflush(stdout);
	char *linea[MAX_LINE];
	fgets(linea, MAX_LINE, stdin);
	//sscanf(linea, "%i", &id);
	clearIfNeeded(linea, MAX_LINE);
	//char* marca;
	printf("Introduce el modelo del coche");
	//char* modelo;

	c = {};

	return c;
};

	// Función para modificar un objeto de la estructura Coche
	Coche modificarAutomovil() {
	    // Pedimos al usuario que introduzca el id del automóvil a modificar
	    printf("Introduce el id del automóvil que quieres modificar: ");
	    int id;
	    scanf("%d", &id);

	    // Buscamos el automóvil en la base de datos y lo mostramos al usuario para que pueda modificarlo
	    //sqlite3 *db;
	 //   int rc = sqlite3_open("base_de_datos.db", &db);
	   // if (rc) {
	     //   fprintf(stderr, "No se pudo abrir la base de datos: %s\n", sqlite3_errmsg(db));
	      //  sqlite3_close(db);
	        Coche coche_vacio = {0};
	        return coche_vacio; // Devolvemos un objeto vacío si no se pudo abrir la base de datos
	    }
	    char sql[100];
	  //  sprintf(sql, "SELECT * FROM coche WHERE  WHERE id=%d;", id);
    char *error_msg;
    Coche coche_modificado = {0};
  //  rc = sqlite3_exec(db, sql, callback, &coche_modificado, &error_msg);
   // if (rc != SQLITE_OK) {
       // fprintf(stderr, "Error al ejecutar la consulta: %s\n", error_msg);
       // sqlite3_free(error_msg);
      //  sqlite3_close(db);
      //  return coche_modificado; // Devolvemos un objeto vacío si no se pudo ejecutar la consulta
    }

    // Si no se encontró el automóvil con el id indicado, devolvemos un objeto vacío
    if (coche_modificado.id == 0) {
        printf("No se encontró ningún automóvil con el id %d.\n", id);
        sqlite3_close(db);
        return coche_modificado;
    }

    // Mostramos al usuario el automóvil a modificar y le pedimos que introduzca los nuevos datos
  //*  printf("Automóvil a modificar:\n");
    printf("ID: %d\n", coche_modificado.id);
    printf("Marca: %s\n", coche_modificado.marca);
    printf("Modelo: %s\n", coche_modificado.modelo);

    printf("Introduce los nuevos datos:\n");
    printf("Marca: ");
    scanf("%s", coche_modificado.marca);
    printf("Modelo: ");
    scanf("%s", coche_modificado.modelo);
    // Actualizamos el objeto en la base de datos
   // sprintf(sql, "UPDATE coches SET marca='%s', modelo='%s' ", coche_modificado.marca, coche_modificado.modelo, coche_modificado.id);
  //  execute_sql(db, sql);
   // sqlite3_close(db);

    return coche_modificado;
}
  //*

void visualizarAutomovil(){

};
void eliminarAutomovil(){

};
void crearUsuario(){

};
Usuario modificarUsuario(){

};
void visualizarUsuario(){

};
void eliminarUsuario(){

};

int main(void)
{

	FILE* f;
        char c;

	int num_lines = 0;

	//abrir fichero para lectura
	f = fopen("prueba.txt", "r");

	//leer mientras no se llegue al final del fichero EOF
	while ((c = fgetc(f)) != EOF)
	{
		if (c == '\n')
			num_lines++;
		putchar(c);
	}
	//cerrar fichero
	fclose(f);

	printf("El fichero tiene %i líneas\n", num_lines);

	return 0;
}
