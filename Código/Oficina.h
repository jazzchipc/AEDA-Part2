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
#include <queue>

using namespace std;

class ServicoOficina
{
private:
	bool especifico;
	unsigned int duracao; // em dias

public:
	ServicoOficina(bool especifico, unsigned int duracao) { this->especifico = especifico; this->duracao = duracao; };
	~ServicoOficina() {};

	bool getEspecifico() { return this->especifico; };
	unsigned int getDuracao() { return this->duracao; }
};

class Oficina
{private:
	string denominacao;
	string especialidade;
	unsigned int disponibilidade;

	queue<ServicoOficina> servicosAtivos;

public:
	Oficina(string denominacao, string especialidade, unsigned int disponibilidade);
	Oficina(){};
	~Oficina(){};
	string getDenominacao() const;
	string getEspecialidade() const;
	unsigned int getDisponibilidade() const;


	void updateDenominacao(string denominacao);
	void updateEspecialidade(string especialidade);
	void updateDisponibilidade(unsigned int disponibilidade);

	bool operator<(const Oficina& o1) const;
};





#endif /* SRC_OFICINA_H_ */
