#ifndef VALIDACAOMENU_HPP
#define VALIDACAOMENU_HPP

#include <iostream>

class ValidacaoMenu {

public:

	int validarInteiro();

	int validarOpcao(int opcao, int valorMenor, int valorMaior);
};

#endif