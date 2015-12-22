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
#include <list>
#include <iomanip>

using namespace std;

const int WIDTH_NOME = 20;
const int WIDTH_NIF = 10;
const int WIDTH_HORAS = 8;

class Motorista
{private:
	string nome;
	unsigned int nif;
	float horas;
public:
	Motorista(string nome, unsigned int nif, float horas);
	Motorista(string nome, unsigned int nif);
	Motorista();
	~Motorista(){};
	string getNome() const;
	unsigned int getNif() const;
	float getHoras() const;
	void updateNome(string nome);
	void updateNif(unsigned int nif);
	void updateHoras(float horas);
	bool operator<(const Motorista& m2) const;
	bool operator==(const Motorista& m2) const;

	friend ostream& operator << (ostream& os, const Motorista& m);

};

void printListaMotoristas(list<Motorista> l);


#endif /* SRC_MOTORISTA_H_ */
