#include "filtronegativo.hpp"

list<Cor> FiltroNegativo::aplicarFiltro(Imagem  * imagem){

	list<Cor> cores;
	
	for(Cor cor : imagem->getCores()){
		cor.setR(imagem->getEscalaMaxima()-cor.getR());
		cor.setG(imagem->getEscalaMaxima()-cor.getG());
		cor.setB(imagem->getEscalaMaxima()-cor.getB());
		cores.push_back(cor);
	}

	return cores;
}