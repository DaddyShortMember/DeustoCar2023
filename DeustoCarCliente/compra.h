#include <iostream>
#include <string>

using namespace std;

#ifndef COMPRA_H_
#define COMPRA_H_

namespace com
{
class Compra
	{
	private:
		int id;
		int precio;
		string fechaCompra;
		int idComprador;
		int idVendedor;
		int idCoche;
	public:
		Compra();
		Compra(int id, int precio, string fechaCompra, int idComprador, int idVendedor, int idCoche);
		~Compra();
		int getId();
		void setId(int id);
		int getPrecio();
		void setPrecio(int precio);
		string getFechaCompra();
		void setFechaCompra(string fechaCompra);
		int getIdComprador();
		void setIdComprador(int idComprador);
		int getIdVendedor();
		void setIdVendedor(int idVendedor);
		int getIdCoche();
		void setIdCoche(int idCoche);
		void imprimirCompra(Compra c);
	};
}

#endif /* COMPRA_H_ */
