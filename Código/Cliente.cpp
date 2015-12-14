/*
* Cliente.cpp
*
*  Created on: 27/10/2015
*      Author: ASUS
*/

#include "Camiao.h"
#include "Cliente.h"
#include "Empresa.h"
#include "Frota.h"
#include "Servico.h"
#include "sequentialSearch.h"

/**
* \brief Cria um Cliente usando os par�metros para definir as sua caracteristicas
* \param nome Nome do Cliente
* \param nif NIF do Cliente
* \return Esta fun��o n�o possui retorno
*/
Cliente::Cliente(string nome, unsigned int nif)
{
	this->nome = nome;
	this->nif = nif;
}

/**
* \brief Obt�m o Nome de um Cliente
* \return Retorna o Nome de um Cliente
*/
string Cliente::getNome() const
{
	return nome;
}

/**
* \brief Obt�m o NIF de um Cliente
* \return Retorna o NIF de um Cliente
*/
unsigned int Cliente::getNif() const
{
	return nif;
}

/**
* \brief Altera, se necess�rio, o nome de um Cliente
* \param codigo Novo valor
* \return Esta fun��o n�o possui retorno
*/
void Cliente::updateNome(string nome)
{
	this->nome = nome;
}

/**
* \brief Altera, se necess�rio, o nif de um Cliente
* \param codigo Novo valor
* \return Esta fun��o n�o possui retorno
*/
void Cliente::updateNif(unsigned int nif)
{
	this->nif = nif;
}

/**
* \brief Operador utilizado para verificar se dois clientes s�o iguais
* \param c1 Cliente a comparar
* \return Retorna true se os clientes forem iguais e false se n�o forem
*/
bool Cliente::operator==(const Cliente &c1)
{
	if (c1.nif == this->nif)
		return true;
	else
		return false;
}



