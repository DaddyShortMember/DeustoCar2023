#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "venta.h"

using namespace std;

namespace ven
{
	Venta::Venta(){
		id = 0;
		precio = 0;
		fechaVenta = "No hay fecha";
		idVendedor = 0;
		idCoche = 0;
	};

	Venta::Venta(int id, int precio, string fechaVenta, int idVendedor, int idCoche){
		this->id = id;
		this->precio = precio;
		this->fechaVenta = fechaVenta;
		this->idVendedor = idVendedor;
		this->idCoche = idCoche;
	};

	Venta::~Venta(){

	};

	int Venta::getId(){
		return this->id;
	};

	void Venta::setId(int id){
		this->id = id;
	};

	int Venta::getPrecio(){
		return this->precio;
	};

	void Venta::setPrecio(int precio){
		this->precio = precio;
	};

	string Venta::getFechaVenta(){
		return this->fechaVenta;
	};

	void Venta::setFechaVenta(string fechaVenta){
		this->fechaVenta = fechaVenta;
	};

	int Venta::getIdVendedor(){
		return this->idVendedor;
	};

	void Venta::setIdVendedor(int idVendedor){
		this->idVendedor = idVendedor;
	};

	int Venta::getIdCoche(){
		return this->idCoche;
	};

	void Venta::setIdCoche(int idCoche){
		this->idCoche = idCoche;
	};
	void Venta::imprimirVenta(Venta v){
		cout << "Id de venta: " << v.getId() << endl;
		cout << "Precio de venta: " << v.getPrecio() << endl;
		cout << "Fecha de venta: " << v.getFechaVenta() << endl;
		cout << "Id del vendedor: " << v.getIdVendedor() << endl;
		cout << "Id del coche: " << v.getIdCoche() << endl;
	};

}



