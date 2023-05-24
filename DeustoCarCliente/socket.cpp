// IMPORTANT: Winsock Library ("ws2_32") should be linked
#include <iostream>
#include <stdio.h>
#include <winsock2.h>
#include "Socket.h"
#include "usuario.h"
#include "coche.h"
#include "venta.h"
#include "compra.h"

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

using namespace std;

SOCKET Socket::openSocket()
{
	WSADATA wsaData;
	SOCKET s;
	struct sockaddr_in server;

	cout << "\nInitialising Winsock..." << endl;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		cout << "Failed. Error Code : " << WSAGetLastError() << endl;
	}

	cout << "Initialised." << endl;

	//SOCKET creation
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		cout << "Could not create socket: " << WSAGetLastError() << endl;
		WSACleanup();
	}

	cout << "Initialised." << endl;
	printf("Socket created.\n");

	server.sin_addr.s_addr = inet_addr(SERVER_IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

	//CONNECT to remote server
	if (connect(s, (struct sockaddr*) &server, sizeof(server)) == SOCKET_ERROR)
	{
		cout << "Connection error: " << WSAGetLastError() << endl;
		closesocket(s);
		WSACleanup();
	}

	cout << "Connection stablished with: " << inet_ntoa(server.sin_addr)
			<< "(" << ntohs(server.sin_port) << ")" << endl;

	return s;
}

//SEND and RECEIVE data (CLIENT/SERVER PROTOCOL)

// SENDING command ANYADIRUSUARIO and parameters to the server
void Socket::SocketAnyadirUsuario(SOCKET s, Usuario u)
{
	char sendBuff[512], recvBuff[512];
	char chars[4], chars2[7];
	sprintf(chars, "%d", u.getId());

	strcpy(sendBuff, "ANYADIRUSUARIO");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, chars);
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, u.getNombre().c_str());
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, u.getEmail().c_str());
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, u.getContrasenya().c_str());
	send(s, sendBuff, sizeof(sendBuff), 0);
	//NO SE SI ESTÁ BIEN LA SIGUIENTE LINEA
	sprintf(chars2, "%d", u.getSaldo());
	strcpy(sendBuff, "ANYADIRUSUARIO-END");
	send(s, sendBuff, sizeof(sendBuff), 0);
}

void Socket::SocketAnyadirVenta(SOCKET s, Venta v) {
	char sendBuff[512], recvBuff[512];
	char chars1[4], chars2[7], chars3[4], chars4[4];
	sprintf(chars1, "%d", v.getId());
	sprintf(chars2, "%d", v.getPrecio());
	sprintf(chars3, "%d", v.getIdVendedor());
	sprintf(chars4, "%d", v.getIdCoche());

	// SENDING command ANYADIRVENTA and parameters to the server
	strcpy(sendBuff, "ANYADIRVENTA");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, chars1);
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, chars2);
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, v.getFechaVenta().c_str());
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, chars3);
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, chars4);
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, "ANYADIRVENTA-END");
	send(s, sendBuff, sizeof(sendBuff), 0);
}

void SocketAnyadirCompras(SOCKET s, Compra c){
	char sendBuff[512], recvBuff[512];
	char chars1[4], chars2[7], chars3[4], chars4[4], chars5[5];
	sprintf(chars1, "%d", c.getId());
	sprintf(chars2, "%d", c.getPrecio());
	sprintf(chars3, "%d", c.getIdComprador());
	sprintf(chars4, "%d", c.getIdVendedor());
	sprintf(chars5, "%d", c.getIdCoche());

	// SENDING command ANYADIRCOMPRA and parameters to the server
	strcpy(sendBuff, "ANYADIRCOMPRA");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, chars1);
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, chars2);
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, c.getFechaCompra().c_str());
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, chars3);
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, chars4);
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, chars5);
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, "ANYADIRCOMPRA-END");
	send(s, sendBuff, sizeof(sendBuff), 0);
}

Usuario* Socket::SocketGetUsuarios(SOCKET s) {
	char sendBuff[512], recvBuff[512];
	Usuario *usuarios = (Usuario*)malloc(sizeof(Usuario) * 50);
	strcpy(sendBuff, "GETUSUARIOS");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, "GETUSUARIOS-END");
	send(s, sendBuff, sizeof(sendBuff), 0);

	// RECEIVING response from the server
	int i = 0;
	for (i = 0; i < 50; i++) {
		recv(s, recvBuff, sizeof(recvBuff), 0);

		if (strcmp(recvBuff, "0")) {
			usuarios[i].setId(atoi(recvBuff));
			recv(s, recvBuff, sizeof(recvBuff), 0);
			string s1 = recvBuff;
			usuarios[i].setNombre(s1);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			string s2 = recvBuff;
			usuarios[i].setEmail(s2);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			string s3 = recvBuff;
			usuarios[i].setContrasenya(s3);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			int s4 = recvBuff;
			usuarios[i].setSaldo(s4);
		} else {
			i = 50;
		}
	}
	return usuarios;
}

