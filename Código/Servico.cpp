/*
* Servico.cpp
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
* \brief Cria um Servi�o usando os par�metros para definir as sua caracteristicas
* \param id ID do Servi�o
* \param preco Pre�o do Servi�o em custo por quilograma de carga (�/kg)
* \param distancia Dist�ncia que o cami�o vai percorrer durante o servi�o (km)
* \return Esta fun��o n�o possui retorno
*/
Servico::Servico(int id, float preco, float distancia)
{
	this->id = id;
	this->preco = preco;
	this->distancia = distancia;
	status = false;
}

/**
* \brief Atribui um status a um Servi�o, ativo(true) ou inativo(false)
* \param status Status a atribuir
* \return Esta fun��o n�o possui retorno
*/
void Servico::setStatus(bool status)
{
	this->status = status;
}

/**
* \brief Obt�m o ID de um Servi�o
* \return Retorna o ID de um Servi�o
*/
int Servico::getId() const
{
	return id;
}

/**
* \brief Verifica se um Servi�o est� ou n�o ativo
* \return Retorna o valor l�gico do status
*/
bool Servico::getStatus() const
{
	return status;
}

/**
* \brief Averigua o valor l�gico do status
* \return Retorna o status de um Servi�o, ativo ou inativo
*/
string Servico::printStatus()
{
	if (this->status)
		return "Ativo";
	else
		return "Inativo";
}

/**
* \brief Obt�m o Pre�o de um Servi�o
* \return Retorna o Pre�o de um Servi�o
*/
float Servico::getPreco() const
{
	return preco;
}

/**
* \brief Altera, se necess�rio, o pre�o de um Servi�o
* \param preco Novo valor (em �/kg) do servi�o
* \return Esta fun��o n�o possui retorno
*/
void Servico::updatePreco(float preco)
{
	this->preco = preco;
}

/**
* \brief Obt�m o vetor que guarda todos os Clientes
* \return Retorna o vetor
*/
vector<Cliente*> Servico::getClientes() const
{
	return clientes;
}

/**
* \brief Obt�m a dist�ncia necess�ria para executar o servi�o
* \return Retorna o valor em km
*/
float Servico::getDistancia() const
{
	return distancia;
}

/**
* \brief Adiciona um Cliente ao vetor
* \param j1 Cliente a adicionar
* \return Esta fun��o n�o possui retorno
*/
void Servico::adicionaCliente(Cliente *j1)
{
	clientes.push_back(j1);

	this->setStatus(true);
}

/**
* \brief Retira um Cliente do vetor, caso este l� esteja, caso contr�rio lan�a a excess�o ClienteInexistente
* \param j1 Cliente a retirar
* \return Esta fun��o n�o possui retorno
*/
void Servico::retiraCliente(Cliente *j1)
{
	int index = sequentialSearch(clientes, j1);
	if (index == -1)
		throw ClienteInexistente(j1->getNif());
	else
		clientes.erase(clientes.begin() + index);

	if (this->clientes.size() == 0)
		this->setStatus(false);
}

/**
* \brief Imprime todas as informa��es dos clientes do vetor
* \return Esta fun��o n�o possui retorno
*/
void Servico::readClientes() const
{
	cout << setw(20) << "Nome" << setw(15) << "NIF" << endl;
	for (unsigned int i = 0; i < clientes.size(); i++)
	{
		cout << setw(20) << clientes[i]->getNome() << setw(15) << clientes[i]->getNif() << endl;
	}
}

/**
* \brief Operador utilizado para verificar se dois servi�os s�o iguais
* \param s1 Servi�o a comparar
* \return Retorna true se os Servi�os forem iguais e false se n�o forem
*/
bool Servico::operator==(const Servico& s1)
{
	if (s1.id == this->id)
		return true;
	else
		return false;
}







