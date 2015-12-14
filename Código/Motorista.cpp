/*
 * Motorista.cpp
 *
 *  Created on: 14/12/2015
 *      Author: up201402717
 */

#include "Motorista.h"

/**
* \brief Cria um Motorista usando os par�metros para definir as sua caracteristicas
* \param nome Nome do Motorista
* \param nif NIF do Motorista
* \param horas N�mero de horas di�rias (j� efetuadas)
* \return Esta fun��o n�o possui retorno
*/
Motorista::Motorista(string nome, unsigned int nif, unsigned int horas)
{
	this->nome = nome;
	this->nif = nif;
	this->horas = 0;
}

/**
* \brief Obt�m o Nome de um Motorista
* \return Retorna o Nome de um Motorista
*/
string Motorista::getNome() const
{
	return nome;
}

/**
* \brief Obt�m o NIF de um Motorista
* \return Retorna o NIF de um Motorista
*/
unsigned int Motorista::getNif() const
{
	return nif;
}

/**
* \brief Obt�m o n�mero de horas de servi�o de um Motorista
* \return Retorna o n�mero de horas de servi�o de um Motorista
*/
unsigned int Motorista::getHoras() const
{
	return horas;
}

/**
* \brief Altera, se necess�rio, o nome de um Motorista
* \param nome Novo nome
* \return Esta fun��o n�o possui retorno
*/
void Motorista::updateNome(string nome)
{
	this->nome = nome;
}

/**
* \brief Altera, se necess�rio, o nif de um Motorista
* \param nif Novo nif
* \return Esta fun��o n�o possui retorno
*/
void Motorista::updateNif(unsigned int nif)
{
	this->nif = nif;
}

/**
* \brief Altera, se necess�rio, o n�mero de horas de servi�o de um Motorista
* \param nif Novo valor das horas
* \return Esta fun��o n�o possui retorno
*/
void Motorista::updateHoras(unsigned int horas)
{
	this->horas = horas;
}
