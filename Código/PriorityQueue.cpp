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
	os << "Nome da Oficina: " << of.getDenominacao() << "Especialidade: " << of.getEspecialidade() << ", Disponiblidade: " << of.getDisponibilidade() << endl;

	return os;
}

unsigned int ListaOficinas::numeroOficinas() const
{
	return oficinas.size();
}

unsigned ListaOficinas::adicionaOficina(Oficina& of)
{
	oficinas.push(of);

	return 0;
}

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
		ss << of << endl;
	}

	return ss.str();
}

Oficina ListaOficinas::retornaOficina(Camiao& c, bool servico)
{
	Oficina of;

	if (servico) // serviço == true , serviço normal
		return oficinas.top();

	vector<Oficina> tmp;

	while (!oficinas.empty()) // serviço especial
	{
		if (c.getMarca() == oficinas.top().getEspecialidade())
		{
			of = oficinas.top();
			oficinas.pop();
			unsigned int disp = oficinas.top().getDisponibilidade() - 1;
			of.updateDisponibilidade(disp);
			oficinas.push(of);
			for (unsigned int i = 0; i < tmp.size(); i++)
			{
				oficinas.push(tmp[i]);
			}
			return of;
		}
		else
		{
			of = oficinas.top();
			tmp.push_back(of);
			oficinas.pop();
		}
	}

	return of;

}

unsigned ListaOficinas::finalizaServico(Oficina& of)
{
	vector<Oficina> tmp;


	while (!oficinas.empty())
	{
		if (oficinas.top().getDenominacao() == of.getDenominacao())
		{
			of.updateDisponibilidade(of.getDisponibilidade() + 1);
			oficinas.push(of);
		}
		else
		{
			Oficina &o = oficinas.top();
			tmp.push_back(of);
			oficinas.pop();
		}
	}

	return 0;
}
