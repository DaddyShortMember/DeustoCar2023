// IMPORTANT: Winsock Library ("ws2_32") should be linked
#include <iostream>
#include <string>
#include <stdio.h>
#include <winsock2.h>
#include "usuario.h"
#include "coche.h"
#include "venta.h"
#include "compra.h"
#include <winsock2.h>
#include <chrono>
#include <ctime>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

using namespace std;
using namespace comven;
using namespace login;
using namespace com;
using namespace ven;

void menuPrincipal()
{
	cout << "--Menu:-----------------------" << endl;
	cout << "|1. Iniciar sesion            |" << endl;
	cout << "|2. Registrarse               |" << endl;
	cout << "|3. Manual                    |" << endl;
	cout << "|4. Salir                     |" << endl;
	cout << "------------------------------" << endl;
}

void menuRegistrarse(SOCKET s)
{
	Usuario u;

	string nombre;
	string email;
	string contrasenya;
	string saldoString;

	cout << "Escribe tu nombre:" << endl;
	cin.ignore(1, '\n');
	getline(cin, nombre);
	cout << "Escribe un email:" << endl;
	cin.ignore(1, '\n');
	getline(cin, email);
	cout << "Escribe tu contrasenya:" << endl;
	cin.ignore(1, '\n');
	getline(cin, contrasenya);
	cout << "Escribe tu saldo:" << endl;
	//Comprobacion de si saldo es un cadena de numeros, 1 error, 0 correcto.
	int correcto = 1;
	for (int i = 0; i < -1; ++i) {
		if (correcto == 1) {
			getline(cin, saldoString);
				for (char caracter : saldoString) {
					if (!std::isdigit(caracter)) {
						cout << "Error. Introduce un numero entero. Escribe tu saldo:" << endl;
						break;
					} else {
						correcto = 0;
					}
				}
		} else if (correcto == 0){
			break;
		}
	}

	u.setId(0);
	u.setNombre(nombre);
	u.setEmail(email);
	u.setContrasenya(contrasenya);
	int saldoInt = std::stoi(saldoString);
	u.setSaldo(saldoInt);

	char sendBuff[512];
	char chars[4];
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
	//NO SE SI ESTï¿½ BIEN LA SIGUIENTE LINEA
	sprintf(sendBuff, "%d", u.getSaldo());
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, "ANYADIRUSUARIO-END");
	send(s, sendBuff, sizeof(sendBuff), 0);

	cout << "Registro completado con exito.\n" << endl;
}

