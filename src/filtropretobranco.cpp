#include "filtropretobranco.hpp"

list<Cor> FiltroPretoBranco::aplicarFiltro(Imagem  * imagem){

	list<Cor> cores;
	
	Cor c;
	for(Cor cor : imagem->getCores()){
		int grayscale_value = (0.299 * cor.getR()) + (0.587 * cor.getG()) + (0.144 * cor.getB());
		c.setR(grayscale_value);
		c.setG(grayscale_value);
		c.setB(grayscale_value);
	    cores.push_back(c);
	}


	return cores;
}