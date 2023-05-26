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


    f = fopen("fichero.txt", "r");

   //falta codigo

    fclose(f);



    Admin a;
    strcpy(a.nUsuario, nombreUsuario);
    strcpy(a.password, contrasena);

    return a;
}