void menuComprarCoche(SOCKET s, int idUsuario)
{
	char sendBuff[512], recvBuff[512];
	Venta *ventas = (Venta*)malloc(sizeof(Venta) * 50);
	Venta v;
	Coche *coches = (Coche*)malloc(sizeof(Coche) * 50);
	Coche c;
	strcpy(sendBuff, "GETVENTAS");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, "GETVENTAS-END");
	send(s, sendBuff, sizeof(sendBuff), 0);

	// RECEIVING response from the server
	int i = 0, tamanyoVentas = 0;
	for (i = 0; i < 50; i++) {
		recv(s, recvBuff, sizeof(recvBuff), 0);

		if (strcmp(recvBuff, "FINBUCLE")) {
			v.setId(atoi(recvBuff));
			recv(s, recvBuff, sizeof(recvBuff), 0);
			v.setPrecio(atoi(recvBuff));
			recv(s, recvBuff, sizeof(recvBuff), 0);
			//NO SE SI ESTÁ BIEN LA SIGUIENTE LINEA
			v.setFechaVenta(recvBuff);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			v.setIdVendedor(atoi(recvBuff));
			recv(s, recvBuff, sizeof(recvBuff), 0);
			v.setIdCoche(atoi(recvBuff));
			if (v.getId() == idUsuario) {
				ventas[tamanyoVentas] = v;
				tamanyoVentas++;
			}
		} else {
			i = 50;
		}
	}

	strcpy(sendBuff, "GETCOCHES");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, "GETCOCHES-END");
	send(s, sendBuff, sizeof(sendBuff), 0);

	// RECEIVING response from the server
	int j = 0, tamanyoCoches = 0;
	for (j = 0; j < 50; j++) {
		recv(s, recvBuff, sizeof(recvBuff), 0);

		if (strcmp(recvBuff, "FINBUCLE")) {
			c.setId(atoi(recvBuff));
			recv(s, recvBuff, sizeof(recvBuff), 0);
			//NO SE SI ESTÁ BIEN LA SIGUIENTE LINEA
			c.setMarca(recvBuff);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			//NO SE SI ESTÁ BIEN LA SIGUIENTE LINEA
			c.setModelo(recvBuff);

			i = 0;
			for (i = 0; i < tamanyoCoches; i++) {
				coches[tamanyoCoches] = c;
				tamanyoCoches++;
			}

		} else {
			j = 50;
		}
	}

	cout << "COCHES EN VENTA:\n" << endl;

	i = 0, j = 0;
	for (i = 0; i < tamanyoVentas; i++) {

		cout << "Id de venta: " << ventas[i].getId() << endl;
		cout << "Precio de venta: " << ventas[i].getPrecio() << " euros\n" << endl;
		cout << "Fecha de venta: " << ventas[i].getFechaVenta() << endl;
		cout << "Id del vendedor: " << ventas[i].getIdVendedor() << endl;
		cout << "Id del coche: " << ventas[i].getIdCoche() << endl;

		for (j = 0; j < tamanyoCoches; j++) {
			if (coches[j].getId() == ventas[i].getIdCoche()) {
				cout << "Marca: " << coches[j].getMarca() << endl;
				cout << "Modelo: " << coches[j].getModelo() << endl;
			}
		}
	}

	string idSeleccionado;
	cout << "Introduce el id de venta que desees para realizar la comprar o cualquier caracter para salir." << endl;
	cin >> idSeleccionado;
	cout << "\n";

	//Comprueba que idSelecionado sea un numero, 1 error, 0 correcto.
	int correcto = 1;
	getline(cin, idSeleccionado);
	for (char caracter : idSeleccionado) {
		if (!std::isdigit(caracter)) {
			correcto = 1;
			//MEJOR SI SALIESE A MENUDESUTOCAR PERO DA FALLO POR EL ORDEN DE LA DECLARACION DE LOS METODOS. Y NO SE SOLUCIONARLO
			cout << "Error. El id de venta no es correcto." << endl;
			menuPrincipal();
			break;
		} else {
			correcto = 0;
		}
	}

	if (correcto == 0) {

		int tamanyoCompra = 0;

		//char sendBuff[512], recvBuff[512];
		Compra *compras = (Compra*)malloc(sizeof(Compra) * 50);
		strcpy(sendBuff, "GETCOMPRAS");
		send(s, sendBuff, sizeof(sendBuff), 0);
		strcpy(sendBuff, "GETCOMPRAS-END");
		send(s, sendBuff, sizeof(sendBuff), 0);// RECEIVING response from the server

		// RECEIVING response from the server
		int i = 0;
		for (i = 0; i < 50; i++) {
			recv(s, recvBuff, sizeof(recvBuff), 0);

			if (strcmp(recvBuff, "FINBUCLE")) {
				compras[i].setId(atoi(recvBuff));
				recv(s, recvBuff, sizeof(recvBuff), 0);
				compras[i].setPrecio(atoi(recvBuff));
				recv(s, recvBuff, sizeof(recvBuff), 0);
				string s1 = recvBuff;
				compras[i].setFechaCompra(s1);
				recv(s, recvBuff, sizeof(recvBuff), 0);
				compras[i].setIdComprador(atoi(recvBuff));
				recv(s, recvBuff, sizeof(recvBuff), 0);
				compras[i].setIdVendedor(atoi(recvBuff));
				recv(s, recvBuff, sizeof(recvBuff), 0);
				compras[i].setIdCoche(atoi(recvBuff));
			} else {
				tamanyoCompra = i;
				i = 50;
			}
		}

		Compra nuevoCompra;
		nuevoCompra.setId(tamanyoCompra+1);
		for (i = 0; i < tamanyoVentas; i++) {
			if (ventas[i].getId() == idSeleccionado) {
				nuevoCompra.setPrecio(ventas[i].getPrecio());
			    // Obtener el tiempo actual
			    std::chrono::system_clock::time_point ahora = std::chrono::system_clock::now();

			    // Convertirlo a un formato de tiempo legible
			    std::time_t tiempo_actual = std::chrono::system_clock::to_time_t(ahora);

			    // Obtener la estructura de fecha y hora local
			    std::tm* fecha_actual = std::localtime(&tiempo_actual);

				int dia = fecha_actual->tm_mday;
				int mes = fecha_actual->tm_mon + 1;
				int anyo = fecha_actual->tm_year + 1900;

				// Imprimir la fecha actual
				string fecha = "Fecha actual: " + dia + "/" + mes + "/" + anyo;
				nuevoCompra.setFechaCompra(fecha);
				nuevoCompra.setIdComprador(idUsuario);
				nuevoCompra.setIdVendedor(ventas[i].getIdVendedor());
				nuevoCompra.setIdCoche(ventas[i].getIdCoche());
			}
		}

		char chars1[3], chars2[8], chars3[20], chars4[3], chars5[3], chars6[3];
		sprintf(chars1, "%d", nuevoCompra.getId());
		sprintf(chars2, "%d", nuevoCompra.getPrecio());
		sprintf(chars3, "%d", nuevoCompra.getFechaCompra());
		sprintf(chars4, "%d", nuevoCompra.getIdComprador());
		sprintf(chars5, "%d", nuevoCompra.getIdVendedor());
		sprintf(chars6, "%d", nuevoCompra.getIdCoche());

		// SENDING command ANYADIRCOCHE and parameters to the server
		strcpy(sendBuff, "ANYADIRCOMPRA");
		send(s, sendBuff, sizeof(sendBuff), 0);
		strcpy(sendBuff, chars1);
		send(s, sendBuff, sizeof(sendBuff), 0);
		strcpy(sendBuff, chars2);
		send(s, sendBuff, sizeof(sendBuff), 0);
		strcpy(sendBuff, chars3);
		send(s, sendBuff, sizeof(sendBuff), 0);
		strcpy(sendBuff, chars4);
		send(s, sendBuff, sizeof(sendBuff), 0);
		strcpy(sendBuff, chars5);
		send(s, sendBuff, sizeof(sendBuff), 0);
		strcpy(sendBuff, chars6);
		send(s, sendBuff, sizeof(sendBuff), 0);
		strcpy(sendBuff, "ANYADIRCOMPRA-END");
		send(s, sendBuff, sizeof(sendBuff), 0);

		//char sendBuff[512], recvBuff[512];
		Usuario *usuarios = (Usuario*)malloc(sizeof(Usuario) * 50);
		strcpy(sendBuff, "GETUSUARIOS");
		send(s, sendBuff, sizeof(sendBuff), 0);
		strcpy(sendBuff, "GETUSUARIOS-END");
		send(s, sendBuff, sizeof(sendBuff), 0);

		// RECEIVING response from the server
		int i = 0, tamanyoUsuario = 0;
		for (i = 0; i < 50; i++) {
			recv(s, recvBuff, sizeof(recvBuff), 0);

			if (strcmp(recvBuff, "FINBUCLE")) {
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
				usuarios[i].setSaldo(atoi(recvBuff));
				if (usuarios[i].getId() == nuevoCompra.getIdComprador()) {
					j = 0;
					for (j = 0; j < tamanyoVentas; ++j) {
						if (ventas[j].getId() == idSeleccionado) {
							usuarios[i].setSaldo(usuarios[i].getSaldo() + ventas[j].getPrecio());
						}
					}
				}

				if (usuarios[i].getId() == nuevoCompra.getIdVendedor()) {
					j = 0;
					for (j = 0; j < tamanyoVentas; ++j) {
						if (ventas[j].getId() == idSeleccionado) {
							usuarios[i].setSaldo(usuarios[i].getSaldo() - ventas[j].getPrecio());
						}
					}
				}
			}
		}

		strcpy(sendBuff, "DELETEVENTAS");
		send(s, sendBuff, sizeof(sendBuff), 0);
		char chars[8];
		sprintf(chars, "%d", ventas[idSeleccionado + 1].getId());
		strcpy(sendBuff, chars);
		send(s, sendBuff, sizeof(sendBuff), 0);

		strcpy(sendBuff, "DELETECOCHES");
		send(s, sendBuff, sizeof(sendBuff), 0);
		char chars[8];
		sprintf(chars, "%d", coches[nuevoCompra.getIdCoche() + 1].getId());
		strcpy(sendBuff, chars);
		send(s, sendBuff, sizeof(sendBuff), 0);

	}

	cout << "Compra realizada con exito.\n" << endl;
}


