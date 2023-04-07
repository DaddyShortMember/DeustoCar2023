
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "coche.h"
#include "admin.h"
#include "BD.h"
#include "sqlite3.h"
#include <winsock2.h>
#include <math.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

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

	admin = readConfigFile();
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
		strcpy(usuario.email, "correoUsuario@gmail.com");
		strcpy(usuario.saldo, "500");
		strcpy(usuario.contrasenya, "lac0ntrasenya");
		strcpy(usuario.nombre, "Nombre");


		//Usuario de prueba 2
		Usuario usuario2;

		usuario2.id = codigoUsuarioPorDefecto;
		strcpy(usuario2.email, "correoUsuario2@gmail.com");
		strcpy(usuario2.saldo, "1000");
		strcpy(usuario2.contrasenya, "contrasenya2");
		strcpy(usuario2.nombre, "Jon");


		//Usuario de prueba 3
		Usuario usuario3;

		usuario3.id = codigoUsuarioPorDefecto;
		strcpy(usuario3.email, "correoUsuario3@gmail.com");
		strcpy(usuario3.saldo, "300");
		strcpy(usuario3.contrasenya, "XXXasdfXXX3451");
		strcpy(usuario3.nombre, "Alvaro");


		//Usuario de prueba 4
		Usuario usuario4;

		usuario4.id = codigoUsuarioPorDefecto;
		strcpy(usuario4.email, "correoUsuario4@gmail.com");
		strcpy(usuario4.saldo, "1500");
		strcpy(usuario4.contrasenya, "1234Alba1234");
		strcpy(usuario4.nombre, "Alba");


		//Usuario de prueba 5
		Usuario usuario5;

		usuario5.id = codigoUsuarioPorDefecto;
		strcpy(usuario5.email, "correoUsuario5@gmail.com");
		strcpy(usuario5.saldo, "360");
		strcpy(usuario5.contrasenya, "87329Lpow65");
		strcpy(usuario5.nombre, "Luis");


		//Usuario de prueba 6
		Usuario usuario6;

		usuario6.id = codigoUsuarioPorDefecto;
		strcpy(usuario6.email, "correoUsuario6@gmail.com");
		strcpy(usuario6.saldo, "700");
		strcpy(usuario6.contrasenya, "NoTengoContrasenya");
		strcpy(usuario6.nombre, "Patricia");


		//Usuario de prueba 7
		Usuario usuario7;

		usuario7.id = codigoUsuarioPorDefecto;
		strcpy(usuario7.email, "correoUsuario7@gmail.com");
		strcpy(usuario7.saldo, "950");
		strcpy(usuario7.contrasenya, "contrasenya1");
		strcpy(usuario7.nombre, "Diego");


		//Usuario de prueba 8
		Usuario usuario8;

		usuario8.id = codigoUsuarioPorDefecto;
		strcpy(usuario8.email, "correoUsuario8@gmail.com");
		strcpy(usuario8.saldo, "200");
		strcpy(usuario8.contrasenya, "NeretxU99");
		strcpy(usuario8.nombre, "Nerea");


		//Usuario de prueba 9
		Usuario usuario9;

		usuario9.id = codigoUsuarioPorDefecto;
		strcpy(usuario9.email, "correoUsuario9@gmail.com");
		strcpy(usuario9.saldo, "560");
		strcpy(usuario9.contrasenya, "lac0ntrasenya");
		strcpy(usuario9.nombre, "Alvaro");


		//Coche de prueba
		Coche coche;

		coche.id = codigoCochePorDefecto;
		coche.marca = 20;
		coche.modelo = 10;
		strcpy(coche.marca, "Seat");
		strcpy(coche.modelo, "Ibiza");


		//Coche de prueba 2
		Coche coche2;

		coche2.id = codigoCochePorDefecto;
		coche2.marca = 2;
		coche2.modelo = 5;
		strcpy(coche2.marca, "Audi");
		strcpy(coche2.modelo, "R8");


		//Coche de prueba 3
		Coche coche3;

		coche3.id = codigoCochePorDefecto;
		coche3.marca = 250;
		coche3.modelo = 75;
		strcpy(coche3.marca, "Bmw");
		strcpy(coche3.modelo, "E46");


		//Coche de prueba 4
		Coche coche4;

		coche4.id = codigoCochePorDefecto;
		coche4.marca = 400;
		coche4.modelo = 250;
		strcpy(coche4.marca, "Audi");
		strcpy(coche4.modelo, "TT");


		//Coche de prueba 5
		Coche coche5;

		coche5.id = codigoCochePorDefecto;
		coche5.marca = 50;
		coche5.modelo = 50;
		strcpy(coche5.marca, "Seat");
		strcpy(coche5.modelo, "Leon");


		//Coche de prueba 6
		Coche coche6;

		coche6.id = codigoCochePorDefecto;
		coche6.marca = 5;
		coche6.modelo = 4;
		strcpy(coche6.marca, "Bmw");
		strcpy(coche6.modelo, "E36");


		//Coche de prueba 7
		Coche coche7;

		coche7.id = codigoCochePorDefecto;
		coche7.marca = 2;
		coche7.modelo = 4;
		strcpy(coche7.marca, "Seat");
		strcpy(coche7.modelo, "Cupra");


		//Coche de prueba 8
		Coche coche8;

		coche8.id = codigoCochePorDefecto;
		coche8.marca = 4;
		coche8.modelo = 3;
		strcpy(coche8.marca, "Audi");
		strcpy(coche8.modelo, " A3");


		//Coche de prueba 9
		Coche coche9;

		coche9.id = codigoCochePorDefecto;
		coche9.marca = 3;
		coche9.modelo = 5;
		strcpy(coche9.marca, "Audi");
		strcpy(coche9.modelo, "A1");

		//Coche de prueba 10
		Coche coche10;

		coche10.id = codigoCochePorDefecto;
		coche10.marca = 6;
		coche10.modelo = 10;
		strcpy(coche10.marca, "GOLF");
		strcpy(coche10.modelo, "GTI");


		eliminarUsuarios(db, result);
		eliminarCoches(db, result);
		anyadirUsuario(db, result, usuario);
		anyadirUsuario(db, result, usuario2);
		anyadirUsuario(db, result, usuario3);
		anyadirUsuario(db, result, usuario4);
		anyadirUsuario(db, result, usuario5);
		anyadirUsuario(db, result, usuario6);
		anyadirUsuario(db, result, usuario7);
		anyadirUsuario(db, result, usuario8);
		anyadirUsuario(db, result, usuario9);
		anyadirCoches(db, result, coche);
		anyadirCoches(db, result, coche2);
		anyadirCoches(db, result, coche3);
		anyadirCoches(db, result, coche4);
		anyadirCoches(db, result, coche5);
		anyadirCoches(db, result, coche6);
		anyadirCoches(db, result, coche7);
		anyadirCoches(db, result, coche8);
		anyadirCoches(db, result, coche9);
		anyadirCoches(db, result, coche10);
		/*//Para probar si los datos entran como deben en la BD
		imprimirUsuarios(db);
		imprimirCoches(db);*/

		WSADATA wsaData;
		SOCKET conn_socket;
		SOCKET comm_socket;
		struct sockaddr_in server;
		struct sockaddr_in client;
		char sendBuff[512], recvBuff[512];

		printf("\nInitialising Winsock...\n");

		f = fopen("log.txt", "a");
		if (fopen("log.txt", "a") == NULL) {
			printf("Error al abrir el fichero de log\n");
		} else {
			fprintf(f, "Inicializando Winsock\n");
		}
		fclose(f);

		if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {

			f = fopen("log.txt", "a");
			if (fopen("log.txt", "a") == NULL) {
				printf("Error al abrir el fichero de log\n");
			} else {
				fprintf(f, "Error al inicializar Winsock\n");
			}
			fclose(f);

			printf("Failed. Error Code : %d", WSAGetLastError());
			return -1;
		}

		f = fopen("log.txt", "a");
		if (fopen("log.txt", "a") == NULL) {
			printf("Error al abrir el fichero de log\n");
		} else {
			fprintf(f, "Winsock inicializado\n");
		}
		fclose(f);

		printf("Initialised.\n");

		//SOCKET creation
		if ((conn_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {

			f = fopen("log.txt", "a");
			if (fopen("log.txt", "a") == NULL) {
				printf("Error al abrir el fichero de log\n");
			} else {
				fprintf(f, "No se ha podido crear el socket\n");
			}
			fclose(f);

			printf("Could not create socket : %d", WSAGetLastError());
			WSACleanup();
			return -1;
		}

		f = fopen("log.txt", "a");
		if (fopen("log.txt", "a") == NULL) {
			printf("Error al abrir el fichero de log\n");
		} else {
			fprintf(f, "Socket creado\n");
		}
		fclose(f);

		printf("Socket created.\n");

		server.sin_addr.s_addr = inet_addr(SERVER_IP);
		server.sin_family = AF_INET;
		server.sin_port = htons(SERVER_PORT);

		//BIND (the IP/port with socket)
		if (bind(conn_socket, (struct sockaddr*) &server, sizeof(server)) == SOCKET_ERROR) {

			f = fopen("log.txt", "a");
			if (fopen("log.txt", "a") == NULL) {
				printf("Error al abrir el fichero de log\n");
			} else {
				fprintf(f, "Fallo en el bind\n");
			}
			fclose(f);

			printf("Bind failed with error code: %d", WSAGetLastError());
			closesocket(conn_socket);
			WSACleanup();
			return -1;
		}

		f = fopen("log.txt", "a");
		if (fopen("log.txt", "a") == NULL) {
			printf("Error al abrir el fichero de log\n");
		} else {
			fprintf(f, "Bind hecho\n");
		}
		fclose(f);

		printf("Bind done.\n");

		//LISTEN to incoming connections (socket server moves to listening mode)
		if (listen(conn_socket, 1) == SOCKET_ERROR) {

			f = fopen("log.txt", "a");
			if (fopen("log.txt", "a") == NULL) {
				printf("Error al abrir el fichero de log\n");
			} else {
				fprintf(f, "Fallo al escuchar\n");
			}
			fclose(f);

			printf("Listen failed with error code: %d", WSAGetLastError());
			closesocket(conn_socket);
			WSACleanup();
			return -1;
		}

		//ACCEPT incoming connections (server keeps waiting for them)

		f = fopen("log.txt", "a");
		if (fopen("log.txt", "a") == NULL) {
			printf("Error al abrir el fichero de log\n");
		} else {
			fprintf(f, "Esperando conexiones\n");
		}
		fclose(f);

		printf("Waiting for incoming connections...\n");
		int stsize = sizeof(struct sockaddr);
		comm_socket = accept(conn_socket, (struct sockaddr*) &client, &stsize);
		// Using comm_socket is able to send/receive data to/from connected client
		if (comm_socket == INVALID_SOCKET) {

			f = fopen("log.txt", "a");
			if (fopen("log.txt", "a") == NULL) {
				printf("Error al abrir el fichero de log\n");
			} else {
				fprintf(f, "Fallo al aceptar\n");
			}
			fclose(f);

			printf("accept failed with error code : %d", WSAGetLastError());
			closesocket(conn_socket);
			WSACleanup();
			return -1;
		}

		f = fopen("log.txt", "a");
		if (fopen("log.txt", "a") == NULL) {
			printf("Error al abrir el fichero de log\n");
		} else {
			fprintf(f, "Estableciendo la conexion\n");
		}
		fclose(f);

		printf("Incomming connection from: %s (%d)\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

		// Closing the listening sockets (is not going to be used anymore)

		f = fopen("log.txt", "a");
		if (fopen("log.txt", "a") == NULL) {
			printf("Error al abrir el fichero de log\n");
		} else {
			fprintf(f, "Cerrando el escuchador\n");
		}
		fclose(f);

		closesocket(conn_socket);

		//SEND and RECEIVE data (CLIENT/SERVER PROTOCOL)

		f = fopen("log.txt", "a");
		if (fopen("log.txt", "a") == NULL) {
			printf("Error al abrir el fichero de log\n");
		} else {
			fprintf(f, "Esperando los comandos del cliente\n");
		}
		fclose(f);

		printf("Waiting for incoming commands from client... \n");
		while (1)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);

			//printf("Command received: %s \n", recvBuff);

			Usuario u; Coche c;

			if (strcmp(recvBuff, "ANYADIRUSUARIO") == 0)
			{

				f = fopen("log.txt", "a");
				if (fopen("log.txt", "a") == NULL) {
					printf("Error al abrir el fichero de log\n");
				} else {
					fprintf(f, "Anyadiendo usuario\n");
				}
				fclose(f);

				int contador = 0;
				recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
				while (strcmp(recvBuff, "ANYADIRUSUARIO-END") != 0)
				{
					contador++;
					if (contador == 1) {
						u.id = atoi(recvBuff);

						f = fopen("log.txt", "a");
						if (fopen("log.txt", "a") == NULL) {
							printf("Error al abrir el fichero de log\n");
						} else {
							fprintf(f, "Anyadido codigo de usuario al nuevo usuario\n");
						}
						fclose(f);
					}
					if (contador == 2) {
						strcpy(u.email, recvBuff);

						f = fopen("log.txt", "a");
						if (fopen("log.txt", "a") == NULL) {
							printf("Error al abrir el fichero de log\n");
						} else {
							fprintf(f, "Anyadido email al nuevo usuario\n");
						}
						fclose(f);
					}
					if (contador == 3) {
						strcpy(u.nombre, recvBuff);

						f = fopen("log.txt", "a");
						if (fopen("log.txt", "a") == NULL) {
							printf("Error al abrir el fichero de log\n");
						} else {
							fprintf(f, "Anyadido nombre al nuevo usuario\n");
						}
						fclose(f);
					}
					if (contador == 4) {
						strcpy(u.contrasenya, recvBuff);

						f = fopen("log.txt", "a");
						if (fopen("log.txt", "a") == NULL) {
							printf("Error al abrir el fichero de log\n");
						} else {
							fprintf(f, "Anyadida contrasenya al nuevo usuario\n");
						}
						fclose(f);
					}

					if (contador == 5) {
						strcpy(u.saldo, recvBuff);

						f = fopen("log.txt", "a");
						if (fopen("log.txt", "a") == NULL) {
							printf("Error al abrir el fichero de log\n");
						} else {
							fprintf(f, "Anyadido saldo al nuevo usuario\n");
						}
						fclose(f);
					}

					recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
				}
				anyadirUsuario(db, result, u);

				f = fopen("log.txt", "a");
				if (fopen("log.txt", "a") == NULL) {
					printf("Error al abrir el fichero de log\n");
				} else {
					fprintf(f, "Usuario anyadido\n");
				}
				fclose(f);

				imprimirUsuarios(db);
			}

			if (strcmp(recvBuff, "ANYADIRCOCHE") == 0)
			{
				f = fopen("log.txt", "a");
				if (fopen("log.txt", "a") == NULL) {
					printf("Error al abrir el fichero de log\n");
				} else {
					fprintf(f, "Anyadiendo coche\n");
				}
				fclose(f);

				int contador = 0;
				recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
				while (strcmp(recvBuff, "ANYADIRCOCHE-END") != 0)
				{
					contador++;

					if (contador == 1) {
						c.id = atoi(recvBuff);

						f = fopen("log.txt", "a");
						if (fopen("log.txt", "a") == NULL) {
							printf("Error al abrir el fichero de log\n");
						} else {
							fprintf(f, "Anyadiendo codigo de coche a el nuevo coche\n");
						}
						fclose(f);
					}
					if (contador == 2) {
						c.id = atoi(recvBuff);

						f = fopen("log.txt", "a");
						if (fopen("log.txt", "a") == NULL) {
							printf("Error al abrir el fichero de log\n");
						} else {
							fprintf(f, "Anyadiendo codigo de coche a el nuevo coche\n");
						}
						fclose(f);
					}
					if (contador == 3) {
						c.id = atoi(recvBuff);

						f = fopen("log.txt", "a");
						if (fopen("log.txt", "a") == NULL) {
							printf("Error al abrir el fichero de log\n");
						} else {
							fprintf(f, "Anyadiendo codigo de coche a el nuevo coche\n");
						}
						fclose(f);
					}
					if (contador == 4) {
						c.importeTotal = atoi(recvBuff);

						f = fopen("log.txt", "a");
						if (fopen("log.txt", "a") == NULL) {
							printf("Error al abrir el fichero de log\n");
						} else {
							fprintf(f, "Anyadiendo precio total al coche nuevo\n");
						}
						fclose(f);
					}

					recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
				}
				insertCoche(db, c.id, c.modelo, c.marca);

				f = fopen("log.txt", "a");
				if (fopen("log.txt", "a") == NULL) {
					printf("Error al abrir el fichero de log\n");
				} else {
					fprintf(f, "Anyadido nuevo coche\n");
				}
				fclose(f);

				imprimirCoches(db);
			}

			if (strcmp(recvBuff, "GETUSUARIOS") == 0)
			{
				f = fopen("log.txt", "a");
				if (fopen("log.txt", "a") == NULL) {
					printf("Error al abrir el fichero de log\n");
				} else {
					fprintf(f, "Cargando usuarios\n");
				}
				fclose(f);

				recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
				if (strcmp(recvBuff, "GETUSUARIOS-END") == 0);

				f = fopen("log.txt", "a");
				if (fopen("log.txt", "a") == NULL) {
					printf("Error al abrir el fichero de log\n");
				} else {
					fprintf(f, "Error al cargar usuarios\n");
				}
				fclose(f);

				Usuario *usuarios = (Usuario*) malloc(50 * sizeof(Usuario));
				usuarios = getUsuarios(db);

				int i = 0;
				for (i = 0; i < 50; i++) {
					if (usuarios[i].id != 0) {
						sprintf(sendBuff, "%d", usuarios[i].id);
						send(comm_socket, sendBuff, sizeof(sendBuff), 0);
						printf("Response sent: %s \n", sendBuff);
						sprintf(sendBuff, "%s", usuarios[i].email);
						send(comm_socket, sendBuff, sizeof(sendBuff), 0);
						printf("Response sent: %s \n", sendBuff);
						sprintf(sendBuff, "%s", usuarios[i].nombre);
						send(comm_socket, sendBuff, sizeof(sendBuff), 0);
						printf("Response sent: %s \n", sendBuff);
						sprintf(sendBuff, "%s", usuarios[i].contrasenya);
						send(comm_socket, sendBuff, sizeof(sendBuff), 0);
						printf("Response sent: %s \n", sendBuff);
						sprintf(sendBuff, "%s", usuarios[i].nombre);
						send(comm_socket, sendBuff, sizeof(sendBuff), 0);
						printf("Response sent: %s \n", sendBuff);
						sprintf(sendBuff, "%s", usuarios[i].saldo);
						send(comm_socket, sendBuff, sizeof(sendBuff), 0);
						printf("Response sent: %s \n", sendBuff);
					} else {
						i = 50;
						sprintf(sendBuff, "%s", "FINBUCLE");
						send(comm_socket, sendBuff, sizeof(sendBuff), 0);
					}
				}

				f = fopen("log.txt", "a");
				if (fopen("log.txt", "a") == NULL) {
					printf("Error al abrir el fichero de log\n");
				} else {
					fprintf(f, "Usuarios cargados correctamente\n");
				}
				fclose(f);

			}

			if (strcmp(recvBuff, "GETCOCHES") == 0)
			{
				f = fopen("log.txt", "a");
				if (fopen("log.txt", "a") == NULL) {
					printf("Error al abrir el fichero de log\n");
				} else {
					fprintf(f, "Cargando coches\n");
				}
				fclose(f);

				recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
				if (strcmp(recvBuff, "GETCOCHES-END") == 0);

				f = fopen("log.txt", "a");
				if (fopen("log.txt", "a") == NULL) {
					printf("Error al abrir el fichero de log\n");
				} else {
					fprintf(f, "Error al cargar coches\n");
				}
				fclose(f);

				Coche *coches = (Coche*) malloc(50 * sizeof(Coche));
				//coches = getCoches(db); NO EXISTE ESTA FUNCION AUN

				int i = 0;
				for (i = 0; i < 50; i++) {
					if (coches[i].id != 0) {
						sprintf(sendBuff, "%d", coches[i].id);
						send(comm_socket, sendBuff, sizeof(sendBuff), 0);
						printf("Response sent: %s \n", sendBuff);
						sprintf(sendBuff, "%s", coches[i].modelo);
						send(comm_socket, sendBuff, sizeof(sendBuff), 0);
						printf("Response sent: %s \n", sendBuff);
						sprintf(sendBuff, "%s", coches[i].marca);
						send(comm_socket, sendBuff, sizeof(sendBuff), 0);
						printf("Response sent: %s \n", sendBuff);
					} else {
						i = 50;
						sprintf(sendBuff, "%s", "FINBUCLE");
						send(comm_socket, sendBuff, sizeof(sendBuff), 0);
					}
				}

				f = fopen("log.txt", "a");
				if (fopen("log.txt", "a") == NULL) {
					printf("Error al abrir el fichero de log\n");
				} else {
					fprintf(f, "Coches cargadas correctamente\n");
				}
				fclose(f);

			}

				f = fopen("log.txt", "a");
				if (fopen("log.txt", "a") == NULL) {
					printf("Error al abrir el fichero de log\n");
				} else {
					fprintf(f, "Coches cargados correctamente\n");
				}
				fclose(f);

			}

			if (strcmp(recvBuff, "DELETECOCHE") == 0)
			{
				f = fopen("log.txt", "a");
				if (fopen("log.txt", "a") == NULL) {
					printf("Error al abrir el fichero de log\n");
				} else {
					fprintf(f, "Eliminando coche\n");
				}
				fclose(f);

				recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
				//deleteCoche(db, recvBuff);

				f = fopen("log.txt", "a");
				if (fopen("log.txt", "a") == NULL) {
					printf("Error al abrir el fichero de log\n");
				} else {
					fprintf(f, "Coche eliminado\n");
				}
				fclose(f);
			}
		}

		// CLOSING the sockets and cleaning Winsock...

		f = fopen("log.txt", "a");
		if (fopen("log.txt", "a") == NULL) {
			printf("Error al abrir el fichero de log\n");
		} else {
			fprintf(f, "Cerrando socket y limpiando Winsock\n");
			fprintf(f, "\n------------------------------------------------------------------------------\n\n");
		}
		fclose(f);

		closesocket(comm_socket);
		WSACleanup();

		result = sqlite3_close(db);
		if (result != SQLITE_OK) {
			printf("Error closing database\n");
			printf("%s\n", sqlite3_errmsg(db));
		}

		printf("Database closed\n");

		return 0;
	} else {
		printf("Acceso denegado al servidor.");
		return 0;
	}
}

