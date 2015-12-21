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
#include "Cliente.h"
#include "ClienteInativo.h"
#include <list>
#include <cstdint>

using namespace std;

class Empresa
{private:
	string nome;
	vector <Servico*> servicos;
	Frota frota;
	float custoCong; // custo extra por capacidade de congelação de um camião
	float custoPerig; // custo extra por capacidade de transporte de cargas perigosas
	float custoDist; // custo por km percorrido pelo camião

	// Parte 2

	BST<Motorista> motoristas;
	inativosHash clientesInativos;

public:
	//Construtor
	Empresa(string nome);

	//Destrutor
	~Empresa(){};

	//Substitui a frota atual
	void setFrota(Frota frota);

	//Retorna um vetor com todos os serviços disponibilizados pela empresa
	vector<Servico*> getServicos() const;

	//Retorna a frota atual da empresa
	Frota getFrota() const;

	//Adiciona um seviço ao vetor de serviços
	void adicionaServico(Servico *s1);

	//Apaga um serviço do vetor de serviços, criando uma exceção se o serviço que se quer apagar não existir
	void retiraServico (Servico *s1);

	//Imprime no ecrã os clientes que estão a usar os serviços
	void readServicos() const;

	//Retorna um vetor com os serviços atualmente usados por um ou mais clientes
	vector< Servico*> returnAtivos();

	//Retorna um vetor com os serviços que não estão a ser usados
	vector< Servico*> returnInativos();

	//Imprime no monitor os preços e nomes dos serviços, ordenando-os de forma crescente de preço
	void printServicos();

	//Procura os serviços utilizados por um cliente
	vector< Servico*> servicoCliente(string nome, unsigned int nif);

	//Guarda a informação da empresa num ficheiro com o nome da empresa
	void saveEmpresa();

	//Vai buscar a informação ao ficheiro com o nome da empresa
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
	Motorista* encontraMotorista(string nome, unsigned int nif);

	void adicionaMotorista(const Motorista& m);

	int removeMotorista(const Motorista& m);
	int removeMotorista(string nome, unsigned int nif);

	int aumentaHorasMotorista(Motorista& m, unsigned int aumentoHoras);
	int aumentaHorasMotorista(string nome, unsigned int nif, unsigned int aumentoHoras);

	void updateMotorista(Motorista& m);
	
	Motorista getMaiorMotorista();
	Motorista getMenorMotorista();

	inativosHash getClientesInativos();
	void adicionaClienteInativo(const ClienteInativo& ci);
	bool contemClienteInativo(string umCliente, unsigned int Nif);
	void printClientesInativos();
	list<string> listaClientesInativos();

};




#endif /* SRC_EMPRESA_H_ */
