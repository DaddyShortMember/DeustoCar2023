/*BORRRAR ESTOS 2 CARACTERES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "coche.h"
#include "admin.h"
#include "BD.h"
#include "sqlite3.h"
#include "ficheros.h"
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
		int codigoVueloPorDefecto = 0;

		//Usuario de prueba
		Usuario usuario;
		usuario.cUsuario = codigoUsuarioPorDefecto;
		strcpy(usuario.email, "correoUsuario@gmail.com");
		strcpy(usuario.dni, "56957653D");
		strcpy(usuario.password, "lac0ntrasenya");
		strcpy(usuario.nombre, "Nombre");
		strcpy(usuario.apellido, "Prueba");

		//Usuario de prueba 2
		Usuario usuario2;

		usuario2.cUsuario = codigoUsuarioPorDefecto;
		strcpy(usuario2.email, "correoUsuario2@gmail.com");
		strcpy(usuario2.dni, "23467893Z");
		strcpy(usuario2.password, "contrasenya2");
		strcpy(usuario2.nombre, "Jon");
		strcpy(usuario2.apellido, "Goikoetxea");

		//Usuario de prueba 3
		Usuario usuario3;

		usuario3.cUsuario = codigoUsuarioPorDefecto;
		strcpy(usuario3.email, "correoUsuario3@gmail.com");
		strcpy(usuario3.dni, "94571388H");
		strcpy(usuario3.password, "XXXasdfXXX3451");
		strcpy(usuario3.nombre, "Alvaro");
		strcpy(usuario3.apellido, "Garcia");

		//Usuario de prueba 4
		Usuario usuario4;

		usuario4.cUsuario = codigoUsuarioPorDefecto;
		strcpy(usuario4.email, "correoUsuario4@gmail.com");
		strcpy(usuario4.dni, "87262155Y");
		strcpy(usuario4.password, "1234Alba1234");
		strcpy(usuario4.nombre, "Alba");
		strcpy(usuario4.apellido, "Rosales");

		//Usuario de prueba 5
		Usuario usuario5;

		usuario5.cUsuario = codigoUsuarioPorDefecto;
		strcpy(usuario5.email, "correoUsuario5@gmail.com");
		strcpy(usuario5.dni, "78906532Q");
		strcpy(usuario5.password, "87329Lpow65");
		strcpy(usuario5.nombre, "Luis");
		strcpy(usuario5.apellido, "Power");

		//Usuario de prueba 6
		Usuario usuario6;

		usuario6.cUsuario = codigoUsuarioPorDefecto;
		strcpy(usuario6.email, "correoUsuario6@gmail.com");
		strcpy(usuario6.dni, "37528831N");
		strcpy(usuario6.password, "NoTengoContrasenya");
		strcpy(usuario6.nombre, "Patricia");
		strcpy(usuario6.apellido, "Quintana");

		//Usuario de prueba 7
		Usuario usuario7;

		usuario7.cUsuario = codigoUsuarioPorDefecto;
		strcpy(usuario7.email, "correoUsuario7@gmail.com");
		strcpy(usuario7.dni, "65411378J");
		strcpy(usuario7.password, "contrasenya1");
		strcpy(usuario7.nombre, "Diego");
		strcpy(usuario7.apellido, "De La Fuente");

		//Usuario de prueba 8
		Usuario usuario8;

		usuario8.cUsuario = codigoUsuarioPorDefecto;
		strcpy(usuario8.email, "correoUsuario8@gmail.com");
		strcpy(usuario8.dni, "22557788C");
		strcpy(usuario8.password, "NeretxU99");
		strcpy(usuario8.nombre, "Nerea");
		strcpy(usuario8.apellido, "Garcia");

		//Usuario de prueba 9
		Usuario usuario9;

		usuario9.cUsuario = codigoUsuarioPorDefecto;
		strcpy(usuario9.email, "correoUsuario9@gmail.com");
		strcpy(usuario9.dni, "99776644P");
		strcpy(usuario9.password, "lac0ntrasenya");
		strcpy(usuario9.nombre, "Alvaro");
		strcpy(usuario9.apellido, "Penya");

		//Vuelo de prueba
		Vuelo vuelo;

		vuelo.cVuelo = codigoVueloPorDefecto;
		vuelo.plazas = 400;
		vuelo.precio = 50;
		strcpy(vuelo.aeropuertoSalida, "Aeropuerto de Bilbao");
		strcpy(vuelo.aeropuertoLlegada, "Aeropuerto de Madrid");
		strcpy(vuelo.fechaSalida, "14/03/22");
		strcpy(vuelo.fechaLlegada, "15/03/22");

		//Vuelo de prueba 2
		Vuelo vuelo2;

		vuelo2.cVuelo = codigoVueloPorDefecto;
		vuelo2.plazas = 100;
		vuelo2.precio = 100;
		strcpy(vuelo2.aeropuertoSalida, "Aeropuerto de Munich");
		strcpy(vuelo2.aeropuertoLlegada, "Aeropuerto de Roma");
		strcpy(vuelo2.fechaSalida, "22/05/22");
		strcpy(vuelo2.fechaLlegada, "22/05/22");

		//Vuelo de prueba 3
		Vuelo vuelo3;

		vuelo3.cVuelo = codigoVueloPorDefecto;
		vuelo3.plazas = 250;
		vuelo3.precio = 75;
		strcpy(vuelo3.aeropuertoSalida, "Aeropuerto de Madrid");
		strcpy(vuelo3.aeropuertoLlegada, "Aeropuerto de Barcelona");
		strcpy(vuelo3.fechaSalida, "07/11/22");
		strcpy(vuelo3.fechaLlegada, "07/11/22");

		//Vuelo de prueba 4
		Vuelo vuelo4;

		vuelo4.cVuelo = codigoVueloPorDefecto;
		vuelo4.plazas = 400;
		vuelo4.precio = 250;
		strcpy(vuelo4.aeropuertoSalida, "Aeropuerto de Londres");
		strcpy(vuelo4.aeropuertoLlegada, "Aeropuerto de Los Angeles");
		strcpy(vuelo4.fechaSalida, "2/04/22");
		strcpy(vuelo4.fechaLlegada, "3/04/22");

		//Vuelo de prueba 5
		Vuelo vuelo5;

		vuelo5.cVuelo = codigoVueloPorDefecto;
		vuelo5.plazas = 50;
		vuelo5.precio = 50;
		strcpy(vuelo5.aeropuertoSalida, "Aeropuerto de Antananaribo");
		strcpy(vuelo5.aeropuertoLlegada, "Aeropuerto de Madawi");
		strcpy(vuelo5.fechaSalida, "2/12/22");
		strcpy(vuelo5.fechaLlegada, "3/12/22");

		//Vuelo de prueba 6
		Vuelo vuelo6;

		vuelo6.cVuelo = codigoVueloPorDefecto;
		vuelo6.plazas = 500;
		vuelo6.precio = 150;
		strcpy(vuelo6.aeropuertoSalida, "Aeropuerto de Praga");
		strcpy(vuelo6.aeropuertoLlegada, "Aeropuerto de Munich");
		strcpy(vuelo6.fechaSalida, "7/07/22");
		strcpy(vuelo6.fechaLlegada, "8/07/22");

		//Vuelo de prueba 7
		Vuelo vuelo7;

		vuelo7.cVuelo = codigoVueloPorDefecto;
		vuelo7.plazas = 125;
		vuelo7.precio = 100;
		strcpy(vuelo7.aeropuertoSalida, "Aeropuerto de Egipto");
		strcpy(vuelo7.aeropuertoLlegada, "Aeropuerto de Budapest");
		strcpy(vuelo7.fechaSalida, "27/11/22");
		strcpy(vuelo7.fechaLlegada, "27/11/22");

		//Vuelo de prueba 8
		Vuelo vuelo8;

		vuelo8.cVuelo = codigoVueloPorDefecto;
		vuelo8.plazas = 400;
		vuelo8.precio = 300;
		strcpy(vuelo8.aeropuertoSalida, "Aeropuerto de Atenas");
		strcpy(vuelo8.aeropuertoLlegada, "Aeropuerto de Los Sicilia");
		strcpy(vuelo8.fechaSalida, "13/08/22");
		strcpy(vuelo8.fechaLlegada, "13/08/22");

		//Vuelo de prueba 9
		Vuelo vuelo9;

		vuelo9.cVuelo = codigoVueloPorDefecto;
		vuelo9.plazas = 500;
		vuelo9.precio = 500;
		strcpy(vuelo9.aeropuertoSalida, "Aeropuerto de Roma");
		strcpy(vuelo9.aeropuertoLlegada, "Aeropuerto de Paris");
		strcpy(vuelo9.fechaSalida, "22/03/22");
		strcpy(vuelo9.fechaLlegada, "23/03/22");

		//Vuelo de prueba 10
		Vuelo vuelo10;

		vuelo10.cVuelo = codigoVueloPorDefecto;
		vuelo10.plazas = 100;
		vuelo10.precio = 1000;
		strcpy(vuelo10.aeropuertoSalida, "Aeropuerto de Dublin");
		strcpy(vuelo10.aeropuertoLlegada, "Aeropuerto de Dubai");
		strcpy(vuelo10.fechaSalida, "2/05/22");
		strcpy(vuelo10.fechaLlegada, "2/05/22");

		eliminarUsuarios(db, result);
		eliminarVuelos(db, result);
		anyadirUsuario(db, result, usuario);
		anyadirUsuario(db, result, usuario2);
		anyadirUsuario(db, result, usuario3);
		anyadirUsuario(db, result, usuario4);
		anyadirUsuario(db, result, usuario5);
		anyadirUsuario(db, result, usuario6);
		anyadirUsuario(db, result, usuario7);
		anyadirUsuario(db, result, usuario8);
		anyadirUsuario(db, result, usuario9);
		anyadirVuelo(db, result, vuelo);
		anyadirVuelo(db, result, vuelo2);
		anyadirVuelo(db, result, vuelo3);
		anyadirVuelo(db, result, vuelo4);
		anyadirVuelo(db, result, vuelo5);
		anyadirVuelo(db, result, vuelo6);
		anyadirVuelo(db, result, vuelo7);
		anyadirVuelo(db, result, vuelo8);
		anyadirVuelo(db, result, vuelo9);
		anyadirVuelo(db, result, vuelo10);
*///BORRRAR ESTOS 2 CARACTERES
		/*//Para probar si los datos entran como deben en la BD
		imprimirUsuarios(db);
		imprimirVuelos(db);*/
