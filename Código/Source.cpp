#include "Empresa.h"
#include "Camiao.h"
#include "Frota.h"
#include "Servico.h"
#include "Interface.h"
#include "sequentialSearch.h"

#include <iostream>


//*****USAR ESTE MAIN PARA TESTAR AS FUN합ES DA PARTE 2******
int main()
{
	Empresa empresa ("Transportex");

	Motorista m1 ("A", 333);
	Motorista m2 ("B", 111);
	Motorista m3 ("C", 3333, 9);
	Motorista m4 ("D", 90901, 10);
	Motorista m5 ("E", 11, 9);

	empresa.adicionaMotorista(m1);
	empresa.adicionaMotorista(m2);
	empresa.adicionaMotorista(m3);
	empresa.adicionaMotorista(m4);
	empresa.adicionaMotorista(m5);

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

	char c;
	cin >> c;

	return 0;
}

//IGNORAR FUN플O TESTE
int m()
{
	Cliente* cliente1 = new Cliente ("Jose Gomes", 15511);
	Cliente* cliente2 = new Cliente ("Antonio Martins", 15511);

	Cliente c1(*cliente1);
	Cliente c2(*cliente2);

	vector <Cliente*> v;
	v.push_back(cliente1);
	v.push_back(cliente2);

	Cliente* cliente3 = new Cliente("Jose Gomes", 15511);

	int i = sequentialSearch(v, cliente3);

	if (*cliente1 == *cliente2)
		cout << "true";
	else
		cout << "false";

	cout << i;

	char c;
	cin >> c;

	return 0;
}

//IGNORAR FUN플O TESTE
int main2()
{
	Empresa empresa = firstScreen();

	menuPrincipal(empresa);

	return 0;
}

//IGNORAR FUN플O TESTE
int a()

{
	//criar empresa
	Empresa empresa("empresa");

	empresa.loadEmpresa();

	empresa.printServicos();

	char c;
	cin >> c;

	/*Cliente* cliente1 = new Cliente ("Jose Gomes", 15511);
	Cliente* cliente2 = new Cliente ("Antonio Martins", 18882);

	Camiao* camiao1 = new Camiao (1, 1000, true);
	Camiao* camiao2 = new Camiao (2, 2000, false);

	Frota frota;
	frota.adicionaCamiao(camiao1);
	frota.adicionaCamiao(camiao2);

	frota.readCamioes();

	Servico*  servico1 = new Servico(1, 20);
	Servico*  servico2 = new Servico(2, 20);
	Servico*  servico3 = new Servico(3, 50);

	empresa.setFrota(frota);

	empresa.adicionaServico(servico1);
	empresa.adicionaServico(servico2);
	empresa.adicionaServico(servico3);

	empresa.printServicos();

	servico1->adicionaCliente(cliente1);
	servico1->adicionaCliente(cliente2);

	servico2->adicionaCliente(cliente2);

	servico1->readClientes();
	servico2->readClientes();
	servico3->readClientes();

	empresa.saveEmpresa();*/


	return 0;
}
