#ifndef FILTROPRETOEBRANCO_HPP
#define FILTROPRETOEBRANCO_HPP

#include <iostream>
#include "imagem.hpp"
#include "filtro.hpp"
#include "cor.hpp"
#include <list>

class FiltroPretoBranco : public Filtro{

	list<Cor> aplicarFiltro(Imagem  * imagem);
};

#endif