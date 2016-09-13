#ifndef FILTRONEGATIVO_HPP
#define FILTRONEGATIVO_HPP

#include <iostream>
#include "imagem.hpp"
#include "filtro.hpp"
#include "cor.hpp"
#include <list>

class FiltroNegativo : public Filtro{

	list<Cor> aplicarFiltro(Imagem  * imagem);
};

#endif