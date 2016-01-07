#include "PriorityQueue.h"

#include <iostream>
#include <queue>
#include <iomanip>
#include <vector>
#include <string>
#include <utility>
#include <sstream>

using namespace std;

//// CLASS Lista de Oficinas ////

//Overloading

ostream& operator<<(ostream& os, Oficina of)
{
	os << "Nome da Oficina: " << of.getDenominacao() << ", Especialidade: " << of.getEspecialidade() << ", Disponiblidade: " << of.getDisponibilidade() << endl;

	return os;
}

/**
* \brief Obtém o número de oficinas presentes na fila de prioridade
* \return Retorna o número de oficinas presentes na fila de prioridade
*/
unsigned int ListaOficinas::numeroOficinas() const
{
	return oficinas.size();
}

/**
* \brief Adiciona o Oficina of à fila de prioridade
* \param of Oficina a adicionar 
* \return Retorna 0
*/
unsigned ListaOficinas::adicionaOficina(Oficina& of)
{
	oficinas.push(of);

	return 0;
}

/**
* \brief Remove a Oficina of da fila de prioridade
* \param of Oficina a remover
* \return Retorna 0
*/
unsigned ListaOficinas::removeOficina(Oficina& of)
{
	vector<Oficina> tmp;

	while (!oficinas.empty())
	{
		if (of.getDenominacao() == oficinas.top().getDenominacao())
		{
			oficinas.pop();
			for (unsigned int i = 0; i < tmp.size(); i++)
			{
				oficinas.push(tmp[i]);
			}
		}
		else
		{
			Oficina &of = oficinas.top();
			tmp.push_back(of);
			oficinas.pop();
		}

	}

	return 0;
}

// função que impime lista de oficinas

/**
* \brief Imprime as Oficinas da fila de prioridade, caso esta esteja fazia imprime "Não existem oficinas disponíveis."
* \return Retorna o string que será imprimido
*/
string ListaOficinas::imprimeOficinas() const
{
	stringstream ss;

	if (oficinas.empty())
		ss << "Não existem oficinas disponíveis.";

	fila tmp = oficinas;

	while (!tmp.empty())
	{
		Oficina of = tmp.top();
		tmp.pop();
		ss << of;
	}

	ss << endl;

	return ss.str();
}

/**
* \brief Procura a Oficina que pode executar o serviço s no camião c mais rapidamente
* \param c Camião especificado
* \param s Serviço especificado 
* \return Retorna a Oficina que pode executar o serviço mais rapidamente
*/
Oficina ListaOficinas::retornaOficina(Camiao& c, ServicoOficina s)
{
	Oficina of;

	c.setDuracao(s.getDuracao());
	c.setReparacao(true);

	if (!s.getEspecifico()) // serviço normal
	{
		of = oficinas.top();
		oficinas.pop();
		unsigned int disp = oficinas.top().getDisponibilidade() + s.getDuracao();
		of.updateDisponibilidade(disp);
		oficinas.push(of);

		return of;
	}

	vector<Oficina> tmp;

	while (!oficinas.empty()) // serviço especial
	{
		if (c.getMarca() == oficinas.top().getEspecialidade())
		{
			of = oficinas.top();
			unsigned int disp = oficinas.top().getDisponibilidade() + s.getDuracao();
			of.updateDisponibilidade(disp);
			oficinas.pop();
			oficinas.push(of);
			for (unsigned int i = 0; i < tmp.size(); i++)
			{
				oficinas.push(tmp[i]);
			}
			c.setOficina(of);
			return of;
		}
		else
		{
			of = oficinas.top();
			tmp.push_back(of);
			oficinas.pop();
		}
	}

	c.setOficina(of);

	return of;

}

/**
* \brief Aumenta a disponibilidade de uma Oficina que termine um certo serviço
* \param of Oficina a atualizar 
* \param duracao Duração do serviço a terminar
* \return Retorna 0
*/
unsigned ListaOficinas::finalizaServico(Oficina& of, int duracao)
{
	vector<Oficina> tmp;

	while (!oficinas.empty())
	{
		if (oficinas.top().getDenominacao() == of.getDenominacao())
		{
			oficinas.pop();
			of.updateDisponibilidade(of.getDisponibilidade() - duracao);
			oficinas.push(of);
			break;
		}
		else
		{
			Oficina &o = oficinas.top();
			tmp.push_back(o);
			oficinas.pop();
		}
	}

	for (int i = 0; i < tmp.size(); i++)
	{
		oficinas.push(tmp[i]);
	}

	return 0;
}

/**
* @brief Retorna a "fila" de uma oficina.
* @return A fila
*/
fila ListaOficinas::retornaFila()
{
	return this->oficinas;
}

