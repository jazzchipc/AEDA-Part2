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

	Oficina o1("VolvoRepair", "Volvo", 8);
	Oficina o2("TeixeiraCo", "Volvo", 4);
	Oficina o3("CarAuto", "Volvo", 0);
	Oficina o4("CaetanoFormula", "Renault", 0);
	Oficina o5("MercServices", "Mercedes", 0);
	Oficina o6("Autoschaft", "Mercedes", 2);
	Oficina o7("Wuman", "MAN", 0);

	Camiao* c1 = new Camiao (100, "Volvo");
	Camiao* c4 = new Camiao(101, "Volvo");
	Camiao* c8 = new Camiao(102, "Volvo");
	Camiao* c2 = new Camiao (200, "Renault");
	Camiao* c3 = new Camiao (300, "Mercedes");
	Camiao* c7 = new Camiao(301, "Mercedes");
	Camiao* c5 = new Camiao(400, "MAN");
	Camiao* c6 = new Camiao(401, "MAN");
	
	


	Frota f;
	f.adicionaCamiao(c1);
	f.adicionaCamiao(c2);
	f.adicionaCamiao(c3);
	f.adicionaCamiao(c4);
	f.adicionaCamiao(c5);
	f.adicionaCamiao(c6);
	f.adicionaCamiao(c7);
	f.adicionaCamiao(c8);

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
	l.adicionaOficina(o7);

	ClienteInativo ci1("AntonioRamada", 3497);
	ClienteInativo ci2("MiguelVenancio", 8719);
	ClienteInativo ci3("HugoCosta", 1657);
	ClienteInativo ci4("DiogoCunha", 1325);
	ClienteInativo ci5("AmaliaAmbrosia", 1127);
	ClienteInativo ci6("DomingosDomingos", 1117);
	ClienteInativo ci7("JoaoFreitas", 1988);

	empresa.adicionaClienteInativo(ci1);
	empresa.adicionaClienteInativo(ci2);
	empresa.adicionaClienteInativo(ci3);
	empresa.adicionaClienteInativo(ci4);
	empresa.adicionaClienteInativo(ci5);
	empresa.adicionaClienteInativo(ci6);
	empresa.adicionaClienteInativo(ci7);

	empresa.setOficinas(l);

	menuPrincipal(empresa);

	return 0;
}