void menuVenderCoche(SOCKET s, int idUsuario)
{

	int tamanyo = 0;

	char sendBuff[512], recvBuff[512];
	Coche *coches = (Coche*)malloc(sizeof(Coche) * 50);
	strcpy(sendBuff, "GETCOCHES");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, "GETCOCHES-END");
	send(s, sendBuff, sizeof(sendBuff), 0);// RECEIVING response from the server

	// RECEIVING response from the server
	int i = 0;
	for (i = 0; i < 50; i++) {
		recv(s, recvBuff, sizeof(recvBuff), 0);

		if (strcmp(recvBuff, "FINBUCLE")) {
			coches[i].setId(atoi(recvBuff));
			recv(s, recvBuff, sizeof(recvBuff), 0);
			string s1 = recvBuff;
			coches[i].setMarca(s1);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			string s2 = recvBuff;
			coches[i].setModelo(s2);
		} else {
			tamanyo = i;
			i = 50;
		}
	}

	string seleccionMarca;
	string seleccionModelo;

	cout << "Introduce la marca del coche que quieres vender." << endl;
	cin >> seleccionMarca;
	cout << "\n";

	cout << "Introduce el modelo del coche que quieres vender." << endl;
	cin >> seleccionModelo;
	cout << "\n";

	Coche nuevoCoche;
	nuevoCoche.setId(tamanyo+1);
	nuevoCoche.setMarca(seleccionMarca);
	nuevoCoche.setModelo(seleccionModelo);

	char chars1[8], chars2[8], chars3[8];
	sprintf(chars1, "%d", nuevoCoche.getId());
	sprintf(chars2, "%d", nuevoCoche.getMarca);
	sprintf(chars3, "%d", nuevoCoche.getModelo());

	// SENDING command ANYADIRCOCHE and parameters to the server
	strcpy(sendBuff, "ANYADIRCOCHE");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, chars1);
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, chars2);
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, chars3);
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, "ANYADIRCOCHE-END");
	send(s, sendBuff, sizeof(sendBuff), 0);

	cout << "Coche anyadido\n" << endl;

	string seleccionPrecio;

	cout << "Introduce el precio al que quieres vender el coche." << endl;
	cin >> seleccionPrecio;
	cout << "\n";
	//Comprueba que seleccionPrecio sea un numero, 1 error, 0 correcto.
	int correcto = 1;
	for (int i = 0; i < -1; ++i) {
		if (correcto == 1) {
			getline(cin, seleccionPrecio);
				for (char caracter : seleccionPrecio) {
					if (!std::isdigit(caracter)) {
						correcto = 1;
						cout << "Error. Introduce el precio al que quieres vender el coche." << endl;
						cin >> seleccionPrecio;
						cout << "\n";
						break;
					} else {

						correcto = 0;

						char sendBuff[512], recvBuff[512];
						Venta *ventas = (Venta*)malloc(sizeof(Venta) * 50);
						Venta v;

						strcpy(sendBuff, "GETVENTAS");
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, "GETVENTAS-END");
						send(s, sendBuff, sizeof(sendBuff), 0);

						// RECEIVING response from the server
						int i = 0, tamanyoVentas = 0;
						for (i = 0; i < 50; i++) {
							recv(s, recvBuff, sizeof(recvBuff), 0);

							if (strcmp(recvBuff, "FINBUCLE")) {
								v.setId(atoi(recvBuff));
								recv(s, recvBuff, sizeof(recvBuff), 0);
								v.setPrecio(atoi(recvBuff));
								recv(s, recvBuff, sizeof(recvBuff), 0);
								//NO SE SI ESTï¿½ BIEN LA SIGUIENTE LINEA
								v.setFechaVenta(recvBuff);
								recv(s, recvBuff, sizeof(recvBuff), 0);
								v.setIdVendedor(atoi(recvBuff));
								recv(s, recvBuff, sizeof(recvBuff), 0);
								v.setIdCoche(atoi(recvBuff));
							} else {
								tamanyoVentas = i;
								i = 50;
							}
						}

						Venta nuevaVenta;
						int precio = std::stoi(seleccionPrecio);

						nuevaVenta.setId(tamanyoVentas+1);
						nuevaVenta.setPrecio(precio);
					    // Obtener el tiempo actual
					    std::chrono::system_clock::time_point ahora = std::chrono::system_clock::now();

					    // Convertirlo a un formato de tiempo legible
					    std::time_t tiempo_actual = std::chrono::system_clock::to_time_t(ahora);

					    // Obtener la estructura de fecha y hora local
					    std::tm* fecha_actual = std::localtime(&tiempo_actual);

						int dia = fecha_actual->tm_mday;
						int mes = fecha_actual->tm_mon + 1;
						int anyo = fecha_actual->tm_year + 1900;

						// Imprimir la fecha actual
						string fecha = "Fecha actual: " + dia + "/" + mes + "/" + anyo;
						nuevaVenta.setFechaVenta(fecha);
						nuevaVenta.setIdVendedor(idUsuario);
						nuevaVenta.setIdCoche(nuevoCoche.getId());

						char chars1[8], chars2[8], chars3[8], chars4[8], chars5[8];
						sprintf(chars1, "%d", nuevaVenta.getId());
						sprintf(chars2, "%d", nuevaVenta.getPrecio());
						sprintf(chars3, "%d", nuevaVenta.getFechaVenta());
						sprintf(chars4, "%d", nuevaVenta.getIdVendedor());
						sprintf(chars5, "%d", nuevaVenta.getIdCoche());

						// SENDING command ANYADIRVENTA and parameters to the server
						strcpy(sendBuff, "ANYADIRVENTA");
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, chars1);
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, chars2);
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, chars3);
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, chars4);
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, chars5);
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, "ANYADIRVENTA-END");
						send(s, sendBuff, sizeof(sendBuff), 0);

						cout << "Anuncio de venta realizado con exito.\n" << endl;
					}
				}
		}
	}
}

