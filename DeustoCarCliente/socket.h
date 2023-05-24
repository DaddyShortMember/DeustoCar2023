#include "usuario.h"
#include "coche.h"
#include "venta.h"
#include "compra.h"
#include <winsock2.h>

using namespace comven;
using namespace login;
using namespace com;
using namespace ven;

#ifndef SOCKET_H_
#define SOCKET_H_

class Socket {
public:
	SOCKET openSocket();
	void closeSocket(SOCKET s);
	Venta* SocketGetVentas(SOCKET s);
	void SocketAnyadirVenta(SOCKET s, Venta r);
	Compra* SocketGetCompras(SOCKET s);
	void SocketAnyadirCompras(SOCKET s, Compra c);
	Usuario* SocketGetUsuarios(SOCKET s);
	void SocketAnyadirUsuario(SOCKET s, Usuario u);
	void SocketModificarUsuario(SOCKET s, Usuario u);
	Coche* SocketGetCoches(SOCKET s);
	void SocketModificarCoche(SOCKET s, Coche c);

};

#endif /* SOCKET_H_ */
