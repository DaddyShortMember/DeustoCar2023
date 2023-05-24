#include <iostream>
#include <string>

using namespace std;

#ifndef COCHE_H_
#define COCHE_H_

namespace comven
{
class Coche
	{
	private:
		int id;
		string marca;
		string modelo;
	public:
		Coche();
		Coche(int id, string marca, string modelo);
		~Coche();
		int getId();
		void setId(int id);
		string getMarca();
		void setMarca(string marca);
		string getModelo();
		void setModelo(string modelo);
		void imprimirCoche(Coche c);
	};
}

#endif /* COCHE_H_ */
