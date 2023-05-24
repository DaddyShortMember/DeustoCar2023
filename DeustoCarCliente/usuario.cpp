#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "usuario.h"

using namespace std;

namespace login
{
	Usuario::Usuario()
	{
		id = 0;
		nombre = "MisterX";
		email = "MisterX@MisterX.com";
		contrasenya = "MisterX";
		saldo = 0;
	};

	Usuario::Usuario(int id, string nombre, string email, string contrasenya, int saldo)
	{
		this->id = id;
		this->nombre = nombre;
		this->email = email;
		this->contrasenya = contrasenya;
		this->saldo = saldo;
	};

	Usuario::~Usuario(){
	};

	int Usuario::getId()
	{
		return id;
	};
	void Usuario::setId(int id)
	{
		this->id = id;
	};
	string Usuario::getNombre()
	{
		return nombre;
	};
	void Usuario::setNombre(string nombre)
	{
		this->nombre = nombre;
	};
	string Usuario::getEmail()
	{
		return email;
	};
	void Usuario::setEmail(string email)
	{
		this->email = email;
	};
	string Usuario::getContrasenya()
	{
		return contrasenya;
	};
	void Usuario::setContrasenya(string contrasenya)
	{
		this->contrasenya = contrasenya;
	};
	int Usuario::getSaldo()
	{
		return saldo;
	};
	void Usuario::setSaldo(int saldo)
	{
		this->saldo = saldo;
	};
	void Usuario::imprimirUsuario(Usuario u)
	{
		cout << "Id del usuario: " << u.getId() << endl;
		cout << "Nombre del usuario: " << u.getNombre() << endl;
		cout << "Email del usuario: " << u.getEmail() << endl;
		cout << "Contrasenya  del usuario: " << u.getContrasenya() << endl;
		cout << "Saldo del usuario: " << u.getSaldo() << endl;
	};
}
