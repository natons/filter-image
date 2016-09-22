#ifndef FILTRODEMEDIA_HPP
#define FFILTRODEMEDIA_HPP

#include <iostream>
#include "imagem.hpp"
#include "filtro.hpp"
#include "cor.hpp"
#include <list>

class FiltroDeMedia : public Filtro{

	list<Cor> aplicarFiltro(Imagem  * imagem);
};

#endif