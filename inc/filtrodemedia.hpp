#ifndef FILTRODEMEDIA_HPP
#define FFILTRODEMEDIA_HPP

#include <iostream>
#include "imagem.hpp"
#include "filtro.hpp"
#include "cor.hpp"
#include <list>

class FiltroDeMedia : public Filtro{

private:
	int mascara;
public:
	FiltroDeMedia();
	void setMascara(int mascara);
	int getMascara();

	list<Cor> aplicarFiltro(Imagem  * imagem);
private:
	Cor ** getMatriz(int altura, int largura, list<Cor>);
	list<Cor> getList(Cor** rgb, int largura, list<Cor> coresList);
};

#endif