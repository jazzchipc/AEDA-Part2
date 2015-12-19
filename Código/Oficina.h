/*
 * Oficina.h
 *
 *  Created on: 14/12/2015
 *      Author: up201402717
 */

#ifndef SRC_OFICINA_H_
#define SRC_OFICINA_H_

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Oficina
{private:
	string denominacao;
	string especialidade;
	unsigned int disponibilidade;
public:
	Oficina(string denominacao, string especialidade, unsigned int disponibilidade);
	~Oficina();
	string getDenominacao() const;
	string getEspecialidade() const;
	unsigned int getDisponibilidade() const;
	void updateDenominacao(string denominacao);
	void updateEspecialidade(string especialidade);
	void updateDisponibilidade(unsigned int disponibilidade);

};

struct oficinaHash
{
	int operator() (const Oficina& o1)
	{
		int v = 0;
		for(unsigned int i = 0; i < o1.getDenominacao().size(); i++)
		{
			v = v*37 + o1.getDenominacao()[i];
		}
		return v;
	}

	bool operator() (const Oficina& o1, const Oficina& o2)
	{
		if(o1.getDenominacao() == o2.getDenominacao())
			return true;
		else
			return false;
	}
};

#endif /* SRC_OFICINA_H_ */
