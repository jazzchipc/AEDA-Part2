#pragma once

#include "Oficina.h"
#include "Camiao.h"


#include <iostream>
#include <queue>
#include <iomanip>
#include <vector>
#include <string>
#include <utility>

using namespace std;


typedef priority_queue<Oficina> fila;

class ListaOficinas
{
private:
	fila oficinas;
public:
	ListaOficinas() {}
	unsigned int numeroOficinas() const;
	unsigned adicionaOficina(Oficina& of);
	unsigned removeOficina(Oficina& of);
	string imprimeOficinas() const;
	Oficina retornaOficina(Camiao c, ServicoOficina s);
	unsigned finalizaServico(Oficina &of);
};

ostream& operator<<(ostream& os, Oficina of);