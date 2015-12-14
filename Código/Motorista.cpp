/*
 * Motorista.cpp
 *
 *  Created on: 14/12/2015
 *      Author: up201402717
 */

#include "Motorista.h"

/**
* \brief Cria um Motorista usando os parâmetros para definir as sua caracteristicas
* \param nome Nome do Motorista
* \param nif NIF do Motorista
* \param horas Número de horas diárias (já efetuadas)
* \return Esta função não possui retorno
*/
Motorista::Motorista(string nome, unsigned int nif, unsigned int horas)
{
	this->nome = nome;
	this->nif = nif;
	this->horas = 0;
}

/**
* \brief Obtém o Nome de um Motorista
* \return Retorna o Nome de um Motorista
*/
string Motorista::getNome() const
{
	return nome;
}

/**
* \brief Obtém o NIF de um Motorista
* \return Retorna o NIF de um Motorista
*/
unsigned int Motorista::getNif() const
{
	return nif;
}

/**
* \brief Obtém o número de horas de serviço de um Motorista
* \return Retorna o número de horas de serviço de um Motorista
*/
unsigned int Motorista::getHoras() const
{
	return horas;
}

/**
* \brief Altera, se necessário, o nome de um Motorista
* \param nome Novo nome
* \return Esta função não possui retorno
*/
void Motorista::updateNome(string nome)
{
	this->nome = nome;
}

/**
* \brief Altera, se necessário, o nif de um Motorista
* \param nif Novo nif
* \return Esta função não possui retorno
*/
void Motorista::updateNif(unsigned int nif)
{
	this->nif = nif;
}

/**
* \brief Altera, se necessário, o número de horas de serviço de um Motorista
* \param nif Novo valor das horas
* \return Esta função não possui retorno
*/
void Motorista::updateHoras(unsigned int horas)
{
	this->horas = horas;
}
