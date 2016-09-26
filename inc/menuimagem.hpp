#ifndef MENUIMAGEM_HPP
#define MENUIMAGEM_HPP
#include "filtro.hpp"
#include <iostream>
#include <string>

using namespace std;

class MenuImagem {

public:

	Filtro * lerOpcaoFiltro();

	int lerOpcaoMascara();

	string lerNomeImagem();

	void mensagem(string mensagem);

};

#endif