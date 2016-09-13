#include "filtronegativo.hpp"

list<Cor> FiltroNegativo::aplicarFiltro(Imagem  * imagem){

	list<Cor> cores;
	
	Cor c;
	for(Cor cor : imagem->getCores()){
		c.setR(imagem->getEscalaMaxima()-cor.getR());
		c.setG(imagem->getEscalaMaxima()-cor.getG());
		c.setB(imagem->getEscalaMaxima()-cor.getB());
		cores.push_back(c);
	}

	return cores;
}