/*
 * Motorista.h
 *
 *  Created on: 14/12/2015
 *      Author: up201402717
 */

#ifndef SRC_MOTORISTA_H_
#define SRC_MOTORISTA_H_

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Motorista
{private:
	string nome;
	unsigned int nif;
	unsigned int horas;
public:
	Motorista(string nome, unsigned int nif, unsigned int horas);
	Motorista(string nome, unsigned int nif);
	Motorista();
	~Motorista(){};
	string getNome() const;
	unsigned int getNif() const;
	unsigned int getHoras() const;
	void updateNome(string nome);
	void updateNif(unsigned int nif);
	void updateHoras(unsigned int horas);
	bool operator<(const Motorista& m2) const;
	bool operator==(const Motorista& m2) const;

	friend ostream& operator << (ostream& os, const Motorista& m);

};



#endif /* SRC_MOTORISTA_H_ */