void menuSusCochesEnVenta(SOCKET s, int idUsuario)
{
	char sendBuff[512], recvBuff[512];
	Venta *ventas = (Venta*)malloc(sizeof(Venta) * 50);
	Venta v;
	Coche *coches = (Coche*)malloc(sizeof(Coche) * 50);
	Coche c;
	strcpy(sendBuff, "GETVENTAS");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, "GETVENTAS-END");
	send(s, sendBuff, sizeof(sendBuff), 0);

	// RECEIVING response from the server
	int i = 0, tamanyoVentas = 0;
	for (i = 0; i < 50; i++) {
		recv(s, recvBuff, sizeof(recvBuff), 0);

		if (strcmp(recvBuff, "FINBUCLE")) {
			v.setId(atoi(recvBuff));
			recv(s, recvBuff, sizeof(recvBuff), 0);
			v.setPrecio(atoi(recvBuff));
			recv(s, recvBuff, sizeof(recvBuff), 0);
			//NO SE SI ESTï¿½ BIEN LA SIGUIENTE LINEA
			v.setFechaVenta(recvBuff);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			v.setIdVendedor(atoi(recvBuff));
			recv(s, recvBuff, sizeof(recvBuff), 0);
			v.setIdCoche(atoi(recvBuff));
			if (v.getId() == idUsuario) {
				ventas[tamanyoVentas] = v;
				tamanyoVentas++;
			}
		} else {
			i = 50;
		}
	}

	strcpy(sendBuff, "GETCOCHES");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, "GETCOCHES-END");
	send(s, sendBuff, sizeof(sendBuff), 0);

	// RECEIVING response from the server
	int j = 0, tamanyoCoches = 0;
	for (j = 0; j < 50; j++) {
		recv(s, recvBuff, sizeof(recvBuff), 0);

		if (strcmp(recvBuff, "FINBUCLE")) {
			c.setId(atoi(recvBuff));
			recv(s, recvBuff, sizeof(recvBuff), 0);
			//NO SE SI ESTï¿½ BIEN LA SIGUIENTE LINEA
			c.setMarca(recvBuff);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			//NO SE SI ESTï¿½ BIEN LA SIGUIENTE LINEA
			c.setModelo(recvBuff);

			i = 0;
			for (i = 0; i < tamanyoCoches; i++) {
				coches[tamanyoCoches] = c;
				tamanyoCoches++;
			}

		} else {
			j = 50;
		}
	}

	cout << "SUS COCHES EN VENTA:\n" << endl;

	i = 0, j = 0;
	for (i = 0; i < tamanyoVentas; i++) {
		if (ventas[i].getIdVendedor() == idUsuario) {
			cout << "Precio de venta: " << ventas[i].getPrecio() << " euros\n" << endl;
			cout << "Fecha de venta: " << ventas[i].getFechaVenta() << endl;
			cout << "Id del vendedor: " << ventas[i].getIdVendedor() << endl;
			cout << "Id del coche: " << ventas[i].getIdCoche() << endl;

			for (j = 0; j < tamanyoCoches; j++) {
				if (coches[j].getId() == ventas[i].getIdCoche()) {
					cout << "Marca: " << coches[j].getMarca() << endl;
					cout << "Modelo: " << coches[j].getModelo() << endl;
				}
			}
		}
	}
}