Venta* Socket::SocketGetVentas(SOCKET s) {
	char sendBuff[512], recvBuff[512];
	Venta *ventas = (Venta*)malloc(sizeof(Venta) * 50);
	strcpy(sendBuff, "GETVENTAS");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, "GETVENTAS-END");
	send(s, sendBuff, sizeof(sendBuff), 0);

	// RECEIVING response from the server
	int i = 0;
	for (i = 0; i < 50; i++) {
		recv(s, recvBuff, sizeof(recvBuff), 0);

		if (strcmp(recvBuff, "FINBUCLE")) {
			ventas[i].setId(atoi(recvBuff));
			recv(s, recvBuff, sizeof(recvBuff), 0);
			ventas[i].setPrecio(atoi(recvBuff));
			recv(s, recvBuff, sizeof(recvBuff), 0);
			//NO SE SI ESTA BIEN LA SIGUIENTE LINEA
			ventas[i].setFechaVenta(recvBuff);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			ventas[i].setIdVendedor(atoi(recvBuff));
			recv(s, recvBuff, sizeof(recvBuff), 0);
			ventas[i].setIdCoche(atoi(recvBuff));
		} else {
			i = 50;
		}
	}
	return ventas;
}

Compra* SocketGetCompras(SOCKET s){
	char sendBuff[512], recvBuff[512];
	Compra *compras = (Compra*)malloc(sizeof(Compra) * 50);
	strcpy(sendBuff, "GETCOMPRAS");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, "GETCOMPRAS-END");
	send(s, sendBuff, sizeof(sendBuff), 0);

	// RECEIVING response from the server
	int i = 0;
	for (i = 0; i < 50; i++) {
		recv(s, recvBuff, sizeof(recvBuff), 0);

		if (strcmp(recvBuff, "FINBUCLE")) {
			compras[i].setId(atoi(recvBuff));
			recv(s, recvBuff, sizeof(recvBuff), 0);
			compras[i].setPrecio(atoi(recvBuff));
			recv(s, recvBuff, sizeof(recvBuff), 0);
			//NO SE SI ESTA BIEN LA SIGUIENTE LINEA
			compras[i].setFechaCompra(recvBuff);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			compras[i].setIdComprador(atoi(recvBuff));
			recv(s, recvBuff, sizeof(recvBuff), 0);
			compras[i].setIdVendedor(atoi(recvBuff));
			recv(s, recvBuff, sizeof(recvBuff), 0);
			compras[i].setIdCoche(atoi(recvBuff));
		} else {
			i = 50;
		}
	}
	return compras;
}

Coche* Socket::SocketGetCoches(SOCKET s) {
	char sendBuff[512], recvBuff[512];
	Coche *coches = (Coche*)malloc(sizeof(Coche) * 50);
	strcpy(sendBuff, "GETCOCHE");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, "GETCOCHE-END");
	send(s, sendBuff, sizeof(sendBuff), 0);

	// RECEIVING response from the server
	int i = 0;
	for (i = 0; i < 50; i++) {
		recv(s, recvBuff, sizeof(recvBuff), 0);

		if (strcmp(recvBuff, "FINBUCLE")) {
			coches[i].setId(atoi(recvBuff));
			recv(s, recvBuff, sizeof(recvBuff), 0);
			//NO SE SI ESTÁ BIEN LA SIGUIENTE LINEA
			coches[i].setMarca(recvBuff);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			//NO SE SI ESTÁ BIEN LA SIGUIENTE LINEA
			coches[i].setModelo(recvBuff);
		} else {
			i = 50;
		}

	}
	return coches;
}

void Socket::SocketModificarUsuario(SOCKET s, Usuario u) {
	char sendBuff[512], recvBuff[512];

	//Modificar usuario
		//Antes de usar el socket, se hace lo que tenga que hacerse en el menu
		strcpy(sendBuff, "MODIFICARUSUARIOS");
		send(s, sendBuff, sizeof(sendBuff), 0);
		strcpy(sendBuff, "MODIFICARUSUARIOS-END");
		send(s, sendBuff, sizeof(sendBuff), 0);

		//Aqui se reenvian el usuario modificado al servidor
		//Primero un Delete
		//Luego un Anyadir
}

void Socket::SocketModificarCoche(SOCKET s, Coche c) {
	char sendBuff[512], recvBuff[512];

	//Modificar coche
		strcpy(sendBuff, "MODIFICARCOCHE");
		send(s, sendBuff, sizeof(sendBuff), 0);
		strcpy(sendBuff, "MODIFICARCOCHE-END");
		send(s, sendBuff, sizeof(sendBuff), 0);

		//Aqui se reenvian el coche modificaoa al servidor
		//Primero un Delete
		//Luego un Anyadir
}

void Socket::closeSocket(SOCKET s)
{
	// CLOSING the socket and cleaning Winsock...
	closesocket(s);
	WSACleanup();
}
