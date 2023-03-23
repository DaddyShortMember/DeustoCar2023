#include <stdio.h>
#include <stdlib.h>

void programBegin(void);
void manual(void);
void clienteAdmin(void);
//Tutorial interactivo? Si hay tiempo, se puede. Una idea para dar mas funcionalidad al programa.

int main(void){
	programBegin();
	
}

void programBegin(void){
	printf("[DeustoCar V0.0]\n");
	printf("[Cliente de Admin. Local]\n");
	printf("[PULSAR CUALQUIER TECLA PARA CONTINUAR]\n");
	getch();
	system("CLS");
	//BD Check, if(exists =! TRUE) -> inicializa, else -> menu
	printf("[DeustoCar V0.0]\n");
	printf("[Cliente de Admin. Local]\n");
	printf("1. Iniciar Sesion\n");
	//ClienteAdmin()
	printf("2. Manual de Uso\n");
	//manual()
	printf("3. Finalizar Programa\n");
	//exit();
	getch(); //cambiar a scanf() y poner switch (o if-else if-else, pero eso no queda muy guapo)
}