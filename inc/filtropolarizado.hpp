#ifndef FILTROPOLARIZADO_HPP
#define FILTROPOLARIZADO_HPP

#include <iostream>
#include "imagem.hpp"
#include "filtro.hpp"
#include "cor.hpp"
#include <list>

class FiltroPolarizado : public Filtro{

	list<Cor> aplicarFiltro(Imagem  * imagem);
};

#endif