void menuDeustoCar(SOCKET s, int idUsuario)
{
	int opcion;

	cout << "--Menu DeustoCar:-----------------------" << endl;
	cout << "|1. Comprar coche           |" << endl;
	cout << "|2. Vender coche               |" << endl;
	cout << "|3. Sus coches en venta                    |" << endl;
	cout << "|4. Salir                     |" << endl;
	cout << "------------------------------" << endl;

	cin >> opcion;
	cout << "\n";
	switch(opcion){
		case 1 :
			menuComprarCoche(s, idUsuario);
			break;

		case 2 :
			menuVenderCoche(s, idUsuario);
			break;

		case 3 :
			menuSusCochesEnVenta(s, idUsuario);
			break;

		case 4 :
			cout << "Cerrando la sesion..." << endl;
			break;

		default:
			cout << "Esa opcion no existe, elija otra." << endl;
			 menuDeustoCar(s, idUsuario);
			break;
	} while (opcion != 4);
}

void menuIniciarSesion(SOCKET s)
{
	char yesNo;
	string email, contrasenya;

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

		if (strcmp(recvBuff, "FINBUCLE")) {
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

	cout << "Introduzca su correo electronico:" << endl;
	cin.ignore(1, '\n');
	getline(cin, email);
	cout << "Introduzca su contrasenya:" << endl;
	getline(cin, contrasenya);

	i = 0;
	for (i = 0; i < 50; i++) {
		if (email == usuarios[i].getEmail() && contrasenya == usuarios[i].getContrasenya()) {
			cout << "Datos correctos. Ha iniciado la sesion.\n" << endl;
			int cUsuario = usuarios[i].getId();
			i = 51;
			menuDeustoCar(s, cUsuario);
		}
	}
	if (i == 50) {
		cout << "Datos incorrectos.\n" << endl;
		cout << "Quiere volver a intentarlo?" << endl;
		cout << "S/N" << endl;
		cin >> yesNo;
		if (yesNo == "S" || yesNo == "s") {
			menuPrincipal();
		} else if (yesNo == "N" || yesNo == "n") {
			menuIniciarSesion(s);
		}
	}
}


int main(int argc, char *argv[])
{
	int opcion;
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
	cout << "\n";

	do {
		menuPrincipal();

		cin >> opcion;
		cout << "\n";
		switch(opcion){
			case 1 :
				menuIniciarSesion(s);
				break;

			case 2 :
				menuRegistrarse(s);
				break;

			case 3 :
				//Manual
				break;

			case 4 :
				cout << "Cerrando el programa..." << endl;
				// CLOSING the socket and cleaning Winsock...
				closesocket(s);
				WSACleanup();
				break;

			default:
				cout << "Esa opcion no existe, elija otra." << endl;
				menuPrincipal();
				cin >> opcion;
				cout << "\n";
				break;
		}

	} while (opcion != 4);

	return 0;
}

