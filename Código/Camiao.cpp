/*
* Camiao.cpp
*
*  Created on: 27/10/2015
*      Author: ASUS
*/

/*TEST*/

#include "Camiao.h"
#include "Cliente.h"
#include "Empresa.h"
#include "Frota.h"
#include "Servico.h"
#include "sequentialSearch.h"

/**
* \brief Cria um Cami�o usando os par�metros para definir as sua caracteristicas, com a marca "Volvo" por defeito
* \param codigo Codigo identificador do Cami�o
* \param cap_max Capacidade M�xima do Cami�o
* \param cap_cong Valor L�gico da Capacidade de Congela��o do Cami�o
* \param cap_perig Valor L�gico da Capacidade de Transporte de Cargas Perigosas do Cami�o
* \param taxa Custo da utiliza��o do cami�o por cada quil�metro percorrido (�/km)
* \return Esta fun��o n�o possui retorno
*/
Camiao::Camiao(int codigo, unsigned int cap_max, bool cap_cong, bool cap_perig)
{
	this->codigo = codigo;
	this->cap_max = cap_max;
	this->cap_cong = cap_cong;
	this->cap_perig = cap_perig;

	this->marca = "Volvo";
}

/**
* \brief Cria um Cami�o usando os par�metros para definir as sua caracteristicas
* \param codigo Codigo identificador do Cami�o
* \param cap_max Capacidade M�xima do Cami�o
* \param cap_cong Valor L�gico da Capacidade de Congela��o do Cami�o
* \param cap_perig Valor L�gico da Capacidade de Transporte de Cargas Perigosas do Cami�o
* \param taxa Custo da utiliza��o do cami�o por cada quil�metro percorrido (�/km)
* \param marca Marca do cami�o
* \return Esta fun��o n�o possui retorno
*/
Camiao::Camiao(int codigo, unsigned int cap_max, bool cap_cong, bool cap_perig, string marca)
{
	this->codigo = codigo;
	this->cap_max = cap_max;
	this->cap_cong = cap_cong;
	this->cap_perig = cap_perig;
	this->marca = marca;
}

Camiao::Camiao(int codigo, string marca)
{
	this->codigo = codigo;
	this->cap_max = 1000;
	this->cap_cong = false;
	this->cap_perig = false;
	this->marca = marca;
} 

/**
* \brief Obt�m a Capacidade M�xima de um Cami�o
* \return Retorna a Capacidade M�xima de um Cami�o
*/
unsigned int Camiao::getCapMax() const
{
	return cap_max;
}

/**
* \brief Verifica se um Cami�o tem ou n�o capacidade de congela��o
* \return Retorna o valor l�gico da capacidade de congela��o
*/
bool Camiao::getCapCong() const
{
	return cap_cong;
}

/**
* \brief Verifica se um Cami�o tem ou n�o capacidade de transportar cargas perigosas
* \return Retorna o valor l�gico da capacidade de transporte de cargas perigosas
*/
bool Camiao::getCapPerig() const
{
	return cap_perig;
}

/**
* \brief Obt�m o C�digo identificador de um Cami�o
* \return Retorna o C�digo de um Cami�o
*/
int Camiao::getCodigo() const
{
	return codigo;
}

/**
* \brief Obt�m os servi�os para os quais um cami�o est� a ser usado
* \return Retorna um vetor com esses servi�os
*/

vector <Servico* > Camiao::getServicos() const
{
	return servicos;
}


/**
* \brief Altera, se necess�rio, o c�digo de um Cami�o
* \param codigo Novo valor
* \return Esta fun��o n�o possui retorno
*/
void Camiao::updateCodigo(int codigo)
{
	this->codigo = codigo;
}

/**
* \brief Altera, se necess�rio, a capacidade m�xima de um Cami�o
* \param cap_max Novo valor
* \return Esta fun��o n�o possui retorno
*/
void Camiao::updateCapMax(unsigned int cap_max)
{
	this->cap_max = cap_max;
}

/**
* \brief Altera, se necess�rio, o valor l�gico da capacidade de congela��o de um cami�o
* \param cap_cong Novo valor
* \return Esta fun��o n�o possui retorno
*/
void Camiao::updateCapCong(bool cap_cong)
{
	this->cap_cong = cap_cong;
}
/**
* \brief Adiciona um servi�o que utiliza o cami�o
* \param *s1 Apontador para o servi�o que usa o cami�o
* \return Esta fun��o n�o poussui retorno
*/
void Camiao::adicionaServico(Servico *s1)
{
	servicos.push_back(s1);
}

/**
* \brief Retira um servi�o que utiliza o cami�o
* \param *s1 Apontador para o servi�o a retirar
* \return Esta fun��o n�o poussui retorno
*/

void Camiao::retiraServico(Servico *s1)
{
	int index = sequentialSearch(servicos, s1);
	if (index == -1)
		throw ServicoInexistente(s1->getId());
	else
		servicos.erase(servicos.begin() + index);
}

/**
* \brief Operador utilizado para verificar se dois cami�es s�o iguais
* \param c1 Um dos cami�es a comparar
* \return Retorna true se os cami�es forem iguais e false se n�o forem
*/
bool Camiao::operator==(const Camiao &c1)
{
	if (c1.codigo == this->codigo)
		return true;
	else
		return false;
}




