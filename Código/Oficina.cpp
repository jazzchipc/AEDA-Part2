/*
 * Oficina.cpp
 *
 *  Created on: 14/12/2015
 *      Author: up201402717
 */

#include "Oficina.h"

/**
* \brief Cria uma Oficina usando os parâmetros para definir as sua caracteristicas
* \param denominacao Denominação da Oficina
* \param especialidade Marca em que a Oficina é especializada
* \param disponibilidade Número de dias até que a Oficina possa efetuar o serviço
* \return Esta função não possui retorno
*/
Oficina::Oficina(string denominacao, string especialidade, unsigned int disponibilidade)
{
	this->denominacao = denominacao;
	this->especialidade = especialidade;
	this->disponibilidade = disponibilidade;
}

/**
* \brief Obtém a Denominação de uma Oficina
* \return Retorna a Denominação de uma Oficina
*/
string Oficina::getDenominacao() const
{
	return denominacao;
}

/**
* \brief Obtém a Especialidade de uma Oficina
* \return Retorna a Especialidade de uma Oficina
*/
string Oficina::getEspecialidade() const
{
	return especialidade;
}

/**
* \brief Obtém a Disponibilidade de uma Oficina
* \return Retorna a Disponibilidade de uma Oficina
*/
unsigned int Oficina::getDisponibilidade() const
{
	return disponibilidade;
}

/**
* \brief Altera, se necessário, a denominação de uma Oficina
* \param denominacao Nova denominação
* \return Esta função não possui retorno
*/
void Oficina::updateDenominacao(string denominacao)
{
	this->denominacao = denominacao;
}

/**
* \brief Altera, se necessário, a especialidade de uma Oficina
* \param denominacao Nova especialidade
* \return Esta função não possui retorno
*/
void Oficina::updateEspecialidade(string especialidade)
{
	this->especialidade = especialidade;
}

/**
* \brief Altera, se necessário, a disponibilidade de uma Oficina
* \param denominacao Nova disponibilidade
* \return Esta função não possui retorno
*/
void Oficina::updateDisponibilidade(unsigned int disponibilidade)
{
	this->disponibilidade = disponibilidade;
}

/**
* \brief Compara duas Oficinas para verificar se uma é maior ou menos que a outra
* \param o1 Uma das Oficinas a comparar
* \return Retorna true se o1 é menor e false caso contrário
*/
bool Oficina::operator<(const Oficina& o1) const
{
	if (this->disponibilidade > o1.disponibilidade)
		return true;
	else
		return false;
}

void Oficina::removeServico()
{
	this->servicosAtivos.pop();
}

void Oficina::adicionaServico(ServicoOficina s)
{
	this->servicosAtivos.push(s);
}

queue<ServicoOficina> Oficina::getServicosAtivos()
{
	return this->servicosAtivos;
}
