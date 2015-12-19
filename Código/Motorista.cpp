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
	this->horas = horas;
}

/**
* \brief Cria um Motorista usando os parâmetros para definir as sua caracteristicas, mas com as horas inicias predefinidas em 0
* \param nome Nome do Motorista
* \param nif NIF do Motorista
* \return Esta função não possui retorno
*/
Motorista::Motorista(string nome, unsigned int nif)
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

/**
* \brief Operador para verificar se um Motorista é maior ou menor que outro
* \param m2 Motorista a comparar
* \return Retorna verdadeiro se o primeiro a comparar tem menos horas de serviço diárias, e falso caso contrário
*/
bool Motorista::operator<(const Motorista& m2) const
{
	if(horas < m2.horas)
		return true;
	else return false;
}

/**
* \brief Operador para verificar se um Motorista é igual a outro
* \param m1 Primeiro motorista a comparar
* \param m2 Segundo motorista a comparar
* \return Retorna verdadeiro se os dois motoristas forem iguais e false se forem diferentes
*/
bool Motorista::operator==(const Motorista& m2) const
{
	if((this->nome == m2.nome) && (this->nif == m2.nif))
		return true;
	else
		return false;
}

/**
 * @brief Overload do operador "<<" para poder imprimir um Motorista no ecrã
 * @param m Motorista a exportar
 * @return Ostream com os atributos do Motorista
 */
ostream& operator << (ostream& os, const Motorista& m)
{
	os << m.getNome() << "; " << m.getNif() << "; " << m.getHoras() << endl;

	return os;
}
