#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "compra.h"

using namespace std;

namespace com
{
	Compra::Compra(){
		id = 0;
		precio = 0;
		fechaCompra = "No hay fecha";
		idComprador = 0;
		idVendedor = 0;
		idCoche = 0;
	};

	Compra::Compra(int id, int precio, string fechaCompra, int idComprador, int idVendedor, int idCoche){
		this->id = id;
		this->precio = precio;
		this->fechaCompra = fechaCompra;
		this->idComprador = idComprador;
		this->idVendedor = idVendedor;
		this->idCoche = idCoche;
	};

	Compra::~Compra(){

	};

	int Compra::getId(){
		return this->id;
	};

	void Compra::setId(int id){
		this->id = id;
	};

	int Compra::getPrecio(){
		return this->precio;
	};

	void Compra::setPrecio(int precio){
		this->precio = precio;
	};

	string Compra::getFechaCompra(){
		return this->fechaCompra;
	};

	void Compra::setFechaCompra(string fechaCompra){
		this->fechaCompra = fechaCompra;
	};
	int Compra::getIdComprador(){
		return this->idComprador;
	};

	void Compra::setIdComprador(int idComprador){
		this->idComprador = idComprador;
	};
	int Compra::getIdVendedor(){
		return this->idVendedor;
	};

	void Compra::setIdVendedor(int idVendedor){
		this->idVendedor = idVendedor;
	};

	int Compra::getIdCoche(){
		return this->idCoche;
	};

	void Compra::setIdCoche(int idCoche){
		this->idCoche = idCoche;
	};
	void Compra::imprimirCompra(Compra c){
		cout << "Id de compra: " << c.getId() << endl;
		cout << "Precio de compra: " << c.getPrecio() << endl;
		cout << "Fecha de compra: " << c.getFechaCompra() << endl;
		cout << "Id del comprador: " << c.getIdComprador() << endl;
		cout << "Id del vendedor: " << c.getIdVendedor() << endl;
		cout << "Id del coche: " << c.getIdCoche() << endl;
	};
}


