/*
 * Empresa.h
 *
 *  Created on: 27/10/2015
 *      Author: ASUS
 */

#ifndef SRC_EMPRESA_H_
#define SRC_EMPRESA_H_


#include "Servico.h"
#include "Frota.h"
#include "BST.h"
#include "Motorista.h"

using namespace std;

class Empresa
{private:
	string nome;
	vector <Servico*> servicos;
	Frota frota;
	float custoCong; // custo extra por capacidade de congela��o de um cami�o
	float custoPerig; // custo extra por capacidade de transporte de cargas perigosas
	float custoDist; // custo por km percorrido pelo cami�o

	// Parte 2

	BST<Motorista> motoristas;

public:
	//Construtor
	Empresa(string nome);

	//Destrutor
	~Empresa(){};

	//Substitui a frota atual
	void setFrota(Frota frota);

	//Retorna um vetor com todos os servi�os disponibilizados pela empresa
	vector<Servico*> getServicos() const;

	//Retorna a frota atual da empresa
	Frota getFrota() const;

	//Adiciona um sevi�o ao vetor de servi�os
	void adicionaServico(Servico *s1);

	//Apaga um servi�o do vetor de servi�os, criando uma exce��o se o servi�o que se quer apagar n�o existir
	void retiraServico (Servico *s1);

	//Imprime no ecr� os clientes que est�o a usar os servi�os
	void readServicos() const;

	//Retorna um vetor com os servi�os atualmente usados por um ou mais clientes
	vector< Servico*> returnAtivos();

	//Retorna um vetor com os servi�os que n�o est�o a ser usados
	vector< Servico*> returnInativos();

	//Imprime no monitor os pre�os e nomes dos servi�os, ordenando-os de forma crescente de pre�o
	void printServicos();

	//Procura os servi�os utilizados por um cliente
	vector< Servico*> servicoCliente(string nome, unsigned int nif);

	//Guarda a informa��o da empresa num ficheiro com o nome da empresa
	void saveEmpresa();

	//Vai buscar a informa��o ao ficheiro com o nome da empresa
	int loadEmpresa();

	float getCustoCap() const;
	float getCustoCong() const;
	float getCustoPerig() const;
	float getCustoDist() const;

	void setCustoCap(float n);
	void setCustoCong(float n);
	void setCustoPerig(float n); 
	void setCustoDist(float n);
	
	/***********
	 * Parte 2 *
	 ***********/

	//Motoristas

	BST<Motorista> getMotoristas();
	void adicionaMotorista(const Motorista& m);

};




#endif /* SRC_EMPRESA_H_ */