/*BORRRAR ESTOS 2 CARACTERES
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

			Usuario u; Reserva r;

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
						u.cUsuario = atoi(recvBuff);

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
						strcpy(u.dni, recvBuff);

						f = fopen("log.txt", "a");
						if (fopen("log.txt", "a") == NULL) {
							printf("Error al abrir el fichero de log\n");
						} else {
							fprintf(f, "Anyadido dni al nuevo usuario\n");
						}
						fclose(f);
					}
					if (contador == 4) {
						strcpy(u.password, recvBuff);

						f = fopen("log.txt", "a");
						if (fopen("log.txt", "a") == NULL) {
							printf("Error al abrir el fichero de log\n");
						} else {
							fprintf(f, "Anyadida contrasenya al nuevo usuario\n");
						}
						fclose(f);
					}
					if (contador == 5) {
						strcpy(u.nombre, recvBuff);

						f = fopen("log.txt", "a");
						if (fopen("log.txt", "a") == NULL) {
							printf("Error al abrir el fichero de log\n");
						} else {
							fprintf(f, "Anyadido nombre al nuevo usuario\n");
						}
						fclose(f);
					}
					if (contador == 6) {
						strcpy(u.apellido, recvBuff);

						f = fopen("log.txt", "a");
						if (fopen("log.txt", "a") == NULL) {
							printf("Error al abrir el fichero de log\n");
						} else {
							fprintf(f, "Anyadido apellido al nuevo usuario\n");
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

			if (strcmp(recvBuff, "ANYADIRRESERVA") == 0)
			{
				f = fopen("log.txt", "a");
				if (fopen("log.txt", "a") == NULL) {
					printf("Error al abrir el fichero de log\n");
				} else {
					fprintf(f, "Anyadiendo reserva\n");
				}
				fclose(f);

				int contador = 0;
				recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
				while (strcmp(recvBuff, "ANYADIRRESERVA-END") != 0)
				{
					contador++;

					if (contador == 1) {
						r.cReserva = atoi(recvBuff);

						f = fopen("log.txt", "a");
						if (fopen("log.txt", "a") == NULL) {
							printf("Error al abrir el fichero de log\n");
						} else {
							fprintf(f, "Anyadiendo codigo de reserva a la nueva reserva\n");
						}
						fclose(f);
					}
					if (contador == 2) {
						r.cUsuario = atoi(recvBuff);

						f = fopen("log.txt", "a");
						if (fopen("log.txt", "a") == NULL) {
							printf("Error al abrir el fichero de log\n");
						} else {
							fprintf(f, "Anyadiendo codigo de usuario a la nueva reserva\n");
						}
						fclose(f);
					}
					if (contador == 3) {
						r.cVuelo = atoi(recvBuff);

						f = fopen("log.txt", "a");
						if (fopen("log.txt", "a") == NULL) {
							printf("Error al abrir el fichero de log\n");
						} else {
							fprintf(f, "Anyadiendo codigo de vuelo a la nueva reserva\n");
						}
						fclose(f);
					}
					if (contador == 4) {
						r.importeTotal = atoi(recvBuff);

						f = fopen("log.txt", "a");
						if (fopen("log.txt", "a") == NULL) {
							printf("Error al abrir el fichero de log\n");
						} else {
							fprintf(f, "Anyadiendo importe total a la nueva reserva\n");
						}
						fclose(f);
					}

					recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
				}
				insertReserva(db, r.cUsuario, r.cVuelo, r.importeTotal);

				f = fopen("log.txt", "a");
				if (fopen("log.txt", "a") == NULL) {
					printf("Error al abrir el fichero de log\n");
				} else {
					fprintf(f, "Anyadida nueva reserva\n");
				}
				fclose(f);

				imprimirReservas(db);
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
					if (usuarios[i].cUsuario != 0) {
						sprintf(sendBuff, "%d", usuarios[i].cUsuario);
						send(comm_socket, sendBuff, sizeof(sendBuff), 0);
						printf("Response sent: %s \n", sendBuff);
						sprintf(sendBuff, "%s", usuarios[i].email);
						send(comm_socket, sendBuff, sizeof(sendBuff), 0);
						printf("Response sent: %s \n", sendBuff);
						sprintf(sendBuff, "%s", usuarios[i].dni);
						send(comm_socket, sendBuff, sizeof(sendBuff), 0);
						printf("Response sent: %s \n", sendBuff);
						sprintf(sendBuff, "%s", usuarios[i].password);
						send(comm_socket, sendBuff, sizeof(sendBuff), 0);
						printf("Response sent: %s \n", sendBuff);
						sprintf(sendBuff, "%s", usuarios[i].nombre);
						send(comm_socket, sendBuff, sizeof(sendBuff), 0);
						printf("Response sent: %s \n", sendBuff);
						sprintf(sendBuff, "%s", usuarios[i].apellido);
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

			if (strcmp(recvBuff, "GETRESERVAS") == 0)
			{
				f = fopen("log.txt", "a");
				if (fopen("log.txt", "a") == NULL) {
					printf("Error al abrir el fichero de log\n");
				} else {
					fprintf(f, "Cargando reservas\n");
				}
				fclose(f);

				recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
				if (strcmp(recvBuff, "GETRESERVAS-END") == 0);

				f = fopen("log.txt", "a");
				if (fopen("log.txt", "a") == NULL) {
					printf("Error al abrir el fichero de log\n");
				} else {
					fprintf(f, "Error al cargar reservas\n");
				}
				fclose(f);

				Reserva *reservas = (Reserva*) malloc(50 * sizeof(Reserva));
				reservas = getReservas(db);

				int i = 0;
				for (i = 0; i < 50; i++) {
					if (reservas[i].cReserva != 0) {
						sprintf(sendBuff, "%d", reservas[i].cReserva);
						send(comm_socket, sendBuff, sizeof(sendBuff), 0);
						printf("Response sent: %s \n", sendBuff);
						sprintf(sendBuff, "%d", reservas[i].cUsuario);
						send(comm_socket, sendBuff, sizeof(sendBuff), 0);
						printf("Response sent: %s \n", sendBuff);
						sprintf(sendBuff, "%d", reservas[i].cVuelo);
						send(comm_socket, sendBuff, sizeof(sendBuff), 0);
						printf("Response sent: %s \n", sendBuff);
						sprintf(sendBuff, "%d", reservas[i].importeTotal);
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
					fprintf(f, "Reservas cargadas correctamente\n");
				}
				fclose(f);

			}

			if (strcmp(recvBuff, "GETVUELOS") == 0)
			{
				f = fopen("log.txt", "a");
				if (fopen("log.txt", "a") == NULL) {
					printf("Error al abrir el fichero de log\n");
				} else {
					fprintf(f, "Cargando vuelos\n");
				}
				fclose(f);

				recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
				if (strcmp(recvBuff, "GETVUELOS-END") == 0);

				f = fopen("log.txt", "a");
				if (fopen("log.txt", "a") == NULL) {
					printf("Error al abrir el fichero de log\n");
				} else {
					fprintf(f, "Error al cargar vuelos\n");
				}
				fclose(f);

				Vuelo *vuelos = (Vuelo*) malloc(50 * sizeof(Vuelo));
				vuelos = getVuelos(db);

				int i = 0;
				for (i = 0; i < 50; i++) {
					if (vuelos[i].cVuelo != 0) {
						sprintf(sendBuff, "%d", vuelos[i].cVuelo);
						send(comm_socket, sendBuff, sizeof(sendBuff), 0);
						printf("Response sent: %s \n", sendBuff);
						sprintf(sendBuff, "%d", vuelos[i].plazas);
						send(comm_socket, sendBuff, sizeof(sendBuff), 0);
						printf("Response sent: %s \n", sendBuff);
						sprintf(sendBuff, "%d", vuelos[i].precio);
						send(comm_socket, sendBuff, sizeof(sendBuff), 0);
						printf("Response sent: %s \n", sendBuff);
						sprintf(sendBuff, "%s", vuelos[i].aeropuertoSalida);
						send(comm_socket, sendBuff, sizeof(sendBuff), 0);
						printf("Response sent: %s \n", sendBuff);
						sprintf(sendBuff, "%s", vuelos[i].aeropuertoLlegada);
						send(comm_socket, sendBuff, sizeof(sendBuff), 0);
						printf("Response sent: %s \n", sendBuff);
						sprintf(sendBuff, "%s", vuelos[i].fechaSalida);
						send(comm_socket, sendBuff, sizeof(sendBuff), 0);
						printf("Response sent: %s \n", sendBuff);
						sprintf(sendBuff, "%s", vuelos[i].fechaLlegada);
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
					fprintf(f, "Vuelos cargados correctamente\n");
				}
				fclose(f);

			}

			if (strcmp(recvBuff, "DELETERESERVA") == 0)
			{
				f = fopen("log.txt", "a");
				if (fopen("log.txt", "a") == NULL) {
					printf("Error al abrir el fichero de log\n");
				} else {
					fprintf(f, "Eliminando reserva\n");
				}
				fclose(f);

				recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
				deleteReserva(db, recvBuff);

				f = fopen("log.txt", "a");
				if (fopen("log.txt", "a") == NULL) {
					printf("Error al abrir el fichero de log\n");
				} else {
					fprintf(f, "Reserva eliminada\n");
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
*///BORRRAR ESTOS 2 CARACTERES
