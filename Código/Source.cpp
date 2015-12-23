#include "Empresa.h"
#include "Camiao.h"
#include "Frota.h"
#include "Servico.h"
#include "Interface.h"
#include "sequentialSearch.h"

#include <iostream>

/******USAR ESTE MAIN PARA TESTAR INTERFACE/PROGRAMA NUM CONJUNTO*******/
int main2()
{
	


	return 0;
}

//*****USAR ESTE MAIN PARA TESTAR AS FUNÇÕES DA PARTE 2******
int main()
{
	Empresa empresa = firstScreen();

	Motorista m1("Joao Peixoto", 12231111);
	Motorista m2("Miguel Pires", 11123411);
	Motorista m3("Pedro Cardoso", 44728912);
	Motorista m4("Luis Mexias", 11134521);
	Motorista m5("Paulo Carvalho", 1234111);
	Motorista m6("Joana Freitas", 1928111);

	empresa.adicionaMotorista(m1);
	empresa.adicionaMotorista(m2);
	empresa.adicionaMotorista(m3);
	empresa.adicionaMotorista(m4);
	empresa.adicionaMotorista(m5);
	empresa.adicionaMotorista(m6);

	Oficina o1("A", "Volvo", 9);
	Oficina o2("B", "Volvo", 1);
	Oficina o3("C", "Volvo", 10);
	Oficina o4("D", "Renault", 9);
	Oficina o5("E", "Mercedes", 1);
	Oficina o6("F", "Mercedes", 11);

	Camiao* c1 = new Camiao (1, "Volvo");
	Camiao* c2 = new Camiao (2, "Renault");
	Camiao* c3 = new Camiao (3, "Mercedes");

	Frota f;
	f.adicionaCamiao(c1);
	f.adicionaCamiao(c2);
	f.adicionaCamiao(c3);

	empresa.setFrota(f);

	ServicoOficina se1(true, 10);
	ServicoOficina se2(true, 5);
	ServicoOficina sn1(false, 2);
	ServicoOficina sn2(false, 6);

	ListaOficinas l;
	l.adicionaOficina(o1);
	l.adicionaOficina(o2);
	l.adicionaOficina(o3);
	l.adicionaOficina(o4);
	l.adicionaOficina(o5);
	l.adicionaOficina(o6);

	ClienteInativo ci1("A", 1333);
	ClienteInativo ci2("B", 1333);
	ClienteInativo ci3("C", 1333);
	ClienteInativo ci4("D", 1333);

	empresa.adicionaClienteInativo(ci1);
	empresa.adicionaClienteInativo(ci3);

	empresa.setOficinas(l);

	menuPrincipal(empresa);

	return 0;
}
