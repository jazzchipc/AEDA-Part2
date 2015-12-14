/*
 * Servico.h
 *
 *  Created on: 27/10/2015
 *      Author: ASUS
 */

#ifndef SRC_SERVICO_H_
#define SRC_SERVICO_H_

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "Cliente.h"

using namespace std;

class Servico
{private:
	int id;
	float preco;
	float distancia;
	vector <Cliente*> clientes;
	bool status;	// status = true se o servi�o est� a ser usado por algu�m.
					// status = false caso contr�rio
public:
	//Construtor
	Servico(int id, float preco, float distancia);

	//Destrutor
	~Servico() {};

	//Altera status do servi�o
	void setStatus(bool status);

	//Retorna o ID do servi�o
	int getId() const;

	//Retorna o status do servi�o
	bool getStatus() const;
	
	//Retorna uma string com "ativo" (a ser usado por clientes) ou "inativo"
	string printStatus();

	//Retorna o pre�o do servi�o
	float getPreco() const;

	float getDistancia() const;

	//Retorna o vetor de clientes que est� a usufruir do servi�o
	vector<Cliente*> getClientes() const;

	//Adiciona um cliente que tenha requisitado o servi�o
	void adicionaCliente(Cliente *j1);

	//Retira um cliente que use o servi�o, lan�ando uma exce��o caso o cliente n�o seja encontrado
	void retiraCliente(Cliente *j1);

	//Imprime a lista de clientes que usa o servi�o
	void readClientes() const;

	//Altera o pre�o do servi�o
	void updatePreco(float preco);

	//Retorna true se dois servi�os tiverem o mesmo ID
	bool operator==(const Servico& s1);

};

class ServicoInexistente
{
	int codigo;
public:
	int getCodigo() { return codigo; };
	ServicoInexistente(int codigo) : codigo(codigo) {};
};


#endif /* SRC_SERVICO_H_ */
