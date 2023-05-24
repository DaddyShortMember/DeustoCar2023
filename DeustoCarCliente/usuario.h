#include <iostream>
#include <string>
using namespace std;

#ifndef USUARIO_H_
#define USUARIO_H_

namespace login
{
class Usuario
	{
	private:
		int id;
		string nombre;
		string email;
		string contrasenya;
		int saldo;
	public:
		Usuario();
		Usuario(int id, string nombre, string email, string contrasenya, int saldo);
		~Usuario();
		int getId();
		void setId(int id);
		string getNombre();
		void setNombre(string nombre);
		string getEmail();
		void setEmail(string email);
		string getContrasenya();
		void setContrasenya(string contrasenya);
		int getSaldo();
		void setSaldo(int saldo);
		void imprimirUsuario(Usuario u);
	};
}

#endif /* USUARIO_H_ */
