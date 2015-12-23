/*
 * Oficina.cpp
 *
 *  Created on: 14/12/2015
 *      Author: up201402717
 */

#include "Oficina.h"

/**
* \brief Cria uma Oficina usando os par�metros para definir as sua caracteristicas
* \param denominacao Denomina��o da Oficina
* \param especialidade Marca em que a Oficina � especializada
* \param disponibilidade N�mero de dias at� que a Oficina possa efetuar o servi�o
* \return Esta fun��o n�o possui retorno
*/
Oficina::Oficina(string denominacao, string especialidade, unsigned int disponibilidade)
{
	this->denominacao = denominacao;
	this->especialidade = especialidade;
	this->disponibilidade = disponibilidade;
}

/**
* \brief Obt�m a Denomina��o de uma Oficina
* \return Retorna a Denomina��o de uma Oficina
*/
string Oficina::getDenominacao() const
{
	return denominacao;
}

/**
* \brief Obt�m a Especialidade de uma Oficina
* \return Retorna a Especialidade de uma Oficina
*/
string Oficina::getEspecialidade() const
{
	return especialidade;
}

/**
* \brief Obt�m a Disponibilidade de uma Oficina
* \return Retorna a Disponibilidade de uma Oficina
*/
unsigned int Oficina::getDisponibilidade() const
{
	return disponibilidade;
}

/**
* \brief Altera, se necess�rio, a denomina��o de uma Oficina
* \param denominacao Nova denomina��o
* \return Esta fun��o n�o possui retorno
*/
void Oficina::updateDenominacao(string denominacao)
{
	this->denominacao = denominacao;
}

/**
* \brief Altera, se necess�rio, a especialidade de uma Oficina
* \param denominacao Nova especialidade
* \return Esta fun��o n�o possui retorno
*/
void Oficina::updateEspecialidade(string especialidade)
{
	this->especialidade = especialidade;
}

/**
* \brief Altera, se necess�rio, a disponibilidade de uma Oficina
* \param denominacao Nova disponibilidade
* \return Esta fun��o n�o possui retorno
*/
void Oficina::updateDisponibilidade(unsigned int disponibilidade)
{
	this->disponibilidade = disponibilidade;
}

bool Oficina::operator<(const Oficina& o1) const
{
	if (this->disponibilidade > o1.disponibilidade)
		return true;
	else
		return false;
}
