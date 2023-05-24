#include <iostream>
#include <string>

using namespace std;

#ifndef VENTA_H_
#define VENTA_H_

namespace ven
{
class Venta
	{
	private:
		int id;
		int precio;
		string fechaVenta;
		int idVendedor;
		int idCoche;
	public:
		Venta();
		Venta(int id, int precio, string fechaVenta, int idVendedor, int idCoche);
		~Venta();
		int getId();
		void setId(int id);
		int getPrecio();
		void setPrecio(int precio);
		string getFechaVenta();
		void setFechaVenta(string fechaVenta);
		int getIdVendedor();
		void setIdVendedor(int idVendedor);
		int getIdCoche();
		void setIdCoche(int idCoche);
		void imprimirVenta(Venta v);
	};
}

#endif /* VENTA_H_ */
