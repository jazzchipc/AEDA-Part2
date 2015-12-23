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
	Empresa empresa = firstScreen();

	menuPrincipal(empresa);

	return 0;
}

//*****USAR ESTE MAIN PARA TESTAR AS FUNÇÕES DA PARTE 2******
int main()
{
	Empresa empresa("Transportex");

	Oficina o1("A", "Volvo", 9);
	Oficina o2("B", "Volvo", 1);
	Oficina o3("C", "Volvo", 10);
	Oficina o4("D", "Renault", 9);
	Oficina o5("E", "Mercedes", 1);
	Oficina o6("F", "Mercedes", 11);

	Camiao c1(1, "Volvo");
	Camiao c2(2, "Renault");
	Camiao c3(3, "Mercedes");

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

	empresa.setOficinas(l);

	cout << empresa.getOficinas().numeroOficinas() << endl;

	cout << empresa.getOficinas().imprimeOficinas();

	ListaOficinas aux = empresa.getOficinas();

	cout << aux.retornaOficina(c1, sn1);

	cout << aux.imprimeOficinas();

	char c;
	cin >> c;

	return 0;
}
