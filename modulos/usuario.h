#ifndef _USUARIO_H_
#define _USUARIO_H_

typedef struct{
	int idUsuario;
	char* nombre;
	char* mail;
	char* pass;
	int saldo;
}Usuario;

//Obtienen los datos de la BD
int getUserid(void);
char* getNombre(void);
char* getMail(void);
//char* getPass(void);? Diria que no, que me parece una vulnerabilidad bastante irresponsable. Iwal se compara la contra directamente en la BD (luego de sanitizar el input del ususuario, of  course)
int getSaldo(void);

//Crean los datos en la BD
void setNombre(char* nom);
void setPass(char* pas);
void setMail(char* mai);
void setSaldo(int saldo);

#endif
