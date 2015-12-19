/*
* Frota.cpp
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
* \brief Cria uma Frota sem par�metros
* \return Esta fun��o n�o possui retorno
*/
Frota::Frota()
{}

/**
* \brief Adiciona um Cami�o � frota
* \param c1 Cami�o a adicionar
* \return Esta fun��o n�o possui retorno
*/
void Frota::adicionaCamiao(Camiao *c1)
{
	camioes.push_back(c1);
}

/**
* \brief Retira um  Cami�o da frota, caso este l� esteja, caso contr�rio lan�a a excess�o CamiaoInexistente
* \param c1 Cami�o a retirar
* \return Esta fun��o n�o possui retorno
*/
void Frota::retiraCamiao(Camiao *c1)
{
	int index = sequentialSearch(camioes, c1);
	if (index == -1)
		throw CamiaoInexistente(c1->getCodigo());
	else
		camioes.erase(camioes.begin() + index);

}

/**
* \brief Imprime todas as informa��es dos cami�es da frota
* \return Esta fun��o n�o possui retorno
*/
void Frota::readCamioes()const
{
	cout << setw(8) << "Codigo" << setw(16) << "Capacidade (KG)" << setw(15) << "Congelador" << setw(15) << "Carga perigosa" << endl;
	for (unsigned int i = 0; i < camioes.size(); i++)
	{
		cout << setw(8) << camioes[i]->getCodigo() << setw(16) << camioes[i]->getCapMax() 
			<< setw(15) << camioes[i]->getCapCong() << setw(15) << camioes[i]->getCapPerig() << endl;
	}
}

/**
* \brief Obt�m o vetor que guarda todos os cami�es da frota
* \return Retorna o vetor
*/
vector <Camiao *> Frota::getCamioes()
{
	return this->camioes;
}



