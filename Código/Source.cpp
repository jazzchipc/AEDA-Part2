#include "Empresa.h"
#include "Camiao.h"
#include "Frota.h"
#include "Servico.h"
#include "Interface.h"
#include "sequentialSearch.h"

#include <iostream>

/******USAR ESTE MAIN PARA TESTAR INTERFACE/PROGRAMA NUM CONJUNTO*******/
int main()
{
	Empresa empresa = firstScreen();

	menuPrincipal(empresa);

	return 0;
}

//*****USAR ESTE MAIN PARA TESTAR AS FUNÇÕES DA PARTE 2******
int main2()
{
	Empresa empresa ("Transportex");

	Motorista m1 ("A", 333);
	Motorista m2 ("B", 111);
	Motorista m3 ("C", 3333, 9);
	Motorista m4 ("D", 90901, 10);
	Motorista m5 ("E", 11, 9);
	Motorista m6("F", 333);
	Motorista m7("G", 111);
	Motorista m8("H", 3333, 8.12);
	Motorista m9("I", 90901, 10);
	Motorista m10("Jose COsta", 11, 9);

	empresa.adicionaMotorista(m1);
	empresa.adicionaMotorista(m2);
	empresa.adicionaMotorista(m3);
	empresa.adicionaMotorista(m4);
	empresa.adicionaMotorista(m5);
	empresa.adicionaMotorista(m6);
	empresa.adicionaMotorista(m7);
	empresa.adicionaMotorista(m8);
	empresa.adicionaMotorista(m9);
	empresa.adicionaMotorista(m10);

	empresa.getMotoristas().printTree();

	cout << empresa.removeMotorista(m4);
	cout << empresa.removeMotorista("C", 3333);
	cout << empresa.removeMotorista("Z", 0);
	cout << empresa.aumentaHorasMotorista(m1, 10);
	cout << empresa.aumentaHorasMotorista(m1, 10);
	cout << empresa.aumentaHorasMotorista(m1, 10);

	cout << endl;

	empresa.getMotoristas().printTree();

	cout << empresa.getMaiorMotorista();
	cout << empresa.getMenorMotorista();

	printListaMotoristas(empresa.getMenoresMotoristas(5));

	char c;
	cin >> c;

	return 0;
}
