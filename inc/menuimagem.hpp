#ifndef MENUIMAGEM_HPP
#define MENUIMAGEM_HPP
#include "filtro.hpp"
#include <iostream>

class MenuImagem {

private:
	int le_teclado_int();
	int isOpcao(int opcao);

public:

	Filtro * lerOpcaoFiltro();

};

#endif