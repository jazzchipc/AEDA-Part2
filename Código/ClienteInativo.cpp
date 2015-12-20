/*
 * ClienteInativo.cpp
 *
 *  Created on: 20/12/2015
 *      Author: ASUS
 */

#include "ClienteInativo.h"

using namespace std;

/**
* \brief Cria um Cliente usando os parâmetros para definir as sua caracteristicas
* \param nome Nome do Cliente
* \param nif NIF do Cliente
* \return Esta função não possui retorno
*/
ClienteInativo::ClienteInativo(string nome, unsigned int nif)
{
	this->nome = nome;
	this->nif = nif;
}

/**
* \brief Obtém o Nome de um Cliente
* \return Retorna o Nome de um Cliente
*/
string ClienteInativo::getNome() const
{
	return nome;
}

/**
* \brief Obtém o NIF de um Cliente
* \return Retorna o NIF de um Cliente
*/
unsigned int ClienteInativo::getNif() const
{
	return nif;
}

/**
* \brief Altera, se necessário, o nome de um Cliente
* \param nome Novo nome
* \return Esta função não possui retorno
*/
void ClienteInativo::updateNome(string nome)
{
	this->nome = nome;
}

/**
* \brief Altera, se necessário, o nif de um Cliente
* \param nif Novo nif
* \return Esta função não possui retorno
*/
void ClienteInativo::updateNif(unsigned int nif)
{
	this->nif = nif;
}


/**
* \brief Operador utilizado para verificar se dois clientes são iguais
* \param c1 Cliente a comparar
* \return Retorna true se os clientes forem iguais e false se não forem
*/
bool ClienteInativo::operator==(const Cliente &c1)
{
	if (c1.getNif() == this->nif)
		return true;
	else
		return false;
}



