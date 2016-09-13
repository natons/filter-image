#ifndef FILTRO_HPP
#define FILTRO_HPP

#include <iostream>
#include <list>
#include "cor.hpp"
#include "imagem.hpp"


class Filtro {

public:

	virtual list<Cor> aplicarFiltro(Imagem * imagem);

};

#endif