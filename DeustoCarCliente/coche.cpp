#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "coche.h"

using namespace std;

namespace comven
{
	Coche::Coche()
	{
		id = 0;
		marca = "No tiene marca";
		modelo = "No tiene modelo";
	}

	Coche::Coche(int id, string marca, string modelo)
	{
		this->id = id;
		this->marca = marca;
		this->modelo = modelo;
	}

	Coche::~Coche()
	{
	}

	int Coche::getId()
	{
		return id;
	}
	void Coche::setId(int id)
	{
		this->id = id;
	}
	string Coche::getMarca()
	{
		return marca;
	}
	void Coche::setMarca(string marca)
	{
		this->marca = marca;
	}
	string Coche::getModelo()
	{
		return modelo;
	}
	void Coche::setModelo(string modelo)
	{
		this->modelo = modelo;
	}
	void Coche::imprimirCoche(Coche c)
	{
		cout << "Id del coche: " << c.getId() << endl;
		cout << "Marca: " << c.getMarca() << endl;
		cout << "Modelo: " << c.getModelo() << endl;
	}
}
