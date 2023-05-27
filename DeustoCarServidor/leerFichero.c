/*
 * leerFichero.c
 *
 *  Created on: 27 may 2023
 *      Author: IGNAC
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leerFichero.h"
#include "Admin.h"

Admin leerFichero() {
    FILE *f;
    //lectura de ficheros caracter a caracter
    char c = '0';
    int pos_car = 0;
    int contador = 0;
    int numero1 = 0, numero2 = 0;

    f = fopen("fichero.txt", "r");

    if (f == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1); // Sale del programa si no se puede abrir el archivo
    }

    char *nombreUsuario = NULL;
    char *contrasena = NULL;
    int tamNombreUsuario = 0;
    int tamContrasena = 0;

    while ((c = fgetc(f)) != EOF) {
        if (c == '\n' && contador == 0) {
            pos_car = 0;
            contador++;
        }

        if (c == '\n' && contador != 0) {
            contador++;
        }

        if (contador == 2 && c != '\n') {
            if (numero1 == tamNombreUsuario) {
                tamNombreUsuario += 10;
                nombreUsuario = (char *)realloc(nombreUsuario, tamNombreUsuario * sizeof(char));
            }
            nombreUsuario[numero1] = c;
            numero1++;
        }

        if (contador == 4 && c != '\n') {
            if (numero2 == tamContrasena) {
                tamContrasena += 10;
                contrasena = (char *)realloc(contrasena, tamContrasena * sizeof(char));
            }
            contrasena[numero2] = c;
            numero2++;
        }

        pos_car++;
    }

    fclose(f);

    // Termina las cadenas con el carácter nulo
    nombreUsuario = (char *)realloc(nombreUsuario, (numero1 + 1) * sizeof(char));
    contrasena = (char *)realloc(contrasena, (numero2 + 1) * sizeof(char));
    nombreUsuario[numero1] = '\0';
    contrasena[numero2] = '\0';

    Admin a;
    strcpy(a.nUsuario, nombreUsuario);
    strcpy(a.password, contrasena);

    // Liberar la memoria asignada
    free(nombreUsuario);
    free(contrasena);

    return a;
}

