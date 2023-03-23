#ifndef _COCHE_H_
#define _COCHE_H_

typedef Struct{
	int idCoche
	char* marca
	char* modelo
}coche;

//Obtienen los datos de la BD
int getCarid(void);
char* getMarca(void);
char* getModelo(void);

//Crean los datos en la BD
void setMarca(char* mar);
void setModelo(char* mol);

#endif