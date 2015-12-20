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



#endif /* SRC_OFICINA_H_ */
