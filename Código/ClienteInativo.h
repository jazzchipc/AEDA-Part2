/*
* ClientesInativos.h
*
*  Created on: 20/12/2015
*      Author: ASUS
*/

#ifndef AEDA_PART2_MASTER_CÓDIGO_CLIENTEINATIVO_H_
#define AEDA_PART2_MASTER_CÓDIGO_CLIENTEINATIVO_H_


#include <unordered_set>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "Cliente.h"

using namespace std;

class ClienteInativo
{
	string nome;
	unsigned int nif;
public:
	ClienteInativo(string nome, unsigned int nif);
	~ClienteInativo() {};
	string getNome() const;
	unsigned int getNif() const;
	void updateNome(string nome);
	void updateNif(unsigned int nif);
	bool operator==(const Cliente &c1);

};

struct clienteHash
{
	int operator() (const ClienteInativo& ci)
	{
		int v = 0;
		for (unsigned int i = 0; i < ci.getNome().size(); i++)
		{
			v = v * 37 + ci.getNome()[i];
		}
		return v;
	}

	bool operator() (const ClienteInativo& ci1, const ClienteInativo& ci2)
	{
		if (ci1.getNome() == ci2.getNome())
			return true;
		else
			return false;
	}
};


typedef unordered_set<ClienteInativo, clienteHash, clienteHash> inativosHash;



#endif /* AEDA_PART2_MASTER_CÓDIGO_CLIENTEINATIVO_H_ */
