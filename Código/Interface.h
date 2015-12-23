#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Empresa.h"

using namespace std;

/*Fun��o que apaga o ecr� da consola*/
void clearScreen();

void printTitulo();

/*Primeiro ecr� a aparecer*/
Empresa firstScreen();

/*Optar por gerar ou carregar um ficheiro de empresa*/
Empresa gerar();
Empresa carregar();

/*Menu principal*/
void menuPrincipal(Empresa &empresa);

/*Menus espec�ficos*/
void mostrarClientes(Empresa &empresa);
void mostrarServicos(Empresa &empresa);
void mostrarFrota(Empresa &empresa);

/*Editar, remover ou adicionar servi�os*/
void editarServicos(Empresa &empresa);
void adicionarServicos(Empresa &empresa);
void removerServicos(Empresa &empresa);

/*Editar, remover ou adicionar clientes*/
void mostrarClientes(Empresa &empresa);

/*Editar, remover ou adicionar camioes*/
void editarCamiao(Empresa &empresa);
void adicionarCamiao(Empresa &empresa);
void removerCamiao(Empresa &empresa);


/**************PARTE 2*****************/

/*Menu dos motoristas*/




#endif // INTERFACE_H

